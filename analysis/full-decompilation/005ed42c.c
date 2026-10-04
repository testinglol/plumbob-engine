
bool FUN_005ed42c(void)

{
  char cVar1;
  undefined4 uVar2;
  uint bFailIfExists;
  LPCSTR lpNewFileName;
  LPCSTR lpExistingFileName;
  BOOL BVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 4))();
  if (cVar1 != '\0') {
    (**(code **)(*extraout_ECX + 8))();
  }
  uVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x54))();
  FUN_005b86bd(uVar2);
  bFailIfExists = (uint)*(byte *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  lpNewFileName = (LPCSTR)FUN_004096c2();
  lpExistingFileName = (LPCSTR)FUN_004096c2();
  BVar3 = CopyFileA(lpExistingFileName,lpNewFileName,bFailIfExists);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return BVar3 != 0;
}

