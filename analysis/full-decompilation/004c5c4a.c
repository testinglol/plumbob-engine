
undefined4 __fastcall FUN_004c5c4a(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  piVar1 = (int *)(param_1 + 0x24);
  uVar4 = 0;
  if (*(int *)(param_1 + 0x28) - *piVar1 >> 3 != 0) {
    do {
      iVar2 = *(int *)(*piVar1 + 4 + uVar4 * 8);
      if (iVar2 != 0) {
        FUN_004c7205();
        FUN_006321f0(iVar2);
      }
      puVar3 = *(undefined4 **)(*piVar1 + uVar4 * 8);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(param_1 + 0x28) - *piVar1 >> 3));
  }
  FUN_004a1827(*piVar1,*(undefined4 *)(param_1 + 0x28));
  *(undefined1 *)(param_1 + 0x10c) = 0;
  return 1;
}

