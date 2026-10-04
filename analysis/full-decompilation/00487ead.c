
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00487ead(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(int *)(param_1 + 0x3c) != 0) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x1ac), iVar1 != 0)) &&
     (*(char *)(param_1 + 0x75) == '\0')) {
    *(undefined1 *)(param_1 + 0x98) = 1;
    *(undefined1 *)(param_1 + 0x99) = 1;
    *(undefined1 *)(param_1 + 0x9a) = *(undefined1 *)(param_1 + 0x78);
    FUN_00432249();
    if (*(char *)(param_1 + 0x78) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = _DAT_00667cc8;
      if (*(char *)(param_1 + 0x77) == '\0') {
        uVar2 = 0x3f800000;
      }
    }
    FUN_004cfaaa(iVar1,*(undefined1 *)(param_1 + 0x99),*(undefined1 *)(param_1 + 0x9a),uVar2);
  }
  return;
}

