#include "hex.h"
#include "memory.h"
#include <iostream>
#include <sstream>
#include <string>

// The use of this function is provide a simple error message to stdout.
void usage(std::ostringstream *err)
{
    std::cout << "Error: " << err->str() << std::endl;
}

int  main(int argc , char **argv)
{

    setbuf(stdout, 0);  // For debugging uses on CLION

    if (argc != 3)
    {
        std::ostringstream os;
        os << "Expected 3 Args, got: " << argc;
        usage(&os);
    }

    memory mem(std::stoul(argv[1], 0, 16)); // Create memory object with second arg as size const.
    mem.dump(); // Dump contents.
    std::cout << std::endl; // Add new extra new line.

    // Load File.
    if (!mem.load_file(argv [2]))
    {
        std::ostringstream os;
        os << "File: " << argv[2] << " could not be opened! ";
        usage(&os); // Return
    }
    mem.dump(); // Dump memory contents.

    std::cout  << mem.get_size () << std::endl;                 // Print size of memory block.
    std::cout  << hex32(mem.get8 (0))  << std::endl;    // Print hex32 val of address 0.
    std::cout  << hex32(mem.get16 (0))  << std::endl;   // Print hex32 val of address 0-1.
    std::cout  << hex32(mem.get32 (0))  << std::endl;   // Print hex32 val of address 0-3.
    std::cout  << hex0x32(mem.get8 (0))  << std::endl;  // Print hex32 0x of address of 0.
    std::cout  << hex0x32(mem.get16 (0))  << std::endl; // Print hex32 0x of address of 0-1.
    std::cout  << hex0x32(mem.get32 (0))  << std::endl; // Print hex32 0x of address of 0-3.
    std::cout  << hex8(mem.get8 (0))  << std::endl;     // Print hex8 val of 8 bit addr 0.
    std::cout  << hex8(mem.get16 (0))  << std::endl;    // Print hex8 val of 16 bit addr 0. The resultant value
                                                                // will be bigger than hex8 can  handle, thus the 8 bits
                                                                // will be ignored on the left.
    std::cout  << hex8(mem.get32 (0))  << std::endl;    // Same as above but with 32 bits.

    std::cout  << hex0x32(mem.get32 (0x1000 )) << std::endl;    // Print 0x form of address 0x1000.

    // Set the belows addresses to the val.
    mem.set8(0x10 , 0x12);
    mem.set16(0x14 , 0x1234);
    mem.set32(0x18 , 0x87654321 );

    std::cout << std::endl;
    mem.dump(); // Dump contents.
    return 0;
}
