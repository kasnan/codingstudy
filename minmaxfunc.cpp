#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    // 최댓값은 42, 최솟값은 -8
    int arr[] = { 11, 4, -5, 9, -8, 34, 0 };
    
    int min = *min_element(std::begin(arr), std::end(arr));
    // min = *min_element(std::begin(arr), arr+0);
    int max = *max_element(std::begin(arr), std::end(arr));

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    return 0;
}