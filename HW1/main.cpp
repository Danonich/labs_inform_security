#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;


const int ABCSize = 26;
const char low_ch[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

string read_file() {
    string str("");
    ifstream readable;
    readable.open("uncripted.txt", ios::in);
    getline(readable, str);
    readable.close();
    return str;
}


string caesar(string input_s) {
    int key;
    cout << "Enter key: ";
    cin >> key;
    bool Ok;
    string output_s("");
    for (int i = 0; i < input_s.length(); i++)
    {
        Ok = false;
        for (int j = 0; j < ABCSize; j++)
        {
            if (input_s[i] == low_ch[j])
            {
                j += key;
                while (j >= ABCSize) j -= ABCSize;
                while (j < 0) j += ABCSize;
                output_s += low_ch[j];
                Ok = true;
                break;
            }
        }
        if (!Ok) output_s += input_s[i];
    }
    return output_s;
}


string decode_caesar(string input_s)
{
    int key; 
    cout << "Enter key: ";
    cin >> key;
    bool Ok;
    string output_s("");
    for (int i = 0; i < input_s.length(); i++)
    {
        Ok = false;
        for (int j = 0; j < ABCSize; j++)
        {
            if (input_s[i] == low_ch[j])
            {
                j -= key;
                while (j >= ABCSize) j += ABCSize;
                while (j < 0) j -= ABCSize;
                output_s += low_ch[j];
                Ok = true;
                break;
            }

        }
        if (!Ok) output_s += input_s[i];
    }
    return output_s;
}

string write_file(string output_s)
{
    string str("");
    string line;
    ofstream write;
    write.open("cripted.txt", ios::out);
    write << output_s;
    write.close();
    return str;
}

int main()
{
    setlocale(LC_ALL, "");
    string s = read_file(),w1,w2;
    int ans;
    cout << "Пожалуйста введите 1 для шифрования, 0 для дешифрования \n";
    cin >> ans;
    if (ans == 1) {
        system("cls");
        w1 = caesar(s);
        write_file(w1);
    }
    else if (ans == 0) {
        system("cls");
        w2 = decode_caesar(s);
        write_file(w2);
    }
    else {
        printf("Ошибка!");
        printf("Вы должны были ввести 0 или 1!");
        _getch();
    }
    system("pause");
    return 0;
}
        
