package backjoon.backtracking

import java.io.*
import java.lang.Math.*
import java.util.*





fun main(){
    `2529-부등호`().main()
}

class `2529-부등호` {

    /**
     * permutation을 구하고 마지막 검증을 진행하였다.
     * 더 최적화시키는방법 -> permutation을 구할때 조건을 주어서 최적화시켜라
     */

    private var sb = StringBuilder()
    private  var N = 0
    private var scan = FastReader()
    private var list = emptyArray<String>()
    private var result = mutableListOf<String>()
    private var selected = emptyArray<Int>().toIntArray()
    private var used = emptyArray<Boolean>()

    fun input(){
        N = scan.nextInt()
        list = Array(N){""}
        result = mutableListOf()
        (0 until N).forEach {
            list[it] = scan.next()
        }
        selected = IntArray(N+1){0}
        used = Array(10){false}
    }

    fun recur( k : Int) {
        if( k == N + 1 ){
            // 체크를 진행하면 되지
            if(isPossibleRole()) {
                result.add(selected.joinToString(""))
            }

        } else {
           for ( i in 0 until 10){
               if(!used[i]) {
                   selected[k] = i
                   used[i] = true
                   recur(k+1)
                   selected[k] = 0
                   used[i] = false
               }
           }
        }

    }

    private fun isPossibleRole(): Boolean {
        for (i in 0 until N) {
            if (list[i] == "<") {
                if (selected[i] >= selected[i + 1]) return false
            } else if (list[i] == ">") {
                if (selected[i] <= selected[i + 1]) return false
            } else {
                return false
            }
        }
        return true
    }

    fun main(){
        input()
        recur(0)
        result.sortByDescending { it }
        println(result.first())
        println(result.last())
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

///////////////////////////////////////////////////////

//val br = System.`in`.bufferedReader()
//
//fun getIntGraph() = br.readLine().split(' ').map { it.toInt() }
//fun getInt() = br.readLine().toInt()
//var minAns = Long.MAX_VALUE
//var maxAns = 0L
//var input =""
//fun permutation(result: Long, idx: Int, visited: BooleanArray){
//    if(idx==input.length){
//        minAns= minAns.coerceAtMost(result)
//        maxAns = maxAns.coerceAtLeast(result)
//        return
//    }
//    for(i in 0 .. 9){
//        if(visited[i]) continue
//        val cur = result%10
//        when(input[idx]){
//            '<'->{
//                if(cur>=i) continue
//            }
//            else->{
//                if(cur<=i) continue
//            }
//        }
//        visited[i] = true
//        permutation(result*10+i, idx+1, visited)
//        visited[i] = false
//    }
//}
//
//fun main() = with(System.out.bufferedWriter()){
//
//    val k = getInt()
//    input = br.readLine().replace(" ","")
//
//    for(i in 0 .. 9) {
//        val visited= BooleanArray(10)
//        visited[i] = true
//        permutation(i.toLong(), 0, visited)
//    }
//
//    write("${String.format("%0${k+1}d", maxAns)}\n${String.format("%0${k+1}d", minAns)}")
//
//    close()
//}