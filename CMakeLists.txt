cmake_minimum_required (VERSION 3.8)


project ("moc")

add_executable(cfile "masterOfC.cpp" "winpart.cpp")
target_compile_features(cfile PUBLIC cxx_std_17)
