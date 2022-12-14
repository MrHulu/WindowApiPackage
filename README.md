<div align="center">
  <h1>Windows Interface Wrapper</h1>
  <p>This project wraps some common Windows api</p>
  <p>
    I hope it can help you~
    See the table of contents for specific functions, and refer to the relevant usage<span><a href="./Test">Test the code of the directory</a></span>
  </p>
  <p>
    <h3><span>English</span>&emsp;|&emsp;<a href="./README_zh-CN.md">简体中文</a></h3>
  </p>
  <p>
    <img src="https://img.shields.io/github/license/MrHulu/WindowApiPackage" alt="license">
  </p>
</div>

## Function Introduction

- [Registry Operations](#Registry Operations)
- [System Display Infomation](#System Display Infomation)

## Registry Operations

- [Registry Search](./Src/WinReg/WinRegUtil.h "WinRegUtil")
- [Registry Modification](./Src/WinReg/WinRegUtil.h "WinRegUtil")
- [System boot, program self-start](./Src/WinReg/WinRegUtil.h. "WinRegUtil")

## System Display Infomation

<img src="./Data/images/SystemDisplayInfo.png" alt="Display">

- [Scale and layout](./Src/WinSystemInfo/WinSystemDisplayInfoUtil.h "WinSystemDisplayInfoUtil")
- [Display resolution](./Src/WinSystemInfo/WinSystemDisplayInfoUtil.h "WinSystemDisplayInfoUtil")
- [Display orientation](./Src/WinSystemInfo/WinSystemDisplayInfoUtil.h "WinSystemDisplayInfoUtil")

## Task Manager Memory

<img src="./Data/images/Memory.png" alt="Memory">
<img src="./Data/images/CPU.png" alt="CPU">

- [System Handles](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Processes](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Threads](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Cache](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Memory Usage](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Page Pool](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Physical Total Memory](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Physical Available Memory](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Virtual Total Memory](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")
- [System Virtual Available Memory](./Src/WinSystemInfo/WinSystemMemoryStatusInfoUtil.h "WinSystemMemoryStatusInfoUtil")

## Other

- [Check if the program has administrator privileges](./Src/Oter/ProgramPermissionsInfo.h "ProgramPermissionsInfo")
