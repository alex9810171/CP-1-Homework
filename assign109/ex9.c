#include <stdio.h>
#include <ctype.h>
int main(){
	int total=0,temptotal=0;
	char word;
	while(scanf("%c",&word)!=EOF){
		printf("%c",word);
		if(word=='-'){
			scanf("%c",&word);
			printf("%c",word);
			if(word=='\n'){
				printf("Total sum: %d\n",total);
				total=0;
			}
			while(isdigit(word)){
				temptotal=temptotal*10+(word-48);
				scanf("%c",&word);
				printf("%c",word);
			}
			total-=temptotal;
			temptotal=0;
			if(word=='\n'){
				printf("Total sum: %d\n",total);
				total=0;
			}
		}
		else{
			while(isdigit(word)){
				temptotal=temptotal*10+(word-48);
				scanf("%c",&word);
				printf("%c",word);
			}
			total+=temptotal;
			temptotal=0;
			if(word=='\n'){
				printf("Total sum: %d\n",total);
				total=0;
			}
		}
	}
	return 0;
}
