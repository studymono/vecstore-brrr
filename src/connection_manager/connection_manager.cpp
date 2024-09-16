#include <netinet/in.h>
#include "connection_manager.h"
#include "../logger/logger.h"

using namespace std;

ConnectionManager::ConnectionManager(int port) : port_(port)
{
}

int ConnectionManager::Start()
{
    logger << "Starting a server on on port: " << port_ << endl;
    server_socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if ((server_socket_) == -1)
    {
        logger << "An error occured when creating a socket for the server." << endl;
        return -1;
    };

    // TODO: Have a way to use a command line argument to set whether a port should be reusable
    // This is a helpful thing to have in production. In fact, it might be more useful to have
    // this being off as a default and then choose to turn it on in dev.
	int reuse = 1;
	if (setsockopt(server_socket_, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
	{
		logger << "SO_REUSEADDR failed: " << endl;
        return -1;
	}

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port_);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket_, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        logger << "An error occured when binding to port " << port_ << endl;
        return -1;
    };

    if (listen(server_socket_, 5) == -1)
    {
        logger << "An error occured when preparing to listen to connections." << endl;
        return -1;
    };

    logger << "VecStore is listening on port: " << port_ << endl;
    int clientSocket = accept(server_socket_, nullptr, nullptr);

    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer << endl;

    return 0;
}