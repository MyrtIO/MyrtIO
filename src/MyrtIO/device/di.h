#pragma once

#include "unit.h"

// Creates instance of Type and DI helpers
#define IO_CREATE_INSTANCE(Type, ...)                         \
	Type instanceOf##Type = Type(__VA_ARGS__);                \
	io::Unit* getUnitOf##Type() { return &instanceOf##Type; } \
    Type* getInstanceOf##Type() { return &instanceOf##Type; }

// Defines header for instance of Type and DI helpers
#define IO_DEFINE_INSTANCE(Type) \
	io::Unit* getUnitOf##Type(); \
    Type* getInstanceOf##Type()

// Creates implementation of Interface and DI helpers
#define IO_CREATE_INSTANCE_OF(Interface, Type, ...)     \
  Type implementationOf##Interface = Type(__VA_ARGS__); \
  Interface* getImplementationOf##Interface() {         \
    return &implementationOf##Interface;                \
  };                                                    \
  io::Unit* getUnitOf##Interface() {                    \
	return &implementationOf##Interface;                \
  }

// Macros to inject implementation headers
#define IO_PROVIDE_IMPLEMENTATION(Interface)   \
  Interface* getImplementationOf##Interface(); \
  io::Unit* getUnitOf##Interface()

// Injects implementation
#define IO_INJECT(Interface) getImplementationOf##Interface()

// Injects unit
#define IO_INJECT_UNIT(Type) getUnitOf##Type()

// Injects instance
#define IO_INJECT_INSTANCE(Type) getInstanceOf##Type()
