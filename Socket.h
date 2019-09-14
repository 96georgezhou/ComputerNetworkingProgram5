//
// Created by george on 6/5/19.
//

#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>        // GetHostByName
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
class Socket {

    public:
        Socket(int);
        int getServerSocket( );
        int getClientSocket(char*);

    private:
        int portNumber;
        int SD;
};


#endif /* SOCKET_H */