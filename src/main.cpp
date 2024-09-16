#include "connection_manager/connection_manager.h"

int main() {
    // TODO: Allow for the setting of the port from a flag.
    ConnectionManager cm{8000};
    cm.Start();
    return 0;
}