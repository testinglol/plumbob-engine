
bool __thiscall FUN_004b0db9(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(int *)(param_1 + 0x84) = param_2;
  uVar2 = *(undefined4 *)(*(int *)(param_2 + 0x48) + 8);
  FUN_005cad3e(uVar2);
  iVar1 = FUN_005d013d(uVar2);
  return -1 < iVar1;
}

