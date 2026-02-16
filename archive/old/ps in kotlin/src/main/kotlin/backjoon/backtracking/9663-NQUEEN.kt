package backjoon.backtracking

import java.io.*
import java.util.*

fun main(){
    `9663-NQUEEN`().main()
}

class `9663-NQUEEN` {


    private var sb = StringBuilder()
    private var N = 0
    private var ans = 0
    lateinit var nums: IntArray
    var col = emptyArray<Int>().toIntArray()
    var maps: Array<IntArray> = emptyArray()

    fun input(){
        val scan =  FastReader()
        N = scan.nextInt()
        col = IntArray(N+1 ){ 0 }
        maps = Array(N + 1) { IntArray(N + 1) }
    }

    fun recursion(row : Int) {
        if (row == N + 1) {
            ans++
        }

        (1..N).forEach { cIndex ->
            var possible = true
            for (previousRow in 1 until row) {
                if (attackable(row, cIndex, previousRow, col[previousRow])) {
                    possible = false
                    continue
                }
            }

            if (possible) {
                col[row] = cIndex
                recursion(row + 1)
                col[row] = 0
            }

        }
    }


    private fun attackable(r1: Int, c1: Int, r2: Int, c2: Int): Boolean {
        if ( c1 == c2 ) return true
        if ( r1 - c1 == r2 - c2) return true;
        if ( r1 + c1 == r2 + c2) return true;
        return false
    }

    fun main(){
        input()
        recursion(1)
        println(ans)
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