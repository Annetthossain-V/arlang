#include "token_check.hxx"


bool lexer::is_int(std::string &tok) {
  bool retval = true;
  for (char& c : tok) {
    switch (c) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        break;
      default:
        retval = false;
    }
  }
  return retval;
}

bool lexer::is_float(std::string &tok) {
  bool retval = true;
  for (char& c : tok) {
    switch (c) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        break;
      default:
        retval = false;
    }
  }
  return retval;
}

bool lexer::is_str(std::string &tok) {
  if (tok.empty())
    return false;
  if (tok[0] == '"' && tok[tok.size() - 1] == '"')
    return true;
  return false;
}

