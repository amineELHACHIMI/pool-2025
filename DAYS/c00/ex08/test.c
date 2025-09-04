void fonction(int nb){
int i;
char tab[9];
while(i < n){
tab[i]='0'+i;
i++;
}
while(1){
	i=0;
	while(i<n)
	write(1,&tab[i++],1);	
		
	if(tab[0]=='0'+(10 -n))
		break;
	i=n-1;
	while(i >= 0 && tab[i] =='9'- (n-1-i))
		i--;
	tab[i]++;
	while(++i< n)
		tab[i]=tab[i-1]+1;

}
}
