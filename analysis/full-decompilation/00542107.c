
void FUN_00542107(void)

{
  int iVar1;
  char cVar2;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  int iStack_14;
  int iStack_10;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 0xc) = iVar4;
  iVar3 = iVar4 * 2 + 2;
  if (iVar3 < *(int *)(unaff_EBP + 0x10)) {
    do {
      iStack_14 = iVar1 + iVar3 * 4;
      iStack_10 = iStack_14 + -4;
      cVar2 = (**(code **)(unaff_EBP + 0x18))();
      iVar4 = iVar3;
      if (cVar2 != '\0') {
        iVar4 = iVar3 + -1;
      }
      iStack_10 = iVar1 + iVar4 * 4;
      iStack_14 = 0x542148;
      FUN_005414d4();
      iVar3 = iVar4 * 2 + 2;
    } while (iVar3 < *(int *)(unaff_EBP + 0x10));
  }
  if (iVar3 == *(int *)(unaff_EBP + 0x10)) {
    iStack_10 = iVar1 + -4 + iVar3 * 4;
    iStack_14 = 0x542165;
    FUN_005414d4();
    iVar4 = iVar3 + -1;
  }
  iStack_10 = *(undefined4 *)(unaff_EBP + 0x18);
  *(int **)(unaff_EBP + 0x10) = &iStack_14;
  FUN_005414bc(unaff_EBP + 0x14);
  FUN_00542270(iVar1,iVar4,*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    iStack_10 = 0x542197;
    FUN_0053c286();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

