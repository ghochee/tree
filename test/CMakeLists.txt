add_executable(raw_tree_test raw_tree.cpp)
target_link_libraries(raw_tree_test PRIVATE tree CONAN_PKG::Catch2)
add_test(NAME tree_raw_tree_test COMMAND raw_tree_test)
