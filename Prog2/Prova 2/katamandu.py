def lerDados():
    T, D, M = [int(x) for x in input().split()]
    refeicoes = [0]
    for i in range(M):
        r = int(input())
        refeicoes.append(r)
    refeicoes.append(D)
    return T, D, M, refeicoes


def katmandu(T, D, M, refeicoes):
    dorme = False
    for t in range(len(refeicoes)-1):
        if refeicoes[t+1] - refeicoes[t] >= T:
            dorme = True
    if dorme:
        print('Y')
    else:
        print('N')


def main():
    T, D, M, refeicoes = lerDados()

    katmandu(T, D, M, refeicoes)

if __name__ == "__main__":
    main()