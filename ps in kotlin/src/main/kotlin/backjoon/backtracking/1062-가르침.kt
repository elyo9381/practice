package backjoon.backtracking

import java.io.*
import java.lang.Integer.max
import java.util.*


/**
 * 조합을 구하는데 c(n,r) 에서 N이 커지면 구해야할 수가 많아진다.
 * 특히 완탐에서는 그러므로 불필요한 부분은 제거 하는 구현이 필요하다.
 */
fun main(){
    `1062-가르침`().main()
}

class `1062-가르침` {


    private var sb = StringBuilder()
    private var N = 0
    private var M = 0
    private var result = 0
    private var word = mutableListOf<String>()
    private var visited = BooleanArray(26) { false }


    fun input(){
        val scan = FastReader()
        N = scan.nextInt()
        M = scan.nextInt()

        for( i in 0 until N){
            val str = scan.next()
            str.replace("anta","")
            str.replace("tica","")
            word.add(str)
        }
    }

    fun recursion(alphabet: Int, cnt : Int) {
        if( cnt == M-5 ){
            var count  = 0
            (0 until N).forEach { i ->
                var check  = true
                (0 until word[i].length).forEach jloop@ { j ->
                    if(!visited[word[i][j] - 'a']){
                        check = false
                        return@jloop
                    }
                }
                if(check) count++
            }
            result = max(result,count)
            return
        } else {
            for (cand in alphabet..25) {
                if(visited[cand]) continue
                visited[cand] = true
                recursion(cand, cnt+1)
                visited[cand] = false
            }
        }
    }



    fun main(){
        input()


        if(M < 5) { //a c i n t의 개수가 5개이므로
            println("0");
            return;
        } else if(M == 26) { //모든 알파벳을 다 읽을 수 있다.
            println(N);
            return;
        }

        // 기본적인 알파벳이 적용되었다고 생각
        "antic".toByteArray().forEach {
            visited[it % 'a'.code] = true
        }

        recursion(0 ,0)
        println(result)

    }

    class FastReader {
        var br: BufferedReader
        var st: StringTokenizer? = null

        constructor() {
            br = BufferedReader(InputStreamReader(System.`in`))
        }

        constructor(s: String?) {
            br = BufferedReader(FileReader(File(s)))
        }

        operator fun next(): String {
            while (st == null || !st!!.hasMoreElements()) {
                try {
                    st = StringTokenizer(br.readLine())
                } catch (e: IOException) {
                    e.printStackTrace()
                }
            }
            return st!!.nextToken()
        }

        fun nextInt(): Int {
            return next().toInt()
        }

        fun nextLong(): Long {
            return next().toLong()
        }

        fun nextDouble(): Double {
            return next().toDouble()
        }

        fun nextLine(): String {
            var str = ""
            try {
                str = br.readLine()
            } catch (e: IOException) {
                e.printStackTrace()
            }
            return str
        }
    }

}