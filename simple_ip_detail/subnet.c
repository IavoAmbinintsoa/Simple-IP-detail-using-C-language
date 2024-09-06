#include "subnet.h"

int main()
{
    test_adress();
    return(0);
}
/*#include <stdio.h>
#include <math.h> // For pow() function
#include <stdint.h> // For uint32_t

// Assume these functions are defined elsewhere:
// unsigned int int_Ip(const char *ip_str);
// char *charIp(unsigned int ip);

void detail_of_IP(const char *IP, const char *Masque, int netmask) {
    // Convert IP and Mask from string to integer representation
    unsigned int ip = int_Ip(IP);
    unsigned int mask = int_Ip(Masque);
    unsigned int network_address;
    unsigned int broadcast_address;
    int num_hosts;

    // Calculate network address (ip & mask)
    network_address = ip & mask;
    
    // Calculate broadcast address (network_address | ~mask)
    broadcast_address = network_address | (~mask & 0xFFFFFFFF);

    // Calculate number of hosts in the subnet
    num_hosts = (1 << (32 - netmask)) - 2; // 2 addresses reserved (network and broadcast)

    // Print the results
    printf("\n=========================================\n");
    printf("=> ADRESSE IP          : %s\n", IP);
    printf("=> Masque              : %s\n", Masque);
    printf("=> Adresse reseau      : %s\n", charIp(network_address));
    printf("=> Adresse broadcast   : %s\n", charIp(broadcast_address));
    printf("=> Nombre de machine   : %d\n", num_hosts);
    printf("\n=========================================\n");
}
*/