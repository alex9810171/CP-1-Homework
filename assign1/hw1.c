#include<stdio.h>

int main(void){
	int hand1,hand2,stair1=1,stair2=1,i=1,j=1;
	printf("the game starts\n");
	printf("1\n");
	printf("----------\n");
	printf("2\n");
	printf("\n");
	while((stair1<10&&stair2<10)&&(scanf("%d,%d",&hand1,&hand2)!=EOF)){
			if(hand1==hand2){
                 printf("even\n");
                 while((i<stair1)&&(i<10)){
                     printf(" ");
                     i=i+1;
                 }
				 i=1;
                 printf("1\n");
                 printf("----------\n");
                 while((j<stair2)&&(j<10)){
                     printf(" ");
                     j=j+1;
                 }
				 j=1;
                 printf("2\n");
                 printf("\n");
			}
			else if((hand1==1&&hand2==0)||(hand1==2&&hand2==1)||(hand1==0&&hand2==2)){
				stair1=stair1+2;
				printf("player1 beats player2\n");
				while((i<stair1)&&(i<10)){
					printf(" ");
					i=i+1;
				}
				i=1;
				printf("1\n");
		    	printf("----------\n");
				while((j<stair2)&&(j<10)){
				    printf(" ");
				    j=j+1;
				}
				j=1;
	        	printf("2\n");
		    	printf("\n");
			}
			else{
			    stair2=stair2+2;
			    printf("player2 beats player1\n");
			    while((i<stair1)&&(i<10)){
			    	printf(" ");
				    i=i+1;
				}
				i=1;
				printf("1\n");
				printf("----------\n");
				while((j<stair2)&&(j<10)){
					printf(" ");
					j=j+1;
				}
				j=1;
				printf("2\n");
				printf("\n");
			}
	}
             if(stair1>10){
				 printf("game over\n");
                 printf("player1 wins the game\n");
             }
             else if(stair2>10){
				 printf("game over\n");
                 printf("player2 wins the game\n");
			 }
	stair1=1,stair2=1;
	return 0;
}
