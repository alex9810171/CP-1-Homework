#include <stdio.h>

int main(){
	int width,length,x=1,y=1,direction,step,face=0;//face 0=north,1=west,2=east,3=south
	scanf("%d %d",&width,&length);
	while((x>=1&&x<=width&&y>=1&&y<=length)&&(scanf("%d %d",&direction,&step)!=EOF)){
		if((face==0&&direction==0)||(face==1&&direction==2)||(face==2&&direction==1)){
			x=x,y=y+step;
			face=0;
			if(x<1||x>width||y<1||y>length){
			}
			else{
				printf("Arrived at (%d,%d)\n",x,y);
			}
		}
		else if((face==1&&direction==0)||(face==0&&direction==1)||(face==3&&direction==2)){
			x=x-step,y=y;
			face=1;
			if(x<1||x>width||y<1||y>length){
			}
			else{
				printf("Arrived at (%d,%d)\n",x,y);
			}
		}
		else if((face==2&&direction==0)||(face==3&&direction==1)||(face==0&&direction==2)){
			x=x+step,y=y;
			face=2;
			if(x<1||x>width||y<1||y>length){
			}
			else{
				printf("Arrived at (%d,%d)\n",x,y);
			}
		}
		else{
			x=x,y=y-step;
			face=3;
			if(x<1||x>width||y<1||y>length){
			}			
			else{
				printf("Arrived at (%d,%d)\n",x,y);
			}
		}
	}
	if(x>width){
		x=width;
		printf("Shut down at (%d,%d)\n",x,y);
	}
	else if(y>length){
		y=length;
		printf("Shut down at (%d,%d)\n",x,y);
	}
	else if(x<1){
		x=1;
		printf("Shut down at (%d,%d)\n",x,y);
	}
	else if(y<1){
		y=1;
		printf("Shut down at (%d,%d)\n",x,y);
	}
	else{
	}
	x=1,y=1;
	return 0;
}
