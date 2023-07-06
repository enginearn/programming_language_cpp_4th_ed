#include <iostream>
#include <complex>
#include <vector>

using namespace std;

double square(double x)
{
    return x * x;
}

constexpr double square_c(double x)
{
    return x * x;
}

void print_square(double x)
{
    cout << "the square of " << x << " is " << square(x) << "\n";
}

double sum(const std::vector<double>& v) {
    double total = 0.0;
    for (double x : v) {
        total += x;
    }
    return total;
}

bool accept()
{
    cout << "Do you want to proceed (y or n)?\n";

    char answer = 0;
    cin >> answer;

    if (answer == 'y') return true;
    return false;
}

bool accept2()
{
    cout << "Do you want to proceed (y or n)?\n";

    char answer = 0;
    cin >> answer;

    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "I'll take that for a no.\n";
            return false;
    }
}

bool accept3()
{
    int tries = 0;
    while (tries < 4) {
        cout << "Do you want to proceed (y or n)?\n";

        char answer = 0;
        cin >> answer;

        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I don't understand that.\n";
                ++tries; // increment
        }
    }
    cout << "I'll take that for a no.\n";
    return false;
}

int main()
{
    print_square(1.234);

    std::complex<double> c(1.0, 2.0); // 実数部が1.0、虚数部が2.0の複素数を作成

    std::cout << "Real part: " << c.real() << '\n';      // 実数部を出力
    std::cout << "Imaginary part: " << c.imag() << '\n'; // 虚数部を出力

    const int dmv = 17; // dmvは「ドライバーの最小視力」(Department of Motor Vehicles)の略
    int var = 17;
    const double pi = 3.1415926535897932385;
    constexpr double e = 2.7182818284590452354;
    constexpr double max1 = 1.4 * square_c(e); // OK。square(e)はconstexpr関数
    // constexpr double max2 = 1.4 * square_c(pi); // エラー。square(pi)はconstexpr関数ではない
    // double sum(const double a[], int n); // OK。sum()はconstexpr関数ではない
    vector <double> v {1.2, 3.4, 4.5}; // OK。vはconstexprオブジェクトではない
    const double s1 = sum(v); // OK。sum(v)はconstexpr関数ではない
    // constexpr double s2 = sum(v); // エラー。sum(v)はconstexpr関数ではない
    accept3();

}
