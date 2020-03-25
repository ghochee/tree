add_executable(raw_tree_bm raw_tree.cpp)
target_link_libraries(raw_tree_bm PRIVATE tree benchmark pthread)
