
void FUN_005e6ab3(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar2;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = (undefined4 *)extraout_ECX[1];
  for (puVar2 = (undefined4 *)*extraout_ECX; puVar2 != puVar1; puVar2 = puVar2 + 0xb) {
    (**(code **)*puVar2)(0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046adc1();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

