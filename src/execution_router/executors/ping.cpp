#include "executors.h"

void HandlePing(Request request, Client client)
{
    client.Send("ACK");
}
