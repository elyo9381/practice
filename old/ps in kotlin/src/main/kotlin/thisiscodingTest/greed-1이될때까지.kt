package thisiscodingTest

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

/**
 * N이 K의 배수인지를 확인한다.
 * 이를 통해서 우리는 N배의 수를 구할수 있다.
 * 주어진 조건에서 N이 K로 나눠지면 +1
 * 그리고 N에서 1을 빼면 +1이라고 조건을 주었다.
 *
 * N이 K로 나눠지면 +1인것이고 이를 통해서 생겨난 N을 다시 계산해야한다.
 *
 */

fun main(args : Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){

    val st   = StringTokenizer(readLine())

    var N = st.nextToken().toInt()
    var K = st.nextToken().toInt()

    var ret = 0
    while (N >= K) {
        val target = (N / K) * K
        ret += (N - target)
        N = target

        ret +=1
        N/=K
    }

    ret += (N-1)
    println(ret)
}
