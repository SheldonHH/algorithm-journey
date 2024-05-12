def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    
    while index < len(data):
        n = int(data[index])
        x = int(data[index + 1])
        index += 2
        
        m = 1
        cost = [0] * MAXN
        val = [0] * MAXN
        ans = 0
        
        for i in range(n):
            pre = int(data[index])
            cur = int(data[index + 1])
            happy = int(data[index + 2])
            index += 3
            
            well = pre - cur - cur
            # 如下是一件"一定要买的商品"
            # 预算 = 100，商品原价 = 10，打折后 = 3
            # 那么好处(well) = (10 - 3) - 3 = 4
            # 所以，可以认为这件商品把预算增加到了104！一定要买！
            # 如下是一件"需要考虑的商品"
            # 预算 = 104，商品原价 = 10，打折后 = 8
            # 那么好处(well) = (10 - 8) - 8 = -6
            # 所以，可以认为这件商品就花掉6元！
            if well >= 0:
                x += well
                ans += happy
            else:
                cost[m] = -well
                val[m] = happy
                m += 1
        
        ans += compute(cost, val, x, m)
        print(ans)

def compute(cost, val, x, m):
    dp = [0] * (x + 1)
    for i in range(1, m):
        for j in range(x, cost[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i])
    return dp[x]

if __name__ == "__main__":
    main()
