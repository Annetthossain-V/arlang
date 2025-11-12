#include "lexical_analyzer.hxx"
#include "lexical_def.hxx"
#include "spliter.hxx"
#include "../core/log.h"
#include "token_word.hxx"
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>


lexer::TokenWord lexer::token_mode = lexer::TokenWord::TokenNone;

std::vector<lexer::LexerToken> lexer::lexical_analyze(std::ifstream &file) {
  log_stdout::info("• `Lexical analysis`");

  const std::string delims = " [],{}.()<>/+-*&$!:;=";
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

    for (size_t i = 0; i < tokens.size(); i++) {
      std::string& token = tokens[i];
      if (token == "//")
        break;

      lexer::LexerToken ltoken;
      ltoken.word = token;
      ltoken.line = line;

      std::string next_token = "";
      if (i + 1 < token.size())
        next_token = tokens[i + 1];

      lexer::token_grouper(i, token, next_token);
      lexer::WordTokenizer(tokens, token, expect, ltoken, next_token, i);

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

  if (token == "import")
    lexer::token_mode = lexer::TokenWord::TokenImport;
  else if (token == "module")
    lexer::token_mode = lexer::TokenWord::TokenModule;

match_token_word:
  switch (lexer::token_mode) {
    case lexer::TokenWord::TokenImport:
      lexer::TokenImportF(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenModule:
      lexer::TokenModuleF(token, expect, ltoken);
      break;
    case lexer::TokenWord::TokenNone:
      throw std::runtime_error(std::format("Unknown Token '{}'", token));
      break;
  }

  return;
}

void lexer::token_grouper(size_t& i, std::string& token, std::string& token_next) {
  if (token.size() != 1 || token_next.size() != 1)
    return;

  char tokenc = token[0];
  char token_nextc = token_next[0];

  return;
}
