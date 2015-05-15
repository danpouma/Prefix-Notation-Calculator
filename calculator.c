#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double power( double, int );
int factorial( int );
int randomRange( int, int );
int sumRange( int, int );
int roundDouble( double );


int main(void)
{
  srand( time( NULL ) );
  char op;
  double double1;
  double double2;
  int int1;
  int int2;

  printf( "%s\n", "add          ( + )   + double double" );
  printf( "%s\n", "subtract     ( - )   - double double" );
  printf( "%s\n", "multiply     ( * )   * double double" );
  printf( "%s\n", "divide       ( / )   / double double" );
  printf( "%s\n", "power        ( ^ )   ^ double int" );
  printf( "%s\n", "exponential  ( e )   e int" );
  printf( "%s\n", "factorial    ( ! )   ! int" );
  printf( "%s\n", "random range ( r )   r int int" );
  printf( "%s\n", "sum range    ( s )   s int int" );
  printf( "%s\n", "round        ( ~ )   ~ double" );
  printf( "%s\n", "roundup      ( ' )   ` double" );
  printf( "%s\n", "rounddown    ( _ )   _ double" );
  printf( "%s\n", "minimum      ( < )   < double double" );
  printf( "%s\n", "maximum      ( > )   > double double" );
  printf( "%s\n", "quit         ( q )   q" );
  
  do
  {
    scanf( " %c", &op );
    switch ( op )
    {
      case '+':
        scanf( "%lf%lf", &double1, &double2 );
        printf( "%.2f\n", double1 + double2 );
        break;
      
      case '-':
        scanf( "%lf%lf", &double1, &double2 );
        printf( "%.2f\n", double1 - double2 );
        break;

      case '*':
        scanf( "%lf%lf", &double1, &double2 );
        printf( "%.2f\n", double1 * double2 );
        break;
      
      case '/':
        scanf( "%lf%lf", &double1, &double2 );
        if ( double2 != 0 )
        {
          printf( "%.2f\n", double1 / double2 );
        }
        else
        {
          printf( "%s\n", "Error: Dividing by 0" );
        }
        break;
      
      case '^':
        scanf( "%lf%d", &double1, &int1 );
        printf( "%.4f\n", power( double1, int1 ) );
        break;

      case 'e':
        scanf( "%d", &int1 );
        printf( "%lf\n", power( 2.71828182846, int1 ) );
        break;
      
      case '!':
        scanf( "%d", &int1 );
        printf( "%d\n", factorial( int1 ) );
        break;

      case 'r':
        scanf( "%d%d", &int1, &int2 );
        printf( "%d\n", randomRange( int1, int2 ) );
        break;

      case 's':
        scanf( "%d%d", &int1, &int2 );
        printf( "%d\n", sumRange( int1, int2 ) );
        break;      

      case '~':
        scanf( "%lf", &double1 );
        printf( "%d\n", roundDouble( double1 ) );
        break;

      case '`':
        scanf( "%lf", &double1 );
        printf( "%d\n", (int) double1 + 1 );
        break;

      case '_':
        scanf( "%lf", &double1 );
        printf( "%d\n", (int) double1 );
        break;

      case '<':
        scanf( "%lf%lf", &double1, &double2 );
        if ( double1 < double2 )
        {
          printf( "%.2f\n", double1 );
        }
        else
        {
          printf( "%.2f\n", double2 );
        }
        break;

      case '>':
        scanf( "%lf%lf", &double1, &double2 );
        if ( double1 > double2 )
        {
          printf( "%.2f\n", double1 );
        }
        else
        {
          printf( "%.2f\n", double2 );
        }
        break;

      case 'q':
        printf( "%s\n", "Good-bye." );
        break;

      default:
        printf( "%s\n", "Invalid input." );
        break; 
    }
  }
  while(op !='q');
}

double power( double x, int n )
{
  double number = 1;

  if ( n > 0 )
  {
    for ( int i = 1; i <= n; i++ )
    {
      number *= x;
    }
  }
  else
  {
    n *= -1;
    for ( int i = 1; i <= n; i++ )
    {
      number /= x;
    }
  }

  return number;
}

int factorial( int n )
{
  int factorial;
  
  factorial = 1;
  for (int i = 1; i <= n; i++)
  {
    factorial *= i;
  }

  return factorial;
}

int randomRange( int x, int y )
{
  int random;

  do
  {
    // mod biggest possible int to make faster
    random = rand() % y; 
  } while ( random < x || random > y );

  return random;
}

int sumRange( int x, int y )
{
  int sum;

  for ( int i = x; i <= y; i++ )
  {
    sum += i;
  }

  return sum;
}

int roundDouble( double x )
{
  int result;

  result = x;

  if ( x >= ( result + .5 ) )
  {
    result += 1;
  }

  return result;
}
