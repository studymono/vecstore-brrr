#ifndef VECTORE_STORE_IMPL
#define VECTORE_STORE_IMPL

#include "store.h"

class StoreImpl : public Store
{
private:
    std::vector<std::vector<double>> vectors;
    int storedVectorsCount;

public:
    virtual bool Delete(int id) override;
    virtual int Write(std::vector<double> v) override;
    virtual std::vector<StoreQueryResponse *> Query(std::vector<double> v) override;
    StoreImpl();
};

#endif // VECTORE_STORE_IMPL
