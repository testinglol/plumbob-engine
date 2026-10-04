
undefined4 FUN_005caaab(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x6c))(param_1);
    (**(code **)(*param_1 + 8))(param_1);
  }
  return uVar1;
}

