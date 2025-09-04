#include <unistd.h>
int main (int argc,char *argv[]){
int i=0;
int j;
if(argc==1){
write(1,"\n",1);
return 0;
}
j=argc-1;
while(argv[j][i]!='\0'){
write(1,&argv[j][i],1);
i++;
}
write(1,"\n",1);
return 0;
}
