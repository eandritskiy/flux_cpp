#include <chrono>
#include <future>
#include <thread>

#include <flux_cpp.h>

#include <action/action_types.h>
#include <service/ftp_service.h>

void FtpService::onUploadFtp(std::string&& filename)
{
	future_ = std::async(std::launch::async, [] () {
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		int percentDone = 0;
		for (int i = 0; i < 10; ++i) {
			percentDone += 10;
			flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ActionType::UploadFtpProcess, percentDone));

			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ActionType::UploadFtpFinished));
	});
}
