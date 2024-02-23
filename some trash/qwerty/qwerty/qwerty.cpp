#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rc4.c"

unsigned char flag[] = {
  0x73, 0x69, 0x6b, 0x6f, 0x72, 0x73, 0x6b, 0x79, 0x5f, 0x74, 0x65, 0x73,
  0x74, 0x5f, 0x66, 0x6c, 0x61, 0x67, 0x5f, 0x31, 0x32, 0x33, 0x34, 0x35,
  0x36, 0x5f
};
unsigned int flag_len = 26;


int main()
{

    unsigned char* outfile, * keystr;
    int key_len = 32;

    char data[32];

    FILE* fp;
    fp = fopen("/dev/urandom", "r");
    read(fileno(fp), data, key_len);
    fclose(fp);

    outfile = malloc(flag_len);

    RC4(data, key_len, flag_len, flag, outfile);

    for (int i = 0; i < flag_len; i++)
        printf("%02hhX", outfile[i]);

    fp = fopen("./enc_flag", "w");
    fwrite(outfile, 1, flag_len, fp);

    fclose(fp);

    getchar();
    return 0;
}