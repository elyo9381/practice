package thisiscodingTest

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*



fun main() = with(BufferedReader(InputStreamReader(System.`in`))){

    val st = StringTokenizer(readLine())

    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val k = st.nextToken().toInt()


    val inputList = mutableListOf<Int>()

    val input = StringTokenizer(readLine())
    repeat(n){ inputList += input.nextToken().toInt() }

    inputList.sortByDescending { it }
    val size = inputList.size
    val firstMax = inputList[0]
    val secondMax = inputList[1]

    var cnt = (m / (k + 1)) * k
    cnt += m % ( k+1)

    var result = 0

    result += cnt * firstMax
    result += (n-cnt) * secondMax
    println(result)
}
