
undefined4 FUN_00541822(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 0xc) - *(int *)(unaff_EBP + 8) >> 2;
  while (iVar3 = iVar5, 0 < iVar3) {
    iVar5 = iVar3 >> 1;
    iVar1 = *(int *)(unaff_EBP + 8) + iVar5 * 4;
    iVar2 = **(int **)(unaff_EBP + 0x10);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar4 = (**(code **)(unaff_EBP + 0x14))(iVar1,unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined1 *)(unaff_EBP + 0xf) = uVar4;
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      FUN_0053c286();
    }
    if (*(char *)(unaff_EBP + 0xf) != '\0') {
      *(int *)(unaff_EBP + 8) = iVar1 + 4;
      iVar5 = iVar3 + (-1 - iVar5);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

