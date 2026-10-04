
void __thiscall FUN_00466fe4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    puVar3 = *(ushort **)(iVar2 + 0x14);
    if ((*(int *)(puVar3 + 0x1a) != 0) &&
       ((param_2 == 0 || (((*puVar3 & 0xc00) >> 10) + 1 == param_2)))) {
      FUN_004682e5();
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  return;
}

