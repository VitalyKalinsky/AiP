if g++ -fsanitize=address lab5.cpp other.cpp -o lab5.exe; then 
cat ./data | ./lab5.exe;
fi