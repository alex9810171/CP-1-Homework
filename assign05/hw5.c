#include <stdio.h>
void bubblesort(int i,int *number,char *word){
	int a=0,tempN=0;
	char tempC;
	while(i>0){
		if(a<=i){
			if(number[a]<number[a+1]){
				tempN=*(number+a);        tempC=*(word+a);
				*(number+a)=*(number+a+1);  *(word+a)=*(word+a+1);
				*(number+a+1)=tempN;      *(word+a+1)=tempC;
			}
			a++;
		}
		else if(a>i){
			a=0;
			i--;
		}
	}
}
int main(){
	int a=0,b=0,i=0,number[1000]={0};
	char word[1000]={'\0'};
	while(scanf("%d%c",&number[i],&word[i])!=EOF){
		i++;
	}
	bubblesort(i,number,word);
	for(a=0;a<i-2;a++){
		printf("%d ",number[a]);
	}
	printf("%d\n",number[i-2]);
	for(b=0;b<i;b++){
		printf("%c",word[b]);
	}
	return 0;
}
