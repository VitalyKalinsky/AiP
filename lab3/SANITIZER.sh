if g++ -o ./lab3.exe -fsanitize=address ./lab3.cpp; then 
cat ./data | ./lab3.exe;
fi