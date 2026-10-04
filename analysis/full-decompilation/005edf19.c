
void __fastcall FUN_005edf19(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(char *)(param_1 + 0x1b1) == '\0') || (*(char *)(param_1 + 0x1b0) == '\0')) {
    *(undefined1 *)(param_1 + 0x1b1) = 1;
    FUN_005dae65(param_1);
    piVar3 = (int *)(**(code **)*DAT_006fe8bc)();
    piVar1 = (int *)(param_1 + 0xd4);
    (**(code **)(*piVar3 + 0x34))(*(undefined4 *)(param_1 + 0xd4));
    *piVar1 = *piVar1 + 1;
    iVar2 = *piVar1;
    if ((iVar2 < 4) && (*(int *)(param_1 + 0xd8 + iVar2 * 4) != 0)) {
      iVar2 = *(int *)(param_1 + 0xe8 + iVar2 * 4);
      if (iVar2 != 0) {
        FUN_005dadff(param_1,iVar2,0);
      }
      *(undefined1 *)(param_1 + 0x170) = 1;
    }
  }
  return;
}

