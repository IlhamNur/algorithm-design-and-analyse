#include<iostream>

using namespace std;

class Siswa {
    public:
    string Nama;
    double IPK;
    
    void printNama() {
	cout << "Nama : " << Nama << endl;
    }

    void printIPK() {
	cout << "IPK : " << IPK << endl;
    }
};

int main (){
    Siswa data1;
    data1.Nama = "Ilham";
    data1.IPK = 3.99;
    
    data1.printNama();
    data1.printIPK();
    
    return 0;
}
