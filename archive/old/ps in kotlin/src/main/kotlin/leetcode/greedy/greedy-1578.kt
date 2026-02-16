package leetcode.greedy


fun minDeleteCost( str : String, costs : IntArray): Int {

    var maxCost = 0
    var result = 0
    var lastChar : String = ""

    costs.forEachIndexed { idx , cost ->
        val findChar = str[idx].toString()

        if( findChar != lastChar ){
            lastChar = findChar
            maxCost = cost
        }else {
            if(cost <= maxCost){
                result+=cost
            } else {
                result += maxCost
                maxCost = cost
            }
        }
    }
    return result

}
fun main(){

    val str = "bbbaaac"
    val cost = intArrayOf(3, 1, 2, 1, 5, 3, 2)

    println(minDeleteCost(str, cost))

}