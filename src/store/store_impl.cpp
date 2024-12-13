#include "store_impl.h"
#include "../injector.h"
#include "../shared/exceptions.h"
#include <cmath>
#include <iostream>


double cosine_similarity(std::vector<double> v1, std::vector<double> v2);
double magnitude(std::vector<double> v);

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
    return storedVectorsCount++;
}

bool StoreImpl::Delete(int id)
{
    // This implementation of a Store cannot support delete operations, so false
    // will be returned here.
    return false;
};

/*
TODO: Cleanup the memory allocated for the StoreQueryResponse objects.
*/
std::vector<StoreQueryResponse *> StoreImpl::Query(std::vector<double> v)
{
    int vSize = injector.getConfigManager().GetVSize();

    // throw an error if the vector does not have the expected size
    if (v.size() != vSize)
    {
        throw VecStoreExceptions(VS_ERROR_INVALID_VECTOR_SIZE);
    }

    // Since delete operations aren't supported here, there shouldn't be a need to
    // implement mutexes here. We do, however, cache the size of `vectors` at the point
    // where we approach the portion of the code here runs and only query up to
    // the vectors at this point, since it is possible for new things to be added
    // afterward.
    int length = vectors.size();
    if (length == 0)
    {
        return {};
    }

    // create an vector of length storedVectorsCount where the value at index i
    // is the similarity between that vector and the vector in the query
    std::vector<double> similarities;

    for (int i = 0; i < length; i++)
    {
        similarities.push_back(cosine_similarity(v, vectors[i]));
    }

    // TODO: Reimplement rest of code with heaps

    // return the indices of the 5 vectors with highest similarity.
    // to be iterated with leastSimilarLocalIndex
    std::vector<int> topIndices;

    // indexed with leastSimilarLocalIndex
    std::vector<double> topSimilarities;
    double leastSimilarSimilarity = similarities[0];

    // position of the smallest of the least similar of the top 5 vectors
    // among the ones we have seen so far in topSimilarities & topIndices
    int leastSimilarLocalIndex = 0;

    for (int i = 0; i < 5 && i < length; i++)
    {
        double similarity = similarities[i];
        topIndices.push_back(i);
        topSimilarities.push_back(similarity);

        if (similarity < leastSimilarSimilarity)
        {
            leastSimilarLocalIndex = i;
            leastSimilarSimilarity = similarity;
        }
    }

    for (int i = 5; i < length; i++)
    {
        // if the current similarity is less than the minimum, replace
        // the leastSimilarSimilarity and leastSimilarLocalIndex, and find the new
        // minValue and minIndex
        double similarity = similarities[i];

        if (similarity < leastSimilarSimilarity)
            continue;

        topIndices[leastSimilarLocalIndex] = i;
        topSimilarities[leastSimilarLocalIndex] = similarity;
        leastSimilarSimilarity = similarity;

        for (int j = 0; j < 5; j++)
        {
            if (topSimilarities[j] < leastSimilarSimilarity)
            {
                leastSimilarLocalIndex = j;
                leastSimilarSimilarity = topSimilarities[j];
            }
        }
    }

    std::vector<StoreQueryResponse *> queryResults;

    for (int i = 0; i < topIndices.size(); i++)
    {
        StoreQueryResponse *storeQueryResponsePtr = new StoreQueryResponse((double)topIndices[i], topSimilarities[i]);
        // StoreQueryResponse res((double) topIndices[i], topSimilarities[i] );
        // queryResults.push_back({(double) topIndices[i], topSimilarities[i]})
        queryResults.push_back(storeQueryResponsePtr);
    }

    // sort the query results in descending order
    std::sort(queryResults.begin(), queryResults.end(), [](const StoreQueryResponse *a, const StoreQueryResponse *b)
              { return a->similarity > b->similarity; });

    return queryResults;
}

double cosine_similarity(std::vector<double> v1, std::vector<double> v2)
{
    // return -1 if dimensions are not equal
    if (v1.size() != v2.size())
        return -1;

    double dot_product = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        dot_product += v1[i] * v2[i];
    }

    // handle zero magnitudes
    double m1 = magnitude(v1);
    double m2 = magnitude(v2);
    if (m1 == 0 || m2 == 0)
        return -1;

    return dot_product / (m1 * m2);
}

double magnitude(std::vector<double> v)
{
    double squared_sum = 0;

    for (auto component : v)
        squared_sum += component * component;

    return std::sqrt(squared_sum);
}
