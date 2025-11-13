#include "lexical_def.hxx"
#include "token_word.hxx"

void lexer::TokenFnF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  if (token == "fn" && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpect token '{}'\n line: {}", token, ltoken.line));

  if (token == "fn" && expect.empty()) {
    expect.push_back(lexer::OPCode::Ident);
    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Fn;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident)) {
    for (;;);
  }

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenFunArgsF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenRetTypeExpr(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}
