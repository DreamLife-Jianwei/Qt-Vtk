![background](https://raw.githubusercontent.com/DreamLife-Jianwei/CSDNResources/master/20210709155203.png)

# Qt-Vtk

[toc]

## 1 文件夹介绍索引：

### 1.1 01_FirstVtk

> 这是Qt与Vtk结合的第一个项目，仅仅调通了在Qt中使用Vtk，包括头文件库包含和库文件包含，以及配置了C11支持。

### 1.2 02_SecondVtk

> 使用了**QVTKWidget**在Qt框架下实现了PNG Jpg bmp dicom格式图片显示和一个立体的Cube，Cube在后面还会再次出现。

### 1.3 03_ThirdVtk

> 跟新到目前的最大的超级工程，实现了多个VTK原生示例在Qt中的横展，同时为了在家和公司均可以对代码进行编译，方便在家也可以学习，对整个项目工程进行了去**绝对路径**处理，方便编译。

> 1.0版本视频演示地址：https://www.bilibili.com/video/BV1dw411o7ir/

> 2.0版本中将实现医学生的四视图。并在从这里开始，Qt版本升级为5.14.2 ，因为在5.7.1 中有个paintevent绘制背景的问题，我暂时解决不了，在我这里理解为Qt的Bug了，所以升级了Qt，VS的版本是VS2015 和2017 两个版本，公司基本用2015，家里用2017。

### 1.4 04_Document

> 参考数据，包括火灵的那本小红书，还有几个是我从其他地方收集的，就让他在我的文件夹里面吃灰吧，但愿对你比较有用。

### 1.5 05_DemoVideo

> 演示视频，没啥屁用，后面会在传导B站上，哈哈哈。

### 1.6 06_ReferenceCode

> 参考代码，这个名称是用有道翻译的，如果不正确，你们去找网易去哈。

### 1.7 07_CTImage

> 没啥好说的，就是测试用的CT数据

### 1.8 08_VTK-8.2.0源码+可执行文件+VS2015编译工程

> 就是和文件夹名称一样，包含VTK8.2.源码，CMake处理过的编译文件和编译好的文件
>
> Bin：编译好的文件
>
> Build：待编译文件
>
> VTK-8.2.0：VTK源码
>
> VTK-8.2.0.rar：原生代码

### 1.9 09_Demo

> 演示程序，欢迎体验

## 1.10 10_VTK9.0.3源码+2017编译文件+运行库

> 编译好的Vtk9.0.3库文件、源码和2017工程文件

## 1.11 11_QtVtk9ReadDicomDemo

> Qt下使用Cmake结合Vtk9.0.3 读取Dicom文件示例，暂时还未实现。









---

![博客签名2021](https://img-blog.csdnimg.cn/20210314131118350.gif#pic_center)
