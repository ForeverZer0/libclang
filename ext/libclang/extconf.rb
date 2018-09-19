require "mkmf"

llvm = 'D:/Program Files/LLVM'
include = File.join(llvm, 'include')
lib = File.join(llvm, 'lib')


libdirs = [RbConfig::CONFIG['libdir'], File.join(llvm, 'lib')]
includeDirs = [RbConfig::CONFIG['includedir'], File.join(llvm, 'include')]

$LOCAL_LIBS << '-lclang '

dir_config('libclang', includeDirs, libdirs)
# have_library("clang", "clang_createIndex")

create_makefile("libclang/libclang")
