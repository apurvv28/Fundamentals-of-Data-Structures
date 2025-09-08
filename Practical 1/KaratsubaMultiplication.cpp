#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

int recursive_calls = 0;
int multiplications = 0;
int additions = 0;
int digit_count = 0;

void reset(){
recursive_calls = 0;
multiplications = 0;
additions = 0;
digit_count = 0;
}

long long pow10(int m) {
    long long p = 1;
    for (int i = 0; i < m; i++) p *= 10;
    return p;
}

long long karatsuba(long long x, long long y){
	recursive_calls++;
	if(x<10 || y<10){
		multiplications++;
		return x * y;
	}
	digit_count += 2;
	int n = max(to_string(x).length(), to_string(y).length());
	int m = n/2;
	long long power = pow10(m);
	long long a = x/power;
	long long b = y/power;
	long long c = x%power;
	long long d = y%power;
	long long cd = karatsuba(c, d);
    long long abcd = karatsuba((a + c), (b + d));
    long long ab = karatsuba(a, b);
    
    additions += 2;
    return ab * pow10(2*m) + (abcd - ab - cd) * pow10(m) + cd;
}

int main(){
	long long n1, n2;
	cout<<"Enter first number : ";
	cin>>n1; 
	cout<<endl;
	cout<<"Enter second number : ";
	cin>>n2; 
	cout<<endl;
	
	clock_t start = clock();
    long long result = karatsuba(n1, n2);
    clock_t stop = clock();
    double duration = double(stop - start) / CLOCKS_PER_SEC * 1000.0;
	
	cout << "Gauss Multiplication : "<<result<<endl;
	cout << "Recursive calls: " << recursive_calls <<endl;
    cout << "Multiplications: " << multiplications <<endl;
    cout << "Additions: " << additions <<endl;
    cout << "Digit count: " << digit_count <<endl;
    cout << "Execution time: " << duration << " ms" <<endl;
	return 0;
}
