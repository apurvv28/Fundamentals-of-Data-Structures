//Conversion of Infix to Prefix and Postfix using Stack Operations
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}
int getPriority(char C){
    if(C=='-' || C=='+'){
        return 1;
    }
    else if(C=='*' || C=='/'){
        return 2;
    }
    else if(C=='^'){
        return 3;
    }
    return 0;
}

string infixToPostfix(string infix){
    infix = '(' + infix + ')';
    int l = infix.length();
    stack<char> charStack;
    string output;
    for(int i = 0;i < l;i++){
        if(isalpha(infix[i])||isdigit(infix[i])){
            output+=infix[i];
        }
        else if(infix[i]=='('){
            charStack.push('(');
        }
        else if(infix[i]==')'){
            while(charStack.top()!='('){
                output+=charStack.top();
                charStack.pop();
            }
            charStack.pop();
        }
        else{
            if(isOperator(charStack.top())){
                if(infix[i]=='^'){
                    while(getPriority(infix[i])<=getPriority(charStack.top())){
                    output+=charStack.top();
                    charStack.pop();
                    } 
                }else{
                    while(getPriority(infix[i])<getPriority(charStack.top())){
                    output+=charStack.top();
                    charStack.pop();
                    }
                }
                charStack.push(infix[i]);
            }
        }
    }
    return output;
}

string infixToPrefix(string infix){
    int l = infix.length();
    reverse(infix.begin(),infix.end());
    for(int i=0;i<l;i++){
        if(infix[i]=='('){
            infix[i]=')';
        }
        else if(infix[i]==')'){
            infix[i]='(';
            i++;
        }
        }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(),prefix.end());
    return prefix;
    }

int evaluatePostfix(string postfix){
    stack<int> s1;
    int l = postfix.length();
    for(int i=0;i<l;i++){
        if(isdigit(postfix[i])){
            s1.push(postfix[i]-'0');
        }
        else{
            int val1 = s1.top();
            s1.pop();
            int val2 = s1.top();
            s1.pop();
            switch(postfix[i]){
                case '+':
                    s1.push(val2+val1);
                    break;
                case '-':
                    s1.push(val2-val1);
                    break;
                case '*':
                    s1.push(val2*val1);
                    break;
                case '/':
                    s1.push(val2/val1);
                    break;
            }
        }
    }
    return s1.top();
}
int main(){
    string infix;
    cout<<"Enter Infix Expression: ";
    getline(cin,infix);
    cout<<"Postfix Expression: "<<infixToPostfix(infix)<<endl;
    cout<<"Prefix Expression: "<<infixToPrefix(infix)<<endl;
    cout<<"Postfix Evaluation: "<<evaluatePostfix(infixToPostfix(infix))<<endl;
    return 0;
}