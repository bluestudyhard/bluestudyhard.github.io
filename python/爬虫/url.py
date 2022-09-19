from operator import imod
from pydoc import resolve


import urllib.request
import urllib.parse
#url = ('https://www.bilibili.com')
url = ('https://www.dm0.cc/')
url1 = ('https://www.baidu.com')
# 模拟浏览器发送请求
# 爬一些反爬的可以模仿用户即ua，来访问，查找header
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.5060.134 Safari/537.36 Edg/103.0.1264.77'}

#response = urllib.request.Request(url,headers=headers)
#html = urllib.request.urlopen(response)


response = urllib.request.urlopen(url)
# 获取响应中页面的源码
# read() 方法返回字节形式的2进制 是一个一个字节来读取的
# 所以要解码
# bites -> str 用decode()解码
content = response.read().decode('utf-8')

# print(content)


# 一个类型和6中方法

print(type(response))  # 类型为 <class 'http.client.HTTPResponse'>

content1 = response.read(5)
content2 = response.readline()  # 读取一行
# content3 = response.readlines() # 直接读取到所有行

# 返回状态码 如果是200 没毛病 404 就寄
print(response.getcode())
print(response.status)
# 返回url地址
print(response.geturl())

# 获取状态信息
print(response.getheaders())


# urllib 下载 urlretrieve(url,'filename（保存的本地路径）',reporthook,)
# urlretrieve(url, filename=None, reporthook=None, data=None)

# 参数url：下载链接地址
# 参数filename：指定了保存本地路径（如果参数未指定，urllib会生成一个临时文件保存数据。）
# 参数reporthook：是一个回调函数，当连接上服务器、以及相应的数据块传输完毕时会触发该回调，我们可以利用这个回调函数来显示当前的下载进度。
# 参数data：指post导服务器的数据，该方法返回一个包含两个元素的(filename, headers) 元组，filename 表示保存到本地的路径，header表示服务器的响应头


url_page = ('https://www.taobao.com/')

urllib.request.urlretrieve(url_page, '../taobao.html')

url_img = ('https://i1.hdslb.com/bfs/archive/6e36ac400cfebf7e7b49fbe2c64119ffaa7cb93e.jpg@672w_378h_1c.webp')

urllib.request.urlretrieve(url_img, 'img1.jpg')

# video 同理


# https://cn.bing.com/search?q=%E5%91%A8%E6%9D%B0%E4%BC%A6
# = https://cn.bing.com/search?q=周杰伦
# q = 后面是Unicode字符串，假设我们要检索的是周杰伦，这个在用urllib.request.Request()里面是会报错的，因为不是Unicode字符，所以，我们要用
# urllib.parse.qoute 将中文字符转换成Unicode编码（单个转换）

# urllib.parse.urlencode 可以将多个中文字符转换成Unicode编码
# urllib.parse.quote 用法



name = urllib.parse.quote('周杰伦')

print(urllib.parse.quote(name))

# urllib.parse.urlencode 用法，先把等号值造一个字典
data = {
    'q': '周杰伦',
    'sex': '男'
}

a = urllib.parse.urlencode(data)
print(a)
url = 'https://cn.bing.com/search?'
url = url+a
print(url)



url = 'https://cn.bing.com/search?q='
header = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.81 Safari/537.36 Edg/104.0.1293.54'
}
url = url+name
# 获取ua，并且定制一个请求对象
request = urllib.request.Request(url=url, headers=header)
# 仿照浏览器访问网站
response = urllib.request.urlopen(request)

# 读取爬来的文件并用decode的方法转字符
content = response.read().decode('utf-8')


print(content)
