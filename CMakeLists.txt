PROJECT(Bingo)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
# Indicamos la versión mínima que necesitamos de CMake

SET(INCLUDES_DIR "/")
SET(CMAKE_CXX_STANDARD 11)
# Creamos variable
FILE(GLOB SRC_CODE "*.cpp")

INCLUDE_DIRECTORIES(${INCLUDES_DIR})
ADD_EXECUTABLE(Bingo ${SRC_CODE})

# Se creará un ejecutable llamado MiProyecto en Linux o MiProyecto.exe en Windows.
# Se hace referencia a las variables con ${NOMBRE_VARIABLE}.

