
#include <unistd.h>
int main (int argc, char *argv[]){
	int i=0;
	if(argc<2)
		return 0;
	while(argv[1][i]!= '\0'){
	if(argv[1][i]>='a' && argv[1][i]<='z')
		argv[1][i]-=32;
	else if(argv[1][i]>='A' && argv[1][i]<='Z')
                argv[1][i]+=32;
	i++;
	}
	i=0;
	while(argv[1][i]){
	write(1,&argv[1][i],1);
	i++;
	}
}
