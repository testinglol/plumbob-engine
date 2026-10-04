
int * FUN_0046c161(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  for (piVar3 = *(int **)(extraout_ECX + 4);
      (piVar3 != *(int **)(extraout_ECX + 8) &&
      ((*(int *)(iVar1 + 8) != *piVar3 || (*(int *)(iVar1 + 0x10) != piVar3[1]))));
      piVar3 = piVar3 + 0xb) {
  }
  if (piVar3 == *(int **)(extraout_ECX + 8)) {
    uVar2 = FUN_0046bed4(iVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046c39a(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046c1d5();
    piVar3 = (int *)(*(int *)(extraout_ECX + 8) + -0x2c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

