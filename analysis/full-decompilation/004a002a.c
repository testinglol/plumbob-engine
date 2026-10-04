
int FUN_004a002a(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_005d5fbc(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  *(undefined4 *)(extraout_ECX + 0x1c) = 0;
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  *(undefined4 *)(extraout_ECX + 0x24) = 0;
  *(undefined4 *)(extraout_ECX + 0x28) = 0;
  *(undefined4 *)(extraout_ECX + 0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0046fca5();
  *(undefined ***)(extraout_ECX + 0x3c) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0046fca5();
  *(undefined ***)(extraout_ECX + 0xa8) = &PTR_FUN_0066643c;
  *(undefined4 *)(extraout_ECX + 0x11c) = 0;
  *(undefined4 *)(extraout_ECX + 0x120) = 0;
  *(undefined4 *)(extraout_ECX + 0x124) = 0;
  *(undefined4 *)(extraout_ECX + 0x128) = 0;
  *(undefined4 *)(extraout_ECX + 300) = 0;
  *(undefined4 *)(extraout_ECX + 0x130) = 0;
  *(undefined4 *)(extraout_ECX + 0x30) = 0;
  *(undefined4 *)(extraout_ECX + 0x34) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(undefined4 *)(extraout_ECX + 0x38) = 0;
  pvVar1 = operator_new(4);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004a1c1e();
  }
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(undefined4 *)(extraout_ECX + 0xc) = uVar2;
  *(undefined2 *)(unaff_EBP + -0x14) = 0x1e;
  *(undefined2 *)(unaff_EBP + -0x12) = 0xfe;
  FUN_00580875(unaff_EBP + -0x14);
  *(undefined2 *)(unaff_EBP + -0x14) = 0x100;
  *(undefined2 *)(unaff_EBP + -0x12) = 0xfffe;
  FUN_00580875(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x118) = 0;
  return extraout_ECX;
}

