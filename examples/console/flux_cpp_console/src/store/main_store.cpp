#include <iostream>

#include <action/action_types.h>
#include <store/main_store.h>

void MainStore::process(const std::shared_ptr<flux_cpp::Action>& action)
{
	switch (action->getType<ActionType>()) {

	case ActionType::UploadFtpStarted:
		std::cout << "Start uploading " << action->getPayload<std::string>().c_str() << std::endl;
		break;

	case ActionType::UploadFtpProcess:
		std::cout << "Uploaded " << action->getPayload<int>() << "%" << std::endl;
		break;

	case ActionType::UploadFtpFinished:
		std::cout << "File uploaded successfully" << std::endl;
		break;
	}
}
