package elyowon.programers.L2;


/**
 *
 */
public class L2_210630_타켓넘버_nextPermutation {
    public int solution(int[] numbers,int target) {
        int answer = 0;
        int sum = numbers[0];

        answer += dfs(sum,numbers,target,1);
        answer += dfs(-sum,numbers,target,1);
        return answer;
    }

    public int dfs(int sum,int[] numbers,int target,int idx) {

        if (idx >= numbers.length) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }

        int a = sum + numbers[idx];
        int b = sum - numbers[idx];

        int result = 0;
        result += dfs(a,numbers,target,idx + 1);
        result += dfs(b,numbers,target,idx + 1);

        return result;
    }


    public boolean nextPermutation(int[] src) {
        int i = src.length - 1;
        while( i>0 && src[i-1] >= src[i]) --i;

        if (i < 0) {
            return false;
        }

        int j = src.length - 1;
        while(src[i-1] >= src[j] ) --j;


        swap(src,i-1,j);

        int k = src.length-1;

        while( i< k){
            swap(src,i,k);
            ++i;
            --k;
        }
        return true;
    }

    private void swap(int[] src,int i,int j) {
        int tmp = src[i];
        src[i] = src[j];
        src[j] = tmp;
    }
}
