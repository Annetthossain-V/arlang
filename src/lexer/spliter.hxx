#pragma once
#include <string>
#include <vector>

namespace lexer {

std::vector<std::string> split_tokens_delim(
  const std::string& input,
  const std::string& delims,
  bool keep_quotes,
  char escape
);


}

