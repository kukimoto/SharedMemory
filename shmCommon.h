#ifndef __SHMCOMMON_H__
#define __SHMCOMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <iostream>
#include <cstring>
#include <string>

//#define KEYFILE_PATH "shmViewer"
#define KEYFILE_PATH "/opt/ssc/bin/hpvt"
#define PROJ_CHAR    (char)'r'
#define FIN (255)

/*#define ZOOMIN 0xb0*/
/*#define ZOOMOUT 0xb1*/
/*#define RIGHT	0xb2*/
/*#define LEFT 0xb3*/
/*#define UP 0xb4*/
/*#define DOWN 0xb5*/

enum motion{
	RIGHT,LEFT,UP,DOWN,ZOOMIN,ZOOMOUT,STOP
};


#define AUTO 0x01
#define MANU 0x02

using namespace std;

struct SHM_PARAM{
  int shd_param_id;
  int status;
  char mode[256];
 	char motion[256];
};

int shm_initialize(int shm_key, int shm_size,int *shrd_id,int *shm_ptr);
int shm_access(int shm_key, int shm_size, int *shrd_id, int *shm_ptr);

#endif /*  __SHMCOMMON_H__ */
