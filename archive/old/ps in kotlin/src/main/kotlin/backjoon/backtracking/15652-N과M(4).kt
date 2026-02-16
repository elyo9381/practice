package backjoon.backtracking

import java.io.*
import java.util.*

fun main(){
    `15652-N과M(4)`().main()
}

class `15652-N과M(4)` {

    // 중복 조합

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

    fun rec_func(k: Int) {
        if (k == M + 1) {
            for (i in 1..M) {
                sb.append(selected[i]).append(' ')
            }
            sb.append('\n')
        } else {
            var start = selected[k-1]
            if(start == 0) start = 1
            for (cand in start..N) {
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