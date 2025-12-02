#ifndef CATEGORIES_H
#define CATEGORIES_H

struct CategoriesList {
    char **categories;    
    int count;            
    int capacity;         
};

CategoriesList* create_categories_list();
void free_categories_list(CategoriesList *list);
void add_category(CategoriesList *list, const char *category);
void print_categories(const CategoriesList *list);
int find_category(const CategoriesList *list, const char *category);
const char* get_category(const CategoriesList *list, int index);
void ensure_categories_capacity(CategoriesList *list);

#endif