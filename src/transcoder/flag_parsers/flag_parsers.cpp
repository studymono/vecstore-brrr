#include "flag_parsers.h"

void ParseStatus(const vector<string> &phrases, Request &parsed_request, int &pos)
{
    // verify that something appears after this, and that it is an integer
    if (phrases.size() <= (pos + 1))
        throw std::invalid_argument("--status is missing a required following integer argument.");

    try
    {
        int status;
        status = stoi(phrases[pos + 1]);
        parsed_request.set_status(status);
    }
    catch (...)
    {
        throw std::invalid_argument("The argument to --status must be an integer.");
    }

    pos += 2;
}

void ParseVCount(const vector<string> &phrases, Request &parsed_request, int &pos)
{
    // verify that something appears after this, and that it is an integer
    if (phrases.size() <= (pos + 1))
        throw std::invalid_argument("--vcount is missing a required following integer argument.");

    try
    {
        int vcount;
        vcount = stoi(phrases[pos + 1]);
        parsed_request.set_vcount(vcount);
    }
    catch (...)
    {
        throw std::invalid_argument("The argument to --vcount must be an integer.");
    }

    pos += 2;
}

void ParseVSize(const vector<string> &phrases, Request &parsed_request, int &pos)
{
    // verify that something appears after this, and that it is an integer
    if (phrases.size() <= (pos + 1))
        throw std::invalid_argument("--vsize is missing a required following integer argument.");

    try
    {
        int vsize;
        vsize = stoi(phrases[pos + 1]);
        parsed_request.set_vsize(vsize);
    }
    catch (...)
    {
        throw std::invalid_argument("The argument to --vsize must be an integer.");
    }

    pos += 2;
}

void ParseTopK(const vector<string> &phrases, Request &parsed_request, int &pos)
{
    // verify that something appears after this, and that it is an integer
    if (phrases.size() <= (pos + 1))
        throw std::invalid_argument("--topk is missing a required following integer argument.");

    try
    {
        int topk;
        topk = stoi(phrases[pos + 1]);
        parsed_request.set_topk(topk);
    }
    catch (...)
    {
        throw std::invalid_argument("The argument to --topk must be an integer.");
    }

    pos += 2;
}