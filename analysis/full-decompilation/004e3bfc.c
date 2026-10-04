
void __thiscall FUN_004e3bfc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004e3df5(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
    FUN_0059875f();
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - param_2 >> 4) * -0x10;
  return;
}

