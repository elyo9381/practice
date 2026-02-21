import java.util.*;
import java.io.*;

/**
 * 이분탐색 / 파라메트릭 서치 템플릿
 * 시간복잡도: O(N log X) - N: 검증 비용, X: 탐색 범위
 *
 * 사용 상황:
 * - 값 존재 여부 확인 (수 찾기)
 * - "최솟값의 최댓값" / "최댓값의 최솟값" (파라메트릭)
 * - 나무 자르기, 랜선 자르기, 공유기 설치 등
 *
 * 핵심 판별법:
 * - "X 이상/이하로 만들 수 있는가?" → 이분탐색
 * - 결정 함수가 단조성(monotone)을 가지면 파라메트릭 적용 가능
 */
public class binary_search_template {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        // 기본 이분탐색: target이 arr에 존재하는지
        int target = Integer.parseInt(br.readLine().trim());
        System.out.println(binarySearch(arr, target) ? 1 : 0);
    }

    // 기본 이분탐색
    static boolean binarySearch(int[] arr, int target) {
        int lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }

    /**
     * 파라메트릭 서치 - "최댓값의 최솟값" 패턴
     * 예: 나무 자르기 (BOJ 2805)
     * - lo: 가능한 최소 답
     * - hi: 가능한 최대 답
     * - check(mid): mid로 조건을 만족하는가?
     */
    static long parametricSearch(long lo, long hi, long target) {
        long answer = 0;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            if (check(mid, target)) {
                answer = mid;  // 조건 만족, 더 큰 값 시도
                lo = mid + 1;
            } else {
                hi = mid - 1;  // 조건 불만족, 더 작은 값 시도
            }
        }
        return answer;
    }

    // 결정 함수 (문제에 맞게 수정)
    static long[] data; // 문제 데이터

    static boolean check(long mid, long target) {
        long sum = 0;
        for (long d : data) {
            if (d > mid) {
                sum += d - mid;
            }
        }
        return sum >= target;
    }

    /**
     * lower_bound: target 이상인 첫 인덱스
     */
    static int lowerBound(int[] arr, int target) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    /**
     * upper_bound: target 초과인 첫 인덱스
     */
    static int upperBound(int[] arr, int target) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
