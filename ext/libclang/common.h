#ifndef RB_LIBCLANG_COMMON_H
#define RB_LIBCLANG_COMMON_H 1

#include "ruby.h"
#include "clang-c/Index.h"
#include "clang-c/Documentation.h"

extern VALUE rb_cCXObject;
extern VALUE rb_cCXCursorSetImpl;
extern VALUE rb_cCXVirtualFileOverlayImpl;
extern VALUE rb_cCXModuleMapDescriptorImpl;
extern VALUE rb_cCXTargetInfoImpl;
extern VALUE rb_cCXTranslationUnitImpl;
extern VALUE rb_cCXVirtualFileOverlay;
extern VALUE rb_cCXModuleMapDescriptor;
extern VALUE rb_cCXIndex;
extern VALUE rb_cCXTargetInfo;
extern VALUE rb_cCXTranslationUnit;
extern VALUE rb_cCXClientData;
extern VALUE rb_cCXFile;
extern VALUE rb_cCXDiagnostic;
extern VALUE rb_cCXDiagnosticSet;
extern VALUE rb_cCXCursorSet;
extern VALUE rb_cCXCompilationDatabase;
extern VALUE rb_cCXCompileCommands;
extern VALUE rb_cCXCompileCommand;
extern VALUE rb_cCXModule;
extern VALUE rb_cCXCompletionString;
extern VALUE rb_cCXEvalResult;
extern VALUE rb_cCXRemapping;
extern VALUE rb_cCXIdxClientFile;
extern VALUE rb_cCXIdxClientEntity;
extern VALUE rb_cCXIdxClientContainer;
extern VALUE rb_cCXIdxClientASTFile;
extern VALUE rb_cCXIndexAction;
extern VALUE rb_cCXCursor;
extern VALUE rb_cCXType;
extern VALUE rb_cCXString;
extern VALUE rb_cCXStringSet;
extern VALUE rb_cCXUnsavedFile;
extern VALUE rb_cCXVersion;
extern VALUE rb_cCXFileUniqueID;
extern VALUE rb_cCXSourceLocation;
extern VALUE rb_cCXSourceRange;
extern VALUE rb_cCXSourceRangeList;
extern VALUE rb_cCXTUResourceUsageEntry;
extern VALUE rb_cCXTUResourceUsage;
extern VALUE rb_cCXPlatformAvailability;
extern VALUE rb_cCXToken;
extern VALUE rb_cCXCompletionResult;
extern VALUE rb_cCXCodeCompleteResults;
extern VALUE rb_cCXCursorAndRangeVisitor;
extern VALUE rb_cCXIdxLoc;
extern VALUE rb_cCXIdxIncludedFileInfo;
extern VALUE rb_cCXIdxImportedASTFileInfo;
extern VALUE rb_cCXIdxAttrInfo;
extern VALUE rb_cCXIdxEntityInfo;
extern VALUE rb_cCXIdxContainerInfo;
extern VALUE rb_cCXIdxIBOutletCollectionAttrInfo;
extern VALUE rb_cCXIdxDeclInfo;
extern VALUE rb_cCXIdxObjCContainerDeclInfo;
extern VALUE rb_cCXIdxBaseClassInfo;
extern VALUE rb_cCXIdxObjCProtocolRefInfo;
extern VALUE rb_cCXIdxObjCProtocolRefListInfo;
extern VALUE rb_cCXIdxObjCInterfaceDeclInfo;
extern VALUE rb_cCXIdxObjCCategoryDeclInfo;
extern VALUE rb_cCXIdxObjCPropertyDeclInfo;
extern VALUE rb_cCXIdxCXXClassDeclInfo;
extern VALUE rb_cCXIdxEntityRefInfo;
extern VALUE rb_cCXIndexerCallbacks;
extern VALUE rb_cCXComment;

#endif /* RB_LIBCLANG_COMMON_H */
