
#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;

// Функция для формирования массива случайных чисел 
void generate_random_arr(int* arr, int size, int min_val, int max_val) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        // Генерируем случайное число 
        arr[i] = min_val + (rand() % (max_val - min_val + 1));
    }
}

// Функция для печати массива
void print_arr(const int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Функция для удаления элемента по индексу 
int* remove_el(const int* arr, int size, int index, int& new_size) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: Недопустимый индекс для удаления." << endl;
        new_size = size;
        int* new_arr = new int[size];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        return new_arr;
    }

    new_size = size - 1;
    int* new_arr = new int[new_size];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (i != index) {
            new_arr[j] = arr[i];
            j++;
        }
    }
    return new_arr;
}

// Функция для добавления элемента после первого четного
int* add_after_first_el(const int* arr, int size, int& new_size) {
    int insert_index = 0;
    int i = 0;
    bool found_even = false; // Флаг

    while (i < size && !found_even) {
        if (arr[i] % 2 == 0) {
            insert_index = i + 1; // Вставляем после этого индекса
            found_even = true; // Устанавливаем флаг, чтобы прекратить поиск
        }
        i++;
    }

    if (insert_index == -1) {
        cout << "В массиве нет четных элементов." << endl;
        new_size = size;
        int* new_arr = new int[size];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        return new_arr;
    }

    new_size = size + 1;
    int* new_arr = new int[new_size];
    int value_to_insert = arr[insert_index - 1] + 2;
    int j = 0;
    for (int i = 0; i < size; ++i) {
        new_arr[j] = arr[i];
        j++;
        if (i == insert_index - 1) {
            new_arr[j] = value_to_insert;
            j++;
        }
    }
    return new_arr;
}

int main() {
    setlocale(LC_ALL, "RU");
    int array_size, index_to_remove;
    cout << "Введите размер массива: ";
    cin >> array_size;
    int* my_array = new int[array_size];

    // Генерируем массив случайных чисел 
    generate_random_arr(my_array, array_size, 1, 100);
    cout << "Исходный массив: ";
    print_arr(my_array, array_size);

    // Получаем индекс для удаления от пользователя
    cout << "Введите индекс элемента для удаления: ";
    cin >> index_to_remove;

    // Удаляем элемент по индексу
    int new_size_remove;
    int* array_after_remove = remove_el(my_array, array_size, index_to_remove, new_size_remove);
    delete[] my_array; // освобождаем динамическую память
    my_array = nullptr;

    // Печатаем массив после удаления
    cout << "Массив после удаления элемента с индексом " << index_to_remove << ": ";
    print_arr(array_after_remove, new_size_remove);

    // Добавляем элемент после первого четного
    int new_size_add;
    int* array_after_add = add_after_first_el(array_after_remove, new_size_remove, new_size_add);

    delete[] array_after_remove; // освобождаем динамическую память
    array_after_remove = nullptr;

    cout << "Массив после добавления элемента после первого четного: ";
    print_arr(array_after_add, new_size_add);
    delete[] array_after_add; //  освобождаем динамическую память
    array_after_add = nullptr;

    return 0;
}