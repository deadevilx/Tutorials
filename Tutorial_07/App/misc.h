#ifndef _MISC_H
#define _MISC_H

#include <cstring>
#include <string>

extern void echo_cstring(char *str);
extern void echo_string(std::string str);
extern char *concat_cstrings(char *str_1, char *str_2);
extern std::string concat_strings(std::string str_1, std::string str_2);
extern int find_cstrings(char *str_1, char *str_2);
extern int find_strings(std::string str_1, std::string str_2);

#endif
