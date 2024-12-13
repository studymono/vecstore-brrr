#ifndef VECSTORE_STORE
#define VECSTORE_STORE

#include <vector>

struct StoreQueryResponse
{
    int id;
    double similarity;

    StoreQueryResponse(int id, double similarity) : id(id), similarity(similarity) {};
};

class Store
{
public:
    virtual bool Delete(int id) = 0;
    virtual int Write(std::vector<double> v) = 0;
    virtual std::vector<StoreQueryResponse *> Query(std::vector<double> v) = 0;
};

#endif // VECSTORE_STORE
