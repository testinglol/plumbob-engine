
void FUN_005d95c9(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673b38;
  puVar1 = (undefined4 *)extraout_ECX[0x5c];
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
    extraout_ECX[0x5c] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x80));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  uVar2 = extraout_ECX[0x73];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_005db425();
  uVar2 = extraout_ECX[0x58];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0040f6e0();
  uVar2 = extraout_ECX[0x55];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0040f6e0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_006029b3();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006029b3();
  uVar2 = extraout_ECX[0xd];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

