//
// Created by steve on 2/23/2020.
//
#include "memory.h"

bool memory::check_address(uint32_t i) const
{
    // Check if the provided address falls in the limits.
    if(i < this->get_size())
    {
        return true;    // Return true.
    }
    else
    {
        std::cout << "WARNING: Address  out of  range: " <<  hex0x32(i) << std::endl; // Print Warning message.
        return false;
    }

}


void memory::dump() const
{
    std::ostringstream temp;    // temp Ostring Stream obj. for creating the char line in dump
    for(uint32_t i = 0; i < this->get_size(); i++ )
    {
        // Clear 'temp' buffer if its beyond the last char.
        if( i % 16 == 0)
        {
            temp.str("");   // Clear the string.
            temp.clear();      // Clear flags.
        }

        temp <<  (isprint(this->get8(i)) ? (char)this->mem[i] : '.' );  // Append the char to temp if readable. Else
                                                                        // append '.' for unreadable char value.

        //std::cout << "I: " << i << " Mod 16: " << i%16 << std::endl;
        std::cout << ( ( (i % 16) == 0) ? ((i != 0 ) ?"\n": "") + hex32(i) + ":  " + hex8(this->get8(i)) : ( i % 16 == 8 ? "   " + hex8(this->get8(i)) : " " + hex8(this->get8(i) ) ) )
                  << ( ( (i % 16 == 15) || (i == 15) ) ?  "  *" + temp.str() + "*" : "");

    }
    std::cout << std::endl;
}


uint32_t memory::get_size() const
{
    return this->size;  // Return Size value.
}


uint8_t memory::get8(uint32_t addr) const
{
    if(check_address(addr))
    {
        return mem[addr];   // Return value at addr.
    }
    else
    {
        return 0;
    }
}


uint16_t memory::get16(uint16_t addr) const
{
    uint16_t r = 0;
    // First Byte.
    if(check_address(addr))
    {
        r += mem[addr];
    }

    // Second byte
    if(check_address(addr+1))
    {
        r += mem[addr + 1]*0x0100; // Add equals the multiplication of 0x0100 for the second byte to unalter first.
    }
    return r;   // Return r back.
}


uint32_t memory::get32(uint32_t addr) const
{
    uint32_t r = 0; // Create return value for modification.
    if(check_address(addr))
    {
        r += mem[addr]; // Add first byte to r.
    }

    if(check_address(addr+1))
    {
        r += mem[addr+1]*0x00000100;    // Add Second byte to r by multiplying by 0x0100 so you don't alter first.
    }

    if(check_address(addr+2))
    {
        r += mem[addr+2]*0x00010000;    // Add Third byte to r by mult. by 0x010000 so you don't alter.
    }

    if(check_address(addr+3))
    {
        r += mem[addr + 3] * 0x01000000;    // Add Fourth byte to r by mult. by 0x01000000 so you dont alter.
    }
    return r;   // Return r.
}


bool memory::load_file(const std::string &fname)
{
    std::string line;           // For getline use.
    std::string fileContents;   // Filecontents, for looping through.
    std::ostringstream os;      // Ostringstream obj for appending chars to one another.

    char* memblock;
    uint32_t fSize;

    std::ifstream inFile(fname, std::ios::in | std::ios::binary| std::ios::ate);   // Open file as input and binary file.

    // As long as file opens.
    if(inFile.is_open()) {
        fSize = inFile.tellg();     // Find File Size.
        memblock = new char[fSize]; // Allocate Memory block for the file.
        inFile.seekg(0, std::ios::beg); // Sets beginning char
        inFile.read(memblock,size) ; // Reads the contents and copies it into memblock.
        inFile.close(); // Close file.
    }
    else
    {
        inFile.close();
        return false;   // Return false for not being able to open file.
    }

    fileContents = os.str();    // Filecontents copies os contents now.

    // Loop through each char and convert to
    for(uint32_t i = 0; i < fSize && i < this->get_size(); i++)
    {
        this->set8(i, static_cast<uint8_t>(memblock[i]));
    }
    // Close file as we don't need it anymore.
    return true;    // Return true.
}


memory::memory(uint32_t size)
{
    this->size = (size+15) &0xfffffff0;     // Rounder function. Therefore the bounds are always mod 16 zero.
    this->mem = new uint8_t[this->size];    // Allocate memory.

    // Loop to set all values to 0xa5 right away.
    for(uint32_t i = 0; i < this->size; i++)
    {
        mem[i] = 0xa5;
    }
}


memory::~memory()
{
    delete []mem;
}


void memory::set8(uint32_t addr, uint8_t val)
{
    if(check_address(addr))
    {
        mem[addr] = val;    // Set the addr in mem array to the provided hex value.
    }
}


void memory::set16(uint32_t addr, uint16_t val)
{
    uint16_t shifter;   // Hex Value to shift.

    shifter = (val << 8) >> 8;  // Shift to delete first 8 bits, shift to right for the first 2 digits.
    set8(addr, static_cast<uint8_t>(shifter));  // Set8 the right 8 bits.

    shifter = (val >> 8);       // Shift to delete right 8 bits, leaving left 8 bits where they lie now.
    set8(addr+1, static_cast<uint8_t>(shifter));    // Set8 the left 8 bits.
}


void memory::set32(uint32_t addr, uint32_t val)
{
    uint32_t shifter;   // Hex val to shift.

    shifter = (val << 16) >> 16;    // Shift to the left 16 bits to erase those bits, and shift right back for R. 16.
    set16(addr, static_cast<uint16_t>(shifter) );   // set16 the 16bits on the right now.

    shifter = (val >> 16);          // Shift to the right 16 bits to erase those bits.
    set16(addr+2, static_cast<uint16_t>(shifter));  // set16 addr+2 for +2 bytes, the left bytes now.
}