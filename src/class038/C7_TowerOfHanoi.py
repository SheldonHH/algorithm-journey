class Code07_TowerOfHanoi:
    @staticmethod
    def hanoi(n):
        """打印n层汉诺塔问题的最优移动轨迹"""
        if n > 0:
            Code07_TowerOfHanoi.f(n, '左', '右', '中')

    @staticmethod
    def f(i, from_pos, to, other):
        if i == 1:
            print(f'移动圆盘 1 从 {from_pos} 到 {to}')
        else:
            Code07_TowerOfHanoi.f(i - 1, from_pos, other, to)
            print(f'移动圆盘 {i} 从 {from_pos} 到 {to}')
            Code07_TowerOfHanoi.f(i - 1, other, to, from_pos)

if __name__ == '__main__':
    n = 3
    Code07_TowerOfHanoi.hanoi(n)
