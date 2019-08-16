#include <packn.h>

VALUE mPackn;
VALUE cBig2_Context;
VALUE cBig4_Context;
VALUE cBig8_Context;

#define WRITE_BIGENDIAN(val, res, size) rb_integer_pack(val, intbuf, size, 1, 0, INTEGER_PACK_2COMP | INTEGER_PACK_BIG_ENDIAN); \
  rb_str_buf_cat(res, intbuf, size)

static VALUE packn_bigendigan2_pack1(VALUE klass, VALUE val)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[2];
  WRITE_BIGENDIAN(val, res, 2);
  return res;
}

static VALUE packn_bigendigan4_pack1(VALUE klass, VALUE val)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[4];
  WRITE_BIGENDIAN(val, res, 4);
  return res;
}

static VALUE packn_bigendigan2_pack2(VALUE klass, VALUE val, VALUE val2)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[2];
  WRITE_BIGENDIAN(val, res, 2);
  WRITE_BIGENDIAN(val2, res, 2);
  return res;
}

static VALUE packn_bigendigan4_pack2(VALUE klass, VALUE val, VALUE val2)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[4];
  WRITE_BIGENDIAN(val, res, 4);
  WRITE_BIGENDIAN(val2, res, 4);
  return res;
}

static VALUE packn_bigendigan2_pack3(VALUE klass, VALUE val, VALUE val2, VALUE val3)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[2];
  WRITE_BIGENDIAN(val, res, 2);
  WRITE_BIGENDIAN(val2, res, 2);
  WRITE_BIGENDIAN(val3, res, 2);
  return res;
}

static VALUE packn_bigendigan4_pack3(VALUE klass, VALUE val, VALUE val2, VALUE val3)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[4];
  WRITE_BIGENDIAN(val, res, 4);
  WRITE_BIGENDIAN(val2, res, 4);
  WRITE_BIGENDIAN(val3, res, 4);
  return res;
}

static VALUE packn_bigendigan2_pack4(VALUE klass, VALUE val, VALUE val2, VALUE val3, VALUE val4)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[2];
  WRITE_BIGENDIAN(val, res, 2);
  WRITE_BIGENDIAN(val2, res, 2);
  WRITE_BIGENDIAN(val3, res, 2);
  WRITE_BIGENDIAN(val4, res, 2);
  return res;
}

static VALUE packn_bigendigan4_pack4(VALUE klass, VALUE val, VALUE val2, VALUE val3, VALUE val4)
{
  VALUE res = rb_str_buf_new(0);
  char intbuf[4];
  WRITE_BIGENDIAN(val, res, 4);
  WRITE_BIGENDIAN(val2, res, 4);
  WRITE_BIGENDIAN(val3, res, 4);
  WRITE_BIGENDIAN(val4, res, 2);
  return res;
}

void Init_packn(void)
{
  mPackn = rb_define_module("Packn");

  cBig2_Context = rb_define_class_under(mPackn, "BigEndian2", rb_cObject);
  rb_define_singleton_method(cBig2_Context, "pack1", packn_bigendigan2_pack1, 1);
  rb_define_singleton_method(cBig2_Context, "pack2", packn_bigendigan2_pack2, 2);
  rb_define_singleton_method(cBig2_Context, "pack3", packn_bigendigan2_pack3, 3);
  rb_define_singleton_method(cBig2_Context, "pack4", packn_bigendigan2_pack4, 4);

  cBig4_Context = rb_define_class_under(mPackn, "BigEndian4", rb_cObject);
  rb_define_singleton_method(cBig4_Context, "pack1", packn_bigendigan4_pack1, 1);
  rb_define_singleton_method(cBig4_Context, "pack2", packn_bigendigan4_pack2, 2);
  rb_define_singleton_method(cBig4_Context, "pack3", packn_bigendigan4_pack3, 3);
  rb_define_singleton_method(cBig4_Context, "pack4", packn_bigendigan4_pack4, 4);

}
