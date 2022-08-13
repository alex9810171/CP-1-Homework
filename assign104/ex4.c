 #include<stdio.h>
 int main(){
     int locationX,locationY,i,X,Y,distance,mindistance,station;
     while(scanf("%d %d",&locationX,&locationY)!=EOF){
         scanf("%d %d",&X,&Y);
         mindistance=(X-locationX)*(X-locationX)+(Y-locationY)*(Y-locationY);
         station=1;
         for(i=1;i<=4;i++){
             scanf("%d %d",&X,&Y);
             distance=(X-locationX)*(X-locationX)+(Y-locationY)*(Y-locationY);
             if(distance<mindistance){
                 mindistance=distance;
                 station=i+1;
             }
         }
         printf("The nearest gas station is Station Number:%d\n",station);
     }
     return 0;
 }
