#ifndef CONSOLE_MAIN_STORE_H
#define CONSOLE_MAIN_STORE_H

#include <flux_cpp.h>

class MainStore final : public flux_cpp::Store 
{
public:
	MainStore() = default;
	MainStore(const MainStore&) = default;
	MainStore(MainStore&&) = default;
	MainStore& operator=(const MainStore&) = default;
	MainStore& operator=(MainStore&&) = default;
	~MainStore() = default;

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;
};

#endif
