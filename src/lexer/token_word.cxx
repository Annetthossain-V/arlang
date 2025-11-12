#include "token_word.hxx"
#include "lexical_def.hxx"
#include <stdexcept>

static int pass = 0;

void lexer::TokenImportF( std::string& token, std::vector<lexer::OPCode>& expect, lexer::LexerToken& ltoken ) {
  if (token == "import" && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpected Token '{}'", token));

  if (token == "import" && expect.empty()) {
    expect.push_back(lexer::OPCode::ValString);
    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Import;

    pass++;
    return;
  }
  else if (!expect.empty() && expect[expect.size() - 1] == lexer::OPCode::ValString) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    ltoken.opcode = lexer::OPCode::ValString;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    pass++;
    return;
  }
  else if (!expect.empty() && expect[expect.size() - 1] == lexer::OPCode::Sym && token == ";") {
    expect.clear();
    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_SemiColon;

    if (pass != 2)
      throw std::runtime_error(std::format("Unable to tokenize '{}' for 'import'", token));

    pass = 0;
    lexer::token_mode = lexer::TokenWord::TokenNone;
    return;
  }
}

// TODO: add sub-module support
void lexer::TokenModuleF( std::string& token, std::vector<lexer::OPCode>& expect, lexer::LexerToken& ltoken ) {
  if (token == "module" && (!expect.empty() || pass != 0))
    throw std::runtime_error(std::format("Unexpected Token '{}'", token));

  if (token == "module" && expect.empty()) {
    expect.push_back(lexer::OPCode::Ident);
    ltoken.opcode = lexer::OPCode::KW;
    ltoken.subopcode = lexer::SubOPCode::KW_Module;

    pass++;
    return;
  }
  else if (!expect.empty() && expect[expect.size() - 1] == lexer::OPCode::Ident) {
    expect.clear();
    expect.push_back(lexer::OPCode::Sym);
    ltoken.opcode = lexer::OPCode::Ident;
    ltoken.subopcode = lexer::SubOPCode::OPName;

    pass++;
    return;
  }
  else if (!expect.empty() && expect[expect.size() - 1] == lexer::OPCode::Sym && token == ";") {
    expect.clear();
    ltoken.opcode = lexer::OPCode::Sym;
    ltoken.subopcode = lexer::SubOPCode::Sym_SemiColon;

    if (pass != 2)
      throw std::runtime_error(std::format("Unable to tokenize '{}' for 'import'", token));

    pass = 0;
    lexer::token_mode = lexer::TokenWord::TokenNone;
    return;
  }
}
