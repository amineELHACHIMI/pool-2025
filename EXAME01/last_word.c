#include <unistd.h>
int main (int argc,char *argv[]){
int i=0;
if(argc<2){
write(1,"\n",1);
return 0;
}
while(argv[1][i] != '\0')
i++;
i--;
while(argv[1][i]!='\0'){
if(argv[1][i]==' ' ||  argv[1][i]=='\t')
	if(argv[1][i+1]>='a'&&argv[1][i+1]<='z')
break;
i--;
}
i++;
while(argv[1][i] != '\0'){
write(1,&argv[1][i],1);
i++;
}
write(1,"\n",1);
return 0;
}

