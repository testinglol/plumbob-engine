
uint __thiscall FUN_00406dea(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_004659fc(0);
  if (*(int **)(param_1 + 0xc) == (int *)0x0) {
    uVar1 = uVar1 & 0xffff0000;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x60))(param_2);
  }
  return uVar1;
}

