
void FUN_0047bf93(void)

{
  int *piVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  byte *pbVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  pcVar3 = *(char **)(unaff_EBP + 8);
  if ((*pcVar3 != '\0') || (pcVar3[1] != '\0')) {
    FUN_004449d1(pcVar3);
    *(undefined1 *)(unaff_EBP + -0x18) = 0;
    *(undefined1 *)(unaff_EBP + -0x17) = 0;
    *(undefined1 *)(unaff_EBP + -0x16) = 0;
    *(undefined1 *)(unaff_EBP + -0x15) = 0;
    FUN_0047c3ea(pcVar3,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    FUN_0047c969(pcVar3,unaff_EBP + 0xb);
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    FUN_0047cb76(pcVar3,unaff_EBP + 0xb);
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    FUN_0047cb76(pcVar3,unaff_EBP + 0xb);
    iVar7 = extraout_ECX + 0x2c;
    *(undefined4 *)(unaff_EBP + -0x20) = 2;
    do {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_0047c5ee(pcVar3,unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_0047c5ee(pcVar3,unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      FUN_0047c969(pcVar3,unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_0047c7d1(pcVar3,unaff_EBP + 8);
      _memset((void *)(unaff_EBP + -0x34),0,0xe);
      _memset((void *)(unaff_EBP + -0x34),0,0xe);
      FUN_0047cd47(pcVar3,unaff_EBP + -0x34);
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0047cefa(pcVar3,unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b5427(pcVar3);
      iVar4 = *(int *)(extraout_ECX + 0x10);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar4;
      if (0 < iVar4) {
        do {
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          do {
            iVar4 = *(int *)(unaff_EBP + -0x10) - (int)*pcVar3;
            iVar6 = *(int *)(unaff_EBP + 8) - (int)pcVar3[1];
            if ((((iVar4 < 0) || (*(int *)(unaff_EBP + -0x14) <= iVar4)) || (iVar6 < 0)) ||
               (*(int *)(unaff_EBP + -0x14) <= iVar6)) {
              iVar4 = *(int *)(unaff_EBP + 8) + 1;
              if (iVar4 < *(int *)(unaff_EBP + -0x14)) {
                iVar6 = *(int *)(iVar7 + 0x18);
                *(int *)(unaff_EBP + -0x1c) = (int)*(char *)(unaff_EBP + -0x10);
                pbVar5 = (byte *)(*(int *)(*(int *)(iVar6 + 0xc) + *(int *)(unaff_EBP + -0x1c) * 4)
                                 + (char)iVar4 * 0xe);
                bVar2 = *pbVar5;
                if ((bVar2 & 2) == 2) {
                  *pbVar5 = bVar2 & 0xfd;
                }
              }
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x10) + -1;
              iVar4 = *(int *)(unaff_EBP + -0x10) + 1;
              if (iVar4 < *(int *)(unaff_EBP + -0x14)) {
                iVar6 = *(char *)(unaff_EBP + 8) * 0xe;
                iVar4 = *(int *)(*(int *)(*(int *)(iVar7 + 0x18) + 0xc) + (char)iVar4 * 4);
                bVar2 = *(byte *)(iVar4 + iVar6);
                if ((bVar2 & 1) == 1) {
                  *(byte *)(iVar4 + iVar6) = bVar2 & 0xfe;
                }
              }
              iVar4 = *(int *)(unaff_EBP + 8) + -1;
              if (-1 < iVar4) {
                iVar6 = *(int *)(iVar7 + 0x18);
                *(int *)(unaff_EBP + -0x24) = (int)*(char *)(unaff_EBP + -0x10);
                pbVar5 = (byte *)(*(int *)(*(int *)(iVar6 + 0xc) + *(int *)(unaff_EBP + -0x24) * 4)
                                 + (char)iVar4 * 0xe);
                bVar2 = *pbVar5;
                if ((bVar2 & 4) == 4) {
                  *pbVar5 = bVar2 & 0xfb;
                }
              }
              if (-1 < *(int *)(unaff_EBP + -0x1c)) {
                iVar6 = *(char *)(unaff_EBP + 8) * 0xe;
                iVar4 = *(int *)(*(int *)(*(int *)(iVar7 + 0x18) + 0xc) +
                                *(char *)(unaff_EBP + -0x1c) * 4);
                bVar2 = *(byte *)(iVar4 + iVar6);
                if ((bVar2 & 8) == 8) {
                  *(byte *)(iVar4 + iVar6) = bVar2 & 0xf7;
                }
              }
            }
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x14));
      }
      iVar7 = iVar7 + 4;
      piVar1 = (int *)(unaff_EBP + -0x20);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

