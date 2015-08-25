include_directories(${CtCI6Edition_SOURCE_DIR}/lib)
link_directories(${CtCI6Edition_SOURCE_DIR}/lib)

set(Matrix_DEPS $<TARGET_OBJECTS:Matrix> ${CtCI6Edition_SOURCE_DIR}/lib/Matrix.hpp)

add_executable(isUnique isUnique.cpp)
add_executable(checkPermutation checkPermutation.cpp)
add_executable(urlify urlify.cpp)
add_executable(palindromePerm palindromePerm.cpp)
add_executable(oneAway oneAway.cpp)
add_executable(strCompress strCompress.cpp)
add_executable(rotateMatrix rotateMatrix.cpp ${Matrix_DEPS})
add_executable(zeroMatrix zeroMatrix.cpp ${Matrix_DEPS})
add_executable(isRotation isRotation.cpp)
