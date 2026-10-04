
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00590c09(void)

{
  float fVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  undefined4 uVar9;
  HWND hWnd;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  byte bVar14;
  int *extraout_ECX;
  int iVar15;
  int unaff_EBP;
  float10 fVar16;
  LPPOINT lpPoint;
  
  FUN_00634c24();
  iVar11 = extraout_ECX[0x4e];
  uVar2 = *(undefined2 *)(iVar11 + 0x620);
  if (((*(byte *)(iVar11 + 0x634) & 1) == 1) || ((*(byte *)(iVar11 + 0x614) & 1) == 1)) {
    *(undefined1 *)(unaff_EBP + -0x24) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x24) = 0;
  }
  bVar14 = (byte)uVar2;
  *(char *)(unaff_EBP + -0x20) = '\x01' - ((bVar14 & 1) != 1);
  *(bool *)(unaff_EBP + -0x28) = (bVar14 & 2) == 2;
  iVar8 = FUN_004b46a0();
  *(int *)(unaff_EBP + -0x3c) = iVar8;
  FUN_00492d2c();
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX[0x4e] + 0x110);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(extraout_ECX[2] + 4);
  uVar9 = FUN_004cebb4();
  iVar11 = extraout_ECX[0x36];
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar9;
  if ((char)iVar11 != '\0') {
    *(undefined1 *)(extraout_ECX + 0x36) = 0;
    (**(code **)(*extraout_ECX + 0x14))();
  }
  FUN_0058a17c(0);
  FUN_005a1444(0);
  if (*(char *)((int)extraout_ECX + 0xdb) != '\0') {
    *(undefined1 *)((int)extraout_ECX + 0xdb) = 0;
    (**(code **)(*extraout_ECX + 0x24))(0);
  }
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(iVar8 + 0x68);
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(iVar8 + 0x6c);
  iVar11 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(iVar8 + 0x70);
  *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(iVar8 + 0x74);
  (**(code **)(iVar11 + 0x6c))(unaff_EBP + -0x6c);
  cVar6 = *(char *)((int)extraout_ECX + 0x109);
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  if (cVar6 == '\0') {
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  if (*(char *)((int)extraout_ECX + 0xd9) != '\0') {
    *(undefined1 *)((int)extraout_ECX + 0xd9) = 0;
    FUN_005992ca(extraout_ECX[0x2d],1,0);
    *(undefined1 *)((int)extraout_ECX + 0xda) = 1;
  }
  if (*(char *)((int)extraout_ECX + 0xda) == '\0') {
    FUN_0059076c();
    FUN_005904d6();
  }
  else {
    *(undefined1 *)((int)extraout_ECX + 0xda) = 0;
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da(0);
    FUN_005a1444(0);
    FUN_0059076c();
    FUN_005904d6();
    (**(code **)(*extraout_ECX + 0x6c))(unaff_EBP + -0x6c);
  }
  if ((*(char *)((int)extraout_ECX + 0x109) != '\0') ||
     (extraout_ECX[0x95] != (int)*(short *)(extraout_ECX[0x4e] + 0x5c8))) {
    FUN_005a0f1a(extraout_ECX[0x2d]);
  }
  FUN_00590b2b();
  if (*(char *)((int)extraout_ECX + 0x109) == '\0') goto LAB_005912e5;
  if (*(int *)(unaff_EBP + -0x2c) != 0) {
    iVar11 = *(int *)(extraout_ECX[2] + 0xc);
    fVar16 = (float10)FUN_004b46a4();
    if ((*(byte *)(extraout_ECX[0x4e] + 0x114) & 1) != 0) {
      fVar16 = (float10)1;
    }
    (**(code **)(*extraout_ECX + 0xe8))((float)fVar16,0);
    fVar16 = (float10)(**(code **)(*extraout_ECX + 0xe4))();
    FUN_004b4bbd((float)fVar16);
    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar11 + 0x48);
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar11 + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar11 + 0x50);
    FUN_004b4b7d(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x18));
    FUN_004b4bc7();
  }
  *(undefined1 *)(unaff_EBP + -0xe) = DAT_006f6b78;
  GetCursorPos((LPPOINT)(unaff_EBP + -0x50));
  lpPoint = (LPPOINT)(unaff_EBP + -0x50);
  hWnd = (HWND)FUN_005caf13();
  ScreenToClient(hWnd,lpPoint);
  if ((((*(char *)(unaff_EBP + -0xe) == '\0') || (*(int *)(unaff_EBP + -0x50) < 0)) ||
      (*(int *)(unaff_EBP + -0x4c) < 0)) ||
     (piVar10 = (int *)FUN_005caed9(), *piVar10 <= *(int *)(unaff_EBP + -0x50))) {
LAB_00590ecb:
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    DAT_006f6b74 = 0;
  }
  else {
    iVar11 = FUN_005caed9();
    if (*(int *)(iVar11 + 4) <= *(int *)(unaff_EBP + -0x4c)) goto LAB_00590ecb;
    *(short *)(unaff_EBP + -0x14) = (short)*(int *)(unaff_EBP + -0x4c);
    *(undefined2 *)(unaff_EBP + -0x12) = *(undefined2 *)(unaff_EBP + -0x50);
    uVar9 = FUN_004a994a(*(undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -0x18) = uVar9;
  }
  if (((*(char *)(unaff_EBP + -0x24) != (char)extraout_ECX[0x3d]) ||
      (*(char *)(unaff_EBP + -0x20) != *(char *)((int)extraout_ECX + 0xf5))) ||
     (*(char *)(unaff_EBP + -0x28) != *(char *)((int)extraout_ECX + 0xf6))) {
    uVar9 = *(undefined4 *)(unaff_EBP + -0x28);
    *(char *)(extraout_ECX + 0x3d) = *(char *)(unaff_EBP + -0x24);
    uVar3 = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined1 *)((int)extraout_ECX + 0xf5) = *(undefined1 *)(unaff_EBP + -0x20);
    uVar4 = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined1 *)((int)extraout_ECX + 0xf6) = *(undefined1 *)(unaff_EBP + -0x28);
    FUN_005a1917(uVar4,uVar3,uVar9);
    uVar9 = FUN_0045741b();
    FUN_004eb227(uVar9);
  }
  cVar6 = FUN_004b465e();
  if ((cVar6 != '\0') && (cVar6 = FUN_004b4665(), cVar6 != '\0')) {
    FUN_005a148a(*(undefined4 *)(unaff_EBP + -0x3c));
  }
  if ((((*(char *)(unaff_EBP + -0xe) != '\0') &&
       (sVar7 = FUN_004a994a(*(undefined4 *)(unaff_EBP + -0x14)),
       *(short *)(unaff_EBP + -0x18) != sVar7)) && (*(short *)(unaff_EBP + -0x18) != -1)) &&
     (sVar7 != -1)) {
    DAT_006f6b74 = extraout_ECX[0x4e];
  }
  if (*(int *)(unaff_EBP + -0x2c) != 0) {
    FUN_004b4ef5();
  }
  uVar12 = (uint)*(short *)(extraout_ECX[0x4e] + 0x5c8);
  uVar5 = extraout_ECX[0x95];
  *(uint *)(unaff_EBP + -0x14) = uVar12;
  if (uVar5 != uVar12) {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  if (uVar12 == 0) {
    extraout_ECX[0x8c] = 0;
    extraout_ECX[0x8d] = 0;
    extraout_ECX[0x8e] = 0;
    extraout_ECX[0x8f] = 0;
    extraout_ECX[0x91] = 0x7149f2ca;
    extraout_ECX[0x90] = 0;
    extraout_ECX[0x92] = 0;
    goto LAB_005912e5;
  }
  if (extraout_ECX[0x94] == 0) {
    FUN_0058fafa();
    FUN_005992ca(extraout_ECX[0x2d],*(undefined1 *)(unaff_EBP + -0xd),0);
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da(0);
    FUN_005a1444(0);
    FUN_0059076c();
    FUN_005904d6();
    FUN_005a0f1a(extraout_ECX[0x2d]);
    FUN_00590b2b();
    uVar12 = *(uint *)(unaff_EBP + -0x14);
  }
  if ((uVar12 & 0x80) != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0x7f;
    uVar12 = *(uint *)(unaff_EBP + -0x14);
  }
  iVar11 = *(int *)(unaff_EBP + -0x1c);
  *(byte *)(unaff_EBP + -0xd) = (byte)(uVar12 >> 7) & 1;
  FUN_00599121(1);
  uVar9 = FUN_00595f4e(iVar11 + 0x1c);
  FUN_0049b9e6(unaff_EBP + -0xb0,uVar9);
  cVar6 = *(char *)(unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x90] = *(int *)(unaff_EBP + -0x80);
  extraout_ECX[0x91] = *(int *)(unaff_EBP + -0x7c);
  extraout_ECX[0x92] = *(int *)(unaff_EBP + -0x78);
  uVar9 = _DAT_0067204c;
  if (cVar6 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x48) = _DAT_0067204c;
    *(undefined4 *)(unaff_EBP + -0x44) = uVar9;
    *(undefined4 *)(unaff_EBP + -0x40) = uVar9;
    uVar9 = _DAT_00672048;
    *(undefined4 *)(unaff_EBP + -0x38) = _DAT_00672048;
    *(undefined4 *)(unaff_EBP + -0x34) = uVar9;
    *(undefined4 *)(unaff_EBP + -0x30) = uVar9;
    iVar11 = FUN_004b4714();
    FUN_0049b9e6(unaff_EBP + -0xf4,extraout_ECX + 0xe,iVar11 + 0xec);
    iVar11 = extraout_ECX[2];
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    iVar15 = 0;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar11 = *(int *)(iVar11 + 4);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    iVar8 = *(int *)(iVar11 + 0x8c) - *(int *)(iVar11 + 0x88) >> 2;
    *(int *)(unaff_EBP + -0x28) = iVar8;
    if (iVar8 < 1) {
LAB_005912c0:
      FUN_0059299a();
    }
    else {
      do {
        iVar8 = *(int *)(*(int *)(iVar11 + 0x88) + iVar15 * 4);
        if ((*(int *)(*(int *)(iVar8 + 4) + 0x14) == 1) &&
           (iVar15 = (*(int *)(iVar8 + 0xc) - *(int *)(iVar8 + 8)) / 0xc, 0 < iVar15)) {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          *(undefined1 *)(unaff_EBP + 0xb) = 1;
          *(int *)(unaff_EBP + -0x24) = iVar15;
          do {
            iVar15 = *(int *)(*(int *)(iVar8 + 8) + 8 + *(int *)(unaff_EBP + -0x14));
            *(int *)(unaff_EBP + -0x3c) = iVar15;
            iVar13 = *(int *)(*(int *)(iVar15 + 8) + 0x50) - *(int *)(*(int *)(iVar15 + 8) + 0x4c)
                     >> 3;
            if (0 < iVar13) {
              *(undefined4 *)(unaff_EBP + -0x1c) = 0;
              *(int *)(unaff_EBP + -0x18) = iVar13;
              while( true ) {
                iVar15 = *(int *)(iVar15 + 0xc);
                iVar13 = *(int *)(unaff_EBP + -0x1c);
                *(uint *)(iVar15 + 0x14) = *(uint *)(iVar15 + 0x14) | 1;
                *(uint *)(iVar15 + 0xc4) = *(uint *)(iVar15 + 0xc4) | 4;
                FUN_005c3840(unaff_EBP + -0x5c,*(int *)(iVar15 + 200) + iVar13,unaff_EBP + -0xf4);
                if (*(float *)(unaff_EBP + -0x5c) < *(float *)(unaff_EBP + -0x48)) {
                  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x5c);
                }
                if (*(float *)(unaff_EBP + -0x58) < *(float *)(unaff_EBP + -0x44)) {
                  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x58);
                }
                fVar1 = *(float *)(unaff_EBP + -0x54);
                if (fVar1 < *(float *)(unaff_EBP + -0x40)) {
                  *(float *)(unaff_EBP + -0x40) = fVar1;
                }
                if (*(float *)(unaff_EBP + -0x38) < *(float *)(unaff_EBP + -0x5c)) {
                  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x5c);
                }
                if (*(float *)(unaff_EBP + -0x34) < *(float *)(unaff_EBP + -0x58)) {
                  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x58);
                }
                if (*(float *)(unaff_EBP + -0x30) < fVar1) {
                  *(float *)(unaff_EBP + -0x30) = fVar1;
                }
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x20;
                piVar10 = (int *)(unaff_EBP + -0x18);
                *piVar10 = *piVar10 + -1;
                if (*piVar10 == 0) break;
                iVar15 = *(int *)(unaff_EBP + -0x3c);
              }
            }
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
            piVar10 = (int *)(unaff_EBP + -0x24);
            *piVar10 = *piVar10 + -1;
          } while (*piVar10 != 0);
        }
        iVar15 = *(int *)(unaff_EBP + -0x20) + 1;
        *(int *)(unaff_EBP + -0x20) = iVar15;
      } while (iVar15 < *(int *)(unaff_EBP + -0x28));
      if (*(char *)(unaff_EBP + 0xb) == '\0') goto LAB_005912c0;
      cVar6 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x14))();
      iVar8 = DAT_006f6d24 << (cVar6 - 1U & 0x1f);
      iVar15 = DAT_006d08dc << (cVar6 - 1U & 0x1f);
      iVar11 = __ftol();
      extraout_ECX[0x8c] = iVar11 + iVar8;
      iVar11 = __ftol();
      extraout_ECX[0x8e] = iVar11 + iVar8;
      iVar11 = __ftol();
      extraout_ECX[0x8d] = iVar11 + iVar15;
      iVar11 = __ftol();
      extraout_ECX[0x8f] = iVar11 + iVar15;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005c4890();
  }
  else {
    extraout_ECX[0x8c] = extraout_ECX[0x43];
    extraout_ECX[0x8d] = extraout_ECX[0x44];
    extraout_ECX[0x8e] = extraout_ECX[0x45];
    extraout_ECX[0x8f] = extraout_ECX[0x46];
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
LAB_005912e5:
  (**(code **)(*extraout_ECX + 0x6c))(unaff_EBP + -0x6c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

