#include <unistd.h>
int main(int argc ,char *argv[]){
	int i=0;
if(argc!=2)
	return 0;

	while(argv[1][i] != '\0'){
	write(1,&argv[1][i],1);
	write(1," ",1);
	i++;
	}
	
}
