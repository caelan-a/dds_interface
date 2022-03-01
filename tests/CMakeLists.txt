list(APPEND English one two three four)
list(APPEND Bahasa satu dua tiga)

foreach(num IN LISTS English Bahasa)
    message("${num}")
endforeach()
