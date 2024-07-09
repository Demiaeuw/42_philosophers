cmake_minimum_required(VERSION 3.10)
project(philosophers)

# Ajouter les fichiers source
set(SOURCES
    ${CMAKE_SOURCE_DIR}/../main.c
    ${CMAKE_SOURCE_DIR}/../srcs/00_error.c
    ${CMAKE_SOURCE_DIR}/../srcs/01_init.c
    ${CMAKE_SOURCE_DIR}/../srcs/02_free.c
    ${CMAKE_SOURCE_DIR}/../srcs/03_thread.c
    ${CMAKE_SOURCE_DIR}/../srcs/04_routine.c
    ${CMAKE_SOURCE_DIR}/../srcs/05_time.c
    ${CMAKE_SOURCE_DIR}/../srcs/10_ft_atoi.c
    ${CMAKE_SOURCE_DIR}/../srcs/11_checkint.c
    ${CMAKE_SOURCE_DIR}/../srcs/12_ft_printf.c
    ${CMAKE_SOURCE_DIR}/../srcs/13_messageprint.c
)

# Ajouter l'exécutable
add_executable(philosopher ${SOURCES})

# Lier la bibliothèque pthread
target_link_libraries(philosopher pthread)

# Ajouter les tests
enable_testing()

add_test(NAME Test1_PhilosopherDies
         COMMAND ./philosopher 1 800 200 200
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test2_NoPhilosopherDies
         COMMAND python3 ${CMAKE_SOURCE_DIR}/timeout_validator.py 20 ./philosopher 5 800 200 200
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test3_NoPhilosopherDies_7Meals
         COMMAND ./philosopher 5 800 200 200 7
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test4_NoPhilosopherDies
         COMMAND python3 ${CMAKE_SOURCE_DIR}/timeout_validator.py 20 ./philosopher 4 410 200 200
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test5_OnePhilosopherDies
         COMMAND ./philosopher 4 310 200 100
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME MemoryLeakTest1
         COMMAND python3 ${CMAKE_SOURCE_DIR}/check_valgrind.py valgrind --leak-check=full ./philosopher 5 800 200 200 10
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME MemoryLeakTest2
         COMMAND python3 ${CMAKE_SOURCE_DIR}/check_valgrind.py valgrind --leak-check=full ./philosopher 4 310 200 100 
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME DataRaceTest1
         COMMAND valgrind --tool=helgrind ./philosopher 5 800 200 200 10 
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME DataRaceTest2
         COMMAND valgrind --tool=helgrind ./philosopher 4 310 200 100
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
