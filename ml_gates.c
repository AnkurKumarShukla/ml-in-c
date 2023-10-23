#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef DEF_SIGMOID
#define DEF_SIGMOID

#define EULER_NUMBER 2.71828
#define EULER_NUMBER_F 2.71828182846
#define EULER_NUMBER_L 2.71828182845904523536

double sigmoid(double n);
float sigmoidf(float n);
long double sigmoidl(long double n);

#endif

// float expf(float x){
//     return (float)pow(x,exp);
// }

float sigmoidf(float n) {
    return (1 / (1 + powf(EULER_NUMBER_F, -n)));
}


float train[][3]={
    {0,0,0},
    {1,0,1},
    {1,1,1},
    {0,1,1}
};
int train_count= sizeof(train)/sizeof(train[0]);
float rand_float(void){
    return (float) rand()/(float) RAND_MAX;
}



float cost(float w1,float w2, float b){
    float tcost=0.0f;
    for (int i =0;i<train_count;i++){

        float d=train[i][2]-sigmoidf(w1*train[i][0]+w2*train[i][1]+b);
        tcost+=d*d;
    }
    return tcost/train_count;
}




int main(){

    srand(69);
    float ep = 1e-3;
    float lr = 1e-3;
    float w1 = rand_float();
     //rand_float()*10.0f;
    float w2=rand_float();
     float b=rand_float();
    // float lr = 1e-2;
    for(int i =0;i<4000;i++){
        float dcost1 = (cost(w1+ep,w2,b)-cost(w1,w2,b))/ep;
        w1-=lr*dcost1;
        float dcost2 = (cost(w1,w2+ep,b)-cost(w1,w2,b))/ep;
        w2-=lr*dcost2;
        float dcost3 = (cost(w1,w2,b+ep)-cost(w1,w2,b))/ep;
        b-=lr*dcost3;
        printf("w1  %f w2  %f b  %f   cost  %f\n",w1,w2,b , cost(w1,w2,b));
        
     }

    for (size_t i=0;i<2;i++){
        for(size_t j =0;j<2;j++){
            printf(" %zu  or  %zu = %f  \n", i ,j , sigmoidf(i*w1+j*w2+b));
        }
    }


    
    return 0;
}