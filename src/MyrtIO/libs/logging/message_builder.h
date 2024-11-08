#pragma once

#include "i_message_builder.h"

#ifndef IO_LOGGER_BUFFER_SIZE
	#define IO_LOGGER_BUFFER_SIZE 256
#endif

namespace io {
    namespace Logging {
        class MessageBuilder : public IMessageBuilder {
        public:
            MessageBuilder& append(const char* message) override;
            MessageBuilder& append(const char symbol) override;
            MessageBuilder& append(const uint8_t message) override;
            MessageBuilder& append(const uint16_t message) override;
            MessageBuilder& append(const uint32_t message) override;
            MessageBuilder& clear() override;

            uint16_t size() override {
                return size_;
            }

            char* buffer() override {
                return buffer_;
            }

        private:
            char buffer_[IO_LOGGER_BUFFER_SIZE];
            uint16_t size_ = 0;
            uint16_t offset_ = 0;
        };
    }    
}

