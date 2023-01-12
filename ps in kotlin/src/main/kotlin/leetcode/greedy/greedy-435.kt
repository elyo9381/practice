package leetcode.greedy


fun overlappingIntervals(intervals : Array<IntArray>) : Int {

    intervals.sortBy { it.last() }

    var lastEnd = -987654321
    var intervalCnt = 0
    
    intervals.forEach { 
        var start = it.first()    
        var end = it.last()

        if( start < lastEnd) return@forEach

        if( lastEnd <= end) {
            intervalCnt++
            lastEnd = end
        }
    }
    return intervals.size - intervalCnt
}

fun main(){
    val intervals = arrayOf(
        intArrayOf(1, 2),
        intArrayOf(2, 3),
        intArrayOf(3, 4),
        intArrayOf(1, 3)
    )
    println (overlappingIntervals(intervals))
}