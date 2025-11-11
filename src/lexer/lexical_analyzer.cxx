#include "lexical_analyzer.hxx"
#include "spliter.hxx"
#include "../core/log.h"
#include <vector>
#include <string>
#include <fstream>

std::vector<lexer::LexerToken> lexer::lexical_analyze(std::ifstream &file) {
  log_stdout::info("• `Lexical analysis`");

  const std::string delims = " [],{}.()<>/+-*&$!:;=";
  std::string line = "";
  std::vector<lexer::LexerToken> result;

  while (std::getline(file, line)) {
    lexer::LexerToken lexer_token;
    line.pop_back(); // ?
    lexer_token.line = line;

    auto tokens = lexer::split_tokens_delim(
        line,
        delims,  
        true, 
        '\\'
    );

    

  }
 
  return result;
}


