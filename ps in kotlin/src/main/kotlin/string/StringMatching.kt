package string

import java.io.BufferedReader
import java.io.InputStreamReader

/**
 * 방법 1 KMP
 * 방법 2 롤링 해쉬
 * 리트코드 28, 796
 */
class StringMatching {
}


fun main()= with(BufferedReader(InputStreamReader(System.`in`))){

    val str = "aaaakaaaab"
    val target = "aaaab"

    val hashCode = target.hashCode()

}