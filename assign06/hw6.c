#include <stdio.h>
#include <math.h>
void function(int *number,int c,int d){
*(number+c)=*(number+c)+pow(2,6-d);
}
int main(){
	int i=0,j=0,a=0,b=0,c=0,d=0,e=0,ASCII[10000][7]={{0}},number[10000]={0};
	char morse[10000][7]={{0}};
	while(scanf("%c",&morse[i][j])!=EOF){
		if(j>=6){
			i++;
			j=0;
		}
		else{
			j++;
		}
	}//讀取"." "-"資料
	for(a=0;a<i;a++){
		for(b=0;b<7;b++){
			if(morse[a][b]=='.'){
				ASCII[a][b]=0;
			}
			else if(morse[a][b]=='-'){
				ASCII[a][b]=1;
			}
		}
	}//轉換成ASCII Code
	for(c=0;c<i;c++){
		for(d=0;d<7;d++){
			if(ASCII[c][d]==1){
				function(number,c,d);
			}
		}
	}//轉換成數字
	for(e=0;e<i;e++){
		printf("%c",number[e]);
	}//輸出英文
	printf("\n");
	return 0;
}
