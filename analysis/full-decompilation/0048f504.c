
undefined4 __fastcall FUN_0048f504(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 != 0) {
    if (DAT_006e57a0 == '\0') {
      FUN_004790b4(iVar2);
      FUN_004616c3(iVar2);
      FUN_004b0de0();
      FUN_0040766a(0x91,0);
    }
    else {
      FUN_004616c3(iVar2);
      FUN_004616c3(*(undefined4 *)(param_1 + 0x28));
    }
    iVar2 = *(int *)(param_1 + 0x2c);
    if (iVar2 == 0) {
      FUN_00492cca();
    }
    else {
      if (iVar2 < 1) {
        uVar1 = __ftol();
        FUN_00492bba(uVar1);
      }
      else {
        FUN_00492bb0(iVar2 * DAT_006c5fe8);
      }
      FUN_00492bc4();
      FUN_00492c68();
    }
  }
  return 0;
}

