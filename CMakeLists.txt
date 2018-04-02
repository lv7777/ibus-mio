set(IME_NAME mio)
cmake_minimum_required(VERSION 2.6)
project(ibus-${IME_NAME})
set(CMAKE_CXX_FLAGS "-Wall -DIME_NAME='\"${IME_NAME}\"'")
message("----------- project name is ibus-${IME_NAME} -----------")

add_executable(ibus-setup-${IME_NAME} gtktes.c)
add_executable(ibus-${IME_NAME} levena.cpp configloader.cpp)
target_link_libraries(ibus-${IME_NAME} jansson)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 gtk+-2.0 REQUIRED)
include_directories(${GTK2_INCLUDE_DIRS})
target_link_libraries(ibus-setup-${IME_NAME} ${GTK2_LIBRARIES})

pkg_check_modules(IBUS1 ibus-1.0 REQUIRED)
include_directories(${IBUS1_INCLUDE_DIRS})
target_link_libraries(ibus-${IME_NAME} ${IBUS1_LIBRARIES})
message("project binary dir is ${PROJECT_BINARY_DIR}")

add_custom_target(run ALL
    cp -r ${PROJECT_SOURCE_DIR}/levena.xml ${PROJECT_BINARY_DIR}
    COMMAND echo "configure ibus xml files for ${IME_NAME}"
    COMMAND sed -i".org" -e \"s/levena/${IME_NAME}/\" levena.xml
    COMMAND sed -i".org" -e \"s/Levena/${IME_NAME}/\" levena.xml
)

ADD_CUSTOM_TARGET(settingbuild
    cp -r ${PROJECT_SOURCE_DIR}/settings ${PROJECT_BINARY_DIR}
    COMMAND cd ${PROJECT_BINARY_DIR}/settings
    COMMAND cd settings && echo "cur dir is `pwd`"
    COMMAND cd settings && sed -i".org" -e \"s/\\\([\\\"\\']name[\\\"\\']\\s*:\\s*[\\\"\\']ibus-setup-\\\).*\\\([\\\"\\']\\\)/\\1${IME_NAME}\\2/\" package.json
    COMMAND cd settings && npm install
    COMMAND cd settings && npm install -g electron-package
    COMMAND cd settings && sudo electron-packager .
    COMMAND cd settings && npm test
    COMMAND cd settings && ln -s /ibus-setup-${IME_NAME}-linux-x64/ibus-setup-${IME_NAME} /usr/libexec/ibus-setup-${IME_NAME}
)

install(FILES levena.jpg DESTINATION /usr/share/ibus/component/ RENAME ibus-${IME_NAME}.jpg)
install(FILES levena.xml DESTINATION /usr/share/ibus/component/ RENAME ${IME_NAME}.xml)
install(FILES mio-config.json DESTINATION ${PROJECT_BINARY_DIR} RENAME ${IME_NAME}-config.json)

install(FILES ${PROJECT_BINARY_DIR}/ibus-${IME_NAME} DESTINATION /usr/libexec RENAME ibus-engine-${IME_NAME})