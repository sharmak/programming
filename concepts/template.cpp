#include <iostream>
#include <vector>
template <class T>
T  sum(const std::vector<T> array, T val=0) {
    T sum = val;
    for(auto& i : array) {
        sum += i;
    }
    return sum;
}
int main() {
    std::vector<int> v(2);
    v.push_back(1); v.push_back(2);
    std::vector<double> v1(2);
    v1.push_back(1.5); v1.push_back(2.5);
    std::cout << sum(v, 20) << std::endl;
    std::cout << sum(v1) << std::endl;
    return 0;
}
