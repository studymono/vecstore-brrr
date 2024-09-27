import json
import socket

# Open the JSON file
with open("questionAnswerPairEmbeddings.json") as f:
    data = json.load(f)

embeddings = [e["sentenceEmbedding"] for e in data] + [
    e["questionEmbedding"] for e in data
]

def create_insert_request_string(arr):
    req = ""

    vcount = 1
    vsize = len(arr)
    req += f"WRITE --vcount {vcount} --vsize {vsize} --vector"

    for num in arr:
        req += f" {num}"

    return req


def connect_and_seed(vectors, host="127.0.0.1", port=8000, verbose=True):
    """
    Connect to a server running on the specified host and send requests to the DB.
    """
    # Create a socket object (IPv4, TCP)
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Connect to the server
        client_socket.connect((host, port))
        print(f"Connected to server on {host}:{port}\n")

        for v in vectors:
            req = create_insert_request_string(v)
            print(f"SENT: \n{req if verbose else req[:64]}")

            client_socket.sendall(req.encode())
            response = client_socket.recv(4096)  # Buffer size
            if not response:
                print("Server closed the connection.")
                break

            # Print the server's response
            print(f"RECEIVED: \n{response.decode()}\n")

        print("DB seed attempy successfully completed. \n")

    except ConnectionRefusedError:
        print(f"Unable to connect to {host}:{port}. Make sure the server is running.")

    finally:
        # Close the socket connection
        client_socket.close()
        print("Connection closed.")


connect_and_seed(vectors=embeddings)
