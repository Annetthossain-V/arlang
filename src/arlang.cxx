#include <iostream>
#include <fstream>
#include <stdexcept>
#include "cmdline.hxx"
#include "core/log.h"
#include "lexer/lexical_analyzer.hxx"
#include "lexer/lexical_def.hxx"
#include "llvm/Support/CommandLine.h"

#define ARLANG_COMPILER_VERSION 1

static void print_help(const char* pname) {
  std::cout << pname << " <Options> <Files>\n";
  std::cout << "Options: \n";
  std::cout << " --help # prints this message\n";
  std::cout << " --version # prints version info\n";
  std::cout << " -O1 # optimization level 1\n";
  std::cout << " -O2 # optimization level 2\n";
  std::cout << " -O3 # optimization level 3\n";
  std::cout << " -Wl <arg> # pass argument to linker\n";
  std::cout << " -nostdlib # link without stdlib\n";
  std::cout << " -nostdinc # compile without std-include path\n";
  std::cout << " --save-temp # save temporary files\n";
  std::cout << " --out-obj # compile and assemble only\n";
  std::cout << " --out-asm # compile only\n";
  std::cout << " --out-ir # emmit llvm-ir\n";
  std::cout << " --target <arg> # specify target machine (llvm)\n";
  std::cout << " -import-dir # add path to import search path\n";
  std::cout << " -fpie # N/A\n";
  std::cout << " -fpic # N/A\n";
  std::cout << " -march <arg> # optimize specified arch\n";
  std::cout << " -mtune <arg> # tune for specified arch\n";
  std::cout << " -ffast-math # fast math optimization (unsafe)\n";
  std::cout << " -m32 # compile to 32-bit code\n";
  std::cout << " --define <arg> # adds a compiler definition\n";
  std::cout << " -o <arg> # specify output name\n";

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
  if (files.size() == 0) {
    log_stdout::error("No files specified!");
    return 1;
  }

  for (auto& file_name : files) {
    log_stdout::info("Compiling `{}`", file_name);
    std::ifstream file(file_name, std::ios::in);

    if (!file.is_open()) {
      log_stdout::error("Failed to open `{}`", file_name);
      return 1;
    }

    try {
      auto lexer_tokens = lexer::lexical_analyze(file);
    } catch (std::runtime_error& e) {
      log_stdout::error("{}", e.what());
    }

    file.close();
  }

  return 0;
}
