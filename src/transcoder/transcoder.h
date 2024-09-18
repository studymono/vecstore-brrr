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
    string get_command() const { return command_; }
    Request &set_command(string newCommand)
    {
        command_ = newCommand;
        return *this;
    }

    string get_modifier() const { return modifier_; }
    Request &set_modifier(string newModifier)
    {
        modifier_ = newModifier;
        return *this;
    }

    int get_status() const { return status_; }
    Request &set_status(int newStatus)
    {
        status_ = newStatus;
        return *this;
    }

    int get_vcount() const { return vcount_; }
    Request &set_vcount(int newVCount)
    {
        vcount_ = newVCount;
        return *this;
    }

    int get_vsize() const { return vsize_; }
    Request &set_vsize(int newVSize)
    {
        vsize_ = newVSize;
        return *this;
    }

    int get_topk() const { return topk_; }
    Request &set_topk(int newTopK)
    {
        topk_ = newTopK;
        return *this;
    }

    vector<int> get_keys() const { return keys_; }
    Request &set_keys(vector<int> newKeys)
    {
        keys_ = newKeys;
        return *this;
    }

    vector<vector<double>> get_vectors() const { return vectors_; }
    Request &set_vectors(vector<vector<double>> newVectors)
    {
        vectors_ = newVectors;
        return *this;
    }
};

#endif // VECSTORE_TRANSCODER_H
