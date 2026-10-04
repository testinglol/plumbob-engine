
void FUN_0057c5c7(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined1 *puStack_1c;
  undefined4 local_18;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  local_18 = *(undefined4 *)(extraout_ECX + 0x14);
  puStack_1c = (undefined1 *)&local_18;
  *(undefined4 **)(unaff_EBP + -0x14) = &local_18;
  *(undefined1 ***)(unaff_EBP + -0x14) = &puStack_1c;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00602902(&puStack_1c);
  FUN_005813bf(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  local_18 = 0x57c614;
  FUN_0057a116();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  local_18 = 0x57c61f;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

