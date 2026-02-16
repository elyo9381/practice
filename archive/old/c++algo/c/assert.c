#include <assert.h>
#include <stdio.h>
int GetSumAToB(int a,int b)
{
    int index = 0;
    int sum = 0; //sum:= 0
    for(index = a; index<=b; ++index)//반복(index:=start; index<=end; index:=index+1)
    {
        sum += index; //sum := sum+index    
    }
    return sum;//반환 sum
}
void TestGetSumAToB()
{
    assert(GetSumAToB(1,10)==55);
    assert(GetSumAToB(5,10)==45);
    printf("GetSumAToB 테스트 성공\n");
}
int main()
{
    TestGetSumAToB();	
    return 0;
}