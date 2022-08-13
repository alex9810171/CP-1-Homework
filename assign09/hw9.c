#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	int a=1,b=0,count=0,count1=0,count2=0,count3=0;
	char locate[52]={"/usr/local/class/cp1/assign/assign9/dataset/000.txt"};
	char target[50],title[200],word[50],title1[200],title2[200],title3[200];
	FILE *fptr;
	scanf("%s",target);
	for(a=1;a<=300;a++){
		locate[44]=a/100+48;	locate[45]=a%100/10+48;	locate[46]=a%10+48;
		fptr=fopen(locate,"r");
		fgets(title,200,fptr);
		while(fscanf(fptr,"%s",word)!=EOF){
			while(isalnum(word[0])==0&&word[0]!='\0'){
				for(b=0;word[b]!='\0';b++)word[b]=word[b+1];
				word[b-1]='\0';
			}//字首整理
			for(b=0;isalnum(word[49-b])==0&&word[0]!='\0';b++)word[49-b]='\0';//字尾整理
			for(b=0;word[b]!='\0';b++)word[b]=tolower(word[b]);//轉小寫
			if(isalpha(word[0])!=0&&strcmp(word,target)==0)count++;
			memset(word,'\0',50);
		}
		if(count>=count1){
			count3=count2;	count2=count1;	count1=count;
			strcpy(title3,title2);	strcpy(title2,title1);	strcpy(title1,title);
		}
		else if(count<count1&&count>=count2){
			count3=count2;	count2=count;
			strcpy(title3,title2);  strcpy(title2,title);
		}
		else if(count<count2&&count>=count3){
			count3=count;
			strcpy(title3,title);
		}
		count=0;
		fclose(fptr);
	}
	printf("%s%s%s",title1,title2,title3);
	return 0;
}
