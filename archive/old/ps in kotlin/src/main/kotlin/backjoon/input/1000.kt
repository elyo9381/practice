class `1000` {

    fun main(){

        var input: String? = readLine()
        println(
            input
                ?.split(" ")
                ?.map { it.toInt() }
                ?.sumBy { it }
        )
    }
}