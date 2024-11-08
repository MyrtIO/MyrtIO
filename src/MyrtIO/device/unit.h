#pragma once

namespace io {
    // Unit is a base class for all units (controllers, platforms).
	class Unit {
	  public:
        virtual ~Unit() = default;

		virtual const char* getName() = 0;

        // Setup and initialize the unit. Called once on unit setup.
		virtual void setup() {};

        // Main loop of the unit. Called every app loop.
		virtual void loop() = 0;
	};
}
