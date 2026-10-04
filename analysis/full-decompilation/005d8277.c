
int FUN_005d8277(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d909f();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_00401742(0x1c);
  *(undefined4 *)(extraout_ECX + 0x24) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(extraout_ECX + 0x24) + 4) = *(int *)(extraout_ECX + 0x24);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  puVar1 = PTR_DAT_006d71e0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d4956(puVar1);
  *(undefined1 *)(extraout_ECX + 0x40) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined1 *)(extraout_ECX + 0x41) = *(undefined1 *)(unaff_EBP + 0x14);
  FUN_005d8aed();
  if (*(char *)(unaff_EBP + 0xc) != '\0') {
    FUN_005d82fa();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

