print('Gerador de PA')
print('-=' * 10)
primeiro = int(input('Primeiro termo: '))
razao = int(input('Razão da PA: '))
termo = primeiro
cont = 1
while cont <= 10:
    primeiro('{} -> '.format(termo), end='')
    termo += razao
    cont += 1
print('FIM')
