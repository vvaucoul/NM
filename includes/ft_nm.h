/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:04:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/12 14:44:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
#define FT_NM_H

#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <stdio.h>

#include "../libft/includes/libft.h"

#define E_USAGE "usage: ./nm « binary / library »"

#define E_ENOENT "No such file"
#define E_EACCES "permission denied"
#define E_EISDIR "is a directory"
#define E_FORMAT "file format not recognized"
#define E_SYM "no symbols"
#define E_FATAL "Fatal error"
#define E_ARG "invalid argument"
#define E_CONFLICT "conflicting arguments"

#define SUCCESS 0
#define FAILURE 1

#define FLAGS_REVERSE_SORT 0
#define FLAGS_DO_NOT_SORT 1

#define NB_NM_FLAGS 2
#define NM_FLAGS                           \
    {                                      \
        "-r", "-p", NULL \
    }
#define NM_ASCII_FLAGS          \
    {                           \
        'r', 'p' \
    }

#define META_FILE_SIZE sizeof(t_meta_file)

#define SHDR_NAME(meta_data, i) (char *)(meta_data->shstr + meta_data->shdr[i].sh_name)
#define SYM_NAME(meta_data, i) (char *)(meta_data->str + meta_data->sym[i].st_name)

enum e_arch
{
    ARCH_32 = 0,
    ARCH_64 = 1
};

typedef struct s_symbol
{
    char *sym_name;
    unsigned char sym_type;
    unsigned char sym_bind;
    unsigned char sym_vis;
    size_t sym_value;
    size_t sym_size;
    unsigned short shdr_index;
    char *shdr_name;
    size_t shdr_link;
    size_t shdr_type;
    size_t shdr_flags;
} t_symbol;

typedef struct s_elf_32
{
    void *start;
    Elf32_Ehdr *ehdr;
    Elf32_Shdr *shdr;
    char *shstr;
    char *str;
    Elf32_Shdr *shdr_str;
    Elf32_Shdr *shdr_sym;
    Elf32_Sym *sym;
    size_t sym_count;
} t_elf_32;

typedef struct s_elf_64
{
    void *start;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    char *shstr;
    char *str;
    Elf64_Shdr *shdr_str;
    Elf64_Shdr *shdr_sym;
    Elf64_Sym *sym;
    size_t sym_count;
} t_elf_64;

typedef struct s_meta_file
{
    int fd;
    char *file_name;
    struct stat st;
    char *ptr;
    enum e_arch arc;
} t_meta_file;

typedef struct s_nm
{
    t_meta_file *meta_files;
    size_t meta_file_count;
    size_t nm_non_arg_count;
    bool flags[NB_NM_FLAGS];
} t_nm;

extern t_meta_file *_g_meta_file;

/*
**  META FILES
*/

int append_meta_file(t_meta_file meta_file);

/*
**  PARSER
*/

int check_arguments(size_t argc, char **argv);
int valid_argument(char *argument);

/*
**  EXECUTION
*/

int execution();
int x64_execution(t_meta_file *meta_file);
int setup_x64_meta_data(t_elf_64 **x64_meta_data, void *file);
int x32_execution(t_meta_file *meta_file);
int setup_x32_meta_data(t_elf_32 **x32_meta_data, void *file);

void display_symbols(t_symbol *symbols, size_t symbol_count);

/*
**  SYMBOLS
*/

void print_line(t_symbol symbol, char c);
char display_section_spec(t_symbol symbol);
char display_section_name(t_symbol symbol);
char value_to_print(t_symbol symbol, char c);
char display_section_flags(t_symbol symbol);

/*
**  SORT
*/

void sort_symbols(t_symbol *symbols, size_t symbol_count);
void reverse_sort_symbols(t_symbol *symbols, size_t symbol_count);

/*
**  UTILS
*/

size_t ft_strlen(const char *str);
int display_error(const char *str);
int display_multiple_error(const char *format, const char *str);
t_nm *get_nm();
bool parser_checker(char *str);
int display_help();
bool has_only_tild(char *str);

/*
**  DEBUG
*/

void debug_display_arguments();

#endif