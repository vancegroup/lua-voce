/**
	@file
	@brief Implementation

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


// Internal Includes
#include "ModuleEntryPoint.h"
#include "voce.h"

// Library/third-party includes
#include <luabind/luabind.hpp>

// Standard includes
// - none

int luaopen_luavoce(lua_State *L) {
	using namespace luabind;
	open(L);
	module(L, "voce")
	[
	    def("init", &voce::init)
	    ,
	    def("destroy", &voce::destroy)
	    ,
	    def("synthesize", &voce::synthesize)
	    ,
	    def("isSynthesizing", &voce::isSynthesizing)
	    ,
	    def("stopSynthesizing", &voce::stopSynthesizing)
	    ,
	    def("getRecognizerQueueSize", &voce::getRecognizerQueueSize)
	    ,
	    def("popRecognizedString", &voce::popRecognizedString)
	    ,
	    def("setRecognizerEnabled", &voce::setRecognizerEnabled)
	    ,
	    def("isRecognizerEnabled", &voce::isRecognizerEnabled)
	    ,
	    scope() // trailing empty scope so we can put commas after each binding call
	];
	return 0;
}
