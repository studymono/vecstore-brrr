#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

class Client
{
private:
    int port_;
    int serverSocket_;

public:
    Client(int port);
};

class ConnectionManager
{
private:
    int port_;
    int server_socket_;

public:
    /*
    Initializes a ConnectionManager object that can listen on a specified
    port.
    */
    ConnectionManager(int port);

    /*
    Returns -1 if an error occurs when the server is being launched.
    */
    int Start();
    void Stop();
};

#endif // CONNECTION_MANAGER_H
