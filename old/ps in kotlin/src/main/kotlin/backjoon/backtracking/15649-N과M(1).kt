package backjoon.backtracking

import java.io.*
import java.util.*

fun main() {
    `15649-N과M(1)`().main()
}

class `15649-N과M(1)` {

    // 순열
    private var sb = StringBuilder()
    private var N = 0
    private var M = 0
    lateinit var selected: IntArray
    lateinit var used: IntArray

    fun input() {

        val scan = FastReader()
        N = scan.nextInt()
        M = scan.nextInt()
        selected = IntArray(M + 1)
        used = IntArray(N+1)
    }

    fun recursion(k: Int) {
        if (k == M + 1) {
            for (i in 1..M) {
                sb.append(selected[i]).append(' ')
            }
            sb.append('\n')
        } else {
            /**
             * 선택된 배열이 존재하고 거기에 순차적이로 등록한 candidate가 존재한다.
             * 순서대로 candiate를 넣는데
             * candidate가 뭔지 알고 넣냐 ? 특정 배열 또는 특정 값으로 존재한다.
             * 우리는 거기에 use배열을 통해서 체크를 진행할수 있을것이다.
             *
             * 이를 순열이라고 말할수있을것같다 퍼뮤테이션이다
             *
             */
//            for (cand in 1..N) {
//                if (used[cand] == 1) continue
//                selected[k] = cand; used[cand] = 1;
//                recursion(k + 1)
//                selected[k] = 0; used[cand] = 0;
//            }

            (1..N).forEach {
                if(used[it] == 1) return@forEach
                selected[k] = it
                used[it] =1;
                recursion(k+1)
                selected[k] = 0;
                used[it] = 0;
            }
        }
    }

    fun main() {
        input()
        recursion(1)

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