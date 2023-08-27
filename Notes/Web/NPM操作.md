### npm install 安装模块

```C++ {.line-numbers}
读取package.json里面的配置单安装
$ npm install
//可简写成 npm i

 默认安装指定模块的最新(@latest)版本
$ npm install [<@scope>/]<name>
//eg:npm install gulp

 安装指定模块的指定版本
$ npm install [<@scope>/]<name>@<version>
//eg: npm install gulp@3.9.1

 安装指定指定版本范围内的模块
$ npm install [<@scope>/]<name>@<version range>
//eg: npm install vue@">=1.0.28 < 2.0.0"

 安装指定模块的指定标签 默认值为(@latest)
$ npm install [<@scope>/]<name>@<tag>
//eg:npm install sax@0.1.1

 通过Github代码库地址安装
$ npm install <tarball url>
//eg:npm install git://github.com/package/path.git
```

### 一、安装配置 Node 和前言

$ npm -v //6.4.0 << 安装成功会返回版本号

$ npm -l

$ npm help

$ npm config list -l

### npm set 设置环境变量

```C++ {.line-numbers}
$ npm set init-author-name 'my name jerry'
$ set init-author-email '12345@qq.com'
$ set init-author-url 'http://yourdomain.com'
$ npm set init-license 'MIT'
执行了以上的修改，此时 Package.json并没有发生变化


```

- 设置后执行 init 才是真正修改成功
  $ npm init

### npm list 查看模块

```C++ {.line-numbers}
#当前项目安装的所有模块
$npm list

#列出全局安装的模块 带上[--depth 0] 不深入到包的支点 更简洁
$ npm list -g --depth 0
```

### npm run 执行脚本

- npm run 就会告诉你有多少个包是可以执行的
  如果不加任何参数，直接运行，会列出 package.json 里面所有可以执行的脚本命令

### npm uninstall 卸载模块

卸载当前项目或全局模块
$ npm uninstall <name> [-g]

eg: npm uninstall gulp --save-dev  
 npm i gulp -g

卸载后，你可以到 /node_modules/ 目录下查看包是否还存在，或者使用以下命令查看：
npm ls 查看安装的模块
