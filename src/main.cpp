#include "connection_manager/connection_manager.h"
#include "execution_router/execution_router.h"
#include "execution_router/executors/executors.h"

ExecutionRouter execution_router{};

int main()
{
    // TODO: Consider moving the binding of executors elsewhere.
    execution_router.Bind("PING", HandlePing);
    // TODO: Allow for the setting of the port from a flag.
    ConnectionManager cm{8000};
    cm.Start();
    return 0;
}