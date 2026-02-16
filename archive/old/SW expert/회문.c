#include <stdio.h>

int main(){
    int length;
    int count;
    int i,j,k,m;
    //맵을 정렬 
    char map[8][8] = {0,};

    //일치 여부를 판단한다. 함수를 사용하지 않고
    bool flag;

    // 회문의 size입력
    for(i =0; i<10; i++){
        cin>> length;
        //맵에서 문자입력
        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
                cin>> map[j][k];

        //처음 카운트는 0이다.
        count = 0;

        for(j=0; j<8 ;j++){
            //회문의 사이즈보다 하나 많게 열을 순회 하려는 반복문
            for(k=0; k<(8-length+1); k++){
                flag = true;
                // 회문은 좌우가 일치하는 것이므로 /2하여 좌우가 일치하는지 확인을 위한 반복문
                for(m=0; m<(length/2);m++)
                {   
                    // 2차원 배열에서 첫인덱스와 length-1이 같은지 확인하는 조건문
                    if(map[j][k+m] != map[j][k+length-m-1])
                        flag = false;
                }
                if(flag)count++;
            }
        }

        for(j=0;j<8;j++) 
        {
            for(k=0;k<8-length+1;k++){
                flag=true;
                for(m=0;m<(length/2);m++){
                    if(map[k+m][j] != map[k+length-1-m][j])
                        flag = false;
                }
                if(flag)count++;
            }
        }

        cout<< count<< endl;
    }
    return 0;    
}