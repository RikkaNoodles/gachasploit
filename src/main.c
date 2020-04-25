//Made by Gacha Exploit Enthusiasts
//Copyright 2020

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#if _WIN32
#else 
#include <unistd.h>
#endif 
#include <errno.h>
#include <string.h>
#if _WIN32
#include <winsock2.h>
#define bzero(s, n) memset((s), 0, (n))
#else 
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#include <sys/types.h>

//Macros
#define HOSTNAME "lunidev.com"

//Functions
int randomint(int min, int max) {
	srand(time(0));
	return (rand() % (max - min + 1)) + min;
}

char* concat(char* s1, char* s2) {
	char* result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

char* levelvars(int level) {
	char* lvars = "";
	if (level < 152) {
		int qcxpnum = 1;
		int twoamnt = level - 1;
		int oneamnt = 150 - (level - 1);
		for (int i = 0; i < twoamnt; i++) {
			size_t needednew = snprintf(NULL, 0, "&qc%i=2&xp%i=0", qcxpnum, qcxpnum);
			char* newstr = malloc(needednew + 1);
			sprintf(newstr, "&qc%i=2&xp%i=0", qcxpnum, qcxpnum);
			lvars = concat(lvars, newstr);
			free(newstr);
			qcxpnum++;
		}
		for (int i = 0; i < oneamnt; i++) {
			size_t needednew = snprintf(NULL, 0, "&qc%i=1&xp%i=0", qcxpnum, qcxpnum);
			char* newstr = malloc(needednew + 1);
			sprintf(newstr, "&qc%i=1&xp%i=0", qcxpnum, qcxpnum);
			lvars = concat(lvars, newstr);
			free(newstr);
			qcxpnum++;
		}
	}
	else {
		int qcnum = 1;
		for (int i = 0; i < 150; i++) {
			size_t needednew = snprintf(NULL, 0, "&qc%i=2", qcnum);
			char* newstr = malloc(needednew + 1);
			sprintf(newstr, "&qc%i=2", qcnum);
			lvars = concat(lvars, newstr);
			free(newstr);
			qcnum++;
		}
		level -= 151;
		int xpnum = 1;
		while (true) {
			if ((level - 7) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=41001100", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=41001100", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level -= 7;
			}
			else if ((level - 6) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=3101100", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=3101100", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level -= 6;
			}
			else if ((level - 5) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=1751100", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=1751100", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level -= 5;
			}
			else if ((level - 4) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=851100", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=851100", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level -= 4;
			}
			else if ((level - 3) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=351100", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=351100", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level -= 3;
			}
			else if ((level - 2) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=101100", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=101100", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level -= 2;
			}
			else if ((level - 1) > -1) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=6300", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=6300", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
				level--;
			}
			else {
				break;
			}
		}
		if (xpnum < 150) {
			for (int i = 0; i < (xpnum - 150); i++) {
				size_t needednew = snprintf(NULL, 0, "&xp%i=0", xpnum);
				char* newstr = malloc(needednew + 1);
				sprintf(newstr, "&xp%i=0", xpnum);
				lvars = concat(lvars, newstr);
				free(newstr);
				xpnum++;
			}
		}
	}
	return lvars;
}

int profilehack(int gems, int level) {
	int sockfd;
	struct hostent* he;
	struct sockaddr_in serv_addr;
	if ((he = gethostbyname(HOSTNAME)) != NULL) {
		if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) > -1) {
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_port = htons(80);
			serv_addr.sin_addr = *((struct in_addr*)he->h_addr);
			bzero(&(serv_addr.sin_zero), 8);
			if (connect(sockfd, (struct sockaddr*) & serv_addr, sizeof(struct sockaddr)) > -1) {
				int savecode = randomint(100000000, 999999999);
				char* levelstr = levelvars(level);
				char* reqbodytemp = "c56=%%2D1&c58=%%2D1&accessory1=0&other1=0&heightx1=2&c59=%%2D1&stance1=1&c60=%%2D1&shirt1=71&c61=%%2D1&sleeves1=31&hat1=0&c62=%%2D1&pants1=2&c63=%%2D1&belt1=0&c64=%%2D1&gloves1=30&c65=%%2D1&shoes1=1&c66=%%2D1&cape1=0&c67=%%2D1&scarf1=44&c68=%%2D1&wings1=0&c69=%%2D1&tail1=0&c70=%%2D1&weapon1=0&c71=%%2D1&backweapon1=0&c72=%%2D1&shield1=0&c73=%%2D1&eye1color1=30AAEE&c74=%%2D1&eye2color1=30AAEE&c75=%%2D1&pupil1color1=2A43AB&c76=%%2D1&pupil2color1=2A43AB&c77=%%2D1&glassescolor1=272727&c78=%%2D1&accessorycolor1=98CEFF&c79=%%2D1&hatcolor1=2A43AB&c80=%%2D1&othercolor1=30AAEE&c81=%%2D1&shirtcolor1=4C97D9&c82=%%2D1&sleevescolor1=4C97D9&c83=%%2D1&pantscolor1=353D4F&c84=%%2D1&beltcolor1=272727&c85=%%2D1&glovescolor1=272727&c86=%%2D1&shoescolor1=4C97D9&c87=%%2D1&capecolor1=2A43AB&c88=%%2D1&scarfcolor1=4C97D9&c89=%%2D1&c90=%%2D1&wingscolor1=434343&weaponcolor1=30AAEE&tailcolor1=434343&backweaponcolor1=8A8A8A&c91=%%2D1&c93=%%2D1&c92=%%2D1&c94=%%2D1&shieldcolor1=30AAEE&skincolor1=FFDCC6&c95=%%2D1&haircoloralt1=4C97D9&accessorycoloralt1=072C78&c96=%%2D1&glassescoloralt1=D4E4FF&hatcoloralt1=2A43AB&c97=%%2D1&c99=%%2D1&othercoloralt1=434343&c98=%%2D1&c100=%%2D1&c101=%%2D1&sleevescoloralt1=4C97D9&shirtcoloralt1=272727&pantscoloralt1=353D4F&c103=%%2D1&c102=%%2D1&c104=%%2D1&beltcoloralt1=434343&glovescoloralt1=30AAEE&c105=%%2D1&shoescoloralt1=353D4F&c106=%%2D1&capecoloralt1=30AAEE&c107=%%2D1&scarfcoloralt1=072C78&c108=%%2D1&wingscoloralt1=30AAEE&c109=%%2D1&tailcoloralt1=30AAEE&c110=%%2D1&weaponcoloralt1=D4E4FF&c111=%%2D1&backweaponcoloralt1=FFFFFF&c112=%%2D1&shieldcoloralt1=D4E4FF&c113=%%2D1&haircolorfade1=4A5A77&c114=%%2D1&haircoloracc1=272727&c115=%%2D1&c117=%%2D1&c116=%%2D1&c118=%%2D1&c119=%%2D1&c120=%%2D1&c121=%%2D1&c122=%%2D1&c123=%%2D1&c124=%%2D1&c125=%%2D1&c126=%%2D1&c127=%%2D1&c128=%%2D1&c129=%%2D1&c130=%%2D1&c132=%%2D1&c131=%%2D1&c133=%%2D1&c134=%%2D1&c135=%%2D1&c136=%%2D1&c137=%%2D1&c138=%%2D1&c139=%%2D1&c140=%%2D1&giftsclaimed=1&o1=%i&o2=0&o3=0&o4=0&o5=0&eyehigh1=1&o8=0&o7=874&o6=0&highscore7=0&highscore8=0&o9=0&highscore9=0&o10=0&highscore10=0&o11=0&highscore11=0&o12=5000&eyecam1=1&o13=0&highscore13=0&highscore12=0&highscore14=0&o15=0&highscore15=0&o14=0&o16=0&highscore16=0&o17=0&totalpulls=0&o18=0&o20=0&o19=0&o21=1&eyewink1=0&o23=0&o22=0&o24=0&o25=0&o26=0&o27=0&o28=0&o29=0&head1=1&o31=1&o30=%%2D1&o32=1&o33=1&o34=1&o35=1&o36=1&o37=1&chin1=1&o39=1&o38=1&o40=1&o41=1&o42=1&o44=1&o43=1&o45=1&o46=1&o47=1&o48=1&o49=1&o50=1&c1=%%2D1&c2=%%2D1&c3=%%2D1&c4=%%2D1&c5=%%2D1&c6=%%2D1&c7=%%2D1&c8=%%2D1&c9=%%2D1&c10=%%2D1&c11=%%2D1&c12=%%2D1&c13=%%2D1&c14=%%2D1&c15=%%2D1&c16=%%2D1&c17=%%2D1&c18=%%2D1&c19=%%2D1&c20=%%2D1&c21=%%2D1&c22=%%2D1&c23=%%2D1&c24=%%2D1&c25=%%2D1&c26=%%2D1&c27=%%2D1&c28=%%2D1&c29=%%2D1&c30=%%2D1&c31=%%2D1&c32=%%2D1&c33=%%2D1&c34=%%2D1&haircolor1=272727&c36=%%2D1&c35=%%2D1&c37=%%2D1&firsttime2=1&accountx=%i&c38=%%2D1&passx=Name&c39=%%2D1&myprofile=Welcome%%20to%%20my%%20profile&c40=%%2D1&friendid=Null&namex1=Luni&secretid=Null&job1=33&fsmall=K7G&c41=%%2D1&trait1=35&hax=1&c42=%%2D1&relationship1=35&myname=Name&c43=%%2D1&gender1=2&myemote=0&c44=%%2D1&fronthair1=304&backhair1=1&c45=%%2D1&rearhair1=261&ponytail1=0&c46=%%2D1&c48=%%2D1&ahoge1=0&c47=%%2D1&c49=%%2D1&eyes1=72&c50=%%2D1&c52=%%2D1&c51=%%2D1&c53=%%2D1&eyebrows1=3&c54=%%2D1&pupil1=0&c55=%%2D1&staminax=200&mouth1=15&highscore4=0&highscore1=0&blush1=0&highscore5=0&highscore2=0&glasses1=34&highscore6=0&highscore3=0&c57=%%2D1%s";
				char* reqtemp = "POST /lifeverse/liferegister.php HTTP/1.0\r\n"
					"Host: %s\r\n"
					"Content-Type: application/x-www-form-urlencoded\r\n"
					"Content-length: %d\r\n\r\n%s";
				size_t neededbody = snprintf(NULL, 0, reqbodytemp, gems, savecode, levelstr);
				char* reqbody = malloc(neededbody + 1);
				sprintf(reqbody, reqbodytemp, gems, savecode, levelstr);
				size_t neededreq = snprintf(NULL, 0, reqtemp, HOSTNAME, strlen(reqbody), reqbody);
				char* req = malloc(neededreq + 1);
				sprintf(reqbody, reqbodytemp, gems, savecode, levelstr);
				sprintf(req, reqtemp, HOSTNAME, strlen(reqbody), reqbody);
				if (send(sockfd, req, strlen(req), 0) > -1) {
					char reply[1024];
					recv(sockfd, reply, 1024, 0);
					free(reqbody);
					free(req);
					free(levelstr);
#if _WIN32
					closesocket(sockfd);
#else 
					close(sockfd);
#endif 
					return savecode;
				}
				else {
#if _WIN32
					closesocket(sockfd);
#else 
					close(sockfd);
#endif 
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void printlogo() {
	printf("\033[32;1m   ___         _         ___      _     _ _   \033[0m\n");
	printf("\033[32;1m  / __|__ _ __| |_  __ _/ __|_ __| |___(_) |_ \033[0m\n");
	printf("\033[32;1m | (_ / _` / _| ' \\/ _` \\__ \\ '_ \\ / _ \\ |  _|\033[0m\n");
	printf("\033[32;1m  \\___\\__,_\\__|_||_\\__,_|___/ .__/_\\___/_|\\__|\033[0m\n");
	printf("\033[32;1m                            |_|               \033[0m\n");
	printf("\033[31;1m                       Made by Gacha Exploit Enthusiasts\033[0m\n\n");
}

void printusage(char* progname) {
	fprintf(stderr, "Usage: %s [-h] [--gems GEMS] [--level LEVEL]\n\n", progname);
	fprintf(stderr, "Required arguments:\n");
	fprintf(stderr, " -g,  --gems      | Generate this amount of gems\n");
	fprintf(stderr, " -l,  --level     | Generate this amount of levels\n\n");
	fprintf(stderr, "Optional arguments:\n");
	fprintf(stderr, " -h,  --help      | Print usage\n");
	fprintf(stderr, " -v,  --version   | Print version\n");
	fprintf(stderr, " -cl, --changelog | Print changelog\n");
}

void changelog() {
	printf("Version 1.2.1:\n");
	printf("  - Optimization\n");
	printf("Version 1.2.0:\n");
	printf("  - Added levels over 151\n");
	printf("Version 1.1.3:\n");
	printf("  - Fixed spelling/grammatical errors\n");
	printf("Version 1.1.2:\n");
	printf("  - Minor bug fixes\n");
	printf("Version 1.1.0:\n");
	printf("  - Level hacking added\n");
	printf("  - Program now waits until exploit is complete\n");
	printf("Version 1.0.0:\n");
	printf("  - Created project\n");
	printf("  - Gem hacking added\n");
}

int main(int argc, char** argv) {
	if (argc < 2) {
		printusage(argv[0]);
		return 1;
	}
	else {
		int gems;
		int level;
#if _WIN32
		WSADATA wsaData;
		WSAStartup(0x202, &wsaData);
#endif 
		for (int i = 0; i < argc; i++) {
			char* arg = argv[i];
			if (strcmp(arg, "-g") == 0 || strcmp(arg, "--gems") == 0) {
				char* gemc = argv[i + 1];
				gems = atoi(gemc);
			}
			else if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
				printusage(argv[0]);
				return 0;
			}
			else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
				printf("Version 1.2.1 (Stable)\nGacha Exploit Enthusiasts, 2020\n");
				return 0;
			}
			else if (strcmp(arg, "-cl") == 0 || strcmp(arg, "--changelog") == 0) {
				changelog();
				return 0;
			}
			else if (strcmp(arg, "-l") == 0 || strcmp(arg, "--level") == 0) {
				char* levelc = argv[i + 1];
				level = atoi(levelc);
			}
		}
		printlogo();
		printf("\033[34;1m[+]\033[0m Generating...\n");
		if (gems && level) {
			if (level < 1202) {
				int savecode = profilehack(gems, level);
				if (savecode != 0) {
					printf("\033[34;1m[+]\033[0m Done!\n");
					printf("\033[33;1m[*]\033[0m Save ID: %i\n", savecode);
				}
				else {
					printf("\033[31;1m[!]\033[0m Error: Unknown error occurred, please try again later.\n");
				}
			}
			else {
				printf("\033[31;1m[!]\033[0m Error: Level amount cannot be over 1,201.\n");
			}
		}
		else {
			printf("\033[31;1m[!]\033[0m Error: Gem and level amount required.\n");
		}
	}
#if _WIN32
	WSACleanup();
#endif
	return 0;
}
