#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#ifndef BUF
#define BUF 3
#endif
unsigned long verfier_in_midlle(char *s)
{
	int	i=0;
	while(s[i])
	{
		if(s[i]=='\n')
			return i;
		i++;
	}
	return i;
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	r = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	p = r;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (r);
}

char *get_next_line(int fd)
{
	if(fd<0)
		return NULL;
	static char* after;
	char *before=NULL;
	char tmp[BUF];
	char *result=strdup("");
	ssize_t num=1;
	if(after && *after)
	{
		char c;
		while(*after)
		{
			c=*after;
			if(c=='\n')
			{
				after++;
				return result;
			}
			result=ft_strjoin(result,&c);
			after++;
		}
	}
	while(num)
	{
		num=read(fd,tmp,BUF);
		if(num <= 0)
			return result;
		tmp[num]='\0';
		if(strlen(tmp)==verfier_in_midlle(tmp))
				result=ft_strjoin(result,tmp);
				
		else
		{
			int	wordp=verfier_in_midlle(tmp);
			before = malloc(wordp+1);
			strncpy(before,tmp,wordp+1);
			int	nwordp=strlen(tmp)-verfier_in_midlle(tmp);
			after = malloc(nwordp);
			strncpy(after,tmp+wordp+1,nwordp);
			result=ft_strjoin(result,before);
			return result;

		}


	}
	return result;
}
int main()
{
	int fd = open("test1.text",O_RDONLY);
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));
	printf(" result :%s \n ",get_next_line(fd));

}
