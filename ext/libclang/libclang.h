#ifndef RB_LIBCLANG_H
#define RB_LIBCLANG_H 1

#include "classes.h"
#include "common.h"
#include "enums.h"

static VALUE rb_clang_annotateTokens(VALUE mod, VALUE obj);                                                          // clang_annotateTokens
static VALUE rb_clang_BlockCommandComment_getArgText(VALUE mod, VALUE obj);                                          // clang_BlockCommandComment_getArgText
static VALUE rb_clang_BlockCommandComment_getCommandName(VALUE mod, VALUE obj);                                      // clang_BlockCommandComment_getCommandName
static VALUE rb_clang_BlockCommandComment_getNumArgs(VALUE mod, VALUE obj);                                          // clang_BlockCommandComment_getNumArgs
static VALUE rb_clang_BlockCommandComment_getParagraph(VALUE mod, VALUE obj);                                        // clang_BlockCommandComment_getParagraph
static VALUE rb_clang_codeCompleteAt(VALUE mod, VALUE obj);                                                          // clang_codeCompleteAt
static VALUE rb_clang_codeCompleteGetContainerKind(VALUE mod, VALUE obj);                                            // clang_codeCompleteGetContainerKind
static VALUE rb_clang_codeCompleteGetContainerUSR(VALUE mod, VALUE obj);                                             // clang_codeCompleteGetContainerUSR
static VALUE rb_clang_codeCompleteGetContexts(VALUE mod, VALUE obj);                                                 // clang_codeCompleteGetContexts
static VALUE rb_clang_codeCompleteGetDiagnostic(VALUE mod, VALUE obj);                                               // clang_codeCompleteGetDiagnostic
static VALUE rb_clang_codeCompleteGetNumDiagnostics(VALUE mod, VALUE obj);                                           // clang_codeCompleteGetNumDiagnostics
static VALUE rb_clang_codeCompleteGetObjCSelector(VALUE mod, VALUE obj);                                             // clang_codeCompleteGetObjCSelector
static VALUE rb_clang_Comment_getChild(VALUE mod, VALUE obj);                                                        // clang_Comment_getChild
static VALUE rb_clang_Comment_getKind(VALUE mod, VALUE obj);                                                         // clang_Comment_getKind
static VALUE rb_clang_Comment_getNumChildren(VALUE mod, VALUE obj);                                                  // clang_Comment_getNumChildren
static VALUE rb_clang_Comment_isWhitespace(VALUE mod, VALUE obj);                                                    // clang_Comment_isWhitespace
static VALUE rb_clang_CompilationDatabase_dispose(VALUE mod, VALUE obj);                                             // clang_CompilationDatabase_dispose
static VALUE rb_clang_CompilationDatabase_fromDirectory(VALUE mod, VALUE obj);                                       // clang_CompilationDatabase_fromDirectory
static VALUE rb_clang_CompilationDatabase_getAllCompileCommands(VALUE mod, VALUE obj);                               // clang_CompilationDatabase_getAllCompileCommands
static VALUE rb_clang_CompilationDatabase_getCompileCommands(VALUE mod, VALUE obj);                                  // clang_CompilationDatabase_getCompileCommands
static VALUE rb_clang_CompileCommand_getArg(VALUE mod, VALUE obj);                                                   // clang_CompileCommand_getArg
static VALUE rb_clang_CompileCommand_getDirectory(VALUE mod, VALUE obj);                                             // clang_CompileCommand_getDirectory
static VALUE rb_clang_CompileCommand_getFilename(VALUE mod, VALUE obj);                                              // clang_CompileCommand_getFilename
static VALUE rb_clang_CompileCommand_getMappedSourceContent(VALUE mod, VALUE obj);                                   // clang_CompileCommand_getMappedSourceContent
static VALUE rb_clang_CompileCommand_getMappedSourcePath(VALUE mod, VALUE obj);                                      // clang_CompileCommand_getMappedSourcePath
static VALUE rb_clang_CompileCommand_getNumArgs(VALUE mod, VALUE obj);                                               // clang_CompileCommand_getNumArgs
static VALUE rb_clang_CompileCommand_getNumMappedSources(VALUE mod, VALUE obj);                                      // clang_CompileCommand_getNumMappedSources
static VALUE rb_clang_CompileCommands_dispose(VALUE mod, VALUE obj);                                                 // clang_CompileCommands_dispose
static VALUE rb_clang_CompileCommands_getCommand(VALUE mod, VALUE obj);                                              // clang_CompileCommands_getCommand
static VALUE rb_clang_CompileCommands_getSize(VALUE mod, VALUE obj);                                                 // clang_CompileCommands_getSize
static VALUE rb_clang_constructUSR_ObjCCategory(VALUE mod, VALUE obj);                                               // clang_constructUSR_ObjCCategory
static VALUE rb_clang_constructUSR_ObjCClass(VALUE mod, VALUE obj);                                                  // clang_constructUSR_ObjCClass
static VALUE rb_clang_constructUSR_ObjCIvar(VALUE mod, VALUE obj);                                                   // clang_constructUSR_ObjCIvar
static VALUE rb_clang_constructUSR_ObjCMethod(VALUE mod, VALUE obj);                                                 // clang_constructUSR_ObjCMethod
static VALUE rb_clang_constructUSR_ObjCProperty(VALUE mod, VALUE obj);                                               // clang_constructUSR_ObjCProperty
static VALUE rb_clang_constructUSR_ObjCProtocol(VALUE mod, VALUE obj);                                               // clang_constructUSR_ObjCProtocol
static VALUE rb_clang_createCXCursorSet(VALUE mod, VALUE obj);                                                       // clang_createCXCursorSet
static VALUE rb_clang_createIndex(VALUE mod, VALUE exclude, VALUE display);                                          // clang_createIndex
static VALUE rb_clang_createTranslationUnit(VALUE mod, VALUE obj);                                                   // clang_createTranslationUnit
static VALUE rb_clang_createTranslationUnit2(VALUE mod, VALUE obj);                                                  // clang_createTranslationUnit2
static VALUE rb_clang_createTranslationUnitFromSourceFile(VALUE mod, VALUE obj);                                     // clang_createTranslationUnitFromSourceFile
static VALUE rb_clang_Cursor_Evaluate(VALUE mod, VALUE obj);                                                         // clang_Cursor_Evaluate
static VALUE rb_clang_Cursor_getArgument(VALUE mod, VALUE cursor, VALUE index);                                      // clang_Cursor_getArgument
static VALUE rb_clang_Cursor_getBriefCommentText(VALUE mod, VALUE obj);                                              // clang_Cursor_getBriefCommentText
static VALUE rb_clang_Cursor_getCommentRange(VALUE mod, VALUE obj);                                                  // clang_Cursor_getCommentRange
static VALUE rb_clang_Cursor_getCXXManglings(VALUE mod, VALUE obj);                                                  // clang_Cursor_getCXXManglings
static VALUE rb_clang_Cursor_getMangling(VALUE mod, VALUE obj);                                                      // clang_Cursor_getMangling
static VALUE rb_clang_Cursor_getModule(VALUE mod, VALUE obj);                                                        // clang_Cursor_getModule
static VALUE rb_clang_Cursor_getNumArguments(VALUE mod, VALUE obj);                                                  // clang_Cursor_getNumArguments
static VALUE rb_clang_Cursor_getNumTemplateArguments(VALUE mod, VALUE obj);                                          // clang_Cursor_getNumTemplateArguments
static VALUE rb_clang_Cursor_getObjCDeclQualifiers(VALUE mod, VALUE obj);                                            // clang_Cursor_getObjCDeclQualifiers
static VALUE rb_clang_Cursor_getObjCManglings(VALUE mod, VALUE obj);                                                 // clang_Cursor_getObjCManglings
static VALUE rb_clang_Cursor_getObjCPropertyAttributes(VALUE mod, VALUE obj, VALUE index);                           // clang_Cursor_getObjCPropertyAttributes
static VALUE rb_clang_Cursor_getObjCSelectorIndex(VALUE mod, VALUE obj);                                             // clang_Cursor_getObjCSelectorIndex
static VALUE rb_clang_Cursor_getOffsetOfField(VALUE mod, VALUE obj);                                                 // clang_Cursor_getOffsetOfField
static VALUE rb_clang_Cursor_getParsedComment(VALUE mod, VALUE obj);                                                 // clang_Cursor_getParsedComment
static VALUE rb_clang_Cursor_getRawCommentText(VALUE mod, VALUE obj);                                                // clang_Cursor_getRawCommentText
static VALUE rb_clang_Cursor_getReceiverType(VALUE mod, VALUE obj);                                                  // clang_Cursor_getReceiverType
static VALUE rb_clang_Cursor_getSpellingNameRange(VALUE mod, VALUE obj, VALUE index, VALUE options);                 // clang_Cursor_getSpellingNameRange
static VALUE rb_clang_Cursor_getStorageClass(VALUE mod, VALUE obj);                                                  // clang_Cursor_getStorageClass
static VALUE rb_clang_Cursor_getTemplateArgumentKind(VALUE mod, VALUE obj, VALUE index);                             // clang_Cursor_getTemplateArgumentKind
static VALUE rb_clang_Cursor_getTemplateArgumentType(VALUE mod, VALUE obj, VALUE index);                             // clang_Cursor_getTemplateArgumentType
static VALUE rb_clang_Cursor_getTemplateArgumentUnsignedValue(VALUE mod, VALUE obj, VALUE index);                    // clang_Cursor_getTemplateArgumentUnsignedValue
static VALUE rb_clang_Cursor_getTemplateArgumentValue(VALUE mod, VALUE obj, VALUE index);                            // clang_Cursor_getTemplateArgumentValue
static VALUE rb_clang_Cursor_getTranslationUnit(VALUE mod, VALUE obj);                                               // clang_Cursor_getTranslationUnit
static VALUE rb_clang_Cursor_hasAttrs(VALUE mod, VALUE obj);                                                         // clang_Cursor_hasAttrs
static VALUE rb_clang_Cursor_isAnonymous(VALUE mod, VALUE obj);                                                      // clang_Cursor_isAnonymous
static VALUE rb_clang_Cursor_isBitField(VALUE mod, VALUE obj);                                                       // clang_Cursor_isBitField
static VALUE rb_clang_Cursor_isDynamicCall(VALUE mod, VALUE obj);                                                    // clang_Cursor_isDynamicCall
static VALUE rb_clang_Cursor_isExternalSymbol(VALUE mod, VALUE cursor, VALUE language, VALUE def, VALUE generated);  // clang_Cursor_isExternalSymbol
static VALUE rb_clang_Cursor_isFunctionInlined(VALUE mod, VALUE obj);                                                // clang_Cursor_isFunctionInlined
static VALUE rb_clang_Cursor_isMacroBuiltin(VALUE mod, VALUE obj);                                                   // clang_Cursor_isMacroBuiltin
static VALUE rb_clang_Cursor_isMacroFunctionLike(VALUE mod, VALUE obj);                                              // clang_Cursor_isMacroFunctionLike
static VALUE rb_clang_Cursor_isNull(VALUE mod, VALUE obj);                                                           // clang_Cursor_isNull
static VALUE rb_clang_Cursor_isObjCOptional(VALUE mod, VALUE obj);                                                   // clang_Cursor_isObjCOptional
static VALUE rb_clang_Cursor_isVariadic(VALUE mod, VALUE obj);                                                       // clang_Cursor_isVariadic
static VALUE rb_clang_CXCursorSet_contains(VALUE mod, VALUE obj);                                                    // clang_CXCursorSet_contains
static VALUE rb_clang_CXCursorSet_insert(VALUE mod, VALUE obj);                                                      // clang_CXCursorSet_insert
static VALUE rb_clang_CXIndex_getGlobalOptions(VALUE mod, VALUE obj);                                                // clang_CXIndex_getGlobalOptions
static VALUE rb_clang_CXIndex_setGlobalOptions(VALUE mod, VALUE obj);                                                // clang_CXIndex_setGlobalOptions
static VALUE rb_clang_CXIndex_setInvocationEmissionPathOption(VALUE mod, VALUE obj);                                 // clang_CXIndex_setInvocationEmissionPathOption
static VALUE rb_clang_CXXConstructor_isConvertingConstructor(VALUE mod, VALUE obj);                                  // clang_CXXConstructor_isConvertingConstructor
static VALUE rb_clang_CXXConstructor_isCopyConstructor(VALUE mod, VALUE obj);                                        // clang_CXXConstructor_isCopyConstructor
static VALUE rb_clang_CXXConstructor_isDefaultConstructor(VALUE mod, VALUE obj);                                     // clang_CXXConstructor_isDefaultConstructor
static VALUE rb_clang_CXXConstructor_isMoveConstructor(VALUE mod, VALUE obj);                                        // clang_CXXConstructor_isMoveConstructor
static VALUE rb_clang_CXXField_isMutable(VALUE mod, VALUE obj);                                                      // clang_CXXField_isMutable
static VALUE rb_clang_CXXMethod_isConst(VALUE mod, VALUE obj);                                                       // clang_CXXMethod_isConst
static VALUE rb_clang_CXXMethod_isDefaulted(VALUE mod, VALUE obj);                                                   // clang_CXXMethod_isDefaulted
static VALUE rb_clang_CXXMethod_isPureVirtual(VALUE mod, VALUE obj);                                                 // clang_CXXMethod_isPureVirtual
static VALUE rb_clang_CXXMethod_isStatic(VALUE mod, VALUE obj);                                                      // clang_CXXMethod_isStatic
static VALUE rb_clang_CXXMethod_isVirtual(VALUE mod, VALUE obj);                                                     // clang_CXXMethod_isVirtual
static VALUE rb_clang_CXXRecord_isAbstract(VALUE mod, VALUE obj);                                                    // clang_CXXRecord_isAbstract
static VALUE rb_clang_defaultCodeCompleteOptions(VALUE mod, VALUE obj);                                              // clang_defaultCodeCompleteOptions
static VALUE rb_clang_defaultDiagnosticDisplayOptions(VALUE mod, VALUE obj);                                         // clang_defaultDiagnosticDisplayOptions
static VALUE rb_clang_defaultEditingTranslationUnitOptions(VALUE mod, VALUE obj);                                    // clang_defaultEditingTranslationUnitOptions
static VALUE rb_clang_defaultReparseOptions(VALUE mod, VALUE obj);                                                   // clang_defaultReparseOptions
static VALUE rb_clang_defaultSaveOptions(VALUE mod, VALUE obj);                                                      // clang_defaultSaveOptions
static VALUE rb_clang_disposeCodeCompleteResults(VALUE mod, VALUE obj);                                              // clang_disposeCodeCompleteResults
static VALUE rb_clang_disposeCXCursorSet(VALUE mod, VALUE obj);                                                      // clang_disposeCXCursorSet
static VALUE rb_clang_disposeCXPlatformAvailability(VALUE mod, VALUE obj);                                           // clang_disposeCXPlatformAvailability
static VALUE rb_clang_disposeCXTUResourceUsage(VALUE mod, VALUE obj);                                                // clang_disposeCXTUResourceUsage
static VALUE rb_clang_disposeDiagnostic(VALUE mod, VALUE obj);                                                       // clang_disposeDiagnostic
static VALUE rb_clang_disposeDiagnosticSet(VALUE mod, VALUE obj);                                                    // clang_disposeDiagnosticSet
static VALUE rb_clang_disposeIndex(VALUE mod, VALUE obj);                                                            // clang_disposeIndex
static VALUE rb_clang_disposeOverriddenCursors(VALUE mod, VALUE obj);                                                // clang_disposeOverriddenCursors
static VALUE rb_clang_disposeSourceRangeList(VALUE mod, VALUE obj);                                                  // clang_disposeSourceRangeList
static VALUE rb_clang_disposeString(VALUE mod, VALUE obj);                                                           // clang_disposeString
static VALUE rb_clang_disposeStringSet(VALUE mod, VALUE obj);                                                        // clang_disposeStringSet
static VALUE rb_clang_disposeTokens(VALUE mod, VALUE trans_units, VALUE tokens, VALUE count);                        // clang_disposeTokens
static VALUE rb_clang_disposeTranslationUnit(VALUE mod, VALUE obj);                                                  // clang_disposeTranslationUnit
static VALUE rb_clang_enableStackTraces(VALUE mod, VALUE obj);                                                       // clang_enableStackTraces
static VALUE rb_clang_EnumDecl_isScoped(VALUE mod, VALUE obj);                                                       // clang_EnumDecl_isScoped
static VALUE rb_clang_equalCursors(VALUE mod, VALUE left, VALUE right);                                                            // clang_equalCursors
static VALUE rb_clang_equalLocations(VALUE mod, VALUE left, VALUE right);                                                          // clang_equalLocations
static VALUE rb_clang_equalRanges(VALUE mod, VALUE left, VALUE right);                                                             // clang_equalRanges
static VALUE rb_clang_equalTypes(VALUE mod, VALUE left, VALUE right);                                                              // clang_equalTypes
static VALUE rb_clang_EvalResult_dispose(VALUE mod, VALUE obj);                                                      // clang_EvalResult_dispose
static VALUE rb_clang_EvalResult_getAsDouble(VALUE mod, VALUE obj);                                                  // clang_EvalResult_getAsDouble
static VALUE rb_clang_EvalResult_getAsInt(VALUE mod, VALUE obj);                                                     // clang_EvalResult_getAsInt
static VALUE rb_clang_EvalResult_getAsLongLong(VALUE mod, VALUE obj);                                                // clang_EvalResult_getAsLongLong
static VALUE rb_clang_EvalResult_getAsStr(VALUE mod, VALUE obj);                                                     // clang_EvalResult_getAsStr
static VALUE rb_clang_EvalResult_getAsUnsigned(VALUE mod, VALUE obj);                                                // clang_EvalResult_getAsUnsigned
static VALUE rb_clang_EvalResult_getKind(VALUE mod, VALUE obj);                                                      // clang_EvalResult_getKind
static VALUE rb_clang_EvalResult_isUnsignedInt(VALUE mod, VALUE obj);                                                // clang_EvalResult_isUnsignedInt
static VALUE rb_clang_executeOnThread(VALUE mod, VALUE obj);                                                         // clang_executeOnThread
static VALUE rb_clang_File_isEqual(VALUE mod, VALUE file1, VALUE file2);                                             // clang_File_isEqual
static VALUE rb_clang_findIncludesInFile(VALUE mod, VALUE obj);                                                      // clang_findIncludesInFile
static VALUE rb_clang_findReferencesInFile(VALUE mod, VALUE obj);                                                    // clang_findReferencesInFile
static VALUE rb_clang_formatDiagnostic(VALUE mod, VALUE obj);                                                        // clang_formatDiagnostic
static VALUE rb_clang_free(VALUE mod, VALUE obj);                                                                    // clang_free
static VALUE rb_clang_FullComment_getAsHTML(VALUE mod, VALUE obj);                                                   // clang_FullComment_getAsHTML
static VALUE rb_clang_FullComment_getAsXML(VALUE mod, VALUE obj);                                                    // clang_FullComment_getAsXML
static VALUE rb_clang_getAddressSpace(VALUE mod, VALUE obj);                                                         // clang_getAddressSpace
static VALUE rb_clang_getAllSkippedRanges(VALUE mod, VALUE obj);                                                     // clang_getAllSkippedRanges
static VALUE rb_clang_getArgType(VALUE mod, VALUE obj, VALUE index);                                                 // clang_getArgType
static VALUE rb_clang_getArrayElementType(VALUE mod, VALUE obj);                                                     // clang_getArrayElementType
static VALUE rb_clang_getArraySize(VALUE mod, VALUE obj);                                                            // clang_getArraySize
static VALUE rb_clang_getBuildSessionTimestamp(VALUE mod, VALUE obj);                                                // clang_getBuildSessionTimestamp
static VALUE rb_clang_getCanonicalCursor(VALUE mod, VALUE obj);                                                      // clang_getCanonicalCursor
static VALUE rb_clang_getCanonicalType(VALUE mod, VALUE obj);                                                        // clang_getCanonicalType
static VALUE rb_clang_getChildDiagnostics(VALUE mod, VALUE obj);                                                     // clang_getChildDiagnostics
static VALUE rb_clang_getClangVersion(VALUE mod, VALUE obj);                                                         // clang_getClangVersion
static VALUE rb_clang_getCompletionAnnotation(VALUE mod, VALUE obj);                                                 // clang_getCompletionAnnotation
static VALUE rb_clang_getCompletionAvailability(VALUE mod, VALUE obj);                                               // clang_getCompletionAvailability
static VALUE rb_clang_getCompletionBriefComment(VALUE mod, VALUE obj);                                               // clang_getCompletionBriefComment
static VALUE rb_clang_getCompletionChunkCompletionString(VALUE mod, VALUE obj);                                      // clang_getCompletionChunkCompletionString
static VALUE rb_clang_getCompletionChunkKind(VALUE mod, VALUE obj);                                                  // clang_getCompletionChunkKind
static VALUE rb_clang_getCompletionChunkText(VALUE mod, VALUE obj);                                                  // clang_getCompletionChunkText
static VALUE rb_clang_getCompletionNumAnnotations(VALUE mod, VALUE obj);                                             // clang_getCompletionNumAnnotations
static VALUE rb_clang_getCompletionParent(VALUE mod, VALUE obj);                                                     // clang_getCompletionParent
static VALUE rb_clang_getCompletionPriority(VALUE mod, VALUE obj);                                                   // clang_getCompletionPriority
static VALUE rb_clang_getCString(VALUE mod, VALUE obj);                                                              // clang_getCString
static VALUE rb_clang_getCursor(VALUE mod, VALUE unit, VALUE location);                                              // clang_getCursor
static VALUE rb_clang_getCursorAvailability(VALUE mod, VALUE obj);                                                   // clang_getCursorAvailability
static VALUE rb_clang_getCursorCompletionString(VALUE mod, VALUE obj);                                               // clang_getCursorCompletionString
static VALUE rb_clang_getCursorDefinition(VALUE mod, VALUE obj);                                                     // clang_getCursorDefinition
static VALUE rb_clang_getCursorDisplayName(VALUE mod, VALUE obj);                                                    // clang_getCursorDisplayName
static VALUE rb_clang_getCursorExceptionSpecificationType(VALUE mod, VALUE obj);                                     // clang_getCursorExceptionSpecificationType
static VALUE rb_clang_getCursorExtent(VALUE mod, VALUE obj);                                                         // clang_getCursorExtent
static VALUE rb_clang_getCursorKind(VALUE mod, VALUE obj);                                                           // clang_getCursorKind
static VALUE rb_clang_getCursorKindSpelling(VALUE mod, VALUE obj);                                                   // clang_getCursorKindSpelling
static VALUE rb_clang_getCursorLanguage(VALUE mod, VALUE obj);                                                       // clang_getCursorLanguage
static VALUE rb_clang_getCursorLexicalParent(VALUE mod, VALUE obj);                                                  // clang_getCursorLexicalParent
static VALUE rb_clang_getCursorLinkage(VALUE mod, VALUE obj);                                                        // clang_getCursorLinkage
static VALUE rb_clang_getCursorLocation(VALUE mod, VALUE obj);                                                       // clang_getCursorLocation
static VALUE rb_clang_getCursorPlatformAvailability(VALUE mod, VALUE obj);                                           // clang_getCursorPlatformAvailability
static VALUE rb_clang_getCursorReferenced(VALUE mod, VALUE obj);                                                     // clang_getCursorReferenced
static VALUE rb_clang_getCursorReferenceNameRange(VALUE mod, VALUE obj, VALUE flag, VALUE index);                    // clang_getCursorReferenceNameRange
static VALUE rb_clang_getCursorResultType(VALUE mod, VALUE obj);                                                     // clang_getCursorResultType
static VALUE rb_clang_getCursorSemanticParent(VALUE mod, VALUE obj);                                                 // clang_getCursorSemanticParent
static VALUE rb_clang_getCursorSpelling(VALUE mod, VALUE obj);                                                       // clang_getCursorSpelling
static VALUE rb_clang_getCursorTLSKind(VALUE mod, VALUE obj);                                                        // clang_getCursorTLSKind
static VALUE rb_clang_getCursorType(VALUE mod, VALUE obj);                                                           // clang_getCursorType
static VALUE rb_clang_getCursorUSR(VALUE mod, VALUE obj);                                                            // clang_getCursorUSR
static VALUE rb_clang_getCursorVisibility(VALUE mod, VALUE obj);                                                     // clang_getCursorVisibility
static VALUE rb_clang_getCXTUResourceUsage(VALUE mod, VALUE obj);                                                    // clang_getCXTUResourceUsage
static VALUE rb_clang_getCXXAccessSpecifier(VALUE mod, VALUE obj);                                                   // clang_getCXXAccessSpecifier
static VALUE rb_clang_getDeclObjCTypeEncoding(VALUE mod, VALUE obj);                                                 // clang_getDeclObjCTypeEncoding
static VALUE rb_clang_getDefinitionSpellingAndExtent(VALUE mod, VALUE obj);                                          // clang_getDefinitionSpellingAndExtent
static VALUE rb_clang_getDiagnostic(VALUE mod, VALUE obj, VALUE index);                                              // clang_getDiagnostic
static VALUE rb_clang_getDiagnosticCategory(VALUE mod, VALUE obj);                                                   // clang_getDiagnosticCategory
static VALUE rb_clang_getDiagnosticCategoryName(VALUE mod, VALUE obj);                                               // clang_getDiagnosticCategoryName
static VALUE rb_clang_getDiagnosticCategoryText(VALUE mod, VALUE obj);                                               // clang_getDiagnosticCategoryText
static VALUE rb_clang_getDiagnosticFixIt(VALUE mod, VALUE obj);                                                      // clang_getDiagnosticFixIt
static VALUE rb_clang_getDiagnosticInSet(VALUE mod, VALUE obj);                                                      // clang_getDiagnosticInSet
static VALUE rb_clang_getDiagnosticLocation(VALUE mod, VALUE obj);                                                   // clang_getDiagnosticLocation
static VALUE rb_clang_getDiagnosticNumFixIts(VALUE mod, VALUE obj);                                                  // clang_getDiagnosticNumFixIts
static VALUE rb_clang_getDiagnosticNumRanges(VALUE mod, VALUE obj);                                                  // clang_getDiagnosticNumRanges
static VALUE rb_clang_getDiagnosticOption(VALUE mod, VALUE obj);                                                     // clang_getDiagnosticOption
static VALUE rb_clang_getDiagnosticRange(VALUE mod, VALUE obj, VALUE range);                                         // clang_getDiagnosticRange
static VALUE rb_clang_getDiagnosticSetFromTU(VALUE mod, VALUE obj);                                                  // clang_getDiagnosticSetFromTU
static VALUE rb_clang_getDiagnosticSeverity(VALUE mod, VALUE obj);                                                   // clang_getDiagnosticSeverity
static VALUE rb_clang_getDiagnosticSpelling(VALUE mod, VALUE obj);                                                   // clang_getDiagnosticSpelling
static VALUE rb_clang_getElementType(VALUE mod, VALUE obj);                                                          // clang_getElementType
static VALUE rb_clang_getEnumConstantDeclUnsignedValue(VALUE mod, VALUE obj);                                        // clang_getEnumConstantDeclUnsignedValue
static VALUE rb_clang_getEnumConstantDeclValue(VALUE mod, VALUE obj);                                                // clang_getEnumConstantDeclValue
static VALUE rb_clang_getEnumDeclIntegerType(VALUE mod, VALUE obj);                                                  // clang_getEnumDeclIntegerType
static VALUE rb_clang_getExceptionSpecificationType(VALUE mod, VALUE obj);                                           // clang_getExceptionSpecificationType
static VALUE rb_clang_getExpansionLocation(VALUE mod, VALUE obj);                                                    // clang_getExpansionLocation
static VALUE rb_clang_getFieldDeclBitWidth(VALUE mod, VALUE obj);                                                    // clang_getFieldDeclBitWidth
static VALUE rb_clang_getFile(VALUE mod, VALUE obj, VALUE filename);                                                 // clang_getFile
static VALUE rb_clang_getFileContents(VALUE mod, VALUE obj, VALUE file, VALUE size);                                 // clang_getFileContents
static VALUE rb_clang_getFileLocation(VALUE mod, VALUE obj);                                                         // clang_getFileLocation
static VALUE rb_clang_getFileName(VALUE mod, VALUE obj);                                                             // clang_getFileName
static VALUE rb_clang_getFileTime(VALUE mod, VALUE obj);                                                             // clang_getFileTime
static VALUE rb_clang_getFileUniqueID(VALUE mod, VALUE obj, VALUE id);                                                         // clang_getFileUniqueID
static VALUE rb_clang_getFunctionTypeCallingConv(VALUE mod, VALUE obj);                                              // clang_getFunctionTypeCallingConv
static VALUE rb_clang_getIBOutletCollectionType(VALUE mod, VALUE obj);                                               // clang_getIBOutletCollectionType
static VALUE rb_clang_getIncludedFile(VALUE mod, VALUE obj);                                                         // clang_getIncludedFile
static VALUE rb_clang_getInclusions(VALUE mod, VALUE obj);                                                           // clang_getInclusions
static VALUE rb_clang_getInstantiationLocation(VALUE mod, VALUE obj);                                                // clang_getInstantiationLocation
static VALUE rb_clang_getLocation(VALUE mod, VALUE obj, VALUE file, VALUE line, VALUE column);                                                             // clang_getLocation
static VALUE rb_clang_getLocationForOffset(VALUE mod, VALUE obj);                                                    // clang_getLocationForOffset
static VALUE rb_clang_getModuleForFile(VALUE mod, VALUE obj);                                                        // clang_getModuleForFile
static VALUE rb_clang_getNullCursor(VALUE mod, VALUE obj);                                                           // clang_getNullCursor
static VALUE rb_clang_getNullLocation(VALUE mod, VALUE obj);                                                         // clang_getNullLocation
static VALUE rb_clang_getNullRange(VALUE mod, VALUE obj);                                                            // clang_getNullRange
static VALUE rb_clang_getNumArgTypes(VALUE mod, VALUE obj);                                                          // clang_getNumArgTypes
static VALUE rb_clang_getNumCompletionChunks(VALUE mod, VALUE obj);                                                  // clang_getNumCompletionChunks
static VALUE rb_clang_getNumDiagnostics(VALUE mod, VALUE obj);                                                       // clang_getNumDiagnostics
static VALUE rb_clang_getNumDiagnosticsInSet(VALUE mod, VALUE obj);                                                  // clang_getNumDiagnosticsInSet
static VALUE rb_clang_getNumElements(VALUE mod, VALUE obj);                                                          // clang_getNumElements
static VALUE rb_clang_getNumOverloadedDecls(VALUE mod, VALUE obj);                                                   // clang_getNumOverloadedDecls
static VALUE rb_clang_getOverloadedDecl(VALUE mod, VALUE obj);                                                       // clang_getOverloadedDecl
static VALUE rb_clang_getOverriddenCursors(VALUE mod, VALUE obj);                                                    // clang_getOverriddenCursors
static VALUE rb_clang_getPointeeType(VALUE mod, VALUE obj);                                                          // clang_getPointeeType
static VALUE rb_clang_getPresumedLocation(VALUE mod, VALUE obj);                                                     // clang_getPresumedLocation
static VALUE rb_clang_getRange(VALUE mod, VALUE start, VALUE finish);                                                                // clang_getRange
static VALUE rb_clang_getRangeEnd(VALUE mod, VALUE obj);                                                             // clang_getRangeEnd
static VALUE rb_clang_getRangeStart(VALUE mod, VALUE obj);                                                           // clang_getRangeStart
static VALUE rb_clang_getRemappings(VALUE mod, VALUE obj);                                                           // clang_getRemappings
static VALUE rb_clang_getRemappingsFromFileList(VALUE mod, VALUE obj);                                               // clang_getRemappingsFromFileList
static VALUE rb_clang_getResultType(VALUE mod, VALUE obj);                                                           // clang_getResultType
static VALUE rb_clang_getSkippedRanges(VALUE mod, VALUE obj, VALUE file));                                                        // clang_getSkippedRanges
static VALUE rb_clang_getSpecializedCursorTemplate(VALUE mod, VALUE obj);                                            // clang_getSpecializedCursorTemplate
static VALUE rb_clang_getSpellingLocation(VALUE mod, VALUE obj);                                                     // clang_getSpellingLocation
static VALUE rb_clang_getTemplateCursorKind(VALUE mod, VALUE obj);                                                   // clang_getTemplateCursorKind
static VALUE rb_clang_getTokenExtent(VALUE mod, VALUE obj, VALUE token);                                                          // clang_getTokenExtent
static VALUE rb_clang_getTokenKind(VALUE mod, VALUE obj);                                                            // clang_getTokenKind
static VALUE rb_clang_getTokenLocation(VALUE mod, VALUE obj, VALUE token);                                                        // clang_getTokenLocation
static VALUE rb_clang_getTokenSpelling(VALUE mod, VALUE obj, VALUE token);                                                        // clang_getTokenSpelling
static VALUE rb_clang_getTranslationUnitCursor(VALUE mod, VALUE obj);                                                // clang_getTranslationUnitCursor
static VALUE rb_clang_getTranslationUnitSpelling(VALUE mod, VALUE obj);                                              // clang_getTranslationUnitSpelling
static VALUE rb_clang_getTranslationUnitTargetInfo(VALUE mod, VALUE obj);                                            // clang_getTranslationUnitTargetInfo
static VALUE rb_clang_getTUResourceUsageName(VALUE mod, VALUE obj);                                                  // clang_getTUResourceUsageName
static VALUE rb_clang_getTypeDeclaration(VALUE mod, VALUE obj);                                                      // clang_getTypeDeclaration
static VALUE rb_clang_getTypedefDeclUnderlyingType(VALUE mod, VALUE obj);                                            // clang_getTypedefDeclUnderlyingType
static VALUE rb_clang_getTypedefName(VALUE mod, VALUE obj);                                                          // clang_getTypedefName
static VALUE rb_clang_getTypeKindSpelling(VALUE mod, VALUE obj);                                                     // clang_getTypeKindSpelling
static VALUE rb_clang_getTypeSpelling(VALUE mod, VALUE obj);                                                         // clang_getTypeSpelling
static VALUE rb_clang_hashCursor(VALUE mod, VALUE obj);                                                              // clang_hashCursor
static VALUE rb_clang_HTMLStartTag_getAttrName(VALUE mod, VALUE obj);                                                // clang_HTMLStartTag_getAttrName
static VALUE rb_clang_HTMLStartTag_getAttrValue(VALUE mod, VALUE obj);                                               // clang_HTMLStartTag_getAttrValue
static VALUE rb_clang_HTMLStartTag_getNumAttrs(VALUE mod, VALUE obj);                                                // clang_HTMLStartTag_getNumAttrs
static VALUE rb_clang_HTMLStartTagComment_isSelfClosing(VALUE mod, VALUE obj);                                       // clang_HTMLStartTagComment_isSelfClosing
static VALUE rb_clang_HTMLTagComment_getAsString(VALUE mod, VALUE obj);                                              // clang_HTMLTagComment_getAsString
static VALUE rb_clang_HTMLTagComment_getTagName(VALUE mod, VALUE obj);                                               // clang_HTMLTagComment_getTagName
static VALUE rb_clang_index_getClientContainer(VALUE mod, VALUE obj);                                                // clang_index_getClientContainer
static VALUE rb_clang_index_getClientEntity(VALUE mod, VALUE obj);                                                   // clang_index_getClientEntity
static VALUE rb_clang_index_getCXXClassDeclInfo(VALUE mod, VALUE obj);                                               // clang_index_getCXXClassDeclInfo
static VALUE rb_clang_index_getIBOutletCollectionAttrInfo(VALUE mod, VALUE obj);                                     // clang_index_getIBOutletCollectionAttrInfo
static VALUE rb_clang_index_getObjCCategoryDeclInfo(VALUE mod, VALUE obj);                                           // clang_index_getObjCCategoryDeclInfo
static VALUE rb_clang_index_getObjCContainerDeclInfo(VALUE mod, VALUE obj);                                          // clang_index_getObjCContainerDeclInfo
static VALUE rb_clang_index_getObjCInterfaceDeclInfo(VALUE mod, VALUE obj);                                          // clang_index_getObjCInterfaceDeclInfo
static VALUE rb_clang_index_getObjCPropertyDeclInfo(VALUE mod, VALUE obj);                                           // clang_index_getObjCPropertyDeclInfo
static VALUE rb_clang_index_getObjCProtocolRefListInfo(VALUE mod, VALUE obj);                                        // clang_index_getObjCProtocolRefListInfo
static VALUE rb_clang_index_isEntityObjCContainerKind(VALUE mod, VALUE obj);                                         // clang_index_isEntityObjCContainerKind
static VALUE rb_clang_index_setClientContainer(VALUE mod, VALUE obj);                                                // clang_index_setClientContainer
static VALUE rb_clang_index_setClientEntity(VALUE mod, VALUE obj);                                                   // clang_index_setClientEntity
static VALUE rb_clang_IndexAction_create(VALUE mod, VALUE obj);                                                      // clang_IndexAction_create
static VALUE rb_clang_IndexAction_dispose(VALUE mod, VALUE obj);                                                     // clang_IndexAction_dispose
static VALUE rb_clang_indexLoc_getCXSourceLocation(VALUE mod, VALUE obj);                                            // clang_indexLoc_getCXSourceLocation
static VALUE rb_clang_indexLoc_getFileLocation(VALUE mod, VALUE obj);                                                // clang_indexLoc_getFileLocation
static VALUE rb_clang_indexSourceFile(VALUE mod, VALUE obj);                                                         // clang_indexSourceFile
static VALUE rb_clang_indexSourceFileFullArgv(VALUE mod, VALUE obj);                                                 // clang_indexSourceFileFullArgv
static VALUE rb_clang_indexTranslationUnit(VALUE mod, VALUE obj);                                                    // clang_indexTranslationUnit
static VALUE rb_clang_InlineCommandComment_getArgText(VALUE mod, VALUE obj);                                         // clang_InlineCommandComment_getArgText
static VALUE rb_clang_InlineCommandComment_getCommandName(VALUE mod, VALUE obj);                                     // clang_InlineCommandComment_getCommandName
static VALUE rb_clang_InlineCommandComment_getNumArgs(VALUE mod, VALUE obj);                                         // clang_InlineCommandComment_getNumArgs
static VALUE rb_clang_InlineCommandComment_getRenderKind(VALUE mod, VALUE obj);                                      // clang_InlineCommandComment_getRenderKind
static VALUE rb_clang_InlineContentComment_hasTrailingNewline(VALUE mod, VALUE obj);                                 // clang_InlineContentComment_hasTrailingNewline
static VALUE rb_clang_isAttribute(VALUE mod, VALUE obj);                                                             // clang_isAttribute
static VALUE rb_clang_isConstQualifiedType(VALUE mod, VALUE obj);                                                    // clang_isConstQualifiedType
static VALUE rb_clang_isCursorDefinition(VALUE mod, VALUE obj);                                                      // clang_isCursorDefinition
static VALUE rb_clang_isDeclaration(VALUE mod, VALUE obj);                                                           // clang_isDeclaration
static VALUE rb_clang_isExpression(VALUE mod, VALUE obj);                                                            // clang_isExpression
static VALUE rb_clang_isFileMultipleIncludeGuarded(VALUE mod, VALUE trans_unit, VALUE file);                         // clang_isFileMultipleIncludeGuarded
static VALUE rb_clang_isFunctionTypeVariadic(VALUE mod, VALUE obj);                                                  // clang_isFunctionTypeVariadic
static VALUE rb_clang_isInvalid(VALUE mod, VALUE obj);                                                               // clang_isInvalid
static VALUE rb_clang_isPODType(VALUE mod, VALUE obj);                                                               // clang_isPODType
static VALUE rb_clang_isPreprocessing(VALUE mod, VALUE obj);                                                         // clang_isPreprocessing
static VALUE rb_clang_isReference(VALUE mod, VALUE obj);                                                             // clang_isReference
static VALUE rb_clang_isRestrictQualifiedType(VALUE mod, VALUE obj);                                                 // clang_isRestrictQualifiedType
static VALUE rb_clang_isStatement(VALUE mod, VALUE obj);                                                             // clang_isStatement
static VALUE rb_clang_isTranslationUnit(VALUE mod, VALUE obj);                                                       // clang_isTranslationUnit
static VALUE rb_clang_isUnexposed(VALUE mod, VALUE obj);                                                             // clang_isUnexposed
static VALUE rb_clang_isVirtualBase(VALUE mod, VALUE obj);                                                           // clang_isVirtualBase
static VALUE rb_clang_isVolatileQualifiedType(VALUE mod, VALUE obj);                                                 // clang_isVolatileQualifiedType
static VALUE rb_clang_loadDiagnostics(VALUE mod, VALUE obj);                                                         // clang_loadDiagnostics
static VALUE rb_clang_Location_isFromMainFile(VALUE mod, VALUE obj);                                                 // clang_Location_isFromMainFile
static VALUE rb_clang_Location_isInSystemHeader(VALUE mod, VALUE obj);                                               // clang_Location_isInSystemHeader
static VALUE rb_clang_Module_getASTFile(VALUE mod, VALUE obj);                                                       // clang_Module_getASTFile
static VALUE rb_clang_Module_getFullName(VALUE mod, VALUE obj);                                                      // clang_Module_getFullName
static VALUE rb_clang_Module_getName(VALUE mod, VALUE obj);                                                          // clang_Module_getName
static VALUE rb_clang_Module_getNumTopLevelHeaders(VALUE mod, VALUE obj, VALUE module);                              // clang_Module_getNumTopLevelHeaders
static VALUE rb_clang_Module_getParent(VALUE mod, VALUE obj);                                                        // clang_Module_getParent
static VALUE rb_clang_Module_getTopLevelHeader(VALUE mod, VALUE obj);                                                // clang_Module_getTopLevelHeader
static VALUE rb_clang_Module_isSystem(VALUE mod, VALUE obj);                                                         // clang_Module_isSystem
static VALUE rb_clang_ModuleMapDescriptor_create(VALUE mod, VALUE obj);                                              // clang_ModuleMapDescriptor_create
static VALUE rb_clang_ModuleMapDescriptor_dispose(VALUE mod, VALUE obj);                                             // clang_ModuleMapDescriptor_dispose
static VALUE rb_clang_ModuleMapDescriptor_setFrameworkModuleName(VALUE mod, VALUE obj);                              // clang_ModuleMapDescriptor_setFrameworkModuleName
static VALUE rb_clang_ModuleMapDescriptor_setUmbrellaHeader(VALUE mod, VALUE obj);                                   // clang_ModuleMapDescriptor_setUmbrellaHeader
static VALUE rb_clang_ModuleMapDescriptor_writeToBuffer(VALUE mod, VALUE obj);                                       // clang_ModuleMapDescriptor_writeToBuffer
static VALUE rb_clang_ParamCommandComment_getDirection(VALUE mod, VALUE obj);                                        // clang_ParamCommandComment_getDirection
static VALUE rb_clang_ParamCommandComment_getParamIndex(VALUE mod, VALUE obj);                                       // clang_ParamCommandComment_getParamIndex
static VALUE rb_clang_ParamCommandComment_getParamName(VALUE mod, VALUE obj);                                        // clang_ParamCommandComment_getParamName
static VALUE rb_clang_ParamCommandComment_isDirectionExplicit(VALUE mod, VALUE obj);                                 // clang_ParamCommandComment_isDirectionExplicit
static VALUE rb_clang_ParamCommandComment_isParamIndexValid(VALUE mod, VALUE obj);                                   // clang_ParamCommandComment_isParamIndexValid
static VALUE rb_clang_parseTranslationUnit(int argc, VALUE *argv, VALUE mod);                                                    // clang_parseTranslationUnit
static VALUE rb_clang_parseTranslationUnit2(int argc, VALUE *argv, VALUE mod);                                                   // clang_parseTranslationUnit2
static VALUE rb_clang_parseTranslationUnit2FullArgv(int argc, VALUE *argv, VALUE mod);                                           // clang_parseTranslationUnit2FullArgv
static VALUE rb_clang_Range_isNull(VALUE mod, VALUE obj);                                                            // clang_Range_isNull
static VALUE rb_clang_remap_dispose(VALUE mod, VALUE obj);                                                           // clang_remap_dispose
static VALUE rb_clang_remap_getFilenames(VALUE mod, VALUE obj);                                                      // clang_remap_getFilenames
static VALUE rb_clang_remap_getNumFiles(VALUE mod, VALUE obj);                                                       // clang_remap_getNumFiles
static VALUE rb_clang_reparseTranslationUnit(VALUE mod, VALUE obj);                                                  // clang_reparseTranslationUnit
static VALUE rb_clang_saveTranslationUnit(VALUE mod, VALUE obj);                                                     // clang_saveTranslationUnit
static VALUE rb_clang_sortCodeCompletionResults(VALUE mod, VALUE obj);                                               // clang_sortCodeCompletionResults
static VALUE rb_clang_suspendTranslationUnit(VALUE mod, VALUE obj);                                                  // clang_suspendTranslationUnit
static VALUE rb_clang_TargetInfo_dispose(VALUE mod, VALUE obj);                                                      // clang_TargetInfo_dispose
static VALUE rb_clang_TargetInfo_getPointerWidth(VALUE mod, VALUE obj);                                              // clang_TargetInfo_getPointerWidth
static VALUE rb_clang_TargetInfo_getTriple(VALUE mod, VALUE obj);                                                    // clang_TargetInfo_getTriple
static VALUE rb_clang_TextComment_getText(VALUE mod, VALUE obj);                                                     // clang_TextComment_getText
static VALUE rb_clang_toggleCrashRecovery(VALUE mod, VALUE obj);                                                     // clang_toggleCrashRecovery
static VALUE rb_clang_tokenize(VALUE mod, VALUE obj);                                                                // clang_tokenize
static VALUE rb_clang_TParamCommandComment_getDepth(VALUE mod, VALUE obj);                                           // clang_TParamCommandComment_getDepth
static VALUE rb_clang_TParamCommandComment_getIndex(VALUE mod, VALUE obj);                                           // clang_TParamCommandComment_getIndex
static VALUE rb_clang_TParamCommandComment_getParamName(VALUE mod, VALUE obj);                                       // clang_TParamCommandComment_getParamName
static VALUE rb_clang_TParamCommandComment_isParamPositionValid(VALUE mod, VALUE obj);                               // clang_TParamCommandComment_isParamPositionValid
static VALUE rb_clang_Type_getAlignOf(VALUE mod, VALUE obj);                                                         // clang_Type_getAlignOf
static VALUE rb_clang_Type_getClassType(VALUE mod, VALUE obj);                                                       // clang_Type_getClassType
static VALUE rb_clang_Type_getCXXRefQualifier(VALUE mod, VALUE obj);                                                 // clang_Type_getCXXRefQualifier
static VALUE rb_clang_Type_getNamedType(VALUE mod, VALUE obj);                                                       // clang_Type_getNamedType
static VALUE rb_clang_Type_getNumTemplateArguments(VALUE mod, VALUE obj);                                            // clang_Type_getNumTemplateArguments
static VALUE rb_clang_Type_getObjCEncoding(VALUE mod, VALUE obj);                                                    // clang_Type_getObjCEncoding
static VALUE rb_clang_Type_getOffsetOf(VALUE mod, VALUE obj, VALUE t);                                               // clang_Type_getOffsetOf
static VALUE rb_clang_Type_getSizeOf(VALUE mod, VALUE obj);                                                          // clang_Type_getSizeOf
static VALUE rb_clang_Type_getTemplateArgumentAsType(VALUE mod, VALUE obj, VALUE index);                             // clang_Type_getTemplateArgumentAsType
static VALUE rb_clang_Type_isTransparentTagTypedef(VALUE mod, VALUE obj);                                            // clang_Type_isTransparentTagTypedef
static VALUE rb_clang_Type_visitFields(VALUE mod, VALUE obj);                                                        // clang_Type_visitFields
static VALUE rb_clang_VerbatimBlockLineComment_getText(VALUE mod, VALUE obj);                                        // clang_VerbatimBlockLineComment_getText
static VALUE rb_clang_VerbatimLineComment_getText(VALUE mod, VALUE obj);                                             // clang_VerbatimLineComment_getText
static VALUE rb_clang_VirtualFileOverlay_addFileMapping(VALUE mod, VALUE obj);                                       // clang_VirtualFileOverlay_addFileMapping
static VALUE rb_clang_VirtualFileOverlay_create(VALUE mod, VALUE obj);                                               // clang_VirtualFileOverlay_create
static VALUE rb_clang_VirtualFileOverlay_dispose(VALUE mod, VALUE obj);                                              // clang_VirtualFileOverlay_dispose
static VALUE rb_clang_VirtualFileOverlay_setCaseSensitivity(VALUE mod, VALUE obj);                                   // clang_VirtualFileOverlay_setCaseSensitivity
static VALUE rb_clang_VirtualFileOverlay_writeToBuffer(VALUE mod, VALUE obj);                                        // clang_VirtualFileOverlay_writeToBuffer
static VALUE rb_clang_visitChildren(VALUE mod, VALUE obj);                                                           // clang_visitChildren

#endif /* RB_LIBCLANG_H */
