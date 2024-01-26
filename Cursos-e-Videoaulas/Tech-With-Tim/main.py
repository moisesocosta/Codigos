from selenium import webdriver
from webdriver_manager.firefox import GeckoDriverManager
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

service = Service(GeckoDriverManager().install())
driver = webdriver.Firefox(service=service)

driver.get("https://google.com")

WebDriverWait(driver, 5).until(
  EC.presence_of_all_elements_located((By.CLASS_NAME, "gLFyf"))
)

input_element = driver.find_element(By.CLASS_NAME, "gLFyf")
input_element.clear()
input_element.send_keys("tech with tim" + Keys.ENTER)

WebDriverWait(driver, 5).until(
  EC.presence_of_all_elements_located((By.PARTIAL_LINK_TEXT, "Tech With Tim"))
)

link = driver.find_element(By.PARTIAL_LINK_TEXT, "Tech With Tim")
link.click()

time.sleep(10)

driver.quit()