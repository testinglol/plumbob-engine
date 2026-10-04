
void FUN_00464faf(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  pcVar2 = (char *)FUN_00420048(*(undefined4 *)(unaff_EBP + 0xc));
  cVar1 = *pcVar2;
  uVar3 = FUN_00420096(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -0x30) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(char **)(unaff_EBP + -0x34) = pcVar2 + 0xc;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(short *)(unaff_EBP + -0x24) = (short)cVar1;
  *(undefined1 *)(unaff_EBP + -0x22) = 0;
  *(undefined1 *)(unaff_EBP + -0x21) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(undefined4 **)(unaff_EBP + 0x10) != (undefined4 *)0x0) {
    **(undefined4 **)(unaff_EBP + 0x10) = *(undefined4 *)(pcVar2 + 4);
  }
  (**(code **)(**(int **)(unaff_EBP + 8) + 4))(unaff_EBP + -0x34,*(undefined4 *)(pcVar2 + 4));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046453f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

