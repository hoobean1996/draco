#include "glog/logging.h"
#include <filesystem>
#include <fstream>
#include <gflags/gflags.h>
#include <iostream>
#include <memory>

DEFINE_bool(verbose, false, "Enable verbose logs");
DEFINE_string(codebase, ".", "Codebase file paths");

// -DCMAKE_TOOLCHAIN_FILE=/home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake
int main(int argc, char *argv[]) {
  const char *usage = R"(
  usage: use this program to build index for codebase.某
  )";
  gflags::SetUsageMessage(usage);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = true;
  LOG(INFO) << "verbose = " << FLAGS_verbose;

  return 0;
}