#include <string>

#include <action/action_types.h>
#include <middleware/ftp_middleware.h>
#include <service/ftp_service.h>

class FtpMiddleware::FtpMiddlewareImpl final
{
public:
	FtpMiddlewareImpl()
		: service_(new FtpService)
	{
	}

	FtpMiddlewareImpl(const FtpMiddlewareImpl&) = delete;
	FtpMiddlewareImpl(FtpMiddlewareImpl&&) = delete;
	FtpMiddlewareImpl& operator=(const FtpMiddlewareImpl&) = delete;
	FtpMiddlewareImpl& operator=(FtpMiddlewareImpl&&) = delete;
	~FtpMiddlewareImpl() = default;

	std::unique_ptr<FtpService> service_;
};

FtpMiddleware::FtpMiddleware()
	: impl_(new FtpMiddlewareImpl)
{
}

FtpMiddleware::~FtpMiddleware()
{
}

std::shared_ptr<flux_cpp::Action> FtpMiddleware::process(const std::shared_ptr<flux_cpp::Action>& action)
{
	switch (action->getType<ActionType>()) {

	case ActionType::UploadFtp:
		impl_->service_->onUploadFtp(action->getPayload<std::string>());
		return std::make_shared<flux_cpp::Action>(ActionType::UploadFtpStarted, action->getPayload<std::string>());
	}

	return action;
}
