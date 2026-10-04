
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00585fbd(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  HWND hWnd;
  int *piVar10;
  byte bVar11;
  char cVar12;
  int *extraout_ECX;
  int unaff_EBP;
  float10 fVar13;
  LPPOINT lpPoint;
  
  FUN_00634c24();
  iVar7 = (**(code **)(*extraout_ECX + 0xac))();
  *(int *)(unaff_EBP + -0x14) = iVar7;
  if (iVar7 == 0) goto LAB_0058668b;
  iVar8 = FUN_004b46a0();
  *(int *)(unaff_EBP + -0x34) = iVar8;
  FUN_00492d2c();
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(extraout_ECX[1] + 0x110);
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar7 + 4);
  uVar9 = FUN_004cebb4();
  iVar7 = extraout_ECX[0x36];
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar9;
  if ((char)iVar7 != '\0') {
    *(undefined1 *)(extraout_ECX + 0x36) = 0;
    (**(code **)(*extraout_ECX + 0x14))();
  }
  (**(code **)(*extraout_ECX + 0xd4))(0);
  FUN_005a1444(0);
  if (*(char *)((int)extraout_ECX + 0xdb) != '\0') {
    *(undefined1 *)((int)extraout_ECX + 0xdb) = 0;
    (**(code **)(*extraout_ECX + 0x24))(1);
  }
  *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(iVar8 + 0x68);
  *(undefined4 *)(unaff_EBP + -0x88) = *(undefined4 *)(iVar8 + 0x6c);
  iVar7 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x84) = *(undefined4 *)(iVar8 + 0x70);
  *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(iVar8 + 0x74);
  (**(code **)(iVar7 + 0x6c))(unaff_EBP + -0x8c);
  if (*(char *)((int)extraout_ECX + 0xd9) != '\0') {
    *(undefined1 *)((int)extraout_ECX + 0xd9) = 0;
    FUN_005992ca(extraout_ECX[0x2d],1,0);
    *(undefined1 *)((int)extraout_ECX + 0xda) = 1;
  }
  if (*(char *)((int)extraout_ECX + 0xda) == '\0') {
    iVar7 = *(int *)(unaff_EBP + -0x14);
  }
  else {
    *(undefined1 *)((int)extraout_ECX + 0xda) = 0;
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da(0);
    iVar7 = *(int *)(unaff_EBP + -0x14);
    FUN_005a1444(0);
    (**(code **)(*extraout_ECX + 0x6c))(unaff_EBP + -0x8c);
  }
  if ((*(char *)((int)extraout_ECX + 0x109) == '\0') ||
     (FUN_005a0f1a(extraout_ECX[0x2d]), *(char *)((int)extraout_ECX + 0x109) == '\0'))
  goto LAB_0058668b;
  *(undefined1 *)(unaff_EBP + -0x19) = 0;
  if (*(char *)((int)extraout_ECX + 0xf7) == '\0') {
    if ((char)extraout_ECX[0x3e] != '\0') {
      iVar8 = FUN_00415707();
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar8 + 4);
      FUN_005cf11a(unaff_EBP + -0xe8);
      uVar9 = DAT_006e5490;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar9;
      iVar8 = FUN_00415707(&DAT_006f6ae8);
      FUN_005c3840(unaff_EBP + -0x7c,iVar8 + 0x184);
      FUN_0049b802();
      if (extraout_ECX[0x41] == 0) {
        FUN_005cfd9c(extraout_ECX + 0x41,0);
      }
      FUN_005d0a0d(&DAT_006f6b38,unaff_EBP + -0x7c);
      *(undefined4 *)(unaff_EBP + -0x28) = 0x3f800000;
      FUN_005d0b17(unaff_EBP + -0x28);
      iVar8 = extraout_ECX[0x3f];
      *(undefined4 *)(unaff_EBP + -0x30) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x24) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x20) = 0x3f800000;
      if (iVar8 == 3) {
        fVar3 = 0.0;
LAB_0058624d:
        *(float *)(unaff_EBP + -0x20) = fVar3;
      }
      else {
        fVar3 = (float)extraout_ECX[0x40] * _DAT_00671eb4;
        if (iVar8 == 2) {
          if (fVar3 < _DAT_00666c18) {
            fVar3 = _DAT_00666c18;
          }
          if (_DAT_00666748 < fVar3) {
            fVar3 = 1.0;
          }
          if (_DAT_0066657c <= fVar3) {
            *(float *)(unaff_EBP + -0x30) = 1.0 - fVar3;
            *(float *)(unaff_EBP + -0x24) = 1.0 - fVar3;
            if (fVar3 < _DAT_00666a44) {
              *(float *)(unaff_EBP + -0x24) =
                   *(float *)(unaff_EBP + -0x24) - (_DAT_00666a44 - fVar3);
            }
          }
          else {
            fVar4 = _DAT_00666748 - fVar3 * fVar3;
            *(float *)(unaff_EBP + -0x24) = fVar4;
            *(float *)(unaff_EBP + -0x20) = fVar4;
            if (_DAT_00671eb0 < fVar3) {
              *(float *)(unaff_EBP + -0x24) =
                   *(float *)(unaff_EBP + -0x24) - (fVar3 + _DAT_00666a44);
            }
          }
        }
        else {
          if (fVar3 < _DAT_00666c18) {
            fVar3 = _DAT_00666c18;
          }
          if (_DAT_00666748 < fVar3) {
            fVar3 = 1.0;
          }
          if (_DAT_0066657c <= fVar3) {
            *(float *)(unaff_EBP + -0x30) = 1.0 - fVar3;
            *(float *)(unaff_EBP + -0x20) = 1.0 - fVar3;
            if (fVar3 < _DAT_00666a44) {
              *(float *)(unaff_EBP + -0x20) =
                   *(float *)(unaff_EBP + -0x20) - (_DAT_00666a44 - fVar3);
            }
          }
          else {
            fVar4 = _DAT_00666748 - fVar3 * fVar3;
            *(float *)(unaff_EBP + -0x20) = fVar4;
            *(float *)(unaff_EBP + -0x24) = fVar4;
            if (_DAT_00671eb0 < fVar3) {
              fVar3 = *(float *)(unaff_EBP + -0x20) - (fVar3 + _DAT_00666a44);
              goto LAB_0058624d;
            }
          }
        }
      }
      FUN_005d0abe(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x20);
      FUN_005ceca4(extraout_ECX[0x41]);
      fVar4 = _DAT_00667370;
      fVar3 = _DAT_00666a48;
      *(float *)(unaff_EBP + -0x60) = *(float *)(unaff_EBP + -0x30) * _DAT_00666a48 + _DAT_00667370;
      *(float *)(unaff_EBP + -0x5c) = *(float *)(unaff_EBP + -0x24) * fVar3 + fVar4;
      *(float *)(unaff_EBP + -0x58) = *(float *)(unaff_EBP + -0x20) * fVar3 + fVar4;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      uVar9 = FUN_005cee4b();
      *(undefined4 *)(unaff_EBP + -0x44) = uVar9;
      FUN_005cedcb(unaff_EBP + -0x60);
      *(float *)(unaff_EBP + -0x40) =
           (DAT_00673438 + DAT_00673438) * (float)*(int *)(unaff_EBP + -0x18) * _DAT_00666b7c *
           _DAT_00666578;
      FUN_005c4830();
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      fVar3 = DAT_00673438 * _DAT_00666578;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      *(float *)(unaff_EBP + -0x14) = fVar3;
      FUN_005c4a60(unaff_EBP + -0x14,unaff_EBP + -0x28,unaff_EBP + -0x40);
      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 0x60);
      FUN_0058669c(unaff_EBP + -0x70);
      *(undefined4 *)(iVar7 + 0x34) = 0x40400000;
      *(undefined4 *)(iVar7 + 0x30) = 0;
      *(undefined4 *)(iVar7 + 0x38) = 0;
      *(int *)(iVar7 + 0x130) = *(int *)(iVar7 + 0x130) + 1;
      *(int *)(iVar7 + 0x150) = *(int *)(iVar7 + 0x150) + 1;
      FUN_005995fd();
      (**(code **)(*extraout_ECX + 0x60))();
      FUN_005994da(0);
      FUN_005a1444(0);
      FUN_005a0f8b(0);
      FUN_005a0f1a(*(undefined4 *)(unaff_EBP + -0x18));
      FUN_0043270d(extraout_ECX[1]);
      iVar7 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0x98),0,&cXObject::RTTI_Type_Descriptor,
                           &cXPerson::RTTI_Type_Descriptor,0);
      if (iVar7 != 0) {
        bVar11 = (byte)*(undefined2 *)(iVar7 + 0x620);
        cVar5 = '\x01' - ((*(byte *)(iVar7 + 0x614) & 1) != 1);
        *(bool *)(unaff_EBP + -0x14) = (bVar11 & 2) == 2;
        sVar6 = *(short *)(iVar7 + 0x8e);
        *(char *)(unaff_EBP + -0x28) = cVar5;
        cVar12 = '\x01' - ((bVar11 & 1) != 1);
        *(char *)(unaff_EBP + -0x18) = cVar12;
        if (sVar6 != 0) {
          cVar12 = '\x01';
          *(undefined1 *)(unaff_EBP + -0x18) = 1;
        }
        if (extraout_ECX[0x3f] == 1) {
          cVar12 = '\0';
          *(undefined1 *)(unaff_EBP + -0x18) = 0;
        }
        if (cVar12 != '\0') {
          *(undefined1 *)(unaff_EBP + -0x19) = 1;
        }
        if ((((char)extraout_ECX[0x3d] != cVar5) || (*(char *)((int)extraout_ECX + 0xf5) != cVar12))
           || (*(char *)((int)extraout_ECX + 0xf6) != *(char *)(unaff_EBP + -0x14))) {
          uVar9 = *(undefined4 *)(unaff_EBP + -0x14);
          *(char *)(extraout_ECX + 0x3d) = cVar5;
          uVar1 = *(undefined1 *)(unaff_EBP + -0x14);
          *(char *)((int)extraout_ECX + 0xf5) = cVar12;
          uVar2 = *(undefined4 *)(unaff_EBP + -0x18);
          *(undefined1 *)((int)extraout_ECX + 0xf6) = uVar1;
          FUN_005a1917(*(undefined4 *)(unaff_EBP + -0x28),uVar2,uVar9);
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005c4890();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005c4890();
    }
  }
  else if (*(int *)(unaff_EBP + -0x2c) != 0) {
    iVar7 = *(int *)(iVar7 + 0xc);
    fVar13 = (float10)FUN_004b46a4();
    if ((*(byte *)(extraout_ECX[1] + 0x114) & 1) != 0) {
      fVar13 = (float10)1;
    }
    (**(code **)(*extraout_ECX + 0xe8))((float)fVar13,0);
    fVar13 = (float10)(**(code **)(*extraout_ECX + 0xe4))();
    FUN_004b4bbd((float)fVar13);
    *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar7 + 0x48);
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar7 + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar7 + 0x50);
    FUN_004b4b7d(unaff_EBP + -0x50,*(undefined4 *)(unaff_EBP + -0x28));
    FUN_004b4bc7();
  }
  *(undefined1 *)(unaff_EBP + -0xd) = DAT_006f6b78;
  GetCursorPos((LPPOINT)(unaff_EBP + -0x3c));
  lpPoint = (LPPOINT)(unaff_EBP + -0x3c);
  hWnd = (HWND)FUN_005caf13();
  ScreenToClient(hWnd,lpPoint);
  if (((*(char *)(unaff_EBP + -0xd) == '\0') || (*(int *)(unaff_EBP + -0x3c) < 0)) ||
     ((*(int *)(unaff_EBP + -0x38) < 0 ||
      (piVar10 = (int *)FUN_005caed9(), *piVar10 <= *(int *)(unaff_EBP + -0x3c))))) {
LAB_005865ed:
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
    DAT_006f6b74 = 0;
  }
  else {
    iVar7 = FUN_005caed9();
    if (*(int *)(iVar7 + 4) <= *(int *)(unaff_EBP + -0x38)) goto LAB_005865ed;
    *(short *)(unaff_EBP + -0x18) = (short)*(int *)(unaff_EBP + -0x38);
    *(undefined2 *)(unaff_EBP + -0x16) = *(undefined2 *)(unaff_EBP + -0x3c);
    uVar9 = FUN_004a994a(*(undefined4 *)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
  }
  cVar5 = FUN_004b465e();
  if (((cVar5 != '\0') && (cVar5 = FUN_004b4665(), cVar5 != '\0')) &&
     (*(char *)(unaff_EBP + -0x19) == '\0')) {
    FUN_005a148a(*(undefined4 *)(unaff_EBP + -0x34));
  }
  if ((((*(char *)(unaff_EBP + -0xd) != '\0') &&
       (sVar6 = FUN_004a994a(*(undefined4 *)(unaff_EBP + -0x18)),
       *(short *)(unaff_EBP + -0x14) != sVar6)) && (*(short *)(unaff_EBP + -0x14) != -1)) &&
     (sVar6 != -1)) {
    DAT_006f6b74 = extraout_ECX[1];
  }
  if (*(char *)((int)extraout_ECX + 0xf7) == '\0') {
    if ((char)extraout_ECX[0x3e] != '\0') {
      FUN_005cee2f(*(undefined4 *)(unaff_EBP + -0x44));
      FUN_005ced0e(extraout_ECX[0x41]);
    }
  }
  else if (*(int *)(unaff_EBP + -0x2c) != 0) {
    FUN_004b4ef5();
  }
LAB_0058668b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

