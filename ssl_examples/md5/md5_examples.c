/*********************************************************************************
 *      Copyright:  (C) 2019 none
 *                  All rights reserved.
 *
 *       Filename:  md5_examples.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(03/19/2019)
 *         Author:  zhanghang <1711318490@qq.com>
 *      ChangeLog:  1, Release initial version on "03/19/2019 07:58:53 PM"
 *                 
 ********************************************************************************/

#include<openssl/md5.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
    MD5_CTX ctx;
    unsigned char output[16];
    char buffer[1024];
    char filename[32];
    int len=0;
    int i;
    FILE *fp=NULL;
    memset(output,0,sizeof(output));
    memset(filename,0,sizeof(filename));
    memset(buffer,0,sizeof(buffer));
    printf("Enter the file name:\n");
    scanf("%s",filename);
    fp=fopen(filename,"rb");
    if(fp==NULL)
    {
        printf("open %s error\n",filename);
        return -1;
    }
    MD5_Init(&ctx);
    while((len=fread(buffer,1,1024,fp))>0)
    {
        MD5_Update(&ctx,buffer,len);
        memset(buffer,0,sizeof(buffer));
    }
    MD5_Final(output,&ctx);
    for(i=0;i<16;i++)
    {
        printf("%02X",output[i]);
    }
    putchar('\n');
    return 0;
}
