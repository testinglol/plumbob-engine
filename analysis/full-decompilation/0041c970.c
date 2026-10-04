
void FUN_0041c970(void)

{
  undefined4 *puVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = operator_new(0x110);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_0046f824(puVar1 + 3,0,0x104);
    *puVar1 = &PTR_FUN_006664e8;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[10] = (int)puVar1;
  FUN_004131e6(puVar1);
  (**(code **)(*extraout_ECX + 0x18))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

