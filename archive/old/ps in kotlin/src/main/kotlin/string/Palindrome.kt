package string

/**
 *   code 125, 680
 *
 *   문자열 회문을 검사 하는 방법
 *   1. 투포인터를 이용해서 비교하며 low < high 의 단조증가 함수 조건일땐 가능하다.
 *   2. 만약 특정 문자만 팰린드롬인지 검사해야한다면 ? 단조 증가 조건 안에서  포인터가 증가하는때 마다 팰린드롬인지 검사해야한다.
 *   3. 680 -> 하나를 제외한다면 ? 이것 2가지 경우가 존재한다. 투포인터중 왼쪽인지 , 오른쪽인지 매번 검사해야한다는것이다.
 *      이때는 재귀를 사용해서 검사하는것이 유용하다.
 */
class Palindrome {
}

fun main() {


    fun isPalidrome(s: String, i: Int, j: Int): Boolean {
        var low = i
        var high = j
        while( low < high ){
            if( s[low] != s[high]) return false
            low++
            high--
        }
        return true
    }


    fun validPalidrome (s : String ) : Boolean{

        var low = 0
        var high = s.length -1

        while (low < high ){
            if(s[low] != s[high]){
                return isPalidrome(s, low+1,high) || isPalidrome(s, low,high+1)
            }
            low++
            high--
        }
        return true
    }


    println(validPalidrome("abca"))

}



fun isPalindrome(s: String): Boolean {
    var current = 0
    var isDelete = false
    for(i in s.indices) {
        if(s[i].isLetterOrDigit()) {
            while (!s[s.length - 1 - current].isLetterOrDigit()) {
                current++
            }
            if(!s[i].equals(s[s.length - 1 - current], true)) {
                return false
            }
            current++
        }
    }
    return true
}
