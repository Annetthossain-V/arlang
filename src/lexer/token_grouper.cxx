#include "lexical_analyzer.hxx"

bool lexer::token_grouper(size_t& i, std::string& token, std::string& token_next) {
  if (token.empty() || token_next.empty())
    return false;

  if (token.size() != 1 || token_next.size() != 1)
    return false;

  char c = token[0];
  char nc = token_next[0];

  if (c == ':' && nc == ':') {
    token_next = "::";
    return true;
  }
  else if (c == '/' && nc == '/') {
    token_next = "//";
    return true;
  }
  else if (c == '*' && nc == '*') {
    token_next = "**";
    return true;
  }
  else if (c == '=' && nc == '=') {
    token_next = "==";
    return true;
  }
  else if (c == '>' && nc == '=') {
    token_next = ">=";
    return true;
  }
  else if (c == '<' && nc == '=') {
    token_next = "<=";
    return true;
  }
  else if (c == '+' && nc == '=') {
    token_next = "+=";
    return true;
  }
  else if (c == '-' && nc == '=') {
    token_next = "-=";
    return true;
  }
  else if (c == '*' && nc == '=') {
    token_next = "*=";
    return true;
  }
  else if (c == '/' && nc == '=') {
    token_next = "/=";
    return true;
  }
  else if (c == '%' && nc == '=') {
    token_next = "%=";
    return true;
  }
  else if (c == '<' && nc == '<') {
    token_next = "<<";
    return true;
  }
  else if (c == '>' && nc == '>') {
    token_next = ">>";
    return true;
  }
  else if (c == '-' && nc == '>') {
    token_next = "->";
    return true;
  }
  else if (c == '<' && nc == '-') {
    token_next = "<-";
    return true;
  }
  else if (c == '&' && nc == '&') {
    token_next = "&&";
    return true;
  }
  else if (c == '|' && nc == '|') {
    token_next = "||";
    return true;
  }
  else if (c == '+' && nc == '+') {
    token_next = "++";
    return true;
  }
  else if (c == '-' && nc == '-') {
    token_next = "--";
    return true;
  }

  return false;
}
