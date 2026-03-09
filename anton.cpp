#include <iostream>
#include <string>

void poslatNahui(int*& ptr, const std::string& target) {
    if (ptr != nullptr) {
        std::cout << "Посылаем " << target << " нахуй через указатель: " << *ptr << std::endl;
        delete ptr;
        ptr = nullptr;
    }
}

int& plohayaSsylka() {
    int localVar = 666;
    std::cout << "Возвращаем ссылку на локальную переменную. Ай-яй-яй!" << std::endl;
    return localVar;
}

void poslatPointerNaPointer(int** ptr2ptr, const std::string& target) {
    if (ptr2ptr != nullptr && *ptr2ptr != nullptr) {
        std::cout << "Посылаем " << target << " нахуй через указатель на указатель: " << **ptr2ptr << std::endl;
        **ptr2ptr = 1488;
    }
}

void poslatConstRef(const int& ref, const std::string& target) {
    std::cout << "Посылаем " << target << " нахуй (константная ссылка): " << ref << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "Начинаем тупую программу с указателями и ссылками" << std::endl;

    int* pAnton = new int(777);
    std::cout << "Антон имеет значение: " << *pAnton << std::endl;

    poslatNahui(pAnton, "Антона");

    if (pAnton == nullptr) {
        std::cout << "Антон теперь nullptr (после посылки нахуй)" << std::endl;
    }

    pAnton = new int(888);
    std::cout << "Антон вернулся с новым значением: " << *pAnton << std::endl;

    int** ppAnton = &pAnton;

    poslatPointerNaPointer(ppAnton, "Антона (через указатель на указатель)");
    std::cout << "Антон после посылки нахуй (ppAnton): " << *pAnton << std::endl;

    int b = 100500;
    int& refB = b;

    std::cout << "b = " << b << ", refB = " << refB << std::endl;

    poslatConstRef(refB, "refB");

    poslatConstRef(b, "b");

    int& badRef = plohayaSsylka();
    std::cout << "Висячая ссылка: " << badRef << " (это может быть что угодно, даже краш)" << std::endl;

    poslatConstRef(badRef, "висячую ссылку");

    int* arrayOfPointers[3];
    arrayOfPointers[0] = new int(111);
    arrayOfPointers[1] = new int(222);
    arrayOfPointers[2] = new int(333);

    std::cout << "Массив указателей:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "arrayOfPointers[" << i << "] = " << *arrayOfPointers[i] << std::endl;
    }

    poslatPointerNaPointer(&arrayOfPointers[1], "элемент массива [1]");

    std::cout << "После посылки нахуй элемента [1]: " << *arrayOfPointers[1] << std::endl;

    delete pAnton;
    for (int i = 0; i < 3; ++i) {
        delete arrayOfPointers[i];
    }

    std::cout << "Конец тупой программы. Все посланы нахуй." << std::endl;

    return 0;
}