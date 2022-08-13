#include<stdio.h>

int main(){
	int number=0,quotient=0,remainder=0,i=0,j=0;
		while(scanf("%d",&number)!=EOF){
			quotient=number/10;
			remainder=number%10;
			switch(quotient){
				case 1 ... 3:
					for(i=1;i<=quotient;i++){
						printf("X");
					}
					break;
				case 4:
					printf("XL");
					break;
				case 5 ... 8:
					printf("L");
					for(i=1;i<=quotient-5;i++){
						printf("X");
					}
					break;
				case 9:
					printf("XC");
					break;
				case 10:
					printf("C");
				default:
					break;
			}
			switch(remainder){
				case 1 ... 3:
					for(j=1;j<=remainder;j++){
						printf("I");
					}
					printf("\n");
					break;
				case 4:
					printf("IV\n");
					break;
				case 5 ... 8:
					printf("V");
					for(j=1;j<=remainder-5;j++){
						printf("I");
					}
					printf("\n");
					break;
				case 9:
					printf("IX\n");
					break;
				default:
					printf("\n");
					break;
			}
		}
	return 0;
}
