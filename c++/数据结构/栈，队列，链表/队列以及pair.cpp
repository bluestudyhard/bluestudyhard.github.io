/*
一 pair pair 本质就是一个结构体，可以把两个数据，放在一起，也可以理解为容器的一种。
pair 的定义 pair <***,***> 如 pair <string,int> name;
pair<string, string> anon; // 创建一个空对象anon，两个元素类型都是string
pair<string, int> word_count;     // 创建一个空对象 word_count, 两个元素类型分别是string和int类型
pair<string, vector<int> > line;  // 创建一个空对象line，两个元素类型分别是string和vector类型
pair 的赋值 因为pair 只有两个成员，所以，分为first 和second
赋值时，像函数那样 xx.first = xxx; 也可以直接赋值
pair<string , int > k("boy","18");
make_pair(v1, v2);以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
make_pair<xxx,xxx> 可以直接建立一个新的pair对象，相当于，直接赋值再建立一个新pair
例：
pair<string,int> k;
string s= "boy";
int a = 18;
newone = make_pair<s,a>;
cout<<newone.first<<newone.second;//boy 18
/*
队列 和栈大致相同，不过他遵循的是先进先出原则。思路，很多题都是以循环数组的形式
这样出现的，像圆圈那样的。
定义：queue<int> name;可以放字符串，int queue<string>
出队列用 front(); 其他都和栈一致
size()返回的是队列元素的大小.