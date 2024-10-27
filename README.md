# MyrtIO

A framework for easy building of IoT devices.

## Concept

MyrtIO is designed to speed up the creation of firmware for new home devices. Existing frameworks seemed either too complicated or took away the ability to write code.

The result is as follows: There is some `io::Device`, which consists of controllers and platforms (units). The platform is an interface to the hardware capabilities of the device (backlight, buttons, WiFi, etc).

Units implement the `io::Unit` interface:

```cpp
class Unit {
  public:
    virtual const char* name() = 0;
    virtual void setup() = 0;
    virtual void loop() = 0;
};
```

The `io::Device` is responsible for setting up and running the units.
