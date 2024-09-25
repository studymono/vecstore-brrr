#include "execution_router.h"

void ExecutionRouter::Handle(char * req, Client client) {
    std::string request_string(req);
    Request request = Transcoder::Parse(request_string);
    string command = request.get_command();

    if(this->executor_map.find(command) != this->executor_map.end()) {
        executor_map[command](request, client);
    } else {
        Request res_request{};
        res_request.set_command("ERR").set_modifier(command).set_status(999);
        client.Send(Transcoder::Encode(res_request));
    }
};