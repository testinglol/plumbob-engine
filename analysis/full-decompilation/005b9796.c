
bool FUN_005b9796(void)

{
  LPCSTR lpFileName;
  char cVar1;
  BOOL BVar2;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00634c24();
  lpFileName = *(LPCSTR *)(unaff_EBP + 8);
  cVar1 = FUN_005b9bbe(lpFileName,unaff_EBP + 8);
  if (cVar1 == '\0') {
    BVar2 = DeleteFileA(lpFileName);
    bVar3 = BVar2 != 0;
  }
  else if (*(char *)(*(int *)(unaff_EBP + 8) + 0x10) == '\0') {
    FUN_005b8680();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b96fe(lpFileName,unaff_EBP + -0x18,unaff_EBP + -0x24);
    FUN_005b9348(unaff_EBP + -0x18,unaff_EBP + -0x24);
    BVar2 = DeleteFileA(lpFileName);
    bVar3 = BVar2 != 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    bVar3 = false;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar3;
}

