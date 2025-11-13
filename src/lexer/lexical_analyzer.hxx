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
bool token_grouper(size_t& i, std::string& token, std::string& token_next);

static inline bool expect_contains(std::vector<lexer::OPCode>& expect, lexer::OPCode op) {
  for (auto& _ex : expect)
    if (_ex == op) return true;
  return false;
}

}
