#include <stdio.h>

/* strlen 函数：返回 s 的长度 */
int tcpl_strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return i;
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
#if 1
	char a = 0xfe;
	signed char b = 0xfd;
	unsigned char c = 0xfd;

	printf ("a = 0x%x, b = 0x%x, c = 0x%x \n", a, b, c);
	printf ("a = 0x%x, b = 0x%x, c = 0x%x \n", (unsigned)a, (unsigned)b, c);
	printf ("a + b + c = 0x%x\n", a + b + c);
	printf ("a + b + c = 0x%x\n", (unsigned)a + (unsigned)b + c);
#endif
}
