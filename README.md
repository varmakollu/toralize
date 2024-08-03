# Toralize

Toralize is a simple C program designed to establish a connection to a target host via a SOCKS proxy server. It constructs and sends a SOCKS proxy request, receives the response, and attempts to connect to the specified destination host and port. The program can be used to test proxy connectivity and perform basic HTTP requests through the proxy.

## Requirements

- A C compiler (e.g., GCC)
- A SOCKS proxy server (e.g., Tor)
- Basic knowledge of C programming and network concepts

## Installation

1. **Install Dependencies**: Ensure you have a C compiler and the necessary networking libraries installed.
   
2. **Proxy Server**: Set up a SOCKS proxy server if you don't already have one. For example, you can use the Tor network:

   ```bash
   sudo apt install tor
   ```

3. **Download Toralize**: Clone or download the Toralize source code from the repository.

## Usage

To run the Toralize program, use the following command:

```bash
./toralize <host> <port>
```

- `<host>`: The target host IP address.
- `<port>`: The target port number.

### Example

```bash
./toralize 46.227.66.141 80
```

This command attempts to connect to the target IP `46.227.66.141` on port `80` through the SOCKS proxy.

## Compilation

To compile the Toralize program, use the provided `Makefile` or compile manually with GCC:

```bash
gcc -o toralize toralize.c -Wall
```

Ensure all source files (`toralize.c` and `toralize.h`) are in the same directory.

## File Descriptions

- **toralize.c**: The main source file containing the program logic for sending SOCKS proxy requests and handling responses.
- **toralize.h**: The header file defining structures and constants used in the program.

## Troubleshooting

- **Connection Refused**: If you encounter a "Connection refused" error, ensure your proxy server is running and accessible at the specified address and port.

- **Firewall Issues**: Ensure that your firewall settings allow connections to and from the proxy server.

- **Incorrect Proxy Information**: Double-check the proxy settings (`PROXY` and `PROXYPORT` in `toralize.h`) to ensure they are correct.

## Contributing

Contributions are welcome! If you have suggestions, bug reports, or improvements, please open an issue or submit a pull request.