#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertion(int arr[], int n){
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selection(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quick(int arr[],int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quick(arr,low,pi-1);
        quick(arr,pi+1,high);
    }
}

void shell(int arr[], int n){
    int h = 1;
    while(h<n/3){
        h = 3*h +1;
    }
    while(h>=1){
        for(int i=h;i<n;i++){
            int j=i;
            int temp = arr[i];
            while(j>=h && arr[j-h]>temp){
                arr[j] = arr[j-h];
                j -= h;
            }
            arr[j] = temp;
        }
        h=h/3;
    }
}

void bucket(int arr[], int n){
    int maxc = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i]>maxc){
            maxc = arr[i];
        }
    }
    int bucket[maxc+1]={0};
    for(int i=0;i<n;i++){
        bucket[arr[i]]++;
    }
    int index = 0;
    for(int i=0;i<=maxc;i++){
        while(bucket[i]>0){
            arr[index++] = i;
            bucket[i]--;
        }
    }
}

void radix(int arr[], int n){
    int bucket[n];
    int maxc = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i]>maxc){
            maxc = arr[i];
        }
    }
    int pos = 1;
    int pass = 1;
    while(maxc/pos>0){
        int count[10]={0};
        for(int i=0;i<n;i++){
            int digit = (arr[i]/pos)%10;
            count[digit]++;
        }
        for(int i=1;i<10;i++){
            count[i] += count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            int digit = (arr[i]/pos)%10;
            bucket[--count[digit]] = arr[i];
        }
        for(int i=0;i<n;i++){
            arr[i] = bucket[i];
        }
        pos*=10;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int choice;
    do {
        cout << "\nChoose 1 option!" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Shell Sort" << endl;
        cout << "6. Bucket Sort" << endl;
        cout << "7. Radix Sort" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int temp[n];
        for(int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        cout << "\nOriginal array: ";
        printArray(arr, n);

        switch(choice) {
            case 1:
                bubble(temp, n);
                cout << "After Bubble Sort: ";
                printArray(temp, n);
                break;
            
            case 2:
                insertion(temp, n);
                cout << "After Insertion Sort: ";
                printArray(temp, n);
                break;
            
            case 3:
                selection(temp, n);
                cout << "After Selection Sort: ";
                printArray(temp, n);
                break;
            
            case 4:
                quick(temp, 0, n-1);
                cout << "After Quick Sort: ";
                printArray(temp, n);
                break;
            
            case 5:
                shell(temp, n);
                cout << "After Shell Sort: ";
                printArray(temp, n);
                break;
            
            case 6:
                bucket(temp, n);
                cout << "After Bucket Sort: ";
                printArray(temp, n);
                break;
            
            case 7:
                radix(temp, n);
                cout << "After Radix Sort: ";
                printArray(temp, n);
                break;
            
            case 8:
                cout << "Exiting program..." << endl;
                break;
            
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 8);
    return 0;
}