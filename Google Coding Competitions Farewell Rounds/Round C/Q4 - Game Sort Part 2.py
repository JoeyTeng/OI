from typing import Dict, List


def p_gt_3(p: int, string: str) -> List[str]:
    pos = -1
    for i, (pre, nex) in enumerate(zip(string, string[1:])):
        if pre > nex:
            pos = i
            break

    if pos < 0:
        return []

    result: List[str] = []
    for i in range(min(p - 1, pos)):
        result.append(string[i:i + 1])

    result.append(string[pos:pos + 1])
    result.append(string[pos + 1:pos + 2])

    remaining_chars = len(string) - (pos + 2)
    remaining_parts = p - len(result)
    for i in range(remaining_parts - 1):
        result.append(string[pos + 2 + i:pos + 2 + i + 1])
    result.append(string[pos + 2 + remaining_parts - 1:])

    return result


def check_two(pre: List[int], nex: List[int]) -> bool:
    """If pre has a rearrangement less than or equal to nex"""
    for i in range(26):
        if pre[i] > 0 and (sum(nex[i + 1:]) > 0 or pre[i] < nex[i]):
            return True
    if pre == nex:
        return True

    return False


def p_eq_3(string: str) -> List[str]:
    left: List[int] = [0 for _ in range(26)]
    middle: List[int] = [0 for _ in range(26)]
    right: List[int] = [0 for _ in range(26)]

    found = False
    for i in range(len(string) - 1):
        left[ord(string[i]) - ord('A')] += 1

        for j in range(26):
            middle[j] = 0
            right[j] = 0
        middle[ord(string[i + 1]) - ord('A')] += 1

        for ch in string[i + 2:]:
            right[ord(ch) - ord('A')] += 1

        if not check_two(left, middle):
            found = True
            break

        for j in range(i + 2, len(string)):
            if not check_two(middle, right):
                found = True
                break
            idx = ord(string[j]) - ord('A')
            middle[idx] += 1
            right[idx] -= 1

        if found:
            break

    if not found:
        return []

    return [
        string[:sum(left)],
        string[sum(left):sum(left) + sum(middle)],
        string[sum(left) + sum(middle):],
    ]


def p_eq_2(string: str) -> List[str]:
    pre: List[int] = [0 for _ in range(26)]
    nex: List[int] = [0 for _ in range(26)]

    for ch in string:
        nex[ord(ch) - ord('A')] += 1

    found = False
    for ch in string:
        idx = ord(ch) - ord('A')
        pre[idx] += 1
        nex[idx] -= 1

        if not check_two(pre, nex):
            found = True
            break

    if not found:
        return []

    return [string[:sum(pre)], string[sum(pre):]]


T = int(input().strip())
counts: Dict[int, int] = dict(((i, 0) for i in range(ord('A'), ord('Z') + 1)))
for t in range(1, T + 1):
    inputs = input().strip().split(' ')
    P, string = int(inputs[0]), inputs[1]

    split: List[str]
    if P > 3:
        split = p_gt_3(P, string)
    elif P == 2:
        split = p_eq_2(string)
    else:
        split = p_eq_3(string)

    if split:
        print(f"Case #{t}: POSSIBLE")
        print(" ".join(split))
    else:
        print(f"Case #{t}: IMPOSSIBLE")
