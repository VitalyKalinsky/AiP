double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double division(double a, double b);
void print_int(void *a);
void print_double(void *a);
void print_str(void *a);
void print_array(char *pcFirst, const int arrSize, int typeSize, void (*type_print)(void *));
// Прототипы используемых в данном задании функций:
void sort(char *pcFirst, int nNumber, int size,
          void (*Swap)(void *, void *), int (*Compare)(void *, void *));

void swap_int(void *p1, void *p2);
int cmp_int(void *p1, void *p2);
void swap_double(void *p1, void *p2);
int cmp_double(void *p1, void *p2);
void swap_str(void *p1, void *p2);
int cmp_str(void *p1, void *p2);