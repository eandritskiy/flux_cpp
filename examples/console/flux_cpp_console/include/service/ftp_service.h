#ifndef CONSOLE_FTP_SERVICE_H
#define CONSOLE_FTP_SERVICE_H

#include <string>
#include <future>

class FtpService final
{
public:
	FtpService() = default;
	~FtpService() = default;

	void onUploadFtp(std::string&& filename);

private:
	FtpService(const FtpService&) = delete;
	FtpService(FtpService&&) = delete;
	FtpService& operator=(const FtpService&) = delete;
	FtpService& operator=(FtpService&&) = delete;

	std::future<void> future_;
};

#endif
