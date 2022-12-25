## YAML 简介

- YAML 是 "YAML Ain't a Markup Language"（YAML 不是一种标记语言）的递归缩写。在开发的这种语言时，YAML 的意思其实是："Yet Another Markup Language"（仍是一种标记语言）。
  YAML 的语法和其他高级语言类似，并且可以简单表达清单、散列表，标量等数据形态。它使用空白符号缩进和大量依赖外观的特色，特别适合用来表达或编辑数据结构、各种配置文件、倾印调试内容、文件大纲（例如：许多电子邮件标题格式和 YAML 非常接近）。

YAML 的配置文件后缀为 .yml，如：runoob.yml 。

- 人话来说，yaml 的语法简洁直观，一般都用于配置文件
- yaml 的优点有字符串不需要引号，对象用缩进来表示(like py)，换行方便，还有锚点什么的，可能这就是为什么流行的原因吧。

## 基本语法

[详情](https://zhuanlan.zhihu.com/p/145173920)

### 用#号注释

```js {.line-numbers}
blue:
  #a name which is your master's;
```

### 大小写敏感

rt

```
One:1
one:2
```

### 用缩进表示层级关系

缩进不允许使用 tab，只允许空格
缩进的空格数不重要，只要相同层级的元素左对齐即可
一般都两个空格

- yaml

```js {.line-numbers}
home_article:
  # Show category in home page article block.
  category:
    enable: true # Option values: true | false
    limit: 3       # Max number of categories shown in home page article block
  # Show tags in home page article block.
```

- Json

```js {.line-numbers}
home_article: {
  enable: true;
  limit: 3;
}
```

## 数据结构与类型

### 键值对

yaml 和 json 一样就是键值对的形式来表示数据，然后多级数据也是和 py 一样采用缩进来嵌套
yaml：

```js {.line-numbers}
one:
   two:
   three:
     four:
```

json:

```js {.line-numbers}
one:{
    two:
    three:{
        four:
    }
}
```

### 字符串

yaml 的字符串不需要加引号，当然如果要转移的话就要加引号
字符串一般不需要用引号包裹，但是如果字符串中使用了反斜杠“\”开头的转义字符就必须使用引号包裹

```js {.line-numbers}
url:https://www.blue.top/
```

### 锚点和引用

### 换行符

- 两种方式
- 保留换行
  一种是用 **|** 使用竖线符“ | ”来表示该语法，每行的缩进和行尾空白都会被去掉，而额外的缩进会被保留，回车表示换行

  ```js {.line-numbers}
    blue:|
    我是第一行
    我是第二行
      我是第三行
  ```

- 折叠换行(Newlines folded)

使用右尖括号“ > ”来表示该语法，只有空白行才会被识别为换行，原来的换行符都会被转换成空格

```js {.line-numbers}
# YAML
lines: >
  我是第一行
  我也是第一行
  我仍是第一行
  我依旧是第一行

  我是第二行
  这么巧我也是第二行

// JSON
"lines": "我是第一行 我也是第一行 我仍是第一行 我依旧是第一行\n我是第二行 这么巧我也是第二行"
```

### 数组（Sequence）

- 一组以区块格式（Block Format）（即“破折号+空格”）开头的数据组成一个数组

```js {.line-numbers}
#yaml
values: -value1 - value2 - value3;
// JSON
"values": [ "value1", "value2", "value3" ]
```

### 布尔值

- “true”、“True”、“TRUE”、“yes”、“Yes”和“YES”皆为真
- “false”、“False”、“FALSE”、“no”、“No”和“NO”皆为假

## js 如何转换 YAML 文件

- 先码着
  [this](https://blog.csdn.net/subfate/article/details/111994745)
