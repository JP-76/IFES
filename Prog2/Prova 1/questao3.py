import questao1
import questao2

def verificaReceita(rec, pac, med, precos):
    cpf = rec[1]
    for presc in rec[2]:
        nomeOFC = presc[0]
        if questao1.alergico( nomeOFC, cpf, pac, med):
            print(f"Medicamento {nomeOFC} inválido! Paciente alérgico.")
        else:
            questao2.opcoes(nomeOFC, med, precos)