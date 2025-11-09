#pragma once
#include <utility>
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
  Static,
};
typedef cmd_opts cmd_opts_t;

class cmd_args {
public:
  cmd_args(const int argc, const char** argv);
  bool contains_opt(cmd_opts_t opt);
  std::vector<std::string>& get_files();
  std::vector<std::pair<cmd_opts_t, std::string>>& get_opts();
  bool is_error();

private:
  std::vector<std::pair<cmd_opts_t, std::string>> opts;
  std::vector<std::string> files;
  bool error = false;
};
