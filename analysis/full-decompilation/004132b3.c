
float10 FUN_004132b3(undefined4 param_1,float param_2,char param_3)

{
  float *pfVar1;
  
  pfVar1 = (float *)FUN_00413236(param_1);
  if (pfVar1 == (float *)0x0) {
    if (param_3 != '\0') {
      FUN_004132e8(param_1,param_2);
    }
  }
  else {
    param_2 = *pfVar1;
  }
  return (float10)param_2;
}

