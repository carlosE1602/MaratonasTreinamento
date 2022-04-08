line = input()

n,g = line.split(" ")

relations = {}

for i in range(int(n)):
    line = input()
    nome1,nome2 = line.split(" ")
    if nome1 in relations:
        relations[nome1].append(nome2)
    else:
        relations[nome1] = []
        relations[nome1].append(nome2)
    if nome2 in relations:
        relations[nome2].append(nome1)
    else:
        relations[nome2] = []
        relations[nome2].append(nome1)  
#    print(nome1,nome2)
#    relations[nome1].append(nome2)

pertence = {}

for key in(relations.keys()):
    pertence[key] = False
for key in relations.keys():
    if key == "Rerisson": continue
    pertence = {}
    for key in(relations.keys()):
        pertence[key] = False    
    for vizinho in(relations[key]):
    

print(relations)
print(pertence)
