
void __fastcall FUN_00493210(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x20))();
  if (iVar1 != 0) {
    param_1[1] = 3;
    return;
  }
  param_1[1] = 1;
  return;
}

