
uint FUN_004d8d0b(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int unaff_EBP;
  uint uVar5;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  uVar5 = 0;
  iVar2 = piVar1[1];
  iVar4 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar2 - iVar4) / 0xc != 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
    do {
      cVar3 = FUN_004317d5(unaff_EBP + 0xc,*(int *)(unaff_EBP + 8) + iVar4);
      if (cVar3 != '\0') goto LAB_004d8d62;
      iVar2 = piVar1[1];
      iVar4 = *piVar1;
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0xc;
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)((iVar2 - iVar4) / 0xc));
  }
  uVar5 = 0xffffffff;
LAB_004d8d62:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

