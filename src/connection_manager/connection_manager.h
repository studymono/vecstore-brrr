#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

class Client
{
private:
    int port_;

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

    void Start();
    void Stop();
};

#endif // CONNECTION_MANAGER_H
