package backjoon.backtracking

import java.io.*
import java.lang.Math.*
import java.util.*
import kotlin.system.exitProcess


fun main(){
    `10819-차이를최대로`().main()
}

class `10819-차이를최대로` {

    private var sb = StringBuilder()
    private  var N = 0
    private  var result = Int.MIN_VALUE
    private var scan = FastReader()
    private var selected = emptyArray<Int>().toIntArray()
    private var list = emptyArray<Int>().toIntArray()
    private var used = emptyArray<Boolean>()

    fun input(){
        N = scan.nextInt()

        list = IntArray(N) { 0 }

        (0 until N).forEach {
            list[it] = scan.nextInt()
        }

        selected = IntArray(N){0}
        used = Array(N){false}
    }


    fun recursion( k : Int ) {
        if( k == N ) {
            val sum = (0..N - 2)
                .map { idx -> abs(list[selected[idx]] - list[selected[idx + 1]]) }
                .sumOf { it }
            result = max(result,sum)

        } else {
            for (cand in 0 until N){
                if(used[cand]) continue
                selected[k] = cand
                used[cand] = true
                recursion(k+1)
                selected[k] = 0
                used[cand] = false
            }
        }

    }

    /**
     * 순열 , 최댓값
     */
    fun main(){
        input()
        recursion(0)
        println(result)
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