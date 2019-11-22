def make_tree():
    default = dict(value=-1)
    return dict(left=default, right=default, value=-1)


def traverse(tree):
    if tree['value'] == -1:
        return 0
    if tree['left']['value'] == -1 == tree['right']['value']:
        return 1

    count = 0
    if (tree['value'] == tree['left']['value'] == tree['right']['value']
        and tree['left'] == tree['right']):
        count = 1

    return count + traverse(tree['left']) + traverse(tree['right'])


def main():
    tree = make_tree()

    n = int(input().split()[0])
    if (n == -1):
        print(-1)
        return

    tree['value'] = int(input().split()[0])
    last_level = [tree]
    for _ in range(n):
        nodes = list(map(int, input().split()))
        curr_level = []
        j = 0
        for node in last_level:
            if node['value'] == -1:
                continue
            left = make_tree()
            right = make_tree()
            left['value'] = nodes[j]
            right['value'] = nodes[j + 1]

            node['left'] = left
            node['right'] = right

            curr_level.append(left)
            curr_level.append(right)
            j += 2

        last_level = curr_level

    print(traverse(tree))


main()
