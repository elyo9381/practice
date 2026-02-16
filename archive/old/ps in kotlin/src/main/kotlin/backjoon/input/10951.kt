class `10951` {

    var input_1 : String? = null
    var input_2 : String? = null

    fun main(args: Array<String>) {

        while ( true ){
            val readLine = readLine()
            if( readLine.isNullOrBlank() ) break
            println(readLine.split(" ").map { it.toInt() }.sumOf { it })
        }
    }
}
