#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/my_socket"

int main() {
    int server_socket, client_socket;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[1024] = {0};

    // Create server socket
    if ((server_socket = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

    // Bind the server socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s\n", SOCKET_PATH);

    // Accept incoming connection
    if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from client\n");

    // Receive data from client
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Client message: %s\n", buffer);

    // Send response to client
    const char* response = "Hello from server!";
    send(client_socket, response, strlen(response), 0);

    printf("Response sent to client\n");

    // Close sockets
    close(client_socket);
    close(server_socket);

    // Remove the socket file
    unlink(SOCKET_PATH);

    return 0;
}

