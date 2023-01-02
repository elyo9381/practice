class `10950` {

    var input_1 : String? = null
    var input_2 : String? = null

    fun main(args: Array<String>) {
        var totalCnt = readLine()?.toInt() ?: println("totalCnt not Int")

        (1..totalCnt as Int).map { println(readLine()?.split(" ")?.map { it.toInt() }?.sumOf { it } ) }
    }
}
