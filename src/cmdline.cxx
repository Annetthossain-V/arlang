#include "cmdline.hxx"
#include "core/log.h"

#define MISSING_ARG_MACRO(msg) \
    log_stdout::error(msg); \
    this->error = true; \
    break

std::expected<std::string, bool> cmd_args::contains_opt(cmd_opts_t opt) {
  for (auto& opt_each : this->opts) {
    auto [cmd_opt, item] = opt_each;
    if (cmd_opt == opt) return item;
  }
  return std::unexpected(false);
}

cmd_args::cmd_args(const int argc, const char** argv) {
  if (argc < 2) {
    log_stdout::error("No arguments given!");
    this->error = true;
    return;
  }

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg[0] != '-') {
      this->files.push_back(arg);
      continue;
    }

    if (arg == "--help" || arg == "-h")
      this->opts.push_back(std::make_pair(cmd_opts::Help, ""));

    else if (arg == "--version" || arg == "-v")
      this->opts.push_back(std::make_pair(cmd_opts::Version, ""));

    else if (arg == "-O1") 
      this->opts.push_back(std::make_pair(cmd_opts::O1, ""));
    
    else if (arg == "-O2") 
      this->opts.push_back(std::make_pair(cmd_opts::O2, ""));
    
    else if (arg == "-O3") 
      this->opts.push_back(std::make_pair(cmd_opts::O3, ""));
    
    else if (arg == "-Wl") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for -Wl!");
      }
      this->opts.push_back(std::make_pair(cmd_opts::Wl, argv[++i]));
    }

    else if (arg == "-nostdlib")
      this->opts.push_back(std::make_pair(cmd_opts::Nostdlib, ""));

    else if (arg == "-nostdinc")
      this->opts.push_back(std::make_pair(cmd_opts::Nostdinc, ""));

    else if (arg == "--save-temp")
      this->opts.push_back(std::make_pair(cmd_opts::SaveTemp, ""));

    else if (arg == "--out-obj")
      this->opts.push_back(std::make_pair(cmd_opts::OutObj, ""));

    else if (arg == "--out-asm")
      this->opts.push_back(std::make_pair(cmd_opts::OutAsm, ""));

    else if (arg == "--out-ir")
      this->opts.push_back(std::make_pair(cmd_opts::OutIr, ""));

    else if (arg == "--target") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for `--target`");
      }
      this->opts.push_back(std::make_pair(cmd_opts::Target, argv[++i]));
    }

    else if (arg == "-import-dir") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for `-import-dir`");
      }
      this->opts.push_back(std::make_pair(cmd_opts::ImportDir, argv[++i]));
    }

    else if (arg == "-fpie")
      this->opts.push_back(std::make_pair(cmd_opts::FPie, ""));

    else if (arg == "-fpic")
      this->opts.push_back(std::make_pair(cmd_opts::FPic, ""));

    else if (arg == "-march") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for `-march`");
      }
      this->opts.push_back(std::make_pair(cmd_opts::March, argv[++i]));
    }

    else if (arg == "-mtune") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for `-mtune`");
      }
      this->opts.push_back(std::make_pair(cmd_opts::Mtune, argv[++i]));
    }

    else if (arg == "-ffast-math")
      this->opts.push_back(std::make_pair(cmd_opts::FFastMath, ""));

    else if (arg == "-m32")
      this->opts.push_back(std::make_pair(cmd_opts::M32, ""));

    else if (arg == "--define") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for `--define`");
      }
      this->opts.push_back(std::make_pair(cmd_opts::define, argv[++i]));
    }

    else if (arg == "-o") {
      if (i + 1 >= argc) {
        MISSING_ARG_MACRO("Missing argument for `-o`");
      }
      this->opts.push_back(std::make_pair(cmd_opts::OutFile, argv[++i]));
    }

    else {
      log_stdout::error("Unknown Argument `{}`", arg);
      this->error = true;
      break;
    }
  }

  return;
}

std::vector<std::pair<cmd_opts_t, std::string>> cmd_args::get_all_opt(cmd_opts_t opt) {
  std::vector<std::pair<cmd_opts_t, std::string>> retval;
  for (auto& opts : this->opts) {
    auto& [val, name] = opts;
    if (val == opt) {
      retval.push_back(std::make_pair(val, name));
    }
  }
  return retval;
}

