/**
 * @file TCA9548A.cpp
 * @brief The source file of the Arduino library for the I²C Multiplexer TCA9548A.
 * @author Jonas Merkle [JJM]
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.1
 * @date 02 December 2018
 * @copyright This project is released under the GNU General Public License v3.0
 */

/**
 * @mainpage Arduino library for the I²C Multiplexer TCA9548A
 *
 * @section intro_sec Introduction
 *
 *
 * @section dependencies Dependencies
 *
 * This library depends on the <a href="https://www.arduino.cc/en/Reference/Wire">
 * Wire Library</a> being present on your system. Please make sure you have
 * installed the latest version before using this library.
 *
 * @section author Author
 *
 * Written by Jonas Merkle [JJM]
 * 
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 *
 * @section license License
 *
 * This project is released under the GNU General Public License v3.0
 * 
*/

/////////////
// include //
/////////////
#include "TCA9548A.h"

//////////////////
// constructors //
//////////////////

TCA9548A::TCA9548A() {
    __addressTCA9548A = STD_TCA9548A_ADDRESS;
    __portTCA9548A = 255;
}

TCA9548A::TCA9548A(uint8_t address) {
    __addressTCA9548A = address;
    __portTCA9548A = 255;
}

TCA9548A::~TCA9548A() {
    ;
}

///////////////////
// init function //
///////////////////
void TCA9548A::init() {
    Wire.begin(0);
}

///////////////
// functions //
///////////////

void TCA9548A::disable() {
    __portTCA9548A = 255;

    // disable all ports
    Wire.beginTransmission(__addressTCA9548A);
    Wire.write(0);
    Wire.endTransmission();
}

void TCA9548A::set_port(uint8_t port) {
    // check if selected port is valid
    if (port > 7) return;
    __portTCA9548A = port;

    // select port
    Wire.beginTransmission(__addressTCA9548A);
    Wire.write(1 << __portTCA9548A);
    Wire.endTransmission();
}

uint8_t TCA9548A::get_port() {
    return __portTCA9548A;
}

uint16_t TCA9548A::get_version() {
    return _lib_version;
}