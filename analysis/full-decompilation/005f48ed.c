
void __fastcall FUN_005f48ed(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar1 = (int *)(param_1 + 0x168);
  if (*(int *)(param_1 + 0x16c) - *piVar1 >> 2 != 0) {
    do {
      iVar2 = *(int *)(*piVar1 + uVar3 * 4);
      if (iVar2 != 0) {
        FUN_005f1d9a();
        FUN_006321f0(iVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0x16c) - *piVar1 >> 2));
  }
  FUN_0052ea87(*piVar1,*(undefined4 *)(param_1 + 0x16c));
  piVar1 = (int *)(param_1 + 0x174);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x178) - *piVar1 >> 2 != 0) {
    do {
      iVar2 = *(int *)(*piVar1 + uVar3 * 4);
      if (iVar2 != 0) {
        FUN_005f1d9a();
        FUN_006321f0(iVar2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0x178) - *piVar1 >> 2));
  }
  FUN_0052ea87(*piVar1,*(undefined4 *)(param_1 + 0x178));
  *(undefined4 *)(param_1 + 0x180) = 0;
  return;
}

