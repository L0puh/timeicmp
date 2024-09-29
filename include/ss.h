#ifndef SS_H
#define SS_H

#define ASSERT(res) { if (res < 0) exit_on_error(__FILE__, __func__, __LINE__); }

#define BUFFER_SIZE 4028
#define DATA_SIZE   1024

#include <strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

struct global {
   int server_running;
};

int init_client(char* ip);
int init_server(char* ip);

int parse_packet(char* buffer, size_t size);
int send_packet(int sockfd, char* data, size_t data_size, struct sockaddr_in serv_addr);
int recv_packet(int sockfd);

void exit_on_error(char* file, const char* func, int line);
unsigned short checksum(void *data, int len);

#endif
