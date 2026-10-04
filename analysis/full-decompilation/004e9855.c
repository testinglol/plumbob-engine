
short FUN_004e9855(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_004e8d71(param_1);
  if (iVar2 != 0) {
    iVar2 = FUN_0043acf5(iVar2);
    if ((iVar2 != 0) && (sVar1 = FUN_00440b6d(iVar2), sVar1 != 0)) {
      return sVar1;
    }
  }
  return -1;
}

