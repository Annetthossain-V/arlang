#include "lexical_analyzer.hxx"
#include "lexical_def.hxx"
#include "spliter.hxx"
#include "../core/log.h"
#include "token_word.hxx"
#include "token_check.hxx"
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>

lexer::TokenWord lexer::token_mode = lexer::TokenWord::TokenNone;

std::vector<lexer::LexerToken> lexer::lexical_analyze(std::ifstream &file) {
  log_stdout::info("• `Lexical analysis`");

  const std::string delims = " [],{}.()<>/+-*&$!:;=%|";
  std::string line = "";
  std::vector<lexer::LexerToken> result;

  std::vector<lexer::OPCode> expect;

  while (std::getline(file, line)) {
    auto tokens = lexer::split_tokens_delim(
        line,
        delims,
        true,
        '\\'
    );

    tokens.push_back("");
    for (size_t i = 0; i < tokens.size() - 1; i++) {
      std::string& token = tokens[i];
      if (token == "//")
        break;

      lexer::LexerToken ltoken;
      ltoken.word = token;
      ltoken.line = line;

      std::string token_next = "";
      if (i + 1 < token.size())
        token_next = tokens[i + 1];

      if (lexer::token_grouper(i, token, tokens[i + 1])) continue;
      lexer::WordTokenizer(tokens, token, expect, ltoken, token_next, i);

      result.push_back(ltoken);
    }
  }

  return result;
}


void lexer::WordTokenizer(
  std::vector<std::string>& tokens,
  std::string& token,
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken,
  std::string next_token,
  size_t& i
  ) {

  if (lexer::token_mode != lexer::TokenWord::TokenNone)
    goto match_token_word;

  if (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Curly_Braces_Open)
    goto segment_start;
  else if (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Curly_Braces_Close)
    goto segment_end;
  else if (lexer::get_token_type(token) == lexer::SubOPCode::Sym_SemiColon)
    goto segment_semi_colon;

  // temporary fix
  if (lexer::get_token_type(token) == lexer::SubOPCode::Sym_Arrow_Right)
    lexer::token_mode = lexer::TokenWord::TokenRetExpr;

  if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Import)
    lexer::token_mode = lexer::TokenWord::TokenImport;
  else if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Module)
    lexer::token_mode = lexer::TokenWord::TokenModule;
  else if (lexer::get_token_type(token) == lexer::SubOPCode::KW_Fn)
    lexer::token_mode = lexer::TokenWord::TokenFn;

match_token_word:
  switch (lexer::token_mode) {
    case lexer::TokenWord::TokenImport:
      lexer::TokenImportF(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenModule:
      lexer::TokenModuleF(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenFn:
      lexer::TokenFnF(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenFnArgs:
      lexer::TokenFunArgsF(token, expect, ltoken, next_token);
      break;
    case lexer::TokenWord::TokenExpr:
      lexer::TokenExprF(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenRetExpr:
      lexer::TokenRetTypeExpr(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenNone:
      throw std::runtime_error(std::format("Unknown Token '{}'\n line: {}", token, ltoken.line));
      break;
  }

  return;

segment_start:
  ltoken.opcode = lexer::OPCode::Sym;
  ltoken.subopcode = lexer::SubOPCode::Sym_Curly_Braces_Open;
  return;

segment_end:
  ltoken.opcode = lexer::OPCode::Sym;
  ltoken.subopcode = lexer::SubOPCode::Sym_Curly_Braces_Close;
  return;

segment_semi_colon:
  ltoken.opcode = lexer::OPCode::Sym;
  ltoken.subopcode = lexer::SubOPCode::Sym_SemiColon;
  return;

}
