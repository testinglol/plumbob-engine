
undefined4 __fastcall FUN_004a0cb9(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 3;
  piVar3 = (int *)(param_1 + 0x30);
  do {
    uVar2 = 0;
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar3 = (int *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x28) - *piVar3 >> 3 != 0) {
    do {
      iVar4 = *(int *)(*piVar3 + 4 + uVar2 * 8);
      if (iVar4 != 0) {
        FUN_004c7205();
        FUN_006321f0(iVar4);
      }
      puVar1 = *(undefined4 **)(*piVar3 + uVar2 * 8);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x28) - *piVar3 >> 3));
  }
  FUN_004a1827(*piVar3,*(undefined4 *)(param_1 + 0x28));
  *(undefined1 *)(param_1 + 0x118) = 0;
  return 1;
}

