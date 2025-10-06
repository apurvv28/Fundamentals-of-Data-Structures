#include<iostream>
using namespace std;

int main(){
    const int MAXIMUM=100;
    int poly[MAXIMUM+1]={0};
    int poly2[MAXIMUM+1]={0};

    int degree;
    cout<<"Enter the degree of first polynomial: "<<endl;
    cin>>degree;
    cout<<"Enter the coefficients of first polynomial:"<<endl;
    for(int i=degree;i>=0;i--){
        cout<<"Coefficient of x^"<<i<<": ";
        cin>>poly[i];
    }
    cout<<"The first polynomial is: "<<endl;
    for(int i=degree;i>=0;i--){
        if(poly[i]!=0){
            cout<<poly[i];
            if(i>0){
                cout<<"x^"<<i;
            }
            if(i!=0){
                cout<<"+";
            }
        }
    }

    cout<<endl;

    cout<<"Enter degree of second polynomial: "<<endl;
    int degree2;
    cin>>degree2;
    cout<<"Enter the coefficients of second polynomial:"<<endl;
    for(int i=degree2;i>=0;i--){
        cout<<"Coefficient of x^"<<i<<": ";
        cin>>poly2[i];
    }
    cout<<"The second polynomial is: "<<endl;
    for(int i=degree2;i>=0;i--){
        if(poly2[i]!=0){
            cout<<poly2[i];
            if(i>0){
                cout<<"x^"<<i;
            }
            if(i!=0){
                cout<<"+";
            }
        }
    }

    cout<<endl;

    int result[MAXIMUM+1]={0};
    int m=max(degree, degree2);
    for(int i=0;i<=m;i++){
        result[i]=poly[i]+poly2[i];
    }

    cout<<"The sum of polynomial is: "<<endl;
    for(int i = m;i>=0;i--){
        if(result[i]!=0){
            cout<<result[i];
            if(i>0){
                cout<<"x^"<<i;
            }
            if(i!=0){
                cout<<"+";
            }
        }
    }

    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            if(i+j<=m){
                result[i+j]+=poly[i]*poly2[j];
            }
        }
    }

    cout<<"The product of polynomial is: "<<endl;
    for(int i = m;i>=0;i--){
        if(result[i]!=0){
            cout<<result[i];
            if(i>0){
                cout<<"x^"<<i;
            }
            if(i!=0){
                cout<<"+";
            }
        }
    }
}