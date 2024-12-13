#include "vecstore_error.h"
#include "map"

VecStoreError VecStoreError::Get(Error e)
{
    std::map<Error, VecStoreError *> errorMap;

    errorMap[VS_ERROR_INVALID_VECTOR_SIZE] = new VecStoreError(413, "The size of the received vector does not match what was expected.");

    return *errorMap[e];
}
