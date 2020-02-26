#include "shmCommon.h"


using namespace std;
int main(int argc, char **argv)
{
  int i;
  
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

  if(shm_access(key, sizeof(struct SHM_PARAM), &shd_param_id, (int *)&param_ptr)<0){
		exit(1);
	}
  param_ptr->shd_param_id = shd_param_id;

  char mode[2][256]={"AUTO", "MANUAL"};
  char motion[7][256]={"UP", "DOWN", "RIGHT","LEFT","ZOOMIN", "ZOOMOUT","STOP"};


  for(i=0 ; i<10 ; i++){
		printf("%d/10 Write : %s %s\n",	i,	mode[i%2], motion[i%7]);
		strcpy(param_ptr->mode, mode[i%2]);
		strcpy(param_ptr->motion, motion[i%7]);


    sleep(1);
  }
  param_ptr->status = FIN;

  return 0;
}
