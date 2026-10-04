
undefined4 FUN_005565f0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0x10);
  piVar2 = *(int **)(unaff_EBP + 0x14);
  **(undefined4 **)(unaff_EBP + 0x18) = 0;
  *piVar2 = 0;
  *piVar1 = 0;
  iVar6 = *(int *)(extraout_ECX + 0xe4);
  if (iVar6 == -1) {
    uVar5 = 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + 0x17) = 0;
    *(undefined1 *)(unaff_EBP + 0x13) = 0;
    if (iVar6 == -1) {
      iVar6 = 0;
    }
    else {
      FUN_00425db3(iVar6);
      iVar6 = FUN_00410315();
    }
    iVar3 = *(int *)(unaff_EBP + 0xc);
    *piVar1 = iVar6;
    if (iVar3 <= iVar6) {
      *(undefined1 *)(unaff_EBP + 0x13) = 1;
      *piVar2 = iVar6 - *(int *)(unaff_EBP + 0xc);
    }
    FUN_00429c21();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar4 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0xe4),unaff_EBP + -0x28);
    if ((cVar4 != '\0') &&
       (iVar6 = *(int *)(unaff_EBP + -0x1c), iVar3 = *(int *)(unaff_EBP + 8),
       **(int **)(unaff_EBP + 0x18) = iVar6, iVar3 <= iVar6)) {
      *(undefined1 *)(unaff_EBP + 0x17) = 1;
    }
    if (*(char *)(unaff_EBP + 0x13) == '\0') {
      if (*(char *)(unaff_EBP + 0x17) == '\0') {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = 0xfffffffe;
      }
    }
    else if (*(char *)(unaff_EBP + 0x17) == '\0') {
      uVar5 = 0xfffffffd;
    }
    else {
      uVar5 = 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

