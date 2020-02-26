#include "shmCommon.h"
#include <iostream>
#include <string>

using namespace std;

//int shm_initialize(key_t shm_key, int shm_size,int *shrd_id,int *shm_ptr);
//int shm_access(key_t shm_key, int shm_size, int *shrd_id, int *shm_ptr);

int erase_shm(struct SHM_PARAM *param_ptr)
{
    shmctl(param_ptr->shd_param_id, IPC_RMID, 0);

    return(0);
}

int main(int argc, char **argv)
{
  int shd_param_id;
  struct SHM_PARAM *param_ptr;

/*
  key_t key;

  key = ftok(KEYFILE_PATH,PROJ_CHAR);
  if( key == -1 ) {
    perror("ftok()");
    return 1;
  }
*/
	int key=6000;

  shm_initialize(key, sizeof(struct SHM_PARAM), &shd_param_id, (int *)&param_ptr);
  param_ptr->shd_param_id = shd_param_id;
  while(1){
		printf("mode:%s\t motion:%s\n",param_ptr->mode, param_ptr->motion);
		if( param_ptr->status == FIN )
      break;
    sleep(1);
  }
  erase_shm(param_ptr);
}
