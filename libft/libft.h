/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:34:13 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/03 17:07:35 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

//Cambios en cadenas a traves de memoria----------------------------------------
void				*ft_memset(void *b, int c, size_t len); //cambia los caracteres de una cadena por el caracter mandado tantas posicones como se le indiquen, a través del movimiento en la dir de memoria
void				ft_bzero(void *s, size_t n); //cambia los carácteres de una cadena por nulos
void				*ft_memcpy(void *dst, const void *src, size_t n); //copia tantos caracteres de una cadena en otra, eliminando lo que haya en ella
void				*ft_memccpy(void *dst, const void *src, int c, size_t n); //copia tantos caracteres de una cadena en otra, hasta que encuenntre un caracter igual al mandado en la cadena original
void				*ft_memmove(void *dst, const void *src, size_t len); //mueve tantos caracteres de una cadena a otra. Si la de destino es mayor el movimiento es como una copia normal, si es menor la copia empieza desde atrás para eliminar todo lo anterior
void				*ft_memchr(const void *s, int c, size_t n); //compara el caracter mandado, en tantas posiciones como se indiquen, en una cadena y devuelve la cadena desde la posicion de ese caracter
int					ft_memcmp(const void *s1, const void *s2, size_t n); //devuelve la diferencia del primer caracter distinto encontrado en dos cadenas, la comaracion se hace tantos caracteres como se le manden
//------------------------------------------------------------------------------

//Cadenas y Chars---------------------------------------------------------------
size_t				ft_strlen(const char *s); //devuelve el tamaño de cadenas
int					ft_isalpha(int c); //devuelve 1 si es una letra
int					ft_isdigit(int c); //devuelve 1 si es un numero.
int					ft_isalnum(int c); //devuelve 1 si el alfanumerico
int					ft_isascii(int c); //devuelve 1 si es ASCII
int					ft_isprint(int c); //devuelve 1 si es carractes imprimible
int					ft_toupper(int c); //devuelve 1 letras a mayusculas
int					ft_tolower(int c); //devuelve 1 letras a minusculas
char				*ft_strchr(const char *s, int c); //devuelve la posicion del caracter mandado en la cadena mandada
char				*ft_strrchr(const char *s, int c); //devuelve la ultima posicion del caracter mandado en la cadena mandada
int					ft_strncmp(const char *s1, const char *s2, size_t n); //compara tanto caracteres mandados de dos cadenas y devuelve la resta de los primeros dos caracteres distintos
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize); //devuelve el tamaño de la cadena original, al intentar copiar y conccatenar dos cadenas
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize); //concatena dos cadenas y devuelve el tamaño de la cadena que ha intentado crear
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len); //devuelve la cadena desde la posicion de la palabra que le mandes, compara la cadena con esa palabra y si conincide en tantos caracteres mandados devuelve la cadena desde esa posicion
int					ft_atoi(const char *nptr); //transforma una cadena de numeros en un entero real
void				*ft_calloc(size_t count, size_t size); //reserva memoria del tamaño mandado y lo llena de nulos
char				*ft_strdup(const char *s1); //reserva memoria del mismo tamaño de la cadena mandada y la duplica en una cadena nueva
char				*ft_substr(char const *s, unsigned int start, size_t len); //reserva memoria para crear una nueva cadena que guarde tantos caracterese como se le indiquen de la posicion mandada de la cadena indicada
char				*ft_strjoin(char const *s1, char const *s2); //reserva memoria para crear una nueva cadena que contenga las dos cadenas mandadas concatenadas
char				*ft_strtrim(char const *s1, char const *set); //reserva memoria para crear una nueva cadena que guarde la cadena mandada sin el delimitador indicado al principio y final de la cadena original
char				**ft_split(char const *s, char c); //reserva memoria para crear una cadena bidimensional. El caracter mandado es el que indicará donde cortar cada fila
char				*ft_itoa(int n); //reserva memoria para crear una nueva cadena que contenga en formato caracter el numero entero mandado
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char)); //reserva memoria para crear una nueva cadena que contanga una copia de la cadena mandada con las modificaciones de la funcion indicada
//------------------------------------------------------------------------------

//Impresion en file descriptor --------------------------------
void				ft_putchar_fd(char c, int fd); //imprime el caracter mandado por el file descriptor que se le indique (1, 0, o el 2)
void				ft_putstr_fd(char *s, int fd); //imprime la cadena mandada por el file descriptor que se le indique
void				ft_putendl_fd(char *s, int fd); //imprime la cadena mandada con salto de linea por el file descriptor que se le indique
void				ft_putnbr_fd(int n, int fd); //imprime en formato cadena el numero entero pasado por el file descriptor que se le indique
//-------------------------------------------------------------

//Estructuras --------------------------------------------------
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content); //añade contenido (cadena, numeros, caracteres) a una nueva cadena
void				ft_lstadd_front(t_list **lst, t_list *new); //añade una nueva estructura al inicio de una lista de estrcuturas
int					ft_lstsize(t_list *lst); //devuelve el numero de elementos de una lista de estructuras
t_list				*ft_lstlast(t_list *lst); //devuelve la ultima estructura de una lista
void				ft_lstadd_back(t_list **lst, t_list *new); //añade una nueva estructura al final de una lista
void				ft_lstdelone(t_list *lst, void (*del)(void*)); //elimina el contenido guardado en una estructura
void				ft_lstclear(t_list **lst, void (*del)(void*)); //elimina una estructura
void				ft_lstiter(t_list *lst, void (*f)(void*)); //aplica la funcion mandada al contenido de las estructuras en una lista
t_list				*ft_lstmap(t_list *lst, void *(*f)(void*),
					void (*del)(void*)); //devuelve una lista nueva con el contenido de las estrcuturas modificadas por la función mandada y elimina la lista anterior
//---------------------------------------------------------------
#endif
