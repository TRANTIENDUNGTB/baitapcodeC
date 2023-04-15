#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*-------------------doi tu so ra chu----------------------*/

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
} typeArray;

/*---------------------Ham doi ra don vi------------------------*/
void readUnit(uint8_t num){
    switch (num)
    {
    case 0:
        printf("KHONG ");
        break;
    case 1:
        printf("MOT ");
        break;
    case 2:
        printf("HAI ");
        break;
    case 3:
        printf("BA ");
        break;
    case 4:
        printf("BON ");
        break;
    case 5:
        printf("NAM ");
        break;
    case 6:
        printf("SAU ");
        break;
    case 7:
        printf("BAY ");
        break;
    case 8:
        printf("TAM ");
        break;
    case 9:
        printf("CHIN ");
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*---------------------Ham doi ra thap phan------------------------*/
void readDecimal(uint8_t dec){
    switch (dec)
    {
    case 0:
        printf("DONG\n");
        break;
    case 1:
    case 4:
        printf("MUOI ");
        break;
    case 3:
        printf("NGHIN  ");
        break;
    case 2:
    case 5:
        printf("TRAM ");
        break;
    case 6:
        printf("TRIEU  ");
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
    
    
}

/*---------------------Ham nhap so------------------------*/
void inputNumber(uint32_t *number, typeArray *array){
    do
    {
        printf("\nNhap So : ");
        scanf("%d",number);
    } while (*number < 0 || *number > 10000000);

    array->size = 7;
    array->firstAdd = (uint8_t*)calloc(array->size,sizeof(uint8_t));

    //Tach tung chu so va nhap nguoc vao mang
    uint32_t reNum = *number;
    uint32_t last;
    for(int i = 0; i < array->size; i++){
        last = reNum % 10;
        array->firstAdd[i] = last;
        reNum /=10;
    }
}

/*---------------------Ham in phan "Nghin" & phan "dong"------------------------*/
void printCase(uint8_t value, typeArray array, uint8_t from){

    //Kiem tra & in ra chu so dau tien 
    int check = 0;
    for (int i = from+2; i < array.size; i++)
    {
        if(array.firstAdd[i] > 0)
            check = 1;
    }
    if(check){
        readUnit(array.firstAdd[(from+2)]);
        readDecimal(from+2);
        if(array.firstAdd[(from)] > 0 && array.firstAdd[(from+1)] == 0)
            printf("LINH ");
    }
    
    //Kiem tra & in ra chu so tiep theo  
    switch (value)
    {
    case 0:
    case 1:
        readDecimal(from);
        break;
    case 2:
    case 3:
        if(array.firstAdd[(from+1)] > 1){
            readUnit(array.firstAdd[(from+1)]);
            readDecimal(from+1);
        }else{
            readDecimal(from+1);
        }
        readDecimal(from);
        break;
    case 4:
    case 5:
        readUnit(array.firstAdd[(from)]);
        readDecimal(from);
        break;
    case 6:
    case 7:
        if(array.firstAdd[(from+1)] > 1){
            readUnit(array.firstAdd[(from+1)]);
            readDecimal(from+1);
        }else{
            readDecimal(from+1);
        }
        if(array.firstAdd[(from)] == 5){
            printf("LAM ");
            readDecimal(from); 
        }else{
            readUnit(array.firstAdd[(from)]);
            readDecimal(from);
        }
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*---------------------Ham thuc hien doc so------------------------*/
void readNumber(typeArray array){

    //doc phan "Trieu"
    if(array.firstAdd[array.size-1] > 0){
        readUnit(array.firstAdd[array.size-1]);
        readDecimal(array.size-1);
    }

    //Tinh toan phan "Nghin"
    uint8_t x = 0;
    for(int i = array.size-4; i < array.size-1; i++){
        uint8_t a = (array.firstAdd[i] > 0) ? 1 : 0;
        x = x*2 + a;
    }
    
    //Tinh toan phan "dong"
    uint8_t y = 0;
    for(int i = array.size-7; i < array.size-4; i++){
        uint8_t a = (array.firstAdd[i] > 0) ? 1 : 0;
        y = y*2 + a;
    }
    
    //Tinh toan cac TH phan "Nghin" + phan "dong"
    if(x + y == 0){ 
        printf("DONG\n"); 
    }
    else{
        if(x > 0){
            printCase(x,array,array.size-4);
            if(y > 0)
                printCase(y,array,array.size-7);
            else
                printf("DONG\n");
        }else{
            printCase(y,array,array.size-7);
        }
    }

}

int main(int argc, char const *argv[])
{
    uint32_t num;
    typeArray arr;

    inputNumber(&num, &arr);
    readNumber(arr);
    return 0;
}

