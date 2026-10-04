
int FUN_005c1c7f(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  FUN_005c26e9(unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + 0x10));
  iVar2 = *(int *)(unaff_EBP + -0x10);
  if (iVar2 == *extraout_ECX) {
    iVar2 = FUN_004096c2();
    while( true ) {
      iVar3 = FUN_00401f73();
      if (iVar2 == iVar3) break;
      FUN_005c2efd(unaff_EBP + -0x1c,iVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar3 = FUN_005c1e25(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + -0x1c),0,*(undefined4 *)(unaff_EBP + 0x14));
      if ((iVar3 == 0) || (iVar3 == 4)) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        goto LAB_005c1d3b;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar2 = iVar2 + 0xc;
    }
  }
  else {
    for (iVar3 = *(int *)(iVar2 + 0x14); iVar3 != *(int *)(iVar2 + 0x18); iVar3 = iVar3 + 4) {
      iVar1 = FUN_005c1c7f(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),iVar3,
                           *(undefined4 *)(unaff_EBP + 0x14));
      if (iVar1 == 0) {
        iVar3 = 0;
        goto LAB_005c1d3b;
      }
    }
  }
  iVar3 = 5;
LAB_005c1d3b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

