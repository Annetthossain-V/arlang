#include "lexical_def.hxx"
#include "token_check.hxx"
#include "token_word.hxx"

void lexer::TokenFnF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Fn && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpect token '{}'\n line: {}", token, ltoken.line));

  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Fn && expect.empty()) {
    expect.push_back(lexer::OPCode::Ident);
    expect.push_back(lexer::OPCode::Sym);

    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Fn;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_Dot) {
    expect.clear();
    expect.push_back(lexer::OPCode::Ident);

    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_Dot;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Greater_Sign || lexer::get_token_type(token) == lexer::SubOPCode::Sym_Less_Sign)) {
    expect.clear();

    if (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Greater_Sign)
      expect.push_back(lexer::OPCode::Sym);
    else if (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Less_Sign)
      expect.push_back(lexer::OPCode::Ident);

    ltoken.opcode = lexer::check_token(token);
    ltoken.subopcode = lexer::get_token_type(token);

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident) && lexer::check_token(token) == lexer::OPCode::UnknownOP) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    ltoken.opcode = lexer::OPCode::Ident;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_Bracket_Open) {
    expect.clear();
    expect.push_back(lexer::OPCode::KW);
    expect.push_back(lexer::OPCode::Ident);

    ltoken.opcode = lexer::check_token(token);
    ltoken.subopcode = lexer::get_token_type(token);

    token_mode = lexer::TokenWord::TokenFnArgs;
    pass = 0;
    return;
  }

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenFunArgsF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken, std::string& ntoken) {
  // if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident) && (lexer::check_token(token) == lexer::OPCode::KW || lexer::check_token(token) == lexer::OPCode::UnknownOP)) {
  //   expect.clear();
  //   expect.push_back(lexer::OPCode::Ident);
  //   expect.push_back(lexer::OPCode::Sym);

  //   ltoken.opcode = lexer::check_token(token);
  //   ltoken.subopcode = lexer::get_token_type(token);

  //   pass++;
  //   return;
  // }

  if (!expect.empty() && expect_contains(expect, lexer::OPCode::KW) && lexer::check_token(token) == lexer::OPCode::KW) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    expect.push_back(lexer::OPCode::Ident);

    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::get_token_type(token);

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident) && lexer::check_token(token) == lexer::OPCode::UnknownOP) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);

    ltoken.opcode = lexer::OPCode::Ident;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Comma || lexer::get_token_type(token) == lexer::SubOPCode::Sym_Double_Colon)) {
    expect.clear();
    expect.push_back(lexer::OPCode::Ident);
    expect.push_back(lexer::OPCode::KW);

    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::get_token_type(token);

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Asterisk || lexer::get_token_type(token) == lexer::SubOPCode::Sym_Double_Asterisk)) {
    expect.clear();
    expect.push_back(lexer::OPCode::Ident);

    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::get_token_type(token);

    pass++;
    return;
  }

  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_Bracket_Close) {
    expect.clear();

    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_Bracket_Close;

    // ntoken is empty for some reason!
    if (lexer::get_token_type(ntoken) == lexer::SubOPCode::Sym_Arrow_Right)
      token_mode = lexer::TokenWord::TokenRetExpr;
    else token_mode = lexer::TokenWord::TokenNone;
    pass = 0;
    return;
  }

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenRetTypeExpr(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  if (expect.empty() && lexer::get_token_type(token) == lexer::SubOPCode::Sym_Arrow_Right) {
    expect.push_back(lexer::OPCode::Ident);
    expect.push_back(lexer::OPCode::KW);

    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_Arrow_Right;

    pass++;
    return;
  }
  else if (!expect.empty() && (expect_contains(expect, lexer::OPCode::Ident) || expect_contains(expect, lexer::OPCode::KW) && (lexer::check_token(token) == lexer::OPCode::KW || lexer::check_token(token) == lexer::OPCode::UnknownOP))) {
    expect.clear();

    ltoken.opcode = lexer::check_token(token);
    ltoken.subopcode = lexer::get_token_type(token);

    token_mode = lexer::TokenWord::TokenNone;
    pass = 0;
    return;
  }

  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenExprF(std::string &token, std::vector<lexer::OPCode> &expect, lexer::LexerToken &ltoken) {
  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}
