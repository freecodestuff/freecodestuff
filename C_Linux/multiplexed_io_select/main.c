#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENT    32
#define SERVER_PORT_NUM     2000 

struct test_struct{

	unsigned int a;
	unsigned int b;
};
struct res_struct{
	unsigned int c;
} ;

char buff[1024];

int monitoring_fd_set[32];

static void
init_monitor_fd_set(){

	int i = 0;
	for(; i < MAX_CLIENT; i++)
		monitoring_fd_set[i] = -1;
}

static void 
add_monitoring_fd_set(int soc_fd){

	int i = 0;
	for(; i < MAX_CLIENT; i++){

		if(monitoring_fd_set[i] != -1)
			continue;   
		monitoring_fd_set[i] = soc_fd;
		break;
	}
}

static void
remove_monitoring_fd_set(int soc_fd){

	int i = 0;
	for(; i < MAX_CLIENT; i++){

		if(monitoring_fd_set[i] != soc_fd)
			continue;

		monitoring_fd_set[i] = -1;
		break;
	}
}

static void
re_init_fds(fd_set *fd_set){

	FD_ZERO(fd_set);
	int i = 0;
	for(; i < MAX_CLIENT; i++){
		if(monitoring_fd_set[i] != -1){
			FD_SET(monitoring_fd_set[i], fd_set);
		}
	}
}

static int 
max_fd(){

	int i = 0;
	int max = -1;

	for(; i < MAX_CLIENT; i++){
		if(monitoring_fd_set[i] > max)
			max = monitoring_fd_set[i];
	}

	return max;
}

void tcp_server(){

	int master_sock_fd = 0, recv_bytes = 0, addr_len = 0, opt = 1;

	int commu_socket_fd = 0;
	fd_set read_fds;             
	struct sockaddr_in srv_addr, cli_addr;

	init_monitor_fd_set();

	if ((master_sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP )) == -1)
	{
		printf("socket creation failed\n");
		exit(1);
	}

	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = SERVER_PORT_NUM;
	srv_addr.sin_addr.s_addr = INADDR_ANY; 
	addr_len = sizeof(struct sockaddr);


	if (bind(master_sock_fd, (struct sockaddr *)&srv_addr, sizeof(struct sockaddr)) == -1)
	{
		printf("bind failed\n");
		return;
	}

	if (listen(master_sock_fd, 5)<0)  
	{
		printf("listen failed\n");
		return;
	}

	add_monitoring_fd_set(master_sock_fd);

	while(1){

		re_init_fds(&read_fds);               

		select(max_fd() + 1, &read_fds, NULL, NULL, NULL); 

		if (FD_ISSET(master_sock_fd, &read_fds))
		{            
			commu_socket_fd = accept(master_sock_fd, (struct sockaddr *)&cli_addr, &addr_len);
			if(commu_socket_fd < 0){
				printf("accept error : errno = %d\n", errno);
				exit(0);
			}
			add_monitoring_fd_set(commu_socket_fd); 
		}
		else
		{

			int i = 0, commu_socket_fd = -1;
			for(; i < MAX_CLIENT; i++){


				if(FD_ISSET(monitoring_fd_set[i], &read_fds)){

					commu_socket_fd = monitoring_fd_set[i];

					memset(buff, 0, sizeof(buff));
					recv_bytes = recvfrom(commu_socket_fd, (char *)buff, sizeof(buff), 0, (struct sockaddr *)&cli_addr, &addr_len);
					if(recv_bytes == 0){
						close(commu_socket_fd);
						remove_monitoring_fd_set(commu_socket_fd);
						break;

					}


					struct test_struct *client_data = (struct test_struct *)buff;
					if(client_data->a == 0 && client_data->b ==0){

						close(commu_socket_fd);
						remove_monitoring_fd_set(commu_socket_fd);
						printf("Server closes client connection : %s:%u\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
						break;
					}

					struct res_struct result;
					result.c = client_data->a + client_data->b;
					recv_bytes = sendto(commu_socket_fd, (char *)&result, sizeof(struct res_struct), 0,
							(struct sockaddr *)&cli_addr, sizeof(struct sockaddr));
				}
			}
		}

	}   
}

int
main(int argc, char **argv){
	tcp_server();
	return 0;
}