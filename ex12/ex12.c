#include<stdio.h>
#include<string.h>
int main(int args, char *argv[]){
	int quit = 0;
	int menu;
	//2
	int num=0,a=0;
	float score[1000],total=0,avg=0;
	//3
	int year=0;
	//4
	int b=0,c=0,ntrue=0;
	char word[100];
	//
	while(!quit){
		printf("=======MENU=========\n"
				"1 - Print Hello World\n"
				"2 - Calculate Average\n"
				"3 - Judge Leap Year\n"
				"4 - Palindromes\n"
				"5 - EXIT\n");
		scanf("%d" , &menu);
		getchar();
		switch(menu){
			case 1:
				printf("Hello World\n");
				//print hello world
				break;
			case 2:
				scanf("%d",&num);
				if(num==0){
					printf("No Number\n");
					break;
				}
				for(a=0;a<num;a++){
					scanf("%f",&score[a]);
					total+=score[a];
				}
				avg=total/num;
				printf("%.2f\n",avg);
				if(avg>=60)printf("PASS\n");
				else printf("NOT PASS\n");
				total=0;
				// calculate average and tell whether passing or not
				break;
			case 3:
				scanf("%d",&year);
				if((year%400==0)||(year%4==0&&year%100!=0))printf("Leap Year\n");
				else printf("Not Leap Year\n");
				//judge one year is leap year or not
				break;
			case 4:
				gets(word);
				for(b=0;word[b]!='\0';b++){
				}
				for(c=0;(c<b/2)&&ntrue==0;c++){
					//printf("word[c]=%c word[b-c-1]=%c c=%d b-c-1=%d",word[c],word[b-c-1],c,b-c-1);
					if(word[c]!=word[b-c-1])ntrue=-1;
				}
				if(ntrue==-1)printf("No\n");
				else printf("Yes\n");
				memset(word,'\0',100);
				ntrue=0;
				//Judge string whether is palindromes
				break;
			case 5:
				quit = 1;
				break;
			default:
				printf("Unrecognized choice\n");
		}
		printf("\n");

	}
	return 0;	
}
