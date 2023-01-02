package backjoon.greedy

/**
 * 이게 그리디인 이유는 ??
 * 5,6 을 결국 하나의 5 혹은 6으로 치환하여 최솟값, 최대값을 구하여야 한다.
 * 5 -> 6 으로 ,6 -> 5 로 가야하는거이다.
 */
fun main() {
    val str = readLine()
    val max = str?.replace("5", "6")?.split(" ")?.sumOf { it.toInt() }
    val min = str?.replace("6", "5")?.split(" ")?.sumOf { it.toInt() }
    println( "$min $max")
}


/** 초기 구현 버전
 * val left = st.nextToken()
val right = st.nextToken()


val split = left.split("")
val changList = arrayListOf(5,6)

val calculateLeftList = changList.map { changData ->
val map = left.split("").filter { it.isNotBlank() }.map {
var digitToInt = it.toInt()

if (digitToInt == 5 || digitToInt == 6) {
digitToInt = changData
}
digitToInt.toString()
}.joinToString("")
map.toInt()
}

val calculateRightList = changList.map { changData ->
val map = right.split("").filter { it.isNotBlank() }.map {
var digitToInt = it.toInt()

if (digitToInt == 5 || digitToInt == 6) {
digitToInt = changData
}
digitToInt.toString()
}.joinToString("")
map.toInt()
}

val min = calculateLeftList.minOf { it } + calculateRightList.minOf { it }
val max = calculateLeftList.maxOf { it } + calculateRightList.maxOf { it }
print( "$min $max" )
 */