import datetime
import uuid
import time
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

chrome_driver_options = webdriver.ChromeOptions()
chrome_driver_options.add_argument('headless')
chrome_driver = webdriver.Chrome(
    ChromeDriverManager().install(), options=chrome_driver_options)

RALLIS = "Rallis India Limited"
TCL = "Tata Chemicals Limited"


def sel_client(client):
    try:
        client_dropdown = WebDriverWait(chrome_driver, 10).until(
            EC.presence_of_all_elements_located((By.CLASS_NAME, "dropdown-chevron")))[0]
        client_dropdown.click()
        dropdown_rows = WebDriverWait(chrome_driver, 10).until(
            EC.presence_of_all_elements_located((By.CLASS_NAME, "slicerText")))
        for r in dropdown_rows:
            if r.text == client:
                r.click()
                random_dom = WebDriverWait(chrome_driver, 10).until(
                    EC.presence_of_element_located((By.CSS_SELECTOR, "h3")))
                random_dom.click()
                return
    except:
        print('error in selecting client')
        return


def sel_rallis():
    sel_client(RALLIS)


def sel_tcl():
    sel_client(TCL)


def sel_date():
    try:
        calendar_btn = WebDriverWait(chrome_driver, 10).until(
            EC.element_to_be_clickable((By.CLASS_NAME, "calendar-button")))
        calendar_btn.click()
        calender_table = WebDriverWait(chrome_driver, 10).until(
            EC.element_to_be_clickable((By.CLASS_NAME, "calendar-table")))
        x = WebDriverWait(calender_table, 10).until(
            EC.presence_of_all_elements_located((By.CSS_SELECTOR, "button")))
        today = datetime.date.today()
        for b in x:
            if int(b.text) == max(int(today.strftime("%d"))-1, 1):
                time.sleep(1)
                b.click()
                return
    except:
        print('err')


def __main__():
    try:
        url = "https://app.powerbi.com/view?r=eyJrIjoiMjIzNjBmNDItZmQ0ZC00Y2M5LTlmYTQtZTY1OTk4MzYxNjEwIiwidCI6ImM5MDhhYzdjLTRjNDgtNDg2OC1hOTZiLTJhN2RkNmQxNDQ1NSJ9"
        chrome_driver.implicitly_wait(30)
        chrome_driver.set_window_size(1920, 1080)
        chrome_driver.get(url)

        # to upload in S3

        btns = WebDriverWait(chrome_driver, 10).until(
            EC.presence_of_all_elements_located((By.CLASS_NAME, "ui-role-button-fill")))
        e = btns[1]
        try:
            e.click()
            sel_date()
            time.sleep(2)
            sel_rallis()
            time.sleep(4)
            chrome_driver.save_screenshot(
                f"/Users/lonewolf777/Pictures/screenshots/selenium/{uuid.uuid4()}-rallis.png")
            sel_tcl()
            time.sleep(4)
            chrome_driver.save_screenshot(
                f"/Users/lonewolf777/Pictures/screenshots/selenium/{uuid.uuid4()}-tcl.png")
        except Exception as err:
            print('error', err)
    finally:
        print('done')
        chrome_driver.quit()


__main__()
