#include<unistd.h>
#include<stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int	*malloc_word(int fd)
{
	int *result=NULL;
	int c;
	size_t numRead;
	int count=0;

	if(fd <0)
	{
		return result;
	}
        else
        {
                numRead = read(fd,&c,1);
                while(numRead)
                {
                        if(c != '\n')
                                count++;
                        else
                        {
                                result=malloc(count*sizeof(int));
                                break;
                        }
                        numRead = read(fd,&c,sizeof(int));
                }
		return result;
        }
}
void affect_word(int fd,char *r)
{
        int	i;
        int c;
        size_t numRead;
        int count=0;
	i=0;

        if(fd <0)
        {
                return ;
        }
        else
        {
                numRead = read(fd,&c,1);
                while(numRead)
                {
                        if(c != '\n')
                                r[i++]=c;
                        else
				break;
                        numRead = read(fd,&c,size(int));
                }
        }
}
int *get_next_line(int fd1,int fd2)
{
	char *result;
	result=malloc_word(fd1);
	affect_word(fd2,result);
	return result;
}
