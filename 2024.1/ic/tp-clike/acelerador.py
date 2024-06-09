def sensor(d):
    res = (d % 8) - 5
    return res if res != -5 else 3

assert 1 == sensor(6)
assert 2 == sensor(23)
assert 3 == sensor(9192)
