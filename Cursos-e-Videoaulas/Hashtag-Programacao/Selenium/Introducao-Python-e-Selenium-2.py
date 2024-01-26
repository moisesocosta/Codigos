# Para aprender, vamos usar o Python para preencher um formulário na internet

# Passo 1: Entrar em https://pages.hashtagtreinamentos.com/inscricao-minicurso-python-automacao-org?origemurl=hashtag_yt_org_minipython_videoselenium
# Passo 2: Preencher nome, preencher e-mail
# Passo 3: Clicar no botão para enviar o formulário

from selenium import webdriver
from webdriver_manager.firefox import GeckoDriverManager
from selenium.webdriver.firefox.service import Service

servico = Service(GeckoDriverManager().install())

navegador = webdriver.Firefox(service=servico)

# Passo 1
navegador.get('https://pages.hashtagtreinamentos.com/inscricao-minicurso-python-automacao-org?origemurl=hashtag_yt_org_minipython_videoselenium')

# Passo 2
navegador.find_element('xpath', 
                       '/html/body/div[2]/div[1]/section/div[2]/div/div[2]/form/div[1]/div/div[1]/div/input').send_keys('Lira')

navegador.find_element('xpath', 
                       '/html/body/div[2]/div[1]/section/div[2]/div/div[2]/form/div[1]/div/div[2]/div/input').send_keys('pythonimpressionador@gmail.com')

navegador.find_element('xpath', 
                       '/html/body/div[2]/div[1]/section/div[2]/div/div[2]/form/div[1]/div/div[3]/div/input').send_keys('0000000000')

# Passo 3
navegador.find_element('xpath', 
                       '/html/body/div[2]/div[1]/section/div[2]/div/div[2]/form/button').click()
