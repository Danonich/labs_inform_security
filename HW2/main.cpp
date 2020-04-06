#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class cipher
{
public:

    const int ABCSize = 26;
    const char low_ch[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alph[26];
    string input_s;
    string output_s;
    string str;

    string read_file() {
        ifstream readable;
        readable.open("unencripted.txt", ios::in);
        getline(readable, str);
        readable.close();
        return str;
    }


    string keygen()
    {
        srand(time(NULL));
        for (int i = 0; i < 26; i++)
        {
            alph[i] = low_ch[rand() % ABCSize];
            for (int k = 0; k < i; k++) {
                if (alph[k] == alph[i])
                    i = i - 1;
            }
        }

        string str("");
        ofstream write;
        write.open("key.txt", ios::out);
        for (int i = 0; i < 26; i++)
            write << low_ch[i] << " --> " << alph[i] << endl;
        write.close();

    }

    string simple_sub()
    {
        input_s = str;
        string output_s("");
        for (int i = 0; i < input_s.length(); i++)
        {
            
            for (int j = 0; j < ABCSize; j++)
            {
                if (input_s[i] == low_ch[j])
                {
                    input_s[i] = alph[j];
                    break;
                }
            }
        }
        return output_s;
    }

    string simple_sub_decrypt()
    {
        input_s = str;
        string output_s("");
        for (int i = 0; i < input_s.length(); i++)
        {

            for (int j = 0; j < ABCSize; j++)
            {
                if (input_s[i] == alph[j])
                {
                    input_s[i] = low_ch[j];
                    break;
                }
            }
        }
        return output_s;
    }

  
    string write_file()
    {
        string str("");
        ofstream write;
        write.open("cripted.txt", ios::out);
        write << input_s;
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
    simple.keygen();
    if (ans == 1) {
        system("cls");
        simple.simple_sub();
        simple.write_file();
    }
    else if (ans == 0) {
        system("cls");
        simple.simple_sub_decrypt();
        simple.write_file();
    }
    else {
        printf("Ошибка!");
        printf("Вы должны были ввести 0 или 1!");
        _getch();
    }
    system("pause");
    return 0;
}
