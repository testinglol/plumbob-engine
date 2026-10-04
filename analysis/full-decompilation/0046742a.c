
void __thiscall FUN_0046742a(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  if (param_2 == 0) {
    while (iVar2 != iVar1) {
      if (*(int *)(*(int *)(iVar2 + 0x14) + 0x34) != 0) {
        FUN_00467999();
      }
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 4);
    }
  }
  else {
    while (iVar2 != iVar1) {
      if ((*(int *)(*(ushort **)(iVar2 + 0x14) + 0x1a) != 0) &&
         (((**(ushort **)(iVar2 + 0x14) & 0xc00) >> 10) + 1 == param_2)) {
        FUN_00467999();
      }
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 4);
    }
  }
  FUN_0046718c(param_2);
  return;
}

