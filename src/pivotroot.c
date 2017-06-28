/*
** mrb_pivotroot.c - PivotRoot class
**
** Copyright (c) Uchio Kondo 2017
**
** See Copyright Notice in LICENSE
*/

#include <mruby.h>
#include <mruby/data.h>
#include <mruby/error.h>
#include <sys/syscall.h>
#include <unistd.h>

#include "pivotroot.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

#define pivot_root(new_root, put_old) syscall(SYS_pivot_root, new_root, put_old)

static mrb_value mrb_pivotroot_do(mrb_state *mrb, mrb_value self)
{
  const char *old_root, new_root;
  mrb_get_args(mrb, "zz", &new_root, &old_root);

  if (pivot_root(new_root, old_root) == -1) {
#ifdef MRB_DEBUG
#include <err.h>
    perror("pivot_root");
#endif
    mrb_sys_fail(mrb, "pivot_root");
  }

  return mrb_true_value();
}

void mrb_mruby_pivot_root_gem_init(mrb_state *mrb)
{
  struct RClass *pivotroot;
  pivotroot = mrb_define_module(mrb, "PivotRoot");
  mrb_define_module_function(mrb, pivotroot, "pivot_root", mrb_pivotroot_do, MRB_ARGS_REQ(2));
  DONE;
}

void mrb_mruby_pivot_root_gem_final(mrb_state *mrb)
{
}
