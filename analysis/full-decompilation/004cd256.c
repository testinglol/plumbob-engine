
void FUN_004cd256(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int *piVar1;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668d2c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  for (piVar1 = (int *)extraout_ECX[1]; piVar1 != (int *)extraout_ECX[2]; piVar1 = piVar1 + 1) {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
  }
  FUN_005a5e48(0);
  FUN_005a5e48(0);
  FUN_005a5e48(0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) =
       *(undefined4 *)(-(uint)(extraout_ECX != (undefined4 *)0x0) & (uint)(extraout_ECX + 1));
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

