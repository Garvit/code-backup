#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,sa,sb,fa,fb,lfa,lfb,bta,btb;
    int j;
    scanf("%d",&t);
    char a[20010];
    char b[20010];
    for(i=0;i<t;i++)
    {
        sa=sb=fa=fb=lfa=lfb=bta=btb=0;
        scanf("%s",a);
        scanf("%s",b);
        //printf("%c",a[0]);
        for(j=0;j<strlen(a);j++)
        {
            if(a[j]=='4')
                fa++;
            else if(a[j]=='7')
                sa++;
            else if(a[j]<'7' && a[j]>'4')
                bta++;
            else if(a[j]<'4' && a[j]>='0')
                lfa++;

            if(b[j]=='4')
                fb++;
            else if(b[j]=='7')
                sb++;
            else if(b[j]<'7' && b[j]>'4')
                btb++;
            else if(b[j]<'4' && b[j]>='0')
                lfb++;

        }
        int l1,frb,fra,srb,sra,l2,ls,l3,l4,lf;
        l1=(sa<=(btb+fb+lfb+sb))?sa:(btb+fb+lfb+sb);
        srb=l1-(btb+fb+lfb);
        if(srb>0){
            sb=sb-srb;
            fb=0;
        }
        else{
        frb=l1-(btb+lfb);
        if(frb>0)
        {
            fb=fb-frb;
        }}

        l2=(sb<=(bta+fa+lfa))?sb:(bta+fa+lfa);
        fra=l2-(bta+lfa);
        if(fra>0)
        {
            fa=fa-fra;
        }
        ls=l1+l2;

        if(frb>0)
        {
            l3=(fa<=fb)?fa:fb;
            fb=l3-fb;
        }
        else{
        if(l1>btb){
            l3=(fa<=(fb+btb+lfb-l1))?fa:(fb+btb+lfb-l1);
            frb=l3-(btb+lfb-l1);
            if(frb>0)
                fb=fb-frb;
            }
            else
            {
                l3=(fa<=(fb+lfb))?fa:(fb+lfb);
                frb=l3-lfb;
                if(frb>0)
                    fb=fb-frb;
            }

        }

        if(fra>0)
        {
            l4=0;
        }
        else{
            if(l2>bta)
            {
                l4=fb<=(lfa+bta-l2)?fb:(lfa+bta-l2);
            }
            else{
                l4=fb<=lfa?fb:lfa;
            }

        }
        lf=l3+l4;
        for(j=0;j<ls;j++)
            putchar('7');
        for(j=0;j<lf;j++)
            putchar('4');

        putchar('\n');
    }

    return 0;
}
