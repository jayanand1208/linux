#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/my_socket"

int main() {
    int client_socket;
    struct sockaddr_un server_addr;
    char buffer[1024] = {0};

    // Create client socket
    if ((client_socket = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("Client socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send data to server
    const char* message = "Hello from client!";
    send(client_socket, message, strlen(message), 0);

    printf("Message sent to server\n");

    // Receive response from server
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server response: %s\n", buffer);

    // Close socket
    close(client_socket);

    return 0;
}

