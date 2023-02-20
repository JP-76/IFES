def lerDados():
    c = int(input())
    valores = []
    for i in range(c):
        v = int(input())
        valores.append(v)
    return c, valores


def gameShow(c, valores):
    maior = 100
    atual = 100
    for v in valores:
        atual += v
        if atual > maior:
            maior = atual
    print(maior)


def main():

    c, valores = lerDados()

    gameShow(c, valores)

if __name__ == "__main__":
    main()