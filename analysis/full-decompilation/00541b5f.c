
void FUN_00541b5f(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int unaff_EBP;
  int *piStack_c;
  int *piStack_8;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 0xc);
  if (*piVar2 != 0) {
    piVar1 = (int *)(*piVar2 + 0x20);
    *piVar1 = *piVar1 + 1;
  }
  *(int *)(unaff_EBP + 0xc) = *piVar2;
  piStack_8 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piStack_c = (int *)(unaff_EBP + 0xc);
  cVar3 = (**(code **)(unaff_EBP + 0x14))();
  if (cVar3 == '\0') {
    piStack_c = piStack_8;
    *(int ***)(unaff_EBP + 8) = &piStack_c;
    piStack_8 = (int *)*(undefined4 *)(unaff_EBP + 0x14);
    FUN_005412dc(unaff_EBP + 0xc);
    FUN_00541e59(piVar2);
  }
  else {
    piStack_8 = piVar2 + 1;
    piStack_c = piVar2;
    FUN_00541be5(*(undefined4 *)(unaff_EBP + 8));
    piStack_8 = (int *)(unaff_EBP + 0xc);
    piStack_c = (int *)0x541bab;
    FUN_005412f4();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    piStack_8 = (int *)0x541bd8;
    FUN_0053d900();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

