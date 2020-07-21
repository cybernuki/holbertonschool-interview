#!/usr/bin/python3


def canUnlockAll(boxes):
    if not boxes:
        return False

    opened = {}
    queue = [0]

    while queue:
        boxNum = queue.pop(0)
        opened[boxNum] = 1
        for key in boxes[boxNum]:
            if key >= 0 and key < len(boxes) and not opened.get(key)\
                    and (key not in queue):
                queue.append(key)

    return True if (len(opened) == len(boxes)) else False
