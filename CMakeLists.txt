
cmake_minimum_required(VERSION 2.8.4)

# Set package properties
project(luavoce)

set(CPACK_PACKAGE_VENDOR "Iowa State University - Vance Research Group")
set(CPACK_PACKAGE_CONTACT "Ryan Pavlik <rpavlik@iastate.edu>")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Boost REQUIRED)
#http://www.cmake.org/cmake/help/cmake-2-8-docs.html#module:FindJNI
find_package(JNI REQUIRED)
find_package(Luabind REQUIRED)
find_program(LUA_COMMAND lua lua5.1)

set(BINDIR bin)
set(LIBDIR lib)
set(INCLUDEDIR include)
set(VOCE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/submodules/voce/src/c++/" ${JNI_INCLUDE_DIRS})

get_filename_component(JAVA_JVM_LIBRARY_DIR "${JAVA_JVM_LIBRARY}" PATH)
if(WIN32)
	find_file(JAVA_JVM_RUNTIME_LIBRARY jvm.dll
		HINTS
		"${JAVA_JVM_LIBRARY_DIR}/../jre/bin/client")
	if(NOT JAVA_JVM_RUNTIME_LIBRARY)
		message(FATAL_ERROR "Cannot find jvm.dll - it should have been right near your JDK's link library!")
	endif()
	install(FILES ${JAVA_JVM_RUNTIME_LIBRARY}
		DESTINATION ${BINDIR})
endif()

#add_subdirectory(submodules)
add_subdirectory(src)
