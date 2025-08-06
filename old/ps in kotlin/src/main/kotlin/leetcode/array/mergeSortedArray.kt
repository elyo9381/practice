package nocode.array

import java.util.*


/**
 * leet code 56
 *
 */
fun main() {

    val array2D = arrayOf(
        arrayOf(1, 3),
        arrayOf(8, 10),
        arrayOf(2, 6),
        arrayOf(15, 18)
    )

    val array1= Array(3) { Array(3) { 3 } }

    array1

//    mergeIntevals(array2D)

}

fun merge(intervals: Array<IntArray>): Array<IntArray>? {
    Arrays.sort(intervals) { a, b -> Integer.compare(a[0], b[0]) }
    val merged = LinkedList<IntArray>()
    for (interval in intervals) {
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, simply append it.
        if (merged.isEmpty() || merged.last[1] < interval[0]) {
            merged.add(interval)
        } else {
            merged.last[1] = Math.max(merged.last[1], interval[1])
        }
    }
    return merged.toTypedArray()
}

//fun mergeIntevals(array2D: Array<Array<Int>>) {
//    array2D.sortWith( compareBy { it.first() })
//
//    val merged = LinkedList<Array>()
//
//    array2D.forEach { _ ->
//        if(merged.isEmpty() || (merged.last[1]  array2D[0]))
//    }
//
//}
