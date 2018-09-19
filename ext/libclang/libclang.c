#include "libclang.h"

VALUE rb_mLibclang;

void
Init_libclang(void)
{
  rb_mLibclang = rb_define_module("Libclang");
}
