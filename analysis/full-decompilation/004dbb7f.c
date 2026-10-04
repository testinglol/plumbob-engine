
bool FUN_004dbb7f(void)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00634c24();
  FUN_00636080();
  if (*(int *)(unaff_EBP + 0xc) < 0xfa01) {
    uVar2 = FUN_004ee344(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                         unaff_EBP + -0xfa28);
    FUN_004d6581(*(undefined4 *)(unaff_EBP + 0x14));
    FUN_005ed06b(*(undefined4 *)(unaff_EBP + 0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_005ed121(2,1,1);
    bVar3 = cVar1 != '\0';
    if (bVar3) {
      FUN_005ed2dd(unaff_EBP + -0xfa28,uVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005ed0c3();
  }
  else {
    bVar3 = false;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar3;
}

