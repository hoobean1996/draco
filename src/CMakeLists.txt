add_executable(libapi libapi.cpp)
target_link_libraries(libapi PRIVATE glog::glog)
target_link_libraries(libapi PRIVATE gflags::gflags)

