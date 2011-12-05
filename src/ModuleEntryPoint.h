/** @file
	@brief Header

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#pragma once
#ifndef INCLUDED_ModuleEntryPoint_h_GUID_e80703e0_e3bd_43ed_8c93_6d56fc795ad0
#define INCLUDED_ModuleEntryPoint_h_GUID_e80703e0_e3bd_43ed_8c93_6d56fc795ad0

// Internal Includes
#include "LuaInterface.h"

// Library/third-party includes
// - none

// Standard includes
// - none

LUAVOCE_BEGIN_LUA_INTERFACE

struct lua_State;
int LUAVOCE_API luaopen_luavoce(lua_State *L);

LUAVOCE_END_LUA_INTERFACE

#endif // INCLUDED_ModuleEntryPoint_h_GUID_e80703e0_e3bd_43ed_8c93_6d56fc795ad0
