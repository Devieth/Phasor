/*! \file memory.h
 * \brief Memory related functions for scripts.
 *
 *	As of 01.00.10.059 all read/write functions have been overloaded
 *	to optionally remove the need for the address offset. For such cases
 *	you shouldn't include address_offset and the address used will be
 *	exactly what's specified and not (base_address + address_offset) as
 *	in previous versions.
 *	
 *	For example, the below are equivalent
 *	\code
 *		readbyte(12345, 5) 
 *		readbyte(12350)
 *	\endcode
 *	
 *	### DEFINITIONS
 *		- \c byte - 8 bit positive integer from [0,255] 	
 *		- \c char - 8 bit integer from [-128, 127]	
 *		- \c word - 16 bit positive integer from [0,65,535]	
 *		- \c short - 16 bit integer from [-32768, 32767]	
 *		- \c dword - 32 bit positive integer from [0, 4,294,967,295]	
 *		- \c int - 32 bit integer from [-2147483648, 2147483647]	
 *		- \c float - 32 bit floating point number from [-3.402823466e+38, 3.402823466e+38]	
 *		- \c double - 64 bit floating point number from[-1.7976931348623158e+308, 1.7976931348623158e+308]
 *		
 * \remark
 * All string operations are limited to 80 characters at max.
 * 
 *	\addtogroup PhasorAPI
 *	@{
*/
#include "../Common/Common.h"
#include "PhasorAPI.h"
#include <list> 


/*! \brief Reads a bit from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param bit_offset Which bit to read (starting at 0)
 *  \return The specified bit (ie 1 or 0)
 * 
 * 	Example usage:
 *  \code
 *		local b = readbit(0x12345678, 3, 2) -- read the 3rd bit at 0x12345678 + 3
 *		local b = readbit(0x12345678, 2) -- read the 3rd bit at 0x12345678
 *  \endcode
 */
void l_readbit(PHASOR_API_ARGS);

/*! \brief Reads a byte from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The byte read.
 *	
 *	Example usage:
 *  \code
 *		local b = readbyte(0x12345678, 3) -- read the byte at 0x12345678 + 3
 *		local b = readbyte(0x12345678) -- read the byte at 0x12345678
 *  \endcode
 */
void l_readbyte(PHASOR_API_ARGS);

/*! \brief Reads a char from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The char read.
 *	
 *	Example usage:
 *  \code
 *		local b = readchar(0x12345678, 3) -- read the char at 0x12345678 + 3
 *		local b = readchar(0x12345678) -- read the char at 0x12345678
 *  \endcode
 */
void l_readchar(PHASOR_API_ARGS);

/*! \brief Reads a word from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The word read
 *	
 *	Example usage:
 *  \code
 *		local b = readword(0x12345678, 3) -- read the word at 0x12345678 + 3
 *		local b = readword(0x12345678) -- read the word at 0x12345678
 *  \endcode
 */
void l_readword(PHASOR_API_ARGS);

/*! \brief Reads a short from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The short read
 *	
 *	Example usage:
 *  \code
 *		local b = readshort(0x12345678, 3) -- read the short at 0x12345678 + 3
 *		local b = readshort(0x12345678) -- read the short at 0x12345678
 *  \endcode
 */
void l_readshort(PHASOR_API_ARGS);

/*! \brief Reads a dword from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The dword read
 *	
 *	Example usage:
 *  \code
 *		local b = readdword(0x12345678, 3) -- read the dword at 0x12345678 + 3
 *		local b = readdword(0x12345678) -- read the dword at 0x12345678
 *  \endcode
 */
void l_readdword(PHASOR_API_ARGS);

/*! \brief Reads an int from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The integer read
 *	
 *	Example usage:
 *  \code
 *		local b = readint(0x12345678, 3) -- read the int at 0x12345678 + 3
 *		local b = readint(0x12345678) -- read the int at 0x12345678
 *  \endcode
 */
void l_readint(PHASOR_API_ARGS);

/*! \brief Reads a float from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The word read
 *	
 *	Example usage:
 *  \code
 *		local b = readfloat(0x12345678, 3) -- read the float at 0x12345678 + 3
 *		local b = readfloat(0x12345678) -- read the float at 0x12345678
 *  \endcode
 */
void l_readfloat(PHASOR_API_ARGS);

/*! \brief Reads a double from the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\return The double read
 *	
 *	Example usage:
 *  \code
 *		local b = readdouble(0x12345678, 3) -- read the double at 0x12345678 + 3
 *		local b = readdouble(0x12345678) -- read the double at 0x12345678
 *  \endcode
 */
void l_readdouble(PHASOR_API_ARGS);

/*! \brief Reads a string from the specified memory address.
 *
 *	\param address The memory address to read from.
 *	\param [length] The number of characters to read.
 */
void l_readstring(PHASOR_API_ARGS);

/*! \brief Reads a wide string from the specified memory address.
 *
 *	\param address The memory address to read from.
 *	\param [length] The number of wide characters to read.
 *	
 *	\remark
 *	A wide string is one where each character is two bytes wide. Lua
 *	can't handle wide strings so Phasor will convert to a narrow string
 *	before returning.
 */
void l_readwidestring(PHASOR_API_ARGS);

/*! \brief Writes a bit to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param bit_offset Which bit to write (starting at 0)
 *	\param data The value to write (1 or 0)
 * 
 * 	Example usage:
 *  \code
 *		writebit(0x12345678, 3, 1, 0) -- write 0 to the 2nd bit at 0x12345678 + 3
 *		writebit(0x12345678, 1, 0) -- write 0 to the 2nd bit at 0x12345678
 *  \endcode
 *  
 *  \remark
 *  \c bit_offset starts at 0 for the least significant bit
 */
void l_writebit(PHASOR_API_ARGS);

/*! \brief Writes a byte to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writebyte(0x12345678, 3, 50) -- write 50 to 0x12345678 + 3
 *		writebyte(0x12345678, 50) -- write 50 to 0x12345678
 *  \endcode
 */
void l_writebyte(PHASOR_API_ARGS);

/*! \brief Writes a char to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writechar(0x12345678, 3, -41) -- write -41 to 0x12345678 + 3
 *		writechar(0x12345678, -41) -- write -41 to 0x12345678
 *  \endcode
 */
void l_writechar(PHASOR_API_ARGS);

/*! \brief Writes a word to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writeword(0x12345678, 3, 50) -- write 50 to 0x12345678 + 3
 *		writeword(0x12345678, 50) -- write 50 to 0x12345678
 *  \endcode
 */
void l_writeword(PHASOR_API_ARGS);

/*! \brief Writes a short to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writeshort(0x12345678, 3, 50) -- write 50 to 0x12345678 + 3
 *		writeshort(0x12345678, 50) -- write 50 to 0x12345678
 *  \endcode
 */
void l_writeshort(PHASOR_API_ARGS);

/*! \brief Writes a dword to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writedword(0x12345678, 3, 0xbadf00d) -- write 0xbadf00d to 0x12345678 + 3
 *		writedword(0x12345678, 50) -- write 50 to 0x12345678
 *  \endcode
 */
void l_writedword(PHASOR_API_ARGS);

/*! \brief Writes an int to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writeint(0x12345678, 3, -501) -- write -501 to 0x12345678 + 3
 *		writeint(0x12345678, 50) -- write 50 to 0x12345678
 *  \endcode
 */
void l_writeint(PHASOR_API_ARGS);

/*! \brief Writes a float to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writefloat(0x12345678, 3, 1.5) -- write 1.5 to 0x12345678 + 3
 *		writefloat(0x12345678, 1.5) -- write 1.5 to 0x12345678
 *  \endcode
 */
void l_writefloat(PHASOR_API_ARGS);

/*! \brief Writes a double to the specified memory address.
 *
 *	\param base_address The base address to use.
 *	\param [address_offset] The offset relative to base_address.
 *	\param data The data to write
 *	
 *	Example usage:
 *  \code
 *		writedouble(0x12345678, 3, 1.5) -- write 1.5 to 0x12345678 + 3
 *		writedouble(0x12345678, 1.5) -- write 1.5 to 0x12345678
 *  \endcode
 */
void l_writedouble(PHASOR_API_ARGS);

/*! \brief Writes a string to the specified memory address
 *
 *	\param address The address to write to.
 *	\param str The string to write.
 *
 * Example usage:
 * \code
 *		writestring(0x12345678, "write this string.")
 * \endcode
 */
void l_writestring(PHASOR_API_ARGS);

/*! \brief Writes a wide string to the specified memory address
 *
 *	\param address The address to write to.
 *	\param str The string to write.
 *
 * Example usage:
 * \code
 *		writewidestring(0x12345678, "write this string.")
 * \endcode
 * 
 * \remark 
 * Lua doesn't support wide strings, so Phasor will convert the provided
 * narrow string to wide before writing it. 
 */
void l_writewidestring(PHASOR_API_ARGS);

//! }@