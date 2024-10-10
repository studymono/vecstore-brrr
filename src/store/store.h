#ifndef VECSTORE_STORE
#define VECSTORE_STORE

class Store
{
public:
    virtual bool Delete(int id) = 0;
    virtual bool Write(double v[]) = 0;
    virtual double *Query(double v[]) = 0;
};

#endif // VECSTORE_STORE
