#ifndef FLUX_CPP_MIDDLEWARE_H
#define FLUX_CPP_MIDDLEWARE_H

#include <memory>

namespace flux_cpp
{
	class Action;

	class Middleware
	{
	public:
		virtual ~Middleware() = default;

		virtual std::shared_ptr<Action> process(const std::shared_ptr<Action>& action) = 0;

	protected:
		Middleware() = default;
		Middleware(const Middleware&) = default;
		Middleware(Middleware&&) = default;
		Middleware& operator=(const Middleware&) = default;
		Middleware& operator=(Middleware&&) = default;
	};
}

#endif
