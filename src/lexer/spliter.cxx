#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
#include "spliter.hxx"


std::vector<std::string> lexer::split_tokens_delim(
    const std::string &input,
    const std::string& delims,
    bool keep_quotes,
    char escape ) {
  
  std::vector<std::string> result;
  std::string cur;
  bool in_quote = false;
  char quote_char = 0;

  auto flush_token = [&](bool force = false) {
    if (!cur.empty() || force) {
      result.push_back(cur);
      cur.clear();
    }
  };

  for (size_t i = 0; i < input.size(); ++i) {
    char c = input[i];

    if (escape != '\0' && c == escape && i + 1 < input.size()) {
      cur.push_back(input[++i]);
      continue;
    }

    if (in_quote) {
      if (c == quote_char) {
        if (keep_quotes) cur.push_back(c);
        in_quote = false;
        quote_char = 0;
      } else {
        cur.push_back(c);
      }
      continue;
    }

    if (c == '"' || c == '\'') {
      in_quote = true;
      quote_char = c;
      if (keep_quotes) cur.push_back(c);
      continue;
    }

    if (delims.find(c) != std::string::npos) {
      flush_token();
      
      if (!std::isspace(static_cast<unsigned char>(c))) {
        std::string d(1, c);
        result.push_back(d);
      }

      continue;
    }

    cur.push_back(c);
  }

  flush_token();

  return result;
}
