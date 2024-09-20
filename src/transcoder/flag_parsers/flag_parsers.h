#include <string>
#include <vector>
#include "../transcoder.h"

void ParseStatus(const vector<string> &phrases, Request &parsed_request, int &pos);

void ParseVCount(const vector<string> &phrases, Request &parsed_request, int &pos);
void ParseVSize(const vector<string> &phrases, Request &parsed_request, int &pos);
void ParseTopK(const vector<string> &phrases, Request &parsed_request, int &pos);

void ParseKeys(const vector<string> &phrases, Request &parsed_request, int &pos);
void ParseVector(const vector<string> &phrases, Request &parsed_request, int &pos);
