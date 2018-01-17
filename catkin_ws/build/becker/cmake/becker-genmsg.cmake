# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "becker: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ibecker:/home/pi/catkin_ws/src/becker/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(becker_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg" NAME_WE)
add_custom_target(_becker_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "becker" "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg" ""
)

get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/imumsg.msg" NAME_WE)
add_custom_target(_becker_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "becker" "/home/pi/catkin_ws/src/becker/msg/imumsg.msg" ""
)

get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/controlmv.msg" NAME_WE)
add_custom_target(_becker_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "becker" "/home/pi/catkin_ws/src/becker/msg/controlmv.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(becker
  "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/becker
)
_generate_msg_cpp(becker
  "/home/pi/catkin_ws/src/becker/msg/controlmv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/becker
)
_generate_msg_cpp(becker
  "/home/pi/catkin_ws/src/becker/msg/imumsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/becker
)

### Generating Services

### Generating Module File
_generate_module_cpp(becker
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/becker
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(becker_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(becker_generate_messages becker_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg" NAME_WE)
add_dependencies(becker_generate_messages_cpp _becker_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/imumsg.msg" NAME_WE)
add_dependencies(becker_generate_messages_cpp _becker_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/controlmv.msg" NAME_WE)
add_dependencies(becker_generate_messages_cpp _becker_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(becker_gencpp)
add_dependencies(becker_gencpp becker_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS becker_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(becker
  "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/becker
)
_generate_msg_lisp(becker
  "/home/pi/catkin_ws/src/becker/msg/controlmv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/becker
)
_generate_msg_lisp(becker
  "/home/pi/catkin_ws/src/becker/msg/imumsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/becker
)

### Generating Services

### Generating Module File
_generate_module_lisp(becker
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/becker
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(becker_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(becker_generate_messages becker_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg" NAME_WE)
add_dependencies(becker_generate_messages_lisp _becker_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/imumsg.msg" NAME_WE)
add_dependencies(becker_generate_messages_lisp _becker_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/controlmv.msg" NAME_WE)
add_dependencies(becker_generate_messages_lisp _becker_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(becker_genlisp)
add_dependencies(becker_genlisp becker_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS becker_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(becker
  "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker
)
_generate_msg_py(becker
  "/home/pi/catkin_ws/src/becker/msg/controlmv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker
)
_generate_msg_py(becker
  "/home/pi/catkin_ws/src/becker/msg/imumsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker
)

### Generating Services

### Generating Module File
_generate_module_py(becker
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(becker_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(becker_generate_messages becker_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/wheelpos.msg" NAME_WE)
add_dependencies(becker_generate_messages_py _becker_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/imumsg.msg" NAME_WE)
add_dependencies(becker_generate_messages_py _becker_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/catkin_ws/src/becker/msg/controlmv.msg" NAME_WE)
add_dependencies(becker_generate_messages_py _becker_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(becker_genpy)
add_dependencies(becker_genpy becker_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS becker_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/becker)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/becker
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(becker_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/becker)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/becker
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(becker_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/becker
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(becker_generate_messages_py std_msgs_generate_messages_py)
endif()
