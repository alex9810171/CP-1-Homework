#include <stdio.h>
int i=1,j=1,blockYmiddle,blockX,blockY,starbegin,starend;
int main(void){
	while(scanf("%d",&starbegin)!=EOF){
		blockX=(starbegin*2)-1;
		blockY=blockX;
		blockYmiddle=starbegin;
		starend=starbegin;
		while(j<=blockY){
			while(j<=blockYmiddle){
				for(i=1;i<=blockX;i++){
					if(i>=starbegin&&i<=starend){
						printf("*");
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
				j=j+1;
				starbegin=starbegin-1;
				starend=starend+1;
			}
			starbegin=starbegin+1;
			starend=starend-1;
			while(j>blockYmiddle&&j<=blockY){
				starbegin=starbegin+1;
				starend=starend-1;
				for(i=1;i<=blockX;i++){
					if(i>=starbegin&&i<=starend){
						printf("*");
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
				j=j+1;
			}
		}
		i=1,j=1;
	}
	return 0;
}
