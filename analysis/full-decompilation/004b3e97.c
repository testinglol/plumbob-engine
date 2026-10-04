
void __thiscall FUN_004b3e97(int param_1,int *param_2,int *param_3,char *param_4)

{
  int iVar1;
  
  *param_2 = ((int)*param_4 - (int)param_4[1]) * (8 << ((byte)DAT_006f0088 & 0x1f)) + DAT_006f0080;
  iVar1 = DAT_006f0084 + ((int)*param_4 + (int)param_4[1]) * (4 << ((byte)DAT_006f0088 & 0x1f));
  *param_3 = iVar1;
  *param_3 = iVar1 - *(int *)(param_1 + (0x4c - DAT_006f0088) * 4) * (param_4[2] + -1);
  return;
}

