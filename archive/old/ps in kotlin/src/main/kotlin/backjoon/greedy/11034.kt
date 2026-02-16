package backjoon.greedy

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


fun main() = with(BufferedReader(InputStreamReader(System.`in`))){


    var str: String? = null
    while ((readLine().also { str = it }  ) != null) {
        val st = StringTokenizer(str)
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        val c = st.nextToken().toInt()
        val listOf = listOf(a,b,c)
        println(listOf.zipWithNext().map {
            it.second - it.first
        }.maxOf { it} - 1)
    }
}