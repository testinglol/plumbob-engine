
undefined4 __fastcall FUN_00488322(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 != *(int *)(param_1 + 0x24)) {
    do {
      iVar1 = iVar2 + -0x3c;
      FUN_004883af(iVar1);
      FUN_00492bba(*(undefined4 *)(iVar2 + -0xc));
      iVar2 = iVar1;
    } while (iVar1 != *(int *)(param_1 + 0x24));
  }
  iVar2 = FUN_00401f73();
  if (iVar2 != 0) {
    FUN_00492bc4();
    DAT_006e5780 = 1;
  }
  return 0;
}

