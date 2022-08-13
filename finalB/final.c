#include<stdio.h>

int main(int argc,char *argv[]){
	int a=0,temp=0,len=0,data[1000]={0},count=0;
	FILE *data1,*data2;
	data1=fopen(argv[1],"r");
	printf("hello\n");
	while(fscanf(data1,"%d",&data[count])!=EOF){
		count++;
	}
	fclose(data1);
	data2=fopen(argv[2],"r");
	while(fscanf(data2,"%d",&data[count])!=EOF){
		count++;
	}
	fclose(data2);
	len=count;
	for(a=0;a<len;a++){
		if(data[a]>data[a+1]){
			temp=data[a];
			data[a]=data[a+1];
			data[a+1]=data[a];
		}
		if(a>=len-1){
			len--;
		}
	}
	for(a=0;a<count-1;a++)printf("%d ",data[a]);
	printf("%d\n",data[count]);
	return 0;
}
