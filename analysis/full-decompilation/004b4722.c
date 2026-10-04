
void __thiscall FUN_004b4722(int param_1,float param_2)

{
  float *pfVar1;
  float *pfVar2;
  
  pfVar1 = &DAT_006c7410;
  if (DAT_006c7410 <= param_2) {
    pfVar1 = &param_2;
  }
  pfVar2 = (float *)(param_1 + 0x48);
  *pfVar2 = *pfVar1;
  pfVar1 = &DAT_006c740c;
  if (*pfVar2 <= DAT_006c740c) {
    pfVar1 = pfVar2;
  }
  *pfVar2 = *pfVar1;
  return;
}

