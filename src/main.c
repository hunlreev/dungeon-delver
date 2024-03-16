#include <stdio.h>
#include <string.h>

void client() { /* TO DO */ }

void server() { /* TO DO */ }

int main(int argc, char *argv[])
{
    printf("Hello gamers!\n");

    if (argc < 2) 
    {
        printf("Usage: %s <Client/Server>\n", argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "Client"))
    {
        client();
    } 
    else 
    {
        server();
    }

    return 0;
}
