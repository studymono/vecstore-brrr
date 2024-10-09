#ifndef VECSTORE_INJECTOR
#define VECSTORE_INJECTOR
#include "config_manager/config_manager.h"
#include "config_manager/config_manager_impl.h"

class Injector
{
private:
    ConfigManagerImpl configManager;

public:
    ConfigManager &getConfigManager();
};

#endif // VECSTORE_INJECTOR
