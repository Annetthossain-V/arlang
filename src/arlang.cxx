#include "cmdline.hxx"
#include "core/log.h"

#define ARLANG_COMPILER_VERSION 1
#define LLVM_VERSION 19

static void print_help() {

  return;
}

int main(const int argc, const char** argv) {
  cmd_args args(argc, argv);
  if (args.is_error())
    return 1;

  if (args.contains_opt(cmd_opts::Help)) {
    print_help();
    return 2;
  }
  else if (args.contains_opt(cmd_opts::Version)) {
    log_stdout::info("Arlang Compiler Version {}", ARLANG_COMPILER_VERSION);
    log_stdout::info("LLVM Version {}", LLVM_VERSION);
    return 2;
  }


  return 0;
}
