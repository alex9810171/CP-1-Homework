#include <stdio.h>
#include <string.h>
int main(){
	int choice=0;
	char Aname1[50],Aname2[50],Bname1[50],Bname2[50];
	while(scanf("%s %s\n%s %s\n%d\n",&Aname1,&Aname2,&Bname1,&Bname2,&choice)!=EOF){
		if(choice==0){
		}
		else if(choice==1){
			strcpy(Bname2,Aname2);
		}
		else if(choice==2){
			strcpy(Aname2,Bname2);
		}
		printf("%s %s and %s %s are couple now! \n",Aname1,Aname2,Bname1,Bname2);
	}
	return 0;
}
