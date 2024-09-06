#include "subnet.h"

void test_adress()
{
    char *IP = (char*)malloc(sizeof(char)*40);
    char *masque = (char*)malloc(sizeof(char)*40);
    int bit;
    do
    {
        printf("Entrer l'adress IP (X.X.X.X): ");
        fgets(IP,35,stdin);
        printf("Masque (X.X.X.X)            : ");
        fgets(masque,35,stdin);
        IP[strcspn(IP, "\n")] = '\0';
        masque[strcspn(IP, "\n")] = '\0';
    } while (!verify(IP,masque,&bit));
    detail_of_IP(IP,masque,bit);
    free(IP);
    free(masque);
}
void detail_of_IP(char *IP, char *Masque, int netmask) {
    unsigned int ip = int_Ip(IP);
    unsigned int mask = int_Ip(Masque);
    unsigned int adresse_reseau;
    unsigned int adresse_broadcast;
    int nombredemachine;
    adresse_reseau = ip & mask;
    adresse_broadcast = adresse_reseau | (~mask);
    nombredemachine = (1 << (32 - netmask)) - 2;
    printf("\n=========================================\n");
    printf("=> ADRESSE IP          : %s\n", IP);
    printf("=> Masque              : %s\n", Masque);
    printf("=> Adresse reseau      : %s\n", charIp(adresse_reseau));
    printf("=> Adresse broadcast   : %s\n", charIp(adresse_broadcast));
    printf("=> Nombre de machine   : %d\n", nombredemachine);
    printf("\n=========================================\n");
}
unsigned int int_Ip(char *IP)
{
    unsigned int octect1,
        octect2,
        octect3,
        octect4;
    sscanf(IP,"%u.%u.%u.%u",&octect1,&octect2,&octect3,&octect4);
    return (octect1 << 24) | (octect2 << 16) | (octect3 << 8) | octect4;
}
char *charIp(int ip) {
    char *IP = malloc(sizeof(char)*32);
    int octect1 = (ip >> 24) & 0xFF,
        octect2 = (ip >> 16) & 0xFF,
        octect3 = (ip >> 8) & 0xFF,
        octect4 = ip & 0xFF;
    sprintf(IP,"%d.%d.%d.%d",octect1,octect2,octect3,octect4);
    return IP;
}
char *cat(int a,int b,int c,int d)
{
    char *retour = malloc(sizeof(int)*32);
    sprintf(retour,"%d.%d.%d.%d",a,b,c,d);
    return retour;
}
int *to_binary(int a)
{
    int * bin = malloc(sizeof(int)*10);
    int tempbin[10];
    int temp = a,i;
    int j;
    for(i = 0;temp != 0;i++){
        tempbin[i] = temp%2;
        temp /= 2;
    }
    if(i < 8)
    {
        for(j = i;j < 8;j++)
        {
            tempbin[j] = 0;
        }
    }
    for(j = 0;j < 8;j++)
    {
        bin[j] = tempbin[8 - j - 1];
    }
    return bin;
}
bool verify(char *IP,char *masque,int *bit)
{
    int octect1;
    int octect2;
    int octect3;
    int octect4;
    int verification;
    int masqueInt[5];
    int *mask1;
    int *mask2;
    int *mask3;
    int *mask4;
    int i;
    int masqueBin[34];
    int netmask = 0;
    verification = sscanf(IP,"%d.%d.%d.%d",&octect1,&octect2,&octect3,&octect4);
    if(verification != 4)
        return false;
    verification = sscanf(masque,"%d.%d.%d.%d",&masqueInt[0],&masqueInt[1],&masqueInt[2],&masqueInt[3]);
    if(!validbytes(octect1) || !validbytes(octect2) || !validbytes(octect3) || !validbytes(octect4))
        return false;
    if(!validbytes(masqueInt[0]) || !validbytes(masqueInt[1]) || !validbytes(masqueInt[2]) || !validbytes(masqueInt[3]))
        return false;
    mask1 = to_binary(masqueInt[0]);
    mask2 = to_binary(masqueInt[1]);
    mask3 = to_binary(masqueInt[2]);
    mask4 = to_binary(masqueInt[3]);
    for(i = 0;i < 32;i++)
    {
        if(i < 8)
            masqueBin[i] = mask1[i];
        if(i > 8 && i < 16)
            masqueBin[i] = mask2[i%8];
        if(i > 16 && i < 24)
            masqueBin[i] = mask3[i%8];
        if(i > 24 && i < 32)
            masqueBin[i] = mask4[i%8];
    }
    for(i = 0;i < 32;i++)
    {
        if(masqueBin[i] == 0)
            for (i = i + 1; i < 32; i++)
            {
                if(masqueBin[i] == 1)
                    return false;
            }
        else if(masqueBin[i] == 1)
        {
            netmask++;
        }
            
    }
    *bit = netmask;
    return true;
}
bool validbytes(int byte)
{
    if(byte > 255 || byte < 0)
        return false;
    return true;
}