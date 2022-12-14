

<div align="center">
  <h1>Windows接口封装包</h1>
  <p>本项目封装了一些 Windows 常见的 api</p>
  <p>
    希望能帮到大家~
    具体功能看目录，相关用法可以参考<span><a href="./Test">测试目录的代码</a></span>
  </p>
  <p>
    <h3><a href="./README.md">English</a>&emsp;|&emsp;<span>简体中文</span></h3>
  </p>
  <p>
    <img src="https://img.shields.io/github/license/MrHulu/WindowApiPackage" alt="license">
  </p>
</div>

## 功能介绍

- [注册表操作](#注册表操作)
- [系统显示信息](#系统显示信息)

## 注册表操作

- [注册表查询](./Src/WinReg/WinRegUtil.h "WinRegUtil")
- [注册表修改](./Src/WinReg/WinRegUtil.h "WinRegUtil")
- [系统开机, 程序自启动](./Src/WinReg/WinRegUtil.h. "WinRegUtil")

## 系统显示信息

<img src="./Data/images/SystemDisplayInfo_zh-CN.png" alt="显示">

- [缩放与布局](./Src/WinSystemInfo/WinSystemDisplayInfoUtil.h "WinSystemDisplayInfoUtil")
- [显示分辨率](./Src/WinSystemInfo/WinSystemDisplayInfoUtil.h "WinSystemDisplayInfoUtil")
- [显示方向](./Src/WinSystemInfo/WinSystemDisplayInfoUtil.h "WinSystemDisplayInfoUtil")

## 任务管理器内存信息

<img src="./Data/images/Memory_zh-CN.png" alt="内存">
<img src="./Data/images/CPU_zh-CN.png" alt="CPU">

- [系统句柄数量](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统进程数量](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统线程数量](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统缓存内存](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统内存使用率](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [分页内核池内存](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统物理总内存](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统物理可用内存](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统虚拟总内存](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [系统虚拟可用内存](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")

## 其他

- [检测程序是否有管理员权限](./Src/Oter/ProgramPermissionsInfo.h "ProgramPermissionsInfo")

