#ifndef VECSTORE_TRANSCODER_H
#define VECSTORE_TRANSCODER_H

#include <string>
#include <vector>
using namespace std;

class Request
{
private:
    string command_;
    string modifier_;
    int status_;

    int vcount_;
    int vsize_;
    int topk_;

    vector<int> keys_;
    vector<vector<double>> vectors_;

public:
    string getCommand() const { return command_; }
    Request &setCommand(string newCommand)
    {
        command_ = newCommand;
        return *this;
    }

    string getModifier() const { return modifier_; }
    Request &setModifier(string newModifier)
    {
        modifier_ = newModifier;
        return *this;
    }

    int getStatus() const { return status_; }
    Request &setStatus(int newStatus)
    {
        status_ = newStatus;
        return *this;
    }

    int getVCount() const { return vcount_; }
    Request &setVCount(int newVCount)
    {
        vcount_ = newVCount;
        return *this;
    }

    int getVSize() const { return vsize_; }
    Request &setVSize(int newVSize)
    {
        vsize_ = newVSize;
        return *this;
    }

    int getTopK() const { return topk_; }
    Request &setTopK(int newTopK)
    {
        topk_ = newTopK;
        return *this;
    }

    vector<int> setKeys() const { return keys_; }
    Request &setKeys(vector<int> newKeys)
    {
        keys_ = newKeys;
        return *this;
    }

    vector<vector<double>> getVectors() const { return vectors_; }
    Request &setVectors(vector<vector<double>> newVectors)
    {
        vectors_ = newVectors;
        return *this;
    }
};

#endif // VECSTORE_TRANSCODER_H
