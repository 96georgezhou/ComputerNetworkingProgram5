//
// Created by george on 6/5/19.
//

#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "Socket.h"
#include <string.h>
#include <iostream>
#include <sys/poll.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 8192

class FTPClient {
public:
    FTPClient();                                            // Constructor
    FTPClient(char*, char*, char*);                         // Constructor (Username & password)
    FTPClient(char* );                                      // Constructor
    ~FTPClient();                                           // Destructor
    int open_connection(char* hostName, int port);          // Establish connection
    void close_connection();                                // Close connection
    void quit();                                            // Quit
    int login(char *username, char* password);              // Login
    int sendUserName(char* nameToSend);                     // Send USER
    int sendMessage(const char *buffer);                    // Send message
    char* recvMessage();                                    // Receive message
    int sendPassword(char* passToSend);                     // Send PASS
    int sendPASV();                                         // Send PASV to server and obtain a new Server Socket
    int sendSYST();                                         // Send client file system type
    int getPortFromPASV(char* );                            // Get port from PASV
    bool changeDir(char* dirName);                          // Change working dir
    char* getCurrentDirContents();                          // Return dir contents
    int downloadFile(char *filename);                       // GET
    bool putFile(char* fileName);                           // PUT
    bool listDir(char* pathname);                           // LIST
    int getReturnCode(char *message);                       // Get return code
    double time_diff(struct timeval x, struct timeval y);   // Get time
    int getMessageSize(char *msg);                          // Get message size
    bool renameFile(char* oldFilename, char* newFilename);  // Rename file
    bool makeDir(char* dirName);                            // Make dir
    bool removeDir(char* dirName);                          // rm dir
    bool printWorkingDirectory();                           // PWD
    bool deleteFile(char* fileName);                        // rm file


private:
    int clientSD;                                           // Client SD
    int dataSD;                                             // passive connection SD
    int recvBytes;
    Socket* sock;                                           // Client socket
    Socket* serverSock;                                     // Server socket
    char ctrlBuf[BUFSIZE + 1];
    char dataBuf[BUFSIZE + 1];
};



#endif /* FTPCLIENT_H */