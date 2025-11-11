#pragma once
#include "lexical_def.hxx"
#include <vector>
#include <fstream>

namespace lexer {

struct LexerToken {
  OPCode opcode;
  SubOPCode subopcode;
  std::string word;
  std::string line;
};

std::vector<LexerToken> lexical_analyze(std::ifstream& file); 


}

