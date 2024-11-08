#pragma once

#include <Print.h>
#include "i_logger.h"

namespace io {
	class Logger : public io::ILogger {
	  public:
		Logger(const char* moduleName = nullptr) : moduleName_(moduleName) {}

		void print(const char* message) override;
		void flush() override;
		io::Logging::IMessageBuilder& build() override;

		static void setOutput(Print* stream);

	  private:
		const char* moduleName_ = nullptr;

		void appendPrefix_();
	};
}


