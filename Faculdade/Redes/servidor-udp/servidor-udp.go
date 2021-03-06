package main

import (
	"fmt"
	"net"
	"os"
	"time"
)

func checkError(err error)  {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Erro: %s.\n", err.Error())
		os.Exit(1)
	}
}

func handleClient(conn *net.UDPConn)  {
	defer conn.Close()
	var buf [512]byte

	_, addr, err := conn.ReadFromUDP(buf[0:])

	if err != nil {
		return
	}

	daytime := time.Now().String()

	conn.WriteToUDP([]byte(daytime), addr)
}

func main() {
	service := ":1200"
	udpAddr, err := net.ResolveUDPAddr("udp", service)
	checkError(err)

	conn, err := net.ListenUDP("udp", udpAddr)
	checkError(err)

	handleClient(conn)
}
