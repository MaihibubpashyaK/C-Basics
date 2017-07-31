/* functions to sort array items in increment order

& decrement order

*/

int *increment_order(int inc[])
{
int l,k,temp;
for(l=0;l<10;l++)
        for(k=0;k<10;k++)
           {
                if(inc[k]>inc[k+1])
                {

                    temp = inc[k];
                    inc[k] = inc[k+1];
                    inc[k+1] = temp;
                }
           }


     return inc;


 }

//**************************************************************************************
//Decrement order

 void decrement_order(int dec[10])
{
int l,k,temp;
for(l=0;l<10;l++)
        for(k=0;k<10;k++)
           {
                if(dec[k]<dec[k+1])
                {

                    temp = dec[k];
                    dec[k] = dec[k+1];
                    dec[k+1] = temp;
                }
           }


 }





