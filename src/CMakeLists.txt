add_executable(main main.cpp)
target_link_libraries(main PRIVATE glog::glog)
target_link_libraries(main PRIVATE gflags::gflags)

