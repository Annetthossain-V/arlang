#pragma once
#include <vector>
#include <string>

enum cmd_opts {
  Help,
  Version,
  O1,
  O2,
  O3,
  I,
  L,
  c,
  S,
  Si,
  Nostd,
  Noinc,
  SaveTemp,
  Target,
};
typedef cmd_opts cmd_opts_t;

class cmd_args {
public:
  cmd_args(const int argc, const char** argv);
  bool contains_opt();
  std::vector<std::string>& get_files();
private:
  std::vector<cmd_opts_t> opts;
  std::vector<std::string> files;
};

