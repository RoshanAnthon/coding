a = {1, 2, 3, 4, 5}
b = set()
c = {}

print(type(a))
print(type(b))
print(type(c))

a.add(6)
b.add("roshan")
b.add((1,2,3))
#b.add([1,2,3])
#b.add({1:2,3:4}) -->list and dict cant be added cos set is only non hashable list, meaning non editible

print(a)
print(b)

a.add(2)
a.add(3)

print(a)

" set is a list of NON_REPETATIVE non hashable elements"

c = {1, 2, 3, 4, 5}
d = {3, 4, 5, 6, 7}

#print(c.len())
print(len(c))
print(c.union(d))
print(c.intersection(d))

print(d.union({8,9}))
print(d.intersection({5,6,7,8,9}))

print(d.remove(7))
print(d)
