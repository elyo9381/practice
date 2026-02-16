package nocode.array


/**
 * 기본 아이디어
 * 두개의 인덱스를 놓는다.
 * 그리고 0이 아닌 인덱스
 * 0인 인덱스를 지명하고 이둘을 스왑한다.
 *
 */
fun main() {

    val nums1 = arrayOf(5,0,4,0,2,3)
    val nums2 = arrayOf(1,3,0,0,0,4,0,5)

    moveZeroes1(nums1).forEach(::print)
    println()
    moveZeroes2(nums2).forEach (::print )

}

fun moveZeroes2(nums2: Array<Int>): Array<Int> {
    var wIdx = 0
    nums2.forEach {
        if(nums2[it] != 0){
            nums2[wIdx] = nums2[it]
            wIdx++
        }
    }
    (wIdx until nums2.size).forEach { nums2[it] = 0 }
    return nums2
}

fun moveZeroes1(nums: Array<Int>): Array<Int> {
    var wIdx = 0;
    nums.forEachIndexed { index, value ->
        if( nums[index] != 0 ){
            nums[index] = nums[wIdx].apply { nums[wIdx] = nums[index] }
            wIdx++
        }
    }
    return nums
}



fun <T> Array<T>.swap(i: Int, j: Int) {
//    with(this[i]) {
//        this@swap[i] = this@swap[j]
//        this@swap[j] = this
//    }
    this[i] = this[j].also { this[j] = this[i] }
}