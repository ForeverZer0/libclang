#ifndef RB_LIBCLANG_CLASSES_H
#define RB_LIBCLANG_CLASSES_H 1

#include "common.h"

void Init_libclang_classes(VALUE module);
static VALUE rb_clang_object_alloc(VALUE klass);

#endif /* RB_LIBCLANG_CLASSES_H */