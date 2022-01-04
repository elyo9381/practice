import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

class `11021` {

    var input_1: String? = null
    var input_2: String? = null

    fun main(args: Array<String>) {

        var totalCnt = readLine()?.toInt() ?: println("totalCnt not Int")

        (1..totalCnt as Int).mapIndexed { index, i ->  println("Case #${index+1}: ${readLine()?.split(" ")?.sumOf { it.toInt() }}") }
    }
    fun with_java_buffer() {
        val br = BufferedReader(InputStreamReader(System.`in`))
        val bw = BufferedWriter(OutputStreamWriter(System.out))

        var s : String?

        while (true) {
            val line = br.readLine()
            if (line == null || line.equals("")) break
            val st = StringTokenizer(line)
            val a = st.nextToken().toInt()
            val b = st.nextToken().toInt()
            bw.write("${a + b} \n")
        }
        bw.flush()
    }
}

