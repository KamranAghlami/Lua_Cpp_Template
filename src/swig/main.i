%module(directors="1") lua_wrapper
%feature("director");

%{
#include "Object.h"
%}

%include <std_string.i>

%include "Object.h"
