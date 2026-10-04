
int FUN_005c2358(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int iStack_34;
  int iStack_30;
  
  FUN_00634c24();
  iStack_30 = *(undefined4 *)(unaff_EBP + 8);
  iStack_34 = unaff_EBP + -0x10;
  FUN_005c2748();
  if (*(int *)(unaff_EBP + -0x10) != *extraout_ECX) {
    iStack_30 = *(int *)(unaff_EBP + -0x10) + 0x10;
    iStack_34 = 0x5c238a;
    cVar1 = FUN_005c1797();
    if (cVar1 == '\0') goto LAB_005c2401;
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  iStack_30 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_34 = 0x5c23a7;
  FUN_005c178a();
  iStack_30 = unaff_EBP + -0x20;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iStack_34 = 0x5c23b7;
  FUN_005c259a();
  iStack_30 = unaff_EBP + -0x30;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(int **)(unaff_EBP + 8) = &iStack_34;
  FUN_00602c56(unaff_EBP + -0x10);
  puVar2 = (undefined4 *)FUN_005c254a(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = *puVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  iStack_30 = 0x5c23ea;
  FUN_0046664c();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  iStack_30 = 0x5c23f5;
  FUN_0042004f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_30 = 0x5c2401;
  FUN_0046664c();
LAB_005c2401:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(int *)(unaff_EBP + -0x10) + 0x14;
}

