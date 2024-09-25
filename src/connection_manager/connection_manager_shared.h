#ifndef VECSTORE_CONNECTION_MANAGER_SHARED_H
#define VECSTORE_CONNECTION_MANAGER_SHARED_H

#include <string>

/*
Shared Client object for communicating with clients. The ConnectionManager creates an instance
of this for all connection clients and passes this object around as the request gets handled.
*/
class Client
{
private:
    int client_socket;

public:
    Client(int client_socket) : client_socket(client_socket) {};

    /*
    The Send function handles adding line terminators at the end of strings.

    Returns a non-zero value if the message gets sent successfully. Returns -1 otherwise.
    */
    int Send(std::string message);
};

#endif // VECSTORE_CONNECTION_MANAGER_SHARED_H