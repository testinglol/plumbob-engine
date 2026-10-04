
void FUN_00458871(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_006e50a8 = param_2;
  iVar1 = param_1[1];
  iVar2 = *param_1;
  FUN_00458485(param_2,0);
  if (((((iVar1 - iVar2) / 0x44 == (param_1[1] - *param_1) / 0x44) &&
       ((*(uint *)(param_2 + 0x40) >> 4 & 1) == 0)) && ((*(uint *)(param_2 + 0x40) >> 3 & 1) != 0))
     && (DAT_006f2a04 == '\0')) {
    FUN_00458cd7(param_2);
  }
  return;
}

