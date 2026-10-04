
void __thiscall
FUN_004b97eb(float *param_1,int *param_2,float param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  float10 fVar2;
  
  *param_1 = (float)param_2[1];
  param_1[1] = (float)*param_2;
  cVar1 = FUN_004b462b(3,1);
  if (cVar1 == '\0') {
    fVar2 = (float10)0;
  }
  else if (param_5 == -1) {
    fVar2 = (float10)FUN_00478f70(param_2);
  }
  else {
    fVar2 = (float10)param_5;
  }
  param_1[2] = (float)fVar2;
  param_1[3] = param_3;
  FUN_004b99c2(param_4);
  return;
}

