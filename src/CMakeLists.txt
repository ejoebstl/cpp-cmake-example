
# We need to link library CPP files into a static lib
add_library(example-lib
    lib/regularClass.cpp
)

# Link opencv into our library (for fun)
# target_link_libraries(example-lib ${OpenCV_LIBS})

if(BUILD_APP) 
    add_executable(app app/app.cpp)
    target_link_libraries(app example-lib)
endif(BUILD_APP) 

if(BUILD_HELLO_WORLD) 
    add_executable(hello-world helloworld/helloworld.cpp)
endif(BUILD_HELLO_WORLD) 

# In case you want to add unit tests. 
# add_subdirectory(test)