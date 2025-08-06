import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

class `10953` {

    var input_1: String? = null
    var input_2: String? = null

    fun main(args: Array<String>) {

        val total = readLine()?.toInt()
        while (total!! > 0) {
            var readLine = readLine()
            if(readLine.isNullOrBlank()) break;
            println(readLine?.split(",")?.map { it.toInt() }?.sum())
        }
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

