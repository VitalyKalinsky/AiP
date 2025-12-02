if g++ -fsanitize=address book.cpp library.cpp ui.cpp lab6.cpp categories.cpp -o library_app; then 
cat ./data | ./library_app;
fi 