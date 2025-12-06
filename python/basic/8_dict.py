mydict = {
"Roshan" : " A failed guy",
"Anthon" : " a good father",
"Pereira" : " arrey its my sirname",
1 : " a number",
2 : 4,
"myanotherdict" : { 3:4 },
5 : 6
}

print(mydict)
print(mydict["Roshan"])
print(mydict[2])
print(type(mydict))
print(list(mydict))

print(mydict.keys())
print(mydict.values())
print(mydict.items())

print(mydict.get("Roshan"))
"this get function returns null if key not found but if you directly access dictionary and if key not present program fails"

updatedict = {
"Shobina" : "my mother",
"Pereira" : "yes its my initial"
}

print(updatedict)
mydict.update(updatedict)
print(mydict)
