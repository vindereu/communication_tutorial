# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "state_machine: 0 messages, 1 services")

set(MSG_I_FLAGS "")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(state_machine_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" NAME_WE)
add_custom_target(_state_machine_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "state_machine" "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(state_machine
  "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
)

### Generating Module File
_generate_module_cpp(state_machine
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(state_machine_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" NAME_WE)
add_dependencies(state_machine_generate_messages_cpp _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_gencpp)
add_dependencies(state_machine_gencpp state_machine_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(state_machine
  "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/state_machine
)

### Generating Module File
_generate_module_eus(state_machine
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(state_machine_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" NAME_WE)
add_dependencies(state_machine_generate_messages_eus _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_geneus)
add_dependencies(state_machine_geneus state_machine_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(state_machine
  "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
)

### Generating Module File
_generate_module_lisp(state_machine
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(state_machine_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" NAME_WE)
add_dependencies(state_machine_generate_messages_lisp _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_genlisp)
add_dependencies(state_machine_genlisp state_machine_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(state_machine
  "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/state_machine
)

### Generating Module File
_generate_module_nodejs(state_machine
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(state_machine_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" NAME_WE)
add_dependencies(state_machine_generate_messages_nodejs _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_gennodejs)
add_dependencies(state_machine_gennodejs state_machine_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(state_machine
  "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
)

### Generating Module File
_generate_module_py(state_machine
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(state_machine_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/van/workspace/commute_ws/src/state_machine/srv/Command.srv" NAME_WE)
add_dependencies(state_machine_generate_messages_py _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_genpy)
add_dependencies(state_machine_genpy state_machine_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/state_machine)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/state_machine
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/state_machine)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/state_machine
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
