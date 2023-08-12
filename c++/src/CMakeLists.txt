add_executable(hello_world hello_world.cpp)

add_executable(basic_adder basic_adder.cpp)
target_link_libraries(
    basic_adder
    PRIVATE
        CLI11::CLI11
    )

add_executable(file_operations ./file_operations.cpp)

add_executable(string_operations ./string_operations.cpp)
