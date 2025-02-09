
#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;

// ������� ��� ������������ ������� ��������� ����� 
void generate_random_arr(int* arr, int size, int min_val, int max_val) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        // ���������� ��������� ����� 
        arr[i] = min_val + (rand() % (max_val - min_val + 1));
    }
}

// ������� ��� ������ �������
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

// ������� ��� �������� �������� �� ������� 
int* remove_el(const int* arr, int size, int index, int& new_size) {
    if (index < 0 || index >= size) {
        cout << "������: ������������ ������ ��� ��������." << endl;
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

// ������� ��� ���������� �������� ����� ������� �������
int* add_after_first_el(const int* arr, int size, int& new_size) {
    int insert_index = 0;
    int i = 0;
    bool found_even = false; // ����

    while (i < size && !found_even) {
        if (arr[i] % 2 == 0) {
            insert_index = i + 1; // ��������� ����� ����� �������
            found_even = true; // ������������� ����, ����� ���������� �����
        }
        i++;
    }

    if (insert_index == -1) {
        cout << "� ������� ��� ������ ���������." << endl;
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
    cout << "������� ������ �������: ";
    cin >> array_size;
    int* my_array = new int[array_size];

    // ���������� ������ ��������� ����� 
    generate_random_arr(my_array, array_size, 1, 100);
    cout << "�������� ������: ";
    print_arr(my_array, array_size);

    // �������� ������ ��� �������� �� ������������
    cout << "������� ������ �������� ��� ��������: ";
    cin >> index_to_remove;

    // ������� ������� �� �������
    int new_size_remove;
    int* array_after_remove = remove_el(my_array, array_size, index_to_remove, new_size_remove);
    delete[] my_array; // ����������� ������������ ������
    my_array = nullptr;

    // �������� ������ ����� ��������
    cout << "������ ����� �������� �������� � �������� " << index_to_remove << ": ";
    print_arr(array_after_remove, new_size_remove);

    // ��������� ������� ����� ������� �������
    int new_size_add;
    int* array_after_add = add_after_first_el(array_after_remove, new_size_remove, new_size_add);

    delete[] array_after_remove; // ����������� ������������ ������
    array_after_remove = nullptr;

    cout << "������ ����� ���������� �������� ����� ������� �������: ";
    print_arr(array_after_add, new_size_add);
    delete[] array_after_add; //  ����������� ������������ ������
    array_after_add = nullptr;

    return 0;
}