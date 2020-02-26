#include "shmCommon.h"

/**
 * shm_initialize(key_t shm_key, size_t shm_size,int *shrd_id,int *shm_ptr)
 * key_t   shm_key INPUT:   Keyword for Shared Memory
 * size_t  shm_size INPUT:   Size of the SHM [bytes]
 * int     *shrd_id OUTPUT:  Pointer to the Shared Memory ID
 * int     *shm_ptr OUTPUT:  Pointer to the Top of SHM
 */
int shm_initialize(int shm_key, int shm_size,int *shrd_id,int *shm_ptr)
{
  *shrd_id = shmget(shm_key, shm_size, IPC_CREAT|0666);
  if( *shrd_id < 0 ){
    printf("[shm_initialize]: Can't Access to the Shared Memory !! \n" );
    return -1;
  }
  *shm_ptr = (int)shmat( *shrd_id, NULL, 0);
  memset( (void *)*shm_ptr, 0, shm_size );

  return  *shrd_id;
}


/**
 * \fn shm_access(key_t shm_key, size_t shm_size, int *shrd_id, int *shm_ptr)
 * \brief OPEN SHARED MEMORY

 * \param key_t   shm_key   INPUT:   Keyword for Shared Memory      
 * \param size_t  shm_size  INPUT:   Size of the SHM [bytes]        
 * \param int     *shrd_id  OUTPUT:  Pointer to the Shared Memory ID
 * \param int     *shm_ptr  OUTPUT:  Pointer to the Top of SHM      
*/
int shm_access(int shm_key, int shm_size, int *shrd_id, int *shm_ptr)
{
  /*-------- ACCESS TO CURRENT STATUS --------*/
  *shrd_id = shmget(shm_key, shm_size, 0444);
  if( *shrd_id < 0 ){
    printf("Can't Access to the Shared Memory !! \n" );
    return(-1);
  }
  *shm_ptr = (int)shmat( *shrd_id, (const void *)NULL, 0);
  
  /*-------- ENDING --------*/
  return *shrd_id;
}
