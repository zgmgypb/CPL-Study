#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* trim 函数：删除字符串尾部的空格符、制表符与换行符 */
int tcpl_trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--) 
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n + 1] = '\0';
	return n;
}

/* reverse 函数：倒置字符串 s 中各个字符的位置 */
void tcpl_reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa 函数：将数字 n 转换为字符串并保存到 s 中 */
void tcpl_itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0) 
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n / 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	tcpl_reverse(s);
}

/* shellsort 函数：按递增顺序对 v[0]...v[n-1] 进行排序 */
void tcpl_shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2) 
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

/* strlen 函数：返回 s 的长度 */
int tcpl_strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return i;
}

/* atoi 函数：将字符串 s 转换为相应的整型数;版本2 */
int tcpl_atoi2(char s[])
{
	int i, n, sign;

	while (isspace(i)) i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + s[i] - '0';
	return sign * n;
}

/* atoi 函数：将字符串 s 转换为相应的整型数 */
int tcpl_atoi(char s[])
{
	int i, n = 0;

	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) 
		n = 10 * n + (s[i] - '0'); 
	
	return n;
}

/* lower 函数：把字符 c 转换为小写形式；只对 ASCII 字符集有效 */
int tcpl_lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

/* squeeze 函数：从字符串 s 中删除字符 c */
void tcpl_squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

/* strcat 函数：将字符串 t 连接到字符串 s 的尾部；s 必须有足够大的空间 */
void tcpl_strcat(char s[], char t[]) 
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] == t[j++]) != '\0');
}

/* getbits 函数：返回 x 中从第 p 位开始的 n 位 */
unsigned tcpl_getbits(unsigned x, int p, int n)
{
	return ((x >> (p + 1 - n)) & ~(~0 << n));
}

/* bitcount 函数：统计 x 中值为 1 的二进制位数 */
int tcpl_bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

unsigned long int tcpl_snext = 1;

/* rand 函数：返回值在 0 ~ 32767 之间的伪随机数 */
int tcpl_rand(void)
{
	tcpl_snext = tcpl_snext * 1103515245 + 12345;
	return (unsigned int)(tcpl_snext / 65536) % 32768;
}

/* srand 函数：为 rand() 函数设置种子数 */
void tcpl_srand(unsigned int seed)
{
	tcpl_snext = seed;
}

#define MAXLINE 1000
/* getline 函数：将行保存到 s 中，并返回该行的长度 */
int tcpl_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') 
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex 函数：返回 t 在 s 中的位置，若未找到则返回 -1 */
int tcpl_strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

#define IN 1 /* 单词内 */
#define OUT 0 /* 单词外 */
int main(int argc, char *argv[])
{
#if 0	
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
#endif

#if 0
	int c, state = OUT;
	long nc = 0, nl = 0, nw = 0;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') 
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf ("%ld %ld %ld\n", nl, nw, nc);
#endif
#if 0
	char a = 0xfe;
	signed char b = 0xfd;
	unsigned char c = 0xfd;

	printf ("a = 0x%x, b = 0x%x, c = 0x%x \n", a, b, c);
	printf ("a = 0x%x, b = 0x%x, c = 0x%x \n", (unsigned)a, (unsigned)b, c);
	printf ("a + b + c = 0x%x\n", a + b + c);
	printf ("a + b + c = 0x%x\n", (unsigned)a + (unsigned)b + c);
#endif

#if 1
	char pattern[] = "ould";
	char line[MAXLINE];
	int found = 0;
	
	while (tcpl_getline(line, MAXLINE))
		if (tcpl_strindex(line, pattern) >= 0) {
			printf ("%s", line);
			found ++;
		}
	return found;
#endif
}
