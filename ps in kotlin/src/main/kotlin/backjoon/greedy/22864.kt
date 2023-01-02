package backjoon.greedy

import kotlin.math.*


/**
 *
 */
fun main() {
    val (a,b,c,m) = readLine()?.split(" ")?.map { it.toInt() } ?: return

    var stress = 0
    var result = 0

    repeat(24){
        if( stress + a <= m ) { result += b; stress += a }
        else stress = max( stress - c, 0)
    }
    println(result)

}


