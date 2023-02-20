def lerDados():
    n = int(input())
    votos = []
    for i in range(n):
        v = int(input())
        votos.append(v)
    return n, votos


def bobo(n, votos):
    eleito = True
    for i in range(1, len(votos)):
        if votos[i] > votos[0]:
            eleito = False
    if eleito:
        print("S")
    else:
        print("N")


def main():

    n, votos = lerDados()

    bobo(n, votos)

if __name__ == "__main__":
    main()