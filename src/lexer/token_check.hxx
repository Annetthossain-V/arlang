#pragma once
#include <string>
#include "lexical_def.hxx"

namespace lexer {

SubOPCode get_token_type(std::string& kw);
OPCode check_token(std::string& kw);

bool is_int(std::string& tok);
bool is_float(std::string& tok);
bool is_str(std::string& tok);

}
