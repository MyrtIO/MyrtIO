#pragma once

#include <stdint.h>

namespace io {
    namespace Logging {
        class IMessageBuilder {
        public:
            virtual IMessageBuilder& append(const char* message);
            virtual IMessageBuilder& append(const char symbol);
            virtual IMessageBuilder& append(const uint8_t message);
            virtual IMessageBuilder& append(const uint16_t message);
            virtual IMessageBuilder& append(const uint32_t message);
            virtual IMessageBuilder& clear();

            virtual uint16_t size();
            virtual char* buffer();
        };
    }    
}