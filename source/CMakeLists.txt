# Build
add_executable(example
 example.cpp
 )
  

# Build aufgabe2bis4
add_executable(aufgabe2bis4
  aufgabe2bis4.cpp
  )
target_link_libraries(example
  m
  )

# Build aufgabe5
add_executable(aufgabe5
  aufgabe5.cpp
  circle.cpp
  )
target_link_libraries(example
  m
  )
