# 🌐 KTU CSL332: Network Programming & Socket Architecture Lab

<div align="center">

[![Language: C](https://img.shields.io/badge/Language-C99-00599C.svg?style=for-the-badge&logo=c)](https://en.cppreference.com/w/c)
[![Architecture: POSIX Sockets](https://img.shields.io/badge/Sockets-Berkeley%20%2F%20POSIX-22c55e.svg?style=for-the-badge)](https://pubs.opengroup.org/)
[![Curriculum](https://img.shields.io/badge/University-KTU%20CSL332-8B0000.svg?style=for-the-badge)](https://ktu.edu.in)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)

<p align="center">
  <b>Comprehensive reference suite for client-server socket programming, transport layer protocols, flow & error control, traffic shaping, and routing algorithms for APJ Abdul Kalam Technological University (KTU).</b>
</p>

</div>

---

## 📌 Overview

This repository provides production-quality, standards-compliant implementations of computer networking algorithms and socket communication models in C. It spans the transport, network, and application layers of the TCP/IP stack, serving as an end-to-end practical manual for network programmers and engineering students.

---

## 🗂️ Protocol & Program Catalog

### 1. Transport Layer Socket Foundations
- **TCP Client-Server** ([`tcp/`](tcp/)): Reliable, stream-oriented, connection-based communication implementing the three-way handshake and socket lifecycle (`socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, `recv()`).
- **UDP Client-Server** ([`udp/`](udp/)): Connectionless, datagram-oriented communication using `sendto()` and `recvfrom()` for high-throughput, low-latency transmission.

### 2. Application Layer Implementations
- **File Transfer Protocol (FTP)** ([`filetransferprotocol/`](filetransferprotocol/)): Custom client-server file exchange over TCP sockets with file integrity verification and buffered streaming.
- **SMTP Protocol Simulator** ([`smtp/`](smtp/)): Emulation of the Simple Mail Transfer Protocol state machine (`HELO`, `MAIL FROM`, `RCPT TO`, `DATA`, `QUIT`).
- **Time Server** ([`time-server/`](time-server/)): Network Time Protocol (NTP) simulation retrieving and syncing system timestamps across sockets.
- **Multi-User Chat System** ([`multi-user/`](multi-user/)): Multi-client concurrent messaging architecture demonstrating process/thread handling on server sockets.

### 3. Flow & Error Control (Sliding Window Protocols)
- **Stop-and-Wait ARQ** ([`sliding window protocol/stopnwait/`](sliding%20window%20protocol/stopnwait/)): Alternating bit protocol with timer expiration and acknowledgment tracking.
- **Go-Back-N ARQ** ([`sliding window protocol/gobackn/`](sliding%20window%20protocol/gobackn/)): Pipelined protocol with window sizing, cumulative ACKs, and timeout retransmission of unacknowledged packets.
- **Selective Repeat ARQ** ([`sliding window protocol/selectiverepeat/`](sliding%20window%20protocol/selectiverepeat/)): Independent packet buffering and selective retransmission for high link efficiency.

### 4. Traffic Shaping & Congestion Control
- **Leaky Bucket Algorithm** ([`leaky-bucket/`](leaky-bucket/)): Traffic policing and shaping algorithm converting bursty network packet flows into a deterministic, constant-rate output stream.

### 5. Network Routing & Shortest Path Algorithms
- **Link-State Routing Algorithm** ([`link-state-routing/`](link-state-routing/)): Implementation of Dijkstra’s Shortest Path First (SPF) algorithm computing optimal routing tables across complex network topologies.

---

## 🛠️ Compilation & Execution

### System Requirements
- Linux (Ubuntu, Debian, Fedora, Arch) or macOS with POSIX-compliant C compiler (`gcc` or `clang`).
- Windows users should run inside WSL (Windows Subsystem for Linux) or a Linux VM to ensure POSIX socket headers (`<sys/socket.h>`, `<arpa/inet.h>`) are available.

---

### Step-by-Step Running Guide

#### Example 1: TCP Client-Server
Open two separate terminal windows:

```bash
# Terminal 1 (Start Server):
cd tcp
gcc server.c -o server
./server

# Terminal 2 (Start Client):
cd tcp
gcc client.c -o client
./client
```

#### Example 2: Sliding Window Protocol (Go-Back-N)
```bash
# Terminal 1:
cd "sliding window protocol/gobackn"
gcc server.c -o gbn_server
./gbn_server

# Terminal 2:
cd "sliding window protocol/gobackn"
gcc client.c -o gbn_client
./gbn_client
```

#### Example 3: Leaky Bucket Traffic Shaper
```bash
cd leaky-bucket
gcc leakybucketclg.c -o leaky_bucket
./leaky_bucket
```

---

## 📡 Sockets Lifecycle Flowchart

```
       TCP Server                              TCP Client
   ┌────────────────┐                      ┌────────────────┐
   │ socket()       │                      │ socket()       │
   ├────────────────┤                      └──────┬─────────┘
   │ bind()         │                             │
   ├────────────────┤                             │
   │ listen()       │                             │
   ├────────────────┤       SYN Packet            │
   │ accept()       │ ◄─────────────────────────  │ connect()
   ├────────────────┤      SYN-ACK Packet         │
   │ [Blocks/Waits] │ ──────────────────────────► │
   ├────────────────┤                             ├────────────────┤
   │ read() / recv()│ ◄────── Data Request ───────│ write()/send() │
   ├────────────────┤                             ├────────────────┤
   │ write()/send() │ ────── Data Response ─────► │ read() / recv()│
   ├────────────────┤                             ├────────────────┤
   │ close()        │ ◄────── FIN / RST ───────── │ close()        │
   └────────────────┘                             └────────────────┘
```

---

## 📄 License

Distributed under the [MIT License](LICENSE). Authored by [Akhil Binu](https://akhilbinu.in/).
