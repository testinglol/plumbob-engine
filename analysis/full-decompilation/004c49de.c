
void __thiscall FUN_004c49de(float *param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  float10 fVar3;
  
  param_1[0x7a] = *param_2;
  param_1[0x7b] = param_2[1];
  param_1[0x7c] = param_2[2];
  FUN_0049b802();
  param_2 = (float *)0x0;
  pfVar2 = param_1;
  do {
    iVar1 = 0;
    do {
      fVar3 = (float10)FUN_004c496a((int)param_2 + -5,iVar1 + -5);
      *pfVar2 = (float)fVar3;
      iVar1 = iVar1 + 1;
      pfVar2 = pfVar2 + 1;
    } while (iVar1 < 0xb);
    param_2 = (float *)((int)param_2 + 1);
  } while ((int)param_2 < 0xb);
  *(undefined2 *)(param_1 + 0x79) = 1;
  return;
}

