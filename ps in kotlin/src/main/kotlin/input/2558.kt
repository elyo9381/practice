class `2558` {

    var input_1 : String? = null
    var input_2 : String? = null

    fun main(args: Array<String>) {
        println(
            readLine()?.toInt()?.let { readLine()?.toInt()?.plus(it) }
        )
    }
    fun roopstyle(){
        print((1..2).map { readLine()?.toInt() }.sumOf { it ?: 0 })
    }
}
