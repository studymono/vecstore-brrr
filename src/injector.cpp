#include "injector.h";

ConfigManager &Injector::getConfigManager()
{
    return configManager;
}

Store &Injector::getStore()
{
    return store;
}
