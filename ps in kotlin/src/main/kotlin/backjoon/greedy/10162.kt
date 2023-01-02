package backjoon.greedy

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.StringTokenizer


fun main() = with(BufferedReader(InputStreamReader(System.`in`))){

    val checkList = arrayOf(300, 60, 10)
    var num = StringTokenizer(readLine()).nextToken().toInt()

    if( num % 10 != 0 ){
        println("-1")
    } else {
        val sb = StringBuilder()
        checkList.map {
            var ret = num / it
            num = num % it
            println("$ret ")
        }
    }

    println()
}


