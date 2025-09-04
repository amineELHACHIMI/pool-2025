#include <unistd.h>
int main (int argc ,char *argv[]){
int i=0;
char c;
if(argc != 2){
	write(1,"\n",1);
	return 0;}
while(argv[1][i]!='\0'){
//if(i%3==0 && i%5==0)
//	c='5';
 if(i%3==0)
	c='5';
else if(i%5==0)
	c='3';
else 
	c=argv[1][i];
write(1,&c,1);
i++;
}
write(1,"\n",1);
return 0;
}
