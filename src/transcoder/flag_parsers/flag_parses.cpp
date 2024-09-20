#include "flag_parsers.h"

void ParseVSize(const vector<string> &phrases, Request &parsed_request, int &pos)
{
    // verify that something appears after this, and that it is an integer
    if (phrases.size() <= (pos + 1))
    {
        throw std::invalid_argument("--vsize is missing a required following integer argument.");
    }

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
