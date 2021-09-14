

from deu_errado_ta_dando_certo_Q1 import criaTabela, mostraTabela, resolvetabela, veriSub, verificalinha




def resolveconsequencialogica(formulas, tabelageral, conjuntoForm_Entrada, aForm_entrada):

    conjuntoForm = conjuntoForm_Entrada.split(",",conjuntoForm_Entrada.count(','))
    #print(conjuntoForm) (a&b)#c),(a#c),-(b>c)

    id_formulas = []
    for formula in conjuntoForm:
        id_formulas.append(verificalinha(formula, formulas))
    #print(id_formulas)  |  [7, 4, 6]

    id_A = verificalinha(aForm_entrada, formulas)
    #print(id_A)  |  8

    for j in range(len(tabelageral[0])): ## verifica linha por linha das colunas abaixo

        contVerdade = 0
        for i in id_formulas: ## colunas referente a lista de subformulas [7, 4, 6] 
            #print("esse é o i",i)
            if tabelageral[i][j] == True:
                contVerdade = contVerdade + 1

        #print(contVerdade)
        if contVerdade == len(id_formulas) and tabelageral[id_A][j] == False:
            return "não é consequencia logica"

    return "é consequencia logica"


def organizaconjntoformulas(conjuntoForm_Entrada,aForm_entrada):
    
#gerar subconjunto de A
    aForm_Subaux = sorted((veriSub(aForm_entrada)), key = len)

    aForm_Subf = []
    for i in aForm_Subaux:
        if not i.isalpha():
            aForm_Subf.append(i)

#separar o conjunto das formulas
    conjuntoForm = conjuntoForm_Entrada.split(",",conjuntoForm_Entrada.count(','))
    #print(conjuntoForm)

#gerar os subconjunto das formulas

    conjuntoForm_Subaux = []
    for i in range(len(conjuntoForm)):
        conjuntoForm_Subaux = conjuntoForm_Subaux + veriSub(conjuntoForm[i])

    #organiza os subconjuntos
    conjuntoForm_Subaux = sorted((conjuntoForm_Subaux), key = len)
    
    #tira os atomos repetidos
    conjuntoForm_Subf = []
    for i in range(len(conjuntoForm_Subaux)):
        if not conjuntoForm_Subaux[i].isalpha():
            conjuntoForm_Subf.append(conjuntoForm_Subaux[i])

    return (conjuntoForm_Subf + aForm_Subf)


def main():

#entradas
    #ex. de formato de entrada: (a&b),(a#c),(b&c)
    conjuntoForm_Entrada = input("digite uma formula de consequencia logica no formato acima")
    
    #ex. de formato de entrada: (a>b)
    aForm_entrada = input("digite a formula a ser comparada")
    

#achar os atomos
    aux = conjuntoForm_Entrada + aForm_entrada

    atomos = []
    for i in range(len(aux)):
        if aux[i].isalpha() and aux[i] not in atomos:
            atomos.append(aux[i])
    #atomos

#gerar a tabela dos atomos
    tabelaAtomos = criaTabela(atomos)
    #print(tabelaAtomos)


    formula = atomos + organizaconjntoformulas(conjuntoForm_Entrada, aForm_entrada)
    #print(formula)

    tabelageral = resolvetabela(formula, tabelaAtomos, len(atomos))

    mostraTabela(formula, tabelageral, len(atomos))
    
    print(resolveconsequencialogica(formula, tabelageral, conjuntoForm_Entrada, aForm_entrada))

main()