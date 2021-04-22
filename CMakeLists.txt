cmake_minimum_required (VERSION 3.0)
project (UnitTest)
project (Example)

set (CMAKE_CXX_STANDARD 17)

set(SRC "${UnitTest_SOURCE_DIR}/")

add_library(UnitTest STATIC
  "${SRC}/include/TestBase.hpp"
)

set_target_properties(UnitTest PROPERTIES LINKER_LANGUAGE CXX)

add_executable(Example
  "${SRC}/example/main.cpp"
)

include_directories(PUBLIC
  "${SRC}/include/"
)