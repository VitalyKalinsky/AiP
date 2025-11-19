if g++ -fsanitize=address lab6.cpp other.cpp book.cpp -o lab6.exe; then 
cat ./data | ./lab6.exe;
fi 