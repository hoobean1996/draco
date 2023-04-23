#include "glog/logging.h"
#include <filesystem>
#include <fstream>
#include <gflags/gflags.h>
#include <iostream>
#include <memory>

// -DCMAKE_TOOLCHAIN_FILE=/home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake
int main(int argc, char *argv[]) {
  const char *usage = R"(
  usage: use this program to parse graphql and restful.
  )";
  gflags::SetUsageMessage(usage);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = true;

  std::string sourceCode = R"()";

  return 0;
}