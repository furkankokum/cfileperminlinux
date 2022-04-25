#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char*argv[]){
if(argc!=2){
        printf("dosya ismi girin.\n");
        exit(-1);
}
int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,FILE_MODE);
char buf[13]="Bu bir dosya.";
char buf2[1];
write(fd,buf,sizeof(buf));
int oku=open(argv[1],O_RDONLY,FILE_MODE);
int n1=1;
int fd2=open("metin_sesli_harfsiz.txt",O_WRONLY|O_CREAT|O_TRUNC,FILE_MODE);
while(n1=read(oku,buf2,sizeof(buf2))>0){
        if(buf2[0]!='a' && buf2[0]!='e' && buf2[0]!='i' && buf2[0]!='o' && buf2[0]!='u'){
        write(fd2,buf2,1);
        }
close(fd);
close(fd2);
return 0;
