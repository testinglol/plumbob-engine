
uint __thiscall FUN_005dd8f5(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x110))(param_2,param_3,param_4,param_1);
  }
  return uVar1 & 0xffffff00;
}

