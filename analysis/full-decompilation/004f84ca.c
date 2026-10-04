
undefined4 FUN_004f84ca(void)

{
  undefined4 uVar1;
  char *pcVar2;
  size_t sVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005d48d9();
  uVar1 = *(undefined4 *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d4bbf(uVar1);
  sVar3 = _strlen(&DAT_006c3d7c);
  FUN_00412d8a(&DAT_006c3d7c,&DAT_006c3d7c + sVar3);
  pcVar2 = *(char **)(extraout_ECX + 8);
  sVar3 = _strlen(pcVar2);
  FUN_00412d8a(pcVar2,pcVar2 + sVar3);
  sVar3 = _strlen(&DAT_006c2814);
  FUN_00412d8a(&DAT_006c2814,&DAT_006c2814 + sVar3);
  pcVar2 = *(char **)(extraout_ECX + 0xc);
  sVar3 = _strlen(pcVar2);
  FUN_00412d8a(pcVar2,pcVar2 + sVar3);
  FUN_005b86bd(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

