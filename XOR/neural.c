# include <stdio.h>
# include <stdlib.h>
# include <math.h>

double sigmoid(double x){ //(tangeante) voir fonction en rouge p.1
  return (1/(1+exp(-x)));
}

double derivative(double x){
  return (x*(1-x));
}

double output(double inputs[], double weights[], double bio){
  return sigmoid(inputs[0]*weights[0]+inputs[1]*weights[1]+bio);
}

void train(){
  ////// init //////
  double inputs[4][2]{{0,0},{0,1},{1,0},{1,1}};
  double result[4]={0,1,1,0};
  ////// init neuron //////
  double neuron1Inputs[2];
  double neuron1Weights[2];
  double neuron1BiasWeight;
  double neuron1Error;
  neuron1Weights[0]=(double)rand()/(double)RAND_MAX;
  neuron1Weights[1]=(double)rand()/(double)RAND_MAX;
  neuron1BiasWeight=(double)rand()/(double)RAND_MAX;
  double neuron2Inputs[2];
  double neuron2Weights[2];
  double neuron2BiasWeight;
  double neuron2Error;
  neuron2Weights[0]=(double)rand()/(double)RAND_MAX;
  neuron2Weights[1]=(double)rand()/(double)RAND_MAX;
  neuron2BiasWeight=(double)rand()/(double)RAND_MAX;
  double neuron3Inputs[2];
  double neuron3Weights[2];
  double neuron3BiasWeight;
  double neuron3Error;
  neuron3Weights[0]=(double)rand()/(double)RAND_MAX;
  neuron3Weights[1]=(double)rand()/(double)RAND_MAX;
  neuron3BiasWeight=(double)rand()/(double)RAND_MAX;
  ////// train //////
  int epoch=0;
  while(epoch < 2000){
    epoch++;
	for(int i=0; i<4;i++){
	  neuron1Inputs[0]=inputs[i][0];
	  neuron1Inputs[1]=inputs[i][1];
	  neuron2Inputs[0]=inputs[i][0];
	  neuron2Inputs[1]=inputs[i][1];
	  neuron3Inputs[0]=output(neuron1Inputs,neuron1Weights,neuron1BiasWeight);
	  neuron3Inputs[1]=output(neuron2Inputs,neuron2Weights,neuron2BiasWeight);
      double n3_output=output(neuron3Inputs,neuron3Weights,neuron3BiasWeight);

	  printf("%f xor %f = %f \n",inputs[i][0],inputs[i][1],n3_output);
	  
	  neuron3Error=derivative(n3_output)*(result[i]-n3_output);
	  neuron3BiasWeight+=neuron3Error;
	  neuron3Weights[0]+=neuron3Error*neuron3Inputs[0];
	  neuron3Weights[1]+=neuron3Error*neuron3Inputs[1];

	  neuron1Error=derivative(neuron3Inputs[0])*neuron3Weights[0]*neuron3Error;
	  neuron2Error=derivative(neuron3Inputs[1])*neuron3Weights[1]*neuron3Error;
	  neuron1BiasWeight+=neuron1Error;
	  neuron2BiasWeight+=neuron2Error;

	  neuron1Weights[0]+=neuron1Error*neuron1Inputs[0];
	  neuron1Weights[1]+=neuron1Error*neuron1Inputs[1];
	  neuron2Weights[0]+=neuron2Error*neuron2Inputs[0];
	  neuron2Weights[1]+=neuron2Error*neuron2Inputs[1];
	}
  }
}

int main(){
  train(); 
}
