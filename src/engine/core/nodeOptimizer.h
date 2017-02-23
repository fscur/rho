#pragma once
#include <rho.h>
#include "coreApi.h"
#include "node.h"

namespace rho
{
	class nodeOptimizer
	{
	private:
		static void removeEmptyNodes(node* node);
		static node* removeUselessNodes(node* node);
		static void deleteNodes(vector<node*>& nodes);
		static bool isNodeUseless(rho::node* node);
		static bool isNodeEmpty(rho::node* node);

	public:
		CORE_API static node* optimize(node*);
	};
}
