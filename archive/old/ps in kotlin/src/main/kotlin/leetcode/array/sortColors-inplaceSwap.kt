package nocode.array


/**
 *  배열에 0,1,2 가 존재할때
 *  o(n)으로 시간 o(1)의 시간으로 처리해라
 *  -> inplaceSwap
 *
 *  카운팅 솔트하면 n,n 의 시공간 복잡도 이다.
 */
fun main() {

    var nums = arrayOf(1, 0, 2, 2, 0, 1, 2, 1, 0)

    inplaceSwap(nums).forEach(::print)
}

fun inplaceSwap(nums: Array<Int>): Array<Int> {
    var idx0 = 0
    var idx2 = nums.size-1
    var i = 0
    while(i <= idx2){

        if(nums[i] == 0){
            nums.swap(i, idx0)
//            nums[i] = nums[idx0].also { nums[idx0] = nums[i] }
            idx0++
            i++
        } else if(nums[i] == 2){
            nums.swap(i, idx2)
//            nums[i] = nums[idx2].also { nums[idx2] = nums[i] }
            idx2--
        } else {
            i++
        }
    }
    return nums
}
