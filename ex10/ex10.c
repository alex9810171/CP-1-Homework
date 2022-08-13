#include <stdio.h>
typedef struct{
	int count,date,month,year,old[100];
	char name[100][50];
}data;
data d;
int main(){
	int i=0,j=0,l=0,lold=0,s=0,sold=1000000;
	scanf("%d\n",&d.count);
	for(i=0;i<d.count;i++){
		scanf("%s %d %d %d",d.name[i],&d.date,&d.month,&d.year);
		d.old[i]=(2016-d.year+1)*365+(12-d.month+1)*30+(30-d.date);
	}
	for(i=0;i<d.count;i++){
		if(d.old[i]>lold){
			lold=d.old[i];
			l=i;
		}
	}
	for(j=0;j<d.count;j++){
		if(d.old[j]<sold){
			sold=d.old[j];
			s=j;
		}
	}
	printf("%s\n%s\n",d.name[s],d.name[l]);
	return 0;
}
