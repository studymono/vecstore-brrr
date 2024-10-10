#ifndef VECTORE_STORE_IMPL
#define VECTORE_STORE_IMPL

#include "store.h"

class StoreImpl : public Store
{
public:
    virtual bool Delete(int id) override;
    virtual bool Write(double v[]) override;
    virtual double *Query(double v[]) override;
};

#endif // VECTORE_STORE_IMPL
