#include <stdio.h>
FILE *player1,*player2,*datain;
void checkanswer(int k,int count,int table[10][5],int answer[1000]){
	int i,j=0,a=0,stop=0;
	for(i=5*k+0;i<5*k+5;i++)
		for(j=0;j<5;j++){
			if(k==0)fscanf(player1,"%d",&table[i][j]);
			else if(k==1)fscanf(player2,"%d",&table[i][j]);
			for(a=0;a<count&&stop==0;a++)
				if(answer[a]==table[i][j]){
					table[i][j]=-1;
					stop=-1;
				}
			stop=0;
		}
}
void countline(int k,int table[10][5],int pline[2]){
	int a;
	for(a=0;a<5;a++){
		if(table[0+5*k][a]==-1&&table[1+5*k][a]==-1&&table[2+5*k][a]==-1&&table[3+5*k][a]==-1&&table[4+5*k][a]==-1)pline[k]++;
		if(table[a+5*k][0]==-1&&table[a+5*k][1]==-1&&table[a+5*k][2]==-1&&table[a+5*k][3]==-1&&table[a+5*k][4]==-1)pline[k]++;
	}
	if(table[0+5*k][0]==-1&&table[1+5*k][1]==-1&&table[2+5*k][2]==-1&&table[3+5*k][3]==-1&&table[4+5*k][4]==-1)pline[k]++;
	if(table[0+5*k][4]==-1&&table[1+5*k][3]==-1&&table[2+5*k][2]==-1&&table[3+5*k][1]==-1&&table[4+5*k][0]==-1)pline[k]++;
}
int main(int argc,char *argp[]){
	int count=0,i=0,j=0,k=0,table[10][5]={{0}},pline[2]={0},answer[1000]={0};
	datain=fopen(argp[3],"r");
	while(fscanf(datain,"%d\n",&answer[count])!=EOF){
		count++;
	}
	fclose(datain);
	player1=fopen(argp[1],"r");//填入第一個人的表格
	checkanswer(k=0,count,table,answer);
	fclose(player1);
	player2=fopen(argp[2],"r");//填入第二個人的表格
	checkanswer(k=1,count,table,answer);
	fclose(player2);
	countline(k=0,table,pline);//數幾條線
	countline(k=1,table,pline);
	if(pline[0]>pline[1])printf("Player1 wins\n");//輸出部分
	else if(pline[0]==pline[1])printf("Tie\n");
	else if(pline[0]<pline[1])printf("Player2 wins\n");
	printf("\nPlayer1 has %d lines:\n",pline[0]);
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(table[i][j]==-1)printf("*");
			else printf("%d",table[i][j]);
			if(j<4)printf(" ");
		}
		printf("\n");
	}
	printf("\nPlayer2 has %d lines:\n",pline[1]);
	for(i=5;i<10;i++){
		for(j=0;j<5;j++){
			if(table[i][j]==-1)printf("*");
			else printf("%d",table[i][j]);
			if(j<4)printf(" ");
		}
		printf("\n");
	}
	return 0;
}
