
undefined4 FUN_005d4a0d(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    FUN_004dfef0(extraout_ECX);
  }
  else {
    iVar3 = (*(code *)PTR__strlen_006d7028)(*(undefined4 *)(unaff_EBP + 0xc));
    if (iVar3 == 0) {
      *(undefined1 *)(unaff_EBP + 0xf) = *(undefined1 *)(unaff_EBP + 0xb);
      FUN_0055e4e2(unaff_EBP + 0xf);
      iVar3 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_00401a3c(*extraout_ECX,iVar3);
    }
    else {
      iVar4 = FUN_004558e0(*(undefined4 *)(unaff_EBP + 0xc),0,iVar3);
      if (iVar4 == -1) {
        FUN_005b8d9d(unaff_EBP + 0xf,8);
        *(undefined4 *)(unaff_EBP + -4) = 2;
        FUN_00401a79();
      }
      else {
        FUN_005d4be4(unaff_EBP + -0x1c,iVar4);
        iVar1 = extraout_ECX[1];
        iVar2 = *extraout_ECX;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        piVar5 = (int *)FUN_005d4c15(unaff_EBP + -0x28,((iVar1 - iVar2) - iVar4) - iVar3);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        if (piVar5 != extraout_ECX) {
          FUN_00431779(*piVar5,piVar5[1]);
        }
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00401729();
        *(undefined1 *)(unaff_EBP + 0xf) = *(undefined1 *)(unaff_EBP + 0xb);
        FUN_0055e4e2(unaff_EBP + 0xf);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
        *(undefined1 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x10) = 1;
        FUN_00401729();
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

