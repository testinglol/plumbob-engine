
uint __thiscall FUN_005def4d(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX & 0xffffff00;
  if (*(int **)(param_1 + 0x48) == (int *)0x0) {
    if (*(int *)(param_1 + 0x4c) != 0) {
      uVar1 = FUN_00606395(param_1,param_4,param_3);
    }
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x1c))
                      (*(undefined4 *)(param_2 + 0x48),param_3,param_4);
  }
  return uVar1;
}

