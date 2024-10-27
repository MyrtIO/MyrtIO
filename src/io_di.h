#pragma once

#include "io_unit.h"

#define IO_REGISTER_INSTANCE(Type, ...) \
	Type instanceOf##Type = Type(__VA_ARGS__); \
	io::Unit* getUnitOf##Type() { return &instanceOf##Type; } \
    Type* getInstanceOf##Type() { return &instanceOf##Type; }

#define IO_PROVIDE_INSTANCE(Type) \
	io::Unit* getUnitOf##Type(); \
    Type* getInstanceOf##Type()

#define IO_REGISTER_IMPLEMENTATION(Interface, Type, ...) \
  Type implementationOf##Interface = Type(__VA_ARGS__); \
  Interface* getImplementationOf##Interface() {         \
    return &implementationOf##Interface;                \
  };                                                     \
  io::Unit* getUnitOf##Interface() {                      \
	return &implementationOf##Interface;                \
  }

// Macros to inject implementation headers
#define IO_PROVIDE_IMPLEMENTATION(Interface)                  \
  Interface* getImplementationOf##Interface(); \
  io::Unit* getUnitOf##Interface()

#define IO_INJECT(Interface) getImplementationOf##Interface()
#define IO_INJECT_UNIT(Type) getUnitOf##Type()
#define IO_INJECT_INSTANCE(Type) getInstanceOf##Type()
