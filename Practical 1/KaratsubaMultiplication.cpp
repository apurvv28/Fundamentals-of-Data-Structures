#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

long long karatsuba(long long a, long long b){
	recursive_calls++;
	if(a<10 || b<10){
		multiplications++;
		return a * b;
	}
	//Size of numbers
	digit_count += 2;
	int n = max(to_string(a).length(), to_string(b).length());
	//Divide size of number in 2 parts for divide and conquer approach
	int m = n/2;
	//Split number into high and low parts
	long long power = pow(10,m);
	long long a_high = a/power;
	long long b_high = b/power;
	long long a_low = a%power;
	long long b_low = b%power;
	//Recursively calculate 3 products needed 
	long long z0 = karatsuba(a_low, b_low);
    long long z1 = karatsuba((a_low + a_high), (b_high + b_low));
    long long z2 = karatsuba(a_high, b_high);
    
    additions += 2;
    return z2 * pow(10, 2 * m) + (z1-z2-z0) * pow(10, m) + z0;
}

int main(){
	long long n1, n2;
	cout<<"Enter first number : ";
	cin>>n1; 
	cout<<endl;
	cout<<"Enter second number : ";
	cin>>n2; 
	cout<<endl;
	
	auto start = high_resolution_clock::now();
	long long result = karatsuba(n1,n2);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	
	cout << "Gauss Multiplication : "<<n1<< " x "<<n2<<" = "<<result<<endl;
	cout << "Recursive calls: " << recursive_calls << endl;
    cout << "Multiplications: " << multiplications << endl;
    cout << "Additions: " << additions << endl;
    cout << "Digit count: " << digit_count << endl;
    cout << "Execution time: " << duration.count() << " ms" << endl;
	return 0;
}
