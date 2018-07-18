#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	
	int shm_id;
	void *ptr;
	
	shm_id = shm_open("temp",O_CREAT | O_RDWR, 0666);
	if(shm_id == -1){
		perror("shm_open");
		exit(EXIT_FAILURE);
	}
	ftruncate(shm_id,4096);
	ptr = mmap(NULL,4096,PROT_WRITE,MAP_SHARED,shm_id,0);
	sprintf(ptr,"%s","narasimha");
	return 0;
}
