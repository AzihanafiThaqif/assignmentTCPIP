#include "inet.h"
#define bufsize 1024

void login(int sockfd, char buffer[])
{

	printf("\n\n\t\tEnter User ID\t: ");
	gets(buffer);
	send(sockfd,buffer,bufsize,0);
	bzero(buffer,sizeof(buffer));
	printf("\n\t\tEnter password\t: ");
	gets(buffer);
	send(sockfd,buffer,bufsize,0);
	bzero(buffer,sizeof(buffer));
	recv(sockfd,buffer, bufsize,0);

	if(strcmp(buffer,"LogIn failed") == 0)
	{
		printf("\nID / Kata laluan SALAH!\n");
printf("\nSistem akan kembali ke halaman utama dalam 3 saat..\n\n");
		sleep(3);
system("clear");
menu();		
		
	}
	bzero(buffer,sizeof(buffer));
	recv(sockfd,buffer,bufsize,0);
	printf("\nLog masuk Berjaya...\n\n");

	printf("\tSelamat Datang %s!       Status : Pelanggan",buffer);
	bzero(buffer,sizeof(buffer));

}


void signup(int sockfd, char buffer[])
{
	printf("\n\n\t\tMasukkan ID\t: ");
	scanf("%s", buffer);
	send(sockfd,buffer,bufsize,0);
	bzero(buffer,sizeof(buffer));
	printf("\n\t\tMasukkan kata laluan\t: ");
	scanf("%s", buffer);
	send(sockfd,buffer,bufsize,0);
	bzero(buffer,sizeof(buffer));
	printf("Pendaftaran Berjaya.. \nRedirecting to login page\n");
	sleep(3);
}


void menu(int sockfd, char buffer[])
{
	int choice;

printf("\n   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf("   x Assignment TCP/IP : Lecturer Dr. Anang Hudaya Muhammad Amin  x\n");
printf("   x Di sediakan oleh:\t\t\t\t\t\t  x\n");
printf("   x Azihanafi bin Mohd Dakir\t1111115003\t\t\t  x\n");
printf("   x Mohamad Thaqif bin Jamaludin\t1112701034\t\t  x");
printf("\n   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printf("\n xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf(" x\t\t\t\t\t\t\t\t\t x\n");
printf(" x SELAMAT DATANG KE SISTEM TEMPAHAN TIKET KEJOHANAN PENCAK SILAT PSSGM\t x\n");
printf(" x\t\t\t\t\t\t\t\t\t x\n");
printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf(" x\t\t\t\t\t\t\t\t\t x\n");
	printf(" x	\t1. Log Masuk\t\t\t\t\t\t x\n");
	printf(" x	\t2. Pendaftaran Baru\t\t\t\t\t x\n");
printf(" x	\t3. Jadual Kejohanan Pencak Silat PSSGM\t\t\t x\n");
	printf(" x	\t3. Keluar\t\t\t\t\t\t x\n");
printf(" x\t\t\t\t\t\t\t\t\t x\n");
	printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

printf("\n\tNo Pilihan: ");
	gets(buffer);
	choice = atoi(buffer);
	switch(choice)
	{
		case 1:
			send(sockfd,buffer,bufsize,0);
			bzero(buffer,sizeof(buffer));
			login(sockfd, buffer);
			bzero(buffer,sizeof(buffer));
			mem_menu(sockfd,buffer);
		break;

		case 2:
			send(sockfd,buffer,bufsize,0);
			bzero(buffer,sizeof(buffer));
			signup(sockfd, buffer);
			menu(sockfd,buffer);
		break;
		case 3:
			system("clear");
			roster();
			printf("\nTekan 'b' untuk kembali ke menu utama :");
			gets(buffer);
			system("clear");
			menu(sockfd,buffer);
			bzero(buffer,sizeof(buffer));

			break;
		case 4:
			printf("\n\n***TERIMA KASIH KERANA MENGGUNAKAN SISTEM KAMI***\n\n");
			exit(0);
		break;

		default:
			system("clear");
			menu(sockfd,buffer);
		break;
	}
}

void mem_menu(int sockfd, char buffer[])
{
	int choice;
	printf("\n\t+++++++++++++++ Menu Pengguna ++++++++++++++");
printf("\n\t+\t\t\t\t\t   +\n");
	printf("\t+  1. Jadual Kejohanan Pencak Silat PSSGM  +\n");
	printf("\t+  2. Tempah sekarang\t\t\t   +\n");
	printf("\t+  3. Keluar\t\t\t\t   +\n");
printf("\t+\t\t\t\t\t   +\n");
	printf("\t++++++++++++++++++++++++++++++++++++++++++++\n");

	printf("\n\tNo Pilihan: ");
	gets(buffer);
	choice = atoi(buffer);
	switch(choice)
	{
		case 1:
system("clear");
		roster();
		mem_menu(sockfd,buffer);
		bzero(buffer,sizeof(buffer));
		break;
		case 2:

		break;
		case 3:
		exit(0);

		break;
		default:
		system("clear");
		mem_menu(sockfd,buffer);
		break;
	
	}
}




//-------
void roster(){
printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf("x\t\t\t\t\t\t\t\t\tx");
printf("\nx\t\tJadual Kejohanan Pencak Silat PSSGM\t\t\tx\n");
printf("x   -----------------------------------------------------------------\tx\n");
printf("x   | 1. Male\t - Featherweight class\t(28 Sept 2015 - 10.00am)    |\tx\n");
printf("x   | 2. Male\t - Bantamweight class\t(28 Sept 2015 - 10.30am)    |\tx\n");
printf("x   | 3. Female\t - Strawweight class\t(28 Sept 2015 - 11.00am)    |\tx\n");
printf("x   | 4. Male\t - Heavyweight class\t(28 Sept 2015 - 11.30am)    |\tx\n");
printf("x   | 5. Female\t - Bantamweight class\t(28 Sept 2015 - 12.00pm)    |\tx\n");
printf("x   -----------------------------------------------------------------\tx\n");
printf("x\t\t\t\t\t\t\t\t\tx");
printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

}

void ring_seat(){
printf("        _________________________________________\n");
printf("     __|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__\n");
printf("  __|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__\n");
printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\n");
printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\n");
printf(" |__|__|__|                [a1]               |__|__|__|\n");
printf(" |__|__|__|        --------------------       |__|__|__|\n");
printf(" |__|__|__|        |                  |       |__|__|__|\n");
printf(" |__|__|__|        |                  |       |__|__|__|\n");
printf(" |__|__|__|[b2]    |   [Gelanggang]   |   [b1]|__|__|__|\n");
printf(" |__|__|__|        |                  |       |__|__|__|\n");
printf(" |__|__|__|        |                  |       |__|__|__|\n");
printf(" |__|__|__|        -------------------        |__|__|__|\n");
printf(" |__|__|__|________________[a2]_______________|__|__|__|\n");
printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\n");
printf(" |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\n");
printf("    |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|\n");
printf("       |__|__|__|__|__|__|__|__|__|__|__|__|__|__|\n");
}

main(int argc,char *argv[])
{
	int sockfd,qty,match_no,total;
	char buffer[bufsize],seat[bufsize],num_of_seat[bufsize],match[bufsize],
     date[bufsize],time[bufsize];
	struct sockaddr_in serv_addr;

	sigset_t set1;
	sigfillset (&set1);

	if(argc <= 1)
	{
		printf("Cara menggunakan : %s remoteIPaddress [contoh: ./client 127.0.0.1]\n", argv[0]);exit(1); }

		bzero ( (char *) &serv_addr, sizeof(serv_addr) );
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons (SERV_TCP_PORT);
		inet_pton (AF_INET, argv[1], &serv_addr.sin_addr);

		if( (sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0)
		{
			perror("Client: connect() error\n");
			exit(1);
		}

		if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		{
			perror("Client: connect() error\n");
			exit(1);
		}

		menu(sockfd,buffer);
			
			do{
			bzero(buffer,sizeof(buffer));			
			recv(sockfd,buffer,bufsize,0);
			puts(buffer);
			bzero(buffer,sizeof(buffer));
			printf("\n-----------------------------------------------\n");
			printf("\nLangkah3: Maklumat tempahan :\n");
			printf("\nSila pilih acara Pencak Silat : \n");
			roster();

			printf("\nSila pilih No. acara Pencak Silat : ");
			scanf("%d",&match_no);

			if(match_no==1)
			{
				strcpy(match,"1. Male - Featherweight class");
				strcpy(date,"28 Sept 2015");
				strcpy(time,"10.00 a.m");
			}
			if(match_no==2)
			{
				strcpy(match,"2. Male - Bantamweight class");
				strcpy(date,"28 Sept 2015");
				strcpy(time,"10.30 a.m");
			}
			if(match_no==3)
			{
				strcpy(match,"3. Female - Strawweight class ");
				strcpy(date,"28 Sept 2015");
				strcpy(time,"11.00 a.m");
			}
			if(match_no==4)
			{
				strcpy(match,"4. Male - Heavyweight class ");
				strcpy(date,"28 Sept 2015");
				strcpy(time,"11.30 a.m");
			}
			if(match_no==5)
			{
				strcpy(match,"5. Female - Bantamweight class");
				strcpy(date,"28 Sept 2015");
				strcpy(time,"12.00 p.m");
			}

			printf("\nAnda memilih No. %s fight\n",match);
printf("NOTA: Sila tunggu sebentar...\n");

			sleep(3);
			sigprocmask(SIG_SETMASK, &set1, (void *)0);
			sleep(3);

			ring_seat();

			printf("\nPilih tempat duduk(a1,a2,b1,b2), Harga setiap tempat duduk RM10 : ");
			scanf("%s",&seat);

			printf("\nQuantiti tempat duduk : ");
			scanf("%d",&qty);
			sprintf(num_of_seat,"%d",qty);
			strcat(seat," dan quantiti ");
			strcat(seat,num_of_seat);
			printf("\nAnda memilih: %s",seat);
			sleep(3);

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

			printf("Langkah 4 : Pengesahan maklumat tempahan\n\n");
			printf("Pertandingan : %s\n",match);
			printf("Tempat duduk  : %s\n\n",seat);
			printf("NOTA: **Sila tekan CTRL[C] jika ingin membatalkan tempahan/keluar\n");
			sleep(3);
			sigprocmask(SIG_SETMASK, &set1, (void *)0);
			printf("**Di larang keluar/exit sistem.. \n\n");
			sleep(3);

			printf("Maklumat dihantar ke server...\n");

			strcat(match,"  ");
			strcat(match,seat);			
			send(sockfd,match,bufsize,0);
			bzero(match,sizeof(match));
			recv(sockfd,match,bufsize,0);

			printf("Maklumat diterima : \n");
			printf("%s\n\n",match);

			total=qty*10;

			printf("\n\n\n\n\n\n\n\n\n\nSila tunggu tiket dicetak . . .\n");
			printf("\n_________________________________________________________________________\n\n");
			printf("\t\tKEJOHANAN PENCAK SILAT PSSGM RESIT \n");
			printf("-------------------------------------------------------------------------\n");
			printf("  Pertandingan\t: %s\n",match);
			printf("  Tarikh\t: %s\n",date);
			printf("  Masa\t\t: %s\n",time);
			printf("  Jumlah\t: RM%d",total);
			printf("\n\n_________________________________________________________________________\n\n");
			sleep(5);


			printf("\nSila tekan /q untuk tamatkan perkhidmatan : \n");
			bzero(buffer,sizeof(buffer));
			scanf("%s",&buffer);
			send(sockfd,buffer,bufsize,0);
			sigprocmask(SIG_UNBLOCK, &set1, (void *)0);
			printf("\n\n\n***TERIMA KASIH KERANA MENGGUNAKAN SYSTEM KAMI***\n\n");
printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
printf("x Assignment TCP/IP : Lecturer Dr. Anang Hudaya Muhammad Amin\tx\n");
printf("x Di sediakan oleh:\t\t\t\t\t\tx\n");
printf("x Azihanafi bin Mohd Dakir\t1111115003\t\t\tx\n");
printf("x Mohamad Thaqif bin Jamaludin\t1112701034\t\t\tx");
printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
exit(0);
		}while(strcmp(buffer,"/q"));

	close (sockfd);
};
