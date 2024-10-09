#ifndef VECSTORE_CONFIG_MANAGER_IMPL
#define VECSTORE_CONFIG_MANAGER_IMPL
#include "config_manager.h"

class ConfigManagerImpl : public ConfigManager
{
private:
    int vsize;

public:
    virtual int GetVSize() override;
    virtual void LoadConfigsFromCommandLineFlags(int argc, char *argv[]) override;
};

#endif // VECSTORE_CONFIG_MANAGER_IMPL
