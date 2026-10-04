
bool FUN_005bf655(void)

{
  undefined4 uVar1;
  char cVar2;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00634c24();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  cVar2 = FUN_005bf513(uVar1);
  if (cVar2 == '\0') {
    cVar2 = FUN_005bf41a(uVar1,0);
    if (cVar2 == '\0') {
      bVar3 = false;
    }
    else {
      FUN_005bf6e7(uVar1);
      bVar3 = true;
    }
  }
  else {
    FUN_005be772(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar2 = FUN_005be9b0(2,2,1);
    bVar3 = cVar2 != '\0';
    if (bVar3) {
      FUN_005bebb1();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005be8cc();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar3;
}

