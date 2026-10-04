
undefined4 __thiscall FUN_004bb786(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = FUN_004b5717();
    FUN_004bba42(*(undefined4 *)(iVar1 + 0x60));
  }
  return *(undefined4 *)(*param_1 + (param_1[1] + param_2) * 4);
}

