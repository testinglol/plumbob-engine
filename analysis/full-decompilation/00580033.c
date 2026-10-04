
uint __fastcall FUN_00580033(int *param_1)

{
  uint uVar1;
  
  param_1[5] = 0;
  uVar1 = (**(code **)(*param_1 + 0xa8))();
  if ((char)param_1[7] != '\0') {
    *(undefined1 *)(param_1 + 7) = 0;
  }
  return uVar1 & 0xffffff00;
}

