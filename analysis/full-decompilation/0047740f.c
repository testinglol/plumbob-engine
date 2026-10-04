
void FUN_0047740f(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  int extraout_ECX;
  int unaff_EBP;
  byte *pbVar7;
  int iVar8;
  
  FUN_00634c24();
  pbVar7 = (byte *)(*(int *)(*(int *)(extraout_ECX + 0x10) + **(char **)(unaff_EBP + 8) * 4) +
                   (int)(*(char **)(unaff_EBP + 8))[1]);
  if (*pbVar7 == 0xff) {
    *pbVar7 = 0;
    iVar8 = 0;
    *(undefined4 *)(unaff_EBP + -0x38) = 2;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 3;
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    *(undefined4 *)(unaff_EBP + -0x28) = 8;
    *(undefined4 *)(unaff_EBP + -0x24) = 4;
    *(undefined4 *)(unaff_EBP + -0x20) = 2;
    *(undefined4 *)(unaff_EBP + -0x1c) = 1;
    do {
      iVar4 = *(int *)(unaff_EBP + -0x38 + iVar8 * 4);
      *(undefined1 *)(unaff_EBP + -0x10) = (&DAT_006e481c)[iVar4 * 3];
      uVar1 = (&DAT_006e481d)[iVar4 * 3];
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      *(undefined1 *)(unaff_EBP + -0xf) = uVar1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x14,unaff_EBP + -0x10);
      cVar2 = *pcVar5;
      iVar4 = *(int *)(extraout_ECX + 0x10);
      *(int *)(unaff_EBP + -0x18) = (int)pcVar5[1];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      pbVar6 = (byte *)(*(int *)(iVar4 + cVar2 * 4) + *(int *)(unaff_EBP + -0x18));
      bVar3 = *pbVar6;
      if (bVar3 != 0xff) {
        *pbVar6 = (byte)*(undefined4 *)(unaff_EBP + -0x28 + iVar8 * 4) | bVar3;
        *pbVar7 = *pbVar7 | *(byte *)(unaff_EBP + -0x28 + (iVar8 - 2U & 3) * 4);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

