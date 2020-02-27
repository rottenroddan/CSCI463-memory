//
// Created by steve on 2/20/2020.
//

#ifndef MEMORY_MEMORY_H
#define MEMORY_MEMORY_H

#include "hex.h"

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>

class memory
{
public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        memory(uint32_t size)                               *
     * @params:         @size - unsigned 32 bit integer of the size alloc.  *
     *                                                                      *
     * Desc:            The purpose of this constructor is to dynamically   *
     *                  allocate space in the mem array. The values then    *
     *                  will be default changed to value of 0xa5. Memory    *
     *                  will be allocated in multiples of 16.               *
     *                                                                      *
     * @returns:        -none-                                              *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    memory(uint32_t size);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        ~memory()                                           *
     * @params:         -none-                                              *
     *                                                                      *
     * Desc:            Default destructor. Delete the memory block.        *
     *                                                                      *
     * @returns:        -none-                                              *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    ~memory();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        check_address(uint32_t i)                           *
     * @params:         @i - address to check.                              *
     *                                                                      *
     * Desc:            The purpose of this function is to return a bool on *
     *                  whether or not the address given is valid. We       *
     *                  compare i to the size variable.                     *
     *                                                                      *
     * @returns:        @bool - true if address is valid. Otherwise false.  *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    bool check_address(uint32_t i)  const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        get_size()                                          *
     * @params:         -none-                                              *
     *                                                                      *
     * Desc:            Returns the size private variable.                  *
     *                                                                      *
     * @returns:        @size - size of the memory allocated.               *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    uint32_t  get_size()            const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        get8(uint32_t addr)                                 *
     * @params:         @addr - Address value.                              *
     *                                                                      *
     * Desc:            Returns the 8 bits in a uint8 variable.             *
     *                                                                      *
     * @returns:        @r - The value of the 8 bits in uint8 vars.         *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    uint8_t get8(uint32_t addr)     const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        get16(uint16_t addr)                                *
     * @params:         @addr - Address value.                              *
     *                                                                      *
     * Desc:            Returns the 16 bits in the address of mem.          *
     *                  multiplies 2nd btye by 0x0100 and addrs to r.       *
     *                                                                      *
     * @returns:            @r - the 16 bits in the form uint16 var.        *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    uint16_t get16(uint16_t addr)   const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        get32(uint32_t addr)                                *
     * @params:         @addr - Address value.                              *
     *                                                                      *
     * Desc:            Returns the 32 bits in the address of mem           *
     *                  multiplies the 2nd byte by 0x0100, 3rd byte by      *
     *                  0x010000 and 4th by 0x01000000.                     *
     *                                                                      *
     * @returns:         @r - The 32 bits in uint32 var.                    *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    uint32_t get32(uint32_t addr)   const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        set8(uint32_t addr, uint8_t val)                    *
     * @params:         @addr - Address we set.                             *
     *                  @val  - Value we set at that address.               *
     *                                                                      *
     * Desc:            Sets the value at the current address provided      *
     *                                                                      *
     * @returns:        -none-                                              *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void set8(uint32_t addr, uint8_t val);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        set16(uint32_t addr, uint16_t val)                  *
     * @params:         @addr - Address.                                    *
     *                  @val  - Value to set the address.                   *
     *                                                                      *
     * Desc:            Sets the 16 bits of the current address. Relies     *
     *                  on using set8 function to set the 2 bytes this fn   *
     *                  has already.                                        *
     *                                                                      *
     * @returns:        -none-                                              *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void set16(uint32_t addr, uint16_t val);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        set32(uint32_t addr, uint32_t val)                  *
     * @params:         @addr - Address.                                    *
     *                  @val  - Val to set.                                 *
     *                                                                      *
     * Desc:            Sets the 32 bits of the current address. Relies on  *
     *                  using set16 function to set the addresses properly. *
     *                  Also uses bit shifters, to only send the LSB16 to   *
     *                  the first address of set16 and MSB16 to set16.      *
     *                                                                      *
     * @returns:        -none-                                              *e
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void set32(uint32_t addr, uint32_t val);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        dump()                                              *
     * @params:         -none-                                              *
     *                                                                      *
     * Desc:            Dumps the contents of the entire memory block.      *
     *                  Prints '.' if the char is non-visible. Otherwise    *
     *                  pritns the char corresponding to the 2 digit hex    *
     *                  value of byte.                                      *
     *                                                                      *
     * @returns:        -none-                                              *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void dump() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function:        laod_file(string &fname)                            *
     * @params:         @fname - Reference to the string of file name.      *
     *                                                                      *
     * Desc:            The purpose of this function is to populate the     *
     *                  the memory block with the contents of the file.     *
     *                  It loops until one of two things. Whether the last  *
     *                  address has been reached in the memory block of the *
     *                  End of File has been reached.                       *
     *                                                                      *
     * @returns:        @bool - True if file has been read, false O/w      *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    bool load_file(const std::string &fname);

private:
    uint8_t *mem;   // Memory block.
    uint32_t size;  // Size of block.
};

#endif //MEMORY_MEMORY_H
