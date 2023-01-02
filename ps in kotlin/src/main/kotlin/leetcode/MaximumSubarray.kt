package leetcode

class MaximumSubarray {
}

fun main() {


    val nums = intArrayOf(1, 2, 3, 1)

    val map = nums.groupBy { it }

    println(map.values.any { it.size  > 1})


}