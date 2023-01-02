package backjoon.backtracking

import java.io.*
import java.util.*

fun main(){
    `15650-N과M(2)`().main()
}

class `15650-N과M(2)` {

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
            /**
             * 중복없이 골라야한다.
             * 그런데 오름차순이다. -> 오른차순이란것은 이전데이터보다 크다는것을 의미한다.
             * 내림차순이라면 어떻게 해야하는가. ??
             * - 큰수에서 내려가면 된다.
             * - used 함수 -> 즉 사용할 데이터의 순서를 바꾸면 된다.
             */
            for (cand in selected[k-1]+1..N) {
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