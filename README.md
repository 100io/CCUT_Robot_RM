# 💡CCUT RoboMaster 步兵代码
> 这个项目 forked from bakend666/CCUT_Robot_RM，原作者为 [李伟豪](https://github.com/bakend666)。

使用 STM32CubeMX 工具生成的 RoboMaster-C型 （STM32F407IGT6）的工程文件。[项目工程文件结构](./proj_tree.md)

## 一、环境依赖
STM32CubeMX + VSCode + Arm GCC + OpenOCD 开发。

- STM32CubeMX: 图形化配置生成代码
- VSCode: 编辑器
- Arm GCC: 编译器工具链
- OpenOCD: 调试、烧录工具

以下为设置示例，可依据个人电脑实际情况动态调整：
1. 为 `Arm GCC Toolchain` 添加环境变量

```powershell
# 变量名：ARM_GCC_HOME
# 变量值（依据实际路径修改）：D:\prebuilt\arm-gnu-toolchain
# PATH 项: %ARM_GCC_HOME%\bin
# 验证方式（下列三种方式任选其一）:
ls ${env:ARM_GCC_HOME}\bin\arm-none-eabi-gcc.exe
arm-none-eabi-gcc --version
cmd /C where arm-none-eabi-gcc
```

2. 为 `OpenOCD` 添加环境变量
```powershell
# 变量名：OPENOCD_HOME
# 变量值（依据实际路径修改）：D:\prebuilt\openocd
# PATH 项: %OPENOCD_HOME%\bin
# 验证方式（下列三种方式任选其一）:
ls ${env:OPENOCD_HOME}\bin\openocd.exe
openocd --version
cmd /C where openocd

```

3. Windows 若没有安装 make 工具，请安装，并将其添加到环境变量中。
```powershell
# 复制一份 mingw32-make 改名为 make.exe 
mv mingw32-make.exe make.exe

# 验证方式:
make --version
cmd /C where make

# 使用示例
mingw32-make -j16
make -j16

```

## 二、构建工程
powershell 命令行方式示例：
```powershell
# 1. 编译链接
mingw32-make -j16

# 2. 烧录固件
openocd -f "${env:OPENOCD_HOME}/share/openocd/scripts/interface/stlink.cfg" -f "${env:OPENOCD_HOME}/share/openocd/scripts/target/stm32f4x.cfg" -c "program build/CCUT_Robot_V1.0.hex verify reset exit"

```



## 三、参考文献
📕 作者 [李伟豪](https://github.com/bakend666) 仓库 [CCUT RoboMaster 步兵代码]("https://github.com/bakend666/CCUT_Robot_RM") `master branch` 的 [`Readme.md`]("./Readme.old.md") .
