
void FUN_0053fce8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 8);
  uVar1 = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(extraout_ECX + 0x50) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 *)(extraout_ECX + 0x48) = 1;
  *(int *)(extraout_ECX + 0x4c) = iVar4;
  *(undefined4 *)(extraout_ECX + 0x54) = uVar1;
  FUN_0053f472(unaff_EBP + -0x10,extraout_ECX + 4,*(undefined4 *)(extraout_ECX + 0x10));
  uVar2 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0053f472(unaff_EBP + -0x14,extraout_ECX + 7,uVar2);
  FUN_0044f2cf(unaff_EBP + 0x10,unaff_EBP + -0x10);
  iVar5 = *(int *)(extraout_ECX + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (iVar5 == 6) {
    bVar3 = (byte)*(undefined4 *)(extraout_ECX + 0x54);
    FUN_0053d257(iVar4 - (8 << (bVar3 & 0x1f)),(4 << (bVar3 & 0x1f)) + *(int *)(unaff_EBP + 0xc),
                 uVar1,extraout_ECX,1);
    bVar3 = (byte)*(undefined4 *)(extraout_ECX + 0x54);
    iVar5 = (4 << (bVar3 & 0x1f)) + *(int *)(unaff_EBP + 0xc);
    iVar4 = (8 << (bVar3 & 0x1f)) + iVar4;
  }
  else {
    FUN_0053d257(iVar4,*(undefined4 *)(unaff_EBP + 0xc),uVar1,extraout_ECX,1);
    bVar3 = (byte)*(undefined4 *)(extraout_ECX + 0x54);
    iVar5 = ((int)*(char *)(unaff_EBP + 0x10) - (int)*(char *)(unaff_EBP + 0x11)) *
            (4 << (bVar3 & 0x1f)) + *(int *)(unaff_EBP + 0xc);
    iVar4 = ((int)*(char *)(unaff_EBP + 0x10) + (int)*(char *)(unaff_EBP + 0x11)) *
            (8 << (bVar3 & 0x1f)) + *(int *)(unaff_EBP + 8);
  }
  FUN_0053d257(iVar4,iVar5,uVar1,extraout_ECX,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

