#include <stdio.h>

int main(void){
	float height;
	int weight;
	float BMI;
	// declare the bmi varible here
	printf("Please enter your height (in meters)\n");
	// scan the height of user here
	scanf("%f",&height);
    // print the height input
	printf("%.2f\n",height);
	printf("Please enter your weight (in kilograms)\n");
	// scan the weight of user here
	scanf("%d",&weight);
    // print the weight input
	printf("%d\n",weight);
	// Count BMI here
	BMI = weight /(height*height);
	if (BMI > 31.5 || BMI < 16.5	/* write the condition here */){
		printf("you don't have to fulfill your mandatory military service\n");
	}else{
		printf("you have to fulfill your mandatory military service\n");
	}
	return 0;
}

