#include "lexical_analyzer.hxx"
#include "lexical_def.hxx"
#include "spliter.hxx"
#include "../core/log.h"
#include <vector>
#include <string>
#include <fstream>



static void WordTokenizer(
  std::vector<std::string>& tokens,
  std::string& token, 
  std::vector<lexer::OPCode>& expect,
  lexer::LexerToken& ltoken 
) {
  static bool in_asm_block = false;
  static bool complete_expr = false;

  if (token.size() == 1) {
    switch (token[0]) {
      case '[':
        ltoken.opcode = lexer::OPCode::Sym;
        break;
      case ']':
        ltoken.opcode = lexer::OPCode::Sym;
        break;

      default:
        break;
    }
  }

  

  bool found_expect = false;
  for (auto& _expect : expect)
    if (ltoken.opcode == _expect) found_expect = true; 

  if (!found_expect) 
    throw std::runtime_error(std::format("Unexpected Token {}", token));
  return;
}


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
      lexer::LexerToken ltoken;
      ltoken.word = token;
      ltoken.line = line;
      WordTokenizer(tokens, token, expect, ltoken);
    }
  }

  return result;
}


