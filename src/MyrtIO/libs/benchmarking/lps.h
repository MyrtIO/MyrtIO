#pragma once

#include <MyrtIO/libs/device/unit.h>
#include <Attotime.h>

namespace io {
    // LPSBenchmark is a benchmarking controller that counts
    // the number of loops per second (greater is better). It will print the
    // number of loops and average loop time (smaller is better) to log every second.
	class LPSBenchmark : public Unit {
	public:
		const char* getName() override;
		void setup() override;
		void loop() override;

	private:
		Timer nextCheck_;
		uint32_t loopsCount_ = 0;
	};
}
