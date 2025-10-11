#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int comparisons = 0;
void reset(){
    comparisons = 0;
}

int linear(int arr[], int n, int target){
    reset();
    for(int i = 0;i<n;i++){
        comparisons++;
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int binary(int arr[],int n,int target){
    reset();
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]==target){
            comparisons++;
            return mid;
        }
        else if(arr[mid]<target){
            comparisons++;
            left = mid + 1;
        }
        else{
            right = mid - 1;
            comparisons++;
        }
    }
    return -1;
}

int sentinel(int arr[],int n, int target){
    reset(); 
    int last = arr[n-1];
    arr[n-1] = target;
    int i = 0;
    while(arr[i]!=target){
        i++;
    }
    arr[n-1] = last;
    if(i<n-1 || arr[n-1]==target){
        comparisons++;
        return i;
    }
}

int fibonacci(int arr[], int n, int target){
    reset();
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;
    int offset = -1;
    while(fib<n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    while(fib>1){
        int i = min(offset+fib2, n-1);
        if(arr[i]<target){
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
            comparisons++;
        }
        else if(arr[i]>target){
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
            comparisons++;
        }
        else{
            comparisons++;
            return i;
        }
    }
}


int main(){
    int n, m, target, ch1, ch2, result = 0, c = 0;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Choose any one!\n 1. Create Sorted Array \n 2. Create Unsorted Array \n 3. Exit"<<endl;
    cin>>ch1;
    switch(ch1){
        case 1:
        cout<<"Enter elements in sorted way: "<<endl;
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        break;

        case 2:
        cout<<"Enter elements in unsorted way: "<<endl;
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        break;

        case 3:
        cout<<"Exitting..."<<endl;
        return 0;

        default:
        cout<<"Invalid Option!"<<endl;
    }
    cout<<"Enter the target element: "<<endl;
    cin>>target;
while(true){
    if(ch1==2){
        cout<<"Choose any one!\n 1. Linear Search\n 2. Sentinel Search \n 5. Exit"<<endl;
        cin>>ch2;
    switch(ch2){
        case 1: 
        result = linear(arr,n,target);
        cout<<"Element found at index: "<<result<<endl;
        c = comparisons;
        cout<<"Number of comparisons: "<<c<<endl;
        if(c==1){
            cout<<"Best Case - O(1)"<<endl;
        }
        else if(c==n){
            cout<<"Worst Case - O(n)"<<endl;
        }
        else{
            cout<<"Average Case - O(n)"<<endl;
        }
        break;

        case 2:
        result = sentinel(arr,n,target);
        cout<<"Element found at index: "<<result<<endl;
        c = comparisons;
        cout<<"Number of comparisons: "<<c<<endl;
        if(c==1){
            cout<<"Best Case - O(1)"<<endl;
        }
        else if(c==n){
            cout<<"Worst Case - O(n)"<<endl;
        }
        else{
            cout<<"Average Case - O(n)"<<endl;
        }
        break;

        case 5:
        cout<<"Exiting..."<<endl;
        return 0;

        default:
        cout<<"Invalid choice!"<<endl;
    }
    }
    if(ch1==1){
        cout<<"Choose any one!\n 3. Binary Search \n 4. Fibonacci Search\n 5. Exit"<<endl;
        cin>>ch2;
    switch(ch2){

        case 3:
        result = binary(arr,n,target);
        cout<<"Element found at index: "<<result<<endl;
        c = comparisons;
        cout<<"Number of comparisons: "<<c<<endl;
        if(c==1){
            cout<<"Best Case - O(1)"<<endl;
        }
        else if(c==log(n)){
            cout<<"Worst Case - O(log n)"<<endl;
        }
        else{
            cout<<"Average Case - O(log n)"<<endl;
        }
        break;

        case 4:
        result = fibonacci(arr,n,target);
        cout<<"Element found at index: "<<result<<endl;
        c = comparisons;
        cout<<"Number of comparisons = "<<c<<endl;
        if(c==1){
            cout<<"Best Case - O(1)"<<endl;
        }
        else if(c==log(n)){
            cout<<"Worst Case - O(log n)"<<endl;
        }
        else{
            cout<<"Average Case - O(log n)"<<endl;
        }
        break;

        case 5:
        cout<<"Exiting..."<<endl;
        return 0;

        default:
        cout<<"Invalid choice!"<<endl;
    }
    }
}
return 0;
}