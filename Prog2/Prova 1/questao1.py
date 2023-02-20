def alergico(nomeOFC, cpf, pac, med):
    for alergia in pac[cpf][1]:
        if alergia == nomeOFC:
            return True
        else:
            for nomeCOM in med[nomeOFC]:
                if alergia == nomeCOM:
                    return True
    return False