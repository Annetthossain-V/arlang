#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <string_view>


static void log_impl(std::ostringstream& oss, std::string_view fmt) { 
  oss << fmt; 
}

template <typename T, typename... Args>
static void log_impl(std::ostringstream& oss, std::string_view fmt, T&& value, Args&&... args) {
  size_t pos = fmt.find("{}");
  if (pos == std::string_view::npos) {
    oss << fmt;
    return;
  }

  oss << fmt.substr(0, pos);
  oss << std::forward<T>(value);

  log_impl(oss, fmt.substr(pos + 2), std::forward<Args>(args)...);
}

namespace log_stdout {

template <typename... Args>
void info(std::string_view fmt, Args&&... args) {
  std::ostringstream oss;
  log_impl(oss, fmt, std::forward<Args>(args)...);
  std::cout << "[\x1b[1;34mINFO\x1b[0m] " << "\x1b[34m" << oss.str() << "\x1b[0m" << std::endl;
}

template <typename... Args>
void warn(std::string_view fmt, Args&&... args) {
  std::ostringstream oss;
  log_impl(oss, fmt, std::forward<Args>(args)...);
  std::cout << "[\x1b[1;33mWARN\x1b[0m] " << "\x1b[33m" << oss.str() << "\x1b[0m" << std::endl;
}

template <typename... Args>
void error(std::string_view fmt, Args&&... args) {
  std::ostringstream oss;
  log_impl(oss, fmt, std::forward<Args>(args)...);
  std::cerr << "[\x1b[1;31mERROR\x1b[0m] " << "\x1b[31m" << oss.str() << "\x1b[0m" << std::endl;
}

}


