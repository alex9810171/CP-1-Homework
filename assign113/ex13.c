#include<stdio.h>
#include<math.h>
int main(int args, char *argv[]){
	int quit = 0;
	int menu;
	int count=0,a=0;
	//case 1
	int data1[100]={0},target=0,number=0;
	//case 2
	int max=0,data2[100]={0};
	//case 3
	int num=0,prime=0;
	//
	while(!quit){
		printf("=======MENU=========\n"
				"1 - Element Count\n"
				"2 - Max Number\n"
				"3 - Prime Number\n"
				"4 - EXIT\n");
		scanf("%d" , &menu);
		getchar();
		switch(menu){
			case 1:
				scanf("%d",&count);
				for(a=0;a<count;a++)scanf("%d",&data1[a]);
				scanf("%d",&target);
				for(a=0;a<count;a++)if(data1[a]==target)number++;
				printf("%d\n",number);
				number=0;
				//print the occurrence count of the specific element
				break;
			case 2:
				scanf("%d",&count);
				for(a=0;a<count;a++){
					scanf("%d",&data2[a]);
					if(data2[a]>max)max=data2[a];
				}
				printf("%d\n",max);
				max=0;
				// print max number of sequence
				break;
			case 3:
				scanf("%d",&num);
				for(a=2;a<sqrt(num)&&prime==0;a++)if(num%a==0)prime=-1;
				if(prime==0)printf("Yes\n");
				else printf("No\n");
				prime=0;
				//judge the number is prime number or not
				break;
			case 4:
				quit = 1;
				break;
			default:
				printf("Unrecognized choice\n");
		}
		printf("\n");

	}
	return 0;
}
