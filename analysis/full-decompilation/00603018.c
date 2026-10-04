
undefined4 FUN_00603018(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_8 [4];
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    FUN_00603147(local_8,iVar2 + 0x10);
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

