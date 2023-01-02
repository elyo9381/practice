package backjoon.greedy


fun main() {

    var refundFee = 1000 - (readLine()?.trim()?.toInt() ?: return )
    val checkNums = arrayOf(500, 100, 50, 10, 5, 1)

    var cnt = 0
    checkNums.forEach {
            cnt += refundFee / it
            refundFee %= it
        }
    println(cnt)

}