from typing import Dict, List, Tuple


def build_biggest(candidates: Dict[int, int]) -> List[int]:
    l: List[int] = []
    for k, v in sorted(candidates.items(), reverse=True):
        for _ in range(v):
            l.append(k)

    return l


def build_str(
    prev: List[int],
    candidates: Dict[int, int],
    total_left: int,
) -> Tuple[bool, List[int]]:
    if not prev:
        return True, build_biggest(candidates)
    if total_left <= 0:
        return False, []

    i = prev[0]
    if candidates[i] > 0:
        candidates[i] -= 1
        possible, following = build_str(
            prev[1:],
            candidates,
            total_left - 1,
        )
        candidates[i] += 1
        if possible:
            following.append(i)
            return possible, following

    first = None
    for i in range(prev[0] + 1, ord('Z') + 1):
        if candidates[i]:
            first = i
            break
    if first:
        candidates[first] -= 1
        string = build_biggest(candidates)
        string.append(first)

        return True, string

    return False, []


T = int(input().strip())
counts: Dict[int, int] = dict(((i, 0) for i in range(ord('A'), ord('Z') + 1)))
for t in range(1, T + 1):
    input()
    parts = [list(map(ord, part)) for part in input().strip().split(' ')]
    parts = list(map(sorted, parts))

    possible = True
    results = [sorted(parts[0])]
    for nex in parts[1:]:
        curr = results[-1]
        for k in counts.keys():
            counts[k] = 0

        for i in nex:
            counts[i] += 1

        _possible, string = build_str(curr, counts, len(nex))
        string = list(reversed(string))
        if _possible:
            results.append(string)
        else:
            possible = False
            break

    if possible:
        print(f"Case #{t}: POSSIBLE")
        to_print = [''.join(map(chr, part)) for part in results]
        print(' '.join(to_print))
    else:
        print(f"Case #{t}: IMPOSSIBLE")
