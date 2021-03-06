/*********************************************************************************
 *      Copyright:  (C) 2019 none
 *                  All rights reserved.
 *
 *       Filename:  socket_client.c
 *    Description:  client
 *                 
 *        Version:  1.0.0(03/22/2019)
 *         Author:  zhanghang <1711318490@qq.com>
 *      ChangeLog:  1, Release initial version on "03/22/2019 09:51:17 PM"
 *                 
 ********************************************************************************/
#include<stdio.h>
#include<unistd.h>//read,write
#include<sys/types.h>         //socket,bind,accept
#include<sys/socket.h>//on
#include<string.h>
#include<errno.h>
#include<netinet/in.h>//struct sockaddr_in
#include<arpa/inet.h>//on

#define MAXSIZE  1024

int main(int argc, char **argv)
{
    struct sockaddr_in              server_addr;
    int                             cli_fd;
//    char                            buf[MAXSIZE];
    int                             sr,sw;
    int                             port=8888;
    const char *ip="127.0.0.1";
    if((cli_fd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        printf("socket error:%d:%s\n",errno,strerror(errno));
        return -1;
    }
    printf("socket OK fd[%d]\n",cli_fd);

    bzero(&server_addr,sizeof(server_addr));

    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(port);
    inet_aton(ip,&server_addr.sin_addr);
    if(connect(cli_fd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
    {
        printf("connect error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1;
    }
    printf("connect to server %s:%d OK\n",ip,port);

   // bzero(buf,sizeof(buf));
   // strcpy(buf,"Hello,this is client\n");
    unsigned char buf[20][32]={
{0xFD,0x01,0x0A,0x48,0x65,0x6C,0x6C,0x6F,0xA7,0x6E,0xFD,0x01,0x07,0x48,0x69,0x2A,0x2B,0xFD,0x01,0x2E,0x54,0x68,0x69,0x73,0x20,0x66,0x6C,0x6F,0x77,0x65,0x72,0x20},
{0x73,0x6D,0x65,0x6C,0x6C,0x73,0x20,0x67,0x6F,0x6F,0x64,0x2C,0x64,0x6F,0x20,0x79,0x6F,0x75,0x20,0x73,0x65,0x6C,0x6C,0x20,0x74,0x68,0x65,0x6D,0x3F,0x4E,0x89,0xFD},
{0x01,0x14,0x48,0x6F,0x77,0x20,0x6D,0x75,0x63,0x68,0x20,0x69,0x73,0x20,0x69,0x74,0x3F,0xFC,0xF7,0xFD,0x02,0x06,0x17,0xE7,0xE8,0xFD,0x01,0x20,0x43,0x61,0x6E,0x20},
{0x79,0x6F,0x75,0x20,0x67,0x69,0x76,0x65,0x20,0x6D,0x65,0x20,0x61,0x20,0x64,0x69,0x73,0x63,0x6F,0x75,0x6E,0x74,0x3F,0xD0,0x60,0xFD,0x05,0x07,0x00,0x5A,0x62,0x8F},
{0xFD,0x01,0x14,0x4F,0x6B,0x2C,0x49,0x20,0x77,0x61,0x6E,0x6E,0x61,0x20,0x74,0x6F,0x20,0x38,0x0B,0x20,0xFD,0x01,0x15,0x4F,0x6B,0x2C,0x20,0x48,0x65,0x72,0x65,0x20},
{0x79,0x6F,0x75,0x20,0x61,0x72,0x65,0x43,0x92,0xFD,0x05,0x07,0x14,0x46,0x7E,0x85,0xFD,0x01,0x1E,0x54,0x68,0x69,0x73,0x20,0x69,0x73,0x20,0x74,0x68,0x65,0x20,0x6D},
{0x6F,0x6E,0x65,0x79,0x2C,0x74,0x68,0x61,0x6E,0x6B,0x73,0x21,0x54,0xCA,0xFD,0x01,0x2C,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B},
{0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x38,0xA3,0xFD,0x01,0x11,0x74,0x65,0x73},
{0x74,0x20,0x62,0x65,0x67,0x69,0x6E,0x73,0x3A,0x58,0x37,0xFD,0x01,0x0B,0x61,0x20,0x69,0x6E,0x74,0x3A,0xC6,0x0C,0xFD,0x04,0x09,0x00,0x00,0x00,0x80,0x8F,0xA0,0xFD},
{0x01,0x0E,0x61,0x20,0x64,0x6F,0x75,0x62,0x6C,0x65,0x3A,0x6B,0x85,0xFD,0x05,0x07,0x00,0xD5,0x02,0xE8,0xFD,0x01,0x12,0x61,0x20,0x62,0x69,0x67,0x20,0x73,0x74,0x72},
{0x69,0x6E,0x67,0x3A,0xF7,0x62,0xFD,0x01,0x68,0x59,0x6F,0x75,0x20,0x6A,0x75,0x73,0x74,0x20,0x77,0x61,0x6E,0x74,0x20,0x6D,0x79,0x20,0x61,0x74,0x74,0x65,0x6E,0x74},
{0x69,0x6F,0x6E,0x2C,0x79,0x6F,0x75,0x20,0x64,0x6F,0x6E,0x27,0x74,0x20,0x77,0x61,0x6E,0x74,0x20,0x6D,0x79,0x20,0x68,0x65,0x61,0x72,0x74,0x2C,0x79,0x6F,0x75,0x20},
{0x6A,0x75,0x73,0x74,0x20,0x6D,0x61,0x6B,0x69,0x6E,0x67,0x20,0x73,0x75,0x72,0x65,0x20,0x49,0x20,0x6E,0x65,0x76,0x65,0x72,0x20,0x67,0x65,0x74,0x74,0x69,0x6E,0x67},
{0x20,0x6F,0x76,0x65,0x72,0x20,0x20,0x20,0x20,0x79,0x6F,0x75,0xBC,0x73,0xFD,0x01,0x0E,0x61,0x20,0x64,0x6F,0x75,0x62,0x6C,0x65,0x3A,0x6B,0x85,0xFD,0x05,0x07,0x00},
{0x5A,0x62,0x8F,0xFD,0x01,0x1A,0x61,0x6E,0x20,0x61,0x6E,0x6F,0x74,0x68,0x65,0x72,0x20,0x62,0x69,0x67,0x20,0x73,0x74,0x72,0x69,0x6E,0x67,0x48,0x95,0xFD,0x01,0x46},
{0x48,0x65,0x6C,0x6C,0x6F,0x2C,0x69,0x66,0x20,0x79,0x6F,0x75,0x20,0x77,0x61,0x6E,0x74,0x20,0x74,0x6F,0x20,0x6C,0x65,0x61,0x76,0x65,0x2C,0x49,0x20,0x68,0x61,0x76},
{0x65,0x20,0x6E,0x6F,0x20,0x69,0x64,0x65,0x61,0x20,0x74,0x6F,0x20,0x73,0x74,0x6F,0x70,0x20,0x79,0x6F,0x75,0x20,0x74,0x6F,0x20,0x64,0x6F,0x20,0x74,0x68,0x69,0x73},
{0x2E,0x00,0x99,0xFD,0x01,0x0D,0x61,0x20,0x73,0x68,0x6F,0x72,0x74,0x3A,0x94,0xC5,0xFD,0x03,0x07,0xCB,0x88,0x64,0x87,0xFD,0x01,0x0E,0x61,0x20,0x73,0x74,0x72,0x69},
{0x6E,0x67,0x3A,0xED,0x55,0xFD,0x01,0x0A,0x48,0x65,0x6C,0x6C,0x6F,0xA7,0x6E,0xFD,0x01,0x15,0x61,0x20,0x75,0x6E,0x73,0x69,0x67,0x6E,0x65,0x64,0x20,0x63,0x68,0x61},
{0x72,0x3A,0x3A,0xB7,0xFD,0x02,0x06,0xAD,0xE1,0x79,0xFD,0x01,0x0E,0x74,0x65,0x73,0x74,0x20,0x65,0x6E,0x64,0x73,0xE5,0x34}};
    int i=0;
    for(i=0;i<20;i++)
    {
        //sleep(2);
        if((sw=write(cli_fd,buf[i],32))<=0)
        {
            printf("write error:%d:%s\n",errno,strerror(errno));
            close(cli_fd);
            return -1;
        }
        printf("write\n");
    }
/*  
//    printf("write %d bytes data to server:%s\n",(int)strlen(buf),buf);
  //  bzero(buf,sizeof(buf));
    sleep(2);
    if((sw=write(cli_fd,buf_s,sizeof(buf_s)))<=0)
    {
        printf("write error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1;
    }
    printf("write\n");
    sleep(2);
    if((sw=write(cli_fd,buf_t,sizeof(buf_t)))<=0)
    {
        printf("write error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1;
    }
    printf("write\n");
    sleep(2);
    if((sw=write(cli_fd,buf_h,sizeof(buf_h)))<=0)
    {
        printf("write error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1;
    }
    printf("write\n");
    sleep(2);
    if((sw=write(cli_fd,buf_v,sizeof(buf_v)))<=0)
    {
        printf("write error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1;
    }
        printf("write\n");
    sleep(2);
    if((sw=write(cli_fd,buf_w,sizeof(buf_w)))<=0)
    {   
        printf("write error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1; 
    }   
    printf("write\n");

  //      printf("write %d bytes data to server:%s\n",(int)strlen(buf_s),buf_s);*/

/*     if((sr=read(cli_fd,buf,sizeof(buf)))<=0)
    {
        printf("read error:%d:%s\n",errno,strerror(errno));
        close(cli_fd);
        return -1;
    }

    printf("read %d bytes data from server:%s\n",sr,buf);*/
    close(cli_fd);
    return 0;
}
