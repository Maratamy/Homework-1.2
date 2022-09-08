#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;
class Polinom {
private:
    double coeff_arr[5] = { 0,0,0,0,0 };
public:

    Polinom() {
    }
    ~Polinom() {}
    double get_coeff(int index) {
        return coeff_arr[index];
    }
    void set_coeff(double new_coeff, int index) {
        coeff_arr[index] = new_coeff;
    }

    void operator+(Polinom add_poli) {
        coeff_arr[0] = coeff_arr[0] + add_poli.get_coeff(0);
        coeff_arr[1] = coeff_arr[1] + add_poli.get_coeff(1);
        coeff_arr[2] = coeff_arr[2] + add_poli.get_coeff(2);
        coeff_arr[3] = coeff_arr[3] + add_poli.get_coeff(3);
        coeff_arr[4] = coeff_arr[4] + add_poli.get_coeff(4);

    }
    void operator-(Polinom decr_vec) {
        coeff_arr[0] = coeff_arr[0] - decr_vec.get_coeff(0);
        coeff_arr[1] = coeff_arr[1] - decr_vec.get_coeff(1);
        coeff_arr[2] = coeff_arr[2] - decr_vec.get_coeff(2);
        coeff_arr[3] = coeff_arr[3] - decr_vec.get_coeff(3);
        coeff_arr[4] = coeff_arr[4] - decr_vec.get_coeff(4);
    }
    void operator/(int divider) {
        coeff_arr[0] = coeff_arr[0] / divider;
        coeff_arr[1] = coeff_arr[1] / divider;
        coeff_arr[2] = coeff_arr[2] / divider;
        coeff_arr[3] = coeff_arr[3] / divider;
        coeff_arr[4] = coeff_arr[4] / divider;
    }
    void operator*(int multiplier) {
        coeff_arr[0] = coeff_arr[0] * multiplier;
        coeff_arr[1] = coeff_arr[1] * multiplier;
        coeff_arr[2] = coeff_arr[2] * multiplier;
        coeff_arr[3] = coeff_arr[3] * multiplier;
        coeff_arr[4] = coeff_arr[4] * multiplier;
    }

    void operator+=(int add_coeff) {
        coeff_arr[0] = coeff_arr[0] + add_coeff;
        coeff_arr[1] = coeff_arr[1] + add_coeff;
        coeff_arr[2] = coeff_arr[2] + add_coeff;
        coeff_arr[3] = coeff_arr[3] + add_coeff;
        coeff_arr[4] = coeff_arr[4] + add_coeff;
    }
    void operator-=(int decr_coeff) {
        coeff_arr[0] = coeff_arr[0] + decr_coeff;
        coeff_arr[1] = coeff_arr[1] + decr_coeff;
        coeff_arr[2] = coeff_arr[2] + decr_coeff;
        coeff_arr[3] = coeff_arr[3] + decr_coeff;
        coeff_arr[4] = coeff_arr[4] + decr_coeff;
    }
    void operator=(Polinom copy_poli) {
        coeff_arr[0] = copy_poli.get_coeff(0);
        coeff_arr[1] = copy_poli.get_coeff(1);
        coeff_arr[2] = copy_poli.get_coeff(2);
        coeff_arr[3] = copy_poli.get_coeff(3);
        coeff_arr[4] = copy_poli.get_coeff(4);
    }
};


ostream& operator<<(ostream& os, Polinom& out_poli) {
    os <<  out_poli.get_coeff(4) << "*x^4" << showpos << out_poli.get_coeff(3) <<"*x^3" << showpos << out_poli.get_coeff(2) <<"*x^2" << showpos << out_poli.get_coeff(1) <<"*x" << showpos <<out_poli.get_coeff(0) << endl;
    return os;
}
istream& operator>>(istream& is, Polinom& in_poli) {
    double temp_coeff;
    int index = 0;
    string enter_line;
    
    cout << "Введите коеффициенты, начиная со свободного. Для остановки ввода введите пустую строку." << endl;
    cout << enter_line.length() << endl;
    getline(cin,enter_line);
    cout << enter_line.length() << endl;
    while (enter_line.length() != 0) {
        temp_coeff = atof(enter_line.c_str());
        in_poli.set_coeff(temp_coeff, index);
        index++;
        if (index >= 5) break;
        getline(cin, enter_line);
    }
    return is;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Polinom Poli1, Poli2, Poli3;
    char sign;
    int temp_number;
    cin >> Poli1;
    cin >> Poli2;
    cout << "Введите знак действия.";
    cin >> sign;
    switch (sign) {
    case '+':
        Poli1 + Poli2;
        cout << Poli1;
        break;
    case '-':
        Poli1 - Poli2;
        cout << Poli1;
        break;
    case '*':
        cin >> temp_number;
        Poli1* temp_number;
        cout << Poli1;
        break;
    case '/':
        cin >> temp_number;
        Poli1 / temp_number;
        cout << Poli1;
        break;
    default:
        cout << "Ошибка!";
        break;
    }
    return 0;
}

