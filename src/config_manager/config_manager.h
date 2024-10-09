#ifndef VECSTORE_CONFIG_MANAGER
#define VECSTORE_CONFIG_MANAGER

class ConfigManager
{
public:
    virtual int GetVSize() = 0;
    virtual void LoadConfigsFromCommandLineFlags(int argc, char *argv[]) = 0;
};

#endif // VECSTORE_CONFIG_MANAGER
