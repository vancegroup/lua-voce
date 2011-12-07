include_directories(${LUABIND_INCLUDE_DIRS} ${VOCE_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
add_definitions(-DLUAVOCE_BUILDING)

set(SOURCES
	LuaInclude.h
	LuaInterface.h
	ModuleEntryPoint.cpp
	ModuleEntryPoint.h)


add_library(luavoce MODULE ${SOURCES})
set_property(TARGET luavoce PROPERTY PREFIX "")
target_link_libraries(luavoce ${LUABIND_LIBRARIES} ${JNI_LIBRARIES})

#if(BUILD_TESTING)
	# if(NOT LUA_COMMAND)
		# message(FATAL_ERROR "Can't test without LUA_COMMAND set - either set it or disable BUILD_TESTING!")
	# endif()
	# add_subdirectory(test)
# endif()

install(TARGETS luavoce
	RUNTIME DESTINATION bin COMPONENT binding
	LIBRARY DESTINATION bin COMPONENT binding)

set(LUAVOCE_INSTALL_NAME "${CMAKE_INSTALL_PREFIX}/bin/luavoce${CMAKE_SHARED_MODULE_SUFFIX}")

set(APP)
set(PLUGINS)
set(LIBRARY_DIRS)

if(LUA_COMMAND)
	install(PROGRAMS "${LUA_COMMAND}" DESTINATION bin)
	get_filename_component(LUA_COMMAND_FILENAME "${LUA_COMMAND}" NAME)
	set(APP "${CMAKE_INSTALL_PREFIX}/bin/${LUA_COMMAND_FILENAME}")
	list(APPEND PLUGINS "${LUAHAPI_INSTALL_NAME}")
else()
	set(APP "${LUAHAPI_INSTALL_NAME}")
endif()

get_filename_component(LUA_LIBDIR "${LUA_LIBRARY}" PATH)
list(APPEND LIBRARY_DIRS "${LUA_LIBDIR}")

install(CODE "
  include(BundleUtilities)
  fixup_bundle(\"${APP}\" \"${PLUGINS}\" \"${LIBRARY_DIRS}\")
  ")
