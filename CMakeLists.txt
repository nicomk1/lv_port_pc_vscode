cmake_minimum_required(VERSION 3.12)
project(lvgl_pc_simulator C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# On vide la fonction install pour neutraliser les bugs de LVGL
macro(install)
endmacro()

# CRUCIAL POUR LVGL V9 : Indiquer explicitement le chemin du fichier lv_conf.h
set(LV_CONF_PATH "${PROJECT_SOURCE_DIR}/lv_conf.h" CACHE STRING "" FORCE)

# Inclusion de LVGL
add_subdirectory(lvgl)
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})

# Recherche de SDL2 pour ouvrir la fenêtre graphique
find_package(SDL2 REQUIRED)

# Liste de tous tes fichiers SquareLine
file(GLOB_RECURSE SOURCES src/*.c src/*.cpp)

# Création de l'application
add_executable(main ${SOURCES})

# Liaison des dossiers et des moteurs graphiques
target_include_directories(main PRIVATE src)
target_link_libraries(main PRIVATE lvgl SDL2::SDL2)

# Force l'inclusion de lv_conf.h dans tous les fichiers compilés
target_compile_options(main PRIVATE -include ${PROJECT_SOURCE_DIR}/lv_conf.h)
target_compile_options(lvgl PRIVATE -include ${PROJECT_SOURCE_DIR}/lv_conf.h)
