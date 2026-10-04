
void FUN_004a415d(void)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  int iVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar3 = 0;
  do {
    if ((&DAT_006efc6c)[iVar3] != '\0') {
      *(char *)(unaff_EBP + -0x14) = (char)iVar3;
      iVar5 = 0;
      puVar4 = (undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      do {
        iVar2 = FUN_004a3b2c(iVar5);
        iVar5 = iVar5 + 1;
        *puVar4 = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18 + iVar2 * 4);
        puVar4 = puVar4 + 1;
      } while (iVar5 < 4);
      cVar1 = FUN_004a41d0(unaff_EBP + -0x24);
      if (cVar1 == '\0') {
        (&DAT_006efc6c)[iVar3] = 0;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

