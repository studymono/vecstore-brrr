#ifndef VECTORE_STORE_IMPL
#define VECTORE_STORE_IMPL

#include "store.h"

class StoreImpl : public Store
{
private:
    int vSize;
    std::vector<std::vector<double>> vectors;

public:
    virtual bool Delete(int id) override;
    virtual bool Write(std::vector<double> v) override;
    virtual std::vector<double> Query(std::vector<double> v) override;
    StoreImpl();
};

#endif // VECTORE_STORE_IMPL
