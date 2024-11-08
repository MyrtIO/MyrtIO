#include "lps.h"
#include <MyrtIO/logging/logger.h>

constexpr char* kLPSBenchmarkName = "LPSBenchmark";
constexpr uint32_t kLPSBenchmarkInterval = 1000;

io::Logger benchmarkLogger(kLPSBenchmarkName);

const char* io::LPSBenchmark::getName() {
	return kLPSBenchmarkName;
}

void io::LPSBenchmark::setup() {
	nextCheck_.start(kLPSBenchmarkInterval);
}

void io::LPSBenchmark::loop() {
	if (!nextCheck_.finished()) {
		loopsCount_++;
		return;
	}
	benchmarkLogger.build()
	    .append(loopsCount_)
	    .append("")
	    .append(" lps, ")
	    .append(kLPSBenchmarkInterval / loopsCount_)
	    .append(" ms");
	benchmarkLogger.flush();
	loopsCount_ = 0;
	nextCheck_.start(kLPSBenchmarkInterval);
}
