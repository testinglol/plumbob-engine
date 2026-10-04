
void FUN_0048bd70(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int *piVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667ef4;
  piVar3 = (int *)extraout_ECX[0xb];
  piVar1 = (int *)extraout_ECX[0xc];
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (piVar3 != piVar1) {
    do {
      if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != (int *)extraout_ECX[0xc]);
  }
  FUN_0052ea87(extraout_ECX[0xb],extraout_ECX[0xc]);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0048bd37();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0048bd37();
  uVar2 = extraout_ECX[0xb];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00492fa7();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

