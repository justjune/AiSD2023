#include <iostream>
#include <fstream>
#include <cstring>

#include <vector>




class LongValue{
    private:
        int *values;      // массив с цифрами числа записанными в обратном порядке
        size_t length;    // длинна числа
    public:
        LongValue() : values(nullptr), length(0) {}  // конструктор по умолчанию

        LongValue(int *x, size_t l) : values(new int[l]), length(l) {
            for (size_t i = 0; i < length; ++i) {
                values[i] = x[i];
                std::cout<<x[i];
            }
            std::cout<<'\n';
        }

        // Деструктор для освобождения выделенной памяти
        ~LongValue() {
            delete[] values;
        }
        size_t getLength(){
            return length;
        }
        // Оператор сложения
        LongValue operator+(const LongValue& other) {
            size_t resultLength = std::max(length, other.length)+1;
            int *resultValues = new int[resultLength]();

            int carry = 0;
            for (size_t i = 0; i < resultLength; ++i) {
                int sum = carry;
                if (i < length) sum += values[i];
                if (i < other.length) sum += other.values[i];

                resultValues[i] = sum % 10;
                carry = sum / 10;
            }

            
            LongValue res(resultValues, resultLength);
            return res;
        }

        // Оператор сравнения
        bool operator==(const LongValue& other) const {
            if (length != other.length) {
                std::cout<<length<<" "<<other.length<<'\n';
                return false;
            }

            for (size_t i = 0; i < length; ++i) {
                if (values[i] != other.values[i]) {
                    return false;
                }
            }

            return true;
        }

        int operator[](size_t index) const {
            if (index < length) {
                return values[index];
            } else {
            
            return -1;  
        }
}
};

int main() {
    // Пример создания объектов LongValue
    int array1[] = {1, 2, 3};   // число 321
    int array2[] = {4, 5, 6};   // число 654

    LongValue num1(array1, 4);
    LongValue num2(array2, 4);
    
    // Пример сложения чисел
    LongValue sum = num1 + num2;
    //std::cout<<sum.getLength();
    // Вывод результата сложения
    //std::cout << "Sum: ";
    //for (size_t i = 0; i < sum.getLength(); ++i) {
    //    std::cout << sum[i];
    //}
    //std::cout << std::endl;

    // Пример сравнения чисел
    if (num1 == num2) {
        std::cout << "Numbers are equal." << std::endl;
    } else {
        std::cout << "Numbers are not equal." << std::endl;
    }

    return 0;
}
