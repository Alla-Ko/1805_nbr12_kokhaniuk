#include <iostream>
#include <string> 
#include <Windows.h>
#include <vector>


using namespace std;

//введення рядка string з пробілами
string Vvod_z_klavy();

//друк 1-вим вектора 0-в рядок, 1 - в стовпчик, 2 - без пробілів

template <class T> void Druk_vect1d(vector<T>& vec, int a = 0) {
    if (a == 2) {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i];
    }
    else {
        if (a == 1) {
            for (int i = 0; i < vec.size(); i++)
                cout << vec[i] << "\n";
        }
        else {
            for (int i = 0; i < vec.size(); i++)
                cout << vec[i] << "   ";
        }
    }
    cout << endl;
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\x1b[32m"; //зелений
    cout << "Кожна приголосна замінюється іншою приголосною\n";
    cout << "б в г ґ д ж з й к л м   <-->  н п р с т ф ц ч ш щ ь \n";
    cout << "Голосні зостаються без змін\n\n";
    cout << "\x1b[37m"; //білий

    string fraza1 = Vvod_z_klavy();

    vector<char> pidst1({ 'б', 'в', 'г', 'ґ', 'д', 'ж', 'з', 'й', 'к', 'л', 'м', 'Б', 'В', 'Г', 'Ґ', 'Д', 'Ж', 'З', 'Й', 'К', 'Л', 'М' });
    vector<char> pidst2({ 'н', 'п', 'р', 'с', 'т', 'ф', 'ц', 'ч', 'ш', 'щ', 'ь', 'Н', 'П', 'Р', 'С', 'Т', 'Ф', 'Ц', 'Ч', 'Ш', 'Щ', 'Ь' });

    vector<char> fraza2;
    int k = 0;
    for (int i = 0; i < fraza1.size(); i++) {
        k = 0;
        for (int j = 0; j < pidst1.size(); j++) {
            if (fraza1[i] == pidst1[j]) {
                fraza2.push_back(pidst2[j]);
                k++;
            }
        }
        if (k == 0) {
            for (int j = 0; j < pidst2.size(); j++) {
                if (fraza1[i] == pidst2[j]) {
                    fraza2.push_back(pidst1[j]);
                    k++;
                }
            }
        }
        if (k == 0)
            fraza2.push_back(fraza1[i]);
    }
    Druk_vect1d(fraza2, 2);

    return 0;
}

//введення рядка string 
string Vvod_z_klavy() {
    cout << "Введіть рядок - ";
    string riadok;
    while (riadok.size() == 0)
        getline(cin, riadok);

    return riadok;
}


