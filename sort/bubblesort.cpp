template <typename Iterator, Compare compare>
void bubbleSort(Iterator begin, Iterator end, Compare compare) {
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = begin; j != end - 1; ++j) {
            if (compare(*j , *(j + 1))==0) {
                swap(*j, *(j + 1));
            }
        }
    }
}