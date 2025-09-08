#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

int recursive_calls=0;
int multiplications=0;
int additions=0;
int digit_count=0;

void reset_counters() {
    recursive_calls=0;
    multiplications=0;
    additions=0;
    digit_count=0;
}

long long pow10(int m) {
    long long p =1;
    for (int i=0; i < m; i++){
		p *= 10;
	}
    return p;
}

long long gauss(long long x, long long y) {
    recursive_calls++;
    if (x<10 || y<10) {
        multiplications++;
        return x*y;
    }

    int n = max(to_string(x).length(), to_string(y).length());
    int m = n/2;
    digit_count += n;

    long long power = pow10(m);
    long long a = x / power;
    long long c = y / power;
    long long b = x % power;
    long long d = y % power;

    long long bd = gauss(b, d);
    long long bc = gauss(b, c);
    long long ad = gauss(a, d);
    long long ac = gauss(a, c);

    additions += 2;
    return ac * pow10(2 * m) + (bc + ad) * pow10(m) + bd;
}

int main() {
    long long n1, n2;
    cout << "Enter first number : ";
    cin >> n1;
    cout << "Enter second number : ";
    cin >> n2;

    reset_counters();

    clock_t start = clock();
    long long result = gauss(n1, n2);
    clock_t stop = clock();
    double duration = double(stop - start) / CLOCKS_PER_SEC * 1000.0;

    cout << "Gauss Multiplication : "<< result <<endl;
    cout << "Recursive calls: " << recursive_calls <<endl;
    cout << "Multiplications: " << multiplications <<endl;
    cout << "Additions: " << additions <<endl;
    cout << "Digit count: " << digit_count <<endl;
    cout << "Execution time: " << duration << " ms" <<endl;

    return 0;
}
