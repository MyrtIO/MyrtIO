#include "device.h"
#include <MyrtIO/logging/logger.h>

#ifdef IO_LPS_BENCHMARK
	#include <MyrtIO/benchmarking/lps.h>
	#warning "Benchmarking enabled"
	io::LPSBenchmark ioLPSBenchmark;
#endif

io::Device& io::Device::setup() {
	log_.print("initializing...");
#if IO_LPS_BENCHMARK
	this->registerController(&ioLPSBenchmark);
#endif
	return *this;
}

io::Logger& io::Device::log() {
	return log_;
}

bool io::Device::addUnit_(io::Unit* u, io::Unit** units, uint8_t* count) {
	log_.build()
	    .append("adding unit: ")
	    .append(u->getName());
	log_.flush();
	if (*count >= IO_DEVICE_MAX_CONTROLLERS) {
		log_.print("too many units of this type");
		return false;
	}
	log_.print("setup unit...");
	u->setup();
	units[*count] = u;
	*count = *count + 1;
	log_.print("unit successfully added");
	return true;
}
