# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "send_then_result: 1 messages, 0 services")

set(MSG_I_FLAGS "-Isend_then_result:/home/van/workspace/commute_ws/src/send_then_result/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(send_then_result_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" NAME_WE)
add_custom_target(_send_then_result_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "send_then_result" "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(send_then_result
  "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/send_then_result
)

### Generating Services

### Generating Module File
_generate_module_cpp(send_then_result
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/send_then_result
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(send_then_result_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(send_then_result_generate_messages send_then_result_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" NAME_WE)
add_dependencies(send_then_result_generate_messages_cpp _send_then_result_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(send_then_result_gencpp)
add_dependencies(send_then_result_gencpp send_then_result_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS send_then_result_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(send_then_result
  "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/send_then_result
)

### Generating Services

### Generating Module File
_generate_module_eus(send_then_result
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/send_then_result
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(send_then_result_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(send_then_result_generate_messages send_then_result_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" NAME_WE)
add_dependencies(send_then_result_generate_messages_eus _send_then_result_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(send_then_result_geneus)
add_dependencies(send_then_result_geneus send_then_result_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS send_then_result_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(send_then_result
  "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/send_then_result
)

### Generating Services

### Generating Module File
_generate_module_lisp(send_then_result
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/send_then_result
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(send_then_result_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(send_then_result_generate_messages send_then_result_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" NAME_WE)
add_dependencies(send_then_result_generate_messages_lisp _send_then_result_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(send_then_result_genlisp)
add_dependencies(send_then_result_genlisp send_then_result_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS send_then_result_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(send_then_result
  "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/send_then_result
)

### Generating Services

### Generating Module File
_generate_module_nodejs(send_then_result
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/send_then_result
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(send_then_result_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(send_then_result_generate_messages send_then_result_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" NAME_WE)
add_dependencies(send_then_result_generate_messages_nodejs _send_then_result_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(send_then_result_gennodejs)
add_dependencies(send_then_result_gennodejs send_then_result_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS send_then_result_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(send_then_result
  "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/send_then_result
)

### Generating Services

### Generating Module File
_generate_module_py(send_then_result
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/send_then_result
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(send_then_result_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(send_then_result_generate_messages send_then_result_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/send_then_result/msg/Arithmetic.msg" NAME_WE)
add_dependencies(send_then_result_generate_messages_py _send_then_result_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(send_then_result_genpy)
add_dependencies(send_then_result_genpy send_then_result_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS send_then_result_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/send_then_result)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/send_then_result
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/send_then_result)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/send_then_result
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/send_then_result)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/send_then_result
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/send_then_result)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/send_then_result
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/send_then_result)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/send_then_result\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/send_then_result
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
