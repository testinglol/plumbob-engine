
void FUN_00489224(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_48 [6];
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  int iStack_20;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = (int)*(char *)(unaff_EBP + 8);
  iStack_20 = 0x40;
  *(int *)(unaff_EBP + -0x14) = (int)*(char *)(unaff_EBP + 9);
  uStack_24 = -*(int *)(extraout_ECX + 0x84) & 3;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  cVar1 = *(char *)(unaff_EBP + 10);
  iStack_28 = unaff_EBP + -0x14;
  iStack_2c = unaff_EBP + -0x18;
  uStack_30 = 0x489268;
  FUN_0047bd91();
  if (*(int *)(unaff_EBP + 0x30) != 0) {
    iStack_20 = 4 - *(int *)(unaff_EBP + 0x30);
    uStack_24 = 0x48927d;
    FUN_0053bdc6();
  }
  *(undefined4 **)(unaff_EBP + -0x1c) = auStack_48;
  puVar4 = (undefined4 *)(unaff_EBP + 0xc);
  puVar5 = auStack_48;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_00434d11(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),
                       (int)cVar1);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00479954(uVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

