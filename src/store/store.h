#ifndef VECSTORE_STORE
#define VECSTORE_STORE

#include <vector>

class Store
{
public:
    virtual bool Delete(int id) = 0;
    virtual int Write(std::vector<double> v) = 0;
    virtual std::vector<double> Query(std::vector<double> v) = 0;
};

#endif // VECSTORE_STORE
