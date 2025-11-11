#pragma once
#include <utility>
#include <vector>
#include <string>
#include <expected>

enum cmd_opts {
  Help,
  Version,
  O1,
  O2,
  O3,
  Wl,
  Nostdlib,
  Nostdinc,
  SaveTemp,
  OutObj,
  OutAsm,
  OutIr,
  Target,
  ImportDir,
  FPie,
  FPic,
  March,
  Mtune,
  FFastMath,
  M32,
  define,
  OutFile,
};
typedef cmd_opts cmd_opts_t;

class cmd_args {
public:
  cmd_args(const int argc, const char** argv);
  std::expected<std::string, bool> contains_opt(cmd_opts_t opt);
  std::vector<std::string>& get_files() {
    return this->files;
  }
  std::vector<std::pair<cmd_opts_t, std::string>>& get_opts() {
    return this->opts;
  }
  bool is_error() {
    return this->error;
  }
  std::vector<std::pair<cmd_opts_t, std::string>> get_all_opt(cmd_opts_t opt);

private:
  std::vector<std::pair<cmd_opts_t, std::string>> opts;
  std::vector<std::string> files;
  bool error = false;
};

