/********************************************************************************
 *      Copyright:  (C) 2019 none
 *                  All rights reserved.
 *
 *       Filename:  login.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(2019年07月24日)
 *         Author:  zhanghang <1711318490@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年07月24日 13时19分23秒"
 *                 
 ********************************************************************************/

#ifndef __LOGIN__
#define __LOGIN__


#include <mosquitto.h>
#include <stdlib.h>
#include <unistd.h>
#include "analysis.h"
#include <string.h>
#include <stdio.h>
#include <sqlite3.h>
#include "insert_db.h"
#define ARR_SIZE 128
struct login_t
{
    char username[ARR_SIZE];
    char password[ARR_SIZE];
    char temp_topic[ARR_SIZE];
    char warn_topic[ARR_SIZE];
    char address[ARR_SIZE];
    int port;
    char mac[ARR_SIZE];
    sqlite3 *db;
};
#define MESSAGE_COUNT 100000L
#define MESSAGE_SIZE 1024L

#define DB_NAME "PRJ_DATA"
#define FILE_NAME "JSON_DATA"
void my_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void my_connect_callback(struct mosquitto *mosq, void *obj, int rc);
void my_disconnect_callback(struct mosquitto *mosq, void *obj, int result);
struct mosquitto *login_mqtt(struct login_t *login);
#define KEEPALIVE 60
#endif

