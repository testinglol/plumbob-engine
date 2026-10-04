
void __fastcall FUN_005e9cf1(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x58))();
  iVar2 = *(int *)(param_1 + -0x4c) - *(int *)(param_1 + -0x54);
  iVar1 = (iVar2 / iVar1) * iVar1;
  if (iVar1 - iVar2 != 0) {
    FUN_004ec1a7(iVar1);
  }
  (**(code **)(*(int *)(param_1 + -0xd4) + 0x168))();
  return;
}

