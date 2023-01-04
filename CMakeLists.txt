# CMakeList.txt: CMake-Projekt für "lru-cpp". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

project ("lru-cpp")

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (lru-cpp "lru-cpp.cpp" "lru-cpp.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lru-cpp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
