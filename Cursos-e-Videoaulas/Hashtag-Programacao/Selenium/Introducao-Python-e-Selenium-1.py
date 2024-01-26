# Para aprendermos a usa, vamos usar o Python para baixar para a gente o Demonstrativo de Resultados da Magazine Luiza

# Passo 1: Entrar em https://ri.magazineluiza.com.br/
# Passo 2: Clicar em 'Planilha Dinâmica'
# Passo 3: Clicar em 'Clique aqui para fazer o download'

from selenium import webdriver
from webdriver_manager.firefox import GeckoDriverManager
from selenium.webdriver.firefox.service import Service

servico = Service(GeckoDriverManager().install())

navegador = webdriver.Firefox(service=servico)

navegador.get('https://ri.magazineluiza.com.br/')

navegador.find_element('xpath', '/html/body/form/main/div[2]/div/div/div[2]/div/div[2]/div/div/div[2]/div/div/a[4]/span').click()