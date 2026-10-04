
int * FUN_005733e9(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00575bc0(unaff_EBP + -0x14,unaff_EBP + -0x38);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if ((((iVar2 == 0) || (*(int *)(iVar2 + 0x10) != 1)) ||
      (piVar1 = (int *)FUN_00573466(*(undefined4 *)(iVar2 + 0x14)), piVar1 == (int *)0x0)) ||
     (iVar2 = (**(code **)(*piVar1 + 0x28))(), iVar2 != 2)) {
    piVar1 = (int *)0x0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar1;
}

