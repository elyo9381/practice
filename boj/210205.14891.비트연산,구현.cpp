#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1000001;


/**
 * 주의할점 비트연산시 내가 생각하는것처럼 비트의 자릿수가 채워지지않으니 
 * 0000 0001 에서 1100 0000 으로 바꾸려면 자릿수를 채워는걸 생각하면서 비트연산해야한다. 
 * 그리고 톱니바퀴의 극의 순서를 내멋대로 정했는데 왼쪽으로 가는걸 1번으로 칭했다.. 
 * 왜그랬지.. 이것때문에 많은 시간이 소요됨.. 
 * 
 * 또한 문자열에서 순서에 비트연산하기 위한 수를 만들기 위해서 뒤에서부터 떙겨야한다. 
*/

int wheel[5], move_dir[5], k, wheel_num, dir, temp_num, is_first_one, is_last_one, result;
char wheel_string[10];

int string_to_int() {
    
    int result = 0;


    for(int i=0; i<8; i++){
        int square_cnt = 7-i;
        int num = wheel_string[i] - '0';
        result += num << square_cnt;
    }
    
    return result;
}

void wheel_rotate(int wheel_num, int dir){
    
    if(dir == 0) return;
    
    // 시계방향
    if(dir == 1) {
        temp_num = wheel[wheel_num] >> 1;
        
        if(wheel[wheel_num] & 1) is_last_one = 1;
        else is_last_one = 0;
        
        wheel[wheel_num] = temp_num & 255;
        
        if(is_last_one) wheel[wheel_num] = wheel[wheel_num] | 128;
    }
    // 반시계 방향
    else{
        temp_num = wheel[wheel_num] << 1;
        
        if(wheel[wheel_num] & 128) is_first_one = 1;
        else is_first_one = 0;

        wheel[wheel_num] = temp_num & 255;

        if(is_first_one) wheel[wheel_num] = wheel[wheel_num] | 1;
    }
}

void right_check() {
    int r_dir = dir;
    for(int i=wheel_num; i<=4; i++){
        int c_wheel_num = i;
        int r_wheel_num = i+1;
        int c_wheel_is_one = 0;
        int r_wheel_is_one = 0;

        if(r_wheel_num > 4) break;

        if(wheel[r_wheel_num] & 2) r_wheel_is_one = 1;
        if(wheel[c_wheel_num] & 32) c_wheel_is_one = 1;

        
        if(c_wheel_is_one != r_wheel_is_one){
            r_dir *= -1;
            move_dir[r_wheel_num] = r_dir;
        }
        else{
            break;
        }
    }
}

void left_check() {
    int l_dir = dir;
    for(int i=wheel_num-1; i>=1; i--){
        int l_wheel_num = i;
        int c_wheel_num = i+1;
        int l_wheel_is_one = 0;
        int c_wheel_is_one = 0;

        if(wheel[l_wheel_num] & 32) l_wheel_is_one = 1;
        if(wheel[c_wheel_num] & 2) c_wheel_is_one = 1;

        if(l_wheel_is_one != c_wheel_is_one){
            l_dir *= -1;
            move_dir[l_wheel_num] = l_dir;
        }
        else{
            break;
        }
    }
}

int main(){
    
    for(int i=1; i<=4; i++) {
        scanf("%s", wheel_string);
        
        int num = string_to_int();
        wheel[i] = num;
    }
   
    scanf("%d", &k);
        
    for(int i=1; i<=k; i++){
        scanf("%d %d", &wheel_num, &dir);

        for(int i=1; i<=4; i++) move_dir[i] = 0;
        
        move_dir[wheel_num] = dir;

        left_check();
        
        right_check();
        
        for(int i=1; i<=4; i++){
            wheel_rotate(i, move_dir[i]);
        }
    }
    
    for(int i=1; i<=4; i++){
        if(wheel[i] & 128){
            result += 1 << (i-1);
        }
    }
    
    printf("%d\n", result);
}
