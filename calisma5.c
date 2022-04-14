#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE          (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("bir dosya adi vermelisiniz.\n");
		exit(-1);
	}
	int fd = open(argv[1],O_RDONLY,FILE_MODE);
		if(fd<0)
		{
			printf("dosya okuma hatasi. \n");
			exit(-2);
		}
	int fd2 = open("cevap.txt", O_WRONLY | O_APPEND | O_CREAT | O_TRUNC,FILE_MODE);
		if(fd2<0)
		{
			printf("dosya olusturma hatasi.\n");
			exit(-3);
		}
	int n = 1;
	char buf[1];
	int cumleSirasi = 1;
	while(n!=0)
	{
		n = read(fd,buf,1);
		if(cumleSirasi % 2 == 1)
                {
                        write(fd2,buf,1);
                        if(fd2<0)
                        {
                                printf("dosya yazma hatası.\n");
                                exit(-4);
                        }
                }

		if(buf[0] == '.')
		{
			cumleSirasi++;
		}
	}
	char buf2[100] = "\nBu dosya Batuhan IRMALI tarafından hazırlanmıştır.\n";
	write(fd2,buf2,sizeof(buf2)-1);
	if(fd2<0)
	{
		printf("dosya yazma hatası2.\n");
		exit(-5);
	}
	close(fd);
	close(fd2);
return 0;
}
