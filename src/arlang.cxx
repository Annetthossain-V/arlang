#include "cmdline.hxx"


int main(const int argc, const char** argv) {
  cmd_args args(argc, argv);
  if (args.is_error())
    return 1;

  return 0;
}
