#include "execution_router.h"

void ExecutionRouter::Handle(char *req, Client client)
{
    std::string request_string(req);
    Request request;

    try
    {
        request = Transcoder::Parse(request_string);
    }
    catch (std::invalid_argument err)
    {
        Request res{};
        res.set_command("ERR").set_modifier("GENERIC").set_status(401);
        client.Send(Transcoder::Encode(res));
        return;
    }

    string command = request.get_command();
    if (Transcoder::Validate(request) == false)
    {
        // query is parsable, but invalid for some other reason
        Request res{};
        res.set_command("ERR").set_modifier(command).set_status(402);
        client.Send(Transcoder::Encode(res));
        return;
    }

    if (this->executor_map.find(command) != this->executor_map.end())
    {
        executor_map[command](request, client);
    }
    else
    {
        Request res{};
        res.set_command("ERR").set_modifier(command).set_status(400);
        client.Send(Transcoder::Encode(res));
        return;
    }
};