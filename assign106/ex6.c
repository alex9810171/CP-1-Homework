#include <stdio.h>
int main(){
	int array[20]={0},i=0,a=0,num=0,add=0,sum=0,maxsum=0;
	while(scanf("%d ",&array[i])!=EOF){
		i++;
	}
	maxsum=array[0];
	for(add=0;add<i;add++){
		for(num=0;num<i;num++){
			for(a=0;a<add+1&&a+num<20;a++){
				sum=array[num+a]+sum;
				}
			if(sum>maxsum){
					maxsum=sum;
				}
		sum=0;	
		}
		}
	printf("Maximum sum is %d\n",maxsum);
	return 0;
}
