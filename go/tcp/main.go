package main

import (
    "fmt"
    "flag"
    "net"
    "os"
)

// Arguments
var host string
var port int

func init() {
    hostPtr := flag.String("host", "localhost", "Host of the server")
    portPtr := flag.Int("port", 4444, "Port of the server")
    flag.Parse()
    host = *hostPtr
    port = *portPtr
}

func main() {
    fmt.Println("Server Running...")
    server, err := net.Listen("tcp", fmt.Sprintf("%s:%d", host, port))
    if err != nil {
        panic(err)
    }
    defer server.Close()

    fmt.Println("Listening on " + fmt.Sprintf("%s:%d", host, port))
    fmt.Println("Waiting for client...")
    for {
        connection, err := server.Accept()
        if err!= nil {
            fmt.Println("Error accepting: ", err.Error())
            os.Exit(1)
        }
        fmt.Printf("Client Connected. Local: %s; Remote: %s\n", connection.LocalAddr().String(), connection.RemoteAddr().String())
        go processClient(connection)
    }
}

func processClient(connection net.Conn) {
    buffer := make([]byte, 1024)
    defer func(){
        connection.Close()
        fmt.Printf("Closing Connection. Local: %s; Remote: %s\n", connection.LocalAddr().String(), connection.RemoteAddr().String())
    }()

    for {
        mLen, err := connection.Read(buffer)
        if err != nil {
            fmt.Println("Error reading", err.Error())
            break
        }
        fmt.Println("Received: ", string(buffer[:mLen]))
        _, err = connection.Write([]byte("Thanks! Got your message: " + string(buffer[:mLen])))
        if err != nil {
            fmt.Println("Error sending", err.Error())
            break
        }
    }
}
