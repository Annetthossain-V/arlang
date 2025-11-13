#include "token_check.hxx"

lexer::SubOPCode lexer::get_token_type(std::string& kw) {
  return lexer::SubOPCode::SubUnknownOp;
}

lexer::OPCode lexer::check_token(std::string& kw) {
  return lexer::OPCode::UnknownOP;
}
