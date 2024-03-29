cmake_minimum_required(VERSION 3.16)
project(test_programs)

option(ENABLE_CROSSCOMPILING "Cross compile the code for the arm rockchip" ON)

if(ENABLE_CROSSCOMPILING)
    # which compilers to use for C and C++
    set(CMAKE_C_COMPILER
        /home/luckfox/luckfox-pico/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc)
    set(CMAKE_CXX_COMPILER
        /home/luckfox/luckfox-pico/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-g++)
    
    # where is the target environment located
    # This expectes to use the container luckfoxtech/luckfox_pico:1.0 with mounted https://github.com/LuckfoxTECH/luckfox-pico.git. See https://wiki.luckfox.com/Luckfox-Pico/Core3566-SDK/
    set(CMAKE_FIND_ROOT_PATH  /home/luckfox/luckfox-pico/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/)
    
    # adjust the default behavior of the FIND_XXX() commands:
    # search programs in the host environment
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
    
    # search headers and libraries in the target environment
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()

add_subdirectory(peripherals_interface)
add_subdirectory(blink_gpio)
add_subdirectory(blink_pwm)
add_subdirectory(hello_world)
add_subdirectory(pwm_two_servos)
