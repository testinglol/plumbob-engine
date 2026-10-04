
void __thiscall FUN_00434ffd(char *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = ((param_2 * 0x40 + -0x40 + (int)*param_1) * 0x40 + (int)param_1[1]) * 2;
    *param_1 = (&DAT_006de81c)[iVar1];
    param_1[1] = (&DAT_006de81d)[iVar1];
  }
  return;
}

