#include <stdio.h>
#include <math.h>

int isanobissexto(int ano){
    return ((ano % 4 == 0) &&
            (ano %100 != 0)) ||
            (ano % 400==0);
}

int isdata(int mes,ano){
	switch (mes){
		case 1: return 3;
		case 3: return 3;
		case 5: return 3;
		case 7: return 3;
		case 8: return 3;
		case 10: return 3;
		case 12: return 3;
		case 4: return 2;
		case 6: return 2;
		case 9: return 2;
		case 11: return 2;
		case 2: return isanobissexto(ano);
		default: return -1;
	}



}


int main(){
	int diaI = 23,
		mesI = 3,
		anoI = 2000,
	int diaF = 30,
		mesF = 5,
		anoF = 2017,
	int diaT=0,
		diaC,
		mesT=1,
		anoT=1900;
	mesI-=1;
	for(anoI;anoI>1900;anoI--){
		for(;mesI>0;mesI--){
			diaI= diaI + (28+isdata(mesI,anoI));
		}
		mesI=12;
	}
	mesF-=1;
	for(anoF;anoF>1900;anoF--){
		for(;mesF>0;mesF--){
			diaF= diaF + (28+isdata(mesF,anoF));
		}
		mesF=12;
	}
	diaC=diaF-diaI;

	for(;diaC>31;anoT++){
		for(;mesT<=12;mesT++){
			diaC = diaC - (28+isdata(mesT,anoT));
		}
		mesT=1;
	}
	switch diaC{
		case <=28: diaT = diaC;
		case 30:{
			if(mesT != 2){
				diaT = diaC;
			}else{
				diaT = diaC - (28+isanobissexto(mesT,anoT));
				mesT++;
			}
		}
		case 29:{
			if(mesT != 2){
				diaT = diaC;
			}else if(isanobissexto(mesT,anoT)){
				diaT = diaC;
			}else{
				diaT=1;
				mesT++;
			}
		}
		case 31: ;
	}





}