
undefined4 FUN_005c10b4(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = FUN_005c1560(**(undefined4 **)(unaff_EBP + 8),**(undefined4 **)(unaff_EBP + 0xc),
                       *(undefined4 *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  iVar1 = *(int *)(extraout_ECX + 0x14);
  iVar4 = *(int *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  if (iVar4 != iVar1) {
    do {
      cVar2 = FUN_005c163f(*(undefined4 *)(unaff_EBP + -0x10));
      if (cVar2 != '\0') break;
      iVar4 = iVar4 + 0x20;
    } while (iVar4 != *(int *)(unaff_EBP + -0x14));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c15c8();
  if (iVar4 == *(int *)(extraout_ECX + 0x14)) {
    uVar3 = FUN_005c1560(**(undefined4 **)(unaff_EBP + 8),**(undefined4 **)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005c125b(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c15c8();
    uVar3 = 0;
  }
  else {
    uVar3 = 3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

