
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c7b37(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  int *piVar9;
  int iVar10;
  bool bVar11;
  float10 fVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x24) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x80000000;
  iVar3 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0x10));
  iVar4 = FUN_004c8f7a(*(undefined4 *)(unaff_EBP + 0x18));
  uVar5 = FUN_00492d2c();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
  if ((iVar3 != 0) && (iVar4 != 0)) {
    iVar3 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x1c));
    iVar6 = FUN_004c1ba2(*(undefined4 *)(unaff_EBP + 0x1c));
    FUN_004c8148(iVar3 + 10,iVar6 + 10,*(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 0x20),
                 iVar3,iVar6,*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),
                 *(undefined4 *)(unaff_EBP + 0x2c),*(undefined4 *)(unaff_EBP + 0x28),
                 *(undefined4 *)(unaff_EBP + 0x30));
    if (*(int *)(unaff_EBP + 0x34) == 0x10) {
      *(undefined4 *)(unaff_EBP + -0x78) = 2;
    }
    else {
      *(uint *)(unaff_EBP + -0x78) = ((*(int *)(unaff_EBP + 0x34) != 0x20) - 1 & 2) + 1;
    }
    *(int *)(unaff_EBP + -0x24) = (int)*(short *)(unaff_EBP + -0xb2) + *(int *)(unaff_EBP + -0xa0);
    *(int *)(unaff_EBP + -0x20) = (int)*(short *)(unaff_EBP + -0xb4) + *(int *)(unaff_EBP + -0x98);
    *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0xae) - *(int *)(unaff_EBP + -0x9c);
    *(int *)(unaff_EBP + -0x18) = (int)*(short *)(unaff_EBP + -0xb0) - *(int *)(unaff_EBP + -0x94);
    cVar2 = FUN_004c7929(&DAT_006f0bc0);
    if (((cVar2 == '\0') && (cVar2 = FUN_004b465e(), cVar2 != '\0')) &&
       (cVar2 = FUN_004b4665(), iVar3 = DAT_006f0bcc, cVar2 != '\0')) {
      iVar6 = (int)*(short *)(unaff_EBP + -0xb4);
      iVar4 = DAT_006f0bbc / 2;
      iVar8 = (int)*(short *)(unaff_EBP + -0xb2);
      *(int *)(unaff_EBP + 0x30) = iVar4;
      *(int *)(unaff_EBP + 0x28) = iVar3 + (iVar4 * iVar6 + iVar8) * 2;
      iVar4 = DAT_006f0bd4 / 2;
      *(int *)(unaff_EBP + 0x10) = iVar4;
      *(int *)(unaff_EBP + 0x24) = iVar6;
      iVar3 = DAT_006f0bd0;
      iVar7 = *(short *)(unaff_EBP + -0xb0) - iVar6;
      *(int *)(unaff_EBP + 0x20) = iVar8;
      iVar10 = *(short *)(unaff_EBP + -0xae) - iVar8;
      *(int *)(unaff_EBP + 0x18) = iVar3 + (iVar4 * iVar6 + iVar8) * 2;
      SetRect((LPRECT)(unaff_EBP + -0xe4),*(int *)(unaff_EBP + -0xa0),*(int *)(unaff_EBP + -0x98),
              *(int *)(unaff_EBP + -0x9c),*(int *)(unaff_EBP + -0x94));
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if ((*(int *)(unaff_EBP + 0x34) == 0x10) || (*(int *)(unaff_EBP + 0x34) == 0x20)) {
        iVar3 = FUN_004cebb0();
        *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(iVar3 + 0x38);
        if (*(int *)(unaff_EBP + 0x34) == 0x20) {
          *(undefined4 *)(unaff_EBP + -0x10) = 0xfffffed4;
        }
      }
      else {
        iVar3 = FUN_004cebb0();
        *(int *)(unaff_EBP + 0x14) =
             *(int *)(iVar3 + (0xe - *(int *)(unaff_EBP + 0xc)) * 4) +
             (0x10 << ((byte)*(int *)(unaff_EBP + 0xc) & 0x1f)) * 2 +
             *(int *)(unaff_EBP + -0x7c) * 2;
      }
      *(undefined ***)(unaff_EBP + -0xd4) = &PTR_FUN_00668958;
      *(undefined1 *)(unaff_EBP + -0xc0) = 0;
      *(undefined4 *)(unaff_EBP + -0xd0) = *(undefined4 *)(unaff_EBP + -0xb8);
      *(undefined4 *)(unaff_EBP + -0xcc) = *(undefined4 *)(unaff_EBP + -0xb8);
      *(undefined4 *)(unaff_EBP + -200) = 0;
      *(undefined4 *)(unaff_EBP + -0xc4) = 0;
      bVar11 = DAT_006f013a == '\0';
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (bVar11) {
        *(undefined4 *)(unaff_EBP + 0x1c) = 0;
      }
      else {
        uVar5 = FUN_004c7a32(*(undefined4 *)(unaff_EBP + 0x38),*(undefined4 *)(unaff_EBP + 0x34),
                             *(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x2c,unaff_EBP + -0x28,
                             unaff_EBP + -0x70,unaff_EBP + -0x74);
        *(undefined4 *)(unaff_EBP + 0x1c) = uVar5;
      }
      if ((*(int *)(unaff_EBP + 0x1c) == 0) ||
         (fVar12 = (float10)FUN_004b46a4(),
         ABS(fVar12 - (float10)_DAT_00666748) <= (float10)_DAT_0067343c)) {
        *(undefined1 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0xbc);
        *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0xbc);
        *(undefined ***)(unaff_EBP + -0x44) = &PTR_FUN_00668958;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x8c);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (*(int *)(unaff_EBP + 0x3c) == 0) {
          FUN_004c4aee(*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),iVar10,
                       iVar7,unaff_EBP + -0x44,unaff_EBP + -0xd4,*(undefined4 *)(unaff_EBP + 0x28),
                       *(undefined4 *)(unaff_EBP + 0x30),*(undefined4 *)(unaff_EBP + 0x18),
                       *(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0xe4,
                       *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x2c),
                       *(undefined4 *)(unaff_EBP + -0x10));
        }
        else if (*(int *)(unaff_EBP + 0x3c) == 1) {
          FUN_004c4c5e(*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),iVar10,
                       iVar7,unaff_EBP + -0x44,unaff_EBP + -0xd4,*(undefined4 *)(unaff_EBP + 0x28),
                       *(undefined4 *)(unaff_EBP + 0x30),*(undefined4 *)(unaff_EBP + 0x18),
                       *(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0xe4,
                       *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x2c),
                       *(undefined4 *)(unaff_EBP + -0x10));
        }
      }
      else if (*(int *)(unaff_EBP + 0x1c) == 1) {
        *(bool *)(unaff_EBP + 0x1c) = *(int *)(unaff_EBP + 0x34) == 1;
        FUN_0049f25a(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x1c));
        *(undefined4 *)(unaff_EBP + -0x60) = 0;
        *(undefined4 *)(unaff_EBP + -0x5c) = 0;
        *(undefined1 *)(unaff_EBP + -0x58) = 0;
        *(undefined ***)(unaff_EBP + -0x6c) = &PTR_FUN_00668958;
        *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0xbc);
        *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0xbc);
        uVar5 = *(undefined4 *)(unaff_EBP + 0x1c);
        iVar3 = unaff_EBP + -0x10;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        iVar4 = unaff_EBP + 0x38;
        uVar15 = *(undefined4 *)(unaff_EBP + 0xc);
        uVar14 = *(undefined4 *)(unaff_EBP + -0x28);
        uVar13 = *(undefined4 *)(unaff_EBP + -0x2c);
        FUN_004b5717(uVar13,uVar14,uVar15,iVar4,iVar3,uVar5);
        iVar3 = FUN_004b5e29(uVar13,uVar14,uVar15,iVar4,iVar3,uVar5);
        *(undefined ***)(unaff_EBP + -0x54) = &PTR_FUN_00668970;
        *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + 0x38);
        iVar3 = iVar3 - *(int *)(unaff_EBP + 0x38) * *(int *)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x4c) = iVar3;
        *(int *)(unaff_EBP + -0x50) = iVar3;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        if ((*(int *)(unaff_EBP + 0x34) == 1) ||
           (piVar9 = (int *)(unaff_EBP + -0xf4), *(int *)(unaff_EBP + 0x34) == 2)) {
          piVar9 = (int *)(unaff_EBP + -0x54);
        }
        iVar3 = (int)*(short *)(unaff_EBP + -0xb4) - (int)*(short *)(unaff_EBP + -0x84);
        *(int *)(unaff_EBP + 0x34) = iVar3;
        if (iVar3 != 0) {
          FUN_004ba71b(iVar3);
          (**(code **)(*piVar9 + 0xc))(*(undefined4 *)(unaff_EBP + 0x34));
        }
        if (*(int *)(unaff_EBP + 0x3c) == 0) {
          FUN_004b7808(*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),iVar10,
                       iVar7,unaff_EBP + -0x6c,*(undefined4 *)(unaff_EBP + -0x90),unaff_EBP + -0xd4,
                       piVar9,*(undefined4 *)(unaff_EBP + 0x28),*(undefined4 *)(unaff_EBP + 0x30),
                       *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x10),
                       unaff_EBP + -0xe4,*(undefined4 *)(unaff_EBP + 0x14),
                       *(undefined4 *)(unaff_EBP + 0x2c));
        }
        else if (*(int *)(unaff_EBP + 0x3c) == 1) {
          FUN_004b79e5(*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),iVar10,
                       iVar7,unaff_EBP + -0x6c,*(undefined4 *)(unaff_EBP + -0x90),unaff_EBP + -0xd4,
                       piVar9,*(undefined4 *)(unaff_EBP + 0x28),*(undefined4 *)(unaff_EBP + 0x30),
                       *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x10),
                       unaff_EBP + -0xe4,*(undefined4 *)(unaff_EBP + 0x14),
                       *(undefined4 *)(unaff_EBP + 0x2c));
        }
      }
      else if (*(int *)(unaff_EBP + 0x1c) == 2) {
        *(bool *)(unaff_EBP + 0x1c) = *(int *)(unaff_EBP + 0x34) == 1;
        FUN_0049f25a(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x1c));
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
        *(undefined1 *)(unaff_EBP + -0x30) = 0;
        *(undefined ***)(unaff_EBP + -0x44) = &PTR_FUN_00668958;
        *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0xbc);
        *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0xbc);
        uVar5 = *(undefined4 *)(unaff_EBP + 0x1c);
        iVar3 = unaff_EBP + 0x38;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        iVar4 = unaff_EBP + 0x3c;
        uVar15 = *(undefined4 *)(unaff_EBP + 0xc);
        uVar14 = *(undefined4 *)(unaff_EBP + -0x28);
        uVar13 = *(undefined4 *)(unaff_EBP + -0x2c);
        FUN_004b5717(uVar13,uVar14,uVar15,iVar4,iVar3,uVar5);
        iVar3 = FUN_004b5e29(uVar13,uVar14,uVar15,iVar4,iVar3,uVar5);
        *(undefined ***)(unaff_EBP + -0x54) = &PTR_FUN_00668970;
        iVar3 = iVar3 - *(int *)(unaff_EBP + 0x3c) * *(int *)(unaff_EBP + 0x38);
        *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + 0x3c);
        *(int *)(unaff_EBP + -0x4c) = iVar3;
        *(int *)(unaff_EBP + -0x50) = iVar3;
        uVar5 = *(undefined4 *)(unaff_EBP + 0x1c);
        iVar3 = unaff_EBP + 0x38;
        *(undefined1 *)(unaff_EBP + -4) = 7;
        iVar4 = unaff_EBP + 0x3c;
        uVar15 = *(undefined4 *)(unaff_EBP + 0xc);
        uVar14 = *(undefined4 *)(unaff_EBP + -0x74);
        uVar13 = *(undefined4 *)(unaff_EBP + -0x70);
        FUN_004b5717(uVar13,uVar14,uVar15,iVar4,iVar3,uVar5);
        iVar3 = FUN_004b5e29(uVar13,uVar14,uVar15,iVar4,iVar3,uVar5);
        *(undefined ***)(unaff_EBP + -100) = &PTR_FUN_00668970;
        *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + 0x3c);
        iVar3 = iVar3 - *(int *)(unaff_EBP + 0x3c) * *(int *)(unaff_EBP + 0x38);
        *(int *)(unaff_EBP + -0x5c) = iVar3;
        *(int *)(unaff_EBP + -0x60) = iVar3;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if ((*(int *)(unaff_EBP + 0x34) == 1) || (*(int *)(unaff_EBP + 0x34) == 2)) {
          piVar9 = (int *)(unaff_EBP + -0x54);
          iVar3 = unaff_EBP + -100;
        }
        else {
          piVar9 = (int *)(unaff_EBP + -0xf4);
          iVar3 = unaff_EBP + -0xf4;
        }
        *(int *)(unaff_EBP + 0x34) = iVar3;
        iVar3 = (int)*(short *)(unaff_EBP + -0xb4) - (int)*(short *)(unaff_EBP + -0x84);
        *(int *)(unaff_EBP + 0x1c) = iVar3;
        if (iVar3 != 0) {
          FUN_004ba71b(iVar3);
          (**(code **)(*piVar9 + 0xc))(*(undefined4 *)(unaff_EBP + 0x1c));
          (**(code **)(**(int **)(unaff_EBP + 0x34) + 0xc))(*(undefined4 *)(unaff_EBP + 0x1c));
        }
        FUN_004b75f8(*(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x24),iVar10,
                     iVar7,unaff_EBP + -0x44,*(undefined4 *)(unaff_EBP + -0x90),unaff_EBP + -0xd4,
                     piVar9,*(undefined4 *)(unaff_EBP + 0x34),*(undefined4 *)(unaff_EBP + 0x28),
                     *(undefined4 *)(unaff_EBP + 0x30),*(undefined4 *)(unaff_EBP + 0x18),
                     *(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0xe4,
                     *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x2c));
      }
    }
  }
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar1 = *(undefined4 *)(unaff_EBP + -0x24);
  puVar1[1] = *(undefined4 *)(unaff_EBP + -0x20);
  puVar1[2] = *(undefined4 *)(unaff_EBP + -0x1c);
  puVar1[3] = *(undefined4 *)(unaff_EBP + -0x18);
  return;
}

