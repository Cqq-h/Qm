#pragma once
#include <iostream>
#ifdef EXPEREMENTALLIBS
	#define STDFUCLIB Qm
	#include "EXPEREMENTALLIBS/smath.h"
#else
	#define STDFUCLIB std
	#define _USE_MATH_DEFINES
	#include <cmath>
#endif // DEBUG
namespace Qm
{
#define PI 3.14159265359
}