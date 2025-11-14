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
  else if (kw == "void")
    return lexer::SubOPCode::KW_Void;

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
  else if (kw == "!=")
    return lexer::SubOPCode::Sym_Not_Equal;

  return lexer::SubOPCode::SubUnknownOp;
}

#define RT_KW return lexer::OPCode::KW
#define RT_Ident return lexer::OPCode::Ident
#define RT_VInt return lexer::OPCode::VInt
#define RT_VFloat return lexer::OPCode::VFloat
#define RT_VStr return lexer::OPCode::VString
#define RT_Sym return lexer::OPCode::Sym
#define RT_Asm return lexer::OPCode::Asm

// need to finish this to check other stuff
lexer::OPCode lexer::check_token(std::string& kw) {
  auto type = lexer::get_token_type(kw);
  switch (type) {
    case lexer::SubOPCode::KW_Import:
    case lexer::SubOPCode::KW_Module:
    case lexer::SubOPCode::KW_Extern:
    case lexer::SubOPCode::KW_Fn:
    case lexer::SubOPCode::KW_CChar:
    case lexer::SubOPCode::KW_CUChar:
    case lexer::SubOPCode::KW_CShort:
    case lexer::SubOPCode::KW_CUShort:
    case lexer::SubOPCode::KW_CInt:
    case lexer::SubOPCode::KW_CUInt:
    case lexer::SubOPCode::KW_CLong:
    case lexer::SubOPCode::KW_CULong:
    case lexer::SubOPCode::KW_CLongLong:
    case lexer::SubOPCode::KW_CULongLong:
    case lexer::SubOPCode::KW_CFloat:
    case lexer::SubOPCode::KW_CDouble:
    case lexer::SubOPCode::KW_U8:
    case lexer::SubOPCode::KW_I8:
    case lexer::SubOPCode::KW_U16:
    case lexer::SubOPCode::KW_I16:
    case lexer::SubOPCode::KW_U32:
    case lexer::SubOPCode::KW_I32:
    case lexer::SubOPCode::KW_U64:
    case lexer::SubOPCode::KW_I64:
    case lexer::SubOPCode::KW_F32:
    case lexer::SubOPCode::KW_F64:
    case lexer::SubOPCode::KW_Size:
    case lexer::SubOPCode::KW_USize:
    case lexer::SubOPCode::KW_Void:
      RT_KW;

    case lexer::SubOPCode::Sym_SemiColon:
    case lexer::SubOPCode::Sym_Square_Brackect_Open:
    case lexer::SubOPCode::Sym_Square_Brackect_Close:
    case lexer::SubOPCode::Sym_Curly_Braces_Open:
    case lexer::SubOPCode::Sym_Curly_Braces_Close:
    case lexer::SubOPCode::Sym_Comma:
    case lexer::SubOPCode::Sym_Dot:
    case lexer::SubOPCode::Sym_Bracket_Open:
    case lexer::SubOPCode::Sym_Bracket_Close:
    case lexer::SubOPCode::Sym_Greater_Sign:
    case lexer::SubOPCode::Sym_Less_Sign:
    case lexer::SubOPCode::Sym_Slash:
    case lexer::SubOPCode::Sym_Plus:
    case lexer::SubOPCode::Sym_Minus:
    case lexer::SubOPCode::Sym_Asterisk:
    case lexer::SubOPCode::Sym_And:
    case lexer::SubOPCode::Sym_Dollar:
    case lexer::SubOPCode::Sym_Exclamation:
    case lexer::SubOPCode::Sym_Colon:
    case lexer::SubOPCode::Sym_Equal:
    case lexer::SubOPCode::Sym_Percentage:
    case lexer::SubOPCode::Sym_Or:
    case lexer::SubOPCode::Sym_Double_Colon:
    case lexer::SubOPCode::Sym_Double_Asterisk:
    case lexer::SubOPCode::Sym_Double_Equal:
    case lexer::SubOPCode::Sym_Greater_Equal:
    case lexer::SubOPCode::Sym_Less_Equal:
    case lexer::SubOPCode::Sym_Plus_Equal:
    case lexer::SubOPCode::Sym_Minus_Equal:
    case lexer::SubOPCode::Sym_Asterisk_Equal:
    case lexer::SubOPCode::Sym_Slash_Equal:
    case lexer::SubOPCode::Sym_Percentage_Equal:
    case lexer::SubOPCode::Sym_Shift_Left:
    case lexer::SubOPCode::Sym_Shift_Right:
    case lexer::SubOPCode::Sym_Arrow_Left:
    case lexer::SubOPCode::Sym_Arrow_Right:
    case lexer::SubOPCode::Sym_And_And:
    case lexer::SubOPCode::Sym_Or_Or:
    case lexer::SubOPCode::Sym_Plus_Plus:
    case lexer::SubOPCode::Sym_Minus_Minus:
    case lexer::SubOPCode::Sym_Not_Equal:
      RT_Sym;

    case lexer::SubOPCode::SubUnknownOp:
      if (lexer::is_int(kw)) RT_VInt;
      else if (lexer::is_float(kw)) RT_VFloat;
      else if (lexer::is_str(kw)) RT_VStr;

    default:
      break;
  }
  return lexer::OPCode::UnknownOP;
}
