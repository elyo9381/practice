package backjoon.greedy


fun main(){
    val num = readLine()?.toLong() ?: return
    var sum = 0L
    var count = 1L
    while(num >= sum){
        sum += count++
    }
    println(if( sum == num) count-1 else count-2)
}

/**
 * 수들의 합이란건
 * (n * n+1)/2  라는 공식이 존재한다.
 * 그렇다면
 * 200
 */
