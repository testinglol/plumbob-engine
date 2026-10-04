
/* WARNING: Removing unreachable block (ram,0x0044a22c) */

void FUN_0044a20e(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffcc;
  *(undefined4 *)(unaff_EBP + -0x2c) = extraout_ECX;
  uVar2 = FUN_00401742(0x18);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x14) + 0x10;
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
  }
  else {
    uVar2 = (*(undefined4 **)(unaff_EBP + 8))[1];
    puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
    *puVar1 = **(undefined4 **)(unaff_EBP + 8);
    puVar1[1] = uVar2;
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x18);
  }
  FUN_0044a29a();
  return;
}

