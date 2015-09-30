#include "inet.h"
#define bufsize 1024

void menu(int new_sockfd, char buffer[]);

struct member
{
    char id[bufsize+1];
    char password[bufsize+1];
}m[50];

struct booking
{
char id[bufsize+1];
char history[bufsize+1];
}b[50];

void load_password()
{
	int index = 0;
	FILE * fp;

	fp = fopen ("Members.txt","r+");
	if (fp == NULL)
	{
		fp = fopen ("Members.txt","w+");
	    	fclose(fp);
	}
	for (index = 0; index < 50; index++)
		fscanf(fp,"%s %s", m[index].id, m[index].password);
 	fclose(fp);
}

void login(int new_sockfd)
{
	int index,s = 0;
	char password[bufsize+1],id[bufsize+1],buffer[bufsize+1],u_id[bufsize];
	FILE *fp;

	recv(new_sockfd,id, bufsize,0);
	recv(new_sockfd,password, bufsize,0);

	for(index=0;index<50;index++)
	{

		if(strcmp(m[index].id,id)==0 && strcmp(m[index].password,password)==0)
		{

			send(new_sockfd,"LogIn Success",bufsize,0);
			bzero(buffer,sizeof(buffer));
			strcpy(buffer,m[index].id);
			fp=fopen("Booking.txt","w");
			fprintf(fp,"%s \t",buffer);
			fclose(fp);
			
			send(new_sockfd,buffer,bufsize,0);
			bzero(buffer,sizeof(buffer));
			break;
		}
	}
	if(strcmp(m[index].id,id)!=0 && strcmp(m[index].password,password)!=0)
	{

		send(new_sockfd,"LogIn failed",bufsize,0);
		exit(0);
	}
return u_id;
}

void signup(int new_sockfd, char buffer[])
{
	char password[bufsize+1],id[bufsize+1],i[50],p[50];
	FILE *fp;
	fp = fopen("Members.txt","a+");
	recv(new_sockfd, id, bufsize,0);
	recv(new_sockfd, password, bufsize,0);
	fprintf(fp,"%s %s ", id, password);
	fclose(fp);
}

void roster(){
printf("jadual\n");
}

void menu(int new_sockfd, char buffer[])
{
	int choice;
	recv(new_sockfd,buffer, bufsize,0);
	choice = atoi(buffer);
	switch(choice)
	{
		case 1:
		load_password();
		login(new_sockfd);
		break;
		case 2:
		signup(new_sockfd,buffer);
		menu(new_sockfd, buffer);
		break;
case 3:
roster();
break;
		case 4:
		printf("\n\n\nClient disconnected from server...");
		exit(0);
		break;
		default:
		menu(new_sockfd, buffer);
		break;
	}
}

main()
{
	int sockfd,new_sockfd,clilen,index;
	char buffer[bufsize+1],id[bufsize+1],password[bufsize+1],u_id[bufsize+1];
	struct sockaddr_in serv_addr,cli_addr;
	FILE *fp;

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("Server: socket() error\n");
		exit(1);
	}
printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf("x Assignment TCP/IP : Lecturer Dr. Anang Hudaya Muhammad Amin\tx\n");
printf("x Di sediakan oleh:\t\t\t\t\t\tx\n");
printf("x Azihanafi bin Mohd Dakir\t1111115003\t\t\tx\n");
printf("x Mohamad Thaqif bin Jamaludin\t1112701034\t\t\tx");
printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf("\nxxxxxxxxxxxxxxxxx SELAMAT DATANG KE SERVER xxxxxxxxxxxxxx\n");
printf("x\t\t\t \t\t\t\tx\n");
	printf("x\t\tKejohanan Pencak Silat PSSGM\t\tx\n");
printf("x\t\t\t \t\t\t\tx\n");
printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

	bzero((char*)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//127.0.0.1
	serv_addr.sin_port=htons(SERV_TCP_PORT);

	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
		perror("Server : bind() error\n");
	printf("\nWaiting for connection... [bind]\n");

	listen(sockfd,5);

	for(;;)
	{
		clilen=sizeof(cli_addr);
		new_sockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);

		if(fork()==0)
		{
			close(sockfd);
			if(new_sockfd>0)
				printf("\nClient connected now.\n");

			menu(new_sockfd, buffer);
			bzero(buffer,sizeof(buffer));
			
				do{

				send(new_sockfd,"\n***Selamat Datang ke Sistem Tempahan Tiket Kejohanan Pencak Silat PSSGM***\n",bufsize,0);

				bzero(buffer,sizeof(buffer));
				recv(new_sockfd,buffer,bufsize,0);

				printf("Received from client : \n %s",buffer);
				
				fp=fopen("Booking.txt","a");
				fprintf(fp,"%s\n",buffer);
				fclose(fp);
				printf("\nSending confirmation on booking to client...");
				send(new_sockfd,buffer,bufsize,0);
				

				bzero(buffer,sizeof(buffer));
				recv(new_sockfd,buffer,bufsize,0);
				printf("\n\n\nClient disconnected from server...");
			}while(strcmp(buffer,"/q"));
			exit(0);
		}
		close(new_sockfd);
	}
	close(sockfd);
}
