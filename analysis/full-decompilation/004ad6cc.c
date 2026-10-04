
void FUN_004ad6cc(void)

{
  short *psVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  int extraout_ECX;
  int iVar5;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  int iVar8;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x2c) = extraout_ECX;
  FUN_00461b74(&DAT_006e482e);
  *(undefined1 *)(unaff_EBP + -0x1e) = 0;
  psVar1 = *(short **)(unaff_EBP + 8);
  uVar3 = 0;
  iVar8 = *(int *)(DAT_006e54dc + 0x10);
  iVar5 = 0x4c - DAT_006f0088;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x30) = iVar8;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  iVar5 = *(int *)(extraout_ECX + iVar5 * 4);
  *(int *)(unaff_EBP + -0x3c) = iVar5;
  iVar7 = extraout_ECX;
  if (0 < iVar8) {
    iVar6 = *(int *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -0x34) = 0;
    *(char *)(unaff_EBP + -0x32) = (char)iVar6;
    *(int *)(unaff_EBP + -0x38) = iVar5 * iVar6;
    while( true ) {
      *(undefined1 *)(unaff_EBP + -0x18) = 0;
      *(char *)(unaff_EBP + -0x17) = (char)uVar3;
      *(char *)(unaff_EBP + -0x16) = (char)iVar6;
      *(char *)(unaff_EBP + -0x33) = (char)uVar3;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004a8000(unaff_EBP + -0x18);
      FUN_004b3e97(unaff_EBP + -0x1c,unaff_EBP + -0x24,unaff_EBP + -0x18);
      cVar2 = (char)DAT_006f0088;
      if ((int)((*(int *)(unaff_EBP + -0x24) -
                ((uint)*(byte *)((int)*(char *)(unaff_EBP + -0x17) +
                                 (int)*(char *)(unaff_EBP + -0x18) + *(int *)(iVar7 + 0x1ec)) <<
                (cVar2 + 1U & 0x1f))) - *(int *)(unaff_EBP + -0x38)) < (int)psVar1[2]) {
        iVar5 = (int)psVar1[1] - *(int *)(unaff_EBP + -0x1c);
        iVar8 = *(char *)(unaff_EBP + -0x28) + 1;
        if (0 < iVar5) {
          iVar5 = iVar5 >> (cVar2 + 4U & 0x1f);
          if (iVar5 != 0) {
            pcVar4 = (char *)FUN_00494e66(unaff_EBP + 8,iVar5,unaff_EBP + -0x20);
            iVar8 = iVar8 - iVar5;
            *(char *)(unaff_EBP + -0x18) = *(char *)(unaff_EBP + -0x18) + *pcVar4;
            *(char *)(unaff_EBP + -0x17) = *(char *)(unaff_EBP + -0x17) + pcVar4[1];
            cVar2 = (char)DAT_006f0088;
            *(int *)(unaff_EBP + -0x1c) =
                 *(int *)(unaff_EBP + -0x1c) + (iVar5 << (cVar2 + 4U & 0x1f));
          }
          iVar7 = *(int *)(unaff_EBP + -0x2c);
        }
        if (0 < iVar8) {
          iVar5 = ((iVar8 << (cVar2 + 4U & 0x1f)) + *(int *)(unaff_EBP + -0x1c)) - (int)psVar1[3];
          if (0 < iVar5) {
            iVar8 = iVar8 + (1 - (iVar5 >> (cVar2 + 4U & 0x1f)));
            while( true ) {
              uVar3 = FUN_00494e66(unaff_EBP + -0x10,iVar8,unaff_EBP + -0x20);
              pcVar4 = (char *)FUN_0046185f(unaff_EBP + -0x14,uVar3);
              if ((((*(int *)(DAT_006e54d8 + 0x70) <= (int)*pcVar4) &&
                   ((int)*pcVar4 <= *(int *)(DAT_006e54d8 + 0x74))) &&
                  (*(int *)(DAT_006e54d8 + 0x78) <= (int)pcVar4[1])) &&
                 ((int)pcVar4[1] <= *(int *)(DAT_006e54d8 + 0x7c))) break;
              iVar8 = iVar8 + -1;
            }
          }
          if (0 < iVar8) {
            if (((*(char *)(unaff_EBP + 0x14) == '\0') || (*(char *)(iVar7 + 0x17b) == '\0')) ||
               ((DAT_006c723a == '\0' && (DAT_006c723b == '\0')))) {
              if (DAT_006c7240 != '\0') {
                FUN_004adabb(unaff_EBP + -0x18,iVar8,unaff_EBP + -0x20,
                             *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x24),
                             *(undefined4 *)(unaff_EBP + 0x18),psVar1,
                             *(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
              }
            }
            else {
              FUN_004af05b(unaff_EBP + -0x18,iVar8,unaff_EBP + -0x20,
                           *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x24),
                           *(undefined4 *)(unaff_EBP + 0x18));
            }
          }
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        iVar8 = *(int *)(unaff_EBP + -0x30);
      }
      else {
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
      if (iVar8 <= *(int *)(unaff_EBP + -0x28)) break;
      iVar6 = *(int *)(unaff_EBP + 0xc);
      uVar3 = *(undefined4 *)(unaff_EBP + -0x28);
    }
  }
  uVar3 = 1;
  *(undefined4 *)(unaff_EBP + -0x28) = 1;
  if (1 < iVar8) {
    *(char *)(unaff_EBP + -0x33) = (char)iVar8 + -1;
    *(undefined1 *)(unaff_EBP + -0x32) = *(undefined1 *)(unaff_EBP + 0xc);
    do {
      *(char *)(unaff_EBP + -0x18) = (char)uVar3;
      *(char *)(unaff_EBP + -0x17) = (char)iVar8 + -1;
      *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(unaff_EBP + 0xc);
      *(char *)(unaff_EBP + -0x34) = (char)uVar3;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_004a8000(unaff_EBP + -0x18);
      FUN_004b3e97(unaff_EBP + -0x1c,unaff_EBP + -0x24,unaff_EBP + -0x18);
      if (*(int *)(iVar7 + 0x60) + *(int *)(unaff_EBP + -0x24) < (int)*psVar1) {
LAB_004ad965:
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      else {
        cVar2 = (char)DAT_006f0088;
        if ((int)psVar1[2] <=
            (int)((*(int *)(unaff_EBP + -0x24) -
                  ((uint)*(byte *)(*(int *)(iVar7 + 0x1ec) + (int)*(char *)(unaff_EBP + -0x17) +
                                  (int)*(char *)(unaff_EBP + -0x18)) << (cVar2 + 1U & 0x1f))) -
                 *(int *)(unaff_EBP + -0x3c) * *(int *)(unaff_EBP + 0xc))) goto LAB_004ad965;
        iVar5 = (int)psVar1[1] - *(int *)(unaff_EBP + -0x1c);
        iVar7 = ((iVar8 * 2 - (int)*(char *)(unaff_EBP + -0x28)) -
                (int)(char)((char)*(undefined4 *)(unaff_EBP + -0x30) + -1)) + -1;
        if ((0 < iVar5) && (iVar5 = iVar5 >> (cVar2 + 4U & 0x1f), iVar5 != 0)) {
          pcVar4 = (char *)FUN_00494e66(unaff_EBP + 8,iVar5,unaff_EBP + -0x20);
          iVar7 = iVar7 - iVar5;
          *(char *)(unaff_EBP + -0x18) = *(char *)(unaff_EBP + -0x18) + *pcVar4;
          *(char *)(unaff_EBP + -0x17) = *(char *)(unaff_EBP + -0x17) + pcVar4[1];
          cVar2 = (char)DAT_006f0088;
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + (iVar5 << (cVar2 + 4U & 0x1f))
          ;
        }
        if (0 < iVar7) {
          iVar5 = ((iVar7 << (cVar2 + 4U & 0x1f)) + *(int *)(unaff_EBP + -0x1c)) - (int)psVar1[3];
          if (0 < iVar5) {
            iVar7 = iVar7 + (1 - (iVar5 >> (cVar2 + 4U & 0x1f)));
            while( true ) {
              uVar3 = FUN_00494e66(unaff_EBP + -0x14,iVar7,unaff_EBP + -0x20);
              pcVar4 = (char *)FUN_0046185f(unaff_EBP + -0x10,uVar3);
              if ((((*(int *)(DAT_006e54d8 + 0x70) <= (int)*pcVar4) &&
                   ((int)*pcVar4 <= *(int *)(DAT_006e54d8 + 0x74))) &&
                  (*(int *)(DAT_006e54d8 + 0x78) <= (int)pcVar4[1])) &&
                 ((int)pcVar4[1] <= *(int *)(DAT_006e54d8 + 0x7c))) break;
              iVar7 = iVar7 + -1;
            }
          }
          if (0 < iVar7) {
            if (((*(char *)(unaff_EBP + 0x14) == '\0') ||
                (*(char *)(*(int *)(unaff_EBP + -0x2c) + 0x17b) == '\0')) ||
               ((DAT_006c723a == '\0' && (DAT_006c723b == '\0')))) {
              if (DAT_006c7240 != '\0') {
                FUN_004adabb(unaff_EBP + -0x18,iVar7,unaff_EBP + -0x20,
                             *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x24),
                             *(undefined4 *)(unaff_EBP + 0x18),psVar1,
                             *(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
              }
            }
            else {
              FUN_004af05b(unaff_EBP + -0x18,iVar7,unaff_EBP + -0x20,
                           *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x24),
                           *(undefined4 *)(unaff_EBP + 0x18));
            }
          }
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        iVar7 = *(int *)(unaff_EBP + -0x2c);
        iVar8 = *(int *)(unaff_EBP + -0x30);
      }
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
      if (iVar8 <= *(int *)(unaff_EBP + -0x28)) break;
      uVar3 = *(undefined4 *)(unaff_EBP + -0x28);
    } while( true );
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

