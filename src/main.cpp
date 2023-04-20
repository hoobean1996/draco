#include <filesystem>
#include <fstream>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <memory>

DEFINE_bool(verbose, false, "Enable verbose logs");
DEFINE_string(codebase, ".", "Codebase file paths");

// -DCMAKE_TOOLCHAIN_FILE=/home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake
int main(int argc, char *argv[]) {
  const char *usage = R"(
  usage: use this program to build index for codebase.
  )";
  gflags::SetUsageMessage(usage);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = true;
  LOG(INFO) << "verbose = " << FLAGS_verbose;
  auto absCodebase =
      std::filesystem::absolute(std::filesystem::path(FLAGS_codebase));
  LOG(INFO) << "codebase = " << absCodebase;

  std::string home = std::getenv("HOME");
  LOG(INFO) << "HOME = " << home;

  FILE *indexer = fopen("./.dracoidx", "w+");
  if (indexer == nullptr) {
    LOG(FATAL) << "draco can't open index file";
  }

  std::filesystem::path root_path(absCodebase);
  for (auto &p : std::filesystem::recursive_directory_iterator(root_path)) {
    if (p.is_regular_file() && p.path().extension() == ".txt") {
      LOG(INFO) << "file = " << p.path().string();
      std::ifstream infile(p.path().string());
      if (!infile.is_open()) {
        LOG(FATAL) << "draco failed to open file, file = " << p.path().string();
      }
      std::string body;
      std::string line;
      while (std::getline(infile, line)) {
        body += line;
      }
      LOG(INFO) << "file content:";
      LOG(INFO) << body;
      infile.close();
    }
  }

  return 0;
}