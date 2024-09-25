#ifndef EXECUTION_ROUTER_H
#define EXECUTION_ROUTER_H

#include <unordered_map>
#include <functional>
#include "../transcoder/transcoder.h"
#include "../connection_manager/connection_manager_shared.h"

class ExecutionRouter
{
private:
    std::unordered_map<std::string, std::function<void(Request, Client)>> executor_map;

public:
    ExecutionRouter() {};
    ExecutionRouter(std::unordered_map<std::string, std::function<void(Request, Client)>> executor_map) : executor_map(executor_map) {};

    /*
    Accepts a command string and an executor and updates the executor_map to define the handler for a command.
    */
    void Bind(std::string command, std::function<void(Request, Client)> executor)
    {
        executor_map[command] = executor;
    }

    /*
    Accepts a request object and a client and passes the request object and the client to the correct executor.
    */
    void Handle(char *req, Client client);
};

extern ExecutionRouter execution_router;

#endif // EXECUTION_ROUTER_H