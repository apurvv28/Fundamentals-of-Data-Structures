#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

int main() {
    Term poly1[] = {{3,2}, {2,1}, {1,0}};
    Term poly2[] = {{2,1}, {3,0}};
    int n1 = 3, n2 = 2;
    
    cout << "First polynomial: ";
    for(int i = 0; i < n1; i++) {
        cout << poly1[i].coeff << "x^" << poly1[i].exp;
        if(i != n1-1) cout << " + ";
    }
    
    cout << "\nSecond polynomial: ";
    for(int i = 0; i < n2; i++) {
        cout << poly2[i].coeff << "x^" << poly2[i].exp;
        if(i != n2-1) cout << " + ";
    }
    
    Term result[10];
    int n3 = 0;
    
    for(int i = 0; i < n1; i++) {
        result[n3++] = poly1[i];
    }
    
    for(int i = 0; i < n2; i++) {
        bool found = false;
        for(int j = 0; j < n3; j++) {
            if(poly2[i].exp == result[j].exp) {
                result[j].coeff += poly2[i].coeff;
                found = true;
                break;
            }
        }
        if(!found) {
            result[n3++] = poly2[i];
        }
    }
    
    cout << "\n\nSum: ";
    for(int i = 0; i < n3; i++) {
        cout << result[i].coeff << "x^" << result[i].exp;
        if(i != n3-1) cout << " + ";
    }
    
    Term product[10];
    int n4 = 0;
    
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            int new_coeff = poly1[i].coeff * poly2[j].coeff;
            int new_exp = poly1[i].exp + poly2[j].exp;
            
            bool found = false;
            for(int k = 0; k < n4; k++) {
                if(product[k].exp == new_exp) {
                    product[k].coeff += new_coeff;
                    found = true;
                    break;
                }
            }
            if(!found) {
                product[n4].coeff = new_coeff;
                product[n4].exp = new_exp;
                n4++;
            }
        }
    }
    
    cout << "\nProduct: ";
    for(int i = 0; i < n4; i++) {
        cout << product[i].coeff << "x^" << product[i].exp;
        if(i != n4-1) cout << " + ";
    }
    
    return 0;
}