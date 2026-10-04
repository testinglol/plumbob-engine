
uint __fastcall FUN_005ecba2(int *param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = param_1[2];
  if ((uVar1 == 3) || (uVar1 == 2)) {
    uVar1 = (**(code **)(*param_1 + 0x138))();
    if ((uVar1 != 0) && (param_1[4] != 0)) {
      piVar2 = (int *)(**(code **)(*param_1 + 0x13c))();
      uVar1 = (**(code **)(*piVar2 + 0x38))(param_1[4]);
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}

