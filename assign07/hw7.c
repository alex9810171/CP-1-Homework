#include <stdio.h>
#include <string.h>
char table[16][10]={"A","B","C","D","E","Taipei","Banqiao","Taoyuan","Hsinchu","Miaoli","Taichung","Changhua","Yunlin","Chiayi","Tainan","Zuoying"};
void cut(char tname2[50],char tfrom[10]){
	int a,b;
	a=strlen(tname2); b=strlen(tfrom);
	tname2[a-1]='\0'; tfrom[b-1]='\0';
}
int strtonum(char *word){
	int a=0;
	if(*(word+1)=='='){
		*(word+1)='\0';
	}
	while((strcmp(word,table[a])!=0)&&a<17){
		a++;
	}
	return a+1;
}
int main(){
	int data[30000][6]={{0}},id,car,row,i=0,j=0,k=0;//id,car,row,line,from,to;
	char cmd[20],unused[50],unused2[50],seat='\0',tname1[50],tname2[50],tfrom[10],tto[10],name1[30000][50],name2[30000][50];
	scanf("%s\n",unused);
	printf("=REQUEST-BEGIN=\n");
	while((scanf("%s %d, %d%c, %s %s %s %s\n",cmd,&car,&row,&seat,tname1,tname2,tfrom,tto)!=EOF)&&(cmd[0]!='=')){
		//printf("%s %d, %d%c, %s %s %s %s\n",cmd,car,row,seat,tname1,tname2,tfrom,tto);
		cut(tname2,tfrom);
		id=(car*2000)+(row*100)+(strtonum(&seat)*10);
		if(car<1||car>12||row<1||row>20||strtonum(&seat)>17){
			if(cmd[0]=='C'){
			printf("FAIL BOOK => %d, %d%s, %s %s, %s, %s\n",car,row,&seat,tname1,tname2,tfrom,tto);
			}
			else{
				printf("FAIL CANCEL BOOK => %d, %d%s, %s %s, %s, %s\n",car,row,&seat,tname1,tname2,tfrom,tto);
			}
			}
		else if(cmd[0]=='C'){
			while((i<10)&&(j==0)){
				if((strcmp(name1[id+i],tname1)!=0||strcmp(name2[id+i],tname2)!=0)&&data[id+i][0]==1&&data[id+i][1]==car&&data[id+i][2]==row&&data[id+i][3]==strtonum(&seat)&&(strtonum(tto)<=data[id+i][4]||strtonum(tfrom)>=data[id+i][5])/*&&(strtonum(tto)<=data[(id+1)+i][4]||strtonum(tfrom)>=data[(id+1)+i][5])&&(data[(id+1)+i][4]!=0)*/){
					i++;
				}
				else if(((strtonum(tto)<=data[id+i][4]||strtonum(tfrom)>=data[id+i][5])&&(data[(id+i)+1][4]==0))||(data[id][0]==0)){
					j=1;printf("SUCCEED BOOK => %d, %d%s, %s %s, %s, %s\n",car,row,&seat,tname1,tname2,tfrom,tto);
					//printf("%d %s\n",id+i,name1[id+i]);
					if(data[id+i][0]==1&&strcmp(name1[id+i],tname1)==0&&strcmp(name2[id+i],tname2)==0){
						data[id+i][0]=1;
						data[id+i][1]=car;
						data[id+i][2]=row;
						data[id+i][3]=strtonum(&seat);
						data[id+i][5]=strtonum(tto);
						strcpy(name1[id+i],tname1);
						strcpy(name2[id+i],tname2);
					}
					else{
						data[id+i][0]=1;
						data[id+i][1]=car;
						data[id+i][2]=row;
						data[id+i][3]=strtonum(&seat);
						data[id+i][4]=strtonum(tfrom);
						data[id+i][5]=strtonum(tto);
						strcpy(name1[id+i],tname1);
						strcpy(name2[id+i],tname2);
					}
				}
				else{
					j=-1;printf("FAIL BOOK => %d, %d%s, %s %s, %s, %s\n",car,row,&seat,tname1,tname2,tfrom,tto);
				}
			}
		}
		else if(cmd[0]=='D'){//1.座位錯誤 2.名稱錯誤 3.起點錯誤
			while((i<10)&&(j==0)){
				if((car==data[id+i][1])&&(row==data[id+i][2])&&(strtonum(&seat)==data[id+i][3])&&(strtonum(tfrom)>=data[id+i][4])&&(strtonum(tto)<=data[id+i][5])&&(strcmp(tname1,name1[id+i])==0)&&(strcmp(tname2,name2[id+i])==0)){
					j=1;printf("SUCCEED CANCEL BOOK => %d, %d%s, %s %s, %s, %s\n",car,row,&seat,tname1,tname2,tfrom,tto);
					if(strtonum(tfrom)==data[id+i][4]&&strtonum(tto)==data[id+i][5]){
						data[id+i][0]=0;
						data[id+i][1]=0;
						data[id+i][2]=0;
						data[id+i][3]=0;
						data[id+i][4]=0;
						data[id+i][5]=0;
						for(k=0;k<50;k++){
							name1[id+i][k]='\0';
							name2[id+i][k]='\0';
						}
					}
					if(strtonum(tfrom)==data[id+i][4]){
						data[id+i][0]=1;
						data[id+i][1]=car;
						data[id+i][2]=row;
						data[id+i][3]=strtonum(&seat);
						data[id+i][4]=strtonum(tto);
						strcpy(name1[id+i],tname1);
						strcpy(name2[id+i],tname2);
					}
					else if(strtonum(tto)==data[id+i][5]){
						data[id+i][0]=1;
						data[id+i][1]=car;
						data[id+i][2]=row;
						data[id+i][3]=strtonum(&seat);
						data[id+i][5]=strtonum(tfrom);
						strcpy(name1[id+i],tname1);
						strcpy(name2[id+i],tname2);
					}
					else{
						data[id+i][0]=0;
						data[id+i][1]=0;
						data[id+i][2]=0;
						data[id+i][3]=0;
						data[id+i][4]=0;
						data[id+i][5]=0;
						for(k=0;k<50;k++){
							name1[id+i][k]='\0';
							name2[id+i][k]='\0';
						}
					}
				}//位置起點名稱正確
				else if((car==data[id+i][1])&&(row==data[id+i][2])&&(strtonum(&seat)==data[id+i][3])){
					i++;
				}//位置正確
				else{
					j=-1;printf("FAIL CANCEL BOOK => %d, %d%s, %s %s, %s, %s\n",car,row,&seat,tname1,tname2,tfrom,tto);
				}
			}
		}
		i=0;j=0;
	}
	scanf("%s\n%s",unused,unused2);
	printf("=REQUEST-END=\n*-*-*-*-*-*-*-*-*-*\n=REPORT-FORM-BEGIN=\n");
	while((scanf("%s %d, %d%c, %s %s\n",cmd,&car,&row,&seat,tname1,tname2)!=EOF)&&(cmd[0]!='=')){
		if(car<1||car>12||row<1||row>20||strtonum(&seat)==17){
			printf("LOOK-SEAT =>\nEMPTY\n");
		}
		else{
			id=(car*2000)+(row*100)+(strtonum(&seat)*10);i=0;j=0;
			while(j==0){
				if((car==data[id+i][1])&&(row==data[id+i][2])&&(strtonum(&seat)==data[id+i][3])&&(strcmp(tname1,name1[id+i])==0)&&(strcmp(tname2,name2[id+i])==0)){
					j=1;printf("LOOK-SEAT =>\n%s %s : %s -> %s\n",tname1,tname2,table[(data[id+i][4])-1],table[(data[id+i][5])-1]);
				}
				else if((car==data[id+i][1])&&(row==data[id+i][2])&&(strtonum(&seat)==data[id+i][3])){
					i++;
				}
				else{
					j=-1;printf("LOOK-SEAT =>\nEMPTY\n");
					/*printf("%d %s\n",id+i,name1[id+i]);*/
				}
			}
		}
	}
	printf("=REPORT-FORM-END=\n");
	return 0;
}
