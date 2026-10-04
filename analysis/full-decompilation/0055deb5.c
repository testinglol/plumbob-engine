
uint __thiscall FUN_0055deb5(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x148);
  uVar2 = *(uint *)(uVar1 + 8);
  while( true ) {
    if (uVar2 == uVar1) {
      return uVar2 & 0xffffff00;
    }
    iVar3 = FUN_0042ba25(*(undefined4 *)(*(int *)(uVar2 + 0x14) + 0x1d8));
    if ((iVar3 == 2) && ((*(uint *)(*(int *)(uVar2 + 0x14) + 0x1b4) & param_2) != 0)) break;
    FUN_0041674f();
    uVar1 = *(uint *)(param_1 + 0x148);
  }
  return CONCAT31((int3)((uint)*(int *)(uVar2 + 0x14) >> 8),1);
}

