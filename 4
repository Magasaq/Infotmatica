#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 256

struct msgbuf{
long type;
char text[SIZE];
};

int main(int argc, char * argv[]){

/*if(argc != 3){
printf("Wrong number of arguments\n");
return -1;
}*/

key_t key = ftok("/bin/true", atoi(argv[2])); 

if(key == -1){
perror("ftok");  
return -1;
}

struct msgbuf m;

while(1){
if(msgget(key, 0) > 0) 
break;
}

int id = msgget(key, 0);

if(id == -1){
perror("msgget"); 
return -1;
}

int ret = msgrcv(id, &m, SIZE, 1, 0); 

if (ret == -1){
perror("msgrcv");
return -1;
}

int ope = open(argv[1], O_RDWR|O_CREAT, 0644);

if(ope == -1){
perror("open"); 
return -1;
}

do {
int wri = write(ope, m.text, ret); 

if(wri == -1){
perror("write"); 
return -1;
}else if(ret == -1){
perror("msgrcv");
return -1;
}else if(ret == 0){break;}
} while (ret = msgrcv(id, &m, SIZE, 1, 0)); 

if(close(ope) == -1){ 
perror("close"); 
}

if(msgctl(id, IPC_RMID, NULL) == -1){ 
perror("msgctl"); 
return -1;
}

printf("File has been recieved successfully\n");
printf("Message queue has been removed successfully\n"); 

return 0;
}
