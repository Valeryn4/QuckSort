#include <algorithm>
#include <iostream>
#include <vector>

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if (first == last) return;
    auto pivot = *std::next(first, std::distance(first, last) / 2);
    auto middle1 = std::partition(first, last,
        [pivot](const auto& em) { return em < pivot; });
    auto middle2 = std::partition(middle1, last,
        [pivot](const auto& em) { return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
}

int main()
{

    std::vector<int> arr = { 0, 2, 10, 2,3, 15, 20, 5, 4, 3, 2, 1, 13 };

    quicksort(arr.begin(), arr.end());
    for (auto i : arr)
        std::cout << " " << i;

    std::cout << std::endl;
    system("pause");

    return 0;
}