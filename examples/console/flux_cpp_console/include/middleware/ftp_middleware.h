#ifndef CONSOLE_FTP_MIDDLEWARE_H
#define CONSOLE_FTP_MIDDLEWARE_H

#include <memory>

#include <flux_cpp.h>

#include <action/action_types.h>

class FtpMiddleware final : public flux_cpp::Middleware
{
public:
	FtpMiddleware();
	~FtpMiddleware();

	std::shared_ptr<flux_cpp::Action> process(const std::shared_ptr<flux_cpp::Action>& action) override;

private:
	FtpMiddleware(const FtpMiddleware&) = delete;
	FtpMiddleware(FtpMiddleware&&) = delete;
	FtpMiddleware& operator=(const FtpMiddleware&) = delete;
	FtpMiddleware& operator=(FtpMiddleware&&) = delete;

	class FtpMiddlewareImpl;
	std::unique_ptr<FtpMiddlewareImpl> impl_;
};

#endif
