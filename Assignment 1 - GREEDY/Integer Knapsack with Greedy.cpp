#include <iostream>
using namespace std;

void ByWeight(int num, float weight[], float profit[], float density[], float kapasitas) {
	
	float x[num], tp = 0, temp;
	int i, j, u = kapasitas;
	
	for (i = 0; i < num; i++) {
	    for (j = i + 1; j < num; j++) {
	        if (weight[i] > weight[j]) {
	            temp = weight[j];
	            weight[j] = weight[i];
	            weight[i] = temp;
	 
	            temp = profit[j];
	            profit[j] = profit[i];
	            profit[i] = temp;
	            
	            temp = density[j];
	            density[j] = density[i];
	            density[i] = temp;
	        }
	    }
	}
	
 	cout << "Weight setiap item adalah: ";  	
	for (i = 0; i < num; i++) {
	    if (weight[i] > u){
	      	x[i] = 0;
	        break;
		}else {
	        x[i] = 1;
	        tp = tp + profit[i];
	        u = u - weight[i];
	        cout << weight[i] << "  ";
		}
   }
   cout << "\nWeight total adalah: " << kapasitas - u;
   cout << "\nProfit total adalah: " << tp;
}

void ByProfit(int num, float weight[], float profit[], float density[], float kapasitas) {
	
	float x[num], tp = 0, temp;
	int i, j, u = kapasitas;
	
	for (i = 0; i < num; i++) {
	    for (j = i + 1; j < num; j++) {
	        if (profit[i] < profit[j]) {
	        	temp = profit[j];
	            profit[j] = profit[i];
	            profit[i] = temp;
	            
				temp = weight[j];
	            weight[j] = weight[i];
	            weight[i] = temp;
	            
	            temp = density[j];
	            density[j] = density[i];
	            density[i] = temp;
	        }
	    }
	}
	
 	cout << "Weight setiap item adalah: ";  	
	for (i = 0; i < num; i++) {
	    if (weight[i] > u){
	      	x[i] = 0;
	        continue;
		}else {
	        x[i] = 1;
	        tp = tp + profit[i];
	        u = u - weight[i];
	        cout << weight[i] << "  ";
		}
   }
   cout << "\nWeight total adalah: " << kapasitas - u;
   cout << "\nProfit total adalah: " << tp;
}

void ByDensity(int num, float weight[], float profit[], float density[], float kapasitas) {
	
	float x[num], tp = 0, temp;
	int i, j, u = kapasitas;
	
	for (i = 0; i < num; i++) {
	    for (j = i + 1; j < num; j++) {
	        if (density[i] < density[j]) {
	        	temp = density[j];
	            density[j] = density[i];
	            density[i] = temp;
	 
	            temp = weight[j];
	            weight[j] = weight[i];
	            weight[i] = temp;
	 
	            temp = profit[j];
	            profit[j] = profit[i];
	            profit[i] = temp;
	        }
	    }
	}
	
 	cout << "Weight setiap item adalah: ";  	
	for (i = 0; i < num; i++) {
	    if (weight[i] > u){
	      	x[i] = 0;
	        continue;
		}else {
	        x[i] = 1;
	        tp = tp + profit[i];
	        u = u - weight[i];
	        cout << weight[i] << "  ";
		}
   }
   cout << "\nWeight total adalah: " << kapasitas - u;
   cout << "\nProfit total adalah: " << tp;
}

int main(){
	float weight[] = {200, 100, 90, 40, 20, 10};
	float profit[] = {80, 70, 36, 8, 20, 4};
	float kapasitas = 100;
	int num = sizeof(profit) / sizeof(profit[0]);
	int i, j;
	float density[num];
	 
	for (i = 0; i < num; i++) {
    	density[i] = profit[i] / weight[i];
	}
	
	cout << "Greedy by Weight:  \n"; 
	ByWeight(num, weight, profit, density, kapasitas);
	cout << endl;
	cout << endl;
	cout << "Greedy by Profit:  \n";
	ByProfit(num, weight, profit, density, kapasitas);
	cout << endl;
	cout << endl;
	cout << "Greedy by Density:  \n";
	ByDensity(num, weight, profit, density, kapasitas);
	cout << endl;
	cout << endl;
	return(0);
}
