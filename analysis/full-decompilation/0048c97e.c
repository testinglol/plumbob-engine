
void __thiscall FUN_0048c97e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((short)param_2 != *(short *)(param_1 + 0x2e)) {
    iVar1 = FUN_00492b10(*(short *)(param_1 + 0x2e));
    if (iVar1 != 0) {
      FUN_00432189(*(uint *)(iVar1 + 0x114) & 0x1e);
      FUN_00432189(*(uint *)(iVar1 + 0x114) & 0x17);
    }
    iVar1 = FUN_00492b10(param_2);
    FUN_0048d4dc(iVar1,param_3,param_4);
    if (iVar1 != 0) {
      if ((*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x30)) / 0x44 == 0) {
        uVar2 = 8;
      }
      else {
        uVar2 = 1;
        iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 8);
      }
      if (iVar1 != 0) {
        param_2._0_2_ = *(short *)(iVar1 + 0xf0);
        FUN_00432189(*(uint *)(iVar1 + 0x114) & 0x1f | uVar2);
      }
    }
    *(short *)(param_1 + 0x2e) = (short)param_2;
  }
  return;
}

