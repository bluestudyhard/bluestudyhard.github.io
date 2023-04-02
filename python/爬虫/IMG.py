import requests
from bs4 import BeautifulSoup
import re
url = "https://zhuanlan.zhihu.com/p/351898030"
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

# 找到所有图片标签
img_tags = soup.find_all('img')

# 遍历所有图片标签，获取图片链接并下载图片
for img in img_tags:
    img_url = img['src']
    img_name = re.sub(r'[\?*:/\\]', '_', img_url.split('/')[-1])
    img_response = requests.get(img_url)
    if img_url.startswith('data:'):
        continue
    with open(img_name, 'wb') as f:
        f.write(img_response.content)
