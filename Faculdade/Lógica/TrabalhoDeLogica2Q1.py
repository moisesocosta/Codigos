# # # Função de verificar se a subformula já foi adicionada na lista de subformulas
def veriRepe(a, sub):
    if a not in sub:
        return sub.append(a)
    else:
        return sub

# # # Função que retorna a lista de subformulas
def veriSub(a):
    sub = []
    i = 0

    while i < len(a):

        if a[i].isalpha():
            veriRepe(a[i], sub)

        if a[i] == "-":
            if a[i+1].isalpha():
                veriRepe(a[i]+a[i+1], sub)

            if a[i+1] == "(":

                j = i+2
                aux = 1
                while j < len(a):
                    if a[j] == "(":
                        aux += 1
                    if a[j] == ")":
                        aux -= 1
                    if aux == 0:
                        aux = j
                        j = len(a)

                    j += 1

                veriRepe(a[i:aux+1], sub)

        if a[i] == "(":

            j = i+1
            aux = 1
            while j < len(a):
                if a[j] == "(":
                    aux += 1
                if a[j] == ")":
                    aux -= 1
                if aux == 0:
                    aux = j
                    j = len(a)

                j += 1

            veriRepe(a[i:aux+1], sub)
        i += 1

    return(sub)

############################ ^^^^^ FUNÇÕES DE SUBFORMULAS ^^^^^ ############################

# # # Função que recebe duas colunas e um operador e retora uma coluna com o reusltado da operação entre elas
def retornalinha(linha1, operador, linha2):


    #print("esse é o operador", operador)
    linha3 = [False for i in range(len(linha2))]

    if operador == "&":
        for i in range(len(linha1)):
            linha3[i] = linha1[i] and linha2[i]

    elif operador == "#":
        for i in range(len(linha1)):
            linha3[i] = linha1[i] or linha2[i]

    elif operador == ">":
        for i in range(len(linha1)):
            if linha1[i] == False and linha2[i] == True:
                linha3[i] = False
            else:
                linha3[i] = True

    elif operador == "-":
        for i in range(len(linha2)):
            linha3[i] = not linha2[i]

    return linha3

# # # Entra com uma parte de uma subformula X e acha que parte é essa na lista de subformulas retornando sua posição na tabela
def verificalinha(partformula, formula):

    #print(partformula)
    #print(formula)
    # serve pra fazer um tamanho da lista-1 (primeiro -1), até 0 (-1 do meio), e de forma decrescente (-1 do final)
    for k in range(len(formula)-1, -1, -1):
        if partformula == formula[k]:
            return k

# # # Função que quebra as subformulas e chama verificalinha para achar sua linha na tabela,
    # chama retornalinha com a linha da tabela da subfoirmula resolvida,
    # adiciona essa linha na tabela e retorna a tabela resolvida
def resolvetabela(formula, tabela, num):

    CONECTIVOS = [">", "&", "#"]

    #print(formula,len(formula))
    for i in range(num, len(formula)): #entra com as posições da formula depois dos atomos
        if formula[i][0] == "-":
            
            #print(formula[i][1:len(formula[i])])  ########## verificador
            linhadatabela2 = tabela[verificalinha(formula[i][1:len(formula[i])], formula)] ##chama a função passando string na posição i da lista dividida entre seu segundo caracter até o ultimo
            linhadatabela1 = None
            conectivo = "-"
            
        elif formula[i][0] == "(" and formula[i][-1] == ")":
            auxFormula = formula[i][1:len(formula[i])-1]
            

            #print("esse é auxFormula", auxFormula)
            if "(" in auxFormula or ")" in auxFormula:
                
                aux = 0
                posição = 0

                primeiroparen = 0
                ultimoparen = 0
                while posição < len(auxFormula)+1:
                    if auxFormula[posição] == "(":
                        primeiroparen = posição
                        aux += 1

                    if auxFormula[posição] == ")":
                        aux -= 1
                    
                    if aux <= 0:
                        ultimoparen = posição
                        posição= len(auxFormula)

                    posição += 1

                #print(primeiroparen, ultimoparen, auxFormula,"\nesse é primeiro parentes", auxFormula[primeiroparen],"\n", auxFormula[primeiroparen-1])
                if auxFormula[primeiroparen-1] in CONECTIVOS:
                    linhadatabela1 = tabela[verificalinha(auxFormula[0:primeiroparen+1], formula)]
                    linhadatabela2 = tabela[verificalinha(auxFormula[primeiroparen+2:len(auxFormula)], formula)]
                    conectivo = auxFormula[primeiroparen-1]
                
                elif auxFormula[ultimoparen+1] in CONECTIVOS:
                    linhadatabela1 = tabela[verificalinha(auxFormula[0:ultimoparen+1], formula)]
                    linhadatabela2 = tabela[verificalinha(auxFormula[ultimoparen+2:len(auxFormula)], formula)]
                    conectivo = auxFormula[ultimoparen+1]

                #percorrer a sting contando os abre parentese e fecha, qnd todos que foram abertos forem fechados
                #guardar os indicies do primeiro parentese aberto e o ultimo fechado
                # 2 opções,
                    
                    # se o conectivo vier depois do ultimo parentese
                        # então manda antes do conectivo e depois do conectivo pra verifica linha
                        #linhanatabela1 = parte com parentese antes do conectivo
                        #linhanatabela2 = resto da formula depois do conectivo

                    # se o conectivo vier antes do primeiro parentese
                        # então manda antes do conectivo e depois do conectivo pra verifica linha
                        #linhanatabela1 = resto da formula depois do conectivo
                        #linhanatabela2 = parte com parentese antes do conectivo

            else:

                for x in range(len(auxFormula)):
                    if auxFormula[x] in CONECTIVOS:
                        

                        print("esse é auxform na posição x",auxFormula[x])
                        """print((auxFormula[0:x],formula))
                        print(auxFormula[x])
                        print(auxFormula[x+1:len(auxFormula)])
                        print(verificalinha(auxFormula[0:x],formula))
                        print(verificalinha(auxFormula[x+1:len(auxFormula)],formula))"""

                        linhadatabela1 = tabela[verificalinha(auxFormula[0:x],formula)]
                        linhadatabela2 = tabela[verificalinha(auxFormula[x+1:len(auxFormula)],formula)]
                        conectivo = auxFormula[x]
                          

                # procurar pelo primeiro conectivo e dividir a string em duas antes do conectivo e dps do conectivo
                # e mandar as duas pra verifica linha


        #print(linhadatabela1, conectivo, linhadatabela2)
        #print(retornalinha(linhadatabela1, conectivo, linhadatabela2))

        tabela.append(retornalinha(linhadatabela1, conectivo, linhadatabela2))

    return tabela

# # # Função que cria as colunas dos atomos
def criaTabela(subformulas):
    
    num = 0
    for i in range(len(subformulas)):
        if len(subformulas[i]) == 1:
            num = num + 1
    
    tabela = []

    for j in range(num):  # colunas | entra como 1
        tabelaVouFTESTE = []
        for i in range(2**(num-1-j)):  # repetições dos blocos | entra como 0 de 0 a 2 ^ (3-1-0) = 4
            for k in range(2*(2**j)):  # repetições dos V ou F | entra como 2 * 2 ** 1 = 2
                if k >= 2**j: 
                    tabelaVouFTESTE.append(False) 
                else: 
                    tabelaVouFTESTE.append(True)
        tabela.insert(0,tabelaVouFTESTE)

    tabelaresolvida = resolvetabela(subformulas, tabela, num)

    return tabelaresolvida

    '''

    até aqui temos a tabela com as linhas preenchidas com os valores dos atomos
    linha 1 = a = [0 1 0 1]
    linha 2 = b = [0 0 1 1]
    ...

    dentro da main
    chama a função de criar a tabela e os atomos(passando num) || retorna tabela dos atomos
    chama a função que seleciona quem vai ser resolvido dps, tipo, a&b dps a&b#b (passando a tabela dos atomos acima)(função a fazer) || retorna tabela pronta
            dentro dessa chamada de cima, em um for, chama a função pra resolução das linhas (retornalinha)(função já concluida) || retorna uma linha da tabela resolvida

    retorno da função que seleciona vai ser a tabela pronta pra ser mostrada e pronta pra ser classificada


    '''

################## ^^^^^ FUNÇÕES DE CRIAR E RESOLVER TABELA VERDADE ^^^^^ ##################

# # # Função para mostrar a tabela verdade
def mostraTabela(formula, a, num):
    
    print()
    for k in range(len(formula)):
        print(formula[k], end=" ")
    print()
    print()
    espacos = 1

    for j in range(pow(2, num)):  # linhas

        for i in range(len(formula)):  # colunas

            if i+1 < len(formula):
                espacos = int(len(formula[i+1]) / 2) + \
                    int(len(formula[i]) / 2) + 1
                # print("esse é o numero de espaços", espacos)
            else:
                espacos = 1

            if a[i][j] == True:
                print("1", end=" "*espacos)
            else:
                print("0", end=" "*espacos)
        print()

    print("\n>>> Isso é tudo pe-pessoal <<<\n")

# # # Função de classificação de Formulas
def classificacao(ultimalinha):
    T = F = 0 
    for i in range(len(ultimalinha)):
        if ultimalinha[i] == True:
            T = T + 1
        else:
            F = F + 1
    
    if T == len(ultimalinha):
        print("é válida(tautologia) e satisfazível")
    elif F == len(ultimalinha):
        print("é insatisfazível e falsificável")
    else:
        print("satisfazivel e falsificável")


######################### ^^^^^ FUNÇÕES DE MOSTRAR RESULTADOS ^^^^^ ########################

# # # Função principal para rodar a bagaça
def main():
    
    formula = (input("Digite a fórmula: "))
    subformula = sorted(veriSub(formula), key=len)

    tabelaresolvida = criaTabela(subformula)

    #print(tabelaresolvida)
    
    num = 0
    for i in range(len(subformula)):
        if len(subformula[i]) == 1:
            num = num + 1

    mostraTabela(subformula, tabelaresolvida, num)
    classificacao(tabelaresolvida[-1])


main()

################################ DAQUI PRA CIMA TA ORGANIZADO ###########################################
############################### DAQUI PRA BAIXO É A QUESTÃO 2 ###########################################

def comparalogica(formulasResultados, AResultado):
    
    formulasResultados = [[True,  True,  True,  False],     #a
                          [False, False, True,  False],     #b
                          [True,  False, True,  False],     #c
                          [True,  True,  False, False]]     #d

    AResultado = [True, True, True, False] 

    casoEspecial = 0

    for i in range(len(formulasResultados)):
        for j in range(len(formulasResultados[i])):

            if formulasResultados[i][j] == True:
                if AResultado[j] == False:
                    return "não é consequência lógica"
            else: 
                casoEspecial = casoEspecial + 1
                if casoEspecial == len(formulasResultados[i]):
                    return "é consequência lógica"

    return "é consequência lógica"

# # # Função para verificar a consequência lógica
def consequenciaLogica():

    Formulas = []
    
    x = True

    print("\n\nDigite o conjunto de Fórmulas que quer verificar sua cosequencia lógica")
    while(x == True):
        Formulas.append(input("\nDigite uma formula: "))
        aux = input("Digite 1 se quiser adicionar mais uma formula ou, qualquer outra tecla para encerrar conjunto de formulas: ")

        if aux != "1":
            x = False

    A = input("Agora, digite a formula a ser validada com o conjunto digitado anteriormente: ")
   
    print(Formulas)
    print(A)

    formulasResultados = []
    for i in range(len(Formulas)):
        x = criaTabela(Formulas[i])

        formulasResultados.append(x[-1])
    
    x = criaTabela(A)
    AResultado = x[-1]

    comparalogica(formulasResultados, AResultado)


"""

"a" "b" "c" |= "((a&b)&c)"
 0   0   0        0
 1   1   1        0
 0                1  
 1                1





"""
'''
a = [[]]
b = []
#consequenciaLogica()
print(comparalogica(a, b))

'''

