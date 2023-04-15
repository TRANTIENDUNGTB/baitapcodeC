#include <stdio.h>

char arr[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks.\
 Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien\
 Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa

void Inversion()
{
    int length = sizeof(arr);
    int dem=0;
    int i;
    for( i =length; i>=0; i--)
    {
        dem++; // biến đếm để đếm số lượng chữ cái trong 1 từ
        if(*(arr + i) == ' ')
        {
        	int j;
            for( j = i+1; j < i + dem ; j++)
            {
                printf("%c", *(arr + j));
            }
            printf("%c", ' ');
            dem=0;
        }
        if (i == 0) // in ra chữ đầu tiên
        {
        	int j;
            for (j = 0; j < length; j++)
            {
                if (*(arr + j) == ' ')
                {
                	int k;
                    for ( k = 0; k < j; k++)
                    {
                        printf("%c", *(arr + k));
                    }
                    break;  // in ra chữ đầu tiên xong break vòng for
                }
            }
        } 
    }
    
}
void capital_letter_after_the_dot()
{
	int i=0;
    for( i; i<sizeof(arr); i++)
    {
          
        if(*(arr+i) =='.' && 97<=*(arr+i+2) && *(arr+i+2)<= 122)
        {
            *(arr+i+2) = *(arr+i+2)-32;
        }
        printf("%c", *(arr+i));
    }
}
void plain_Print()
{
	int i=0;
    for( i; i<sizeof(arr); i++)
    {
          
        if( 65<=*(arr+i) && *(arr+i)<= 90)
        {
            *(arr+i) = *(arr+i)+32;
        }
        printf("%c", *(arr+i));
    }
}
void floral_Print()
{
	int i=0;
    for( i; i<sizeof(arr); i++)
    {
          
        if(97<=*(arr+i) && *(arr+i)<= 122)
        {
            *(arr+i) = *(arr+i)-32;
        }
        printf("%c", *(arr+i));
    }
}


int main(int argc, char const *argv[])
{
    printf("1,Viet mot chuyen dao nguoc: \n");
    Inversion();
    printf("\n----------------------\n");
    printf("2,In Hoa chu cai dau tien sau dau cham: \n");
    capital_letter_after_the_dot();
    printf("\n----------------------\n");
    printf("3,Chuyen doi tat ca doan van thanh chu thuong: \n");
    plain_Print();
    printf("\n-----------------------\n");
    printf("4,Chuyen doi tat ca doan van thanh chu hoa: \n");
    floral_Print();
    return 0;
}
