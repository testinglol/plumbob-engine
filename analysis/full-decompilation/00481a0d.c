
void FUN_00481a0d(void)

{
  short sVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  undefined4 *puVar11;
  LPRECT lprc;
  undefined4 *puVar12;
  
  FUN_00634c24();
  iVar10 = *DAT_006e486c;
  *(int *)(unaff_EBP + -0x34) = iVar10;
  FUN_004670a4(*(undefined4 *)(unaff_EBP + 8));
  iVar5 = FUN_00468838();
  *(int *)(unaff_EBP + -0x28) = iVar5;
  iVar6 = 1;
  if ((((*(char *)(unaff_EBP + 0x10) == '\0') || (iVar5 != 1)) ||
      (cVar4 = FUN_00468851(), cVar4 == '\0')) || (cVar4 = FUN_004074bc(), cVar4 != '\x01')) {
    *(undefined1 *)(unaff_EBP + -0x19) = 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x19) = 1;
  }
  iVar8 = (int)*(char *)(unaff_EBP + -0x28);
  iVar10 = *(int *)(iVar10 + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(int *)(unaff_EBP + -0x3c) = iVar10;
  *(int *)(unaff_EBP + -0x94) = iVar8;
  iVar5 = *(int *)(iVar10 + 0x10);
  iVar9 = *(int *)(iVar10 + 0x28 + iVar8 * 4);
  *(undefined1 *)(unaff_EBP + 0x13) = 0;
  uVar2 = *(undefined4 *)(iVar9 + 0xc);
  *(int *)(unaff_EBP + -0x14) = iVar5 + -1;
  *(undefined4 *)(unaff_EBP + -0x54) = uVar2;
  do {
    if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0x54) + (char)iVar6 * 4) +
                  *(char *)(unaff_EBP + -0x10) * 2) == *(short *)(unaff_EBP + 8)) {
      *(int *)(unaff_EBP + -0x20) = iVar6;
      *(int *)(unaff_EBP + -0x30) = iVar6;
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x10);
      *(undefined1 *)(unaff_EBP + 0x13) = 1;
    }
    iVar6 = iVar6 + 1;
    if (*(int *)(unaff_EBP + -0x14) <= iVar6) {
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar6 = 1;
      if (*(int *)(unaff_EBP + -0x14) <= *(int *)(unaff_EBP + -0x10)) {
        *(undefined1 *)(unaff_EBP + 0x13) = 1;
      }
    }
  } while (*(char *)(unaff_EBP + 0x13) == '\0');
  iVar10 = *(int *)(iVar10 + 0x28 + iVar8 * 4);
  *(undefined1 *)(unaff_EBP + 0x13) = 0;
  iVar10 = *(int *)(iVar10 + 0xc);
  iVar5 = *(int *)(unaff_EBP + -0x10);
  do {
    if (*(short *)(*(int *)(iVar10 + (char)iVar6 * 4) + (char)iVar5 * 2) ==
        *(short *)(unaff_EBP + 8)) {
      if (iVar6 < *(int *)(unaff_EBP + -0x30)) {
        *(int *)(unaff_EBP + -0x30) = iVar6;
      }
      if (*(int *)(unaff_EBP + -0x20) < iVar6) {
        *(int *)(unaff_EBP + -0x20) = iVar6;
      }
      if (iVar5 < *(int *)(unaff_EBP + -0x24)) {
        *(int *)(unaff_EBP + -0x24) = iVar5;
      }
      if (*(int *)(unaff_EBP + -0x2c) < iVar5) {
        *(int *)(unaff_EBP + -0x2c) = iVar5;
      }
    }
    iVar9 = *(int *)(unaff_EBP + -0x14);
    iVar6 = iVar6 + 1;
    if (iVar9 <= iVar6) {
      iVar5 = iVar5 + 1;
      iVar6 = 1;
      if (iVar9 <= iVar5) {
        *(undefined1 *)(unaff_EBP + 0x13) = 1;
      }
    }
  } while (*(char *)(unaff_EBP + 0x13) == '\0');
  if (1 < *(int *)(unaff_EBP + -0x30)) {
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -1;
  }
  if (*(int *)(unaff_EBP + -0x20) < iVar9 + -1) {
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
  }
  if (1 < *(int *)(unaff_EBP + -0x24)) {
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -1;
  }
  if (*(int *)(unaff_EBP + -0x2c) < iVar9 + -1) {
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
  }
  iVar10 = *(int *)(unaff_EBP + -0x30);
  FUN_00469648(iVar10 + -1,*(int *)(unaff_EBP + -0x24) + -1,iVar10,*(int *)(unaff_EBP + -0x2c) + 2,
               0x7fffffff);
  *(int *)(unaff_EBP + -0x68) = *(int *)(unaff_EBP + -0x68) << 4;
  *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -100) << 4;
  *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x60) << 4;
  *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x5c) << 4;
  FUN_0046ad0a(unaff_EBP + -0x68);
  OffsetRect((LPRECT)(unaff_EBP + -0x68),((*(int *)(unaff_EBP + -0x20) - iVar10) + 2) * 0x10,0);
  FUN_0046ad0a(unaff_EBP + -0x68);
  FUN_00469648(iVar10 + -1,*(int *)(unaff_EBP + -0x24) + -1,*(int *)(unaff_EBP + -0x20) + 2,
               *(int *)(unaff_EBP + -0x24),0x7fffffff);
  *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) << 4;
  *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) << 4;
  *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) << 4;
  *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) << 4;
  FUN_0046ad0a(unaff_EBP + -0x50);
  OffsetRect((LPRECT)(unaff_EBP + -0x50),0,
             ((*(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x24)) + 2) * 0x10);
  FUN_0046ad0a(unaff_EBP + -0x50);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x24);
LAB_00481c45:
  cVar4 = FUN_00482351(iVar10,*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x28),
                       *(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x34));
  if (cVar4 == '\0') {
    iVar6 = iVar10 + 1;
    iVar5 = *(int *)(unaff_EBP + -0x10) + 1;
    *(int *)(unaff_EBP + 0x10) = iVar5;
    FUN_00469648(iVar10,*(int *)(unaff_EBP + -0x10),iVar6,iVar5,0x7fffffff);
    *(int *)(unaff_EBP + -0x68) = *(int *)(unaff_EBP + -0x68) << 4;
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -100) << 4;
    *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x60) << 4;
    *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x5c) << 4;
    iVar5 = FUN_0046966e(unaff_EBP + -0x68,*(undefined4 *)(unaff_EBP + 0xc));
    if (iVar5 == -1) {
      while ((iVar6 <= *(int *)(unaff_EBP + -0x20) &&
             (cVar4 = FUN_00482351(iVar6,*(undefined4 *)(unaff_EBP + -0x10),
                                   *(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + 8)
                                   ,*(undefined4 *)(unaff_EBP + -0x34)), cVar4 == '\0'))) {
        iVar6 = iVar6 + 1;
      }
      iVar5 = *(int *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + -0x18) = iVar6;
      *(undefined1 *)(unaff_EBP + 0x13) = 1;
      do {
        *(int *)(unaff_EBP + -0x14) = iVar10;
        if (iVar10 < iVar6) {
          do {
            cVar4 = FUN_00482351(*(undefined4 *)(unaff_EBP + -0x14),iVar5,
                                 *(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + 8),
                                 *(undefined4 *)(unaff_EBP + -0x34));
            if (cVar4 != '\0') {
              *(undefined1 *)(unaff_EBP + 0x13) = 0;
              break;
            }
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x18));
          iVar6 = *(int *)(unaff_EBP + -0x18);
        }
        if ((*(char *)(unaff_EBP + 0x13) == '\0') || (*(int *)(unaff_EBP + -0x2c) < iVar5))
        goto LAB_00481d43;
        iVar5 = iVar5 + 1;
      } while( true );
    }
    iVar6 = *(int *)(**(int **)(unaff_EBP + 0xc) + 8 + iVar5 * 0x14) / 0x10;
    if (iVar10 != iVar6) {
      iVar10 = iVar6 + -1;
    }
  }
  else {
    *(char *)(unaff_EBP + -0x38) = (char)iVar10;
    *(undefined1 *)(unaff_EBP + -0x37) = *(undefined1 *)(unaff_EBP + -0x10);
    *(undefined1 *)(unaff_EBP + -0x36) = *(undefined1 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00479737(unaff_EBP + -0xe0,unaff_EBP + -0x38);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (((byte)*(undefined4 *)(unaff_EBP + -0xe0) & 8) == 8) {
      iVar6 = FUN_00435221(8,0);
      sVar1 = *(short *)(unaff_EBP + -0xd8 + iVar6 * 2);
      if (((sVar1 != 3) && (sVar1 != 5)) && ((sVar1 != 6 && ((sVar1 != 0xf && (sVar1 != 0x17)))))) {
        iVar6 = *(int *)(unaff_EBP + -0x10) + 1;
        cVar4 = FUN_00482351(iVar10,iVar6,*(undefined4 *)(unaff_EBP + -0x28),
                             *(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x34));
        if (cVar4 != '\0') {
          FUN_00469648(iVar10,iVar6,iVar10 + 1,iVar6,0x7fffffff);
          *(int *)(unaff_EBP + -0x90) = *(int *)(unaff_EBP + -0x90) << 4;
          *(int *)(unaff_EBP + -0x8c) = *(int *)(unaff_EBP + -0x8c) << 4;
          *(int *)(unaff_EBP + -0x88) = *(int *)(unaff_EBP + -0x88) << 4;
          *(int *)(unaff_EBP + -0x84) = *(int *)(unaff_EBP + -0x84) << 4;
          FUN_0046ad0a(unaff_EBP + -0x90);
        }
      }
    }
    if (((((((byte)*(undefined4 *)(unaff_EBP + -0xe0) & 4) == 4) &&
          (iVar6 = FUN_00467ece(4), iVar6 != 3)) && (iVar6 != 5)) &&
        ((iVar6 != 6 && (iVar6 != 0xf)))) && (iVar6 != 0x17)) {
      iVar6 = iVar10 + 1;
      cVar4 = FUN_00482351(iVar6,*(undefined4 *)(unaff_EBP + -0x10),
                           *(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + 8),
                           *(undefined4 *)(unaff_EBP + -0x34));
      if (cVar4 != '\0') {
        FUN_00469648(iVar6,*(int *)(unaff_EBP + -0x10),iVar6,*(int *)(unaff_EBP + -0x10) + 1,
                     0x7fffffff);
        *(int *)(unaff_EBP + -0xa8) = *(int *)(unaff_EBP + -0xa8) << 4;
        *(int *)(unaff_EBP + -0xa4) = *(int *)(unaff_EBP + -0xa4) << 4;
        *(int *)(unaff_EBP + -0xa0) = *(int *)(unaff_EBP + -0xa0) << 4;
        *(int *)(unaff_EBP + -0x9c) = *(int *)(unaff_EBP + -0x9c) << 4;
        FUN_0046ad0a(unaff_EBP + -0xa8);
      }
    }
    if ((*(byte *)(unaff_EBP + -0xe0) & 0x30) != 0) {
      FUN_00469648(iVar10,*(int *)(unaff_EBP + -0x10),iVar10 + 1,*(int *)(unaff_EBP + -0x10) + 1,
                   0x7fffffff);
      *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) << 4;
      *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) << 4;
      iVar5 = *(int *)(unaff_EBP + -0x48) * 0x10;
      iVar9 = *(int *)(unaff_EBP + -0x44) * 0x10;
      *(int *)(unaff_EBP + -0x48) = iVar5;
      *(int *)(unaff_EBP + -0x44) = iVar9;
      puVar11 = (undefined4 *)(unaff_EBP + -0x50);
      puVar12 = (undefined4 *)(unaff_EBP + -0x7c);
      for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      if (((byte)*(undefined4 *)(unaff_EBP + -0xe0) & 0x10) == 0x10) {
        *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) + 8;
        *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + 8;
        *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x70) + -8;
        *(int *)(unaff_EBP + -0x48) = iVar5 + -8;
      }
      else {
        *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + 8;
        *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x78) + 8;
        *(int *)(unaff_EBP + -0x44) = iVar9 + -8;
        *(int *)(unaff_EBP + -0x48) = iVar5 + -8;
      }
      InflateRect((LPRECT)(unaff_EBP + -0x50),-4,-4);
      InflateRect((LPRECT)(unaff_EBP + -0x7c),-4,-4);
      FUN_0046ad0a(unaff_EBP + -0x50);
      FUN_0046ad0a(unaff_EBP + -0x7c);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  goto LAB_00481fd7;
LAB_00481d43:
  *(int *)(unaff_EBP + -0x60) = iVar6 << 4;
  *(int *)(unaff_EBP + -0x5c) = iVar5 << 4;
  FUN_0046ad0a(unaff_EBP + -0x68);
LAB_00481fd7:
  iVar10 = iVar10 + 1;
  if (iVar10 <= *(int *)(unaff_EBP + -0x20)) goto LAB_00481c45;
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  iVar10 = *(int *)(unaff_EBP + -0x30);
  if (*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x10)) goto code_r0x00481ff3;
  goto LAB_00481c45;
code_r0x00481ff3:
  *(int *)(unaff_EBP + -0xac) =
       ((*(int **)(unaff_EBP + 0xc))[1] - **(int **)(unaff_EBP + 0xc)) / 0x14;
  if (*(char *)(unaff_EBP + -0x19) == '\0') {
LAB_00482322:
    iVar10 = *(int *)(unaff_EBP + -0xac);
    lprc = (LPRECT)**(undefined4 **)(unaff_EBP + 0xc);
    if (0 < iVar10) {
      do {
        InflateRect(lprc,7,7);
        lprc = (LPRECT)&lprc[1].top;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  *(int *)(unaff_EBP + -0x18) = iVar10;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -0x36) = *(undefined1 *)(unaff_EBP + -0x28);
LAB_00482024:
  cVar4 = *(char *)(unaff_EBP + -0x10);
  *(char *)(unaff_EBP + -0x38) = *(char *)(unaff_EBP + -0x18);
  *(char *)(unaff_EBP + -0x37) = cVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(int *)(unaff_EBP + -0x54) = (int)cVar4;
  iVar5 = *(char *)(unaff_EBP + -0x18) * 4;
  iVar10 = *(int *)(*(int *)(unaff_EBP + -0x3c) + 0x20 + *(int *)(unaff_EBP + -0x94) * 4);
  iVar6 = cVar4 * 2;
  *(int *)(unaff_EBP + -0xb0) = iVar6;
  if (*(short *)(*(int *)(*(int *)(iVar10 + 0xc) + iVar5) + iVar6) != 0) {
    FUN_00469648(0,0,1,1,0);
    if ((DAT_006e4a84 == 0) &&
       (uVar7 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x3c) + 0x34) +
                                                   0xc) + iVar5) + *(int *)(unaff_EBP + -0x54)) &
                0x20) >> 5, *(uint *)(unaff_EBP + 0x10) = uVar7, uVar7 == 0)) {
      iVar10 = *(int *)(unaff_EBP + -0x10) + 1;
      iVar6 = *(int *)(unaff_EBP + -0x18) + 1;
      *(int *)(unaff_EBP + 0x10) = iVar10;
      *(int *)(unaff_EBP + -0x14) = iVar6;
      FUN_00469648(*(int *)(unaff_EBP + -0x18),*(int *)(unaff_EBP + -0x10),iVar6,iVar10,10);
      puVar11 = (undefined4 *)(unaff_EBP + -0x68);
    }
    else {
      iVar10 = *(int *)(unaff_EBP + -0x10) + 1;
      iVar6 = *(int *)(unaff_EBP + -0x18) + 1;
      *(int *)(unaff_EBP + 0x10) = iVar10;
      *(int *)(unaff_EBP + -0x14) = iVar6;
      FUN_00469648(*(int *)(unaff_EBP + -0x18),*(int *)(unaff_EBP + -0x10),iVar6,iVar10,0);
      puVar11 = (undefined4 *)(unaff_EBP + -0xa8);
    }
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    puVar12 = (undefined4 *)(unaff_EBP + -0x90);
    for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    *(int *)(unaff_EBP + -0x90) = *(int *)(unaff_EBP + -0x90) << 4;
    *(int *)(unaff_EBP + -0x8c) = *(int *)(unaff_EBP + -0x8c) << 4;
    *(int *)(unaff_EBP + -0x88) = *(int *)(unaff_EBP + -0x88) << 4;
    *(int *)(unaff_EBP + -0x84) = *(int *)(unaff_EBP + -0x84) << 4;
    iVar10 = FUN_0046966e(unaff_EBP + -0x90,uVar2);
    *(int *)(unaff_EBP + -0xb4) = iVar10;
    FUN_00469648(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x10),
                 *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0x10),0);
    if ((DAT_006e4a84 == 0) &&
       (uVar7 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x3c) + 0x34) +
                                                   0xc) + iVar5) + *(int *)(unaff_EBP + -0x54)) &
                0x20) >> 5, *(uint *)(unaff_EBP + -0x54) = uVar7, uVar7 == 0)) {
      FUN_00469648(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x10),
                   *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0x10),10);
      puVar11 = (undefined4 *)(unaff_EBP + -0x50);
      puVar12 = (undefined4 *)(unaff_EBP + -0x7c);
      for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      iVar10 = *(int *)(unaff_EBP + -0xb4);
    }
    if (iVar10 == -1) {
      iVar10 = *(int *)(unaff_EBP + -0x14);
      if (iVar10 <= *(int *)(unaff_EBP + -0x20)) {
        iVar6 = *(int *)(unaff_EBP + -0x94);
        iVar5 = *(int *)(unaff_EBP + -0x3c);
        do {
          if ((*(short *)(*(int *)(*(int *)(*(int *)(iVar5 + 0x20 + iVar6 * 4) + 0xc) +
                                  (char)iVar10 * 4) + *(int *)(unaff_EBP + -0xb0)) == 0) ||
             (cVar4 = FUN_00482351(iVar10,*(undefined4 *)(unaff_EBP + -0x10),
                                   *(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + 8)
                                   ,*(undefined4 *)(unaff_EBP + -0x34)), cVar4 == '\0')) break;
          iVar10 = iVar10 + 1;
        } while (iVar10 <= *(int *)(unaff_EBP + -0x20));
      }
      iVar6 = *(int *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + -0x74) = iVar10;
      *(undefined1 *)(unaff_EBP + 0x13) = 1;
      do {
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x18);
        if (*(int *)(unaff_EBP + -0x18) < iVar10) {
          iVar5 = *(int *)(unaff_EBP + -0x94);
          *(undefined1 *)(unaff_EBP + -0x22) = *(undefined1 *)(unaff_EBP + -0x28);
          iVar9 = *(int *)(unaff_EBP + -0x3c);
          *(char *)(unaff_EBP + -0x23) = (char)iVar6;
          do {
            *(char *)(unaff_EBP + -0x24) = *(char *)(unaff_EBP + -0x14);
            iVar8 = *(int *)(iVar9 + 0x20 + iVar5 * 4);
            *(undefined1 *)(unaff_EBP + -4) = 3;
            if (*(short *)(*(int *)(*(int *)(iVar8 + 0xc) + *(char *)(unaff_EBP + -0x14) * 4) +
                          (char)iVar6 * 2) == 0) {
LAB_004822a7:
              bVar3 = true;
            }
            else {
              cVar4 = FUN_00482351(*(undefined4 *)(unaff_EBP + -0x14),iVar6,
                                   *(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + 8)
                                   ,*(undefined4 *)(unaff_EBP + -0x34));
              cVar4 = '\x01' - (cVar4 != '\0');
              *(char *)(unaff_EBP + -0x19) = cVar4;
              if (cVar4 != '\0') {
                iVar10 = *(int *)(unaff_EBP + -0x74);
                goto LAB_004822a7;
              }
              iVar10 = *(int *)(unaff_EBP + -0x74);
              bVar3 = false;
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
            if (bVar3) {
              *(undefined1 *)(unaff_EBP + 0x13) = 0;
              break;
            }
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          } while (*(int *)(unaff_EBP + -0x14) < iVar10);
        }
        if ((*(char *)(unaff_EBP + 0x13) == '\0') || (*(int *)(unaff_EBP + -0x2c) < iVar6))
        goto LAB_004822d0;
        iVar6 = iVar6 + 1;
      } while( true );
    }
    iVar10 = *(int *)(**(int **)(unaff_EBP + 0xc) + 8 + iVar10 * 0x14) / 0x10;
    if (iVar10 != *(int *)(unaff_EBP + -0x18)) {
      *(int *)(unaff_EBP + -0x18) = iVar10 + -1;
    }
  }
  goto LAB_004822fa;
LAB_004822d0:
  *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) << 4;
  *(int *)(unaff_EBP + -0x74) = iVar10 << 4;
  *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x78) << 4;
  *(int *)(unaff_EBP + -0x70) = iVar6 << 4;
  FUN_0046ad0a(unaff_EBP + -0x7c);
LAB_004822fa:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
  if (*(int *)(unaff_EBP + -0x18) <= *(int *)(unaff_EBP + -0x20)) goto LAB_00482024;
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x30);
  if (*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x10)) goto LAB_00482322;
  goto LAB_00482024;
}

