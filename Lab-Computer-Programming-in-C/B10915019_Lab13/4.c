#include <stdio.h>
#include <math.h>

typedef struct sci_not_t {
    double mantissa ;
    int exponent ;
}sci_not_t;

sci_not_t scan_sci(char* str){
    sci_not_t res;
    sscanf(str,"%lfe%d",&res.mantissa,&res.exponent);
    return res;
}

sci_not_t add(sci_not_t a,sci_not_t b){
    double fa = a.mantissa*pow(10.0,a.exponent);
    double fb = b.mantissa*pow(10.0,b.exponent);
    double fres = fa+fb;
    sci_not_t res;
    res.exponent = 0;
    while(fres>1){
        res.exponent++;
        fres/=10.0;
    }
    while(fres<0.1){
        res.exponent--;
        fres*=10;
    }
    res.mantissa = fres;
    return res;
}

sci_not_t min(sci_not_t a,sci_not_t b){
    double fa = a.mantissa*pow(10.0,a.exponent);
    double fb = b.mantissa*pow(10.0,b.exponent);
double fres = fa-fb;
    sci_not_t res;
    res.exponent = 0;
    while(fres>1){
        res.exponent++;
        fres/=10.0;
    }
    while(fres<0.1){
        res.exponent--;
        fres*=10;
    }
    res.mantissa = fres;
    return res;
}
sci_not_t tim(sci_not_t a,sci_not_t b){
    double fa = a.mantissa*pow(10.0,a.exponent);
    double fb = b.mantissa*pow(10.0,b.exponent);
double fres = fa*fb;
    sci_not_t res;
    res.exponent = 0;
    while(fres>1){
        res.exponent++;
        fres/=10.0;
    }
    while(fres<0.1){
        res.exponent--;
        fres*=10;
    }
    res.mantissa = fres;
    return res;
}
sci_not_t div(sci_not_t a,sci_not_t b){
    double fa = a.mantissa*pow(10.0,a.exponent);
    double fb = b.mantissa*pow(10.0,b.exponent);
double fres = fa/fb;
    sci_not_t res;
    res.exponent = 0;
    while(fres>1){
        res.exponent++;
        fres/=10.0;
    }
    while(fres<0.1){
        res.exponent--;
        fres*=10;
    }
    res.mantissa = fres;
    return res;
}

int main(){
    printf("Value input: ");
    char i1[100], i2[100];
    scanf("%s %s",i1,i2);
    sci_not_t s1 = scan_sci(i1), s2 = scan_sci(i2);
    sci_not_t r = add(s1,s2);
    printf("Sum: %.5lfe%d\n",r.mantissa,r.exponent);
    r = min(s1,s2);
    printf("Difference: %.5lfe%d\n",r.mantissa,r.exponent);
    r = tim(s1,s2);
    printf("Product: %.5lfe%d\n",r.mantissa,r.exponent);
    r = div(s1,s2);
    printf("Quotient: %.5lfe%d\n",r.mantissa,r.exponent);
}