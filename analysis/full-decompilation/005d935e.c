
undefined4 * FUN_005d935e(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d909f();
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_00673858;
  iVar1 = (**(code **)(iVar1 + 0x10))();
  if (iVar1 == 0) {
    extraout_ECX[10] = 0;
  }
  else {
    extraout_ECX[10] = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

