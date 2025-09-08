#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int recursive_calls = 0;
int multiplications = 0;
int additions = 0;
int digit_count = 0;

void reset_counters() {
    recursive_calls = 0;
    multiplications = 0;
    additions = 0;
    digit_count = 0;
}

long long pow10(int m) {
    long long p = 1;
    for (int i = 0; i < m; i++){
        p *= 10;
    }
    return p;
}

long long gauss(long long x, long long y) {
    recursive_calls++;
    if (x < 10 || y < 10) {
        multiplications++;
        return x * y;
    }
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;
    digit_count += n;
    long long power = pow10(m);
    long long a = x / power;  
    long long b = x % power;   
    long long c = y / power;   
    long long d = y % power;   
    long long bd = gauss(b, d);
    long long bc = gauss(b, c);
    long long ad = gauss(a, d);
    long long ac = gauss(a, c);
    additions += 2;
    return ac * pow10(2 * m) + (bc + ad) * pow10(m) + bd;
}

long long karatsuba(long long x, long long y) {
    recursive_calls++;
    if (x < 10 || y < 10) {
        multiplications++;
        return x * y;
    }
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;
    digit_count += n;
    long long power = pow10(m);
    long long a = x / power;   
    long long b = x % power;   
    long long c = y / power;   
    long long d = y % power;   
    long long bd = karatsuba(b, d);
    long long z1 = karatsuba(a + b, c + d);
    long long ac = karatsuba(a, c);
    additions += 2; 
    return ac * pow10(2 * m) + (z1 - ac - bd) * pow10(m) + bd;
}

int main() {
    long long n1, n2;
    int choice;
    cout << "Enter first number : ";
    cin >> n1;
    cout << "Enter second number : ";
    cin >> n2;
    cout <<"Choose a method:"<<endl;
    cout << "1. Gauss Multiplication"<<endl;
    cout << "2. Karatsuba Multiplication"<<endl;
    cout << "Enter choice: ";
    cin >> choice;
    reset_counters();
    clock_t start = clock();
    long long result;

    switch (choice) {
        case 1:
            result = gauss(n1, n2);
            cout << "Gauss Multiplication : "<<result << endl;
            break;
        case 2:
            result = karatsuba(n1, n2);
            cout << "Karatsuba Multiplication : "<<result << endl;
            break;
        default:
            cout <<"Invalid option"<< endl;
            return 0;
    }

    clock_t stop = clock();
    double duration = double(stop-start) /CLOCKS_PER_SEC * 1000.0;
    cout<< "Recursive calls: "<<recursive_calls<< endl;
    cout<< "Multiplications: " <<multiplications<<endl;
    cout<< "Additions: " <<additions<<endl;
    cout<< "Digit count: " <<digit_count<< endl;
    cout<< "Execution time: " <<duration<< " ms" << endl;
    return 0;
}