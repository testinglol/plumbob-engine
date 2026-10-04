
void __thiscall FUN_004d5e20(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x100) + 4))();
  iVar2 = (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4)) / 0xc;
  if (*(int *)(param_1 + 0xf0) <= iVar2) {
    iVar1 = *(int *)(param_1 + 0xf4);
    FUN_004d5f89(iVar1,iVar1 + (iVar2 / 2) * 0xc);
  }
  FUN_004d5f61(param_2);
  (**(code **)(*(int *)(param_1 + 0x100) + 8))();
  return;
}

