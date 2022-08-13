#include <stdio.h>
#include <math.h>
int main(void){
	int pokemon[152][5]={{0}},a=1,id=0,cp=0,attack=0,defense=0,hp=0;//0num,1cp,2atk,3def,4hp
	float iv=0;
	while(scanf("%d %d %d %d %d",&id,&cp,&attack,&defense,&hp)!=EOF){
		pokemon[id][0]++;
		if(cp>pokemon[id][1]){
			pokemon[id][1]=cp;
			pokemon[id][2]=attack;
			pokemon[id][3]=defense;
			pokemon[id][4]=hp;
		}
	}
	for(a=1;a<=151;a++){
		if(pokemon[a][1]>0){
			pokemon[a][1]=pokemon[a][1]+10*(pokemon[a][0]*2-1);
			iv=pow(pokemon[a][1],2)/10*(pokemon[a][2]*sqrt(pokemon[a][3]*pokemon[a][4]));
			printf("%d %.0f\n",a,iv);
		}
	}
	return 0;
}
