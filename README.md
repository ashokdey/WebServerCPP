# Web Server in C++ 

This project provides a modular C++ networking solution with reusable components for building and testing socket servers.

## What's Inside? 

- 🧩 Modular Design: Organized into server and socket components for clarity and scalability.
- 🔌 Socket Abstraction: Easy-to-use classes for creating binding and listening sockets.
- 🚀 Test Server: A simple server implementation for quick development and testing.
- 🛠️ Custom Networking Tools: Extendable components to suit your networking needs.

### Directory Structure 

```bash 

.
├── BUILD.bazel
├── MODULE.bazel
├── MODULE.bazel.lock
├── README.md
├── assets
│   └── screens
│       ├── 1.png
│       └── 2.png
├── main_server.cpp
├── main_socket.cpp
└── networking
    ├── BUILD.bazel
    ├── lib
    │   ├── BUILD.bazel
    │   ├── binding_socket
    │   │   ├── BUILD.bazel
    │   │   ├── binding_socket.cpp
    │   │   └── binding_socket.hpp
    │   ├── lib.hpp
    │   ├── listening_socket
    │   │   ├── BUILD.bazel
    │   │   ├── listening_socket.cpp
    │   │   └── listening_socket.hpp
    │   └── socket
    │       ├── BUILD.bazel
    │       ├── socket.cpp
    │       └── socket.hpp
    └── server
        ├── BUILD.bazel
        ├── _server_lib.hpp
        ├── server.cpp
        ├── server.hpp
        ├── test_server.cpp
        └── test_server.hpp

```

### Compilation 

Using [Bazel](https://bazel.build) for compiling and runnig the applications 

- Buidling the `main_socket` lib ```bash bazel build //:main_socket ```
- Running the `main_socket` lib ```bash bazel run //:main_socket ```
- Buidling the `main_server` lib ```bash bazel build //:main_server ```
- Running the `main_server` lib ```bash bazel run //:main_socket ```

If you are willing to build the supporting the libraries

- Buidling the socket lib ```bash bazel build //networking/lib/socket:socket ```
- Buidling the server lib ```bash bazel build //networking/server/server:server ```


### Working Explained 

Server Initialization: The Server base class initializes sockets and manages communication.

Test Server: The TestServer class extends the Server class and handles:

- acceptor(): Accepts incoming connections.
- handler(): Reads client messages.
- responder(): Sends responses back to the client.

Socket Abstraction:

- Provides reusable components for binding, listening, and handling sockets.

### Screens 

The browser making the request and getting the response 

![browser view](./assets/screens/1.png)

The server logs 

![browser view](./assets/screens/2.png)

#### Using G++? 

To compile the test server 

```bash 

g++ -std=c++11 -I./networking   main_server.cpp networking/*/*.cpp  -o server

```

To compile the socket listener 

```bash 

g++ -std=c++11 -I./networking   main_socket.cpp networking/*/*.cpp  -o socket

```

#### Credits 

Thanks to [Eric's Videos](https://www.youtube.com/@eom-dev) which made this possible! 