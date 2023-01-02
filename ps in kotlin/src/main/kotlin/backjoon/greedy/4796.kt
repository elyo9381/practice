package backjoon.greedy
fun main() {
    var index = 0
    while (true) {
        index++
        val (l,p,v) = readLine()?.split(" ")?.map { it.toInt() } ?: return
        if (p ==0 && l ==0 && v == 0) return
        val useDay = (v / p) * l
        val remindUseDay = v % p
        val possibleUseDay = if( remindUseDay >= l ) l else remindUseDay
        println("Case $index: ${useDay + possibleUseDay} ")
    }
}