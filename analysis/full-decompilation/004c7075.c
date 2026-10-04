
int * FUN_004c7075(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  for (puVar2 = (undefined4 *)*extraout_ECX;
      (puVar2 != (undefined4 *)extraout_ECX[1] && (*(int *)*puVar2 != iVar1)); puVar2 = puVar2 + 2)
  {
  }
  if (puVar2 == (undefined4 *)extraout_ECX[1]) {
    piVar3 = operator_new(0x28);
    *(int **)(unaff_EBP + 8) = piVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      FUN_004c94d1();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046ea4d();
      *(undefined1 *)(piVar3 + 6) = 1;
      *piVar3 = iVar1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(unaff_EBP + -0x14) = piVar3;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    FUN_004c946e(unaff_EBP + -0x14);
  }
  else {
    puVar2[1] = puVar2[1] + 1;
    piVar3 = (int *)*puVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

