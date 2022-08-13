#include <stdio.h>

int main()
{
	int A=0,B=0,C=0,D=0,printin=0,total=0,number=0,i=0,j=0,k=0,l=0;
	float average=0;
	while(scanf("%d",&printin)!=EOF){
		if(printin != -1){
		if (80<=printin&&printin<=100){
			++A;
			number=number+1;
			total=total+printin;
		}
		else if(70<=printin&&printin<=79){
			++B;
			number=number+1;
			total=total+printin;
		}
		else if(60<=printin&&printin<=69){
			++C;
			number=number+1;
			total=total+printin;
		}
		else if(0<=printin&&printin<=59){
			++D;
			number=number+1;
			total=total+printin;
		}
	}
	else{
	average=(float)total/number;
	printf("Score :\n");
	printf("A:");
	while(i<A){
		printf("*");
		++i;
	}
	printf("\n");
	printf("B:");
	while(j<B){
		printf("*");
		++j;
	}
	printf("\n");
	printf("C:");
	while(k<C){
	    printf("*");
		++k;
	}
	printf("\n");
	printf("D:");
	while(l<D){
		printf("*");
		++l;
	}
	printf("\n");
	printf("Amount:%d",number);
	printf(" Average:%.3f\n",average);
	printf("-------------------------\n");
	total=0,number=0,average=0;
	}
	}
return 0;
}
