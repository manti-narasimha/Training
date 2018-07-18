#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc,char *argv[]){
	
	int shm_id;void *ptr;

	shm_id = shm_open("temp",O_RDONLY,0666);
	if(shm_id == -1){
		perror("shm_open");
	}
	ptr = mmap(NULL,4096,PROT_READ,MAP_SHARED,shm_id,0);
	printf("%s\n",(char*)ptr);
	shm_unlink("temp");
	return 0;
}
