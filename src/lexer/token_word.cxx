#include "token_word.hxx"
#include "lexical_def.hxx"
#include "lexical_analyzer.hxx"
#include "token_check.hxx"
#include <stdexcept>

int pass = 0;

void lexer::TokenImportF( std::string& token, std::vector<lexer::OPCode>& expect, lexer::LexerToken& ltoken ) {
  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Import && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpected Token '{}'\n line: {}", token, ltoken.line));

  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Import && expect.empty()) {
    expect.push_back(lexer::OPCode::ValString);
    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Import;

    pass++;
    return;
  }
  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::ValString)) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    ltoken.opcode = lexer::OPCode::ValString;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    pass++;
    return;
  }
  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_SemiColon) {
    expect.clear();
    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_SemiColon;

    if (pass != 2)
      throw std::runtime_error(std::format("Unable to tokenize '{}' for 'import'", token));

    pass = 0;
    lexer::token_mode = lexer::TokenWord::TokenNone;
    return;
  }
  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}

void lexer::TokenModuleF( std::string& token, std::vector<lexer::OPCode>& expect, lexer::LexerToken& ltoken ) {
  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Module && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpected Token '{}'\n line: {}", token, ltoken.line));

  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Module && expect.empty()) {
    expect.push_back(lexer::OPCode::Ident);
    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Module;

    pass++;
    return;
  }
  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Ident)) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    ltoken.opcode = lexer::OPCode::Ident;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    pass++;
    return;
  }
  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_Double_Colon) {
    expect.clear();
    expect.push_back(lexer::OPCode::Ident);
    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_Double_Colon;

    pass++;
    return;
  }
  else if (!expect.empty() && expect_contains(expect, lexer::OPCode::Sym) && lexer::get_token_type(token) == lexer::SubOPCode::Sym_SemiColon) {
    expect.clear();
    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_SemiColon;

    if (pass < 2)
      throw std::runtime_error(std::format("Unable to tokenize '{}' for 'import'", token));

    pass = 0;
    lexer::token_mode = lexer::TokenWord::TokenNone;
    return;
  }
  throw std::runtime_error(std::format("Unexpect End! token '{}'\n line: {}", token, ltoken.line));
}
