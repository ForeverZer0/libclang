#include "libclang.h"

#define HIDE 1

VALUE rb_mLibClang;

#define METHOD(name, function, argc) rb_define_singleton_method(rb_mLibClang, name, function, argc)

#define RETURN_WRAP(obj, klass) return Data_Wrap_Struct(klass, NULL, RUBY_DEFAULT_FREE, obj)
#define RETURN_STRING(str) return Data_Wrap_Struct(rb_cCXString, NULL, clang_disposeString, str)
#define RETURN_CURSOR(cur) return Data_Wrap_Struct(rb_cCXCursor, NULL, RUBY_DEFAULT_FREE, cur)
#define RETURN_TYPE(type) return Data_Wrap_Struct(rb_cCXType, NULL, RUBY_DEFAULT_FREE, type)
#define RETURN_TRANS_UNIT(unit) return Data_Wrap_Struct(rb_cCXTranslationUnit, NULL, clang_disposeTranslationUnit, unit)

#define UNWRAP(obj, type) \
    type *x;              \
    Data_Get_Struct(obj, type, x)

#define CURSOR() UNWRAP(obj, CXCursor)
#define TYPE() UNWRAP(obj, CXType)

#define WRAP_BOOL_FUNC(name, func, type)      \
    static VALUE name(VALUE mod, VALUE obj) { \
        UNWRAP(obj, type);                    \
        return func(*x) ? Qtrue : Qfalse;     \
    }

#define WRAP_UINT_FUNC(name, func, type)      \
    static VALUE name(VALUE mod, VALUE obj) { \
        UNWRAP(obj, type);                    \
        return UINT2NUM(func(*x));            \
    }

#define WRAP_INT_FUNC(name, func, type)       \
    static VALUE name(VALUE mod, VALUE obj) { \
        UNWRAP(obj, type);                    \
        return INT2NUM(func(*x));             \
    }

#define WRAP_STRING_FUNC(name, func, type)    \
    static VALUE name(VALUE mod, VALUE obj) { \
        UNWRAP(obj, type);                    \
        CXString str = func(*x);              \
        RETURN_STRING(&str);                  \
    }

#define WRAP_DISPOSE_FUNC(name, func, type)   \
    static VALUE name(VALUE mod, VALUE obj) { \
        UNWRAP(obj, type);                    \
        func(x);                              \
        return Qnil;                          \
    }

void Init_libclang(void) {
    rb_mLibClang = rb_define_module("LibClang");
    Init_libclang_enums(rb_mLibClang);
    Init_libclang_classes(rb_mLibClang);

    METHOD("AnnotateTokens", rb_clang_annotateTokens, 1);
    METHOD("BlockCommandCommentGetArgText", rb_clang_BlockCommandComment_getArgText, 1);
    METHOD("BlockCommandCommentGetCommandName", rb_clang_BlockCommandComment_getCommandName, 1);
    METHOD("BlockCommandCommentGetNumArgs", rb_clang_BlockCommandComment_getNumArgs, 1);
    METHOD("BlockCommandCommentGetParagraph", rb_clang_BlockCommandComment_getParagraph, 1);
    METHOD("CodeCompleteAt", rb_clang_codeCompleteAt, 1);
    METHOD("CodeCompleteGetContainerKind", rb_clang_codeCompleteGetContainerKind, 1);
    METHOD("CodeCompleteGetContainerUsr", rb_clang_codeCompleteGetContainerUSR, 1);
    METHOD("CodeCompleteGetContexts", rb_clang_codeCompleteGetContexts, 1);
    METHOD("CodeCompleteGetDiagnostic", rb_clang_codeCompleteGetDiagnostic, 1);
    METHOD("CodeCompleteGetNumDiagnostics", rb_clang_codeCompleteGetNumDiagnostics, 1);
    METHOD("CodeCompleteGetObjCSelector", rb_clang_codeCompleteGetObjCSelector, 1);
    METHOD("CommentGetChild", rb_clang_Comment_getChild, 1);
    METHOD("CommentGetKind", rb_clang_Comment_getKind, 1);
    METHOD("CommentGetNumChildren", rb_clang_Comment_getNumChildren, 1);
    METHOD("CommentIsWhitespace", rb_clang_Comment_isWhitespace, 1);
    METHOD("CompilationDatabaseDispose", rb_clang_CompilationDatabase_dispose, 1);
    METHOD("CompilationDatabaseFromDirectory", rb_clang_CompilationDatabase_fromDirectory, 1);
    METHOD("CompilationDatabaseGetAllCompileCommands", rb_clang_CompilationDatabase_getAllCompileCommands, 1);
    METHOD("CompilationDatabaseGetCompileCommands", rb_clang_CompilationDatabase_getCompileCommands, 1);
    METHOD("CompileCommandGetArg", rb_clang_CompileCommand_getArg, 1);
    METHOD("CompileCommandGetDirectory", rb_clang_CompileCommand_getDirectory, 1);
    METHOD("CompileCommandGetFilename", rb_clang_CompileCommand_getFilename, 1);
    METHOD("CompileCommandGetMappedSourceContent", rb_clang_CompileCommand_getMappedSourceContent, 1);
    METHOD("CompileCommandGetMappedSourcePath", rb_clang_CompileCommand_getMappedSourcePath, 1);
    METHOD("CompileCommandGetNumArgs", rb_clang_CompileCommand_getNumArgs, 1);
    METHOD("CompileCommandGetNumMappedSources", rb_clang_CompileCommand_getNumMappedSources, 1);
    METHOD("CompileCommandsDispose", rb_clang_CompileCommands_dispose, 1);
    METHOD("CompileCommandsGetCommand", rb_clang_CompileCommands_getCommand, 1);
    METHOD("CompileCommandsGetSize", rb_clang_CompileCommands_getSize, 1);
    METHOD("ConstructUsrObjCCategory", rb_clang_constructUSR_ObjCCategory, 1);
    METHOD("ConstructUsrObjCClass", rb_clang_constructUSR_ObjCClass, 1);
    METHOD("ConstructUsrObjCIvar", rb_clang_constructUSR_ObjCIvar, 1);
    METHOD("ConstructUsrObjCMethod", rb_clang_constructUSR_ObjCMethod, 1);
    METHOD("ConstructUsrObjCProperty", rb_clang_constructUSR_ObjCProperty, 1);
    METHOD("ConstructUsrObjCProtocol", rb_clang_constructUSR_ObjCProtocol, 1);
    METHOD("CreateCxCursorSet", rb_clang_createCXCursorSet, 1);
    METHOD("CreateIndex", rb_clang_createIndex, 2);
    METHOD("CreateTranslationUnit", rb_clang_createTranslationUnit, 1);
    METHOD("CreateTranslationUnit2", rb_clang_createTranslationUnit2, 1);
    METHOD("CreateTranslationUnitFromSourceFile", rb_clang_createTranslationUnitFromSourceFile, 1);
    METHOD("CursorEvaluate", rb_clang_Cursor_Evaluate, 1);
    METHOD("CursorGetArgument", rb_clang_Cursor_getArgument, 2);
    METHOD("CursorGetBriefCommentText", rb_clang_Cursor_getBriefCommentText, 1);
    METHOD("CursorGetCommentRange", rb_clang_Cursor_getCommentRange, 1);
    METHOD("CursorGetCxxManglings", rb_clang_Cursor_getCXXManglings, 1);
    METHOD("CursorGetMangling", rb_clang_Cursor_getMangling, 1);
    METHOD("CursorGetModule", rb_clang_Cursor_getModule, 1);
    METHOD("CursorGetNumArguments", rb_clang_Cursor_getNumArguments, 1);
    METHOD("CursorGetNumTemplateArguments", rb_clang_Cursor_getNumTemplateArguments, 1);
    METHOD("CursorGetObjCDeclQualifiers", rb_clang_Cursor_getObjCDeclQualifiers, 1);
    METHOD("CursorGetObjCManglings", rb_clang_Cursor_getObjCManglings, 1);
    METHOD("CursorGetObjCPropertyAttributes", rb_clang_Cursor_getObjCPropertyAttributes, 2);
    METHOD("CursorGetObjCSelectorIndex", rb_clang_Cursor_getObjCSelectorIndex, 1);
    METHOD("CursorGetOffsetOfField", rb_clang_Cursor_getOffsetOfField, 1);
    METHOD("CursorGetParsedComment", rb_clang_Cursor_getParsedComment, 1);
    METHOD("CursorGetRawCommentText", rb_clang_Cursor_getRawCommentText, 1);
    METHOD("CursorGetReceiverType", rb_clang_Cursor_getReceiverType, 1);
    METHOD("CursorGetSpellingNameRange", rb_clang_Cursor_getSpellingNameRange, 3);
    METHOD("CursorGetStorageClass", rb_clang_Cursor_getStorageClass, 1);
    METHOD("CursorGetTemplateArgumentKind", rb_clang_Cursor_getTemplateArgumentKind, 2);
    METHOD("CursorGetTemplateArgumentType", rb_clang_Cursor_getTemplateArgumentType, 2);
    METHOD("CursorGetTemplateArgumentUnsignedValue", rb_clang_Cursor_getTemplateArgumentUnsignedValue, 2);
    METHOD("CursorGetTemplateArgumentValue", rb_clang_Cursor_getTemplateArgumentValue, 2);
    METHOD("CursorGetTranslationUnit", rb_clang_Cursor_getTranslationUnit, 1);
    METHOD("CursorHasAttrs", rb_clang_Cursor_hasAttrs, 1);
    METHOD("CursorIsAnonymous", rb_clang_Cursor_isAnonymous, 1);
    METHOD("CursorIsBitField", rb_clang_Cursor_isBitField, 1);
    METHOD("CursorIsDynamicCall", rb_clang_Cursor_isDynamicCall, 1);
    METHOD("CursorIsExternalSymbol", rb_clang_Cursor_isExternalSymbol, 4);
    METHOD("CursorIsFunctionInlined", rb_clang_Cursor_isFunctionInlined, 1);
    METHOD("CursorIsMacroBuiltin", rb_clang_Cursor_isMacroBuiltin, 1);
    METHOD("CursorIsMacroFunctionLike", rb_clang_Cursor_isMacroFunctionLike, 1);
    METHOD("CursorIsNull", rb_clang_Cursor_isNull, 1);
    METHOD("CursorIsObjCOptional", rb_clang_Cursor_isObjCOptional, 1);
    METHOD("CursorIsVariadic", rb_clang_Cursor_isVariadic, 1);
    METHOD("CxCursorSetContains", rb_clang_CXCursorSet_contains, 1);
    METHOD("CxCursorSetInsert", rb_clang_CXCursorSet_insert, 1);
    METHOD("CxIndexGetGlobalOptions", rb_clang_CXIndex_getGlobalOptions, 1);
    METHOD("CxIndexSetGlobalOptions", rb_clang_CXIndex_setGlobalOptions, 1);
    METHOD("CxIndexSetInvocationEmissionPathOption", rb_clang_CXIndex_setInvocationEmissionPathOption, 1);
    METHOD("CxxConstructorIsConvertingConstructor", rb_clang_CXXConstructor_isConvertingConstructor, 1);
    METHOD("CxxConstructorIsCopyConstructor", rb_clang_CXXConstructor_isCopyConstructor, 1);
    METHOD("CxxConstructorIsDefaultConstructor", rb_clang_CXXConstructor_isDefaultConstructor, 1);
    METHOD("CxxConstructorIsMoveConstructor", rb_clang_CXXConstructor_isMoveConstructor, 1);
    METHOD("CxxFieldIsMutable", rb_clang_CXXField_isMutable, 1);
    METHOD("CxxMethodIsConst", rb_clang_CXXMethod_isConst, 1);
    METHOD("CxxMethodIsDefaulted", rb_clang_CXXMethod_isDefaulted, 1);
    METHOD("CxxMethodIsPureVirtual", rb_clang_CXXMethod_isPureVirtual, 1);
    METHOD("CxxMethodIsStatic", rb_clang_CXXMethod_isStatic, 1);
    METHOD("CxxMethodIsVirtual", rb_clang_CXXMethod_isVirtual, 1);
    METHOD("CxxRecordIsAbstract", rb_clang_CXXRecord_isAbstract, 1);
    METHOD("DefaultCodeCompleteOptions", rb_clang_defaultCodeCompleteOptions, 1);
    METHOD("DefaultDiagnosticDisplayOptions", rb_clang_defaultDiagnosticDisplayOptions, 1);
    METHOD("DefaultEditingTranslationUnitOptions", rb_clang_defaultEditingTranslationUnitOptions, 1);
    METHOD("DefaultReparseOptions", rb_clang_defaultReparseOptions, 1);
    METHOD("DefaultSaveOptions", rb_clang_defaultSaveOptions, 1);
    METHOD("DisposeCodeCompleteResults", rb_clang_disposeCodeCompleteResults, 1);
    METHOD("DisposeCxCursorSet", rb_clang_disposeCXCursorSet, 1);
    METHOD("DisposeCxPlatformAvailability", rb_clang_disposeCXPlatformAvailability, 1);
    METHOD("DisposeCxtuResourceUsage", rb_clang_disposeCXTUResourceUsage, 1);
    METHOD("DisposeDiagnostic", rb_clang_disposeDiagnostic, 1);
    METHOD("DisposeDiagnosticSet", rb_clang_disposeDiagnosticSet, 1);
    METHOD("DisposeIndex", rb_clang_disposeIndex, 1);
    METHOD("DisposeOverriddenCursors", rb_clang_disposeOverriddenCursors, 1);
    METHOD("DisposeSourceRangeList", rb_clang_disposeSourceRangeList, 1);
    METHOD("DisposeString", rb_clang_disposeString, 1);
    METHOD("DisposeStringSet", rb_clang_disposeStringSet, 1);
    METHOD("DisposeTokens", rb_clang_disposeTokens, 3);
    METHOD("DisposeTranslationUnit", rb_clang_disposeTranslationUnit, 1);
    METHOD("EnableStackTraces", rb_clang_enableStackTraces, 1);
    METHOD("EnumDeclIsScoped", rb_clang_EnumDecl_isScoped, 1);
    METHOD("EqualCursors", rb_clang_equalCursors, 1);
    METHOD("EqualLocations", rb_clang_equalLocations, 1);
    METHOD("EqualRanges", rb_clang_equalRanges, 1);
    METHOD("EqualTypes", rb_clang_equalTypes, 1);
    METHOD("EvalResultDispose", rb_clang_EvalResult_dispose, 1);
    METHOD("EvalResultGetAsDouble", rb_clang_EvalResult_getAsDouble, 1);
    METHOD("EvalResultGetAsInt", rb_clang_EvalResult_getAsInt, 1);
    METHOD("EvalResultGetAsLongLong", rb_clang_EvalResult_getAsLongLong, 1);
    METHOD("EvalResultGetAsStr", rb_clang_EvalResult_getAsStr, 1);
    METHOD("EvalResultGetAsUnsigned", rb_clang_EvalResult_getAsUnsigned, 1);
    METHOD("EvalResultGetKind", rb_clang_EvalResult_getKind, 1);
    METHOD("EvalResultIsUnsignedInt", rb_clang_EvalResult_isUnsignedInt, 1);
    METHOD("ExecuteOnThread", rb_clang_executeOnThread, 1);
    METHOD("FileIsEqual", rb_clang_File_isEqual, 2);
    METHOD("FindIncludesInFile", rb_clang_findIncludesInFile, 1);
    METHOD("FindReferencesInFile", rb_clang_findReferencesInFile, 1);
    METHOD("FormatDiagnostic", rb_clang_formatDiagnostic, 1);
    METHOD("Free", rb_clang_free, 1);
    METHOD("FullCommentGetAsHtml", rb_clang_FullComment_getAsHTML, 1);
    METHOD("FullCommentGetAsXml", rb_clang_FullComment_getAsXML, 1);
    METHOD("GetAddressSpace", rb_clang_getAddressSpace, 1);
    METHOD("GetAllSkippedRanges", rb_clang_getAllSkippedRanges, 1);
    METHOD("GetArgType", rb_clang_getArgType, 2);
    METHOD("GetArrayElementType", rb_clang_getArrayElementType, 1);
    METHOD("GetArraySize", rb_clang_getArraySize, 1);
    METHOD("GetBuildSessionTimestamp", rb_clang_getBuildSessionTimestamp, 1);
    METHOD("GetCanonicalCursor", rb_clang_getCanonicalCursor, 1);
    METHOD("GetCanonicalType", rb_clang_getCanonicalType, 1);
    METHOD("GetChildDiagnostics", rb_clang_getChildDiagnostics, 1);
    METHOD("GetClangVersion", rb_clang_getClangVersion, 1);
    METHOD("GetCompletionAnnotation", rb_clang_getCompletionAnnotation, 1);
    METHOD("GetCompletionAvailability", rb_clang_getCompletionAvailability, 1);
    METHOD("GetCompletionBriefComment", rb_clang_getCompletionBriefComment, 1);
    METHOD("GetCompletionChunkCompletionString", rb_clang_getCompletionChunkCompletionString, 1);
    METHOD("GetCompletionChunkKind", rb_clang_getCompletionChunkKind, 1);
    METHOD("GetCompletionChunkText", rb_clang_getCompletionChunkText, 1);
    METHOD("GetCompletionNumAnnotations", rb_clang_getCompletionNumAnnotations, 1);
    METHOD("GetCompletionParent", rb_clang_getCompletionParent, 1);
    METHOD("GetCompletionPriority", rb_clang_getCompletionPriority, 1);
    METHOD("GetCString", rb_clang_getCString, 1);
    METHOD("GetCursor", rb_clang_getCursor, 2);
    METHOD("GetCursorAvailability", rb_clang_getCursorAvailability, 1);
    METHOD("GetCursorCompletionString", rb_clang_getCursorCompletionString, 1);
    METHOD("GetCursorDefinition", rb_clang_getCursorDefinition, 1);
    METHOD("GetCursorDisplayName", rb_clang_getCursorDisplayName, 1);
    METHOD("GetCursorExceptionSpecificationType", rb_clang_getCursorExceptionSpecificationType, 1);
    METHOD("GetCursorExtent", rb_clang_getCursorExtent, 1);
    METHOD("GetCursorKind", rb_clang_getCursorKind, 1);
    METHOD("GetCursorKindSpelling", rb_clang_getCursorKindSpelling, 1);
    METHOD("GetCursorLanguage", rb_clang_getCursorLanguage, 1);
    METHOD("GetCursorLexicalParent", rb_clang_getCursorLexicalParent, 1);
    METHOD("GetCursorLinkage", rb_clang_getCursorLinkage, 1);
    METHOD("GetCursorLocation", rb_clang_getCursorLocation, 1);
    METHOD("GetCursorPlatformAvailability", rb_clang_getCursorPlatformAvailability, 1);
    METHOD("GetCursorReferenced", rb_clang_getCursorReferenced, 1);
    METHOD("GetCursorReferenceNameRange", rb_clang_getCursorReferenceNameRange, 3);
    METHOD("GetCursorResultType", rb_clang_getCursorResultType, 1);
    METHOD("GetCursorSemanticParent", rb_clang_getCursorSemanticParent, 1);
    METHOD("GetCursorSpelling", rb_clang_getCursorSpelling, 1);
    METHOD("GetCursorTlsKind", rb_clang_getCursorTLSKind, 1);
    METHOD("GetCursorType", rb_clang_getCursorType, 1);
    METHOD("GetCursorUsr", rb_clang_getCursorUSR, 1);
    METHOD("GetCursorVisibility", rb_clang_getCursorVisibility, 1);
    METHOD("GetCxtuResourceUsage", rb_clang_getCXTUResourceUsage, 1);
    METHOD("GetCxxAccessSpecifier", rb_clang_getCXXAccessSpecifier, 1);
    METHOD("GetDeclObjCTypeEncoding", rb_clang_getDeclObjCTypeEncoding, 1);
    METHOD("GetDefinitionSpellingAndExtent", rb_clang_getDefinitionSpellingAndExtent, 1);
    METHOD("GetDiagnostic", rb_clang_getDiagnostic, 2);
    METHOD("GetDiagnosticCategory", rb_clang_getDiagnosticCategory, 1);
    METHOD("GetDiagnosticCategoryName", rb_clang_getDiagnosticCategoryName, 1);
    METHOD("GetDiagnosticCategoryText", rb_clang_getDiagnosticCategoryText, 1);
    METHOD("GetDiagnosticFixIt", rb_clang_getDiagnosticFixIt, 1);
    METHOD("GetDiagnosticInSet", rb_clang_getDiagnosticInSet, 1);
    METHOD("GetDiagnosticLocation", rb_clang_getDiagnosticLocation, 1);
    METHOD("GetDiagnosticNumFixIts", rb_clang_getDiagnosticNumFixIts, 1);
    METHOD("GetDiagnosticNumRanges", rb_clang_getDiagnosticNumRanges, 1);
    METHOD("GetDiagnosticOption", rb_clang_getDiagnosticOption, 1);
    METHOD("GetDiagnosticRange", rb_clang_getDiagnosticRange, 2);
    METHOD("GetDiagnosticSetFromTu", rb_clang_getDiagnosticSetFromTU, 1);
    METHOD("GetDiagnosticSeverity", rb_clang_getDiagnosticSeverity, 1);
    METHOD("GetDiagnosticSpelling", rb_clang_getDiagnosticSpelling, 1);
    METHOD("GetElementType", rb_clang_getElementType, 1);
    METHOD("GetEnumConstantDeclUnsignedValue", rb_clang_getEnumConstantDeclUnsignedValue, 1);
    METHOD("GetEnumConstantDeclValue", rb_clang_getEnumConstantDeclValue, 1);
    METHOD("GetEnumDeclIntegerType", rb_clang_getEnumDeclIntegerType, 1);
    METHOD("GetExceptionSpecificationType", rb_clang_getExceptionSpecificationType, 1);
    METHOD("GetExpansionLocation", rb_clang_getExpansionLocation, 1);
    METHOD("GetFieldDeclBitWidth", rb_clang_getFieldDeclBitWidth, 1);
    METHOD("GetFile", rb_clang_getFile, 2);
    METHOD("GetFileContents", rb_clang_getFileContents, 3);
    METHOD("GetFileLocation", rb_clang_getFileLocation, 1);
    METHOD("GetFileName", rb_clang_getFileName, 1);
    METHOD("GetFileTime", rb_clang_getFileTime, 1);
    METHOD("GetFileUniqueId", rb_clang_getFileUniqueID, 2);
    METHOD("GetFunctionTypeCallingConv", rb_clang_getFunctionTypeCallingConv, 1);
    METHOD("GetIbOutletCollectionType", rb_clang_getIBOutletCollectionType, 1);
    METHOD("GetIncludedFile", rb_clang_getIncludedFile, 1);
    METHOD("GetInclusions", rb_clang_getInclusions, 1);
    METHOD("GetInstantiationLocation", rb_clang_getInstantiationLocation, 1);
    METHOD("GetLocation", rb_clang_getLocation, 1);
    METHOD("GetLocationForOffset", rb_clang_getLocationForOffset, 1);
    METHOD("GetModuleForFile", rb_clang_getModuleForFile, 1);
    METHOD("GetNullCursor", rb_clang_getNullCursor, 1);
    METHOD("GetNullLocation", rb_clang_getNullLocation, 1);
    METHOD("GetNullRange", rb_clang_getNullRange, 1);
    METHOD("GetNumArgTypes", rb_clang_getNumArgTypes, 1);
    METHOD("GetNumCompletionChunks", rb_clang_getNumCompletionChunks, 1);
    METHOD("GetNumDiagnostics", rb_clang_getNumDiagnostics, 1);
    METHOD("GetNumDiagnosticsInSet", rb_clang_getNumDiagnosticsInSet, 1);
    METHOD("GetNumElements", rb_clang_getNumElements, 1);
    METHOD("GetNumOverloadedDecls", rb_clang_getNumOverloadedDecls, 1);
    METHOD("GetOverloadedDecl", rb_clang_getOverloadedDecl, 1);
    METHOD("GetOverriddenCursors", rb_clang_getOverriddenCursors, 1);
    METHOD("GetPointeeType", rb_clang_getPointeeType, 1);
    METHOD("GetPresumedLocation", rb_clang_getPresumedLocation, 1);
    METHOD("GetRange", rb_clang_getRange, 1);
    METHOD("GetRangeEnd", rb_clang_getRangeEnd, 1);
    METHOD("GetRangeStart", rb_clang_getRangeStart, 1);
    METHOD("GetRemappings", rb_clang_getRemappings, 1);
    METHOD("GetRemappingsFromFileList", rb_clang_getRemappingsFromFileList, 1);
    METHOD("GetResultType", rb_clang_getResultType, 1);
    METHOD("GetSkippedRanges", rb_clang_getSkippedRanges, 1);
    METHOD("GetSpecializedCursorTemplate", rb_clang_getSpecializedCursorTemplate, 1);
    METHOD("GetSpellingLocation", rb_clang_getSpellingLocation, 1);
    METHOD("GetTemplateCursorKind", rb_clang_getTemplateCursorKind, 1);
    METHOD("GetTokenExtent", rb_clang_getTokenExtent, 1);
    METHOD("GetTokenKind", rb_clang_getTokenKind, 1);
    METHOD("GetTokenLocation", rb_clang_getTokenLocation, 1);
    METHOD("GetTokenSpelling", rb_clang_getTokenSpelling, 1);
    METHOD("GetTranslationUnitCursor", rb_clang_getTranslationUnitCursor, 1);
    METHOD("GetTranslationUnitSpelling", rb_clang_getTranslationUnitSpelling, 1);
    METHOD("GetTranslationUnitTargetInfo", rb_clang_getTranslationUnitTargetInfo, 1);
    METHOD("GetTuResourceUsageName", rb_clang_getTUResourceUsageName, 1);
    METHOD("GetTypeDeclaration", rb_clang_getTypeDeclaration, 1);
    METHOD("GetTypedefDeclUnderlyingType", rb_clang_getTypedefDeclUnderlyingType, 1);
    METHOD("GetTypedefName", rb_clang_getTypedefName, 1);
    METHOD("GetTypeKindSpelling", rb_clang_getTypeKindSpelling, 1);
    METHOD("GetTypeSpelling", rb_clang_getTypeSpelling, 1);
    METHOD("HashCursor", rb_clang_hashCursor, 1);
    METHOD("HtmlStartTagGetAttrName", rb_clang_HTMLStartTag_getAttrName, 1);
    METHOD("HtmlStartTagGetAttrValue", rb_clang_HTMLStartTag_getAttrValue, 1);
    METHOD("HtmlStartTagGetNumAttrs", rb_clang_HTMLStartTag_getNumAttrs, 1);
    METHOD("HtmlStartTagCommentIsSelfClosing", rb_clang_HTMLStartTagComment_isSelfClosing, 1);
    METHOD("HtmlTagCommentGetAsString", rb_clang_HTMLTagComment_getAsString, 1);
    METHOD("HtmlTagCommentGetTagName", rb_clang_HTMLTagComment_getTagName, 1);
    METHOD("IndexGetClientContainer", rb_clang_index_getClientContainer, 1);
    METHOD("IndexGetClientEntity", rb_clang_index_getClientEntity, 1);
    METHOD("IndexGetCxxClassDeclInfo", rb_clang_index_getCXXClassDeclInfo, 1);
    METHOD("IndexGetIbOutletCollectionAttrInfo", rb_clang_index_getIBOutletCollectionAttrInfo, 1);
    METHOD("IndexGetObjCCategoryDeclInfo", rb_clang_index_getObjCCategoryDeclInfo, 1);
    METHOD("IndexGetObjCContainerDeclInfo", rb_clang_index_getObjCContainerDeclInfo, 1);
    METHOD("IndexGetObjCInterfaceDeclInfo", rb_clang_index_getObjCInterfaceDeclInfo, 1);
    METHOD("IndexGetObjCPropertyDeclInfo", rb_clang_index_getObjCPropertyDeclInfo, 1);
    METHOD("IndexGetObjCProtocolRefListInfo", rb_clang_index_getObjCProtocolRefListInfo, 1);
    METHOD("IndexIsEntityObjCContainerKind", rb_clang_index_isEntityObjCContainerKind, 1);
    METHOD("IndexSetClientContainer", rb_clang_index_setClientContainer, 1);
    METHOD("IndexSetClientEntity", rb_clang_index_setClientEntity, 1);
    METHOD("IndexActionCreate", rb_clang_IndexAction_create, 1);
    METHOD("IndexActionDispose", rb_clang_IndexAction_dispose, 1);
    METHOD("IndexLocGetCxSourceLocation", rb_clang_indexLoc_getCXSourceLocation, 1);
    METHOD("IndexLocGetFileLocation", rb_clang_indexLoc_getFileLocation, 1);
    METHOD("IndexSourceFile", rb_clang_indexSourceFile, 1);
    METHOD("IndexSourceFileFullArgv", rb_clang_indexSourceFileFullArgv, 1);
    METHOD("IndexTranslationUnit", rb_clang_indexTranslationUnit, 1);
    METHOD("InlineCommandCommentGetArgText", rb_clang_InlineCommandComment_getArgText, 1);
    METHOD("InlineCommandCommentGetCommandName", rb_clang_InlineCommandComment_getCommandName, 1);
    METHOD("InlineCommandCommentGetNumArgs", rb_clang_InlineCommandComment_getNumArgs, 1);
    METHOD("InlineCommandCommentGetRenderKind", rb_clang_InlineCommandComment_getRenderKind, 1);
    METHOD("InlineContentCommentHasTrailingNewline", rb_clang_InlineContentComment_hasTrailingNewline, 1);
    METHOD("IsAttribute", rb_clang_isAttribute, 1);
    METHOD("IsConstQualifiedType", rb_clang_isConstQualifiedType, 1);
    METHOD("IsCursorDefinition", rb_clang_isCursorDefinition, 1);
    METHOD("IsDeclaration", rb_clang_isDeclaration, 1);
    METHOD("IsExpression", rb_clang_isExpression, 1);
    METHOD("IsFileMultipleIncludeGuarded", rb_clang_isFileMultipleIncludeGuarded, 2);
    METHOD("IsFunctionTypeVariadic", rb_clang_isFunctionTypeVariadic, 1);
    METHOD("IsInvalid", rb_clang_isInvalid, 1);
    METHOD("IsPodType", rb_clang_isPODType, 1);
    METHOD("IsPreprocessing", rb_clang_isPreprocessing, 1);
    METHOD("IsReference", rb_clang_isReference, 1);
    METHOD("IsRestrictQualifiedType", rb_clang_isRestrictQualifiedType, 1);
    METHOD("IsStatement", rb_clang_isStatement, 1);
    METHOD("IsTranslationUnit", rb_clang_isTranslationUnit, 1);
    METHOD("IsUnexposed", rb_clang_isUnexposed, 1);
    METHOD("IsVirtualBase", rb_clang_isVirtualBase, 1);
    METHOD("IsVolatileQualifiedType", rb_clang_isVolatileQualifiedType, 1);
    METHOD("LoadDiagnostics", rb_clang_loadDiagnostics, 1);
    METHOD("LocationIsFromMainFile", rb_clang_Location_isFromMainFile, 1);
    METHOD("LocationIsInSystemHeader", rb_clang_Location_isInSystemHeader, 1);
    METHOD("ModuleGetAstFile", rb_clang_Module_getASTFile, 1);
    METHOD("ModuleGetFullName", rb_clang_Module_getFullName, 1);
    METHOD("ModuleGetName", rb_clang_Module_getName, 1);
    METHOD("ModuleGetNumTopLevelHeaders", rb_clang_Module_getNumTopLevelHeaders, 2);
    METHOD("ModuleGetParent", rb_clang_Module_getParent, 1);
    METHOD("ModuleGetTopLevelHeader", rb_clang_Module_getTopLevelHeader, 1);
    METHOD("ModuleIsSystem", rb_clang_Module_isSystem, 1);
    METHOD("ModuleMapDescriptorCreate", rb_clang_ModuleMapDescriptor_create, 1);
    METHOD("ModuleMapDescriptorDispose", rb_clang_ModuleMapDescriptor_dispose, 1);
    METHOD("ModuleMapDescriptorSetFrameworkModuleName", rb_clang_ModuleMapDescriptor_setFrameworkModuleName, 1);
    METHOD("ModuleMapDescriptorSetUmbrellaHeader", rb_clang_ModuleMapDescriptor_setUmbrellaHeader, 1);
    METHOD("ModuleMapDescriptorWriteToBuffer", rb_clang_ModuleMapDescriptor_writeToBuffer, 1);
    METHOD("ParamCommandCommentGetDirection", rb_clang_ParamCommandComment_getDirection, 1);
    METHOD("ParamCommandCommentGetParamIndex", rb_clang_ParamCommandComment_getParamIndex, 1);
    METHOD("ParamCommandCommentGetParamName", rb_clang_ParamCommandComment_getParamName, 1);
    METHOD("ParamCommandCommentIsDirectionExplicit", rb_clang_ParamCommandComment_isDirectionExplicit, 1);
    METHOD("ParamCommandCommentIsParamIndexValid", rb_clang_ParamCommandComment_isParamIndexValid, 1);
    METHOD("ParseTranslationUnit", rb_clang_parseTranslationUnit, 1);
    METHOD("ParseTranslationUnit2", rb_clang_parseTranslationUnit2, 1);
    METHOD("ParseTranslationUnit2FullArgv", rb_clang_parseTranslationUnit2FullArgv, 1);
    METHOD("RangeIsNull", rb_clang_Range_isNull, 1);
    METHOD("RemapDispose", rb_clang_remap_dispose, 1);
    METHOD("RemapGetFilenames", rb_clang_remap_getFilenames, 1);
    METHOD("RemapGetNumFiles", rb_clang_remap_getNumFiles, 1);
    METHOD("ReparseTranslationUnit", rb_clang_reparseTranslationUnit, 1);
    METHOD("SaveTranslationUnit", rb_clang_saveTranslationUnit, 1);
    METHOD("SortCodeCompletionResults", rb_clang_sortCodeCompletionResults, 1);
    METHOD("SuspendTranslationUnit", rb_clang_suspendTranslationUnit, 1);
    METHOD("TargetInfoDispose", rb_clang_TargetInfo_dispose, 1);
    METHOD("TargetInfoGetPointerWidth", rb_clang_TargetInfo_getPointerWidth, 1);
    METHOD("TargetInfoGetTriple", rb_clang_TargetInfo_getTriple, 1);
    METHOD("TextCommentGetText", rb_clang_TextComment_getText, 1);
    METHOD("ToggleCrashRecovery", rb_clang_toggleCrashRecovery, 1);
    METHOD("Tokenize", rb_clang_tokenize, 1);
    METHOD("TParamCommandCommentGetDepth", rb_clang_TParamCommandComment_getDepth, 1);
    METHOD("TParamCommandCommentGetIndex", rb_clang_TParamCommandComment_getIndex, 1);
    METHOD("TParamCommandCommentGetParamName", rb_clang_TParamCommandComment_getParamName, 1);
    METHOD("TParamCommandCommentIsParamPositionValid", rb_clang_TParamCommandComment_isParamPositionValid, 1);
    METHOD("TypeGetAlignOf", rb_clang_Type_getAlignOf, 1);
    METHOD("TypeGetClassType", rb_clang_Type_getClassType, 1);
    METHOD("TypeGetCxxRefQualifier", rb_clang_Type_getCXXRefQualifier, 1);
    METHOD("TypeGetNamedType", rb_clang_Type_getNamedType, 1);
    METHOD("TypeGetNumTemplateArguments", rb_clang_Type_getNumTemplateArguments, 1);
    METHOD("TypeGetObjCEncoding", rb_clang_Type_getObjCEncoding, 1);
    METHOD("TypeGetOffsetOf", rb_clang_Type_getOffsetOf, 2);
    METHOD("TypeGetSizeOf", rb_clang_Type_getSizeOf, 1);
    METHOD("TypeGetTemplateArgumentAsType", rb_clang_Type_getTemplateArgumentAsType, 2);
    METHOD("TypeIsTransparentTagTypedef", rb_clang_Type_isTransparentTagTypedef, 1);
    METHOD("TypeVisitFields", rb_clang_Type_visitFields, 1);
    METHOD("VerbatimBlockLineCommentGetText", rb_clang_VerbatimBlockLineComment_getText, 1);
    METHOD("VerbatimLineCommentGetText", rb_clang_VerbatimLineComment_getText, 1);
    METHOD("VirtualFileOverlayAddFileMapping", rb_clang_VirtualFileOverlay_addFileMapping, 1);
    METHOD("VirtualFileOverlayCreate", rb_clang_VirtualFileOverlay_create, 1);
    METHOD("VirtualFileOverlayDispose", rb_clang_VirtualFileOverlay_dispose, 1);
    METHOD("VirtualFileOverlaySetCaseSensitivity", rb_clang_VirtualFileOverlay_setCaseSensitivity, 1);
    METHOD("VirtualFileOverlayWriteToBuffer", rb_clang_VirtualFileOverlay_writeToBuffer, 1);
    METHOD("VisitChildren", rb_clang_visitChildren, 1);
}

static VALUE rb_clang_createIndex(VALUE mod, VALUE exlude, VALUE display) {
    CXIndex index = clang_createIndex(RTEST(exlude), RTEST(display));
    RETURN_WRAP(index, rb_cCXIndex);
}

static VALUE rb_clang_disposeIndex(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXIndex);
    clang_disposeIndex(&x);
    return Qnil;
}

WRAP_BOOL_FUNC(rb_clang_Module_isSystem, clang_Module_isSystem, CXModule)
WRAP_BOOL_FUNC(rb_clang_ParamCommandComment_isDirectionExplicit, clang_ParamCommandComment_isDirectionExplicit, CXComment)
WRAP_BOOL_FUNC(rb_clang_ParamCommandComment_isParamIndexValid, clang_ParamCommandComment_isParamIndexValid, CXComment)
WRAP_BOOL_FUNC(rb_clang_Range_isNull, clang_Range_isNull, CXSourceRange)
WRAP_BOOL_FUNC(rb_clang_TParamCommandComment_isParamPositionValid, clang_TParamCommandComment_isParamPositionValid, CXComment)
WRAP_BOOL_FUNC(rb_clang_Type_isTransparentTagTypedef, clang_Type_isTransparentTagTypedef, CXType)
WRAP_BOOL_FUNC(rb_clang_Cursor_isAnonymous, clang_Cursor_isAnonymous, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isBitField, clang_Cursor_isBitField, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isDynamicCall, clang_Cursor_isDynamicCall, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Location_isInSystemHeader, clang_Location_isInSystemHeader, CXSourceLocation)
WRAP_BOOL_FUNC(rb_clang_Comment_isWhitespace, clang_Comment_isWhitespace, CXComment)
WRAP_BOOL_FUNC(rb_clang_Cursor_isFunctionInlined, clang_Cursor_isFunctionInlined, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isMacroBuiltin, clang_Cursor_isMacroBuiltin, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isMacroFunctionLike, clang_Cursor_isMacroFunctionLike, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isNull, clang_Cursor_isNull, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isObjCOptional, clang_Cursor_isObjCOptional, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Cursor_isVariadic, clang_Cursor_isVariadic, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXConstructor_isConvertingConstructor, clang_CXXConstructor_isConvertingConstructor, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXConstructor_isCopyConstructor, clang_CXXConstructor_isCopyConstructor, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXConstructor_isDefaultConstructor, clang_CXXConstructor_isDefaultConstructor, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXConstructor_isMoveConstructor, clang_CXXConstructor_isMoveConstructor, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXField_isMutable, clang_CXXField_isMutable, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXMethod_isConst, clang_CXXMethod_isConst, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXMethod_isDefaulted, clang_CXXMethod_isDefaulted, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXMethod_isPureVirtual, clang_CXXMethod_isPureVirtual, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXMethod_isStatic, clang_CXXMethod_isStatic, CXCursor)
WRAP_BOOL_FUNC(rb_clang_CXXMethod_isVirtual, clang_CXXMethod_isVirtual, CXCursor)
WRAP_BOOL_FUNC(rb_clang_isConstQualifiedType, clang_isConstQualifiedType, CXType)
WRAP_BOOL_FUNC(rb_clang_isCursorDefinition, clang_isCursorDefinition, CXCursor)
WRAP_BOOL_FUNC(rb_clang_Location_isFromMainFile, clang_Location_isFromMainFile, CXSourceLocation)
WRAP_BOOL_FUNC(rb_clang_EvalResult_isUnsignedInt, clang_EvalResult_isUnsignedInt, CXEvalResult)
WRAP_BOOL_FUNC(rb_clang_CXXRecord_isAbstract, clang_CXXRecord_isAbstract, CXCursor)
WRAP_BOOL_FUNC(rb_clang_EnumDecl_isScoped, clang_EnumDecl_isScoped, CXCursor)
WRAP_BOOL_FUNC(rb_clang_isFunctionTypeVariadic, clang_isFunctionTypeVariadic, CXType)
WRAP_BOOL_FUNC(rb_clang_isPODType, clang_isPODType, CXType)
WRAP_BOOL_FUNC(rb_clang_isRestrictQualifiedType, clang_isRestrictQualifiedType, CXType)
WRAP_BOOL_FUNC(rb_clang_isVirtualBase, clang_isVirtualBase, CXCursor)
WRAP_BOOL_FUNC(rb_clang_isVolatileQualifiedType, clang_isVolatileQualifiedType, CXType)
WRAP_BOOL_FUNC(rb_clang_HTMLStartTagComment_isSelfClosing, clang_HTMLStartTagComment_isSelfClosing, CXComment)
WRAP_BOOL_FUNC(rb_clang_Cursor_hasAttrs, clang_Cursor_hasAttrs, CXCursor)
WRAP_BOOL_FUNC(rb_clang_InlineContentComment_hasTrailingNewline, clang_InlineContentComment_hasTrailingNewline, CXComment)

WRAP_INT_FUNC(rb_clang_Cursor_getObjCSelectorIndex, clang_Cursor_getObjCSelectorIndex, CXCursor)
WRAP_INT_FUNC(rb_clang_getNumArgTypes, clang_getNumArgTypes, CXType)
WRAP_INT_FUNC(rb_clang_Type_getNumTemplateArguments, clang_Type_getNumTemplateArguments, CXType)
WRAP_INT_FUNC(rb_clang_Cursor_getNumArguments, clang_Cursor_getNumArguments, CXCursor)
WRAP_INT_FUNC(rb_clang_Cursor_getNumTemplateArguments, clang_Cursor_getNumTemplateArguments, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorAvailability, clang_getCursorAvailability, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorExceptionSpecificationType, clang_getCursorExceptionSpecificationType, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorKind, clang_getCursorKind, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorLanguage, clang_getCursorLanguage, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorLinkage, clang_getCursorLinkage, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorTLSKind, clang_getCursorTLSKind, CXCursor)
WRAP_INT_FUNC(rb_clang_getCursorVisibility, clang_getCursorVisibility, CXCursor)
WRAP_INT_FUNC(rb_clang_Cursor_getStorageClass, clang_Cursor_getStorageClass, CXCursor)
WRAP_INT_FUNC(rb_clang_Type_getCXXRefQualifier, clang_Type_getCXXRefQualifier, CXType)
WRAP_INT_FUNC(rb_clang_getCXXAccessSpecifier, clang_getCXXAccessSpecifier, CXCursor)
WRAP_INT_FUNC(rb_clang_getCompletionAvailability, clang_getCompletionAvailability, CXCompletionString)
WRAP_INT_FUNC(rb_clang_getFieldDeclBitWidth, clang_getFieldDeclBitWidth, CXCursor)
WRAP_INT_FUNC(rb_clang_getExceptionSpecificationType, clang_getExceptionSpecificationType, CXType)
WRAP_INT_FUNC(rb_clang_getDiagnosticSeverity, clang_getDiagnosticSeverity, CXDiagnostic)

WRAP_UINT_FUNC(rb_clang_getNumCompletionChunks, clang_getNumCompletionChunks, CXCompletionString)
WRAP_UINT_FUNC(rb_clang_getNumDiagnostics, clang_getNumDiagnostics, CXTranslationUnit)
WRAP_UINT_FUNC(rb_clang_getNumDiagnosticsInSet, clang_getNumDiagnosticsInSet, CXDiagnosticSet)
WRAP_UINT_FUNC(rb_clang_getNumOverloadedDecls, clang_getNumOverloadedDecls, CXCursor)
WRAP_UINT_FUNC(rb_clang_getDiagnosticNumFixIts, clang_getDiagnosticNumFixIts, CXDiagnostic)
WRAP_UINT_FUNC(rb_clang_getDiagnosticNumRanges, clang_getDiagnosticNumRanges, CXDiagnostic)
WRAP_UINT_FUNC(rb_clang_getCompletionNumAnnotations, clang_getCompletionNumAnnotations, CXCompletionString)
WRAP_UINT_FUNC(rb_clang_remap_getNumFiles, clang_remap_getNumFiles, CXRemapping)
WRAP_UINT_FUNC(rb_clang_InlineCommandComment_getNumArgs, clang_InlineCommandComment_getNumArgs, CXComment)
WRAP_UINT_FUNC(rb_clang_HTMLStartTag_getNumAttrs, clang_HTMLStartTag_getNumAttrs, CXComment)
WRAP_UINT_FUNC(rb_clang_BlockCommandComment_getNumArgs, clang_BlockCommandComment_getNumArgs, CXComment)
WRAP_UINT_FUNC(rb_clang_Cursor_getObjCDeclQualifiers, clang_Cursor_getObjCDeclQualifiers, CXCursor)
WRAP_UINT_FUNC(rb_clang_getAddressSpace, clang_getAddressSpace, CXType)
WRAP_UINT_FUNC(rb_clang_getCompletionPriority, clang_getCompletionPriority, CXCompletionString)
WRAP_UINT_FUNC(rb_clang_getDiagnosticCategory, clang_getDiagnosticCategory, CXDiagnostic)

WRAP_STRING_FUNC(rb_clang_getDiagnosticSpelling, clang_getDiagnosticSpelling, CXDiagnostic)
WRAP_STRING_FUNC(rb_clang_getCompletionBriefComment, clang_getCompletionBriefComment, CXCompletionString)
WRAP_STRING_FUNC(rb_clang_getDeclObjCTypeEncoding, clang_getDeclObjCTypeEncoding, CXCursor)
WRAP_STRING_FUNC(rb_clang_getDiagnosticCategoryText, clang_getDiagnosticCategoryText, CXDiagnostic)
WRAP_STRING_FUNC(rb_clang_BlockCommandComment_getCommandName, clang_BlockCommandComment_getCommandName, CXComment)
WRAP_STRING_FUNC(rb_clang_Type_getObjCEncoding, clang_Type_getObjCEncoding, CXType)
WRAP_STRING_FUNC(rb_clang_getCursorSpelling, clang_getCursorSpelling, CXCursor)
WRAP_STRING_FUNC(rb_clang_getCursorDisplayName, clang_getCursorDisplayName, CXCursor)
WRAP_STRING_FUNC(rb_clang_getCursorUSR, clang_getCursorUSR, CXCursor)
WRAP_STRING_FUNC(rb_clang_Cursor_getBriefCommentText, clang_Cursor_getBriefCommentText, CXCursor)
WRAP_STRING_FUNC(rb_clang_Cursor_getMangling, clang_Cursor_getMangling, CXCursor)
WRAP_STRING_FUNC(rb_clang_Cursor_getRawCommentText, clang_Cursor_getRawCommentText, CXCursor)

WRAP_DISPOSE_FUNC(rb_clang_disposeCodeCompleteResults, clang_disposeCodeCompleteResults, CXCodeCompleteResults)
WRAP_DISPOSE_FUNC(rb_clang_disposeCXCursorSet, clang_disposeCXCursorSet, CXCursorSet)
WRAP_DISPOSE_FUNC(rb_clang_disposeCXPlatformAvailability, clang_disposeCXPlatformAvailability, CXPlatformAvailability)
WRAP_DISPOSE_FUNC(rb_clang_disposeSourceRangeList, clang_disposeSourceRangeList, CXSourceRangeList)
WRAP_DISPOSE_FUNC(rb_clang_disposeDiagnostic, clang_disposeDiagnostic, CXDiagnostic)
WRAP_DISPOSE_FUNC(rb_clang_disposeDiagnosticSet, clang_disposeDiagnosticSet, CXDiagnosticSet)
WRAP_DISPOSE_FUNC(rb_clang_disposeOverriddenCursors, clang_disposeOverriddenCursors, CXCursor)
WRAP_DISPOSE_FUNC(rb_clang_disposeStringSet, clang_disposeStringSet, CXStringSet)
WRAP_DISPOSE_FUNC(rb_clang_EvalResult_dispose, clang_EvalResult_dispose, CXEvalResult)
WRAP_DISPOSE_FUNC(rb_clang_disposeTranslationUnit, clang_disposeTranslationUnit, CXTranslationUnit)
WRAP_DISPOSE_FUNC(rb_clang_IndexAction_dispose, clang_IndexAction_dispose, CXIndexAction)
WRAP_DISPOSE_FUNC(rb_clang_VirtualFileOverlay_dispose, clang_VirtualFileOverlay_dispose, CXVirtualFileOverlay)
WRAP_DISPOSE_FUNC(rb_clang_TargetInfo_dispose, clang_TargetInfo_dispose, CXTargetInfo)
WRAP_DISPOSE_FUNC(rb_clang_remap_dispose, clang_remap_dispose, CXRemapping)
WRAP_DISPOSE_FUNC(rb_clang_ModuleMapDescriptor_dispose, clang_ModuleMapDescriptor_dispose, CXModuleMapDescriptor)
// WRAP_DISPOSE_FUNC(rb_clang_CompilationDatabase_dispose, clang_CompilationDatabase_dispose)
// WRAP_DISPOSE_FUNC(rb_clang_CompileCommands_dispose, clang_CompileCommands_dispose, Compi)

#pragma region 

static VALUE rb_clang_isPreprocessing(VALUE mod, VALUE obj) {
    return clang_isPreprocessing(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isInvalid(VALUE mod, VALUE obj) {
    return clang_isInvalid(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isAttribute(VALUE mod, VALUE obj) {
    return clang_isAttribute(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isDeclaration(VALUE mod, VALUE obj) {
    return clang_isDeclaration(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isReference(VALUE mod, VALUE obj) {
    return clang_isReference(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isExpression(VALUE mod, VALUE obj) {
    return clang_isExpression(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_index_isEntityObjCContainerKind(VALUE mod, VALUE obj) {
    return clang_index_isEntityObjCContainerKind(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isTranslationUnit(VALUE mod, VALUE obj) {
    return clang_isTranslationUnit(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isStatement(VALUE mod, VALUE obj) {
    return clang_isStatement(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isUnexposed(VALUE mod, VALUE obj) {
    return clang_isUnexposed(NUM2INT(obj)) ? Qtrue : Qfalse;
}

static VALUE rb_clang_File_isEqual(VALUE mod, VALUE file1, VALUE file2) {
    CXFile *f1, *f2;
    Data_Get_Struct(file1, CXFile, f1);
    Data_Get_Struct(file2, CXFile, f2);
    return clang_File_isEqual(&f1, &f2) ? Qtrue : Qfalse;
}

static VALUE rb_clang_isFileMultipleIncludeGuarded(VALUE mod, VALUE trans_unit, VALUE file) {
    CXTranslationUnit *tu;
    CXFile *f;
    Data_Get_Struct(trans_unit, CXTranslationUnit, tu);
    Data_Get_Struct(file, CXFile, f);
    return clang_isFileMultipleIncludeGuarded(*tu, *f) ? Qtrue : Qfalse;
}

static VALUE rb_clang_Cursor_isExternalSymbol(VALUE mod, VALUE cursor, VALUE language, VALUE def, VALUE generated) {
    CXCursor *c;
    CXString *l, *d;
    unsigned int g = NUM2UINT(generated);
    return clang_Cursor_isExternalSymbol(*c, l, d, &g) ? Qtrue : Qfalse;
}

static VALUE rb_clang_getCursor(VALUE mod, VALUE unit, VALUE location) {
    CXTranslationUnit *tu;
    CXSourceLocation *loc;
    Data_Get_Struct(unit, CXTranslationUnit, tu);
    Data_Get_Struct(location, CXSourceLocation, loc);
    CXCursor cursor = clang_getCursor(*tu, *loc);
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getCursorCompletionString(VALUE mod, VALUE obj) {
    CURSOR();
    CXCompletionString str = clang_getCursorCompletionString(*x);
    RETURN_WRAP(&str, rb_cCXCompletionString);
}

static VALUE rb_clang_getCursorDefinition(VALUE mod, VALUE obj) {
    CURSOR();
    CXCursor cursor = clang_getCursorDefinition(*x);
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getCursorExtent(VALUE mod, VALUE obj) {
    CURSOR();
    CXSourceRange range = clang_getCursorExtent(*x);
    RETURN_WRAP(&range, rb_cCXSourceRange);
}

static VALUE rb_clang_getCursorKindSpelling(VALUE mod, VALUE obj) {
    CXString str = clang_getCursorKindSpelling(NUM2INT(obj));
    RETURN_STRING(&str);
}

static VALUE rb_clang_getCursorLexicalParent(VALUE mod, VALUE obj) {
    CURSOR();
    CXCursor cursor = clang_getCursorLexicalParent(*x);
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getCursorLocation(VALUE mod, VALUE obj) {
    CURSOR();
    CXSourceLocation loc = clang_getCursorLocation(*x);
    RETURN_WRAP(&loc, rb_cCXSourceLocation);
}

static VALUE rb_clang_getCursorReferenced(VALUE mod, VALUE obj) {
    CURSOR();
    CXCursor cursor = clang_getCursorReferenced(*x);
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getCursorResultType(VALUE mod, VALUE obj) {
    CURSOR();
    CXType t = clang_getCursorResultType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getCursorSemanticParent(VALUE mod, VALUE obj) {
    CURSOR();
    CXCursor cursor = clang_getCursorSemanticParent(*x);
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getCursorType(VALUE mod, VALUE obj) {
    CURSOR();
    CXType type = clang_getCursorType(*x);
    RETURN_TYPE(&type);
}

static VALUE rb_clang_Cursor_getArgument(VALUE mod, VALUE cursor, VALUE index) {
    UNWRAP(cursor, CXCursor);
    CXCursor c = clang_Cursor_getArgument(*x, NUM2UINT(index));
    RETURN_CURSOR(&c);
}

static VALUE rb_clang_Cursor_getCommentRange(VALUE mod, VALUE obj) {
    CURSOR();
    CXSourceRange range = clang_Cursor_getCommentRange(*x);
    RETURN_WRAP(&range, rb_cCXSourceRange);
}

static VALUE rb_clang_Cursor_getModule(VALUE mod, VALUE obj) {
    CURSOR();
    CXModule m = clang_Cursor_getModule(*x);
    RETURN_WRAP(&m, rb_cCXModule);
}

static VALUE rb_clang_Cursor_getObjCPropertyAttributes(VALUE mod, VALUE obj, VALUE index) {
    CURSOR();
    return UINT2NUM(clang_Cursor_getObjCPropertyAttributes(*x, NUM2UINT(index)));
}

static VALUE rb_clang_Cursor_getOffsetOfField(VALUE mod, VALUE obj) {
    CURSOR();
    return LL2NUM(clang_Cursor_getOffsetOfField(*x));
}

static VALUE rb_clang_Cursor_getParsedComment(VALUE mod, VALUE obj) {
    CURSOR();
    CXComment com = clang_Cursor_getParsedComment(*x);
    RETURN_WRAP(&com, rb_cCXComment);
}

static VALUE rb_clang_Cursor_getReceiverType(VALUE mod, VALUE obj) {
    CURSOR();
    CXType type = clang_Cursor_getReceiverType(*x);
    RETURN_TYPE(&type);
}

static VALUE rb_clang_Cursor_getTranslationUnit(VALUE mod, VALUE obj) {
    CURSOR();
    CXTranslationUnit unit = clang_Cursor_getTranslationUnit(*x);
    RETURN_TRANS_UNIT(&unit);
}

static VALUE rb_clang_Cursor_getSpellingNameRange(VALUE mod, VALUE obj, VALUE index, VALUE options) {
    CURSOR();
    CXSourceRange range = clang_Cursor_getSpellingNameRange(*x, NUM2UINT(index), NUM2UINT(options));
    RETURN_WRAP(&range, rb_cCXSourceRange);
}

static VALUE rb_clang_Cursor_getTemplateArgumentKind(VALUE mod, VALUE obj, VALUE index) {
    CURSOR();
    return INT2NUM(clang_Cursor_getTemplateArgumentKind(*x, NUM2UINT(index)));
}

static VALUE rb_clang_Cursor_getTemplateArgumentType(VALUE mod, VALUE obj, VALUE index) {
    CURSOR();
    CXType type = clang_Cursor_getTemplateArgumentType(*x, NUM2UINT(index));
    RETURN_TYPE(&type);
}

static VALUE rb_clang_Cursor_getTemplateArgumentUnsignedValue(VALUE mod, VALUE obj, VALUE index) {
    CURSOR();
    return ULL2NUM(clang_Cursor_getTemplateArgumentUnsignedValue(*x, NUM2UINT(index)));
}

static VALUE rb_clang_Cursor_getTemplateArgumentValue(VALUE mod, VALUE obj, VALUE index) {
    CURSOR();
    return LL2NUM(clang_Cursor_getTemplateArgumentValue(*x, NUM2UINT(index)));
}

static VALUE rb_clang_Cursor_getCXXManglings(VALUE mod, VALUE obj) {
    CURSOR();
    CXStringSet *set = clang_Cursor_getCXXManglings(*x);
    RETURN_WRAP(set, rb_cCXStringSet);
}

static VALUE rb_clang_Cursor_getObjCManglings(VALUE mod, VALUE obj) {
    CURSOR();
    CXStringSet *set = clang_Cursor_getObjCManglings(*x);
    RETURN_WRAP(set, rb_cCXStringSet);
}

static VALUE rb_clang_disposeCXTUResourceUsage(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXTUResourceUsage);
    clang_disposeCXTUResourceUsage(*x);
    return Qnil;
}

static VALUE rb_clang_disposeString(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXString);
    clang_disposeString(*x);
    return Qnil;
}

static VALUE rb_clang_getNumElements(VALUE mod, VALUE obj) {
    TYPE();
    return LL2NUM(clang_getNumElements(*x));
}

static VALUE rb_clang_Module_getNumTopLevelHeaders(VALUE mod, VALUE obj, VALUE module) {
    UNWRAP(obj, CXTranslationUnit);
    CXModule *m;
    Data_Get_Struct(module, CXModule, m);
    return UINT2NUM(clang_Module_getNumTopLevelHeaders(*x, *m));
}

static VALUE rb_clang_getCursorReferenceNameRange(VALUE mod, VALUE obj, VALUE flag, VALUE index) {
    CURSOR();
    CXSourceRange r = clang_getCursorReferenceNameRange(*x, NUM2UINT(flag), NUM2UINT(index));
    RETURN_WRAP(&r, rb_cCXSourceRange);
}

static VALUE rb_clang_BlockCommandComment_getParagraph(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXComment);
    CXComment c = clang_BlockCommandComment_getParagraph(*x);
    RETURN_WRAP(&x, rb_cCXComment);
}

static VALUE rb_clang_Type_getAlignOf(VALUE mod, VALUE obj) {
    TYPE();
    return LL2NUM(clang_Type_getAlignOf(*x));
}

static VALUE rb_clang_Type_getClassType(VALUE mod, VALUE obj) {
    TYPE();
    CXType t = clang_Type_getClassType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_Type_getNamedType(VALUE mod, VALUE obj) {
    TYPE();
    CXType t = clang_Type_getNamedType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_Type_getOffsetOf(VALUE mod, VALUE obj, VALUE s) {
    TYPE();
    return LL2NUM(clang_Type_getOffsetOf(*x, StringValueCStr(s)));
}

static VALUE rb_clang_Type_getSizeOf(VALUE mod, VALUE obj) {
    TYPE();
    return LL2NUM(clang_Type_getSizeOf(*x));
}

static VALUE rb_clang_Type_getTemplateArgumentAsType(VALUE mod, VALUE obj, VALUE index) {
    TYPE();
    CXType t = clang_Type_getTemplateArgumentAsType(*x, NUM2UINT(index));
    RETURN_TYPE(&t);
}

static VALUE rb_clang_Cursor_Evaluate(VALUE mod, VALUE obj) {
    CURSOR();
    CXEvalResult r = clang_Cursor_Evaluate(*x);
    return Data_Wrap_Struct(rb_cCXEvalResult, NULL, clang_EvalResult_dispose, &r);
}

#pragma endregion

static VALUE rb_clang_getAllSkippedRanges(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXTranslationUnit);
    CXSourceRangeList *l = clang_getAllSkippedRanges(*x);
    return Data_Wrap_Struct(rb_cCXSourceRangeList, NULL, clang_disposeSourceRangeList, l);
}

static VALUE rb_clang_getArgType(VALUE mod, VALUE obj, VALUE index) {
    TYPE();
    CXType t = clang_getArgType(*x, NUM2UINT(index));
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getArrayElementType(VALUE mod, VALUE obj) {
    TYPE();
    CXType t = clang_getArrayElementType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getArraySize(VALUE mod, VALUE obj) {
    TYPE();
    return LL2NUM(clang_getArraySize(*x));
}

static VALUE rb_clang_getBuildSessionTimestamp(VALUE mod, VALUE obj) {
    return ULL2NUM(clang_getBuildSessionTimestamp());
}

static VALUE rb_clang_getCanonicalCursor(VALUE mod, VALUE obj) {
    CURSOR();
    CXCursor cursor = clang_getCanonicalCursor(*x);
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getCanonicalType(VALUE mod, VALUE obj) {
    TYPE();
    CXType t = clang_getCanonicalType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getChildDiagnostics(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXDiagnostic);
    CXDiagnosticSet *set = clang_getChildDiagnostics(*x);
    return Data_Wrap_Struct(rb_cCXDiagnosticSet, NULL, clang_disposeDiagnosticSet, set);
}

static VALUE rb_clang_getClangVersion(VALUE mod, VALUE obj) {
    CXString str = clang_getClangVersion();
    RETURN_STRING(&str);
}

static VALUE rb_clang_getCString(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXString);
    return rb_str_new_cstr(clang_getCString(*x));
}

static VALUE rb_clang_getCXTUResourceUsage(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXTranslationUnit);
    CXTUResourceUsage r = clang_getCXTUResourceUsage(*x);
    return Data_Wrap_Struct(rb_cCXTUResourceUsage, NULL, clang_disposeCXTUResourceUsage, &r);
}

static VALUE rb_clang_getDiagnostic(VALUE mod, VALUE obj, VALUE index) {
    UNWRAP(obj, CXTranslationUnit);
    CXDiagnostic d = clang_getDiagnostic(*x, NUM2UINT(index));
    return Data_Wrap_Struct(rb_cCXDiagnostic, NULL, clang_disposeDiagnostic, &d);
}

static VALUE rb_clang_getDiagnosticCategoryName(VALUE mod, VALUE obj) {
    CXString str = clang_getDiagnosticCategoryName(NUM2UINT(obj));
    RETURN_STRING(&str);
}

static VALUE rb_clang_getDiagnosticLocation(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXDiagnostic);
    CXSourceLocation loc = clang_getDiagnosticLocation(*x);
    RETURN_WRAP(&loc, rb_cCXSourceLocation);
}

static VALUE rb_clang_getDiagnosticRange(VALUE mod, VALUE obj, VALUE range) {
    UNWRAP(obj, CXDiagnostic);
    CXSourceRange r = clang_getDiagnosticRange(*x, NUM2UINT(range));
    RETURN_WRAP(&r, rb_cCXSourceRange);
}

static VALUE rb_clang_getDiagnosticSetFromTU(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXTranslationUnit);
    CXDiagnosticSet set = clang_getDiagnosticSetFromTU(*x);
    RETURN_WRAP(&set, rb_cCXDiagnosticSet);
}

static VALUE rb_clang_getElementType(VALUE mod, VALUE obj) {
    TYPE();
    CXType t = clang_getElementType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getEnumConstantDeclUnsignedValue(VALUE mod, VALUE obj) {
    CURSOR();
    return ULL2NUM(clang_getEnumConstantDeclUnsignedValue(*x));
}

static VALUE rb_clang_getEnumConstantDeclValue(VALUE mod, VALUE obj) {
    CURSOR();
    return LL2NUM(clang_getEnumConstantDeclValue(*x));
}

static VALUE rb_clang_getEnumDeclIntegerType(VALUE mod, VALUE obj) {
    CURSOR();
    CXType t = clang_getEnumDeclIntegerType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getFile(VALUE mod, VALUE obj, VALUE filename) {
    UNWRAP(obj, CXTranslationUnit);
    CXFile file = clang_getFile(*x, StringValueCStr(filename));
    RETURN_WRAP(&file, rb_cCXFile);
}

static VALUE rb_clang_getFileContents(VALUE mod, VALUE obj, VALUE file, VALUE size) {
    UNWRAP(obj, CXTranslationUnit);
    CXFile *f;
    Data_Get_Struct(file, CXFile, f);
    return rb_str_new_cstr(clang_getFileContents(*x, *f, NUM2SIZET(size)));
}

static VALUE rb_clang_getFileTime(VALUE mod, VALUE obj) {
    UNWRAP(obj, CXFile);
    return TIMET2NUM(clang_getFileTime(*x));
}

static VALUE rb_clang_getFileUniqueID(VALUE mod, VALUE obj, VALUE file_id) {
    UNWRAP(obj, CXFile);
    CXFileUniqueID *id;
    Data_Get_Struct(file_id, CXFileUniqueID, id);
    return clang_getFileUniqueID(*x, id) ? Qtrue : Qfalse;
}

static VALUE rb_clang_getIBOutletCollectionType(VALUE mod, VALUE obj) {
    CURSOR();
    CXType t = clang_getIBOutletCollectionType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getIncludedFile(VALUE mod, VALUE obj) {
    CURSOR();
    CXFile file = clang_getIncludedFile(*x);
    RETURN_WRAP(&file, rb_cCXFile);
}

WRAP_INT_FUNC(rb_clang_getFunctionTypeCallingConv, clang_getFunctionTypeCallingConv, CXType)
WRAP_STRING_FUNC(rb_clang_getFileName, clang_getFileName, CXFile)

static VALUE rb_clang_getNullCursor(VALUE mod, VALUE obj) {
    CXCursor cursor = clang_getNullCursor();
    RETURN_CURSOR(&cursor);
}

static VALUE rb_clang_getNullLocation(VALUE mod, VALUE obj) {
    CXSourceLocation loc = clang_getNullLocation();
    RETURN_WRAP(&loc, rb_cCXSourceLocation);
}

static VALUE rb_clang_getNullRange(VALUE mod, VALUE obj) {
    CXSourceRange range = clang_getNullRange();
    RETURN_WRAP(&range, rb_cCXSourceRange);
}

static VALUE rb_clang_getPointeeType(VALUE mod, VALUE obj) {
    TYPE();
    CXType t = clang_getPointeeType(*x);
    RETURN_TYPE(&t);
}

static VALUE rb_clang_getPresumedLocation(VALUE mod, VALUE obj) {
    // clang_getPresumedLocation
    return Qnil;
}

static VALUE rb_clang_getRange(VALUE mod, VALUE obj) {
    // clang_getRange
    return Qnil;
}

static VALUE rb_clang_getRangeEnd(VALUE mod, VALUE obj) {
    // clang_getRangeEnd
    return Qnil;
}

static VALUE rb_clang_getRangeStart(VALUE mod, VALUE obj) {
    // clang_getRangeStart
    return Qnil;
}

static VALUE rb_clang_getRemappings(VALUE mod, VALUE obj) {
    // clang_getRemappings
    return Qnil;
}

static VALUE rb_clang_getRemappingsFromFileList(VALUE mod, VALUE obj) {
    // clang_getRemappingsFromFileList
    return Qnil;
}

static VALUE rb_clang_getResultType(VALUE mod, VALUE obj) {
    // clang_getResultType
    return Qnil;
}

static VALUE rb_clang_getSkippedRanges(VALUE mod, VALUE obj) {
    // clang_getSkippedRanges
    return Qnil;
}

static VALUE rb_clang_getSpecializedCursorTemplate(VALUE mod, VALUE obj) {
    // clang_getSpecializedCursorTemplate
    return Qnil;
}

static VALUE rb_clang_getSpellingLocation(VALUE mod, VALUE obj) {
    // clang_getSpellingLocation
    return Qnil;
}

static VALUE rb_clang_getTemplateCursorKind(VALUE mod, VALUE obj) {
    // clang_getTemplateCursorKind
    return Qnil;
}

static VALUE rb_clang_getTokenExtent(VALUE mod, VALUE obj) {
    // clang_getTokenExtent
    return Qnil;
}

static VALUE rb_clang_getTokenKind(VALUE mod, VALUE obj) {
    // clang_getTokenKind
    return Qnil;
}

static VALUE rb_clang_getTokenLocation(VALUE mod, VALUE obj) {
    // clang_getTokenLocation
    return Qnil;
}

static VALUE rb_clang_getTokenSpelling(VALUE mod, VALUE obj) {
    // clang_getTokenSpelling
    return Qnil;
}

static VALUE rb_clang_getTranslationUnitCursor(VALUE mod, VALUE obj) {
    // clang_getTranslationUnitCursor
    return Qnil;
}

static VALUE rb_clang_getTranslationUnitSpelling(VALUE mod, VALUE obj) {
    // clang_getTranslationUnitSpelling
    return Qnil;
}

static VALUE rb_clang_getTranslationUnitTargetInfo(VALUE mod, VALUE obj) {
    // clang_getTranslationUnitTargetInfo
    return Qnil;
}

static VALUE rb_clang_getTUResourceUsageName(VALUE mod, VALUE obj) {
    // clang_getTUResourceUsageName
    return Qnil;
}

static VALUE rb_clang_getTypeDeclaration(VALUE mod, VALUE obj) {
    // clang_getTypeDeclaration
    return Qnil;
}

static VALUE rb_clang_getTypedefDeclUnderlyingType(VALUE mod, VALUE obj) {
    // clang_getTypedefDeclUnderlyingType
    return Qnil;
}

static VALUE rb_clang_getTypedefName(VALUE mod, VALUE obj) {
    // clang_getTypedefName
    return Qnil;
}

static VALUE rb_clang_getTypeKindSpelling(VALUE mod, VALUE obj) {
    // clang_getTypeKindSpelling
    return Qnil;
}

static VALUE rb_clang_getTypeSpelling(VALUE mod, VALUE obj) {
    // clang_getTypeSpelling
    return Qnil;
}

static VALUE rb_clang_getCompletionAnnotation(VALUE mod, VALUE obj) {
    // clang_getCompletionAnnotation
    return Qnil;
}

static VALUE rb_clang_getCompletionChunkCompletionString(VALUE mod, VALUE obj) {
    // clang_getCompletionChunkCompletionString
    return Qnil;
}

static VALUE rb_clang_getCompletionChunkKind(VALUE mod, VALUE obj) {
    // clang_getCompletionChunkKind
    return Qnil;
}

static VALUE rb_clang_getCompletionChunkText(VALUE mod, VALUE obj) {
    // clang_getCompletionChunkText
    return Qnil;
}

static VALUE rb_clang_getCompletionParent(VALUE mod, VALUE obj) {
    // clang_getCompletionParent
    return Qnil;
}

static VALUE rb_clang_getDefinitionSpellingAndExtent(VALUE mod, VALUE obj) {
    // clang_getDefinitionSpellingAndExtent
    return Qnil;
}

static VALUE rb_clang_getDiagnosticInSet(VALUE mod, VALUE obj) {
    // clang_getDiagnosticInSet
    return Qnil;
}

static VALUE rb_clang_getDiagnosticFixIt(VALUE mod, VALUE obj) {
    // clang_getDiagnosticFixIt
    return Qnil;
}

static VALUE rb_clang_getDiagnosticOption(VALUE mod, VALUE obj) {
    // clang_getDiagnosticOption
    return Qnil;
}

static VALUE rb_clang_getExpansionLocation(VALUE mod, VALUE obj) {
    // clang_getExpansionLocation
    return Qnil;
}

static VALUE rb_clang_getFileLocation(VALUE mod, VALUE obj) {

    // clang_getFileLocation
    return Qnil;
}

static VALUE rb_clang_getInclusions(VALUE mod, VALUE obj) {
    // clang_getInclusions
    return Qnil;
}

static VALUE rb_clang_getInstantiationLocation(VALUE mod, VALUE obj) {
    // clang_getInstantiationLocation
    return Qnil;
}

static VALUE rb_clang_getLocation(VALUE mod, VALUE obj) {
    // clang_getLocation
    return Qnil;
}

static VALUE rb_clang_getLocationForOffset(VALUE mod, VALUE obj) {
    // clang_getLocationForOffset
    return Qnil;
}

static VALUE rb_clang_getModuleForFile(VALUE mod, VALUE obj) {
    // clang_getModuleForFile
    return Qnil;
}

static VALUE rb_clang_getOverloadedDecl(VALUE mod, VALUE obj) {
    // clang_getOverloadedDecl
    return Qnil;
}

static VALUE rb_clang_getOverriddenCursors(VALUE mod, VALUE obj) {
    // clang_getOverriddenCursors
    return Qnil;
}





static VALUE rb_clang_codeCompleteGetContainerKind(VALUE mod, VALUE obj) {
    // clang_codeCompleteGetContainerKind
    return Qnil;
}

static VALUE rb_clang_codeCompleteGetContainerUSR(VALUE mod, VALUE obj) {
    // clang_codeCompleteGetContainerUSR
    return Qnil;
}

static VALUE rb_clang_codeCompleteGetContexts(VALUE mod, VALUE obj) {
    // clang_codeCompleteGetContexts
    return Qnil;
}

static VALUE rb_clang_codeCompleteGetDiagnostic(VALUE mod, VALUE obj) {
    // clang_codeCompleteGetDiagnostic
    return Qnil;
}

static VALUE rb_clang_codeCompleteGetNumDiagnostics(VALUE mod, VALUE obj) {
    // clang_codeCompleteGetNumDiagnostics
    return Qnil;
}

static VALUE rb_clang_Comment_getNumChildren(VALUE mod, VALUE obj) {  // UINT
    // clang_Comment_getNumChildren
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getNumArgs(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getNumArgs
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getNumMappedSources(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getNumMappedSources
    return Qnil;
}

static VALUE rb_clang_codeCompleteGetObjCSelector(VALUE mod, VALUE obj) {
    // clang_codeCompleteGetObjCSelector
    return Qnil;
}

static VALUE rb_clang_Comment_getChild(VALUE mod, VALUE obj) {
    // clang_Comment_getChild
    return Qnil;
}

static VALUE rb_clang_Comment_getKind(VALUE mod, VALUE obj) {
    // clang_Comment_getKind
    return Qnil;
}

static VALUE rb_clang_CompilationDatabase_fromDirectory(VALUE mod, VALUE obj) {
    // clang_CompilationDatabase_fromDirectory
    return Qnil;
}

static VALUE rb_clang_CompilationDatabase_getAllCompileCommands(VALUE mod, VALUE obj) {
    // clang_CompilationDatabase_getAllCompileCommands
    return Qnil;
}

static VALUE rb_clang_CompilationDatabase_getCompileCommands(VALUE mod, VALUE obj) {
    // clang_CompilationDatabase_getCompileCommands
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getArg(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getArg
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getDirectory(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getDirectory
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getFilename(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getFilename
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getMappedSourceContent(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getMappedSourceContent
    return Qnil;
}

static VALUE rb_clang_CompileCommand_getMappedSourcePath(VALUE mod, VALUE obj) {
    // clang_CompileCommand_getMappedSourcePath
    return Qnil;
}

static VALUE rb_clang_CompileCommands_getCommand(VALUE mod, VALUE obj) {
    // clang_CompileCommands_getCommand
    return Qnil;
}

static VALUE rb_clang_CompileCommands_getSize(VALUE mod, VALUE obj) {
    // clang_CompileCommands_getSize
    return Qnil;
}

static VALUE rb_clang_constructUSR_ObjCCategory(VALUE mod, VALUE obj) {
    // clang_constructUSR_ObjCCategory
    return Qnil;
}

static VALUE rb_clang_constructUSR_ObjCClass(VALUE mod, VALUE obj) {
    // clang_constructUSR_ObjCClass
    return Qnil;
}

static VALUE rb_clang_constructUSR_ObjCIvar(VALUE mod, VALUE obj) {
    // clang_constructUSR_ObjCIvar
    return Qnil;
}

static VALUE rb_clang_constructUSR_ObjCMethod(VALUE mod, VALUE obj) {
    // clang_constructUSR_ObjCMethod
    return Qnil;
}

static VALUE rb_clang_constructUSR_ObjCProperty(VALUE mod, VALUE obj) {
    // clang_constructUSR_ObjCProperty
    return Qnil;
}

static VALUE rb_clang_constructUSR_ObjCProtocol(VALUE mod, VALUE obj) {
    // clang_constructUSR_ObjCProtocol
    return Qnil;
}

static VALUE rb_clang_createCXCursorSet(VALUE mod, VALUE obj) {
    // clang_createCXCursorSet
    return Qnil;
}

static VALUE rb_clang_createTranslationUnit(VALUE mod, VALUE obj) {
    // clang_createTranslationUnit
    return Qnil;
}

static VALUE rb_clang_createTranslationUnit2(VALUE mod, VALUE obj) {
    // clang_createTranslationUnit2
    return Qnil;
}

static VALUE rb_clang_createTranslationUnitFromSourceFile(VALUE mod, VALUE obj) {
    // clang_createTranslationUnitFromSourceFile
    return Qnil;
}

static VALUE rb_clang_CXCursorSet_contains(VALUE mod, VALUE obj) {
    // clang_CXCursorSet_contains
    return Qnil;
}

static VALUE rb_clang_CXCursorSet_insert(VALUE mod, VALUE obj) {
    // clang_CXCursorSet_insert
    return Qnil;
}

static VALUE rb_clang_CXIndex_getGlobalOptions(VALUE mod, VALUE obj) {
    // clang_CXIndex_getGlobalOptions
    return Qnil;
}

static VALUE rb_clang_CXIndex_setGlobalOptions(VALUE mod, VALUE obj) {
    // clang_CXIndex_setGlobalOptions
    return Qnil;
}

static VALUE rb_clang_CXIndex_setInvocationEmissionPathOption(VALUE mod, VALUE obj) {
    // clang_CXIndex_setInvocationEmissionPathOption
    return Qnil;
}

static VALUE rb_clang_defaultCodeCompleteOptions(VALUE mod, VALUE obj) {
    // clang_defaultCodeCompleteOptions
    return Qnil;
}

static VALUE rb_clang_defaultDiagnosticDisplayOptions(VALUE mod, VALUE obj) {
    // clang_defaultDiagnosticDisplayOptions
    return Qnil;
}

static VALUE rb_clang_defaultEditingTranslationUnitOptions(VALUE mod, VALUE obj) {
    // clang_defaultEditingTranslationUnitOptions
    return Qnil;
}

static VALUE rb_clang_defaultReparseOptions(VALUE mod, VALUE obj) {
    // clang_defaultReparseOptions
    return Qnil;
}

static VALUE rb_clang_defaultSaveOptions(VALUE mod, VALUE obj) {
    // clang_defaultSaveOptions
    return Qnil;
}

static VALUE rb_clang_enableStackTraces(VALUE mod, VALUE obj) {
    // clang_enableStackTraces
    return Qnil;
}

static VALUE rb_clang_equalCursors(VALUE mod, VALUE obj) {
    // clang_equalCursors
    return Qnil;
}

static VALUE rb_clang_equalLocations(VALUE mod, VALUE obj) {
    // clang_equalLocations
    return Qnil;
}

static VALUE rb_clang_equalRanges(VALUE mod, VALUE obj) {
    // clang_equalRanges
    return Qnil;
}

static VALUE rb_clang_equalTypes(VALUE mod, VALUE obj) {
    // clang_equalTypes
    return Qnil;
}

static VALUE rb_clang_EvalResult_getAsDouble(VALUE mod, VALUE obj) {
    // clang_EvalResult_getAsDouble
    return Qnil;
}

static VALUE rb_clang_EvalResult_getAsInt(VALUE mod, VALUE obj) {
    // clang_EvalResult_getAsInt
    return Qnil;
}

static VALUE rb_clang_EvalResult_getAsLongLong(VALUE mod, VALUE obj) {
    // clang_EvalResult_getAsLongLong
    return Qnil;
}

static VALUE rb_clang_EvalResult_getAsStr(VALUE mod, VALUE obj) {
    // clang_EvalResult_getAsStr
    return Qnil;
}

static VALUE rb_clang_EvalResult_getAsUnsigned(VALUE mod, VALUE obj) {
    // clang_EvalResult_getAsUnsigned
    return Qnil;
}

static VALUE rb_clang_EvalResult_getKind(VALUE mod, VALUE obj) {
    // clang_EvalResult_getKind
    return Qnil;
}

static VALUE rb_clang_executeOnThread(VALUE mod, VALUE obj) {
    // clang_executeOnThread
    return Qnil;
}

static VALUE rb_clang_findIncludesInFile(VALUE mod, VALUE obj) {
    // clang_findIncludesInFile
    return Qnil;
}

static VALUE rb_clang_findReferencesInFile(VALUE mod, VALUE obj) {
    // clang_findReferencesInFile
    return Qnil;
}

static VALUE rb_clang_formatDiagnostic(VALUE mod, VALUE obj) {
    // clang_formatDiagnostic
    return Qnil;
}

static VALUE rb_clang_free(VALUE mod, VALUE obj) {
    // clang_free
    return Qnil;
}

static VALUE rb_clang_FullComment_getAsHTML(VALUE mod, VALUE obj) {
    // clang_FullComment_getAsHTML
    return Qnil;
}

static VALUE rb_clang_FullComment_getAsXML(VALUE mod, VALUE obj) {
    // clang_FullComment_getAsXML
    return Qnil;
}

static VALUE rb_clang_hashCursor(VALUE mod, VALUE obj) {
    // clang_hashCursor
    return Qnil;
}

static VALUE rb_clang_HTMLStartTag_getAttrName(VALUE mod, VALUE obj) {
    // clang_HTMLStartTag_getAttrName
    return Qnil;
}

static VALUE rb_clang_HTMLStartTag_getAttrValue(VALUE mod, VALUE obj) {
    // clang_HTMLStartTag_getAttrValue
    return Qnil;
}

static VALUE rb_clang_HTMLTagComment_getAsString(VALUE mod, VALUE obj) {
    // clang_HTMLTagComment_getAsString
    return Qnil;
}

static VALUE rb_clang_HTMLTagComment_getTagName(VALUE mod, VALUE obj) {
    // clang_HTMLTagComment_getTagName
    return Qnil;
}

static VALUE rb_clang_index_getClientContainer(VALUE mod, VALUE obj) {
    // clang_index_getClientContainer
    return Qnil;
}

static VALUE rb_clang_index_getClientEntity(VALUE mod, VALUE obj) {
    // clang_index_getClientEntity
    return Qnil;
}

static VALUE rb_clang_index_getCXXClassDeclInfo(VALUE mod, VALUE obj) {
    // clang_index_getCXXClassDeclInfo
    return Qnil;
}

static VALUE rb_clang_index_getIBOutletCollectionAttrInfo(VALUE mod, VALUE obj) {
    // clang_index_getIBOutletCollectionAttrInfo
    return Qnil;
}

static VALUE rb_clang_index_getObjCCategoryDeclInfo(VALUE mod, VALUE obj) {
    // clang_index_getObjCCategoryDeclInfo
    return Qnil;
}

static VALUE rb_clang_index_getObjCContainerDeclInfo(VALUE mod, VALUE obj) {
    // clang_index_getObjCContainerDeclInfo
    return Qnil;
}

static VALUE rb_clang_index_getObjCInterfaceDeclInfo(VALUE mod, VALUE obj) {
    // clang_index_getObjCInterfaceDeclInfo
    return Qnil;
}

static VALUE rb_clang_index_getObjCPropertyDeclInfo(VALUE mod, VALUE obj) {
    // clang_index_getObjCPropertyDeclInfo
    return Qnil;
}

static VALUE rb_clang_index_getObjCProtocolRefListInfo(VALUE mod, VALUE obj) {
    // clang_index_getObjCProtocolRefListInfo
    return Qnil;
}

static VALUE rb_clang_index_setClientContainer(VALUE mod, VALUE obj) {
    // clang_index_setClientContainer
    return Qnil;
}

static VALUE rb_clang_index_setClientEntity(VALUE mod, VALUE obj) {
    // clang_index_setClientEntity
    return Qnil;
}

static VALUE rb_clang_IndexAction_create(VALUE mod, VALUE obj) {
    // clang_IndexAction_create
    return Qnil;
}

static VALUE rb_clang_indexLoc_getCXSourceLocation(VALUE mod, VALUE obj) {
    // clang_indexLoc_getCXSourceLocation
    return Qnil;
}

static VALUE rb_clang_indexLoc_getFileLocation(VALUE mod, VALUE obj) {
    // clang_indexLoc_getFileLocation
    return Qnil;
}

static VALUE rb_clang_indexSourceFile(VALUE mod, VALUE obj) {
    // clang_indexSourceFile
    return Qnil;
}

static VALUE rb_clang_indexSourceFileFullArgv(VALUE mod, VALUE obj) {
    // clang_indexSourceFileFullArgv
    return Qnil;
}

static VALUE rb_clang_indexTranslationUnit(VALUE mod, VALUE obj) {
    // clang_indexTranslationUnit
    return Qnil;
}

static VALUE rb_clang_InlineCommandComment_getArgText(VALUE mod, VALUE obj) {
    // clang_InlineCommandComment_getArgText
    return Qnil;
}

static VALUE rb_clang_InlineCommandComment_getCommandName(VALUE mod, VALUE obj) {
    // clang_InlineCommandComment_getCommandName
    return Qnil;
}

static VALUE rb_clang_InlineCommandComment_getRenderKind(VALUE mod, VALUE obj) {
    // clang_InlineCommandComment_getRenderKind
    return Qnil;
}

static VALUE rb_clang_loadDiagnostics(VALUE mod, VALUE obj) {
    // clang_loadDiagnostics
    return Qnil;
}

static VALUE rb_clang_Module_getASTFile(VALUE mod, VALUE obj) {
    // clang_Module_getASTFile
    return Qnil;
}

static VALUE rb_clang_Module_getFullName(VALUE mod, VALUE obj) {
    // clang_Module_getFullName
    return Qnil;
}

static VALUE rb_clang_Module_getName(VALUE mod, VALUE obj) {
    // clang_Module_getName
    return Qnil;
}

static VALUE rb_clang_Module_getParent(VALUE mod, VALUE obj) {
    // clang_Module_getParent
    return Qnil;
}

static VALUE rb_clang_Module_getTopLevelHeader(VALUE mod, VALUE obj) {
    // clang_Module_getTopLevelHeader
    return Qnil;
}

static VALUE rb_clang_ModuleMapDescriptor_create(VALUE mod, VALUE obj) {
    // clang_ModuleMapDescriptor_create
    return Qnil;
}

static VALUE rb_clang_ModuleMapDescriptor_setFrameworkModuleName(VALUE mod, VALUE obj) {
    // clang_ModuleMapDescriptor_setFrameworkModuleName
    return Qnil;
}

static VALUE rb_clang_ModuleMapDescriptor_setUmbrellaHeader(VALUE mod, VALUE obj) {
    // clang_ModuleMapDescriptor_setUmbrellaHeader
    return Qnil;
}

static VALUE rb_clang_ModuleMapDescriptor_writeToBuffer(VALUE mod, VALUE obj) {
    // clang_ModuleMapDescriptor_writeToBuffer
    return Qnil;
}

static VALUE rb_clang_ParamCommandComment_getDirection(VALUE mod, VALUE obj) {
    // clang_ParamCommandComment_getDirection
    return Qnil;
}

static VALUE rb_clang_ParamCommandComment_getParamIndex(VALUE mod, VALUE obj) {
    // clang_ParamCommandComment_getParamIndex
    return Qnil;
}

static VALUE rb_clang_ParamCommandComment_getParamName(VALUE mod, VALUE obj) {
    // clang_ParamCommandComment_getParamName
    return Qnil;
}

static VALUE rb_clang_parseTranslationUnit(VALUE mod, VALUE obj) {
    // clang_parseTranslationUnit
    return Qnil;
}

static VALUE rb_clang_parseTranslationUnit2(VALUE mod, VALUE obj) {
    // clang_parseTranslationUnit2
    return Qnil;
}

static VALUE rb_clang_parseTranslationUnit2FullArgv(VALUE mod, VALUE obj) {
    // clang_parseTranslationUnit2FullArgv
    return Qnil;
}

static VALUE rb_clang_remap_getFilenames(VALUE mod, VALUE obj) {
    // clang_remap_getFilenames
    return Qnil;
}

static VALUE rb_clang_reparseTranslationUnit(VALUE mod, VALUE obj) {
    // clang_reparseTranslationUnit
    return Qnil;
}

static VALUE rb_clang_saveTranslationUnit(VALUE mod, VALUE obj) {
    // clang_saveTranslationUnit
    return Qnil;
}

static VALUE rb_clang_sortCodeCompletionResults(VALUE mod, VALUE obj) {
    // clang_sortCodeCompletionResults
    return Qnil;
}

static VALUE rb_clang_suspendTranslationUnit(VALUE mod, VALUE obj) {
    // clang_suspendTranslationUnit
    return Qnil;
}

static VALUE rb_clang_TargetInfo_getPointerWidth(VALUE mod, VALUE obj) {
    // clang_TargetInfo_getPointerWidth
    return Qnil;
}

static VALUE rb_clang_TargetInfo_getTriple(VALUE mod, VALUE obj) {
    // clang_TargetInfo_getTriple
    return Qnil;
}

static VALUE rb_clang_TextComment_getText(VALUE mod, VALUE obj) {
    // clang_TextComment_getText
    return Qnil;
}

static VALUE rb_clang_toggleCrashRecovery(VALUE mod, VALUE obj) {
    // clang_toggleCrashRecovery
    return Qnil;
}

static VALUE rb_clang_tokenize(VALUE mod, VALUE obj) {
    // clang_tokenize
    return Qnil;
}

static VALUE rb_clang_TParamCommandComment_getDepth(VALUE mod, VALUE obj) {
    // clang_TParamCommandComment_getDepth
    return Qnil;
}

static VALUE rb_clang_TParamCommandComment_getIndex(VALUE mod, VALUE obj) {
    // clang_TParamCommandComment_getIndex
    return Qnil;
}

static VALUE rb_clang_TParamCommandComment_getParamName(VALUE mod, VALUE obj) {
    // clang_TParamCommandComment_getParamName
    return Qnil;
}

static VALUE rb_clang_VerbatimBlockLineComment_getText(VALUE mod, VALUE obj) {
    // clang_VerbatimBlockLineComment_getText
    return Qnil;
}

static VALUE rb_clang_VerbatimLineComment_getText(VALUE mod, VALUE obj) {
    // clang_VerbatimLineComment_getText
    return Qnil;
}

static VALUE rb_clang_VirtualFileOverlay_addFileMapping(VALUE mod, VALUE obj) {
    // clang_VirtualFileOverlay_addFileMapping
    return Qnil;
}

static VALUE rb_clang_VirtualFileOverlay_create(VALUE mod, VALUE obj) {
    // clang_VirtualFileOverlay_create
    return Qnil;
}

static VALUE rb_clang_VirtualFileOverlay_setCaseSensitivity(VALUE mod, VALUE obj) {
    // clang_VirtualFileOverlay_setCaseSensitivity
    return Qnil;
}

static VALUE rb_clang_VirtualFileOverlay_writeToBuffer(VALUE mod, VALUE obj) {
    // clang_VirtualFileOverlay_writeToBuffer
    return Qnil;
}

static VALUE rb_clang_visitChildren(VALUE mod, VALUE obj) {
    // clang_visitChildren
    return Qnil;
}

static VALUE rb_clang_annotateTokens(VALUE mod, VALUE obj) {
    // clang_annotateTokens
    return Qnil;
}

static VALUE rb_clang_BlockCommandComment_getArgText(VALUE mod, VALUE obj) {
    // clang_BlockCommandComment_getArgText
    return Qnil;
}

static VALUE rb_clang_disposeTokens(VALUE mod, VALUE trans_units, VALUE tokens, VALUE count) {
    return Qnil;
}

static VALUE rb_clang_getCursorPlatformAvailability(VALUE mod, VALUE obj) {
    // clang_getCursorPlatformAvailability
    return Qnil;
}

static VALUE rb_clang_codeCompleteAt(VALUE mod, VALUE obj) {
    // clang_codeCompleteAt
    return Qnil;
}

static VALUE rb_clang_Type_visitFields(VALUE mod, VALUE obj) {
    // clang_Type_visitFields
    return Qnil;
}