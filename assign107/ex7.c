#include <stdio.h>
void toUpper(int j,char *word){
	int a=0;
	for(a=0;a<j;a++){
		if(*(word+a)<=122&&*(word+a)>=97)
			*(word+a)=*(word+a)-32;
	}
}
void toLower(int j,char *word){
	int b=0;
	for(b=0;b<j;b++){
		if(*(word+b)<=90&&*(word+b)>=65)
			*(word+b)=*(word+b)+32;
	}
}
int main(){
	int i=0,j=0,k=0;
	char word[1000]={'\0'};
	scanf("%d\n",&i);
	while(scanf("%c",&word[j])!=EOF){
		j++;
	}
	if(i==1){
		toUpper(j,word);		
	}
	else if(i==2){
		toLower(j,word);
	}
	for(k=0;k<j;k++){
		printf("%c",word[k]);
	}
	return 0;
}
