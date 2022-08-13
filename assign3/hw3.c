#include <stdio.h>

int main(){
	int money,fifty,twenty,ten,i,j,k;//i=50re,j=20re,k=10re
	scanf("%d %d %d",&ten,&twenty,&fifty);
	while(scanf("%d",&money)!=EOF){
		if(money<=(fifty*50+twenty*20+ten*10)){
			i=money/50;
			if(i>fifty){
				i=fifty;j=(money-50*fifty)/20;
				if(j>twenty){
					j=twenty;k=(money-50*i-20*twenty)/10;
				}
				else{
					k=(money-50*i-20*j)/10;
				}
			}
			else{
				j=(money-50*i)/20;
				if(j>twenty){
					j=twenty;k=(money-50*i-20*twenty)/10;
				}
				else{
					k=(money-50*i-20*j)/10;
				}
			}
			fifty=fifty-i;twenty=twenty-j;ten=ten-k;
			printf("ACCEPTED: 50 * %d, 20 * %d, 10 * %d\n",i,j,k);
		}
		else{
			printf("ERROR: The Machine is running out of coins!\n");
		}
	}
	return 0;
}
