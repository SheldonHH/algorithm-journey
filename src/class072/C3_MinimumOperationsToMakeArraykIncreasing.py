def compute(n, m, items):
    dp = [0] * (n + 1)
    # Organize items into main items and their attachments
    main_items = {}
    attachments = {}

    for item in items:
        v, p, q = item
        if q == 0:
            main_items[v * p] = (v, p)  # key is value to sort later
        else:
            if q in attachments:
                attachments[q].append((v, p))
            else:
                attachments[q] = [(v, p)]

    # Process each main item and its attachments
    for value, (v, p) in sorted(main_items.items(), reverse=True):
        # Traverse the dp array in reverse to prevent multiple usage of the same item
        for j in range(n, v - 1, -1):
            # Option 1: Take only the main item
            dp[j] = max(dp[j], dp[j - v] + v * p)
            # Process attachments if any
            if value in attachments:
                for i, (av, ap) in enumerate(attachments[value]):
                    if j >= v + av:
                        # Option 2: Take the main item and one attachment
                        dp[j] = max(dp[j], dp[j - v - av] + v * p + av * ap)
                    # Check for a second attachment
                    if len(attachments[value]) > 1 and i == 0:
                        av2, ap2 = attachments[value][1]
                        if j >= v + av + av2:
                            # Option 3: Take the main item and two attachments
                            dp[j] = max(dp[j], dp[j - v - av - av2] + v * p + av * ap + av2 * ap2)

    return dp[n]

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Total budget
    m = int(data[1])  # Number of items
    items = []

    index = 2
    for _ in range(m):
        v = int(data[index])
        p = int(data[index + 1])
        q = int(data[index + 2])
        index += 3
        items.append((v, p, q))

    print(compute(n, m, items))

if __name__ == "__main__":
    main()
