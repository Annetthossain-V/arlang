#pragma once


enum OPCode {
  KeyWord,
  Ident,
  Op,
  Int,
  Float,
  String,
  Sym,
};

enum SubOPCode {
  KeyWord_Int,
  KeyWord_Float,

  OP_Equal,
};



