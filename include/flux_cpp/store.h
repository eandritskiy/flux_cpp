#ifndef FLUX_CPP_STORE_H
#define FLUX_CPP_STORE_H

#include <memory>

namespace flux_cpp 
{
	class Action;

	class Store 
	{
	public:
		virtual ~Store() = default;

		virtual void process(const std::shared_ptr<Action>& action) = 0;

	protected:
		Store() = default;
		Store(const Store&) = default;
		Store(Store&&) = default;
		Store& operator=(const Store&) = default;
		Store& operator=(Store&&) = default;
	};
}

#endif
