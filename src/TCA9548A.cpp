/*
/////////////////////////////////////////////////////	
/////        TCA9548A Library for Arduino	    /////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	     Version 1.0.0 -2.11.2018- 		    /////
/////////////////////////////////////////////////////
*/

// include
#include "TCA9548A.h"

// constructors
TCA9548A::TCA9548A() {
    __addressTCA9548A = STD_TCA9548A_ADDRESS;
    __portTCA9548A = 255;
}

TCA9548A::TCA9548A(uint8_t address) {
    __addressTCA9548A = address;
    __portTCA9548A = 255;
}

TCA9548A::~TCA9548A() {}

// init function 
void TCA9548A::init() {
    Wire.begin(0);
}

// functions
void TCA9548A::disable() {
    __portTCA9548A = 255;

    // disable all ports
    Wire.beginTransmission(__addressTCA9548A);
    Wire.write(0);
    Wire.endTransmission();
}

void TCA9548A::setPort(uint8_t port) {
    // check if selected port is valid
    if (port > 7) return;
    __portTCA9548A = port;

    // select port
    Wire.beginTransmission(__addressTCA9548A);
    Wire.write(1 << __portTCA9548A);
    Wire.endTransmission();
}

uint8_t TCA9548A::getPort() {
    return __portTCA9548A;
}