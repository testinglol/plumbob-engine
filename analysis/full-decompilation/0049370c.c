
undefined4 __fastcall FUN_0049370c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 != *(int *)(param_1 + 0x24)) {
    do {
      iVar1 = iVar2 + -0x34;
      FUN_0049363a(iVar1);
      FUN_00492bba(*(undefined4 *)(iVar2 + -4));
      iVar2 = iVar1;
    } while (iVar1 != *(int *)(param_1 + 0x24));
  }
  iVar2 = FUN_00401f73();
  if (iVar2 != 0) {
    FUN_00492bc4();
  }
  uVar3 = FUN_00492b26();
  FUN_00540a5b(uVar3);
  FUN_00540ecf(uVar3);
  return 0;
}

