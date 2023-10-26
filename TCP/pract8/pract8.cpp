#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>



int main() {
    char ipStr[20]; 
    uint32_t ip; 
    int subnetBits; 
    int numSubnets; 
    
    printf("Enter an IPv4 address in given format (e.g., 195.160.0.0/26): ");
    scanf("%19s", ipStr);


    char ipAddress[16];
    if (sscanf(ipStr, "%15[^/]/%d", ipAddress, &subnetBits) == 2) {
        int a, b, c, d;
        if (sscanf(ipAddress, "%d.%d.%d.%d", &a, &b, &c, &d) == 4) {
            if (a >= 0 && a <= 255 && b >= 0 && b <= 255 && c >= 0 && c <= 255 && d >= 0 && d <= 255) {
                ip = (a << 24) | (b << 16) | (c << 8) | d;                                                   //converting input to single ip address

          


                uint32_t subnetMask = 0xFFFFFFFF << (32 - subnetBits);
             

      
                printf("Enter the number of subnets: ");
                scanf("%d", &numSubnets);

                printf("Number of Subnets: %d\n", numSubnets);


                uint32_t subnetStart = ip & subnetMask;
                uint32_t subnetSize = (1 << (32 - subnetBits)) / numSubnets;           

                printf("starting and ending range :\n");
                for (int i = 0; i < numSubnets; i++) {
                    uint32_t subnetEnd = subnetStart + subnetSize - 1;
                   
                    
                    printf("%d.%d.%d.%d - ",
                           (subnetStart >> 24) & 255, (subnetStart >> 16) & 255,
                           (subnetStart >> 8) & 255, subnetStart & 255);
                    printf("%d.%d.%d.%d\n",
                           (subnetEnd >> 24) & 255, (subnetEnd >> 16) & 255,
                           (subnetEnd >> 8) & 255, subnetEnd & 255);

                    subnetStart = subnetEnd + 1; 
                }
            } else {
                printf("Invalid IP address.\n");
            }
        } else {
            printf("Invalid IP address format.\n");
        }
    } else {
        printf("Invalid CIDR notation format.\n");
    }

    return 0;
}