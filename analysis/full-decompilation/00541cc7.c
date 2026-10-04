
void FUN_00541cc7(void)

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
    piVar1 = (int *)(*piVar2 + 0x58);
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
    FUN_005414bc(unaff_EBP + 0xc);
    FUN_00541f62(piVar2);
  }
  else {
    piStack_8 = piVar2 + 1;
    piStack_c = piVar2;
    FUN_00541d4d(*(undefined4 *)(unaff_EBP + 8));
    piStack_8 = (int *)(unaff_EBP + 0xc);
    piStack_c = (int *)0x541d13;
    FUN_005414d4();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    piStack_8 = (int *)0x541d40;
    FUN_0053c286();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

