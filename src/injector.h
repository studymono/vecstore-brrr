#ifndef VECSTORE_INJECTOR
#define VECSTORE_INJECTOR

// Configuration Manager
#include "config_manager/config_manager.h"
#include "config_manager/config_manager_impl.h"

// Store
#include "store/store.h"
#include "store/store_impl.h"

class Injector
{
private:
    ConfigManagerImpl configManager;
    StoreImpl store;

public:
    ConfigManager &getConfigManager();
    Store &getStore();
};

extern Injector injector;

#endif // VECSTORE_INJECTOR
