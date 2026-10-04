
void __fastcall FUN_005f6e62(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + -0x4c) < *(int *)(param_1 + -0x44)) {
    iVar1 = (**(code **)(*(int *)(param_1 + -0x124) + 0x19c))();
    iVar1 = iVar1 - *(int *)(param_1 + 4);
    if (iVar1 < *(int *)(param_1 + -0x4c)) {
      iVar1 = *(int *)(param_1 + -0x4c);
    }
    (**(code **)(*(int *)(param_1 + -0x124) + 0x1a8))(iVar1);
  }
  return;
}

