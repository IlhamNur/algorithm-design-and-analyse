// file Mahasiswa.cpp 

#include <iostream>
 
using namespace std;

class Mahasiswa{ 
private :
	string nama;
	char jenisKelamin; 
	string alamat;
public :
	// input data
	void input_data(string a, char b, string c){
		nama = a;
		jenisKelamin = b;
		alamat = c;
	}
	// tampil data
	void tampil_data(){
		cout << "nama mhs : " << nama << endl; 
		cout << "jenis kelamin mhs : " << jenisKelamin << endl; 
		cout << "alamat mhs : " << alamat << endl;
	}
}; 

int main(){
	Mahasiswa mhs;
	mhs.input_data("Dennis Ritchie", 'L', "Sukoharjo");
	mhs.tampil_data();
}
