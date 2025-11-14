#include "token_check.hxx"
#include "lexical_def.hxx"

lexer::SubOPCode lexer::get_token_type(std::string& kw) {
  if (kw == "import")
    return lexer::SubOPCode::KW_Import;
  else if (kw == "module")
    return lexer::SubOPCode::KW_Module;
  else if (kw == "extern")
    return lexer::SubOPCode::KW_Extern;
  else if (kw == "fn")
    return lexer::SubOPCode::KW_Fn;

  else if (kw == "uchar")
    return lexer::SubOPCode::KW_CUChar;
  else if (kw == "char")
    return lexer::SubOPCode::KW_CChar;
  else if (kw == "short")
    return lexer::SubOPCode::KW_CShort;
  else if (kw == "ushort")
    return lexer::SubOPCode::KW_CUShort;
  else if (kw == "int")
    return lexer::SubOPCode::KW_CInt;
  else if (kw == "uint")
    return lexer::SubOPCode::KW_CUInt;
  else if (kw == "long")
    return lexer::SubOPCode::KW_CLong;
  else if (kw == "ulong")
    return lexer::SubOPCode::KW_CULong;
  else if (kw == "llong")
    return lexer::SubOPCode::KW_CLongLong;
  else if (kw == "ullong")
    return lexer::SubOPCode::KW_CULongLong;
  else if (kw == "float")
    return lexer::SubOPCode::KW_CFloat;
  else if (kw == "double")
    return lexer::SubOPCode::KW_CDouble;

  else if (kw == "u8")
    return lexer::SubOPCode::KW_U8;
  else if (kw == "i8")
    return lexer::SubOPCode::KW_I8;
  else if (kw == "u16")
    return lexer::SubOPCode::KW_U16;
  else if (kw == "i16")
    return lexer::SubOPCode::KW_I16;
  else if (kw == "u32")
    return lexer::SubOPCode::KW_U32;
  else if (kw == "i32")
    return lexer::SubOPCode::KW_I32;
  else if (kw == "u64")
    return lexer::SubOPCode::KW_U64;
  else if (kw == "i64")
    return lexer::SubOPCode::KW_I64;
  else if (kw == "f32")
    return lexer::SubOPCode::KW_F32;
  else if (kw == "f64")
    return lexer::SubOPCode::KW_F64;
  else if (kw == "size")
    return lexer::SubOPCode::KW_Size;
  else if (kw == "usize")
    return lexer::SubOPCode::KW_USize;

  else if (kw == ";")
    return lexer::SubOPCode::Sym_SemiColon;
  else if (kw == "[")
    return lexer::SubOPCode::Sym_Square_Brackect_Open;
  else if (kw == "]")
    return lexer::SubOPCode::Sym_Square_Brackect_Close;
  else if (kw == "{")
    return lexer::SubOPCode::Sym_Curly_Braces_Open;
  else if (kw == "}")
    return lexer::SubOPCode::Sym_Curly_Braces_Close;
  else if (kw == ">")
    return lexer::SubOPCode::Sym_Greater_Sign;
  else if (kw == "<")
    return lexer::SubOPCode::Sym_Less_Sign;
  else if (kw == ",")
    return lexer::SubOPCode::Sym_Comma;
  else if (kw == ".")
    return lexer::SubOPCode::Sym_Dot;
  else if (kw == "(")
    return lexer::SubOPCode::Sym_Bracket_Open;
  else if (kw == ")")
    return lexer::SubOPCode::Sym_Bracket_Close;
  else if (kw == "/")
    return lexer::SubOPCode::Sym_Slash;
  else if (kw == "+")
    return lexer::SubOPCode::Sym_Plus;
  else if (kw == "-")
    return lexer::SubOPCode::Sym_Minus;
  else if (kw == "*")
    return lexer::SubOPCode::Sym_Asterisk;
  else if (kw == "&")
    return lexer::SubOPCode::Sym_And;
  else if (kw == "$")
    return lexer::SubOPCode::Sym_Dollar;
  else if (kw == "!")
    return lexer::SubOPCode::Sym_Exclamation;
  else if (kw == ":")
    return lexer::SubOPCode::Sym_Colon;
  else if (kw == "=")
    return lexer::SubOPCode::Sym_Equal;
  else if (kw == "%")
    return lexer::SubOPCode::Sym_Percentage;
  else if (kw == "|")
    return lexer::SubOPCode::Sym_Or;

  else if (kw == "::")
    return lexer::SubOPCode::Sym_Double_Colon;
  else if (kw == "**")
    return lexer::SubOPCode::Sym_Double_Asterisk;
  else if (kw == "==")
    return lexer::SubOPCode::Sym_Double_Equal;
  else if (kw == ">=")
    return lexer::SubOPCode::Sym_Greater_Equal;
  else if (kw == "<=")
    return lexer::SubOPCode::Sym_Less_Equal;
  else if (kw == "+=")
    return lexer::SubOPCode::Sym_Plus_Equal;
  else if (kw == "-=")
    return lexer::SubOPCode::Sym_Minus_Equal;
  else if (kw == "*=")
    return lexer::SubOPCode::Sym_Asterisk_Equal;
  else if (kw == "/=")
    return lexer::SubOPCode::Sym_Slash_Equal;
  else if (kw == "%=")
    return lexer::SubOPCode::Sym_Percentage_Equal;
  else if (kw == "<<")
    return lexer::SubOPCode::Sym_Shift_Left;
  else if (kw == ">>")
    return lexer::SubOPCode::Sym_Shift_Right;
  else if (kw == "<-")
    return lexer::SubOPCode::Sym_Arrow_Left;
  else if (kw == "->")
    return lexer::SubOPCode::Sym_Arrow_Right;
  else if (kw == "&&")
    return lexer::SubOPCode::Sym_And_And;
  else if (kw == "||")
    return lexer::SubOPCode::Sym_Or_Or;
  else if (kw == "++")
    return lexer::SubOPCode::Sym_Plus_Plus;
  else if (kw == "--")
    return lexer::SubOPCode::Sym_Minus_Minus;

  return lexer::SubOPCode::SubUnknownOp;
}

lexer::OPCode lexer::check_token(std::string& kw) {
  auto type = lexer::get_token_type(kw);
  switch (type) {

  }
  return lexer::OPCode::UnknownOP;
}
