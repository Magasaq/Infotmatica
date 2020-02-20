#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 256

struct msgbuf{
long type;
char text[SIZE];
};

int main(int argc, char * argv[]){

/*if(argc != 3){
printf("Too much arguments\n"); 
return -1;
}*/

key_t key = ftok("/bin/true", atoi(argv[2])); 
if(key == -1){
perror("ftok"); 
return -1;
}

int id = msgget(key, IPC_CREAT | 0644);

if (id == -1){
perror("msgget"); 
return -1;
}

int a = open(argv[1], O_RDONLY);

if(a == -1){
perror("open"); 
return -1;
}

struct msgbuf m;
m.type = 1;
int ret;

while (ret = read(a, m.text, SIZE)) { 

if (ret == -1){
perror("read"); 
return -1;
}

int snd = msgsnd(id, &m, ret, 0); 

if(snd == -1){
perror("msgsnd"); 
return -1;
}
}

int snd = msgsnd(id, &m, 0, 0); 
if(snd == -1){
perror("msgsnd");
return -1;
}

int clo = close(a);

if(clo == -1)
perror("close"); 
printf("File has been sent successfully\n"); 

return 0;
}
