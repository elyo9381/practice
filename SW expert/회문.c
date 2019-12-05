#include <stdio.h>

int main(){
    int length;
    int count;
    int i,j,k,m;

    char map[8][8] = {0,};

    bool flag;

    for(i =0; i<10; i++){
        cin>> length;

        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
                cin>> map[j][k];

        count = 0;
        for(j=0; j<8 ;j++){
            for(k=0; k<(8-length+1); k++){
                flag = true;
                for(m=0; m<(length/2);m++)
                {
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