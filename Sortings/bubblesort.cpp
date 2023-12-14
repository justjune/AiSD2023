#include <functional>

template <typename Iterator, typename Compare = std::less<>>
void bubbleSort(Iterator begin, Iterator end, Compare comp = Compare()) {
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = begin; j != end - 1; ++j) {
            if (comp(*j , *(j + 1))==0) {
                std::swap(*j, *(j + 1));
            }
        }
    }
}

