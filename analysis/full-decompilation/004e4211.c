
void FUN_004e4211(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_0043ac6a();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      uVar2 = FUN_0043ad1f(iVar3);
      FUN_004e4244(uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

