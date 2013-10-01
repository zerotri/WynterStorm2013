package main

import (
        "log"
        "net"
)

func main() {
        var conns []net.Conn
        for i := 0; i < 200; i++ {
                c, err := net.Dial("tcp", "127.0.0.1:2020")
                if err != nil {
                        log.Fatalf("dial error: %v", err)
                }
                conns = append(conns, c)
        }
        select {}
}