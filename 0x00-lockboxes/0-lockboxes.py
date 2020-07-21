#!/usr/bin/python3


def canUnlockAll(boxes):
    hasOpen = {0: 1}

    if not boxes:
        return False

    return True if (len(hasOpen) == len(boxes)) else False


def openBox(keys, boxes, hasOpen):
    if not keys:
        return {}
    for key in keys:
        if key >= 0 and key < len(hasOpen) and not hasOpen.get(key):
            hasOpen.update({key: 1})
            hasOpen.update(openBox(boxes[key], boxes, hasOpen))
    return hasOpen
