#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int swapCount = 0;
int comparisonCount = 0;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    swapCount++;
}

void bubble(int arr[], int n){
    swapCount = 0;
    comparisonCount = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            comparisonCount++;
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertion(int arr[], int n){
    swapCount = 0;
    comparisonCount = 0;
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0){
            comparisonCount++;
            if(arr[j]<key){
                arr[j+1] = arr[j];
                swapCount++;
                j--;
            } else {
                break;
            }
        }
        arr[j+1]=key;
    }
}

void selection(int arr[], int n){
    swapCount = 0;
    comparisonCount = 0;
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            comparisonCount++;
            if(arr[j]>arr[mini]){
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
        comparisonCount++;
        if(arr[j]>pivot){
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
    swapCount = 0;
    comparisonCount = 0;
    int h = 1;
    while(h<n/3){
        h = 3*h +1;
    }
    while(h>=1){
        for(int i=h;i<n;i++){
            int j=i;
            int temp = arr[i];
            while(j>=h){
                comparisonCount++;
                if(arr[j-h]<temp){
                    arr[j] = arr[j-h];
                    swapCount++;
                    j -= h;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
        h=h/3;
    }
}

void bucket(int arr[], int n){
    swapCount = 0;
    comparisonCount = 0;
    int maxc = arr[0];
    for(int i = 1;i<n;i++){
        comparisonCount++;
        if(arr[i]>maxc){
            maxc = arr[i];
        }
    }
    int bucket[maxc+1]={0};
    for(int i=0;i<n;i++){
        bucket[arr[i]]++;
    }
    int index = 0;
    for(int i=maxc;i>=0;i--){
        while(bucket[i]>0){
            arr[index++] = i;
            bucket[i]--;
            swapCount++;
        }
    }
}

void radix(int arr[], int n){
    swapCount = 0;
    comparisonCount = 0;
    int bucket[n];
    int maxc = arr[0];
    for(int i = 1;i<n;i++){
        comparisonCount++;
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
        for(int i=8;i>=0;i--){
            count[i] += count[i+1];
        }
        for(int i=n-1;i>=0;i--){
            int digit = (arr[i]/pos)%10;
            bucket[--count[digit]] = arr[i];
            swapCount++;
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
    cout << "Enter the number of players: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " scores: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int choice;
    do {
        cout << "\nGAMING LEADERBOARD SORTING" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Shell Sort" << endl;
        cout << "6. Bucket Sort" << endl;
        cout << "7. Radix Sort" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose sorting method: ";
        cin >> choice;

        int temp[n];
        for(int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        cout << "\nOriginal scores: ";
        printArray(arr, n);

        auto start = high_resolution_clock::now();
        
        switch(choice) {
            case 1:
                bubble(temp, n);
                cout << "Leaderboard (Bubble Sort): ";
                printArray(temp, n);
                break;
            
            case 2:
                insertion(temp, n);
                cout << "Leaderboard (Insertion Sort): ";
                printArray(temp, n);
                break;
            
            case 3:
                selection(temp, n);
                cout << "Leaderboard (Selection Sort): ";
                printArray(temp, n);
                break;
            
            case 4:
                quick(temp, 0, n-1);
                cout << "Leaderboard (Quick Sort): ";
                printArray(temp, n);
                break;
            
            case 5:
                shell(temp, n);
                cout << "Leaderboard (Shell Sort): ";
                printArray(temp, n);
                break;
            
            case 6:
                bucket(temp, n);
                cout << "Leaderboard (Bucket Sort): ";
                printArray(temp, n);
                break;
            
            case 7:
                radix(temp, n);
                cout << "Leaderboard (Radix Sort): ";
                printArray(temp, n);
                break;
            
            case 8:
                cout << "Exiting program..." << endl;
                break;
            
            default:
                cout << "Invalid choice!" << endl;
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        if(choice >= 1 && choice <= 7) {
            cout << "Time taken: " << duration.count() << " microseconds" << endl;
            cout << "Number of swaps: " << swapCount << endl;
            cout << "Number of comparisons: " << comparisonCount << endl;
        }
        
    } while(choice != 8);
    return 0;
}