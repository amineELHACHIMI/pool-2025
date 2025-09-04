#include <unistd.h>
int main (int argc,char *argv[]){
int i=0;
int c=0;
if (argc==2){
	while(argv [1][i]!='\0'){

	if(argv[1][i]>='a'&& argv[1][i]<='z')
	c=1+argv[1][i]-'a';
	else if(argv[1][i]>='A'&&argv[1][i]<='Z')
		c=1+(argv[1][i]-'A');
	while(c>=1){
	write(1, &argv[1][i],1);
		c--;
	}
i++;
}
}
write(1,"\n",1);
}
