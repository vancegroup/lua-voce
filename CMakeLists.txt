
cmake_minimum_required(VERSION 2.8.4)

# Set package properties
project(luavoce)

set(CPACK_PACKAGE_VENDOR "Iowa State University - Vance Research Group")
set(CPACK_PACKAGE_CONTACT "Ryan Pavlik <rpavlik@iastate.edu>")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Boost REQUIRED)
find_package(JNI REQUIRED)
find_package(Luabind REQUIRED)
find_program(LUA_COMMAND lua lua5.1)

set(BINDIR bin)
set(LIBDIR lib)
set(INCLUDEDIR include)
set(VOCE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/submodules/voce/src/c++/" ${JNI_INCLUDE_DIRS})

#add_subdirectory(submodules)
add_subdirectory(src)
