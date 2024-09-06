# Simple-IP-Detail-Using-C-Language

This project provides a C script to calculate network details such as the network address, broadcast address, and number of hosts based on an IP address and subnet mask provided by the user.

## Using the `subnet` Script

The `subnet` script calculates network details based on an IP address and subnet mask. Here’s how to use it and understand its output.

### Running the Script

1. Navigate to the `simple_ip_detail` directory: `cd simple_ip_detail`

2. Compile the script (if not yet compiled): `gcc -o subnet subnet.c`

3. Run the script with the following command: `./subnet`

4. The script will prompt you to enter an IP address and a subnet mask:  
   `Enter the IP address (X.X.X.X): 111.1.1.1`  
   `Mask (X.X.X.X): 192.0.0.0`

5. The output will display key network details: