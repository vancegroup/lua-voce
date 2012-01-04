# CMake cross-platform build system
# 2009-2010 Ryan Pavlik <rpavlik@iastate.edu>
# http://academic.cleardefinition.com/
# Iowa State University HCI Graduate Program/VRAC

include(LuaTargets)

set(LUA_FILES
	init.lua)


add_lua_target(luaFiles "${CMAKE_BINARY_DIR}/share/lua-voce/lua/" ${LUA_FILES})
add_dependencies(luaFiles luaFiles-Manipulators)

set_property(TARGET
		luaFiles
		PROPERTY
		PROJECT_LABEL
		"lua-voce")

# Install into the install location, as well
#install_lua_target(luaFiles
#	DESTINATION
#	${LUA_DIR})
