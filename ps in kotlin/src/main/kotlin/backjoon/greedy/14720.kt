package backjoon.greedy

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer


fun main() = with(BufferedReader(InputStreamReader(System.`in`))){

    val N = StringTokenizer(readLine()).nextToken().toInt()
    val st2 = StringTokenizer(readLine())

    var inputList = emptyArray<Int>()
    repeat(N){ inputList += st2.nextToken().toInt() }
    var cnt = 0
    inputList.forEach {if( it == cnt % 3) cnt += 1 }
    println(cnt)
}


