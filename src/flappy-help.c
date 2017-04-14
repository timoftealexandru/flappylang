/**
 * Created by Mihai Sandor and Dobai David on 2/19/17.
 * Modified by Stelian Saracut (github : sstelian)
 */

#include <getopt.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
  int             c;
  const char    * short_opt = "hvnrstepxaHVNRSTEPXA";
  struct option   long_opt[] =
  {
     {"help",          no_argument,       NULL, 'h'},
     {"version",       no_argument,       NULL, 'v'},
     {"number",        no_argument,       NULL, 'n'},
     {"variable",      no_argument,       NULL, 'r'},
     {"string",        no_argument,       NULL, 's'},
     {"statements",    no_argument,       NULL, 't'},
     {"expression",    no_argument,       NULL, 'e'},
     {"print",         no_argument,       NULL, 'p'},
     {"extension",     no_argument,       NULL, 'x'},
     {"assign",        no_argument,       NULL, 'a'},
     {"help",          no_argument,       NULL, 'h'},
     {"VERSION",       no_argument,       NULL, 'V'},
     {"NUMBER",        no_argument,       NULL, 'N'},
     {"VARIABLE",      no_argument,       NULL, 'R'},
     {"STRING",        no_argument,       NULL, 'S'},
     {"STATEMENTS",    no_argument,       NULL, 'T'},
     {"EXPRESSION",    no_argument,       NULL, 'E'},
     {"PRINT",         no_argument,       NULL, 'P'},
     {"EXTENSION",     no_argument,       NULL, 'X'},
     {"ASSIGN",        no_argument,       NULL, 'A'},
     {NULL,            0,                 NULL, 0  }
  };

  while((c = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1)
  {
     switch(c)
     {
        case -1:       /* no more arguments */
        case 0:        /* long options toggles */
        break;

        case 'h':
        printf("Usage: %s [OPTIONS]\n", argv[0]);
        printf("  -n  --number                   number\n");
        printf("  -s  --string                   string\n");
        printf("  -r  --variables                variables\n");
        printf("  -p  --print                    print\n");
        printf("  -e  --expressions              expressions\n");
        printf("  -t  --statements               if statements\n");
        printf("  -a  --assign                   assign var to other var\n");
        printf("  -x, --extension                extension (.fa)\n");
        printf("  -h, --help                     print this help and exit\n");
        printf("\n");
        return(0);

        case 'v':
        printf("FlappyLang version 0.0.1");
        printf("\n");
        return(0);

        case 'r':
        printf("$ = var \n");
        printf("$name = \"FlappyLang\"\n");
        printf("print $name // FlappyLang\n");
        return(0);

        case 'p':
        printf("print word + \"text\", numbers, variables\n");
        return(0);

        case 'n':
        printf("a + b = addition \n");
        printf("a - b = decrement \n");
        printf("a / b = division \n");
        printf("a * b = multiplication \n");
        return(0);

        case 's':
        printf("$string = \"text\"\n");
        printf("print $string\n");
        printf("//text\n");
        return(0);

        case 't':
        printf("if 1 == 1 then => 1 == 1 (eval True)\n");
        printf("\tprint \"Hello World\" => print STRING\n");
        printf("endif => Close IF\n");
        return(0);

        case 'a':
        printf("$var1 = 10 => Initializing variables\n");
        printf("$var2 = $var1 => Assigning variables to other variables\n");
        printf("print $var2 => 10 => Output variables after assigning\n");
        return(0);

        case 'e':
        printf("10 + (2 + 3) => expression\n");
        return(0);

        case 'x':
        printf(".fa is extension for FlappyLang\n");
        return(0);

        case 'H':
        printf("Usage: %s [OPTIONS]\n", argv[0]);
        printf("  -N  --number                   number\n");
        printf("  -S  --string                   string\n");
        printf("  -R  --variables                variables\n");
        printf("  -P  --print                    print\n");
        printf("  -E  --expressions              expressions\n");
        printf("  -T  --statements               if statements\n");
        printf("  -A  --assign                   assign var to other var\n");
        printf("  -X, --extension                extension (.fa)\n");
        printf("  -H, --help                     print this help and exit\n");
        printf("\n");
        return(0);

        case 'V':
        printf("FlappyLang version 0.0.1");
        printf("\n");
        return(0);

        case 'R':
        printf("$ = var \n");
        printf("$name = \"FlappyLang\"\n");
        printf("print $name // FlappyLang\n");
        return(0);

        case 'P':
        printf("print word + \"text\", numbers, variables\n");
        return(0);

        case 'N':
        printf("a + b = addition \n");
        printf("a - b = decrement \n");
        printf("a / b = division \n");
        printf("a * b = multiplication \n");
        return(0);

        case 'S':
        printf("$string = \"text\"\n");
        printf("print $string\n");
        printf("//text\n");
        return(0);

        case 'T':
        printf("if 1 == 1 then => 1 == 1 (eval True)\n");
        printf("\tprint \"Hello World\" => print STRING\n");
        printf("endif => Close IF\n");
        return(0);

        case 'A':
        printf("$var1 = 10 => Initializing variables\n");
        printf("$var2 = $var1 => Assigning variables to other variables\n");
        printf("print $var2 => 10 => Output variables after assigning\n");
        return(0);

        case 'E':
        printf("10 + (2 + 3) => expression\n");
        return(0);

        case 'X':
        printf(".fa is extension for FlappyLang\n");
        return(0);

        case ':':
        case '?':
        fprintf(stderr, "Try `%s -h' for more information.\n", argv[0]);
        return(-2);

        default:
        fprintf(stderr, "%s: invalid option -- %c\n", argv[0], c);
        fprintf(stderr, "Try `%s -h' for more information.\n", argv[0]);
        return(-2);
     };
  }
  return(-2);
}
