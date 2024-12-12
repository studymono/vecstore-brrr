#include "store_impl.h"
#include "../injector.h"
#include "../shared/exceptions.h"
#include <iostream>
using namespace std;

StoreImpl::StoreImpl()
{
}

int StoreImpl::Write(std::vector<double> v)
{
    // TODO: Implement a mutex here to prevent race conditions
    int vSize = injector.getConfigManager().GetVSize();

    // throw an error if the vector does not have the expected size
    if (v.size() != vSize)
    {
        throw VecStoreExceptions(VS_ERROR_INVALID_VECTOR_SIZE);
    }

    // insert the new vector into the array
    vectors.push_back(v);

    // IMPLEMENT AND REMOVE
    return ++size;
}

bool StoreImpl::Delete(int id)
{
    // This implementation of a Store cannot support delete operations, so false
    // will be returned here.
    return false;
};

std::vector<double> StoreImpl::Query(std::vector<double> v)
{
    return {};
}
