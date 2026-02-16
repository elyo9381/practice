package backjoon.backtracking

import java.io.*
import java.util.*
import kotlin.system.exitProcess

fun main(){
    `2580-스도쿠`().main()
}

class `2580-스도쿠` {


    private var sb = StringBuilder()
    private var map = emptyArray<IntArray> ()

    fun input(){
        val scan = FastReader()

        map = Array(9) { IntArray(9) }


        for( i in 0 until 9){
            for(j  in 0 until 9){
                map[i][j] = scan.nextInt()
            }
        }
    }

    fun possibleSudoku(row: Int, col : Int, target: Int ) : Boolean{

        for(i in 0 until 9){
            if( map[row][i] == target ) return false
        }

        for(i in 0 until 9){
            if( map[i][col] == target ) return false
        }

        val subSudokuRow = row / 3 * 3
        val subSudokuCol = col / 3 * 3

        for( i in subSudokuRow until subSudokuRow+3){
            for(j  in subSudokuCol until subSudokuCol+3){
                if( map[i][j] == target ) return false
            }
        }

        return true
    }

    fun recursion(row: Int, col : Int ) {

        if( col == 9 ){
            recursion(row+1,0)
            return;
        }

        if( row == 9 ){
            for( i in 0 until 9){
                for(j  in 0 until 9){
                    sb.append(map[i][j]).append(' ')
                }
                sb.append('\n')
            }
            println(sb.toString())
            exitProcess(0)
        }

        if( map[row][col] == 0 ){
            for(target in 1 ..  9){
                if(possibleSudoku(row,col,target)){
                    map[row][col] = target
                    recursion(row,col+1)
                }
                map[row][col] = 0
            }
            return;
        }

        recursion(row,col+1)

    }

    fun main(){
        input()
        recursion(0,0)
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