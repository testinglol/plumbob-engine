
undefined4 FUN_00608135(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 < 0) || (5 < param_1)) {
    FUN_004096c2();
    uVar3 = 0;
  }
  else {
    iVar1 = FUN_005d49d6();
    iVar2 = FUN_004096c2();
    FUN_00608217(&param_1);
    FUN_00431779(iVar2,iVar2 + iVar1);
    uVar3 = 1;
  }
  return uVar3;
}

