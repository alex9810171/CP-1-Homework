#include <stdio.h> 
#include <string.h>
typedef struct{
	char word[2000][50];
}data;
data d;
int numword(char c){//0�ҫD 1�j�g 2�p�g 3�Ʀr
	if(c>=65&&c<=90) return 1;
	else if(c>=97&&c<=122) return 2;
	else if(c>=48&&c<=57) return 3;
	else return 0;
}
int main(){
	int i=0,j=0,k=1,a=0,tcount=1,count=1,l=0,tl=0;
	char temp[50]={'\0'};
	while(scanf("%s",d.word[l])!=EOF){
		while(numword(d.word[l][0])==0&&d.word[l][0]!='\0'){
			for(a=0;d.word[l][a]!='\0';a++)d.word[l][a]=d.word[l][a+1];
			d.word[l][a-1]='\0';
		}//��e�����I�Ÿ��h��
		for(a=0;a<50&&numword(d.word[l][49-a])==0;a++){
			if(numword(d.word[l][49-a])==0)d.word[l][49-a]='\0';
		}//��᭱�����I�Ÿ��h��
		if(numword(d.word[l][0])==3||d.word[l][0]=='\0'){
			for(a=0;d.word[l][a]!='\0';a++)d.word[l][a]='\0';
			l--;
		}//�����M��
		else{
			for(a=0;d.word[l][a]!='\0';a++){
				if(numword(d.word[l][a])==1)d.word[l][a]+=32;
			}
		}//�Y���j�g�r���Ӯ�+32
		l++;
	}//�έp�X���׬�l
	tl=l-1;
	while(tl>0){
		for(j=0;j<50&&k==1&&(d.word[i][j]!='\0'&&d.word[i+1][j]!='\0');j++){
			if(d.word[i][j]>d.word[i+1][j]){
				strcpy(temp,d.word[i]);
				memset(d.word[i],'\0',50);
				strcpy(d.word[i],d.word[i+1]);
				memset(d.word[i+1],'\0',50);
				strcpy(d.word[i+1],temp);
				memset(temp,'\0',50);
				k=0;
			}
			else if(d.word[i][j]<d.word[i+1][j]) k=0;
		}
		if(k==1&&strlen(d.word[i])>strlen(d.word[i+1])){
			strcpy(temp,d.word[i]);
			memset(d.word[i],'\0',50);
			strcpy(d.word[i],d.word[i+1]);
			memset(d.word[i+1],'\0',50);
			strcpy(d.word[i+1],temp);
			memset(temp,'\0',50);
		}
		if(i==tl-1){
			tl-=1;
			i=0;
		}
		else i++;
		k=1;
	}
	printf("---------\n%c\n%s",d.word[0][0]-32,d.word[0]);
	for(a=1;a<l;a++){
		if(strcmp(d.word[a],d.word[a-1])==0){
			count++;
			tcount--;
		}//�r��ۦP��
		else if(d.word[a][0]==d.word[a-1][0]){
			printf(" %d\n%s",count,d.word[a]);
			count=1;
		}//�r���ۦP��
		else{
			printf(" %d\n---------\n%c\n%s",count,d.word[a][0]-32,d.word[a]);
			count=1;
		}//�Ҥ��ۦP��
		tcount++;
	}
	printf(" %d\n---------\n%d unique words\n",count,tcount);//�έp���G
	return 0;
}
