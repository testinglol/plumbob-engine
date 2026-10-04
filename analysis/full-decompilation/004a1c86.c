
void FUN_004a1c86(void)

{
  int iVar1;
  byte *pbVar2;
  int unaff_EBP;
  int iVar3;
  byte *pbVar4;
  
  FUN_00634c24();
  iVar3 = **(int **)(unaff_EBP + 0xc);
  iVar1 = (*(int **)(unaff_EBP + 0xc))[1];
  *(int *)(unaff_EBP + 0xc) = iVar1;
  if (iVar3 != iVar1) {
    do {
      FUN_004a223c();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046f8e4(iVar3 + 4);
      pbVar2 = *(byte **)(iVar3 + 0x114);
      for (pbVar4 = *(byte **)(iVar3 + 0x110); pbVar4 != pbVar2; pbVar4 = pbVar4 + 8) {
        *(ushort *)(unaff_EBP + -0x14) = (ushort)*pbVar4;
        *(ushort *)(unaff_EBP + -0x12) = (ushort)pbVar4[1];
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(pbVar4 + 4);
        FUN_004a177b(unaff_EBP + -0x14);
      }
      FUN_004a16d8(unaff_EBP + -0x130);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar3 = iVar3 + 0x11c;
      FUN_004a216a();
    } while (iVar3 != *(int *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

