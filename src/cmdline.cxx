#include "cmdline.hxx"
#include "core/log.h"

bool cmd_args::is_error() {
  return this->error;
}

std::vector<std::string>& cmd_args::get_files() {
  return this->files;
}

std::vector<std::pair<cmd_opts_t, std::string>>& cmd_args::get_opts() {
  return this->opts;
}

cmd_args::cmd_args(const int argc, const char** argv) {
  for (int i = 0; i < argc; i++) {
    std::string arg = argv[i];


  }
  return;
}
