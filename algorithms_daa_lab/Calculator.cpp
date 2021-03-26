#include<bits/stdc++.h>
using namespace std;
int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    else if(op =='*' || op == '/')
        return 2;
    else if(op == '^')
        return 3;
    else return 0;
}

double evaluate(double x, double y, char op){
    switch (op)
    {
    case '*': return x*y;
    case '/': return x/y;
    case '+': return x+y;
    case '-': return x-y;
    case '^': return pow(x,y);
    default: return 0;
    }
    return 0;

}

double solve(string exp){
    stack<double> val;
    stack<char> oper;
    int size = exp.size();
    for(int i=0;i<size;i++){
        if(exp[i]==' ')
            continue;
        if(exp[i]>'0'&&exp[i]<'9'||exp[i]=='.'){
            string temp;
            while( i<size && (exp[i]>'0'&&exp[i]<'9'||exp[i]=='.')){
                temp.push_back(exp[i++]);
            }
            val.push(stod(temp));
            i--;
        }

        else if(exp[i]=='('){
            oper.push('(');
        }
        else if(exp[i]==')'){
            while (oper.top()!='(' && !oper.empty())
            {
                char op = oper.top();
                oper.pop();
                double v2 = val.top();
                val.pop();
                double v1 = val.top();
                val.pop();
                val.push(evaluate(v1,v2,op));
            }
            if(oper.top()=='(')
                oper.pop();
        }
        else{
            while (!oper.empty() && precedence(oper.top())>precedence(exp[i]))
            {
                char op = oper.top();
                oper.pop();
                double v2 = val.top();
                val.pop();
                double v1 = val.top();
                val.pop();
                val.push(evaluate(v1, v2, op));
            }
            oper.push(exp[i]);
            
        }
    }
    while (!oper.empty())
    {
        char op = oper.top();
        oper.pop();
        double v2 = val.top();
        val.pop();
        double v1 = val.top();
        val.pop();
        val.push(evaluate(v1, v2, op));
    }
    return(val.top());
    
}

int main() {
    string exp;
    double ans;
    cin>>exp;
    ans = solve(exp);
    cout<<ans;
    return 0;
}