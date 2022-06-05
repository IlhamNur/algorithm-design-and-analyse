#include <iostream>

using namespace std;

#define INF 999

int main() {
    int i, j, source, target, start, minimum, m, update, ver, min_weight;
    cout << "Masukkan Jumlah Vertex / Node yang diinginkan : "; 
    cin >> ver; 
    ver++;
    int weight[ver][ver], buff[ver], path[ver], prev[ver], visited[ver]={0};

    for(i = 1; i < ver; i++) {
        buff[i] = INF;
        prev[i] = -1;
        path[i] = 0;
        for(int j = 1;j < ver; j++) {
            weight[i][j] = INF;
        }
    }

    for(i = 1;i < ver; i++) {
        for(j = i+1; j < ver; j++)
        {
            cout << "Masukkan bobot " << i << " ke " << j << " (masukkan 999 untuk representasi Infinity) : "; 
            cin >> weight[i][j];
            weight [j][i] = weight[i][j];
        }   
        cout << "\n";
    }

    cout << "Masukkan Vertex / Node Awal : "; 
    cin >> source;
    cout << "Masukkan Vertex / Node Tujuan : "; 
    cin >> target;
    
    start = source;
    visited[start]=1;
    buff[start] = 0;

    while(visited[target] == 0) {
        minimum = INF;
        m = 0;
        for(i=1;i< ver;i++) {
            update = buff[start] + weight[start][i];
            if(update < buff[i] && visited[i]==0) {
                buff[i] = update;
                prev[i] = start;
            }
            if(minimum > buff[i] && visited[i]==0) {
                minimum = buff[i];
                m = i;
            }
        } 
        start = m;
        visited[start] = 1;
    }

    min_weight = buff[target];

    start = target;
    j = 0;

    while(start != -1) {
        path[j] = start;
        start = prev[start];
        j++;
    }

    cout << "\nBobot terkecil yang dilalui adalah " << min_weight << "\n";
    cout << "Jalur yang ditempuh adalah : ";

    for (int i = ver-1; i >= 0; i--) {
        if (path[i] != 0) {
            cout << path[i] << " ";
        }
    } 
    cout << "\n";
}