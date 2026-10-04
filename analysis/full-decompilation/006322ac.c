
undefined4 __fastcall FUN_006322ac(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_00633e5e((int)param_1 + *(int *)(*param_1 + 4) + 0x38);
  }
  iVar1 = *(int *)(*param_1 + 4);
  uVar2 = *(uint *)(iVar1 + 8 + (int)param_1);
  if (uVar2 != 0) {
    *(uint *)((int)param_1 + iVar1 + 8) = uVar2 | 2;
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
      FUN_00633e69((int)param_1 + *(int *)(*param_1 + 4) + 0x38);
    }
    return 0;
  }
  if (*(int *)((int)param_1 + iVar1 + 0x20) != 0) {
    FUN_006323f9();
  }
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_00633e5e(iVar1 + 0x34);
  }
  return 1;
}

