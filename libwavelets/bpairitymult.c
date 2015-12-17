#include "bio_parameters.h"

void bpairitymultiply(FLOAT *vector,
		      int xlength,
		      int ylength,
		      int zlength,
                      int pairity,
		      FLOAT factor){


  if((pairity==0)&&(xlength>1))
    for(int k=0;k<zlength;k++)
      for(int j=0;j<ylength;j++) vector[xlength*(k*ylength+j)] *=factor;

  if(((xlength&1)==(1-pairity))&&(xlength>1)) 
    for(int k=0;k<zlength;k++)
      for(int j=0;j<ylength;j++) vector[xlength*(k*ylength+j+1)-1] *=factor;

  if((pairity==0)&&(ylength>1))
     for(int k=0;k<zlength;k++)
      for(int j=0;j<xlength;j++) vector[xlength*k*ylength +j] *=factor;

  if(((ylength&1)==(1-pairity))&&(ylength>1)) 
    for(int k=0;k<zlength;k++)
      for(int j=0;j<xlength;j++) vector[j+xlength*((k+1)*ylength-1)] *=factor;

  if((pairity==0)&&(zlength>1))
    for(int k=0;k<ylength;k++)
      for(int j=0;j<xlength;j++) vector[(xlength*k)+j] *=factor;

  if(((zlength&1)==(1-pairity))&&(zlength>1)) 
    for(int k=0;k<ylength;k++)
      for(int j=0;j<xlength;j++) vector[xlength*(k+(zlength-1)*ylength)+j] *=factor;
}




void boundarymultiply(FLOAT *vector,
		      int xlength,
		      int ylength,
		      int zlength,
               		FLOAT factor){

  for(int k=0;k<ylength;k++)
    for(int j=0;j<xlength;j++) vector[k*xlength+j] *=factor;
  for(int k=0;k<zlength;k++){
    for(int j=0;j<xlength;j++) vector[xlength*k*ylength +j] *=factor;   
    for(int j=0;j<ylength;j++){
      vector[xlength*(k*ylength+j)] *=factor;
      vector[xlength*(k*ylength+j+1)-1] *=factor;
    }
    for(int j=0;j<xlength;j++) vector[xlength*((k+1)*ylength -1) +j] *=factor;     }
  for(int k=0;k<ylength;k++)
    for(int j=0;j<xlength;j++) vector[((zlength-1)*ylength+k)*xlength+j] *=factor;
}


