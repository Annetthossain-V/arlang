#include "lexical_def.hxx"
#include "token_check.hxx"
#include "token_word.hxx"

void lexer::TokenFnF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Fn && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpect token '{}'\n line: {}", token, ltoken.line));

  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Fn && expect.empty()) {
    expect.push_back(lexer::OPCode::Ident);
    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Fn;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident)) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    ltoken.opcode = lexer::OPCode::Ident;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    token_mode = lexer::TokenWord::TokenFnArgs;
    pass++;
    return;
  }

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenFunArgsF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_Bracket_Open) {
    expect.clear();
    expect.push_back(lexer::OPCode::KW);
    expect.push_back(lexer::OPCode::Ident);

    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_Bracket_Open;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::KW) && lexer::check_token(token) == lexer::OPCode::KW) {

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident) && lexer::check_token(token) == lexer::OPCode::UnknownOP) {

    pass++;
    return;
  }

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenRetTypeExpr(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenExprF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  return;
}
