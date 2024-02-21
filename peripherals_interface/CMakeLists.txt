set(target_name peripherals_interface)

add_library(${target_name}
             INTERFACE
             )

         target_include_directories(${target_name} INTERFACE .)
