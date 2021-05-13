#include <iostream>;

void bubble_sort(int* a, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
}

void shaker_sort(int* a, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int new_right = left;
        for (int i = left; i < right; ++i) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;

                new_right = i;
            }
        }
        right = new_right;


        int new_left = right;
        for (int i = right; i > left; --i) {
            if (a[i] < a[i - 1]) {
                int t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;

                new_left = i;
            }
        }
        left = new_left;
    }
}

void insertion_sort(int* a, int n) {
    for (int sorted_part = 0; sorted_part < n; ++sorted_part) {
        for (int i = sorted_part; i < n; ++i) {
            if (a[sorted_part] > a[i]) {
                int t = a[i];
                a[i] = a[sorted_part];
                a[sorted_part] = t;
            }
        }
    }
}

void shell_sort_shell(int* a, int n) {
    int d = n;
    while (d > 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + d; j < n; j += d) {
                if (a[i] > a[j]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
        d /= 2;
    }
}

void shell_sort_hibbord(int* a, int n) {
    int d = 1;
    while (d < n) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + d; j < n; j += d) {
                if (a[i] > a[j]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
        d = (d + 1) * 2 - 1;
    }
}

void shell_sort_pratt(int* a, int n) {
    int* posl = new int[n];
    int posl_size = 0;
    int current_2i = 1;
    int cur_i = 0;
    int cur_j = 0;
    int cur_max_i = 0;
    int cur = 1;
    while (cur * 2 <= n) {
        int cur1 = cur;
        while (cur1 * 2 <= n) {
            posl[posl_size++] = cur;
            cur1 *= 2;
        }
        cur *= 3;
    }
    for (int k = 0; k < posl_size; ++k) {
        int d = posl[k];
        for (int i = 0; i < n; ++i) {
            for (int j = i + d; j < n; j += d) {
                if (a[i] > a[j]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }
    delete posl;
}

int selection_sort(int* a, int n) {
    int max_elem = a[0];
    for (int i = 1; i < n; ++i) {
        max_elem = std::max(max_elem, a[i]);
    }
    int* counter = new int[max_elem + 1];
    for (int i = 0; i < n; ++i) {
        counter[a[i]]++;
    }
    int current_index = 0;
    for (int i = 0; i <= max_elem; ++i) {
        for (int j = 0; j < counter[i]; ++j) {
            a[current_index++] = i;
        }
    }
}

void merge_arrays(int* a1, int size1, int* a2, int size2, int* dst) {
    int pointer1 = 0;
    int pointer2 = 0;
    int dst_pointer = 0;
    while (pointer1 < size1 || pointer2 < size2) {
        if (pointer1 == size1) {
            dst[dst_pointer++] = a2[pointer2++];
        } else if (pointer2 == size2) {
            dst[dst_pointer++] = a1[pointer1++];
        } else {
            if (a1[pointer1] < a2[pointer2]) {
                dst[dst_pointer++] = a1[pointer1++];
            } else {
                dst[dst_pointer++] = a2[pointer2++];
            }
        }
    }
}

void merge_sort(int* a, int n) {
    if (n <= 1) {
        return ;
    }
    int left_part_size = n / 2 + n % 2;
    int right_part_size = n - left_part_size;

    int* left_part = new int[left_part_size];
    for (int i = 0; i < left_part_size; ++i) {
        left_part[i] = a[i];
    }

    int* right_part = new int[right_part_size];
    for (int i = 0; i < right_part_size; ++i) {
        right_part[i] = a[left_part_size + i];
    }

    merge_sort(left_part, left_part_size);
    merge_sort(right_part, right_part_size);
    merge_arrays(left_part, left_part_size, right_part, right_part_size, a);
    delete left_part;
    delete right_part;
}

void quick_sort(int* a, int n) {
    if (n <= 1) {
        return;
    }
    if (!(a[0] <= 10 && 1 <= a[0])) {
        return;
    }
    int pivot_index = n / 2 + n % 2;
    int pivot = a[pivot_index];
    int left_pointer = 0;
    int right_pointer = n - 1;
    while (left_pointer <= right_pointer) {
        if (a[left_pointer] > pivot) {
            int t = a[left_pointer];
            a[left_pointer] = a[right_pointer];
            a[right_pointer] = t;
            --right_pointer;
        } else {
            ++left_pointer;
        }
    }
    int new_pivot_place = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == pivot) {
            new_pivot_place = i;
            break;
        }
    }
    if (left_pointer == n) {
        int t = a[left_pointer - 1];
        a[left_pointer - 1] = a[new_pivot_place];
        a[new_pivot_place] = t;
        quick_sort(a, n - 1);
        return;
    }
    left_pointer--;
    int t = a[left_pointer];
    a[left_pointer] = a[new_pivot_place];
    a[new_pivot_place] = t;
    quick_sort(a, left_pointer);
    quick_sort(a + left_pointer + 1, n - (left_pointer + 1));
}

int main() {}
