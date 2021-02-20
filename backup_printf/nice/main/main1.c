/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:21:36 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 18:25:11 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** - = 45 =  101101
** 0 = 48 =  110000 1bit目がたってれば-だし、5bit目が立ってれば0
** # = 35 =  100011
**   = 32 =  100000
** + = 43 =  101011
*/
#ifdef ctest
int main()
{
	int i = 0;
	int n;
	char nl = 0;

// %c
	char c='a';
	printf("%c\n",c);
	ft_printf("%c\n",c);
	printf("\n");

	printf("%c\n",c);
	ft_printf("%c\n",c);
	printf("\n");

	printf("[%-5c]\n",c);
	ft_printf("[%-5c]\n",c);
	printf("\n");

	printf("[%10c]\n",c);
	ft_printf("[%10c]\n",c);
	printf("\n");

	printf("%.c\n",c);
	ft_printf("%.c\n",c);
	printf("\n");

	printf("Kashim a %c histoires Ã  raconter\n", 1001);	
	ft_printf("Kashim a %c histoires Ã  raconter\n", 1001);	
	printf("\n");

	printf("Kashim a %c histoires Ã  raconter\n", 2147483647);
	ft_printf("Kashim a %c histoires Ã  raconter\n", 2147483647);
	printf("\n");
}
#endif
#ifdef stest
int main()
{
	printf("%s\n", "abcde");
	ft_printf("%s\n", "abcde");
	printf("\n");

	printf("[%10s]\n", "abcde");
	ft_printf("[%10s]\n", "abcde");
	printf("\n");

	printf("[%2s]\n", "abcde");
	ft_printf("[%2s]\n", "abcde");
	printf("\n");

	printf("[%-10s]\n", "abcde");
	ft_printf("[%-10s]\n", "abcde");
	printf("\n");

	printf("[%-.10s]\n", "abcde");
	ft_printf("[%-.10s]\n", "abcde");
	printf("\n");

	printf("[%-10.10s]\n", "abcde");
	ft_printf("[%-10.10s]\n", "abcde");
	printf("\n");
}
#endif
#ifdef dtest
int main()
{
	// %d
	printf("%d\n", -1);
	ft_printf("%d\n", -1);
	printf("\n");

	printf("%0d\n", -1);
	ft_printf("%0d\n", -1);
	printf("\n");

	printf("%0.0d\n", -1);
	ft_printf("%0.0d\n", -1);
	printf("\n");

	printf("%10.0d\n", 0);
	ft_printf("%10.0d\n", 0);
	printf("\n");

	printf("%10.10d\n", -1);
	ft_printf("%10.10d\n", -1);
	printf("\n");

	printf("%-10d\n", -1);
	ft_printf("%-10d\n", -1);
	printf("\n");

	printf("%010d\n", -1);
	ft_printf("%010d\n", -1);
	printf("\n");

	printf("+5hd[%+5hd]\n", (short)10000);
	ft_printf("+5hd[%+5hd]\n", (short)10000);
	printf("\n");

	printf("%10.8hhd\n", (char)-10000);
	ft_printf("%10.8hhd\n", (char)-10000);
	printf("\n");

	printf("%10d\n", 2147483647);
	ft_printf("%10d\n", 2147483647);
	printf("\n");

	printf("%ld\n", 9223372036854775807);
	ft_printf("%ld\n", 9223372036854775807);
	printf("\n");

	printf("%lld\n", (long long)-9223372036854775807);
	ft_printf("%lld\n", (long long)-9223372036854775807);
	printf("\n");

	printf("real : [%*.10d]\n", 9, 1);
	ft_printf("real : [%*.10d]\n", 9, 1);
	printf("\n");

	printf("+.0d[%+.0d]\n", 0);
	ft_printf("+.0d[%+.0d]\n", 0);
	printf("\n");

	printf(" .0d[% .0d]\n", 0);
	ft_printf(" .0d[% .0d]\n", 0);
	printf("\n");

	printf(" .0d[% .0d]\n", (int)-2147483649);
	ft_printf(" .0d[% .0d]\n", (int)-2147483649);

}
#endif
#ifdef ftest
int main()
{
	// %f
	printf("10.4f[%10.4f]\n", 7.123456789);
	ft_printf("10.4f[%10.4f]\n", 7.123456789);
	printf("\n");

	printf("-10.4f[%-10.4f]\n", 7.123456789);
	ft_printf("-10.4f[%-10.4f]\n", 7.123456789);
	printf("\n");

	printf("010.4f[%010.4f]\n", 7.123456789);
	ft_printf("010.4f[%010.4f]\n", 7.123456789);
	printf("\n");

	printf("010f[%010f]\n", 7.123456789);
	ft_printf("010f[%010f]\n", 7.123456789);
	printf("\n");

	printf(".10f[%.10f]\n", 7.12345);
	ft_printf(".10f[%.10f]\n", 7.12345);
	printf("\n");

	printf(".6f[%.6f]\n", 7.123456789);
	ft_printf(".6f[%.6f]\n", 7.123456789);
	printf("\n");

	printf(".0f[%.0f]\n", 7.00);
	ft_printf(".0f[%.0f]\n", 7.00);
	printf("\n");

	printf(".0f[%.0f]\n", 8.0);
	ft_printf(".0f[%.0f]\n", 8.0);
	printf("\n");

	printf(".0f[%.0f]\n", 10.5);
	ft_printf(".0f[%.0f]\n", 10.5);
	printf("\n");

	printf(".0f[%.0f]\n", 11.5);
	ft_printf(".0f[%.0f]\n", 11.5);
	printf("\n");

	printf(".0f[%.0f]\n", 2.501);
	ft_printf(".0f[%.0f]\n", 2.501);
	printf("\n");

	printf(".0f[%.0f]\n", 3.50);
	ft_printf(".0f[%.0f]\n", 3.50);
	printf("\n");

	printf(".1f[%.1f]\n", 2.55);
	ft_printf(".1f[%.1f]\n", 2.55);
	printf("\n");

	printf(".1f[%.1f]\n", 3.65);
	ft_printf(".1f[%.1f]\n", 3.65);
	printf("\n");

	printf("+.10f[%+.10f]\n", 3.65);
	ft_printf("+.10f[%+.10f]\n", 3.65);
	printf("\n");

	printf(".10f[%.10f]\n", -7.000000036);
	ft_printf(".10f[%.10f]\n", -7.000000036);
	printf("\n");

	printf("+05.1f[%+05.1f]\n", -7.3);
	ft_printf("+05.1f[%+05.1f]\n", -7.3);
	printf("\n");

	printf("nantest:[%f]\n", 0.0/0.0);
	ft_printf("nantest:[%f]\n", 0.0/0.0);
	printf("\n");

	printf("DBLMAX:[%f]\n", __DBL_MAX__);
	ft_printf("DBLMAX:[%f]\n", __DBL_MAX__);
	printf("\n");

	printf(".0f:[%.0f]\n", -4.5);
	ft_printf(".0f:[%.0f]\n", -4.5);
	printf("\n");
}
#endif

#ifdef etest
int main()
{
	printf(".3e[%.3e]\n", -3.85);
	ft_printf(".3e[%.3e]\n", -3.85);
	printf("\n");

	printf(".3e[%.3e]\n", 573.924);
	ft_printf(".3e[%.3e]\n", 573.924);
	printf("\n");

	printf("e[%e]\n", 999.999999);
	ft_printf("e[%e]\n", 999.999999);
	printf("\n");

	printf("e[%e]\n", 0.0894255);
	ft_printf("e[%e]\n", 0.0894255);
	printf("\n");

	printf(".1e[%.1e]\n", -0.0);
	ft_printf(".1e[%.1e]\n", -0.0);
	printf("\n");

	printf(".0e[%.0e]\n", -0.0);
	ft_printf(".0e[%.0e]\n", -0.0);
	printf("\n");

	printf(".1e[%.1e]\n", 0.0);
	ft_printf(".1e[%.1e]\n", 0.0);
	printf("\n");

	printf(".0e[%.0e]\n", 0.0);
	ft_printf(".0e[%.0e]\n", 0.0);
	printf("\n");

	printf(".3MAXe[%.3e]\n", -__DBL_MAX__);
	ft_printf(".3MAXe[%.3e]\n", -__DBL_MAX__);
	printf("\n");

}
#endif

#ifdef gtest
int main()
{
	printf(".8g[%.8g]\n", 0.0000003912345678);
	ft_printf(".8g[%.8g]\n", 0.0000003912345678);
	printf("\n");

	printf(".3g[%.3g]\n", 12345.6789);
	ft_printf(".3g[%.3g]\n", 12345.6789);
	printf("\n");

	printf(".3g[%.3g]\n", 123.45);
	ft_printf(".3g[%.3g]\n", 123.45);
	printf("\n");

	printf(".4g[%.4g]\n", 12.345);
	ft_printf(".4g[%.4g]\n", 12.345);
	printf("\n");

	printf(".3g[%.3g]\n", 1234.56);
	ft_printf(".3g[%.3g]\n", 1234.56);
	printf("\n");

	printf(".11g[%.11g]\n", 0.000000000010000000);
	ft_printf(".11g[%.11g]\n", 0.000000000010000000);
	printf("\n");

	printf(".0g[%.0g]\n", -0.00032);
	ft_printf(".0g[%.0g]\n", -0.00032);
	printf("\n");

	printf(".10g[%.10g]\n", 0.0000000001);
	ft_printf(".10g[%.10g]\n", 0.0000000001);
	printf("\n");

	printf("#.0g[%#.0g]\n", 0.0);
	ft_printf("#.0g[%#.0g]\n", 0.0);
	printf("\n");


	printf("#.1g[%#.1g]\n", -0.0);
	ft_printf("#.1g[%#.1g]\n", -0.0);
	printf("\n");

	printf("#-5.3g[%#-5.3g]\n", 0.0);
	ft_printf("#-5.3g[%#-5.3g]\n", 0.0);
	printf("\n");

	printf("#-5.3g[%#-5.3g]\n", 7.3);
	ft_printf("#-5.3g[%#-5.3g]\n", 7.3);
	printf("\n");

	printf("#-5.3g[%#-5.3g]\n", 0.0);
	ft_printf("#-5.3g[%#-5.3g]\n", 0.0);
	printf("\n");

	printf(".0g[%.0g]\n", -9.9);
	ft_printf(".0g[%.0g]\n", -9.9);
	printf("\n");
	
	printf(".14g[%.14g]\n", 9.999999999999990000);
	ft_printf(".14g[%.14g]\n", 9.999999999999990000);
	printf("\n");

	printf(".14g[%.14g]\n", 10.999999999999990000);
	ft_printf(".14g[%.14g]\n", 10.999999999999990000);
	printf("\n");

	printf(".10000g[%.10000g]\n", 10.999999999999990000);
	ft_printf(".10000g[%.10000g]\n", 10.999999999999990000);
	printf("\n");

}
#endif

#ifdef mixtest
int main()
{
	static char 		ch_pos_1 = 100, ch_neg_1 = -87;
	static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
	static int			i_pos_1 = 878023;
	static long			l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
	static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
	static long			lmax	= 9223372036854775807;
	static long			lmin	= -9223372036854775807;
	static long long	llmax = 9223372036854775807;
	static long long	llmin = -9223372036854775807ll;
	static unsigned char 		uch_pos_1 = 100;
	static unsigned short		ush_pos_1 = 3047;
	static unsigned int		ui_pos_1 = 878023;
	static unsigned long		ul_pos_1 = 22337203685477;
	static unsigned long long	ull_pos_1 = 22337203685477;
	static unsigned long long  ullmax = 9223372036854775807;
	static unsigned long  		ulmax = 9223372036854775807;

	printf("%%abc%l%\n");
	ft_printf("%%abc%l%\n");
	printf("\n");

	printf("%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li\n","abc",sh_neg_1,
		ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);
	ft_printf("%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li\n","abc",sh_neg_1,
		ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);
	printf("\n");

//	printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);
//	ft_printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);
//	printf("\n");

	printf("1000f[%1000f]\n", 1.0);
	ft_printf("1000f[%1000f]\n", 1.0);
	printf("\n");

	printf("1000e[%1000e]\n", 1.0);
	ft_printf("1000e[%1000e]\n", 1.0);
	printf("\n");

	printf("1000g[%1000g]\n", 1.0);
	ft_printf("1000g[%1000g]\n", 1.0);
	printf("\n");

	printf(".1000f[%.1000f]\n", 1.0);
	ft_printf(".1000f[%.1000f]\n", 1.0);
	printf("\n");

	printf(".1000e[%.1000e]\n", 1.0);
	ft_printf(".1000e[%.1000e]\n", 1.0);
	printf("\n");

	printf(".1000g%.1000g\n", 1.0);
	ft_printf(".1000g%.1000g\n", 1.0);
	printf("\n");

//	printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);
//	ft_printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);
//	printf("\n");
}
#endif

#ifdef ntest
int main()
{	// %n
	int n;
	
	printf("pft%5.5ntest%d\n", &n, 12);
	printf("[%d]\n",n);
	ft_printf("pft%5.5ntest%d\n", &n, 12);
	printf("[%d]\n",n);
	printf("\n");

	printf("hntest:%hn%d\n", (short*)&n, 7);
	printf("[%d]\n",n);
	ft_printf("hntest:%hn%d\n", (short*)&n, 7);
	printf("[%d]\n",n);
	printf("\n");

	printf("hhntest:%hhn%d\n", (signed char*)&n, 8);
	printf("[%d]\n",n);
	ft_printf("hhntest:%hhn%d\n", (signed char*)&n, 8);
	printf("[%d]\n",n);
	printf("\n");

	printf("lntest:%ln%d\n", (long *)&n, 7);
	printf("[%d]\n",n);
	ft_printf("lntest:%ln%d\n", (long *)&n, 7);
	printf("[%d]\n",n);
	printf("\n");

	printf("llntest:%lln%d\n", (long long *)&n, 8);
	printf("[%d]\n",n);
	ft_printf("llntest:%lln%d\n", (long long *)&n, 8);
	printf("[%d]\n",n);
	printf("\n");

	printf("+.0n:[%+.0n]%d\n", &n, 3);
	ft_printf("+.0n:[%+.0n]%d\n", &n, 3);
	printf("\n");

	printf(" .0n:[% .0n]%d\n", &n, 3);
	ft_printf(" .0n:[% .0n]%d\n", &n, 3);
	printf("\n");

}
#endif

#ifdef utest
int main()
{
	printf("%10u\n", 2147483647);
	ft_printf("%10u\n", 2147483647);
	printf("\n");

	printf("%u\n",(unsigned int)4294967295);
	ft_printf("%u\n",(unsigned int)4294967295);
	printf("\n");

	printf("%.15u\n",(unsigned int)-1);
	ft_printf("%.15u\n",(unsigned int)-1);
	printf("\n");

	printf("%0.0lu\n",(unsigned long)-1);
	ft_printf("%0.0lu\n",(unsigned long)-1);
	printf("\n");

	printf("%llu\n",(unsigned long long)-1);
	ft_printf("%llu\n",(unsigned long long)-1);
	printf("\n");

	printf("%hu\n",(unsigned short int)65535);
	ft_printf("%hu\n",(unsigned short int)65535);
	printf("\n");

	printf("%hu\n",(unsigned short int)-1);
	ft_printf("%hu\n",(unsigned short int)-1);
	printf("\n");

	printf("%hhu\n",(unsigned char)255);
	ft_printf("%hhu\n",(unsigned char)255);
	printf("\n");

	printf("%hhu\n",(unsigned char)-1);
	ft_printf("%hhu\n",(unsigned char)-1);
	printf("\n");

	int i=0;
	i=printf("%llu\n",(unsigned long long)-12345612220);
	printf("len:%d\n",i);
	i=ft_printf("%llu\n",(unsigned long long)-12345612220);
	printf("len:%d\n",i);
	printf("\n");
}
#endif

#ifdef pertest
int main()
{
	printf("p[%5%]\n");
	ft_printf("f[%5%]\n");
	printf("\n");

	printf("p[%.0%]\n");
	ft_printf("f[%.0%]\n");
	printf("\n");

	printf("%0%\n");
	ft_printf("%0%\n");
	printf("\n");

	printf("%-10%\n");
	ft_printf("%-10%\n");
	printf("\n");

	printf("p[%010%]\n");
	ft_printf("f[%010%]\n");
	printf("\n");
}
#endif

#ifdef xtest
int main()
{
	printf("0#10.0x 0#x[%0#10.0x %0#x]\n", 12345, 0);
	ft_printf("0#10.0x 0#x[%0#10.0x %0#x]\n", 12345, 0);
	printf("\n");

	printf("#5.5X[%#5.5X]\n", 0);
	ft_printf("#5.5X[%#5.5X]\n", 0);
	printf("\n");

	printf("-#5.5X[%-#5.5X]\n", 0);
	ft_printf("-#5.5X[%-#5.5X]\n", 0);
	printf("\n");

	printf("-#5.0X[%-#5.0X]\n", 0);
	ft_printf("-#5.0X[%-#5.0X]\n", 0);
	printf("\n");

	printf("-#5.0x[%-#5.0x]\n", 0);
	ft_printf("-#5.0x[%-#5.0x]\n", 0);

	printf("-#5.5x[%-#5.5x]\n", 0);
	ft_printf("-#5.5x[%-#5.5x]\n", 0);
	printf("\n");

	printf("#5.0x[%#5.0x]\n", 123);
	ft_printf("#5.0x[%#5.0x]\n", 123);
	printf("\n");

	printf("#+5.0x[%#+5.0x]\n", 123);
	ft_printf("#+5.0x[%#+5.0x]\n", 123);
	printf("\n");	

	printf("#0.0X[%#0.0X]\n", 123);
	ft_printf("#0.0X[%#0.0X]\n", 123);
	printf("\n");
}
#endif
#ifdef htest
int main()
{
	printf(".0ho[%.0ho]\n", 123);
	ft_printf(".0ho[%.0ho]\n", 123);
	printf("\n");

	printf(".10ho[%.10ho]\n", 123);
	ft_printf(".10ho[%.10ho]\n", 123);
	printf("\n");

	printf(".010ho[%.10ho]\n", 123);
	ft_printf(".010ho[%.10ho]\n", 123);
	printf("\n");
}
#endif

#ifdef otest
int main()
{
	printf("#6o[%#6o]\n", 52625);
	ft_printf("#6o[%#6o]\n", 52625);
	printf("\n");	

	printf("#.0o[%#.0o]\n", 0);
	ft_printf("#.0o[%#.0o]\n", 0);
	printf("\n");	

	printf("#.0o[%#.0o]\n", 10);
	ft_printf("#.0o[%#.0o]\n", 10);
	printf("\n");

	printf("#-5.0o[%#-5.0o]\n", 0);
	ft_printf("#-5.0o[%#-5.0o]\n", 0);
	printf("\n");

	printf("#0o[this %#o number]\n", 0);
	ft_printf("#0o[this %#o number]\n", 0);
	printf("\n");

	printf("#.1o[%#.1o]\n", 000);
	ft_printf("#.1o[%#.1o]\n", 000);
	printf("\n");
}
#endif