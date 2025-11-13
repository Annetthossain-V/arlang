#pragma once
#include "lexical_analyzer.hxx"
#include "lexical_def.hxx"

extern int pass;

namespace lexer {

enum TokenWord {
  TokenImport,
  TokenModule,
  TokenFn,
  TokenFnArgs,
  TokenExprVal,
  TokenNone,
};

extern TokenWord token_mode;

void WordTokenizer(
  std::vector<std::string>& tokens,
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken,
  std::string next_token,
  size_t& i
);

void TokenImportF(
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken
);

void TokenModuleF(
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken
);

void TokenFnF(
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken
);

void TokenFunArgsF(
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken
);

void TokenExprValF(
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken
);

void TokenRetTypeExpr(
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken
);

void TokenExprGenBasicF(
  void
);

}
