# Python 基本语法
###
# 是注释，python严格区分大小写，不用加;
# print 直接输出类型
# python 的编码是Unicode
import json
from collections import namedtuple
from posixpath import split
from re import I
from tkinter import PIESLICE, W
from unicodedata import name


print(123)
print("你好\n 你好 你好")  # 字符串类型要双引号or 单引号
print('hehe')

if 5 > 2:  # :相当于c++的{},这个区域就属于代码块了
    print("yes")
else:
    print("no")


# python 变量
# 和php一样变量不用声明类型，系统会自动识别，字符串加"" or ''表明就行,和string一样可以实现字符串相加的功能
x = 10
y = 20.2
z = "python"
z1 = 'python1'
sex = True
print(x, y, z, z1, sex)
###x1,y1,z1 = 1,2,3
print(z1+"  "+z)  # 直接实现string相加
# print(z1+x) 会报错，因为不能实现不同类型相加

whole = "全局变量"
print(whole)


def func():
    whole = "局部变量"  # 在函数内部可以声明同名局部变量
    print(whole)


func()


def globalfunc():
    global whole  # 用global声明可以在内部改变全局变量的值
    whole = "函数体内改变全局变量"
    print(whole)


globalfunc()
print(whole)

print("\"lk\"")  # 转义符，在所需要转义的符号面前加\
print("'lk'")
print('''line1 "可以用 \''' \''' 换行 " 
      line 2''')  # 如果字符串内部有很多换行，用\n写在一行里不好阅读，为了简化，Python允许用'''...'''的格式表示输出多行字符串，空格换行，换行符等都会起作用。
print()
print()
### 数据类型 ###


# 文字类型： str
# 数值类型： int，float， complex
# 序列类型： list，tuple， range
# 映射类型： dict
# 集合类型： set， frozenset
# 布尔类型： bool
# 二进制类型： bytes，bytearray， memoryview


# 类型转换 ###int float complex str
# int 转换常用于把字符串转换为整形，比如说一个网站的页码
# float转换 字符串转换为浮点
# 字符串 常用于将整形变为字符串然后进行拼接。
# bool转换 int float不为0 str非空内容的 都为TRUE

print(type(x))  # 输出类型
x = float(x)
y = complex(y+I)
print(x, y)
y1 = str(x)+"change"  # 这样就变成字符串了
print(y1)
print(bool(1.2), bool(0.0), bool("你好"), bool(" "), bool(''))
print()
print()
print('字符串函数')
st = " hello,world,word"
print(st[1])
print(len(st))
print(st.strip())  # 去空格
print(st.upper())  # 变大写
# 切片
print(st[2:5])  # return 迭代器第二个到第五个
print(st[-5:-2])  # 返回这个字符串 倒数第五个到倒数第二个
print(st[1:5:2])  # 最后一个是步长 返回下标为1的和下标为3的，下标为5时因为是开区间不返回
print(st[1:])  # 从左的闭区间到结尾
print(st[:4])  # 从0到右的开区间
# find 查找字符或者字符串，返回他的下标
print(st.find('hello'))
print(st.find('ld'))

# count 范围字符或部分字符串出现次数
print(st.count('l'))
print(st.count('wor'))
# 判断开头结尾是不是哪个字符
print(st.startswith('c'))
print(st.endswith('d'))

# 用replace 可以替换字符串
judge = "aabb"
print(judge.replace('b', 'a'))

# split 根据内容分割成几部分
# 比如hello，world 以w,w抛掉分割 就分割成 'hello','','orld'
# 如果什么都不加，他就是默认字符串
print(st.split('w'))
print(st.split())

# join
print(st.join('a'))

print()
print()
print('列表')

# Python 集合（数组）
# Python编程语言中有四种收集数据类型：
# List(列表) - 是有序且可更改的集合。允许重复的成员。
# Tuple(元组) - 是有序且不可更改的集合。允许重复的成员。
# Set(集合) - 是无序和未索引的集合。没有重复的成员。
# Dictionary(字典) - 是无序，可变和索引的集合。没有重复的成员。


# list 有序可修改
# 列表可以理解为字符串数组，他以键值存储数据，访问时也是通过键值访问,下标从0开始
# append() 相当于push 从列表的末尾插入一个元素
# insert(self,index,object) 在列表元素之间插入一个元素。 index指的是你想插入的下标
# len() 懂得都懂,return元素个数
# pop(index) 出栈咯，指定下标删除元素,没指定下标就默认最后一个元素。
# remove(index.id) 删除指定名字项目
# del name_list[1] 通过数组 下标删除项目
# extend() list1,list2 把list2 直接和list1 末尾相连
# list() 直接copy 一个新的list
name_list = ['001', 'lk', '002', 'wyt']
print(name_list)
print(name_list[1])


name_list.append("love,blue")
print(name_list)


name_list.insert(1, 'aaa')
print(name_list)

print(len(name_list))

print(name_list.pop(1))
print(name_list)
name_list.insert(1, 'aaa')
print(name_list)
name_list.remove('aaa')
print(name_list)

name_list.insert(5, 'aaa')
print(name_list)


del name_list[5]
print(name_list)


print()
print()


print('元祖')


# tuple 元组，元组的数据不可修改，其他的内置函数和list的基本一致，同理元组的内容不可删除，但是可以删除整个元组

name_tuple = ('001', '002', 'lk', 'wyt')
print(name_tuple[0])
# name_tuple[1] = 2 报错 元组不可修改

a_tuple = (2)
del(a_tuple)


print()
print()


print('字典')
# dict 字典！！非常重要 scrapy 框架可用
# 本质是树结构 格式 变量 = {key:value} 一个元素包括键和值

name_dict = {"name": '蓝凯', 'age': '19'}
print(name_dict)
print(name_dict['age'])  # 用键值访问，输出结果是value
print(type(name_dict['name']))  # 也可以用type函数获取dict或者list，Tuple里的数据类型
print(name_dict.get("name"))    # .get() 同理

# len 获取键值的多少
print(len(name_dict))


if "name" in name_dict:
    print("yes")

name_dict['age'] = '20'
print(name_dict['age'])


# 增加dict 直接新建键值就好
name_dict["sex"] = 1
print(name_dict)


# 删除操作 pop()+key名 删除指定键值 popiteam 删除最后一个键 del 也行 clear() 清空
name_dict.popitem()
print(name_dict)

# 复制的话可以用构造 dict() 这个最常用，可以生成一个新的dict
dict1 = name_dict.copy()
print(dict1)
# 嵌套字典以及构造新字典 这个很重要 可以嵌套元组和list
person = {
    "boy": {
        "name": 'bluekkk',
        "age": 20
    },
    "girl": {
        "name": 'wyt',
        "age": 20
    },
    "nomale": [1, 2, 3]
}
print(person)

print(person['nomale'])
print(person['nomale'][0])  # 访问带list的dict里面的list的第一个元素 疯狂套娃

# 如果想用dict() 来构造的话，要注意里面的key不能带双引号，然后赋值用=
dict2 = dict(gouzao="dict来构造", lala=[1, 2, 3], lulu=("当然也可以嵌套元组和list", 1))
print(dict2)
print(dict2["lala"])

print(len(dict2))

# 遍历字典
# 直接遍历获取键值就用普通的遍历到dict名
for key in dict2:
    print(key, end=' ')

print()

# 遍历到值就要用values()
for values in dict2.values():
    print(values)


# 遍历key和value 用items()
for itemm in dict2.items():
    print(itemm)


print()
print()
# 运算符
# **是求幂次x**y x的y次方，//是向下取整 9//2 = 4
# /的话会自动判断类型相除 浮点型也会变成浮点型保留几位小数  保留小数'%.xf ' %float

print(2**3, 9//2, 9/2, '%.2f' % 9.5578)
print('%.2f' % (9.5/2.5))
print("123"+"334")

i = 1
while i <= 6:
    x = 10
    if i == 1:
        x ^= 3
        print(x)
        i += 1
    elif i == 2:
        x //= 3
        print(x)
        i += 1
    elif i == 3:
        x >>= 3
        print(x)
        i += 1
    elif i == 4:
        x <<= 3
        print(x)
        i += 1
    elif i == 5:
        x &= 3  # 相当于%了
        print(x)
        i += 1
    else:
        x |= 3
        print(x)
        i += 1


a = 30
a < 10 and print("不用if利用逻辑运算符的特性")
a > 10 and print("不用if利用逻辑运算符的特性")

# 输入 input()
# 输出 print() print 参数自带end = ('\n') 所以可以 end=(' ')来让输出在一行内

### name = input("请输入名字")
# print(name)


# for in  for后面的变量可以理解为一个迭代器， in 指向要遍历的对象，迭代器会自动遍历对象。
# 若想像c++那样 指定变量范围
# 可以用 for i in range(5),一个参数 区间（0,参数-1） range(5,10)
# 两个参数  区间左闭右开(5,9)
# 三个参数 (起始值，结束值，步长) range(5,10,3) 结果 5,8啥意思呢，i相当于i+=3，然后第三次的时候已经加到11了，所以结果只有5,8
for i in name_list:
    print(i, end=' ')
    print(type(i), end=' ')
print()
for i in range(5):
    print(i, end=' ')
print()
for i in range(5, 10):
    print(i, end=' ')
print()
for i in range(5, 10, 3):
    print(i, end=' ')
print()

# 循环插入数组元素的方法，要记得input放循环体里面
a = []
# while i <= 5:
#     sx = input("请输入list元素")
#     a.append(sx)
#     i += 1
# for 循环插入#
# for i in range(5):
#     sx = float(input())#避免输入到了字符串什么的东西
#     a.append(sx)

# print(a)

print()

# 函数 #


def sum():
    a = 2
    b = 3
    c = a+b
    return c


print(sum())

#文件操作#


# r,t 是默认值
# open 可以创建并打开一个新的文件，当然打开并不会真的打开。
# "r" - 读取 - 默认值。打开文件进行读取，如果文件不存在，则错误
# "a" - 附加 - 打开要附加的文件，如果不存在则创建文件
# "w" - 写入 - 打开文件进行写入，如果不存在则创建文件
# "x" - 创建 - 创建指定的文件，如果文件存在则返回错误
# 另外，您可以指定文件应以二进制还是文本模式处理
# "t" - 文本 - 默认值。文字模式
# "b" - 二进制 - 二进制模式（例如图像）


# f = open("lalala.txt", 'w')
# f.write("hello,world")
# fp = open("text.py")
# print(fp.read())  # 用read() 来读取文件内容并在终端显示

# fp1 = open("../Notes/py.md", "r", encoding="utf-8")  # 最好改成用utf8打开，不然很有可能gbk报错。
# print(fp1.read())
# fp1.close()

print()

# 文件的序列化与反序列化

# .write() 是不能写入非字符串以外的东西的，比如说list，所以这个时候要用json模块
# 对象-> 字节序列 == 序列化 字节序列-> 对象 反序列化  json的写入和提取

# 序列化 用dump 和 dumps 函数
# dumps () 转化为字符串对象 写入的话需要手动
# dump() 不需要再write 只需要
j_list = [1, 2, 3]
js = json.dumps(j_list)
print(js)

f = open("text.txt", 'w')
f.write(js)

fp = open("text.txt", 'w')
j_list1 = ["123", '\n']  # dump和dumps只能用一种，另一种会把原本的覆盖掉
json.dump(j_list1, fp)
fp = open("text.txt", 'r')


result = json.load(fp)
print(result)
print(type(result))
