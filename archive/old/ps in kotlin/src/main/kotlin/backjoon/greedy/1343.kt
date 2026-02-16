package backjoon.greedy

/**
 * 구현 열심히 했는데
 * 함수로 처리 가능 했었네... 하 젠장
 */
fun main() {

    val input = readLine()?.trim() ?: return

    val replace = input.replace("XXXX", "AAAA").replace("XX","BB")
    println(if(replace.any { it == 'X' }) -1 else replace)

//    var cnt = 0;
//    val sb = StringBuilder()
//
//    input.forEach {  element ->
//        if( element == '.' ){
//            if(cnt % 2 == 1 ) {println(-1); return}
//            val isPossibleAcover = (cnt % 4)
//            val ACoverCnt = cnt / 4
//            repeat(ACoverCnt){
//                sb.append("AAAA")
//            }
//
//            if(isPossibleAcover == 2){
//                sb.append("BB")
//            }
//            sb.append(".")
//            cnt = 0
//        }else {
//            cnt++
//        }
//    }
//    if(cnt % 2 == 1 ) {println(-1); return}
//
//    val isPossibleAcover = (cnt % 4)
//    val ACoverCnt = cnt / 4
//    repeat(ACoverCnt){
//        sb.append("AAAA")
//    }
//
//    if(isPossibleAcover == 2){
//        sb.append("BB")
//    }

//    println(sb)
}