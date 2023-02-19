#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1,y = 2,z = 3;
    int *px = &x,*py = &y,*pz = &z;

    // a- Print with labels the values of x, y, z, px, py, pz, *px, *py, *pz.
    printf (" x= %d \n y= %d \n z= %d \n \n px= %d \n py= %d \n pz= %d \n \n *px= %d\n *py= %d \n *pz= %d \n", x,y,z,px,py,pz,*px,*py,*pz);

    // b- Print the message: Swapping pointers.
    printf("Swapping pointers. \n");

    // c- Execute the swap code: pz = px; px = py; py = pz;
    int *pzn;


    pzn=pz;

    pz=px;
    px=py;
    py=pzn;

    // Print with labels the values of x, y, z, px, py, pz, *px, *py, *pz.
    printf (" x= %d \n y= %d \n z= %d \n \n px= %d \n py= %d \n pz= %d \n \n *px= %d\n *py= %d \n *pz= %d \n", x,y,z,px,py,pz,*px,*py,*pz);

    return 0;
}
