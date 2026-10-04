
undefined4 __fastcall FUN_00493761(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  for (iVar2 = *(int *)(param_1 + 0x24); iVar2 != *(int *)(param_1 + 0x28); iVar2 = iVar2 + 0x34) {
    FUN_0049363a(iVar2);
    FUN_00492bb0(*(undefined4 *)(iVar2 + 0x30));
  }
  iVar2 = FUN_00401f73();
  if (iVar2 != 0) {
    FUN_00492bc4();
  }
  uVar1 = FUN_00492b26();
  FUN_00540a5b(uVar1);
  FUN_00540ecf(uVar1);
  return 0;
}

