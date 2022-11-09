[toc]

## 前言

- css 就是对 html 的一种设计，修饰，布局其中我认为最为重要的是布局

## 选择器

## 单位

- **px**
     px 就是 pixel 的缩写，意为像素。px 就是一张图片最小的一个点，一张位图就是千千万万的这样的点构成的，比如常常听到的电脑像素是 1024x768 的，表示的是水平方向是 1024 个像素点，垂直方向是 768 个像素点。

- **em**
  相对于父元素的大小

- **vw**
  css3 新单位，viewpoint width 的缩写，视窗宽度，**1vw 等于视窗宽度的 1%**。
  举个例子：浏览器宽度 1200px, 1 vw = 1200px/100 = 12 px。
- **vh**
  css3 新单位，viewpoint height 的缩写，视窗高度，1vh 等于视窗高度的 1%。
  举个例子：浏览器高度 900px, 1 vh = 900px/100 = 9 px。

-

-

-

-

## 字体

## 表格&边框

### table

### border

#### border-radius

表示四周的圆角边框

- **如果输入两个值实现值的位置顺序为：值 1（左上 右下）值 2（左下 右上）**
- **如果输入三个值实现值的位置顺序为：值 1（左上 ）值 2（左下 右上）值 3（右下）**
- **如果输入四个值实现值的位置顺序为：值 1（左上 ）值 2（ 右上）值 3（右下）值 4 （左下）**

- border-radius: 20px 100px 50px 50px;

- **border-radius:50%;表示圆**

## 列表

## 盒子模型

## 布局

### 开局布局

- margin 0
- padding 0
### border-sizing


### display 的种类

#### flex

- 弹性布局默认值是 将元素按行排列 而且排列的时候会预备空间
- flex-direction: row | row-reverse | column | column-reverse;将元素按行，按行反向排列。。。
- flex-wrap : nowrap | wrap | wrap-reverse; wrap 换行，从上向下排 wrap-reverse 换行，从下向上排
- 属性 描述
  display 指定 HTML 元素的盒子类型
  flex-direction 指定弹性盒子中子元素的排列方式
  flex-wrap 设置当弹性盒子的子元素超出父容器时是否换行
  flex-flow flex-direction 和 flex-wrap 两个属性的简写
- justify-content 设置弹性盒子中元素在主轴（横轴）方向上的对齐方式,也就是横向对齐，justify-content: flex-start | flex-end | center | space-between | space-around | space-evenly; 沿着开头/结尾/中间对齐
  space -between ![img](imgg/space-between.png)

#### block

- display 的默认属性是 block，也就是块级元素，可以定义宽高

#### inline

- 内联元素，如 span，<a> 等等都是内联元素，内联元素无法设置长宽高，所以想要设置下拉菜单的话，你就得强制改成 block 元素使其可以改变

align-items 设置弹性盒子中元素在侧轴（纵轴）方向上的对齐方式
align-content 修改 flex-wrap 属性的行为，类似 align-items，但不是设置子元素对齐，而是设置行对齐
order 设置弹性盒子中子元素的排列顺序
align-self 在弹性盒子的子元素上使用，用来覆盖容器的 align-items 属性
flex 设置弹性盒子中子元素如何分配空间
flex-grow 设置弹性盒子的扩展比率
flex-shrink 设置弹性盒子的收缩比率
flex-basis 设置弹性盒子伸缩基准值

### position

- 用 position 进行定位以后，元素可以通过 right left bottom top 来上下改变位置
- position 一共有 5 种 static relative absolute fixed sticky
- position 的初始值是 static

#### relative

- 最常用。会在盒子中预留特定的空间，该关键字下，元素先放置在未添加定位时的位置，再在不改变页面布局的前提下调整元素位置
  怎么理解呢，也就是说 relative 定位下，一个没有指定位移的元素，将会和其他元素保持一致，或者平行,调整该元素时，他不会影响到别的元素
  ![例](imgg/relative.png)
  进行右移
  ![](imgg/relative1.png)

#### absolute

- 绝对定位，fixed 是相对于窗口定位，不常用先不说
- 绝对定位元素，会和其他元素区分开来，不会预留空间，如果和别的元素位置重叠时会叠在元素上面。
- 例如
- ![](imgg/absolute.png)

#### sticky

- sticky 会一直定位在那个地方，下拉的时候也会跟着移动,这个在做固定菜单栏时用到
- ![](imgg/sticky.png)

## 继承

## 伪类和伪元素

- 伪类是元素有一个特定状态时（如鼠标点击），会获得特定的样式，样式改变后（如点击过后） 失去样式恢复原状的一种类型

### 所有伪类

![img](/Notes/imgg/%E4%BC%AA%E7%B1%BB.png)

- link：鼠标未点击前的样子
- visited : 鼠标点过以后 但是 a 包含了 link 和 visited
- hover 就是鼠标放上去的状态
- focus：就是输入框的时候的一些状态，比如说 text 文本框里面的背景

- :after 在指定元素后面插入内容
- 如 p:after
  content : "" url =
  font-size,color
  background:
- before 同理

- first-child = nth-child(1) 表示更改第一个子元素的样式
  如 p:first-child
- nth-child()父元素的第几个儿子

## 下拉菜单

## background 属性

- background-position:

### background-position 设置背景图片的方位来展示图片

### 设置背景透明度

- opacity 设置整体的透明度 透明度标准为 0-1.0
  opacity:1.0 表示完全不透明
  opacity:0.5 模糊一半

- backdrop-fliter 在背景背后的元素设置模糊 即毛玻璃/高斯模糊的效果。

常用用法

- **backdrop-filter: blur(2px);** 设置模糊
- backdrop-filter: brightness(60%); 亮度 这个是黑色模糊框框
- backdrop-filter: contrast(40%);棕色框框
- backdrop-filter: drop-shadow(4px 4px 10px blue);
- backdrop-filter: grayscale(30%);
- backdrop-filter: hue-rotate(120deg);
- backdrop-filter: invert(70%);
- backdrop-filter: opacity(20%);
- backdrop-filter: sepia(90%);
- backdrop-filter: saturate(80%);

/_ 全局值 _/
backdrop-filter: inherit;
backdrop-filter: initial;
backdrop-filter: revert;
backdrop-filter: unset;

## 图标 iconfont

[阿里巴巴 iconfont 库](https://www.iconfont.cn/?spm=a313x.7781069.1998910419.d4d0a486a)
**iconfont 图标是一些好看的矢量图，比如说音乐播放器的开启，暂停键等等。**

可以说是 font-awsome 的升级版，而且好用

### 引用方式

一. 以 png,svg 图片的形式引用 不推荐这种。

**二. 以 font-class 的形式引用，这种最简单**
把想要的图标全部添加进购物车，然后下载源代码，看到里面的 css 和 ttf 文件，把他放在一个文件夹里，然后在 html 里用 class 引用就好了。可以直接在 iconfont.css 里更改样式。

- **如果我们想添加单个图标的话，下载以后，把 ttf 和 css 改名字，引用就好**

```js {.line-numbers}
<link rel="stylesheet" href="iconfont/iconfont.css" />
// class 引用
<i id="voice" class="iconfont icon-shengyin_shiti"></i>
```

- 更改样式

```js {.line-numbers}
.iconfont {
  font-family: "iconfont" !important;
  font-size: 24px;
  font-style: normal;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
.iconfont:nth-child(odd):hover {
  transition: font-size 0.25s linear;
  font-size: 30px;
}
.iconfont:nth-child(even):hover {
  transition: font-size 0.25s linear;
  font-size: 30px;
}
```

- symbol 引用。
