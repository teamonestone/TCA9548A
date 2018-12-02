/**
 * \file bot.h
 * \brief The header file of the Arduino library for the I²C Multiplexer TCA9548A.
 * \author Jonas Merkle [JJM]
 * \version 1.0.1
 * \date 02 December 2018
 * \license This project is released under the GNU General Public License v3.0
 */

#ifndef TCA9548A_h
#define TCA9548A_h

// includes
#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>

// defines
#define STD_TCA9548A_ADDRESS 0x70

/**
 * \class TCA9548A
 * \brief The main class of the Arduino library for the I²C Multiplexer TCA9548A.
 */
class TCA9548A {
// Begin PUBLIC ------------------------------------------------------------------
    public:

        // constructors
        TCA9548A();
        TCA9548A(uint8_t address);
        ~TCA9548A();

        // init function
        void init();

        // functions
        void disable();
        void set_port(uint8_t port);
        uint8_t get_port();
        uint16_t get_version();

// End PUBLIC --------------------------------------------------------------------

// Begin PRIVATE -----------------------------------------------------------------        
    private:

        // variables
        uint16_t const _lib_version = 101;

        uint8_t __addressTCA9548A;
        uint8_t __portTCA9548A;

// End PRIVATE -------------------------------------------------------------------
};

#endif