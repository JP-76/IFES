def opcoes(nomeOFC, med, precos):
    r = nomeOFC
    r = r + med[nomeOFC]
    for nome in precos:
        dose, qnt, prc = precos[nome]
        if nome in r:
            print(f"{nome} - {dose} - R${prc:.2f}")