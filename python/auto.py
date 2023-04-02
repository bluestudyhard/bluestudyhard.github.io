import pyautogui
import time

# 设置鼠标点击位置
x, y = 500, 500

# 循环执行鼠标点击事件
while True:
    pyautogui.click(x=x, y=y, button='left')
    time.sleep(1)  # 暂停1秒钟
