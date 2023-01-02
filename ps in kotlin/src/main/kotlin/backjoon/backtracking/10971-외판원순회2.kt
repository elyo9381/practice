package backjoon.backtracking

import java.io.*
import java.lang.Math.*
import java.util.*





fun main(){
    `10971-외판원순회2`().main()
}

class `10971-외판원순회2` {

    private var sb = StringBuilder()
    private  var N = 0
    private  var result = Int.MAX_VALUE
    private var scan = FastReader()
    private var map = emptyArray<IntArray>()
    private var selected = emptyArray<Int>().toIntArray()
    private var used = emptyArray<Boolean>()

    fun input(){

        N = scan.nextInt()
        map = Array(N){IntArray(N) {0}}

        for (i in 0 until N){
            for (j in 0 until N){
                map[i][j] = scan.nextInt()
            }
        }

        selected = IntArray(N) {0}
        used = Array(N) {false}
    }


    /**
     * DFS를 통해서 도시를 방문한다고는 생각이다.
     * 각각의 방문한 도시에서의 탐색을 진행되어야한다.
     */
    fun dfs(now : Int, sum : Int) {
        if( isAllUsed() ) {
            if(map[now][0] != 0)  {
                 result = min(result,map[now][0] + sum)
            }
            return
        } else {
            for (i in 0 until N ){
                if(!used[i] && map[now][i] != 0) {
                    used[i] = true
                    dfs(i , sum + map[now][i])
                    used[i] = false
                }
            }
        }
    }


    fun isAllUsed() : Boolean {
        return used.all { it }
    }


    /**
     * 백트래킹
     * 1.N 개의 도시를 모두 탐색해야한다.
     * 2. 안가는 도시가 존재한다.
     * 3. 사이클이 생길수 있다.
     * 4. 중복 X 순열이다.
     *
     * 위의조건을 만족하며 N이 최대 10 이므로
     * N!/(N-M)! 의 조건이여서 순열로 가능하다. 백트래킹
     */
    fun recur(depth : Int) {
        if( depth == N  ) {
            val sumOf = (0 until N-1 ).map {
                map[selected[it]][selected[it+1]]
            }.sumOf { it }

            if(map[selected[depth-1]][selected[0]] != 0)  {
                result = min(result,map[selected[depth-1]][selected[0]] + sumOf)
            }
            return
        } else {
            for (i in 0 until N ){
                if(!used[i] ) {
                    selected[depth] = i
                    used[i] = true
                    recur(depth+1 )
                    selected[depth] = 0
                    used[i] = false
                }
            }
        }
    }

    fun main(){
        input()
        used[0] = true
        dfs(0,0)
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