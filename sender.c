#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "dsp.h"
#include "bigdigits.h"
#include "protocol.h"
#include "sender.h"

// Keys
const char            Enc_PublicExp[KEY_SIZE] =
    "\x01\x00\x01";

const char        Enc_SenderModulus[KEY_SIZE] =
    "\x00\xa2\x79\xf4\x8f\xe4\x08\x9d\x96\x13\x09\x66\x31\x6f\x56"
	"\x48\x78\x2c\xaa\xba\x8d\x01\x05\x6f\x41\xb2\xba\x63\x6a\x7a"
	"\x8c\x1f\x54\x33\x31\xc3\x0f\xa0\xe7\x30\x35\x36\x09\x51\x6f"
	"\x6d\xdd\xaf\xe5\x35\xc9\xb9\x6e\x16\x73\xa6\x30\x15\xff\xad"
	"\x86\xaf\xc3\xf4\x6c\x8d\x4a\x76\xe5\xb6\x4e\xe4\x8f\x60\x12"
	"\x46\xc0\xcd\x42\x65\x04\x58\x08\xf1\x3a\xa3\xe2\xc9\x1a\xc3"
	"\x3c\x71\x81\xe9\x20\xff\x7a\xc0\xff\x8e\x24\x44\x34\x6e\x5a"
	"\x8f\xfc\x13\x94\xf6\x09\x19\x57\x94\x0a\xec\xcf\xe7\x19\x11"
	"\x96\x1d\x00\xff\x44\x63\xb7\x40\x3c\xa9\xe4\xd2\x51\x42\x0a"
	"\xd4\xc7\x09\xc5\xea\x72\xdb\x6a\xf8\x3b\x0c\x06\x5f\x4f\x67"
	"\xeb\x2b\x53\x07\xa4\x86\xf7";
const char  Enc_SenderPrivateExp[KEY_SIZE] =
    "\x07\x8e\x74\x79\x5c\xb9\xa9\xda\x98\xf8\x0e\xf0\xad\xa4\xed"
	"\xa9\xe9\x29\xe7\x93\x37\x40\xf1\x73\xb4\xc4\x46\x6b\x65\x57"
	"\xae\xfd\x53\x84\x34\xf6\x3d\x1d\x83\x78\x76\x12\xe8\xde\xad"
	"\xd5\x69\xa0\xd7\x67\x92\x60\x34\x5b\x1c\x97\x8f\xee\x5c\x3b"
	"\xaf\x61\x05\xb5\x26\xbd\x17\xda\x87\x28\x14\x29\x36\xe6\xa2"
	"\xb3\xc4\xd8\x06\xaf\x49\xc0\x5e\x4b\x8a\xea\xb5\x50\x58\xa1"
	"\x93\x1a\x34\xb7\xb1\x1b\x4f\xf9\x6c\xc0\xed\xad\xdf\xa1\xa0"
	"\xe3\x9e\x87\x28\x65\x3f\xf2\x6f\x40\xa4\x0c\xe6\x13\x63\xd9"
	"\x59\x1f\x7c\x31\x31\x73\xfc\xf7\xda\x68\xc8\x23\xff\xc3\x19"
	"\x4f\x85\x17\x63\xce\xf1\x7a\xe6\xb1\xde\xb0\xb9\x65\xfd\x2a"
	"\x83\xeb\x6d\xf6\x5a\x41";

const char  Enc_ReceiverModulus[KEY_SIZE] =
    "\x00\xb2\x20\x91\x91\x03\xe9\x2f\x99\x59\xa3\x65\x80\x2c\xb5"
	"\x25\x03\x03\xaf\xe9\x3c\x42\x13\x07\xc2\x5e\x15\x1b\x21\x09"
	"\x9e\x31\xcb\xef\xaf\x19\xa7\xda\x52\xfc\x8c\x01\x2b\x53\x4e"
	"\xee\x53\x2d\x31\xa6\xe5\x3c\x26\xbc\x61\x9e\x38\x86\x74\xc1"
	"\x44\xf9\xb1\x9c\x87\x18\x9f\x58\x3d\x0c\x00\x58\x83\xaa\x5c"
	"\x77\xe1\xd2\x5d\x04\x8c\x00\xb6\x24\x91\x66\x15\x6a\xd9\xc1"
	"\xaa\x3e\x02\x99\xb5\x11\xad\xf6\xb4\x73\x77\x91\xda\x4a\xb2"
	"\xb6\xa5\x3c\xda\xcd\x2f\xaa\xc9\x47\x51\x20\xf2\x87\xe3\xbe"
	"\x3b\xf5\x8f\x15\x63\xb4\xc1\xb0\xb0\x22\x51\xf0\x4b\xd4\x1c"
	"\x50\x91\xa8\x5b\x8f\x09\x55\x5d\x46\x65\x41\xa7\x4e\xab\x5f"
	"\x4c\xf1\x86\x05\x55\xdf\x83";

int main() {
    exit(EXIT_SUCCESS);
}