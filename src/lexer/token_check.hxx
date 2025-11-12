#pragma once
#include <string>
#include "lexical_def.hxx"

namespace lexer {

SubOPCode get_token_type(std::string& kw);
OPCode check_token(std::string& kw);

}
