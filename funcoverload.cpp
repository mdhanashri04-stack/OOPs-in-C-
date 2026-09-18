#include<iostream>
int add(int first, int second) {
    return first + second;
}

double add(double first, double second) {
    return first + second;
}
int add(int first, int second, int third) {
    return first + second + third;
}

int main(){
    std::cout << "Sum of 2 integers: " << add(5, 10) << std::endl;
    std::cout << "Sum of 2 doubles: " << add(5.5, 10.5) << std::endl;
    std::cout << "Sum of 3 integers: " << add(5, 10, 15) << std::endl;
    return 0;
}