
void FUN_004c3c93(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066886c;
  puVar1 = (undefined4 *)extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  extraout_ECX[2] = 0;
  if ((undefined4 *)extraout_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[1])(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[1] = 0;
  *extraout_ECX = &PTR_LAB_006683f4;
  return;
}

