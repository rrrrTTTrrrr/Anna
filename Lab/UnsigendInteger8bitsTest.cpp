#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test

int main()
{
    int x = 1;

    asm ("movl %1, %%eax;"
         "movl %%eax, %0;"
         :"=r"(x) /* x is output operand and it's related to %0 */
         :"r"(11)  /* 11 is input operand and it's related to %1 */
         :"%eax"); /* %eax is clobbered register */

   printf("Hello x = %d\n", x);
}