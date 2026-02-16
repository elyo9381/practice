package backjoon.backtracking

import java.io.*
import java.util.*


/**
 * 순열, 조합으로만 보면 풀수가없다.
 * 1. 감소하는수를 만들수 있는 아이디어가 필요하다.
 * 2. 감소하는수가 없는 N의 수 구하는 방법
 *
 */
fun main(){
    `1038-감소하는수`().main()
}

class `1038-감소하는수` {

    private var sb = StringBuilder()
    private var N = 0
    private var M = 0
    private var result = 0
    private var nums = mutableListOf<Long>()


    fun input(){
        val scan = FastReader()
        N= scan.nextInt()
    }

    fun recursion(num: Long) {
        val lastNum = num % 10
        if(lastNum <= 0) {
            return
        }
        for (i in lastNum-1 downTo 0){
        nums.add(num)
            recursion(num * 10 + i)
        }
    }


    fun main(){
        input()

        if( N < 10){
            println(N)
        } else if ( N >= 1023){
            println(-1)
        }else {
            for (i in 0..9){
                recursion(i.toLong())
            }
            nums.sortBy { it }
            println(nums[N])
        }
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