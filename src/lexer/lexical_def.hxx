#pragma once

namespace lexer {

enum OPCode {
  KW,
  Ident,
  Op,
  Int,
  Float,
  String,
  Sym,

  UnknownOP,
};

enum SubOPCode {
  KW_Int,
  KW_Float,
  KW_I32,
  KW_F32,

  OP_Equal,

  OPName,
  SubUnknownOp,
};

}


