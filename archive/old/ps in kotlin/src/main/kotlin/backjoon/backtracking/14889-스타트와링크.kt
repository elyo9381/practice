package backjoon.backtracking

import java.io.*
import java.util.*
import kotlin.math.abs
import kotlin.math.min
import kotlin.system.exitProcess

fun main(){
    `14889-스타트와링크`().main()
}

class `14889-스타트와링크` {


    private var sb = StringBuilder()
    private var N = 0
    private var result = Int.MAX_VALUE
    private var map = emptyArray<IntArray> ()
    var selected = emptyArray<Int>().toIntArray()
    var visitied = emptyArray<Int>().toIntArray()

    fun input(){
        val scan =  FastReader()
        N = scan.nextInt()

        map = Array(N+1) { IntArray(N+1) { 0 } }

        for ( i in 1..N){
            for (j in 1..N){
                map[i][j] = scan.nextInt()
            }
        }
        selected = IntArray(N+1 ) { 0 }
        visitied = IntArray(N+1 ) { 0 }
    }

    fun recursion(index: Int, count : Int ) {
        if (count == N/2 ) {
            var start = 0
            var link = 0

            for ( i in 1 until  N){
                for( j in i+1 ..  N){
                    if( selected[i] != 0 && selected[j] != 0) {
                        start += map[i][j]
                        start += map[j][i]
                    } else if (selected[i] == 0 && selected[j] == 0 ) {
                        link += map[i][j]
                        link += map[j][i]
                    }
                }
            }
            val abs = abs(start - link)

            if( abs == 0 ){
                println(abs)
                exitProcess(0)
            }
            result = min(abs, result)


            for (i in 1..N) {
                sb.append(visitied[i]).append(' ')
            }
            sb.append('\n')

        } else {
            for (cand in selected[index-1]+1..N) {
                selected[index] = cand
                visitied[cand] = 1
                recursion(index + 1, count +1)
                selected[index] = 0
                visitied[cand] = 0
            }
        }

    }

    fun main(){
        input()
        recursion(1,0)
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