#pragma once

#include <stdint.h>
#include <MyrtIO/logging/logger.h>
#include "unit.h"

#define IO_DEVICE_MAX_CONTROLLERS 16
#define IO_DEVICE_MAX_PLATFORMS 16

namespace io {
	class Device {
	public:
		Device(const char* name) :
			name_(name),
			log_(Logger(name)) {};

		Device& setup();
		Logger& log();

		void inline __attribute__((always_inline)) loop() {
			// First loop over platforms, then controllers.
			// Controller changes will be applied on next loop.
			for (int i = 0; i < platformsCount_; i++) {
				platforms_[i]->loop();
			}
			for (int i = 0; i < controllersCount_; i++) {
				controllers_[i]->loop();
			}
		}

		Device& registerPlatform(Unit* platform) {
			addUnit_(platform, &platforms_[0], &platformsCount_);
			return *this;
		}

		Device& registerController(Unit* controller) {
			addUnit_(controller, &controllers_[0], &controllersCount_);
			return *this;
		}

	private:
		const char* name_;
		uint8_t controllersCount_ = 0;
		uint8_t platformsCount_ = 0;
		Unit* controllers_[IO_DEVICE_MAX_CONTROLLERS];
		Unit* platforms_[IO_DEVICE_MAX_PLATFORMS];
		Logger log_;

		bool addUnit_(Unit* u, Unit** units, uint8_t* count);
	};

}

