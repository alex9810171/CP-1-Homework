#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc, char *argv[]){
	int menu = 0;
	int quit = 0;
	int a=0,b=0,c=0,d=0;
	//case 1
	int x[3],y[3],inner;
	//case 2
	int elenum=0,ele[1000];
	//case 3
	char word[100];
	//case 4
	int sq1[4]={0},sq2[4]={0},sq=0;
	//case 5
	int k=0,n=0,per=1;
	//
	while(!quit){
		printf( "=======MENU=========\n"
				"1 - Inner Product\n"
				"2 - Unique Element\n"
				"3 - Capitalization\n"
				"4 - Overlapping Area\n"
				"6 - Permutation\n"
				"7 - EXIT\n"
				"====================\n"
				"Enter Your choice:\n") ;
		scanf( "%d", &menu ) ;
		getchar();
		switch( menu ) {
			case 1:
				scanf("%d %d %d",&x[0],&x[1],&x[2]);
				scanf("%d %d %d",&y[0],&y[1],&y[2]);
				inner=x[0]*y[0]+x[1]*y[1]+x[2]*y[2];
				printf("%d\n",inner);
				// Inner Product
				break;
			case 2:
				scanf("%d",&elenum);
				for(a=0;a<elenum;a++)scanf("%d",&ele[a]);
				for(a=0;a<elenum;a++){
					for(b=a+1;b<elenum;b++){
						if(ele[b]==ele[a]){
							for(c=b;c<elenum;c++)ele[c]=ele[c+1];
							ele[elenum-1]=0;
							elenum--;
						}
					}
				}
				for(a=0;a<elenum;a++)printf("%d ",ele[a]);
				// Unique Element
				break;
			case 3:
				scanf("%s",word);
				if(word[0]>=97&&word[0]<=122)word[0]=word[0]-32;
				for(a=1;a<100;a++){
					if(word[a]>=65&&word[a]<=90)word[a]=word[a]+32;
				}
				printf("%s\n",word);
				memset(word,'\0',100);
				// Capitalization
				break;
			case 4:
				scanf("%d %d %d %d",&sq1[0],&sq1[1],&sq1[2],&sq1[3]);
				scanf("%d %d %d %d",&sq2[0],&sq2[1],&sq2[2],&sq2[3]);
				if(sq1[2]<sq2[0]||sq1[3]<sq2[1]){
					printf("0\n");
				}
				else{
					sq=(sq1[2]-sq2[0])*(sq1[3]-sq2[1]);
					printf("%d\n",sq);
				}
				// Overlapping Area
				break;
			case 6:
				scanf("%d %d",&n,&k);
				for(a=0;a<k;a++)per=per*(n-a);
				printf("%d\n",per);
				per=1;
				// Permutation
				break;
			case 7:
				quit = 1;
				break;
			default :
				printf( "Wrong choice!\n") ;
				break;
		}
		printf("\n");
	}

	return 0;
}
