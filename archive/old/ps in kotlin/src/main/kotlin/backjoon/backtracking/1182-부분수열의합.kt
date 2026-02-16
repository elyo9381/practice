package backjoon.backtracking

import java.io.*
import java.util.*

fun main(){
    `1182-부분수열의합`().main()
}

class `1182-부분수열의합` {


    private var sb = StringBuilder()
    private var N = 0
    private var S = 0
    private var result = 0
    private var nums  = emptyArray<Int>().toIntArray()

    fun input(){
        val scan = FastReader()
        N = scan.nextInt()
        S = scan.nextInt()

        nums = IntArray(N){0}
        for( i in 0 until N){
            nums[i] = scan.nextInt()
        }
    }

    fun recursion(k: Int, sum : Int ) {
        if(k == N){
            if(sum == S) result++
        } else {
            recursion(k+1,sum+nums[k] )
            recursion(k+1,sum)
        }
    }

    fun main(){
        input()
        recursion(0,0)
        if(S == 0 ) result--
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