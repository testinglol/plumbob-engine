
void FUN_005c3314(void)

{
  int *piVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  iVar2 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar2 == 0) {
    piVar1 = (int *)extraout_ECX[1];
    if (piVar1 != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    }
  }
  else if ((iVar2 == 1) && (iVar2 = extraout_ECX[1], iVar2 != 0)) {
    FUN_005b8e25(iVar2);
    FUN_005b95c0(iVar2);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042004f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

