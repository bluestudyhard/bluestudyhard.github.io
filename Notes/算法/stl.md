# STL

- 因为经常会忘记一些用法，所以感觉必须要再记记了 orz，记最常见的就欧克

## vector

- 删除元素

其实本质就是对迭代器的理解，他是根据迭代器来要求删除哪个部分的元素的

```C++ {.line-numbers}
numbers.erase(numbers.begin(),numbers.begin()+1);// 这个表示的是删除第x个开始到第几个的元素，比如这个是第一个元素
numbers.erase(numbers.begin()+1,numbers.begin()+2);// 删除第1到第二个元素
numbers.pop_back(); // 删除vector末尾的元素
numbers.erase(numbers.begin() + 2); // 删除vector中的第三个元素
kk.erase(kk.begin(), kk.end());// 清空
```

- 创建和遍历

```C++ {.line-numbers}
vector<int> numbers; // 创建一个空的整数类型vector
vector<string> names(10); // 创建一个包含10个空字符串的字符串类型vector
for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << endl;
}

for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
    cout << *it << endl;
}

```

- 访问元素

```C++ {.line-numbers}
int num = numbers[0]; // 访问vector中的第一个元素
int num2 = numbers.at(1); // 访问vector中的第二个元素

```

- 插入

```C++ {.line-numbers}
numbers.push_back(5); // 在vector末尾插入一个整数5
numbers.insert(numbers.begin() + 2, 10); // 在vector的第三个位置插入一个整数10

```

- 创建二维数组
  使用 vector 的嵌套来实现

```C++ {.line-numbers}
vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
```

- 遍历二维数组

```C++ {.line-numbers}
// way1
   vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
// using auto
    for (auto i : arr)
    {
        for (auto j : i)
            cout << j << " ";
    cout << endl;
    }
```

## string

- 字符串转换

```C++ {.line-numbers}
string str("123");
int num = stoi(str); // 将字符串转换为整数
float f = stof(str); // 将字符串转换为浮点数
string str2 = to_string(num); // 将整数转换为字符串
```

- 字符串查找
  find 返回的是字符串在字符串中的位置,存在即返回下标，不存在即返回 0

```C++ {.line-numbers}

```

- 查找第一个出现的子串的下标

```C++ {.line-numbers}
string s = "helloworld";
    int pos = s.find_first_of('1');// -1
    int pos1 = s.find_first_of('w');// 5
    cout << pos << endl;
    cout << pos1 << endl;
```

- 字符串替换

```C++ {.line-numbers}

```

- 删除元素

```C++ {.line-numbers}
str = "hello world";
	// 从str.begin()+2地方开始删除两个字符
	str.erase(str.begin() + 2, str.begin() + 4);
	cout << str << endl;
```

- 使用 reverse 函数逆置字符串

```C++ {.line-numbers}
reverse(s.begin(),s.end());
```

- 创建字符串对象

```C++ {.line-numbers}
string str1; // 创建一个空字符串
string str2("hello"); // 创建一个包含"hello"的字符串
string str3(str2); // 创建一个与str2相同的字符串
string str4(5, 'a'); // 创建一个包含5个'a'的字符串
```

- 访问字符串的元素

```C++ {.line-numbers}

char ch = str[0]; // 获取字符串中索引为 0 的字符
char ch2 = str.at(1); // 获取字符串中索引为 1 的字符
```

## set

## map

## priority_queue
