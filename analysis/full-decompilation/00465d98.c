
undefined4 __fastcall FUN_00465d98(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    FUN_005c2ee6();
    FUN_006321f0(iVar1);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}

