#include "classes.h"

VALUE rb_cCXObject;

// Pointer Types
VALUE rb_cCXCursorSetImpl;
VALUE rb_cCXVirtualFileOverlayImpl;
VALUE rb_cCXModuleMapDescriptorImpl;
VALUE rb_cCXTargetInfoImpl;
VALUE rb_cCXTranslationUnitImpl;
VALUE rb_cCXVirtualFileOverlay;
VALUE rb_cCXModuleMapDescriptor;
VALUE rb_cCXIndex;
VALUE rb_cCXTargetInfo;
VALUE rb_cCXTranslationUnit;
VALUE rb_cCXClientData;
VALUE rb_cCXFile;
VALUE rb_cCXDiagnostic;
VALUE rb_cCXDiagnosticSet;
VALUE rb_cCXCursorSet;
VALUE rb_cCXCompilationDatabase;
VALUE rb_cCXCompileCommands;
VALUE rb_cCXCompileCommand;
VALUE rb_cCXModule;
VALUE rb_cCXCompletionString;
VALUE rb_cCXEvalResult;
VALUE rb_cCXRemapping;
VALUE rb_cCXIdxClientFile;
VALUE rb_cCXIdxClientEntity;
VALUE rb_cCXIdxClientContainer;
VALUE rb_cCXIdxClientASTFile;
VALUE rb_cCXIndexAction;

// Storage Types
VALUE rb_cCXCursor;
VALUE rb_cCXType;
VALUE rb_cCXString;
VALUE rb_cCXStringSet;
VALUE rb_cCXUnsavedFile;
VALUE rb_cCXVersion;
VALUE rb_cCXFileUniqueID;
VALUE rb_cCXSourceLocation;
VALUE rb_cCXSourceRange;
VALUE rb_cCXSourceRangeList;
VALUE rb_cCXTUResourceUsageEntry;
VALUE rb_cCXTUResourceUsage;
VALUE rb_cCXPlatformAvailability;
VALUE rb_cCXToken;
VALUE rb_cCXCompletionResult;
VALUE rb_cCXCodeCompleteResults;
VALUE rb_cCXCursorAndRangeVisitor;
VALUE rb_cCXIdxLoc;
VALUE rb_cCXIdxIncludedFileInfo;
VALUE rb_cCXIdxImportedASTFileInfo;
VALUE rb_cCXIdxAttrInfo;
VALUE rb_cCXIdxEntityInfo;
VALUE rb_cCXIdxContainerInfo;
VALUE rb_cCXIdxIBOutletCollectionAttrInfo;
VALUE rb_cCXIdxDeclInfo;
VALUE rb_cCXIdxObjCContainerDeclInfo;
VALUE rb_cCXIdxBaseClassInfo;
VALUE rb_cCXIdxObjCProtocolRefInfo;
VALUE rb_cCXIdxObjCProtocolRefListInfo;
VALUE rb_cCXIdxObjCInterfaceDeclInfo;
VALUE rb_cCXIdxObjCCategoryDeclInfo;
VALUE rb_cCXIdxObjCPropertyDeclInfo;
VALUE rb_cCXIdxCXXClassDeclInfo;
VALUE rb_cCXIdxEntityRefInfo;
VALUE rb_cCXIndexerCallbacks;
VALUE rb_cCXComment;

#define DEFINE_OBJECT(name, variable) variable = rb_define_class_under(module, name, rb_cObject)

void Init_libclang_classes(VALUE module) {
    rb_cCXObject = rb_define_class_under(module, "ClangObject", rb_cObject);
    rb_define_alloc_func(rb_cCXObject, rb_clang_object_alloc);
    rb_define_singleton_method(rb_cCXObject, "null", rb_clang_object_alloc, 0);

    // Pointer Types
    DEFINE_OBJECT("CursorSetImpl", rb_cCXCursorSetImpl);
    DEFINE_OBJECT("VirtualFileOverlayImpl", rb_cCXVirtualFileOverlayImpl);
    DEFINE_OBJECT("ModuleMapDescriptorImpl", rb_cCXModuleMapDescriptorImpl);
    DEFINE_OBJECT("TargetInfoImpl", rb_cCXTargetInfoImpl);
    DEFINE_OBJECT("TranslationUnitImpl", rb_cCXTranslationUnitImpl);
    DEFINE_OBJECT("VirtualFileOverlay", rb_cCXVirtualFileOverlay);
    DEFINE_OBJECT("ModuleMapDescriptor", rb_cCXModuleMapDescriptor);
    DEFINE_OBJECT("Index", rb_cCXIndex);
    DEFINE_OBJECT("TargetInfo", rb_cCXTargetInfo);
    DEFINE_OBJECT("TranslationUnit", rb_cCXTranslationUnit);
    DEFINE_OBJECT("ClientData", rb_cCXClientData);
    DEFINE_OBJECT("File", rb_cCXFile);
    DEFINE_OBJECT("Diagnostic", rb_cCXDiagnostic);
    DEFINE_OBJECT("DiagnosticSet", rb_cCXDiagnosticSet);
    DEFINE_OBJECT("CursorSet", rb_cCXCursorSet);
    DEFINE_OBJECT("CompilationDatabase", rb_cCXCompilationDatabase);
    DEFINE_OBJECT("CompileCommands", rb_cCXCompileCommands);
    DEFINE_OBJECT("CompileCommand", rb_cCXCompileCommand);
    DEFINE_OBJECT("Module", rb_cCXModule);
    DEFINE_OBJECT("CompletionString", rb_cCXCompletionString);
    DEFINE_OBJECT("EvalResult", rb_cCXEvalResult);
    DEFINE_OBJECT("Remapping", rb_cCXRemapping);
    DEFINE_OBJECT("IdxClientFile", rb_cCXIdxClientFile);
    DEFINE_OBJECT("IdxClientEntity", rb_cCXIdxClientEntity);
    DEFINE_OBJECT("IdxClientContainer", rb_cCXIdxClientContainer);
    DEFINE_OBJECT("IdxClientASTFile", rb_cCXIdxClientASTFile);
    DEFINE_OBJECT("IndexAction", rb_cCXIndexAction);
    
    // Storage Types
    DEFINE_OBJECT("Type", rb_cCXType);
    DEFINE_OBJECT("Cursor", rb_cCXCursor);
    DEFINE_OBJECT("String", rb_cCXString);
    DEFINE_OBJECT("StringSet", rb_cCXStringSet);
    DEFINE_OBJECT("UnsavedFile", rb_cCXUnsavedFile);
    DEFINE_OBJECT("Version", rb_cCXVersion);
    DEFINE_OBJECT("FileUniqueID", rb_cCXFileUniqueID);
    DEFINE_OBJECT("SourceLocation", rb_cCXSourceLocation);
    DEFINE_OBJECT("SourceRange", rb_cCXSourceRange);
    DEFINE_OBJECT("SourceRangeList", rb_cCXSourceRangeList);
    DEFINE_OBJECT("TUResourceUsageEntry", rb_cCXTUResourceUsageEntry);
    DEFINE_OBJECT("TUResourceUsage", rb_cCXTUResourceUsage);
    DEFINE_OBJECT("PlatformAvailability", rb_cCXPlatformAvailability);
    DEFINE_OBJECT("Token", rb_cCXToken);
    DEFINE_OBJECT("CompletionResult", rb_cCXCompletionResult);
    DEFINE_OBJECT("CodeCompleteResults", rb_cCXCodeCompleteResults);
    DEFINE_OBJECT("CursorAndRangeVisitor", rb_cCXCursorAndRangeVisitor);
    DEFINE_OBJECT("IdxLoc", rb_cCXIdxLoc);
    DEFINE_OBJECT("IdxIncludedFileInfo", rb_cCXIdxIncludedFileInfo);
    DEFINE_OBJECT("IdxImportedASTFileInfo", rb_cCXIdxImportedASTFileInfo);
    DEFINE_OBJECT("IdxAttrInfo", rb_cCXIdxAttrInfo);
    DEFINE_OBJECT("IdxEntityInfo", rb_cCXIdxEntityInfo);
    DEFINE_OBJECT("IdxContainerInfo", rb_cCXIdxContainerInfo);
    DEFINE_OBJECT("IdxIBOutletCollectionAttrInfo", rb_cCXIdxIBOutletCollectionAttrInfo);
    DEFINE_OBJECT("IdxDeclInfo", rb_cCXIdxDeclInfo);
    DEFINE_OBJECT("IdxObjCContainerDeclInfo", rb_cCXIdxObjCContainerDeclInfo);
    DEFINE_OBJECT("IdxBaseClassInfo", rb_cCXIdxBaseClassInfo);
    DEFINE_OBJECT("IdxObjCProtocolRefInfo", rb_cCXIdxObjCProtocolRefInfo);
    DEFINE_OBJECT("IdxObjCProtocolRefListInfo", rb_cCXIdxObjCProtocolRefListInfo);
    DEFINE_OBJECT("IdxObjCInterfaceDeclInfo", rb_cCXIdxObjCInterfaceDeclInfo);
    DEFINE_OBJECT("IdxObjCCategoryDeclInfo", rb_cCXIdxObjCCategoryDeclInfo);
    DEFINE_OBJECT("IdxObjCPropertyDeclInfo", rb_cCXIdxObjCPropertyDeclInfo);
    DEFINE_OBJECT("IdxCXXClassDeclInfo", rb_cCXIdxCXXClassDeclInfo);
    DEFINE_OBJECT("IdxEntityRefInfo", rb_cCXIdxEntityRefInfo);
    DEFINE_OBJECT("IndexerCallbacks", rb_cCXIndexerCallbacks);
    DEFINE_OBJECT("Comment", rb_cCXComment);
}

static VALUE rb_clang_object_alloc(VALUE klass) {
    return Data_Wrap_Struct(klass, NULL, RUBY_DEFAULT_FREE, NULL);
}