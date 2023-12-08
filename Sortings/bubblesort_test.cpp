#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "bubblesort.cpp"
#include <initializer_list>
#include "../Karatsuba algorithm/Karatsuba_algorithm.cpp"
#include <string>

TEST_CASE("Bubble Sort for Karatsuba_algorithm::LongValue") {
  
    std::vector<LongValue> data;
    std::vector<LongValue> sorted;
    SUBCASE("Empty array") {
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Single element array") {
        data = {1};
        sorted = {1};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Multiple elements array") {
        data = {3, 1, 2};
        sorted = {1, 2, 3};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Already sorted array") {
        data = {1, 2, 3};
        sorted = {1, 2, 3};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Reverse sorted array") {
        data = {3, 2, 1};
        sorted = {1, 2, 3};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }
    SUBCASE("Reverse sorted Large array") {
        data = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, {4,0,0,0,0,0,3,0,0,0,0,5}, {0,0,0,0,0,0,0,0,0,0,0,4}, {0,0,0,0,0,1,0,0,0,0,0}};
        sorted = {{0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,4},{4,0,0,0,0,0,3,0,0,0,0,5},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};

        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }
}

TEST_CASE("Bubble Sort for int") {
  
    std::vector<int> data;
    std::vector<int> sorted;
    SUBCASE("Empty array") {
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Single element array") {
        data = {1};
        sorted = {1};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Multiple elements array") {
        data = {3, 1, 2};
        sorted = {1, 2, 3};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Already sorted array") {
        data = {1, 2, 3};
        sorted = {1, 2, 3};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Reverse sorted array") {
        data = {3, 2, 1};
        sorted = {1, 2, 3};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }
    SUBCASE("Reverse sorted Large array") {
        data = {536973, -503155, 355814, -710570, 368820, -411975, -352960, 219466, -34014, -95335, 243586, 173544, -831249, -439054, 564012, -819408, -274916, 298739, 50040, -397061, -851106, 483609, -848285, 503359, 157045, 896658, 321876, 45111, 51566, 196282, -305149, 990873, -737377, -70335, -679347, 394972, 92268, 77822, -366384, -621414, -182888, 265606, -423477, -520290, 79894, -606700, -481813, 356840, 730002, 707816, -223318, -730095, -787096, 969551, 624511, 269415, 760895, -657132, -542732, 664063, -981556, -990485, -691808, -138283, -2381, 509940, 474112, 937360, -594839, -288120, 92344, -161840, 394046, 335776, 182090, -61743, 256615, 639660, -565886, 162723, 432876, -159378, 179023, 29181, 697331, 921362, 473515, 859083, 64961, 65707, -244716, -538565, -623166, -890883, -440320, 14359, -809130, 630294, 404676, -759308};
        sorted = {-990485, -981556, -890883, -851106, -848285, -831249, -819408, -809130, -787096, -759308, -737377, -730095, -710570, -691808, -679347, -657132, -623166, -621414, -606700, -594839, -565886, -542732, -538565, -520290, -503155, -481813, -440320, -439054, -423477, -411975, -397061, -366384, -352960, -305149, -288120, -274916, -244716, -223318, -182888, -161840, -159378, -138283, -95335, -70335, -61743, -34014, -2381, 14359, 29181, 45111, 50040, 51566, 64961, 65707, 77822, 79894, 92268, 92344, 157045, 162723, 173544, 179023, 182090, 196282, 219466, 243586, 256615, 265606, 269415, 298739, 321876, 335776, 355814, 356840, 368820, 394046, 394972, 404676, 432876, 473515, 474112, 483609, 503359, 509940, 536973, 564012, 624511, 630294, 639660, 664063, 697331, 707816, 730002, 760895, 859083, 896658, 921362, 937360, 969551, 990873};
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }
}

TEST_CASE("Bubble Sort for string") {
  
    std::string data;
    std::string sorted;
    SUBCASE("Empty array") {
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Single element array") {
        data = "D";
        sorted = "D";
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Reverse sorted array") {
        data = "FEDCBA"; 
        sorted = "ABCDEF";
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }

    SUBCASE("Already sorted array") {
        data = "ABC";
        sorted = "ABC";
        bubbleSort(data.begin(), data.end());
        CHECK(data == sorted);
    }
}