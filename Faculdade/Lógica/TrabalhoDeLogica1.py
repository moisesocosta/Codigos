#Função para verificar se é fórmula ou não
def principal(a, contsubf):

    #Caso o número de abertura de parentese for diferente de fechamento de parentese
    if a.count("(") != a.count(")"):
        return "FALSO"

    #Caso se só foi digitado um átomo e estiver em minúsculo
    if len(a) == 1 and a.islower() and a.isalpha():  
        if a not in contsubf:   
            contsubf.append(a)
        return "x"

    #Caso tenha negação na fórmula
    elif "-" in a:

        #Procurando o conectivo de negação
        x = a.find("-")

        #Caso a negação esteja no fim da fórmula, sem um átomo depois
        if x == len(a)-1:
            return "FALSO"

        #Caso, depois da negação, seja um átomo ou um parentese
        if a[x+1].isalpha() or a[x+1] == "(":

            #Caso depois da negação for um átomo
            if a[x+1].isalpha() and a[x]+a[x+1] not in contsubf:   
                contsubf.append(a[x:x+2])
            #Caso depois da negação for uma abertura de parentese
            if a[x+1] == "(":   
                contsubf.append(a)

            a = a[0:x]+a[x+1:]
            return "-" + principal(a, contsubf)

        #Senão for nenhum desses casos
        else:
            return "FALSO"
            
    else:

        #Caso não tenha parenteses na fórmula
        if "(" not in a and ")" not in a:
            return "FALSO"

        else: 

            #Caso a fórmula não tenha sido adicionada na contsubf, variável que armazena as subformulas
            if a not in contsubf:   
                contsubf.append(a)
            a = a[1:-1]

            aux = 0
            i = 0

            #Divide a string/fórmula em dois e analisa os parenteses
            while i < len(a)+1:
                    if a[i] == "(":
                        aux += 1

                    if a[i] == ")":
                        aux -= 1
                    
                    if aux <= 0:
                        x = i
                        i = len(a)

                    i += 1
            
            #Partes da string/fórmula
            parte1 = a[0:x+1]
            parte2 = a[x+2:len(a)]
            
            #Caso a negação esteja no fim da fórmula, sem um átomo depois
            if x == len(a)-1:
                return "FALSO"

            #Caso encontre um conectivo
            elif a[x+1] in CONECTIVOS:
                return principal(parte1, contsubf) + a[x+1] + principal(parte2, contsubf)

        #Senão for nenhum desses casos
        return "FALSO"

#Função para verificar as subformulas repetidas
def veriRepe(a, sub):
    #Caso a fórmula ainda não foi adicionada na sub, variavel para armazenar as subformulas
    if a not in sub:
        return sub.append(a)
    else:
        return sub

#Função para verificar as subformulas
def veriSub(a):
    sub = []
    i = 0

    #Percorre a string/fórmula
    while i < len(a):   

        #Caso tenha encontrado uma átomo
        if a[i].isalpha():
            veriRepe(a[i], sub)
        
        #Caso tenha encontrado um conectivo de negação
        if a[i] == "-":
            #Verifica se o próximo é um átomo
            if a[i+1].isalpha():
                veriRepe(a[i]+a[i+1], sub)

            #Verifica se o próximo é uma abertura de parentese
            if a[i+1] == "(":
                
                j = i+2
                aux = 1

                #Divide a string/fórmula em dois e analisa os parenteses
                while j < len(a):
                    if a[j] == "(":
                        aux += 1
                    if a[j] == ")":
                        aux -= 1
                    if aux == 0:
                        aux = j
                        j = len(a)

                    j += 1

                #Verifica uma parte da string/fórmula
                veriRepe(a[i:aux+1], sub)
            
        #Caso tenha encontrado uma abertura de parentese
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

#Função principal
def main():

    #Menu de apresentação
    print("#"*33)
    print("  Verificador de Fórmula Lógica  ")
    print("#"*33)
    print()

    print('Símbolos Átomicos -> {\033[1;32ma, b, c, ..., x, y, z\033[m}')
    print('Símbolos auxiliares -> {\033[1;32m( )\033[m}')
    print('{\033[1;32m-\033[m} significando negação')
    print('{\033[1;32m&\033[m} significando conjução')
    print('{\033[1;32m#\033[m} significando disjunção')
    print('{\033[1;32m>\033[m} significando implicação')

    print("Exemplo:\033[1;32m (-(a#b)>(a&b)) \033[m")
    print()

    #Pedir uma fórmula proposicional ao usuário
    formula = input("Digite uma formula: ")

    #Tirando os espaços, se tiver, da fórmula
    semespaco = ""
    for i in range(len(formula)):
        if formula[i] != " ":
            semespaco = semespaco + formula[i]

    #Criando a variável em formato de lista para armazenar as subformulas
    contsubf = []

    #Mandando a fórmula para a verificação
    resultado = principal(semespaco, contsubf)

    #Após receber o resultado da verificação
    if "FALSO" in resultado:
        #Se não for fórmula
        print("\n>>> NÃO É FORMULA")

    else:

        #Se for fórmula
        listOrdem = sorted(veriSub(semespaco), key=len)
        print("\n>>> É FORMULA")
        print(">>> As subformulas são:", listOrdem)
        print(">>> A complexidade é:", len(resultado))

#Armazendo os conectivos lógicos em uma só variável
CONECTIVOS = [">" , "&", "#"]

#Chamando a função main para começar o código
main()
