package backjoon.backtracking

import java.io.*
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main(){
    `14888-연산자 끼워넣기`().main()
}

class `14888-연산자 끼워넣기` {

    private var sb = StringBuilder()
    private var N = 0
    private var max = Int.MIN_VALUE
    private var min = Int.MAX_VALUE
    lateinit var nums: IntArray
    var operator = IntArray(5) { 0 }

    fun input(){
        val scan =  FastReader()
        N = scan.nextInt()
        nums = IntArray(N+1)
        for(i in 1..N){ nums[i] = scan.nextInt() }
        for(i in 1..4){ operator[i] = scan.nextInt() }
    }

    fun calculate(value : Int, operator : Int, value2 : Int ): Int {
        return when(operator){
            1 -> { value + value2 }
            2-> { value - value2 }
            3-> { value * value2 }
            else -> { value / value2 }
        }
    }

    /**
     * n개의 숫자들과 와 n-1의 연산자를 순열로 나열하는 문제이다.
     * 순열로 사영하려면 후보자리스트를 순서대로 돌면 되는데
     * 해당 문제에서는 순서자가 주어졌으로 특정 갯수 이상이라는 조건으로 후보자 리스트를 체크한다.
     *
     * 해당문제를 더욱 더 최적화 하는 방법으로는 뭐가 았을까 ?
     *
     */
    fun rec_func(k: Int, value: Int) {
        if ( k == N ) {
            max = max(max,value)
            min = min(min,value)
        } else {
            (1..4).forEach { candidate ->
                if(operator[candidate] >= 1){
                    operator[candidate]--
                    rec_func(k+1, calculate(value,candidate,nums[k+1]))
                    operator[candidate]++
                }
            }
        }
    }

    fun main(){
        input()
        rec_func(1,nums[1])
        sb.append(max).append("\n").append(min)
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