#pragma once

#include "i_message_builder.h"

namespace io {
	class ILogger {
	  public:
		virtual void print(const char* message) = 0;
		virtual void flush() = 0;

		virtual io::Logging::IMessageBuilder& build();
	};
}