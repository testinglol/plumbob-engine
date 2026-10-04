
undefined4 __fastcall FUN_005941db(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
  cVar1 = FUN_005b90ab(iVar4);
  if (cVar1 == '\0') {
LAB_00594231:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        cVar1 = FUN_005b9169(*(undefined4 *)(*(int *)(param_1 + 4) + iVar3 * 8));
        if (cVar1 == '\0') goto LAB_00594231;
        cVar1 = FUN_005b9169(*(undefined4 *)(*(int *)(param_1 + 4) + 4 + iVar3 * 8));
        if (cVar1 == '\0') goto LAB_00594231;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    uVar2 = 1;
  }
  return uVar2;
}

