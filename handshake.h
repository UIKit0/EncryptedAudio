#ifndef __ENC_HANDSHAKE_H__
#define __ENC_HANDSHAKE_H__

enum state {
    SENDER_HELLO,
    RECEIVER_HELLO,
    SENDER_ACKNOWLEDGE,
    RECEIVER_CHECK_ACKNOWLEDGE,
    HANDSHAKE_FINISHED
};

void _handshake();

#endif