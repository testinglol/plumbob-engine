
void __thiscall FUN_004b3f04(int param_1,int *param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = ((int)param_3[1] + (int)*param_3) * (4 << ((byte)DAT_006f0088 & 0x1f)) + DAT_006f0084;
  *param_2 = iVar1;
  if (param_3[2] != '\0') {
    *param_2 = iVar1 - *(int *)(param_1 + (0x4c - DAT_006f0088) * 4) * (param_3[2] + -1);
  }
  return;
}

