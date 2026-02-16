package nocode.array

import kotlin.math.min


/**
 * pivot은 좌 배류값의 합과 우 밸류값으 합이 같을때이다.
 * 이떄 pivot 의 인덱스를 찾아 내는것이다.
 * sliding 의 기법이 필요하다
 *
 * 투포인터
 * 슬라이딩 윈도우 할때 주의사항 !
 * a,b 포인터
 * b 포인터가 전진하고 특정 조건에서 a포인터가 전지해야할때 ?
 * a를 어떻게 끓고 올래 ?
 * b+1-a 를 하게되면 a가 증가할때마다 b까지 도달할수 있는것이다.
 *
 */
fun main() {

    val nums = arrayOf(1, 8, 2, 9, 2, 3, 6)
    println(slidingPivot(nums))

    val nums2 = arrayOf(2,3,1,2,4,3)

    println(slidingSubset2(nums2, 4))

    println(equal_range(nums2,0,nums2.size-1,7))
}

fun slidingSubset( nums: Array<Int>, target : Int): Int {

    var ans = Int.MAX_VALUE
    var start = 0
    var sum =0

    for (end in nums.indices){
        sum += nums[end]
        while( sum >= target) {
            ans = min(ans,end + 1 - start)
            sum -= nums[start++]
        }
    }
    return if(ans != Int.MAX_VALUE) ans else 0
}

fun slidingSubset2(nums: Array<Int>, target: Int): Int {

    // 문제에서 찾고자 하는 것은 서브어레이의 길이
    // 여기서 필요한 개념은 서브어레이 라는것은 모든 배열의 순차 합이라는것이다.
    // a = {2,3,1,2,4,3}
    // b = {0,2,5,6,8,12,15}
    // a의 서브 집합은 a의 밸류들을 순차적으로 더하여 만든 집합 b가 있을때
    // b의 특정 인덱스의 차이가 서브어레이의 길이가 될수있다.
    // 이러한 개념을 통해서 이진탐색으로 내가 찾고자하는 서브어레이의 값을 찾을수있고 길이를 찾을수있다.
    // 0은 원래 없던 인덱스(값)이므로 바이너리 서치 해서 찾은값에서 bound - b.first()를 빼고
    // i 번에서 시작하니 -1 를 통해서 인덱스를 뺀다 ( 서브어레이의 길이를 요구하기 때문에 )

    var n = nums.size
    if (n == 0) return 0

    var ans = Int.MAX_VALUE
    val sums = Array(n + 1) { 0 }

    for (i in 1..n){
        sums[i] = sums[i-1] + nums[i-1]
    }

    for(i in 1..n){
        val findNum = target + sums[i - 1]
        val bound = lower_bound(sums, 0, sums.size, findNum)
        if(bound != sums.last()) ans = min(ans, (bound - (sums.first() + i -1)))
    }

    return if(ans != Int.MAX_VALUE) ans else 0
}

fun lower_bound(
    elements: Array<Int>,
    low: Int, high: Int, value: Int) : Int {
    var lo = low
    var hi = high
    var mid: Int
    while(lo < hi) {
        mid = (lo + hi) shr 1
        if (mid == high)
            return high

        if(elements[mid] < value) { // value보다. 작은 값을 만난 경우
            lo = mid + 1            // 탐색해야 하는 범위가 뒤쪽에 있다고 가정
        } else {                    // value보다 크거나 같은 값을 만난 경우
            hi = mid                // 탐색해야 하는 범위가 안쪽에 있다고 가정
        }
    }

    return lo                     // 맨 왼쪽 범위가 처음 나타나는 위치를 의미
}

fun upper_bound(elements: Array<Int>,
                low: Int, high: Int, value: Int) : Int {
    var lo = low
    var hi = high
    var mid: Int = high
    while (lo < hi) {
        mid = (lo + hi) shr 1
        if (mid == high)
            return high

        if(elements[mid] <= value) {  // value보다 작거나 같은 값을 만난 경우
            lo = mid + 1              // 탐색 범위가 뒤쪽에 있다고 가정
        } else {                      // value보다 큰 값을 만난 경우
            hi = mid                  // 탐색 범위가 안쪽에 있다고 가정
        }
    }

    return lo                       // 맨 왼쪽 범위가 처음 나타나는 위치를 의미
}


fun equal_range(
    elements: Array<Int>,
    low: Int, high: Int, value: Int) : Pair<Int,Int> {
    return Pair(lower_bound(elements, low, high, value), upper_bound(elements, low, high, value))
}


fun slidingPivot(nums: Array<Int>): Int {
    var prev = 0
    val sum = nums.sum()
    var leftSum = 0
    var rightSum = sum

    nums.indices.forEach { idx ->
        val num = nums[idx]
        rightSum -= num
        leftSum += prev

        if(leftSum == rightSum){
            return idx
        }
        prev = num
    }
    return -1
}
