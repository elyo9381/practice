package backjoon.greedy

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.StringTokenizer

class `2720` {
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val st = StringTokenizer(readLine())
    val t = st.nextToken().toInt()
    val checkList = arrayOf(25, 10, 5, 1)

    val sb = StringBuilder()
    repeat(t){
        var num = StringTokenizer(readLine()).nextToken().toInt()
        checkList.map {
            val ret = num / it
            num = num % it
            sb.append(ret)
            sb.append(" ")
        }
        sb.append("\n")
    }

    println(sb)
}