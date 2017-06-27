/*
** mrb_pivotroot.c - PivotRoot class
**
** Copyright (c) Uchio Kondo 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_pivotroot.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_pivotroot_data;

static const struct mrb_data_type mrb_pivotroot_data_type = {
  "mrb_pivotroot_data", mrb_free,
};

static mrb_value mrb_pivotroot_init(mrb_state *mrb, mrb_value self)
{
  mrb_pivotroot_data *data;
  char *str;
  int len;

  data = (mrb_pivotroot_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_pivotroot_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_pivotroot_data *)mrb_malloc(mrb, sizeof(mrb_pivotroot_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_pivotroot_hello(mrb_state *mrb, mrb_value self)
{
  mrb_pivotroot_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_pivotroot_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_pivot_root_gem_init(mrb_state *mrb)
{
    struct RClass *pivotroot;
    pivotroot = mrb_define_class(mrb, "PivotRoot", mrb->object_class);
    mrb_define_method(mrb, pivotroot, "initialize", mrb_pivotroot_init, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, pivotroot, "hello", mrb_pivotroot_hello, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, pivotroot, "hi", mrb_pivotroot_hi, MRB_ARGS_NONE());
    DONE;
}

void mrb_mruby_pivot_root_gem_final(mrb_state *mrb)
{
}

