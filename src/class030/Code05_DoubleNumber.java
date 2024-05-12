package class030;

/**
 * 在数组中找出两种出现奇数次的数。 
 * 条件是：有两种数出现了奇数次，其他数都出现了偶数次。
 * 这个问题可以在O(N)的时间和O(1)的空间复杂度解决。
 * 测试链接 : https://leetcode.cn/problems/single-number-iii/
 */
public class Code05_DoubleNumber {

    /**
     * 返回数组中出现奇数次的两个数字
     * @param nums 输入的数组
     * @return 包含两个奇数次数字的数组
     */
    public static int[] singleNumber(int[] nums) {
        // eor1最终的结果是两种出现奇数次的数的异或结果
        int eor1 = 0;
        for (int num : nums) {
            // 通过异或整个数组，成对的数字会相互抵消（异或结果为0）
            eor1 ^= num;
        }
        
        // eor1的结果现在是两个出现奇数次数的异或，也就是a ^ b
        // a和b是不同的，所以eor1不为0
        // Brian Kernighan算法：通过eor1 & (-eor1)提取出最右的1
        // 由于a和b不同，它们在某一位上一定是不同的，这个1来自于这个不同的位
        int rightOne = eor1 & (-eor1);

        int eor2 = 0;
        for (int num : nums) {
            // 过滤出其中一组，具体是哪一组取决于这个rightOne位
            // 由于rightOne是从eor1中提取出来的，所以这个操作可以保证
            // 如果a在这一位上是1，那么所有在这一位上是1的数都会被eor2异或，
            // 而b以及其他成对的数都会被忽略
            if ((num & rightOne) == 0) { // 仅仅异或这一位上是0的数
                eor2 ^= num;
            }
        }
        // eor2现在是a和b中的一个，因为它是上面if条件筛选出的数的异或结果
        // 为了得到另一个数，我们可以用eor1 ^ eor2，因为eor1是a ^ b
        // 异或相同的数会抵消，所以eor1 ^ eor2结果是另一个数
        return new int[] { eor2, eor1 ^ eor2 };
    }

}
