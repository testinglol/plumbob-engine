
undefined4 __fastcall FUN_0048836c(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x24); iVar1 != *(int *)(param_1 + 0x28); iVar1 = iVar1 + 0x3c) {
    FUN_004883af(iVar1);
    FUN_00492bb0(*(undefined4 *)(iVar1 + 0x30));
  }
  iVar1 = FUN_00401f73();
  if (iVar1 != 0) {
    FUN_00492bc4();
    DAT_006e5780 = 1;
  }
  return 0;
}

