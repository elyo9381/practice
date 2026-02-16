package backjoon.greedy

import kotlin.math.min

fun main() {

    val inputStr = readLine() ?: return

    var zeroIndex = 0
    var oneIndex = 0
    var previous = 0

    if(inputStr[0] == '1') oneIndex++ else zeroIndex++
    (1 until inputStr.length).forEach {
        if( inputStr[previous] != inputStr[it] ){
            previous = it
            if(inputStr[it] == '1') oneIndex++ else zeroIndex++
        }
    }

//    println(if( oneIndex < zeroIndex) oneIndex else zeroIndex)

    println(   (5..19).sum())

}