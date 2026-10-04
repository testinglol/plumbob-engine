
void __thiscall FUN_0046f8e4(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 8) = 0;
  **(undefined1 **)(param_1 + 4) = 0;
  iVar1 = (**(code **)*param_2)();
  if (iVar1 < 0) {
    iVar1 = (**(code **)*param_2)();
  }
  FUN_0046f847(param_2[1],iVar1);
  return;
}

