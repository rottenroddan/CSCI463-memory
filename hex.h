//
// Created by steve on 2/20/2020.
//

#ifndef MEMORY_HEX_H
#define MEMORY_HEX_H

#include <iomanip>  // Formatting for sstream obj.
#include <sstream>  // Handling formatting strings.
#include <string>
#include <string.h>


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function:        hex8(uint8_t i)                                     *
 * @params:         @i - Value we return as a 2 digit hex string.       *
 *                                                                      *
 * Desc:            The pupose of this function is to create a 2 digit  *
 *                  hex string from the provided parameter and format   *
 *                  it.                                                 *
 *                                                                      *
 * @returns:        @string - formatted 2 digit hex string.             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
std::string hex8(uint8_t i);


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function:        hex32(uint32_t i)                                   *
 * @params:         @i - 32 Unsigned int value that gets conv. to hex   *
 *                                                                      *
 * Desc:            The purpose of this function is to return a string  *
 *                  that is formatted for 8 hex digits.                 *
 *                                                                      *
 * @returns:        @string - formatted 8 digit hex string.             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
std::string hex32(uint32_t i);


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: hex0x32(uint32_t i)                                        *
 * @params:         @i - 32 Unsigned int vlaue that is conv. to hex     *
 *                                                                      *
 * Desc:            The purpose of this function is to return a string  *
 *                  that is formatted for 8 hex digits with a leading   *
 *                  '0x....' to represent a hex value.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 std::string hex0x32(uint32_t i);

#endif //MEMORY_HEX_H
