package backjoon.backtracking

import java.io.*
import java.util.*

fun main(){
    `15649-N과M(1)`().main()
}

class `15651-N과M(3)` {
    // 중복 순열

    private var sb = StringBuilder()
    private var N = 0
    private var M = 0
    lateinit var selected: IntArray

    fun input(){
        val scan =  FastReader()
        N = scan.nextInt()
        M = scan.nextInt()
        selected = IntArray(M + 1)
    }

    fun input2(){
        val scan = FastReader()
        N = scan.nextInt()
        M = scan.nextInt()
        selected = IntArray(M+1)
    }

    fun recursion(k : Int) {
        if(k == M+1) {
            for( i in 1..M){
                sb.append(selected[i]).append(' ')
            }
            sb.append('\n')
        }

        for (cand in 1..N){
            selected[k] = cand
            recursion(k+1)
            selected[k] = 0
        }
    }


    fun rec_func(k: Int) {
        if (k == M + 1) {
            for (i in 1..M) {
                sb.append(selected[i]).append(' ')
            }
            sb.append('\n')
        } else {
            for (cand in 1..N) {
                selected[k] = cand
                rec_func(k + 1)
                selected[k] = 0
            }
        }
    }
    fun main(){
        input()
        rec_func(1)

        println(sb.toString())
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