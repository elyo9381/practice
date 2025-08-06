package backjoon.greedy


/**
 * 아래의 방법은 매우 기초적인 풀이 방법이다.
 * O(N^2) 이기 떄문이다.
 * 이건 그리디가 아니고 브루트 포스 전략이다.
 *
 * 그럼 그리디는 무엇일까?
 * 계산으로 처리 할수있도록 하는것이 그리디이다.
 *
 *
 * 이걸 기억하자 초기값 + M - 1 . 초기값 부터 초기값 + M 까지 범위가 될수있다는 뜻이다. 이떄 M은 최대값이다. 해당 범위의
 *  특정수 A - M + 1 = M인데  이때 M은 최소값이다. M부터 A까지의 범위중에서
 */
fun main(){
    greedySolution()
}

fun bruteforceSolution(){
    val (n,m) = readLine()?.split(" ")?.map { it.toInt() } ?: return

    val appleCnt = readLine()?.toLong() ?: return

    var cnt = 0
    var start = 1
    var end = m

    repeat(appleCnt.toInt()){
        var x = readLine()?.toInt() ?: return
        var flag = true
        while(flag){
            if(x in start..end){
                flag = false
            } else if (start > x){
                start--; end --; cnt++
            } else {
                start++; end++; cnt++
            }
        }
    }
    println(cnt)
}
fun greedySolution(){
    val (n, m) = readLine()?.split(" ")?.map { it.toInt() } ?: return
    val appleCnt = readLine()?.toInt() ?: return
    var currentPos = 1
    var result  = 0
    repeat(appleCnt){
        val applePos = readLine()?.toInt() ?: return
        if (applePos < currentPos) {
            result += currentPos - applePos
            currentPos = applePos
        } else if (applePos > (currentPos + m - 1)) {
            result += applePos - (currentPos + m - 1)
            currentPos = applePos - m + 1
        }
    }

    println(result)

}