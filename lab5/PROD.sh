if g++ -fsanitize=address lab5.cpp other.cpp matrix.cpp -o lab5.exe; then 
cat ./data | ./lab5.exe;
fi