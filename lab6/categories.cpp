#include "categories.h"
#include <cstring>
#include <iostream>
#include <cstdio>

CategoriesList* create_categories_list()
{
    CategoriesList *list = new CategoriesList();
    list->capacity = 10;
    list->count = 0;
    list->categories = new char*[list->capacity];
    
    for (int i = 0; i < list->capacity; i++) {
        list->categories[i] = nullptr;
    }
    add_category(list, "manga");
    add_category(list, "fairy tail");
    add_category(list, "romance");
    add_category(list, "dota rap");
    return list;
}

void free_categories_list(CategoriesList *list)
{
    if (!list) return;
    
    for (int i = 0; i < list->count; i++) {
        if (list->categories[i]) {
            delete[] list->categories[i];
        }
    }

    delete[] list->categories;
    delete list;
}

void ensure_categories_capacity(CategoriesList *list)
{
    if (list->count >= list->capacity) {
        int new_capacity = list->capacity * 1.5 + 1;
        char **new_categories = new char*[new_capacity];
        
        for (int i = 0; i < list->count; i++) {
            new_categories[i] = list->categories[i];
        }
        
        for (int i = list->count; i < new_capacity; i++) {
            new_categories[i] = nullptr;
        }
        
        delete[] list->categories;
        list->categories = new_categories;
        list->capacity = new_capacity;
    }
}

void add_category(CategoriesList *list, const char *category)
{
    for (int i = 0; i < list->count; i++) {
        if (strcasecmp(list->categories[i], category) == 0) {
            return;
        }
    }
    
    ensure_categories_capacity(list);
    
    char *new_category = new char[strlen(category) + 1];
    strcpy(new_category, category);
    
    list->categories[list->count] = new_category;
    list->count++;
}

void print_categories(const CategoriesList *list)
{   printf("(");
    for (int i = 0; i < list->count; i++) {
        printf("%s%s", list->categories[i], ((i == list->count - 1) ? ")\n" : ", "));
    }
}

int find_category(const CategoriesList *list, const char *category)
{
    for (int i = 0; i < list->count; i++) {
        if (strcasecmp(list->categories[i], category) == 0) {
            return i;
        }
    }
    return -1;
}

const char* get_category(const CategoriesList *list, int index)
{
    if (index < 0 || index >= list->count) {
        return nullptr;
    }
    return list->categories[index];
}