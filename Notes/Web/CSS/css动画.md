## transition
- 四个属性 
transition-property 目前的水平只能用到all 全过渡
transition-duration 顾名思义持续时间
transition-timing-function 
transition-delay 延迟变形的时间

### transition-timing-function 





## animation
- 六个属性
animation-name	规定需要绑定到选择器的 keyframe 名称。。
animation-duration	规定完成动画所花费的时间，以秒或毫秒计。
animation-timing-function	规定动画的速度曲线。
animation-delay	规定在动画开始之前的延迟。
animation-iteration-count	规定动画应该播放的次数。
animation-direction	规定是否应该轮流反向播放动画。

- 一般来说用到的就是，持续时间和keyframe这个才是关键


## transform
translateX(x)	定义转换，只是用 X 轴的值。	改变x的长短
translateY(y)	定义转换，只是用 Y 轴的值。	改变y的长短
translateZ(z)	定义 3D 转换，只是用 Z 轴的值。	
scale(x,y)	定义 2D 缩放转换。	测试
scale3d(x,y,z)	定义 3D 缩放转换。	
scaleX(x)	通过设置 X 轴的值来定义缩放转换。	延伸x
scaleY(y)	通过设置 Y 轴的值来定义缩放转换。 延伸y
scaleZ(z)	通过设置 Z 轴的值来定义 3D 缩放转换。	
rotate(angle)	定义 2D 旋转，在参数中规定角度。	测试
rotate3d(x,y,z,angle)	定义 3D 旋转。	
rotateX(angle)	定义沿着 X 轴的 3D 旋转。	
rotateY(angle)	定义沿着 Y 轴的 3D 旋转。	
rotateZ(angle)	定义沿着 Z 轴的 3D 旋转。


## 伪类
- 常见的伪类就有::before ::after ::hover等等
### before
可以理解为直接在元素前插入一个元素，after同理