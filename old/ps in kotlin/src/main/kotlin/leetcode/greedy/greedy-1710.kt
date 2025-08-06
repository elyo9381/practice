package leetcode.greedy

fun maximumUnits(boxTypes: Array<IntArray>, truckSize: Int): Int {

    boxTypes.sortByDescending { it.last() }

    var totalUnit = 0
    var leftBoxes = truckSize
    boxTypes.forEach { (boxCount, unit) ->
        if(boxCount <= leftBoxes){
            totalUnit += (unit * boxCount)
            leftBoxes -= boxCount
        } else {
            totalUnit += (unit * leftBoxes)
            leftBoxes -= leftBoxes
        }

        if(leftBoxes == 0) return totalUnit
    }
    return totalUnit
}
fun main(){
    val boxTypes = arrayOf(intArrayOf(3, 1), intArrayOf(2, 2), intArrayOf(1, 4), intArrayOf(2, 3))

    println(maximumUnits(boxTypes,4))
}