#include <iostream> 
#include <fstream> 
#include <map> 
#include <vector>
#include <cstring> 

using namespace std;

#define MAX 1000

char name1[MAX], name2[MAX]; 
FILE *f1, *f2;

bool match (char c) {
        return ((c == ' ') || (c == '\t') || (c == '+') || (c == '-') || (c == '*') || 
                (c == '/') || (c == '\\') || (c == ':') || (c == ',') || (c == ';') || 
                (c == '"') || (c == '\'') || (c == '>') || (c == '<') || (c == '=') || 
                (c == '.') || (c == '&') || (c == '!') || (c == '(') || (c == ')') || 
                (c == '[') || (c == ']') || (c == '{') || (c == '}') || (c== '#') || 
                (c == '?') || (c == '%') || (c == '$') || (c == '^'));
}

void matching (char const* name1, char const* name2) {
        char temp[MAX], temp2[MAX]; 
        bool match = true; 
        f1 = fopen (name1, "r"); 
        f2 = fopen (name2, "r");
                
        while ((fscanf (f1, "%s", temp) != EOF) && match) 
        {
                if (fscanf (f2,"%s",temp2) == EOF) 
                        match = false;
                else 
                        match = strcmp(temp, temp2) == 0; 
        }
        if (match) 
        {
                if (fscanf (f2,"%s",temp2) == EOF) 
                        cout << "Kedua file memiliki kemiripan\n";
                else 
                        cout << "Kedua file berbeda\n";
        } 
        else cout<< "Kedua file berbeda\n";
        fclose(f2); 
        fclose(f1);
}

void convert (char const * name, char const * name2) {
        string temp, temp2; 
        map <string, int> a; 
        vector <string> s; 
        char tempc[100]; 
        f1 = fopen (name2, "w");
        ifstream input (name , ifstream::in);
        int i, j, n;  
        char c;

        while (getline (input, temp)) {
                n = temp.length(); 
                j = 0;
                for (i=0; i < n; ++i) {
                        c = temp[i]; 
                        if (match(c)) {
                                if (j < i) {
                                        temp2 = temp.substr(j, i-j); 
                                        j = a[temp2]; 
                                        if (!j) {
                                                j = s.size(); 
                                                a[temp2] = j; 
                                                if (j > 0) {
                                                        itoa(j, tempc, 10); 
                                                        s.push_back ("a" + (string)tempc); 
                                                }
                                                else s.push_back ("a0"); 
                                        } 
                                        fprintf(f1, "%s ", s[j].c_str()); 
                                }
                                if ((c != ' ') && (c != '\t')) 
                                        fprintf (f1, "%c", c);
                                j = i+1; 
                        } 
                        else if ((c <= '9') && (c>='0') && (i==j)) {
                                do 
                                        ++i; 
                                while ((i < n) && (!match(temp[i]))); 
                                temp2 = temp.substr(j,i-j).c_str(); 
                                fprintf(f1, "%s ", temp2.c_str()); 
                                j = i+1;
                        } 
                }
                if (j < i) {
                        fprintf(f1, "%s ", temp.substr(j, i-j).c_str()); 
                        cout << temp.substr(j, i-j) << "...\n"; 
                }
        }
        input.close(); 
        fclose(f1);
}

int main() {
        cout << "Masukkan nama file pertama : ";
        cin >> name1;

        cout << "Masukkan nama file kedua : ";
        cin >> name2;

        convert (name1, "temp1.txt");
        convert (name2, "temp2.txt");

        matching ("temp1.txt", "temp2.txt");
        return 0;
}