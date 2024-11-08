#include "message_builder.h"
#include <stdlib.h>
#include <string.h>

io::Logging::MessageBuilder& io::Logging::MessageBuilder::append(
    const char* message
) {
	for (int i = 0; i < strlen(message); i++) {
		buffer_[size_] = message[i];
		size_++;
	}
	return *this;
}

io::Logging::MessageBuilder& io::Logging::MessageBuilder::append(
    const char symbol
) {
	buffer_[size_] = symbol;
	size_++;
    return *this;
}

io::Logging::MessageBuilder& io::Logging::MessageBuilder::append(
    const uint8_t message
) {
	char buffer[4];
	itoa(message, buffer, 10);
	return append(buffer);
}

io::Logging::MessageBuilder& io::Logging::MessageBuilder::append(
    const uint16_t message
) {
	char buffer[10];
	itoa(message, buffer, 10);
	return append(buffer);
}

io::Logging::MessageBuilder& io::Logging::MessageBuilder::append(
    const uint32_t message
) {
	char buffer[10];
	itoa(message, buffer, 10);
	return append(buffer);
}

io::Logging::MessageBuilder& io::Logging::MessageBuilder::clear() {
	if (size_ == 0) {
		return *this;
	}
	for (int i = 0; i < size_; i++) {
		buffer_[i] = 0;
	}
	size_ = 0;
    return *this;
}

