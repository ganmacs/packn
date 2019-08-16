# frozen_string_literal: true

require 'mkmf'

have_func('rb_integer_pack')
have_func('rb_str_buf_cat')
have_func('rb_str_buf_new')

create_makefile 'packn/packn'
