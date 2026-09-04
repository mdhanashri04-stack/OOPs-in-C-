#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <functional>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

class User {
    string name; int age;
public:
    void inputDetails(){cout<<"Enter your name: ";getline(cin,name);cout<<"Enter your age: ";cin>>age;cin.ignore();}
    string getName()const{return name;} int getAge()const{return age;}
};

class MathOperations {
public:
    static double add(double a,double b){return a+b;}
    static double subtract(double a,double b){return a-b;}
    static double multiply(double a,double b){return a*b;}
    static double divide(double a,double b){if(b==0)throw runtime_error("Division by zero is undefined!");return a/b;}
    static double power(double a,double b){return pow(a,b);}
    static double squareRoot(double x){if(x<0)throw runtime_error("Square root of a negative number is undefined (in reals)!");return sqrt(x);}
    static unsigned long long factorial(int n){if(n<0)throw runtime_error("Factorial is not defined for negative numbers!");unsigned long long r=1;for(int i=2;i<=n;i++)r*=i;return r;}
    static double logNatural(double x){if(x<=0)throw runtime_error("Logarithm undefined for x <= 0!");return log(x);}
    static double log10Val(double x){if(x<=0)throw runtime_error("Logarithm undefined for x <= 0!");return log10(x);}
    static double logBase(double x,double b){if(x<=0||b<=0||b==1)throw runtime_error("Invalid arguments for log base n!");return log(x)/log(b);}
};

class Binomial {
public:
    static unsigned long long nCr(int n,int r){
        if(r<0||r>n)return 0;r=min(r,n-r);unsigned long long x=1;
        for(int i=0;i<r;i++)x=x*(n-i)/(i+1);return x;
    }
    static void expand(int n){
        cout<<"(a + b)^"<<n<<" = ";
        for(int k=0;k<=n;k++){cout<<nCr(n,k)<<"*a^"<<n-k<<"*b^"<<k;if(k!=n)cout<<" + ";}
        cout<<endl;
    }
};

class Polynomial {
    vector<double> c;
public:
    void input(){
        int d;cout<<"Enter the degree of the polynomial: ";cin>>d;
        c.assign(d+1,0);cout<<"Enter coefficients from x^0 up to x^"<<d<<":\n";
        for(int i=0;i<=d;i++){cout<<"  Coefficient of x^"<<i<<": ";cin>>c[i];}
    }
    void display()const{
        bool f=1;
        for(int i=c.size()-1;i>=0;i--){if(!c[i])continue;if(!f)cout<<(c[i]>0?" + ":" - ");else if(c[i]<0)cout<<"-";cout<<fabs(c[i]);if(i>0)cout<<"x^"<<i;f=0;}
        if(f)cout<<"0";cout<<endl;
    }
    double evaluate(double x)const{
        double r=0;for(int i=c.size()-1;i>=0;i--)r=r*x+c[i];return r;
    }
    Polynomial derivative()const{
        Polynomial d;if(c.size()<=1){d.c={0};return d;}d.c.resize(c.size()-1);
        for(size_t i=1;i<c.size();i++)d.c[i-1]=c[i]*i;return d;
    }
    Polynomial integrate(double C=0)const{
        Polynomial p;p.c.resize(c.size()+1);p.c[0]=C;
        for(size_t i=0;i<c.size();i++)p.c[i+1]=c[i]/(i+1);return p;
    }
    double definiteIntegral(double a,double b)const{
        Polynomial p=integrate();return p.evaluate(b)-p.evaluate(a);
    }
};

class Matrix {
    int rows=0,cols=0;vector<vector<double>> data;

    static double det(const vector<vector<double>>&m,int n){
        if(n==1)return m[0][0];
        if(n==2)return m[0][0]*m[1][1]-m[0][1]*m[1][0];
        double d=0;
        for(int col=0;col<n;col++){
            vector<vector<double>>s(n-1,vector<double>(n-1));
            for(int i=1;i<n;i++){int k=0;for(int j=0;j<n;j++)if(j!=col)s[i-1][k++]=m[i][j];}
            d+=(col%2?-1:1)*m[0][col]*det(s,n-1);
        }
        return d;
    }

public:
    void input(){
        cout<<"Enter number of rows and columns: ";cin>>rows>>cols;
        data.assign(rows,vector<double>(cols));
        cout<<"Enter "<<rows*cols<<" elements (row-wise):\n";
        for(auto&r:data)for(double&x:r)cin>>x;
    }

    void display()const{
        for(const auto&r:data){for(double x:r)cout<<setw(10)<<x;cout<<endl;}
    }

    Matrix add(const Matrix&o)const{
        if(rows!=o.rows||cols!=o.cols)throw runtime_error("Matrix dimensions must match for addition!");
        Matrix r;r.rows=rows;r.cols=cols;r.data.assign(rows,vector<double>(cols));
        for(int i=0;i<rows;i++)for(int j=0;j<cols;j++)r.data[i][j]=data[i][j]+o.data[i][j];
        return r;
    }

    Matrix multiply(const Matrix&o)const{
        if(cols!=o.rows)throw runtime_error("Columns of A must equal rows of B for multiplication!");
        Matrix r;r.rows=rows;r.cols=o.cols;r.data.assign(rows,vector<double>(o.cols));
        for(int i=0;i<rows;i++)for(int j=0;j<o.cols;j++)for(int k=0;k<cols;k++)r.data[i][j]+=data[i][k]*o.data[k][j];
        return r;
    }

    Matrix transpose()const{
        Matrix r;r.rows=cols;r.cols=rows;r.data.assign(cols,vector<double>(rows));
        for(int i=0;i<rows;i++)for(int j=0;j<cols;j++)r.data[j][i]=data[i][j];
        return r;
    }

    double determinant()const{
        if(rows!=cols)throw runtime_error("Determinant is only defined for square matrices!");
        return det(data,rows);
    }
};

class Calculus {
public:
    static double numericalDerivative(const function<double(double)>&f,double x,double h=1e-5){
        return(f(x+h)-f(x-h))/(2*h);
    }

    static double numericalIntegral(const function<double(double)>&f,double a,double b,int n=1000){
        if(n%2)n++;double h=(b-a)/n,sum=f(a)+f(b);
        for(int i=1;i<n;i++)sum+=(i%2?4.0:2.0)*f(a+i*h);
        return sum*h/3.0;
    }
};

function<double(double)> chooseFunction(){
    cout<<"Choose a function f(x):\n"
        <<"  1. sin(x)\n"
        <<"  2. cos(x)\n"
        <<"  3. e^x\n"
        <<"  4. ln(x)\n"
        <<"  5. x^2\n"
        <<"  6. x^3\n"
        <<"Enter choice: ";
    int c;cin>>c;
    switch(c){
        case 1:return[](double x){return sin(x);};
        case 2:return[](double x){return cos(x);};
        case 3:return[](double x){return exp(x);};
        case 4:return[](double x){return log(x);};
        case 5:return[](double x){return x*x;};
        case 6:return[](double x){return x*x*x;};
        default:throw runtime_error("Invalid function choice!");
    }
}

int main(){
    User user;

    cout<<"=======================================================\n"
        <<"           WELCOME TO THE SCIENTIFIC CALCULATOR         \n"
        <<"=======================================================\n";

    user.inputDetails();
    cout<<"\nHello, "<<user.getName()<<" (Age: "<<user.getAge()<<")! Let's start calculating.\n";

    int choice;
    do{
        cout<<"\n===================== MAIN MENU ======================\n"
            <<" 1. Basic Arithmetic (+, -, *, /)\n"
            <<" 2. Power & Square Root\n"
            <<" 3. Logarithmic Functions (ln, log10, log base n)\n"
            <<" 4. Factorial\n"
            <<" 5. Binomial Theorem (nCr / Full Expansion)\n"
            <<" 6. Polynomial Operations (Evaluate/Derivative/Integral)\n"
            <<" 7. Matrix Operations (Add/Multiply/Transpose/Determinant)\n"
            <<" 8. Numerical Differentiation\n"
            <<" 9. Numerical Integration\n"
            <<" 0. Exit\n"
            <<"=======================================================\n"
            <<"Enter your choice: ";

        cin>>choice;

        try{
            switch(choice){

            case 1:{
                double a,b,r;char op;
                cout<<"Enter first number: ";cin>>a;
                cout<<"Enter operator (+, -, *, /): ";cin>>op;
                cout<<"Enter second number: ";cin>>b;

                switch(op){
                    case '+':r=MathOperations::add(a,b);break;
                    case '-':r=MathOperations::subtract(a,b);break;
                    case '*':r=MathOperations::multiply(a,b);break;
                    case '/':r=MathOperations::divide(a,b);break;
                    default:throw runtime_error("Invalid operator!");
                }

                cout<<"Result: "<<r<<endl;
                break;
            }

            case 2:{
                cout<<"1. Power  2. Square Root\nChoice: ";
                int s;cin>>s;

                if(s==1){
                    double a,b;
                    cout<<"Enter base: ";cin>>a;
                    cout<<"Enter exponent: ";cin>>b;
                    cout<<"Result: "<<MathOperations::power(a,b)<<endl;
                }else if(s==2){
                    double x;
                    cout<<"Enter number: ";cin>>x;
                    cout<<"Result: "<<MathOperations::squareRoot(x)<<endl;
                }else throw runtime_error("Invalid sub-choice!");
                break;
            }

            case 3:{
                cout<<"1. Natural Log (ln)  2. Log base 10  3. Log base n\nChoice: ";
                int s;cin>>s;double x,b;

                if(s==1){
                    cout<<"Enter x: ";cin>>x;
                    cout<<"ln("<<x<<") = "<<MathOperations::logNatural(x)<<endl;
                }else if(s==2){
                    cout<<"Enter x: ";cin>>x;
                    cout<<"log10("<<x<<") = "<<MathOperations::log10Val(x)<<endl;
                }else if(s==3){
                    cout<<"Enter x: ";cin>>x;
                    cout<<"Enter base: ";cin>>b;
                    cout<<"log_"<<b<<"("<<x<<") = "<<MathOperations::logBase(x,b)<<endl;
                }else throw runtime_error("Invalid sub-choice!");
                break;
            }

            case 4:{
                int n;cout<<"Enter n: ";cin>>n;
                cout<<n<<"! = "<<MathOperations::factorial(n)<<endl;
                break;
            }

            case 5:{
                cout<<"1. nCr  2. Full Binomial Expansion (a+b)^n\nChoice: ";
                int s;cin>>s;

                if(s==1){
                    int n,r;
                    cout<<"Enter n: ";cin>>n;
                    cout<<"Enter r: ";cin>>r;
                    cout<<"C("<<n<<", "<<r<<") = "<<Binomial::nCr(n,r)<<endl;
                }else if(s==2){
                    int n;cout<<"Enter n: ";cin>>n;Binomial::expand(n);
                }else throw runtime_error("Invalid sub-choice!");
                break;
            }

            case 6:{
                Polynomial p;p.input();
                cout<<"Polynomial P(x) = ";p.display();

                cout<<"1. Evaluate  2. Derivative  3. Indefinite Integral  4. Definite Integral\nChoice: ";
                int s;cin>>s;

                if(s==1){
                    double x;cout<<"Enter x: ";cin>>x;
                    cout<<"P("<<x<<") = "<<p.evaluate(x)<<endl;
                }else if(s==2){
                    Polynomial d=p.derivative();cout<<"P'(x) = ";d.display();
                }else if(s==3){
                    Polynomial in=p.integrate();cout<<"Integral P(x) dx = ";in.display();cout<<" (+ C)\n";
                }else if(s==4){
                    double a,b;
                    cout<<"Enter lower bound a: ";cin>>a;
                    cout<<"Enter upper bound b: ";cin>>b;
                    cout<<"Definite integral from "<<a<<" to "<<b<<" = "<<p.definiteIntegral(a,b)<<endl;
                }else throw runtime_error("Invalid sub-choice!");
                break;
            }

            case 7:{
                cout<<"1. Add  2. Multiply  3. Transpose  4. Determinant\nChoice: ";
                int s;cin>>s;

                if(s==1){
                    Matrix a,b;
                    cout<<"Matrix A:\n";a.input();
                    cout<<"Matrix B:\n";b.input();
                    cout<<"A + B =\n";a.add(b).display();
                }else if(s==2){
                    Matrix a,b;
                    cout<<"Matrix A:\n";a.input();
                    cout<<"Matrix B:\n";b.input();
                    cout<<"A * B =\n";a.multiply(b).display();
                }else if(s==3){
                    Matrix a;
                    cout<<"Matrix A:\n";a.input();
                    cout<<"A^T =\n";a.transpose().display();
                }else if(s==4){
                    Matrix a;
                    cout<<"Matrix A:\n";a.input();
                    cout<<"Determinant = "<<a.determinant()<<endl;
                }else throw runtime_error("Invalid sub-choice!");
                break;
            }

            case 8:{
                auto f=chooseFunction();double x;
                cout<<"Enter the point x at which to differentiate: ";cin>>x;
                cout<<"f'("<<x<<") = approx "<<Calculus::numericalDerivative(f,x)<<endl;
                break;
            }

            case 9:{
                auto f=chooseFunction();double a,b;
                cout<<"Enter lower bound a: ";cin>>a;
                cout<<"Enter upper bound b: ";cin>>b;
                cout<<"Integral from "<<a<<" to "<<b<<" = approx "<<Calculus::numericalIntegral(f,a,b)<<endl;
                break;
            }

            case 0:
                cout<<"Thank you for using the calculator, "<<user.getName()<<"! Goodbye.\n";
                break;

            default:
                cout<<"Invalid choice! Please select a valid menu option.\n";
            }
        }
        catch(const exception&e){
            cout<<"Error: "<<e.what()<<endl;
        }

    }while(choice!=0);

    return 0;
}