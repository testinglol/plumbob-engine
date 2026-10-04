
void __fastcall FUN_00596389(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x130) = param_2;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    FUN_00596389();
  }
  return;
}

