{\rtf1\ansi\ansicpg1252\cocoartf1187\cocoasubrtf400
{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fnil\fcharset0 HelveticaNeue;}
{\colortbl;\red255\green255\blue255;\red38\green38\blue38;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural

\f0\fs24 \cf0 # CPP-eth0\
<h3>Assignment TCP/IP : Lecturer Dr. Anang</h3>\
C++ code to find eth0 in linux\
\
<h2> Group Member </h2>\
1. Azihanafi Mohd Dakir 1111115003\
2. Mohamad Thaqif bin Jamaludin 1112701034\
\
<h2> Task That Have Been Carried Out </h2>\

\f1 \cf2 \cb3 Development of File Repository System using Client-Server TCP/IP Model\

\f0 \cf0 \cb1 \
\
<h2>Work Distribution</h2>\
All work distribution are equally divided among members\
\
<h2>c++ Code on server (server.c)</h2>\
#include "inet.h"\
#define bufsize 1024\
\
void menu(int new_sockfd, char buffer[]);\
\
struct member\
\{\
    char id[bufsize+1];\
    char password[bufsize+1];\
\}m[50];\
\
struct booking\
\{\
char id[bufsize+1];\
char history[bufsize+1];\
\}b[50];\
\
void load_password()\
\{\
	int index = 0;\
	FILE * fp;\
\
	fp = fopen ("Members.txt","r+");\
	if (fp == NULL)\
	\{\
		fp = fopen ("Members.txt","w+");\
	    	fclose(fp);\
	\}\
	for (index = 0; index < 50; index++)\
		fscanf(fp,"%s %s", m[index].id, m[index].password);\
 	fclose(fp);\
\}\
\
void login(int new_sockfd)\
\{\
	int index,s = 0;\
	char password[bufsize+1],id[bufsize+1],buffer[bufsize+1],u_id[bufsize];\
	FILE *fp;\
\
	recv(new_sockfd,id, bufsize,0);\
	recv(new_sockfd,password, bufsize,0);\
\
	for(index=0;index<50;index++)\
	\{\
\
		if(strcmp(m[index].id,id)==0 && strcmp(m[index].password,password)==0)\
		\{\
\
			send(new_sockfd,"LogIn Success",bufsize,0);\
			bzero(buffer,sizeof(buffer));\
			strcpy(buffer,m[index].id);\
			fp=fopen("Booking.txt","w");\
			fprintf(fp,"%s \\t",buffer);\
			fclose(fp);\
			\
			send(new_sockfd,buffer,bufsize,0);\
			bzero(buffer,sizeof(buffer));\
			break;\
		\}\
	\}\
	if(strcmp(m[index].id,id)!=0 && strcmp(m[index].password,password)!=0)\
	\{\
\
		send(new_sockfd,"LogIn failed",bufsize,0);\
		exit(0);\
	\}\
return u_id;\
\}\
\
void signup(int new_sockfd, char buffer[])\
\{\
	char password[bufsize+1],id[bufsize+1],i[50],p[50];\
	FILE *fp;\
	fp = fopen("Members.txt","a+");\
	recv(new_sockfd, id, bufsize,0);\
	recv(new_sockfd, password, bufsize,0);\
	fprintf(fp,"%s %s ", id, password);\
	fclose(fp);\
\}\
\
void roster()\{\
printf("jadual\\n");\
\}\
\
void menu(int new_sockfd, char buffer[])\
\{\
	int choice;\
	recv(new_sockfd,buffer, bufsize,0);\
	choice = atoi(buffer);\
	switch(choice)\
	\{\
		case 1:\
		load_password();\
		login(new_sockfd);\
		break;\
\
		case 2:\
		signup(new_sockfd,buffer);\
		menu(new_sockfd, buffer);\
		break;\
\
		case 3:\
		roster();\
		break;\
\
		case 4:\
		printf("\\n\\n\\nClient disconnected from server...");\
		exit(0);\
		break;\
\
		default:\
		menu(new_sockfd, buffer);\
		break;\
	\}\
\}\
\
main()\
\{\
	int sockfd,new_sockfd,clilen,index;\
	char buffer[bufsize+1],id[bufsize+1],password[bufsize+1],u_id[bufsize+1];\
	struct sockaddr_in serv_addr,cli_addr;\
	FILE *fp;\
\
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)\
	\{\
		perror("Server: socket() error\\n");\
		exit(1);\
	\}\
	printf("\\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
	printf("x Assignment TCP/IP : Lecturer Dr. Anang Hudaya Muhammad Amin\\tx\\n");\
	printf("x Di sediakan oleh:\\t\\t\\t\\t\\t\\tx\\n");\
	printf("x Azihanafi bin Mohd Dakir\\t1111115003\\t\\t\\tx\\n");\
	printf("x Mohamad Thaqif bin Jamaludin\\t1112701034\\t\\t\\tx");\
	printf("\\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
	printf("\\nxxxxxxxxxxxxxxxxx SELAMAT DATANG KE SERVER xxxxxxxxxxxxxx\\n");\
	printf("x\\t\\t\\t \\t\\t\\t\\tx\\n");\
	printf("x\\t\\tKejohanan Pencak Silat PSSGM\\t\\tx\\n");\
	printf("x\\t\\t\\t \\t\\t\\t\\tx\\n");\
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
\
	bzero((char*)&serv_addr,sizeof(serv_addr));\
	serv_addr.sin_family=AF_INET;\
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//127.0.0.1\
	serv_addr.sin_port=htons(SERV_TCP_PORT);\
\
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)\
		perror("Server : bind() error\\n");\
	printf("\\nWaiting for connection... [bind]\\n");\
\
	listen(sockfd,5);\
\
	for(;;)\
	\{\
		clilen=sizeof(cli_addr);\
		new_sockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);\
\
		if(fork()==0)\
		\{\
			close(sockfd);\
			if(new_sockfd>0)\
				printf("\\nClient connected now.\\n");\
\
			menu(new_sockfd, buffer);\
			bzero(buffer,sizeof(buffer));\
			\
				do\{\
\
				send(new_sockfd,"\\n***Selamat Datang ke Sistem Tempahan Tiket Kejohanan Pencak Silat PSSGM***\\n",bufsize,0);\
\
				bzero(buffer,sizeof(buffer));\
				recv(new_sockfd,buffer,bufsize,0);\
\
				printf("Received from client : \\n %s",buffer);\
				\
				fp=fopen("Booking.txt","a");\
				fprintf(fp,"%s\\n",buffer);\
				fclose(fp);\
				printf("\\nSending confirmation on booking to client...");\
				send(new_sockfd,buffer,bufsize,0);\
				\
\
				bzero(buffer,sizeof(buffer));\
				recv(new_sockfd,buffer,bufsize,0);\
				printf("\\n\\n\\nClient disconnected from server...");\
			\}while(strcmp(buffer,"/q"));\
			exit(0);\
		\}\
		close(new_sockfd);\
	\}\
	close(sockfd);\
\}\
\
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural
\cf0 <h2>c++ Code on client (client.c)</h2>\
#include "inet.h"\
#define bufsize 1024\
\
void login(int sockfd, char buffer[])\
\{\
\
	printf("\\n\\n\\t\\tEnter User ID\\t: ");\
	gets(buffer);\
	send(sockfd,buffer,bufsize,0);\
	bzero(buffer,sizeof(buffer));\
	printf("\\n\\t\\tEnter password\\t: ");\
	gets(buffer);\
	send(sockfd,buffer,bufsize,0);\
	bzero(buffer,sizeof(buffer));\
	recv(sockfd,buffer, bufsize,0);\
\
	if(strcmp(buffer,"LogIn failed") == 0)\
	\{\
		printf("\\nID / Kata laluan SALAH!\\n");\
		printf("\\nSistem akan kembali ke halaman utama dalam 3 saat..\\n\\n");\
		sleep(3);\
		system("clear");\
		menu();		\
		\
	\}\
	bzero(buffer,sizeof(buffer));\
	recv(sockfd,buffer,bufsize,0);\
	printf("\\nLog masuk Berjaya...\\n\\n");\
\
	printf("\\tSelamat Datang %s!       Status : Pelanggan",buffer);\
	bzero(buffer,sizeof(buffer));\
\
\}\
\
\
void signup(int sockfd, char buffer[])\
\{\
	printf("\\n\\n\\t\\tMasukkan ID\\t: ");\
	scanf("%s", buffer);\
	send(sockfd,buffer,bufsize,0);\
	bzero(buffer,sizeof(buffer));\
	printf("\\n\\t\\tMasukkan kata laluan\\t: ");\
	scanf("%s", buffer);\
	send(sockfd,buffer,bufsize,0);\
	bzero(buffer,sizeof(buffer));\
	printf("Pendaftaran Berjaya.. \\nRedirecting to login page\\n");\
	sleep(3);\
\}\
\
\
void menu(int sockfd, char buffer[])\
\{\
	int choice;\
\
		printf("\\n   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
		printf("   x Assignment TCP/IP : Lecturer Dr. Anang Hudaya Muhammad Amin  x\\n");\
		printf("   x Di sediakan oleh:\\t\\t\\t\\t\\t\\t  x\\n");\
		printf("   x Azihanafi bin Mohd Dakir\\t1111115003\\t\\t\\t  x\\n");\
		printf("   x Mohamad Thaqif bin Jamaludin\\t1112701034\\t\\t  x");\
		printf("\\n   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
		printf("\\n xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
		printf(" x\\t\\t\\t\\t\\t\\t\\t\\t\\t x\\n");\
		printf(" x SELAMAT DATANG KE SISTEM TEMPAHAN TIKET KEJOHANAN PENCAK SILAT PSSGM\\t x\\n");\
		printf(" x\\t\\t\\t\\t\\t\\t\\t\\t\\t x\\n");\
		printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
		printf(" x\\t\\t\\t\\t\\t\\t\\t\\t\\t x\\n");\
		printf(" x	\\t1. Log Masuk\\t\\t\\t\\t\\t\\t x\\n");\
		printf(" x	\\t2. Pendaftaran Baru\\t\\t\\t\\t\\t x\\n");\
		printf(" x	\\t3. Jadual Kejohanan Pencak Silat PSSGM\\t\\t\\t x\\n");\
		printf(" x	\\t3. Keluar\\t\\t\\t\\t\\t\\t x\\n");\
		printf(" x\\t\\t\\t\\t\\t\\t\\t\\t\\t x\\n");\
		printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
\
		printf("\\n\\tNo Pilihan: ");\
\
	gets(buffer);\
	choice = atoi(buffer);\
	switch(choice)\
	\{\
		case 1:\
			send(sockfd,buffer,bufsize,0);\
			bzero(buffer,sizeof(buffer));\
			login(sockfd, buffer);\
			bzero(buffer,sizeof(buffer));\
			mem_menu(sockfd,buffer);\
		break;\
\
		case 2:\
			send(sockfd,buffer,bufsize,0);\
			bzero(buffer,sizeof(buffer));\
			signup(sockfd, buffer);\
			menu(sockfd,buffer);\
		break;\
\
		case 3:\
			system("clear");\
			roster();\
			printf("\\nTekan 'b' untuk kembali ke menu utama :");\
			gets(buffer);\
			system("clear");\
			menu(sockfd,buffer);\
			bzero(buffer,sizeof(buffer));\
			break;\
\
		case 4:\
			printf("\\n\\n***TERIMA KASIH KERANA MENGGUNAKAN SISTEM KAMI***\\n\\n");\
			exit(0);\
		break;\
\
		default:\
			system("clear");\
			menu(sockfd,buffer);\
		break;\
	\}\
\}\
\
void mem_menu(int sockfd, char buffer[])\
\{\
	int choice;\
		printf("\\n\\t+++++++++++++++ Menu Pengguna ++++++++++++++");\
		printf("\\n\\t+\\t\\t\\t\\t\\t   +\\n");\
		printf("\\t+  1. Jadual Kejohanan Pencak Silat PSSGM  +\\n");\
		printf("\\t+  2. Tempah sekarang\\t\\t\\t   +\\n");\
		printf("\\t+  3. Keluar\\t\\t\\t\\t   +\\n");\
		printf("\\t+\\t\\t\\t\\t\\t   +\\n");\
		printf("\\t++++++++++++++++++++++++++++++++++++++++++++\\n");\
		printf("\\n\\tNo Pilihan: ");\
\
	gets(buffer);\
	choice = atoi(buffer);\
	switch(choice)\
	\{\
		case 1:\
		system("clear");\
		roster();\
		mem_menu(sockfd,buffer);\
		bzero(buffer,sizeof(buffer));\
		break;\
\
		case 2:\
		break;\
\
		case 3:\
		exit(0);\
		break;\
\
		default:\
		system("clear");\
		mem_menu(sockfd,buffer);\
		break;\
	\
	\}\
\}\
\
void roster()\{\
		printf("\\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
		printf("x\\t\\t\\t\\t\\t\\t\\t\\t\\tx");\
		printf("\\nx\\t\\tJadual Kejohanan Pencak Silat PSSGM\\t\\t\\tx\\n");\
		printf("x   -----------------------------------------------------------------\\tx\\n");\
		printf("x   | 1. Male\\t - Featherweight class\\t(28 Sept 2015 - 10.00am)    |\\tx\\n");\
		printf("x   | 2. Male\\t - Bantamweight class\\t(28 Sept 2015 - 10.30am)    |\\tx\\n");\
		printf("x   | 3. Female\\t - Strawweight class\\t(28 Sept 2015 - 11.00am)    |\\tx\\n");\
		printf("x   | 4. Male\\t - Heavyweight class\\t(28 Sept 2015 - 11.30am)    |\\tx\\n");\
		printf("x   | 5. Female\\t - Bantamweight class\\t(28 Sept 2015 - 12.00pm)    |\\tx\\n");\
		printf("x   -----------------------------------------------------------------\\tx\\n");\
		printf("x\\t\\t\\t\\t\\t\\t\\t\\t\\tx");\
		printf("\\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
\
\}\
\
void ring_seat()\{\
		printf("        _________________________________________\\n");\
		printf("     __|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__\\n");\
		printf("  __|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__\\n");\
		printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\\n");\
		printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\\n");\
		printf(" |__|__|__|                [a1]               			|__|__|__|\\n");\
		printf(" |__|__|__|          --------------------      			|__|__|__|\\n");\
		printf(" |__|__|__|          |                        |     		|__|__|__|\\n");\
		printf(" |__|__|__|          |                        |      		|__|__|__|\\n");\
		printf(" |__|__|__|[b2]    | [Gelanggang]  | 		  [b1]|__|__|__|\\n");\
		printf(" |__|__|__|          |                        |	 		|__|__|__|\\n");\
		printf(" |__|__|__|          |                        |       		|__|__|__|\\n");\
		printf(" |__|__|__|          -------------------        			|__|__|__|\\n");\
		printf(" |__|__|__|________________[a2]__________|__|__|__|\\n");\
		printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\\n");\
		printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\\n");\
		printf("    |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\\n");\
		printf("       |__|__|__|__|__|__|__|__|__|__|__|__|__|__|\\n");\
\}\
\
main(int argc,char *argv[])\
\{\
	int sockfd,qty,match_no,total;\
	char buffer[bufsize],seat[bufsize],num_of_seat[bufsize],match[bufsize],\
    	date[bufsize],time[bufsize];\
	struct sockaddr_in serv_addr;\
\
	sigset_t set1;\
	sigfillset (&set1);\
\
	if(argc <= 1)\
	\{\
		printf("Cara menggunakan : %s remoteIPaddress [contoh: ./client 127.0.0.1]\\n", argv[0]);exit(1); \}\
\
		bzero ( (char *) &serv_addr, sizeof(serv_addr) );\
		serv_addr.sin_family = AF_INET;\
		serv_addr.sin_port = htons (SERV_TCP_PORT);\
		inet_pton (AF_INET, argv[1], &serv_addr.sin_addr);\
\
		if( (sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0)\
		\{\
			perror("Client: connect() error\\n");\
			exit(1);\
		\}\
\
		if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)\
		\{\
			perror("Client: connect() error\\n");\
			exit(1);\
		\}\
\
		menu(sockfd,buffer);\
			\
			do\{\
			bzero(buffer,sizeof(buffer));			\
			recv(sockfd,buffer,bufsize,0);\
			puts(buffer);\
			bzero(buffer,sizeof(buffer));\
			printf("\\n-----------------------------------------------\\n");\
			printf("\\nLangkah3: Maklumat tempahan :\\n");\
			printf("\\nSila pilih acara Pencak Silat : \\n");\
			roster();\
\
			printf("\\nSila pilih No. acara Pencak Silat : ");\
			scanf("%d",&match_no);\
\
			if(match_no==1)\
			\{\
				strcpy(match,"1. Male - Featherweight class");\
				strcpy(date,"28 Sept 2015");\
				strcpy(time,"10.00 a.m");\
			\}\
			if(match_no==2)\
			\{\
				strcpy(match,"2. Male - Bantamweight class");\
				strcpy(date,"28 Sept 2015");\
				strcpy(time,"10.30 a.m");\
			\}\
			if(match_no==3)\
			\{\
				strcpy(match,"3. Female - Strawweight class ");\
				strcpy(date,"28 Sept 2015");\
				strcpy(time,"11.00 a.m");\
			\}\
			if(match_no==4)\
			\{\
				strcpy(match,"4. Male - Heavyweight class ");\
				strcpy(date,"28 Sept 2015");\
				strcpy(time,"11.30 a.m");\
			\}\
			if(match_no==5)\
			\{\
				strcpy(match,"5. Female - Bantamweight class");\
				strcpy(date,"28 Sept 2015");\
				strcpy(time,"12.00 p.m");\
			\}\
\
			printf("\\nAnda memilih No. %s fight\\n",match);\
			printf("NOTA: Sila tunggu sebentar...\\n");\
\
			sleep(3);\
			sigprocmask(SIG_SETMASK, &set1, (void *)0);\
			sleep(3);\
\
			ring_seat();\
\
			printf("\\nPilih tempat duduk(a1,a2,b1,b2), Harga setiap tempat duduk RM10 : ");\
			scanf("%s",&seat);\
\
			printf("\\nQuantiti tempat duduk : ");\
			scanf("%d",&qty);\
			sprintf(num_of_seat,"%d",qty);\
			strcat(seat," dan quantiti ");\
			strcat(seat,num_of_seat);\
			printf("\\nAnda memilih: %s",seat);\
			sleep(3);\
\
			printf("\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n");\
\
			printf("Langkah 4 : Pengesahan maklumat tempahan\\n\\n");\
			printf("Pertandingan : %s\\n",match);\
			printf("Tempat duduk  : %s\\n\\n",seat);\
			printf("NOTA: **Sila tekan CTRL[C] jika ingin membatalkan tempahan/keluar\\n");\
			sleep(3);\
			sigprocmask(SIG_SETMASK, &set1, (void *)0);\
			printf("**Di larang keluar/exit sistem.. \\n\\n");\
			sleep(3);\
\
			printf("Maklumat dihantar ke server...\\n");\
\
			strcat(match,"  ");\
			strcat(match,seat);			\
			send(sockfd,match,bufsize,0);\
			bzero(match,sizeof(match));\
			recv(sockfd,match,bufsize,0);\
\
			printf("Maklumat diterima : \\n");\
			printf("%s\\n\\n",match);\
\
			total=qty*10;\
\
			printf("\\n\\n\\n\\n\\n\\n\\n\\n\\n\\nSila tunggu tiket dicetak . . .\\n");\
							printf("\\n_________________________________________________________________________\\n\\n");\
			printf("\\t\\tKEJOHANAN PENCAK SILAT PSSGM RESIT \\n");\
			printf("-------------------------------------------------------------------------\\n");\
			printf("  Pertandingan\\t: %s\\n",match);\
			printf("  Tarikh\\t: %s\\n",date);\
			printf("  Masa\\t\\t: %s\\n",time);\
			printf("  Jumlah\\t: RM%d",total);\
			printf("\\n\\n_________________________________________________________________________\\n\\n");\
			sleep(5);\
\
\
			printf("\\nSila tekan /q untuk tamatkan perkhidmatan : \\n");\
			bzero(buffer,sizeof(buffer));\
			scanf("%s",&buffer);\
			send(sockfd,buffer,bufsize,0);\
			sigprocmask(SIG_UNBLOCK, &set1, (void *)0);\
\
		printf("\\n\\n\\n***TERIMA KASIH KERANA MENGGUNAKAN SYSTEM KAMI***\\n\\n");\
		printf("\\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
		printf("x Assignment TCP/IP : Lecturer Dr. Anang Hudaya Muhammad Amin\\tx\\n");\
		printf("x Di sediakan oleh:\\t\\t\\t\\t\\t\\tx\\n");\
		printf("x Azihanafi bin Mohd Dakir\\t1111115003\\t\\t\\tx\\n");\
		printf("x Mohamad Thaqif bin Jamaludin\\t1112701034\\t\\t\\tx");\
		printf("\\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\n");\
exit(0);\
		\}while(strcmp(buffer,"/q"));\
\
	close (sockfd);\
\};\
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural
\cf0 # CPP-eth0\
<h2>Output result</h2>\
\
![server.c](https://cloud.githubusercontent.com/assets/13751130/10186143/5f8a3b2e-6781-11e5-91d9-c9f7e17f66c9.png)\
\
![client.c](https://cloud.githubusercontent.com/assets/13751130/10186141/5f2fa5c4-6781-11e5-856d-71157c28fa9e.png)\
\
![user menu](https://cloud.githubusercontent.com/assets/13751130/10186146/5fc0fef2-6781-11e5-8093-1be24240e14d.png)\
\
![jadual acara](https://cloud.githubusercontent.com/assets/13751130/10186148/600028a2-6781-11e5-8947-589b2ae9bf39.png)\
\
![seat arrangement](https://cloud.githubusercontent.com/assets/13751130/10186149/60046714-6781-11e5-9c8e-4475afbb7a25.png)\
\
![Pengesahan](https://cloud.githubusercontent.com/assets/13751130/10186150/600bd468-6781-11e5-9501-6c6abd8a6258.png)\
\
![Resit](https://cloud.githubusercontent.com/assets/13751130/10186143/5f8a3b2e-6781-11e5-91d9-c9f7e17f66c9.png)}