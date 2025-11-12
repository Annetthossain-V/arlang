#include "lexical_analyzer.hxx"
#include "spliter.hxx"
#include "../core/log.h"
#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <iostream>


static void WordTokenizer(
  std::vector<std::string>& tokens,
  std::string& token, 
  std::vector<lexer::LexerToken>& previous,
  std::array<lexer::OPCode, 255>& expect,
  lexer::LexerToken& ltoken 
) {

  

  return;
}


std::vector<lexer::LexerToken> lexer::lexical_analyze(std::ifstream &file) {
  log_stdout::info("• `Lexical analysis`");

  const std::string delims = " [],{}.()<>/+-*&$!:;=";
  std::string line = "";
  std::vector<lexer::LexerToken> result;

  std::vector<lexer::LexerToken> previous;
  std::array<lexer::OPCode, 255> expect;

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
      WordTokenizer(tokens, token, previous, expect, ltoken);
    }
  }

  return result;
}


