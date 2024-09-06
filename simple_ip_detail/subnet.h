#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

unsigned int int_Ip(char *IP);
int binDec(int *resultat);
int *fillmasque(int netmask);
void test_adress();
bool validbytes(int byte);
int IPReseau(int octect,int *masque);
bool verify(char *IP,char *masque,int *bit);
int *to_binary(int a);
void detail_of_IP(char *IP,char *Masque,int netmask);
char *charIp(int ip);
char* broadcast(char *Ip,char *mask);
char *cat(int a,int b,int c,int d);