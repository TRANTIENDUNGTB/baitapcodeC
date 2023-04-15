#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
//  sap xep mang theo thu tu tang dan
//  liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                              7 xuat hien 2 lan
//                                              8 xuat hien 3 lan

typedef struct
{
    uint8_t size;
    uint8_t *firstAdd;
} typeArray;

int randomA(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length)
{
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t) * value->size);
    int r;
    for (int i = 0; i < value->size; ++i)
    {
        value->firstAdd[i] = randomA(0, 10);
    }
}

void printArray(typeArray arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.firstAdd[i]);
    }
    printf("\n");
}

void mov(uint8_t *a, uint8_t *b)
{
    uint8_t temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(typeArray arr)
{
    int i, j, min_idx;

    // Duyệt qua từng phần tử của mảng
    for (i = 0; i < arr.size - 1; i++)
    {
        // Tìm phần tử nhỏ nhất trong mảng từ vị trí hiện tại đến phần tử cuối cùng
        min_idx = i;
        for (j = i + 1; j < arr.size; j++)
        {
            if (arr.firstAdd[j] < arr.firstAdd[min_idx])
            {
                min_idx = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử hiện tại
           mov(&arr.firstAdd[min_idx], &arr.firstAdd[i]);
    }
}

void countArray (typeArray arr)
{
int count[arr.size];
// Khởi tạo số lần xuất hiện của từng phần tử là 0
for (int i = 0; i < arr.size; i++)
{
    count[i] = 0;
}

// Duyệt qua từng phần tử của mảng
for (int i = 0; i < arr.size; i++)
{
    // Tăng số lần xuất hiện của phần tử đó lên 1
    count[arr.firstAdd[i]]++;
   
}

// Liệt kê số lần xuất hiện của từng phần tử
for (int i = 0; i < arr.size; i++)
{
    if (count[i] > 0)
    {
        printf("%d xuat hien %d lan\n", i, count[i]);
    }
}
}

int main(int argc, char const *argv[])
{
typeArray arr;
randomArray(&arr, 20);

printf("Mang ban dau:\n");
printArray(arr);

sortArray(arr);

printf("Mang sau khi sap xep theo thu tu tang dan:\n");
printArray(arr);

printf("So lan xuat hien cua tung phan tu:\n");
countArray(arr);


return 0;
}




