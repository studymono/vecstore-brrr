#ifndef VECSTORE_VECSTORE_ERROR
#define VECSTORE_VECSTORE_ERROR

#include <string>

enum Error
{
    VS_ERROR_INVALID_VECTOR_SIZE,
};

class VecStoreError
{
private:
    int errorCode;
    std::string description;

public:
    VecStoreError(int errorCode, std::string description)
        : errorCode(errorCode),
          description(description)
    {
    }

    std::string GetDescription() const
    {
        return description;
    }

    int GetErrorCode() const
    {
        return errorCode;
    }

    static VecStoreError Get(Error e);
};

#endif // VECSTORE_VECSTORE_ERROR