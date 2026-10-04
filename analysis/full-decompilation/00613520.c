
void FUN_00613520(double *param_1,double *param_2,double param_3)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  
  dVar1 = *param_1;
  dVar2 = *param_2;
  fVar3 = (float10)fcos((float10)param_3);
  fVar4 = (float10)fsin((float10)param_3);
  *param_1 = (double)(fVar3 * (float10)dVar1 - fVar4 * (float10)dVar2);
  *param_2 = (double)(fVar3 * (float10)dVar2 + fVar4 * (float10)dVar1);
  return;
}

