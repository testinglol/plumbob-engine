
void FUN_004a1fe2(void)

{
  int iVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  int iVar3;
  undefined1 *puVar4;
  
  FUN_00634c24();
  iVar3 = **(int **)(unaff_EBP + 0xc);
  iVar1 = (*(int **)(unaff_EBP + 0xc))[1];
  *(int *)(unaff_EBP + 0xc) = iVar1;
  if (iVar3 != iVar1) {
    do {
      FUN_004a223c();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046f8e4(iVar3 + 4);
      puVar2 = *(undefined1 **)(iVar3 + 0x114);
      for (puVar4 = *(undefined1 **)(iVar3 + 0x110); puVar4 != puVar2; puVar4 = puVar4 + 8) {
        *(undefined1 *)(unaff_EBP + -0x14) = *puVar4;
        *(undefined1 *)(unaff_EBP + -0x13) = puVar4[2];
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(puVar4 + 4);
        FUN_004a220d(unaff_EBP + -0x14);
      }
      FUN_004a2182(unaff_EBP + -0x130);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar3 = iVar3 + 0x11c;
      FUN_004a216a();
    } while (iVar3 != *(int *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

