
void FUN_0040149e(void)

{
  undefined4 *puVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = operator_new(0x1c);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8680();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040155d(puVar1);
  *puVar1 = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(int *)(extraout_ECX + 8) = (int)*(short *)(extraout_ECX + 4);
  *(int *)(extraout_ECX + 0xc) = *(short *)(extraout_ECX + 4) + -1;
  return;
}

