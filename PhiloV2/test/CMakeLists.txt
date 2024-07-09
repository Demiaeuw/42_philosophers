cmake_minimum_required(VERSION 3.10)
project(philosophers)

# Trouver tous les fichiers source dans le répertoire parent et les ajouter à la liste SOURCES
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/../*.c")

# Exclure les fichiers de test et les fichiers temporaires générés par CMake
list(FILTER SOURCES EXCLUDE REGEX "(${CMAKE_SOURCE_DIR}/CMakeFiles/|${CMAKE_SOURCE_DIR}/../test/|/CMakeCCompilerId.c|\\.o)")

# Définir le nom de l'exécutable
set(EXECUTABLE_NAME philosopher)

# Ajouter l'exécutable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Lier la bibliothèque pthread
target_link_libraries(${EXECUTABLE_NAME} pthread)

# Ajouter les tests
enable_testing()

add_test(NAME Test1_PhilosopherDies
         COMMAND ./${EXECUTABLE_NAME} 1 800 200 200
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test2_NoPhilosopherDies
         COMMAND python3 ${CMAKE_SOURCE_DIR}/timeout_validator.py 20 ./${EXECUTABLE_NAME} 5 800 200 200
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test3_NoPhilosopherDies_7Meals
         COMMAND ./${EXECUTABLE_NAME} 5 800 200 200 7
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test4_NoPhilosopherDies
         COMMAND python3 ${CMAKE_SOURCE_DIR}/timeout_validator.py 20 ./${EXECUTABLE_NAME} 4 410 200 200
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME Test5_OnePhilosopherDies
         COMMAND ./${EXECUTABLE_NAME} 4 310 200 100
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME MemoryLeakTest1
         COMMAND python3 ${CMAKE_SOURCE_DIR}/check_valgrind.py valgrind --leak-check=full ./${EXECUTABLE_NAME} 5 800 200 200 10
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME MemoryLeakTest2
         COMMAND python3 ${CMAKE_SOURCE_DIR}/check_valgrind.py valgrind --leak-check=full ./${EXECUTABLE_NAME} 4 310 200 100
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME DataRaceTest1
         COMMAND valgrind --tool=helgrind ./${EXECUTABLE_NAME} 5 800 200 200 10
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME DataRaceTest2
         COMMAND valgrind --tool=helgrind ./${EXECUTABLE_NAME} 4 310 200 100
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
