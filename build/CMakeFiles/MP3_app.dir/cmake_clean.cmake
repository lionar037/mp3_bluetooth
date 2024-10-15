file(REMOVE_RECURSE
  "../bin/MP3_app"
  "../bin/MP3_app.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/MP3_app.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
