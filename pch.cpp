#include "pch.h"
//(Measure-Command{g++ .\precompiledHeader.cpp -o precompiledHeader}).TotalMilliseconds
//g++ -x c++-header pch.h -o pch.h.gch
//The goal of use precompiled header is reduce time build but it can take more data if we include in some file we dont use some include in pch.h