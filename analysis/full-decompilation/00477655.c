
void FUN_00477655(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined1 *)(unaff_EBP + -0x16) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar2 = (undefined4 *)FUN_004619d2(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x1c) = *puVar2;
  *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(puVar2 + 1);
  *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)((int)puVar2 + 5);
  *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)((int)puVar2 + 6);
  puVar2 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x14) = *puVar2;
  *(undefined1 *)(unaff_EBP + -0x10) = *(undefined1 *)(puVar2 + 1);
  *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)((int)puVar2 + 5);
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)((int)puVar2 + 6);
  while( true ) {
    cVar1 = FUN_00461979(unaff_EBP + -0x1c);
    if (cVar1 != '\0') break;
    uVar3 = FUN_00461941(unaff_EBP + 8);
    FUN_0047759d(uVar3);
    FUN_00461961();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

