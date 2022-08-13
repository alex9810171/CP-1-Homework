#include <stdio.h>
int main(){
	int year=0,c=0,y=0,m=0,d=0,w=0;
	while(scanf("%d %d %d\n",&year,&m,&d)!=EOF){
		if(m==1){
			m=13;
			year-=1;
		}
		else if(m==2){
			m=14;
			year-=1;
		}
		c=(year-year%100)/100;
		y=year%100;
		w=(y+(y/4)+(c/4)-2*c+26*(m+1)/10+d-1);
		if(w<0)w=(w%7+7)%7;
		else w=w%7;
		printf("%d\n",w);
	}
	return 0;
}
