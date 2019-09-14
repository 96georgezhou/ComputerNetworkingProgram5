# ComputerNetworkingProgram5
FTP, or File Transfer Protocol, is a method of transmitting files from one computer to another over a
TCP/IP connection. This FTP Client is written from scratch and is designed to mimic the functionality and
interaction of the native Linux console FTP client. It operates by establishing a TCP connection between
the client and a remote server over port 21 (or another user specified port). Commands and responses
are handled on the full-duplex control socket connection as character streams and decoded to
determine requested interactions. For ASCII or binary data streams, a second TCP socket connection
must be established.
