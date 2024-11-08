#include <Arduino.h>
#include "logger.h"
#include "message_builder.h"

io::Logging::MessageBuilder ioMessageBuilder;

Print* ioLogOutput = &Serial;

using namespace io;

void io::Logger::print(const char* message) {
	build().append(message);
	flush();
}

void io::Logger::flush() { 
	if (ioMessageBuilder.size() > 0) {
		ioMessageBuilder.append("\n");
		ioLogOutput->write(ioMessageBuilder.buffer(), ioMessageBuilder.size());
		ioLogOutput->flush();
	}
}

io::Logging::IMessageBuilder& io::Logger::build() {
	ioMessageBuilder.clear();
	appendPrefix_();
	return ioMessageBuilder;
}

void io::Logger::appendPrefix_() {
	char buffer[12];
	for (int i = 0; i < 12; i++) {
		buffer[i] = ' ';
	}
	auto now = millis();
	char prefixBuffer[10];
    // TODO: optimize timestamp printing
	uint32_t seconds = now / 1000;
	uint32_t minutes = seconds / 60;
	seconds = seconds % 60;
	uint32_t hours = minutes / 60;
	minutes = minutes % 60;
	sprintf(prefixBuffer, "%02d:%02d:%02d", hours, minutes, seconds);
	ioMessageBuilder
        .append(prefixBuffer)
		.append(" ");
	if (moduleName_ != nullptr) {
		ioMessageBuilder
			.append("[")
			.append(moduleName_)
			.append("] ");
	}
}

void io::Logger::setOutput(Print* stream) {
	ioLogOutput = stream;
}

