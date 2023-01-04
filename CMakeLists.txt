cmake_minimum_required (VERSION 3.8)

project ("lru-cpp")

add_executable (lru-cpp "lru-cpp.cpp" "lru-cpp.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lru-cpp PROPERTY CXX_STANDARD 20)
endif()
