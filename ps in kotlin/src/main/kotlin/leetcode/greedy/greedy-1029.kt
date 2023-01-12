package leetcode.greedy


fun meetingRooms(costs: Array<IntArray>): Int {

    costs.sortByDescending { it.last() - it.first() }

    var costsCount = costs.size
    var halfCnt = costs.size/2
    
    var minCost : Int = 0
    minCost = (0 until halfCnt).sumOf { costs[it][0] }
    minCost = (halfCnt until costsCount).sumOf { costs[it][1] }

    return minCost
}


fun main(){

    val inputList = arrayOf(
        intArrayOf(1, 2),
        intArrayOf(100, 200),
        intArrayOf(30, 10),
        intArrayOf(10, 100),
        intArrayOf(1, 1),
        intArrayOf(100, 100)
    )

    println(meetingRooms(inputList))


}