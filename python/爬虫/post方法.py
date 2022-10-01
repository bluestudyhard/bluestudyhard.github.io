
import urllib.request
import urllib.parse

# 常规的爬取post数据的方法如下，但是有道和百度翻译等网站都用了反爬手段，所以会报错误码。
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.81 Safari/537.36 Edg/104.0.1293.54'
}

url = 'https://fanyi.youdao.com/translate_o?smartresult=dict&smartresult=rule'

data = {
    'wd':'spider'
}

data = urllib.parse.urlencode(data).encode('utf-8')

request = urllib.request.Request(url=url,data=data,headers=headers)

response = urllib.request.urlopen(request)
print(response)

content = response.read().decode('utf-8')

print(content)