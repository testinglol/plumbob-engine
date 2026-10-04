
void FUN_00541e0a(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  iVar3 = *piVar2;
  if (iVar3 != 0) {
    piVar1 = (int *)(iVar3 + 0x20);
    *piVar1 = *piVar1 + 1;
  }
  *(int *)(unaff_EBP + 8) = *piVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005412f4(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_005412f4(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 8) != 0) {
    FUN_0053d900();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

