#include "receiver.h"

// Keys
const unsigned char  Enc_ReceiverModulus[ENC_KEY_CHARS+1] =
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

const unsigned char Enc_ReceiverPrivateExp[ENC_KEY_CHARS] =
    "\x3c\x13\xf0\x04\xd1\x24\xdd\x01\x03\xd2\xb0\x71\x42\xa2\xf6"
    "\x10\xc6\x35\x96\x9c\xd4\x4c\x46\xd9\xaf\x91\xbe\xcc\xad\xc9"
    "\xc5\x51\xdb\x4d\x5b\x81\xd9\x89\x13\xd4\xc4\xb0\x30\x30\xf7"
    "\x00\xe6\xc5\x50\x5d\x10\xa4\x9f\xf4\xec\xc0\x73\xd8\xfd\x36"
    "\x9e\x60\xe1\x42\x4f\x73\xae\xf7\x28\x0d\x15\xcd\x92\xb0\x0d"
    "\x5f\x04\xeb\xf9\xd0\xc0\xe7\x38\xff\x9e\xc3\x2c\xab\x22\xcd"
    "\x4b\xda\xcb\xc7\xbd\x24\xd4\x51\x71\xe5\x99\x01\xcb\xcb\x78"
    "\xc0\xbd\x3f\xc2\xc5\xd9\x02\x46\x68\xa9\xbc\xfd\x11\x3f\xc5"
    "\xdc\xc3\x6a\x55\xad\x3f\x5f\xfb\x08\xad\x01\x5a\xac\x02\xbc"
    "\xa1\xaa\xb7\x88\x01\x2b\xbd\x60\x97\x41\xbf\x5b\x6e\x06\x55"
    "\xf9\x03\xb5\xd1\xd3\xc1";

// Memory Pointers
int *senderModExp;
int *receiverSecret;

void receiver_construct() {
    senderModExp = (int *) calloc(ENC_KEY_CHARS, sizeof(field_t));
    receiverSecret = (int *) calloc(ENC_DH_SECRET_DIGITS, sizeof(field_t));
}

int receiver_receiverHello(field_t *sendPacket, field_t *receivedPacket) {
    unsigned char i = 0;

    printf("--> receiver_receiverHello\n");

    if (0x00 != receivedPacket[0])
        return ENC_REJECT_PACKET_TAG;

    printf("--| senderModExp\n");
    for (i = 0; i < ENC_KEY_CHARS; i++) {
        senderModExp[i] = receivedPacket[i+1];
        printf("%x", senderModExp[i]);
    }
    printf("\n");

    receiverHello(sendPacket, senderModExp, receiverSecret, Enc_ReceiverModulus, Enc_ReceiverPrivateExp);
}

void receiver_destruct() {
	free(senderModExp);
    free(receiverSecret);
}
