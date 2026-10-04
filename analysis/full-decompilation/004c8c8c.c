
void FUN_004c8c8c(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int unaff_EBP;
  undefined4 uVar11;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x10) = 0x80000000;
  iVar7 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0x10));
  iVar8 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0xc));
  if ((iVar7 != 0) && (iVar8 != 0)) {
    iVar7 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x14));
    iVar9 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x14));
    *(int *)(unaff_EBP + 0x14) = iVar9 + 10;
    FUN_004c8148(iVar7 + 10,*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(iVar8 + 8),
                 *(undefined4 *)(iVar8 + 0x20),iVar7,iVar9,*(undefined4 *)(unaff_EBP + 0x18),
                 *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x24),
                 *(undefined4 *)(unaff_EBP + 0x20),0);
    *(undefined4 *)(unaff_EBP + -0x24) = 6;
    *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0x5e) + *(int *)(unaff_EBP + -0x4c);
    *(int *)(unaff_EBP + -0x18) = (int)*(short *)(unaff_EBP + -0x60) + *(int *)(unaff_EBP + -0x44);
    *(int *)(unaff_EBP + -0x14) = (int)*(short *)(unaff_EBP + -0x5a) - *(int *)(unaff_EBP + -0x48);
    *(int *)(unaff_EBP + -0x10) = (int)*(short *)(unaff_EBP + -0x5c) - *(int *)(unaff_EBP + -0x40);
    cVar6 = FUN_004c7929(&DAT_006f0bc0);
    if (cVar6 == '\0') {
      sVar1 = *(short *)(unaff_EBP + -0x60);
      sVar2 = *(short *)(unaff_EBP + -0x5e);
      sVar3 = *(short *)(unaff_EBP + -0x5a);
      sVar4 = *(short *)(unaff_EBP + -0x5c);
      *(int *)(unaff_EBP + 0x14) = (int)sVar1;
      *(int *)(unaff_EBP + 0x10) = (int)sVar2;
      *(undefined ***)(unaff_EBP + -0x80) = &PTR_FUN_00668958;
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x68);
      *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x68);
      *(undefined4 *)(unaff_EBP + -0x74) = 0;
      *(undefined4 *)(unaff_EBP + -0x70) = 0;
      *(undefined1 *)(unaff_EBP + -0x6c) = 0;
      *(undefined ***)(unaff_EBP + -0x98) = &PTR_FUN_00668958;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(unaff_EBP + -100);
      *(undefined4 *)(unaff_EBP + -0x90) = *(undefined4 *)(unaff_EBP + -100);
      *(undefined4 *)(unaff_EBP + -0x8c) = 0;
      *(undefined4 *)(unaff_EBP + -0x88) = 0;
      *(undefined1 *)(unaff_EBP + -0x84) = 0;
      uVar11 = 1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar10 = FUN_00492d2c(1);
      FUN_0049f25a(uVar10,uVar11);
      iVar7 = DAT_006f0bcc;
      iVar9 = DAT_006f0bbc / 2;
      *(int *)(unaff_EBP + 0x18) = iVar9;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar8 = DAT_006f0bd0;
      *(int *)(unaff_EBP + -0x20) =
           iVar7 + (iVar9 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
      iVar7 = DAT_006f0bd4 / 2;
      *(int *)(unaff_EBP + 0x20) = iVar7;
      *(int *)(unaff_EBP + 0x1c) =
           iVar8 + (iVar7 * *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10)) * 2;
      SetRect((LPRECT)(unaff_EBP + -0xa8),*(int *)(unaff_EBP + -0x4c),*(int *)(unaff_EBP + -0x44),
              *(int *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x40));
      cVar6 = FUN_004b465e();
      if ((cVar6 != '\0') && (cVar6 = FUN_004b4665(), cVar6 != '\0')) {
        uVar10 = FUN_00492d2c();
        *(undefined4 *)(unaff_EBP + 0xc) = uVar10;
        iVar7 = FUN_004cebb0();
        FUN_0049ee29(*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                     (int)sVar3 - (int)sVar2,(int)sVar4 - (int)sVar1,unaff_EBP + -0x80,
                     *(undefined4 *)(unaff_EBP + -0x38),unaff_EBP + -0x98,
                     *(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + 0x18),
                     *(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x20),
                     unaff_EBP + -0xa8,
                     *(int *)(iVar7 + (0xe - *(int *)(unaff_EBP + 0xc)) * 4) +
                     (0x10 << ((byte)*(int *)(unaff_EBP + 0xc) & 0x1f)) * 2,
                     *(undefined4 *)(unaff_EBP + 0x24));
      }
    }
  }
  puVar5 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar5 = *(undefined4 *)(unaff_EBP + -0x1c);
  puVar5[1] = *(undefined4 *)(unaff_EBP + -0x18);
  puVar5[2] = *(undefined4 *)(unaff_EBP + -0x14);
  puVar5[3] = *(undefined4 *)(unaff_EBP + -0x10);
  return;
}

