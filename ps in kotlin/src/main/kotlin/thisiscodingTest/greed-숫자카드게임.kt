package thisiscodingTest

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


fun main(args : Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){

    val st = StringTokenizer(readLine())

    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()

    val array = Array(n) { IntArray(m) }

    println(array.indices.map { i ->
        val st2 = StringTokenizer(readLine())
        array[i].indices.map { j ->
            array[i][j] = st2.nextToken().toInt()
            array[i][j]
        }.minOf { it }
    }.maxOf { it })
}