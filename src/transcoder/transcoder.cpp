#include "transcoder.h"
#include "flag_parsers/flag_parsers.h"

/*
This splits a string across whitespaces. The ignores trailing whitespaces and treats consecutive
whitespaces as a single whitespace.
*/
vector<string> split_on_whitespaces(string str)
{
    string word;
    vector<string> words;

    for (auto c : str)
    {
        if (c != ' ')
            word += c;
        else if (word != "")
        {
            words.push_back(word);
            word = "";
        }
    }

    if (word != "")
    {
        words.push_back(word);
    }

    return words;
}

void ParseRecurser(const vector<string> &phrases, Request parsed_request, int pos)
{
    // return if pos is out of bounds
    if (pos >= phrases.size())
        return;

    // everything except for a command and a modifier must be preceeded by a flag.
    // so an error is thrown if the phrase at pos is not preceeded by a flag
    if (phrases[pos].substr(0, 2) != "--")
        throw std::invalid_argument("All non-command/modifier arguments passed in a request must be preceeded by a flag.");

    // decide how to proceed with parsing based on what flag was passed
    if (phrases[pos] == "--vsize")
        ParseVSize(phrases, parsed_request, pos);

        ParseRecurser(phrases, parsed_request, pos);
}

/*
We assume that only commands and modifiers are written in upper case. A future version of the parser will be designed
to be case insensitive.
*/
Request Transcoder::Parse(string req)
{
    vector<string> req_phrases = split_on_whitespaces(req);

    // throw an error if the request is empty
    if (req_phrases.size() == 0)
        throw std::invalid_argument("Request to be parsed cannot be empty");

    Request parsed_request{};
    // set the first word in the request as the command
    parsed_request.set_command(req_phrases[0]);

    // Returned the parsed request if the request contains one phrase
    if (req_phrases.size() == 1)
        return parsed_request;

    int pos = 1;
    // If the second phrase does not start with --, set it as the modifier
    if (req_phrases[1].substr(0, 2) != "--")
        parsed_request.set_modifier(req_phrases[pos++]);

    // call the function that recursively looks at the xth phrase of req_phrases and updates
    ParseRecurser(req_phrases, parsed_request, pos);

    return parsed_request;
}

/*

Parsing Queries

=====
Split everything across white spaces.

- The first word will be the command.
- If the second word is not preceeded by a flag, then it is a modifier
- Have a recursive thing that looks at the first thing available to it and decides how to update
the parsed object.
- If the recursive function meets any of the flags that must appear last, it should error if it sees another flag afterward.
- If a flag appears multiple time, use the second value that is set for the flag.


*/