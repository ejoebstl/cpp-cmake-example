
#add_library(optonaut-lib
#common/image.cppcommon/progressCallback.cpp
#)
#target_link_libraries(optonaut-lib ${OpenCV_LIBS})

#add_library(visual-debug-hook
#debug/visualDebugHook.cpp
#)

#target_link_libraries(visual-debug-hook ${OpenCV_LIBS})
#target_link_libraries(visual-debug-hook optonaut-lib)
#target_link_libraries(visual-debug-hook ${OPENGL_LIBRARIES})
#target_link_libraries(visual-debug-hook ${OSX_LIBS})
#target_link_libraries(visual-debug-hook ${CMAKE_CURRENT_LIST_DIR}/../vendor/libIrrlicht.a)

#if(BUILD_APP) 
#    add_executable(app app/app.cpp)
#    target_link_libraries(app example-lib)
#endif(BUILD_APP) 

if(BUILD_HELLO_WORLD) 
    add_executable(hello-world helloworld/helloworld.cpp)
endif(BUILD_HELLO_WORLD) 

#add_subdirectory(test)
