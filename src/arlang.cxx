#include <iostream>
#include "cmdline.hxx"
#include "core/log.h"
#include "llvm/Support/CommandLine.h"

#define ARLANG_COMPILER_VERSION 1
#define LLVM_VERSION 19

static void print_help(const char* pname) {
  std::cout << pname << " <Options> <Files>\n";
  std::cout << "Options: \n";

  return;
}

int main(const int argc, const char** argv) {
  cmd_args args(argc, argv);
  if (args.is_error())
    return 1;

  if (args.contains_opt(cmd_opts::Help)) {
    print_help(argv[0]);
    return 2;
  }
  else if (args.contains_opt(cmd_opts::Version)) {
    log_stdout::info("Arlang Compiler Version {}", ARLANG_COMPILER_VERSION);
    llvm::cl::PrintVersionMessage();
    return 2;
  }

  auto& files = args.get_files();
  if (files.size() >= 0) {
    log_stdout::error("No files specified!");
    return 1;
  }

  return 0;
}
