/*
/////////////////////////////////////////////////////	
/////        TCA9548A Library for Arduino	    /////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	     Version 1.0.0 -2.11.2018- 		    /////
/////////////////////////////////////////////////////
*/

#ifndef TCA9548A_h
#define TCA9548A_h

// includes
#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>

// defines
#define STD_TCA9548A_ADDRESS 0x70

////////////////////
// TCA9548A class //
////////////////////
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

        // util functions
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