
undefined4 __fastcall FUN_005fbec1(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xf0c);
  *(undefined4 *)(param_1 + 0xf64) = 0;
  if (iVar1 != 0) {
    FUN_005b8e25(iVar1);
    FUN_005b95c0(iVar1);
    *(undefined4 *)(param_1 + 0xf0c) = 0;
  }
  return 1;
}

