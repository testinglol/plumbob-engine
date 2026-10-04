
void __thiscall FUN_0048be02(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x38) = param_2;
  for (; iVar1 != *(int *)(param_1 + 0x30); iVar1 = iVar1 + 4) {
    FUN_0048be02(param_2);
  }
  return;
}

