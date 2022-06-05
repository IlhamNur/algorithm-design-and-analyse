#include <iostream>
using namespace std;

void ByWeight(int num, float weight[], float profit[], float density[], float capacity) {
	
	float x[6], total_profit = 0, temp;
	int i, j, u = capacity;
	
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
	
 	cout << "Weight per Items is: ";  	
	for (i = 0; i < num; i++) {
	    if (weight[i] > u){
	      	x[i] = 0;
	        break;
		}else {
	        x[i] = 1;
	        total_profit = total_profit + profit[i];
	        u = u - weight[i];
	        cout << weight[i] << "  ";
		}
   }
   cout << "\nWeight total is: " << capacity - u;
   cout << "\nProfit total is: " << total_profit;
}

void ByProfit(int num, float weight[], float profit[], float density[], float capacity) {
	
	float x[6], total_profit = 0, temp;
	int i, j, u = capacity;
	
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
	
 	cout << "Weight per Items is: ";  	
	for (i = 0; i < num; i++) {
	    if (weight[i] > u){
	      	x[i] = 0;
	        continue;
		}else {
	        x[i] = 1;
	        total_profit = total_profit + profit[i];
	        u = u - weight[i];
	        cout << weight[i] << "  ";
		}
   }
   cout << "\nWeight total is: " << capacity - u;
   cout << "\nProfit total is: " << total_profit;
}

void ByDensity(int num, float weight[], float profit[], float density[], float capacity) {
	
	float x[6], total_profit = 0, temp;
	int i, j, u = capacity;
	
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
	
 	cout << "Weight per Items is: ";  	
	for (i = 0; i < num; i++) {
	    if (weight[i] > u){
	      	x[i] = 0;
	        continue;
		}else {
	        x[i] = 1;
	        total_profit = total_profit + profit[i];
	        u = u - weight[i];
	        cout << weight[i] << "  ";
		}
   }
   cout << "\nWeight total is: " << capacity - u;
   cout << "\nProfit total is: " << total_profit;
}

int main(){
	int num = 6, i, j;
	float weight[num] = {200, 100, 90, 40, 20, 10};
	float profit[num] = {80, 70, 36, 8, 20, 4};
	float density[num] = {0.4, 0.7, 0.2, 1.0, 0.4};
	float capacity;

	cout << "Masukkan Kapasitas Knapsack:  ";
	cin >> capacity;
	cout << endl;
	 
	cout << "Knapsack by Weight:  \n"; 
	ByWeight(num, weight, profit, density, capacity);
	cout << endl;
	cout << endl;
	cout << "Knapsack by Profit:  \n";
	ByProfit(num, weight, profit, density, capacity);
	cout << endl;
	cout << endl;
	cout << "Knapsack by Density:  \n";
	ByDensity(num, weight, profit, density, capacity);
	cout << endl;
	cout << endl;
	return(0);
}
