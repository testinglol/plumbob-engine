
void FUN_004c89b6(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int unaff_EBP;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x10) = 0x80000000;
  iVar6 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0x10));
  iVar7 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0x10));
  if ((iVar6 != 0) && (iVar7 != 0)) {
    iVar6 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x14));
    iVar8 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x14));
    FUN_004c8148(iVar6 + 10,iVar8 + 10,*(undefined4 *)(iVar7 + 8),*(undefined4 *)(iVar7 + 0x20),
                 iVar6,iVar8,*(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x1c),
                 *(undefined4 *)(unaff_EBP + 0x24),*(undefined4 *)(unaff_EBP + 0x20),0);
    *(undefined4 *)(unaff_EBP + -0x34) = 5;
    *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0x6e) + *(int *)(unaff_EBP + -0x5c);
    *(int *)(unaff_EBP + -0x18) = (int)*(short *)(unaff_EBP + -0x70) + *(int *)(unaff_EBP + -0x54);
    *(int *)(unaff_EBP + -0x14) = (int)*(short *)(unaff_EBP + -0x6a) - *(int *)(unaff_EBP + -0x58);
    *(int *)(unaff_EBP + -0x10) = (int)*(short *)(unaff_EBP + -0x6c) - *(int *)(unaff_EBP + -0x50);
    cVar5 = FUN_004c7929(&DAT_006f0bc0);
    if (cVar5 == '\0') {
      sVar1 = *(short *)(unaff_EBP + -0x6e);
      sVar2 = *(short *)(unaff_EBP + -0x6a);
      *(int *)(unaff_EBP + 0x20) = (int)sVar1;
      iVar10 = (int)*(short *)(unaff_EBP + -0x70);
      sVar3 = *(short *)(unaff_EBP + -0x6c);
      *(undefined4 *)(unaff_EBP + -0xa4) = *(undefined4 *)(unaff_EBP + -0x78);
      *(undefined4 *)(unaff_EBP + -0xa0) = *(undefined4 *)(unaff_EBP + -0x78);
      *(int *)(unaff_EBP + -0x28) = iVar10;
      *(undefined1 *)(unaff_EBP + -0x94) = 0;
      *(undefined ***)(unaff_EBP + -0xa8) = &PTR_FUN_00668958;
      *(undefined4 *)(unaff_EBP + -0x9c) = 0;
      *(undefined4 *)(unaff_EBP + -0x98) = 0;
      *(undefined1 *)(unaff_EBP + -0x7c) = 0;
      *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_00668958;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(unaff_EBP + -0x74);
      *(undefined4 *)(unaff_EBP + -0x88) = *(undefined4 *)(unaff_EBP + -0x74);
      *(undefined4 *)(unaff_EBP + -0x84) = 0;
      *(undefined4 *)(unaff_EBP + -0x80) = 0;
      uVar12 = 1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar9 = FUN_00492d2c(1);
      FUN_0049f25a(uVar9,uVar12);
      iVar6 = DAT_006f0bcc;
      iVar8 = DAT_006f0bbc / 2;
      *(int *)(unaff_EBP + -0x2c) = iVar8;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar7 = DAT_006f0bd0;
      *(int *)(unaff_EBP + -0x30) = iVar6 + (iVar8 * iVar10 + *(int *)(unaff_EBP + 0x20)) * 2;
      iVar6 = DAT_006f0bd4 / 2;
      *(int *)(unaff_EBP + -0x20) = iVar6;
      *(int *)(unaff_EBP + -0x24) = iVar7 + (iVar6 * iVar10 + *(int *)(unaff_EBP + 0x20)) * 2;
      SetRect((LPRECT)(unaff_EBP + -0xb8),*(int *)(unaff_EBP + -0x5c),*(int *)(unaff_EBP + -0x54),
              *(int *)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x50));
      iVar6 = FUN_004b469d();
      *(undefined4 *)(unaff_EBP + 0x18) = *(undefined4 *)(iVar6 + 0xc);
      uVar9 = FUN_00492d2c();
      *(undefined4 *)(unaff_EBP + 0x14) = uVar9;
      iVar6 = FUN_004cebb0();
      *(int *)(unaff_EBP + 0x10) = iVar6;
      *(undefined4 *)(unaff_EBP + 0x1c) =
           *(undefined4 *)(iVar6 + (0x24 - *(int *)(unaff_EBP + 0x14)) * 4);
      iVar7 = FUN_00492d2c();
      piVar11 = (int *)(*(int *)(iVar6 + (7 - iVar7) * 4) + DAT_006f0084 * -4);
      cVar5 = FUN_004b4616(3,1);
      if (cVar5 == '\0') {
        iVar6 = FUN_004c9f9a(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x14),0);
        *(int *)(unaff_EBP + 0x10) =
             (*(int *)(unaff_EBP + 0x1c) + 0x41) * *(int *)(unaff_EBP + 0x18) +
             *(int *)(unaff_EBP + 0x28) + iVar6;
      }
      else {
        uVar9 = FUN_0049a73d(*(int *)(unaff_EBP + 0x24),
                             *(undefined4 *)(*(int *)(unaff_EBP + 0x24) + 0x24));
        *(undefined4 *)(unaff_EBP + 0x10) = uVar9;
      }
      *(int *)(unaff_EBP + 0x10) =
           *(int *)(unaff_EBP + 0x10) +
           (*piVar11 - piVar11[(4 << ((byte)*(undefined4 *)(unaff_EBP + 0x14) & 0x1f)) + 1]);
      if (0xffff < *(int *)(unaff_EBP + 0x10)) {
        *(undefined4 *)(unaff_EBP + 0x10) = 0xffff;
      }
      cVar5 = FUN_004b465e();
      if ((cVar5 != '\0') && (cVar5 = FUN_004b4665(), cVar5 != '\0')) {
        FUN_0049f41c(*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + -0x28),
                     (int)sVar2 - (int)sVar1,sVar3 - iVar10,unaff_EBP + -0xa8,
                     *(undefined4 *)(unaff_EBP + -0x48),unaff_EBP + -0x90,
                     *(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c),
                     *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                     unaff_EBP + -0xb8,*(undefined4 *)(unaff_EBP + 0x10),
                     *(undefined4 *)(unaff_EBP + 0x24));
      }
    }
  }
  puVar4 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar4 = *(undefined4 *)(unaff_EBP + -0x1c);
  puVar4[1] = *(undefined4 *)(unaff_EBP + -0x18);
  puVar4[2] = *(undefined4 *)(unaff_EBP + -0x14);
  puVar4[3] = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

