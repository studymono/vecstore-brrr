# vecstore
A vector database


## Error Code Translations:
- 400: The server is unable to respond to your request.
- 401: Invalid query. The query is invalid and unparsable. Data might have been provided without relevant flags. Incomplete data might have been sent. It's also possible that the request contains more bytes than the maximum receivable bytes. (See `connection_manager::handle_connection`).
- 402: Invalid query. The query can be parsed but is invalid. it is likely that there are arrays of values that were provided more or fewer values than expected. Only send the amount of data required to exactly describe the request to be made, as described in the protocol.