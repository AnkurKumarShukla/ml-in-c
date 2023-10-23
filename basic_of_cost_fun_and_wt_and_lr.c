#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2]={
    {0,0},
    {1,2},
    {2,4},
    {4,8}
};
int train_count= sizeof(train)/sizeof(train[0]);
float rand_float(void){
    return (float) rand()/(float) RAND_MAX;
}



float cost(float w){
    float tcost=0;
    for (int i =0;i<train_count;i++){

        float d=train[i][1]-w*train[i][0];
        tcost+=d*d;
    }
    return tcost/train_count;
}




int main(){
    // y= W*x
    // 1 000 000 000 000 => GPT4 trilloin
    // 1                 => us
    // srand(time(0));
    srand(69);
    float ep = 1e-3;
    float w = 10000; //rand_float()*10.0f;
    // float dcost = (cost(w+ep)-cost(w))/ep;
    float lr = 1e-2;
    // printf("w before  %f\n",w);
    // printf(" cost before change %f \n",cost(w));
    // w=w-ep;
    // printf("cost after  change %f \n",cost(w));
    // printf("w after %f\n",w);
     for(int i =0;i<40000;i++){
        float dcost = (cost(w+ep)-cost(w))/ep;
        w-=lr*dcost;
        printf("w  %f  cost  %f\n",w,cost(w));
        
     }
    
    return 0;
}