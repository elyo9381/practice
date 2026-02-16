package nocode.array


/**
 * 바이너리 서치
 * 리트코드 704번
 *
 */
fun main() {

    val arrayOf = arrayOf(1, 2,3,4,5,6,7,8,9,10)
    val target = 6

    val i = lower_bound(arrayOf,0, arrayOf.size, target)
    println("$target 은 $i 번째 보다 크거나 같습니다.")

}
