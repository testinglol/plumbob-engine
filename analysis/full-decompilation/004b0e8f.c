
void FUN_004b0e8f(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x4b8) != 0) {
    FUN_00461e56(0,0,*(undefined4 *)(DAT_006e54dc + 0x10),*(undefined4 *)(DAT_006e54dc + 0x10),1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined1 *)(unaff_EBP + -0x26) = 0;
    FUN_004619d2(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -100) = 0x7fffffff;
    *(undefined4 *)(unaff_EBP + -0x60) = 0x7fffffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + -0x5c) = 0x80000000;
    *(undefined4 *)(unaff_EBP + -0x58) = 0x80000000;
    puVar4 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x4c);
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar4;
    FUN_00461b74(puVar4 + 1);
    cVar3 = FUN_0046198c(unaff_EBP + -0x50);
    iVar2 = *(int *)(unaff_EBP + 8);
    while (cVar3 == '\0') {
      pcVar5 = (char *)FUN_00461941(unaff_EBP + 8);
      cVar3 = *pcVar5;
      iVar7 = *(int *)(*(int *)(extraout_ECX + 0x4b8) + 0x10);
      *(int *)(unaff_EBP + -0x14) = (int)pcVar5[1];
      bVar1 = *(byte *)(*(int *)(iVar7 + cVar3 * 4) + *(int *)(unaff_EBP + -0x14));
      *(byte *)(unaff_EBP + -0x3c) = bVar1;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if ((bVar1 < 0x10) || (bVar1 == 0x10)) {
        FUN_00461628(*(undefined4 *)(DAT_006e54d8 + 0x84));
        if (*(byte *)(unaff_EBP + -0x3c) < 0x10) {
          uVar6 = (uint)*(byte *)(unaff_EBP + -0x3c);
          if (0xf < uVar6) {
            iVar7 = uVar6 + 0x41c + DAT_006f0088 * 4;
            goto LAB_004b0fac;
          }
          *(uint *)(unaff_EBP + -0x14) = (DAT_006f0088 + 0x3f) * 0x10 + uVar6;
        }
        else {
          iVar7 = DAT_006f0088 * 0x100 + -0xf4;
LAB_004b0fac:
          *(int *)(unaff_EBP + -0x14) = iVar7;
        }
        FUN_00461941(unaff_EBP + -0x68);
        uVar20 = 0xffffffff;
        uVar17 = 1;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        iVar7 = iVar2;
        uVar8 = FUN_00434d3d(unaff_EBP + -0x80);
        FUN_004b469d(uVar8,uVar17,iVar7,uVar20);
        FUN_004b97eb(uVar8,uVar17,iVar7,uVar20);
        *(int *)(unaff_EBP + -0x1c) = *(int *)(iVar2 + 0x10) - *(int *)(extraout_ECX + 0x5c);
        *(int *)(unaff_EBP + -0x18) = *(int *)(iVar2 + 0x14) - *(int *)(extraout_ECX + 100);
        FUN_00461941(unaff_EBP + -0x10);
        iVar7 = DAT_006e54d8;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_00434ffd(*(undefined4 *)(iVar7 + 0x84));
        *(int *)(unaff_EBP + -0x48) = (int)*(char *)(unaff_EBP + -0xe);
        uVar8 = FUN_00434d3d(unaff_EBP + -0x88);
        fVar9 = (float10)FUN_0046755a(uVar8,*(undefined4 *)(unaff_EBP + -0x48));
        FUN_004b4722((float)fVar9);
        *(undefined1 *)(unaff_EBP + -0x31) = 0x7f;
        *(undefined1 *)(unaff_EBP + -0x32) = 0x7f;
        *(undefined1 *)(unaff_EBP + -0x33) = 0x7f;
        *(undefined1 *)(unaff_EBP + -0x34) = 0x7f;
        uVar21 = 0;
        uVar19 = 0;
        uVar18 = 0;
        iVar7 = unaff_EBP + -0x34;
        uVar16 = 1;
        uVar14 = 0;
        uVar8 = *(undefined4 *)(unaff_EBP + -0x18);
        iVar11 = unaff_EBP + -0x10;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        uVar17 = *(undefined4 *)(unaff_EBP + -0x1c);
        uVar13 = 0;
        uVar20 = *(undefined4 *)(unaff_EBP + -0x14);
        iVar10 = unaff_EBP + -200;
        iVar12 = iVar2;
        FUN_004c656a(iVar10,iVar11,uVar20,0,uVar17,uVar8,0,iVar2,iVar7,1,0,0,0);
        FUN_004c828c(iVar10,iVar11,uVar20,uVar13,uVar17,uVar8,uVar14,iVar12,iVar7,uVar16,uVar18,
                     uVar19,uVar21);
        uVar8 = DAT_006f008c;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        uVar6 = FUN_00461f92(unaff_EBP + -0x10,uVar8);
        *(uint *)(unaff_EBP + -0x14) = uVar6;
        if (uVar6 != 0) {
          if ((uVar6 & 1) != 0) {
            *(undefined1 *)(unaff_EBP + -0x1d) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x1e) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x1f) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x20) = 0x7f;
            uVar19 = 0;
            uVar18 = 0;
            uVar16 = 0xffffffff;
            iVar7 = unaff_EBP + -0x20;
            uVar14 = 1;
            uVar13 = 0;
            iVar12 = DAT_006f0088 * 4 + 0x42c;
            uVar8 = *(undefined4 *)(unaff_EBP + -0x18);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            uVar17 = *(undefined4 *)(unaff_EBP + -0x1c);
            uVar20 = 0;
            iVar11 = unaff_EBP + -0x10;
            iVar10 = unaff_EBP + -0x98;
            iVar15 = iVar2;
            FUN_004c656a(iVar10,iVar11,iVar12,0,uVar17,uVar8,0,iVar2,iVar7,1,0xffffffff,0,0);
            FUN_004c828c(iVar10,iVar11,iVar12,uVar20,uVar17,uVar8,uVar13,iVar15,iVar7,uVar14,uVar16,
                         uVar18,uVar19);
          }
          if ((*(byte *)(unaff_EBP + -0x14) & 2) != 0) {
            *(undefined1 *)(unaff_EBP + -0x2d) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x2e) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x2f) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x30) = 0x7f;
            uVar19 = 0;
            uVar18 = 0;
            uVar16 = 0xffffffff;
            iVar7 = unaff_EBP + -0x30;
            uVar14 = 1;
            uVar13 = 0;
            iVar12 = DAT_006f0088 * 4 + 0x42d;
            uVar8 = *(undefined4 *)(unaff_EBP + -0x18);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            uVar17 = *(undefined4 *)(unaff_EBP + -0x1c);
            uVar20 = 0;
            iVar11 = unaff_EBP + -0x10;
            iVar10 = unaff_EBP + -0xa8;
            iVar15 = iVar2;
            FUN_004c656a(iVar10,iVar11,iVar12,0,uVar17,uVar8,0,iVar2,iVar7,1,0xffffffff,0,0);
            FUN_004c828c(iVar10,iVar11,iVar12,uVar20,uVar17,uVar8,uVar13,iVar15,iVar7,uVar14,uVar16,
                         uVar18,uVar19);
          }
          if ((*(byte *)(unaff_EBP + -0x14) & 4) != 0) {
            *(undefined1 *)(unaff_EBP + -0x35) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x36) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x37) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x38) = 0x7f;
            uVar19 = 0;
            uVar18 = 0;
            uVar16 = 0xffffffff;
            iVar7 = unaff_EBP + -0x38;
            uVar14 = 1;
            uVar13 = 0;
            iVar12 = DAT_006f0088 * 4 + 0x42e;
            uVar8 = *(undefined4 *)(unaff_EBP + -0x18);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            uVar17 = *(undefined4 *)(unaff_EBP + -0x1c);
            uVar20 = 0;
            iVar11 = unaff_EBP + -0x10;
            iVar10 = unaff_EBP + -0xb8;
            iVar15 = iVar2;
            FUN_004c656a(iVar10,iVar11,iVar12,0,uVar17,uVar8,0,iVar2,iVar7,1,0xffffffff,0,0);
            FUN_004c828c(iVar10,iVar11,iVar12,uVar20,uVar17,uVar8,uVar13,iVar15,iVar7,uVar14,uVar16,
                         uVar18,uVar19);
          }
          if ((*(byte *)(unaff_EBP + -0x14) & 8) != 0) {
            *(undefined1 *)(unaff_EBP + -0x21) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x22) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x23) = 0x7f;
            *(undefined1 *)(unaff_EBP + -0x24) = 0x7f;
            uVar19 = 0;
            uVar18 = 0;
            uVar16 = 0xffffffff;
            iVar7 = unaff_EBP + -0x24;
            uVar14 = 1;
            uVar13 = 0;
            iVar12 = DAT_006f0088 * 4 + 0x42f;
            uVar8 = *(undefined4 *)(unaff_EBP + -0x18);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            uVar17 = *(undefined4 *)(unaff_EBP + -0x1c);
            uVar20 = 0;
            iVar11 = unaff_EBP + -0x10;
            iVar10 = unaff_EBP + -0xd8;
            iVar15 = iVar2;
            FUN_004c656a(iVar10,iVar11,iVar12,0,uVar17,uVar8,0,iVar2,iVar7,1,0xffffffff,0,0);
            FUN_004c828c(iVar10,iVar11,iVar12,uVar20,uVar17,uVar8,uVar13,iVar15,iVar7,uVar14,uVar16,
                         uVar18,uVar19);
          }
        }
        SetRect((LPRECT)(unaff_EBP + -0x78),*(int *)(unaff_EBP + -0x1c),*(int *)(unaff_EBP + -0x18),
                *(int *)(extraout_ECX + 0x58) + *(int *)(unaff_EBP + -0x1c),
                *(int *)(extraout_ECX + 0x60) + *(int *)(unaff_EBP + -0x18));
        FUN_00422698();
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00461961();
      cVar3 = FUN_0046198c(unaff_EBP + -0x50);
    }
    cVar3 = FUN_004b466e();
    if (((cVar3 != '\0') && (*(int *)(extraout_ECX + 0x68) != 0)) && (DAT_006e4870 == '\0')) {
      FUN_005cf0fa(unaff_EBP + -100);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

