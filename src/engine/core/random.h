#pragma once
#include <rho.h>
#include "coreApi.h"

namespace rho
{
	class random
	{	
	private:
		static random _global;
		random();

	public:
		CORE_API static float next();
		CORE_API static float next(float min, float max);
	};
}