#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class cipher
{
public:

    bool is_alphavet = false;
    const char low_ch[5][5] = {
    { 'a', 'b', 'c', 'd', 'e' },
    { 'f', 'g', 'h', 'i', 'k' },
    { 'l', 'm', 'n', 'o', 'p' },
    { 'q', 'r', 's', 't', 'u' },
    { 'v', 'w', 'x', 'y', 'z' }
};
    string input_s, output_s, str;

    string read_file() {
        ifstream readable;
        readable.open("unencripted.txt", ios::in);
        getline(readable, str);
        readable.close();
        return str;
    }

   string polybius()
   {
        input_s = str;
        for (int i = 0; i < input_s.length(); i++){            
            for(int m = 0; m < 5; m++){
                for (int j = 0; j < 5; j++){
                   if(input_s[i] == low_ch[m][j]) {
                        if (input_s[i] == low_ch[4][j]) 
                        output_s += low_ch[0][j];
                        else
                        output_s += low_ch[m + 1][j];
                   }
                }
        }
        if(input_s[i] == ' ' || input_s[i] == 'j')
            output_s += input_s[i];}
        return output_s;
    }

   string polybius_decrypt()
    {
       input_s = str;
        for (int i = 0; i < input_s.length(); i++){            
            for(int m = 0; m < 5; m++){
                for (int j = 0; j < 5; j++){
                    if (input_s[i] == low_ch[m][j]) {
                        if (input_s[i] == low_ch[0][j])
                            output_s += low_ch[4][j];
                        else
                            output_s += low_ch[m - 1][j];
                    }
                }
             }
       if(input_s[i] == ' ' || input_s[i] == 'j')
            output_s += input_s[i];}
        return output_s;
    }
  
    string write_file()
    {
        string str("");
        ofstream write;
        write.open("cripted.txt", ios::out);
        write << output_s;
        write.close();
        return str;
    }
};
    
    
int main()
{
        setlocale(LC_ALL, "");
        int ans;
        cout << "Пожалуйста введите 1 для шифрования, 0 для дешифрования \n";
        cin >> ans;
        cipher simple;
        simple.read_file();
        if (ans == 1) {
            system("cls");
            simple.polybius();
            simple.write_file();
        }
        else if (ans == 0) {
            system("cls");
            simple.polybius_decrypt();
            simple.write_file();
        }
        else {
            printf("Ошибка!");
            printf("Вы должны были ввести 0 или 1!");
            _getch();
        }
        system("pause");
        return 0;
        return 0;
}
