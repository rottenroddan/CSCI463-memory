//
// Created by steve on 2/20/2020.
//
#include "hex.h"


std::string hex8(uint8_t i )
{
    std::ostringstream os;  // Create string stream obj.
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);  // Append 2 digit hex
                                                                                             // to os.
    return os.str();    // Return String of os.
}

std::string hex32(uint32_t i )
{
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(8) << i;   // Append 8 hex digits together.
    return os.str();    // Return String of os.
}

std::string hex0x32(uint32_t i )
{
    std::ostringstream os;
    os << "0x" << std::hex << std::setfill('0') << std::setw(8) << i;   // Append 8 hex digits with 0x... format.
    return os.str();
}