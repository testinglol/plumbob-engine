
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8b45(void)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  HWND hWnd;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  void *pvVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *extraout_ECX;
  int extraout_ECX_00;
  int unaff_EBP;
  undefined2 *puVar11;
  int iStack_120;
  int iStack_11c;
  int *piStack_118;
  LPRECT lpRect;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffef4;
  *(int **)(unaff_EBP + -0x34) = extraout_ECX;
  piStack_118 = (int *)0x4a8b70;
  FUN_005d51f5();
  FUN_004b406a();
  FUN_004b4533();
  *(int *)(unaff_EBP + -0x14) = unaff_EBP + -0x10c;
  if ((*(int *)(extraout_ECX[0x1b] + 4) == 0) && (*(int *)(extraout_ECX[0x1b] + 0x504) == 0)) {
    lpRect = (LPRECT)(unaff_EBP + -0x48);
    hWnd = (HWND)FUN_0049bacf();
    piStack_118 = (int *)0x4a8bbd;
    GetClientRect(hWnd,lpRect);
    BVar4 = IsRectEmpty((RECT *)(unaff_EBP + -0x48));
    if (BVar4 == 0) {
      if ((DAT_006f0094 != '\0') || (extraout_ECX[0x12f] != 0)) {
        *(undefined4 *)(unaff_EBP + -0x1c) = DAT_006fe838;
        DAT_006fe838 = DAT_006d6180;
        FUN_005cddcf();
        DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x1c);
      }
      piStack_118 = (int *)0x4a8c20;
      FUN_005d51f5();
      FUN_004b406a();
      if ((DAT_006f6b5c != (int *)0x0) && (extraout_ECX[0x69] == 0)) {
        (**(code **)(*DAT_006f6b5c + 0x84))();
      }
      if (*(char *)((int)extraout_ECX + 0x49) != '\0') {
        iVar5 = *(int *)(*DAT_006e486c + 0x14);
        piVar7 = (int *)(iVar5 + 0x84);
        *(int **)(unaff_EBP + -0x28) = piVar7;
        piVar7 = (int *)*piVar7;
        piVar1 = *(int **)(iVar5 + 0x88);
        *(int **)(unaff_EBP + -0x18) = piVar7;
        if (piVar7 != piVar1) {
          do {
            iVar5 = *piVar7;
            cVar3 = *(char *)(iVar5 + 0xfc);
            cVar2 = *(char *)(iVar5 + 0xfd);
            *(char *)(unaff_EBP + -0x20) = cVar3;
            *(char *)(unaff_EBP + -0x1f) = cVar2;
            *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(iVar5 + 0xfe);
            *(undefined4 *)(unaff_EBP + -4) = 0;
            if ('\0' < cVar3) {
              iVar5 = *(int *)(DAT_006e54dc + 0x10);
              *(int *)(unaff_EBP + -0x1c) = (int)cVar3;
              iVar5 = iVar5 + -1;
              if ((((cVar3 < iVar5) && ('\0' < cVar2)) &&
                  (*(int *)(unaff_EBP + -0x2c) = (int)cVar2, cVar2 < iVar5)) &&
                 ((cVar3 = FUN_0045e67a(), cVar3 != '\0' &&
                  ((*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x30 +
                                                        *(char *)(unaff_EBP + -0x1e) * 4) + 0xc) +
                                      *(int *)(unaff_EBP + -0x1c) * 4) + *(int *)(unaff_EBP + -0x2c)
                             ) & 4) != 0)))) {
                FUN_004abb9e();
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                break;
              }
            }
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            if (*(int *)(unaff_EBP + -0x18) == *(int *)(*(int *)(unaff_EBP + -0x28) + 4)) break;
            piVar7 = *(int **)(unaff_EBP + -0x18);
          } while( true );
        }
      }
      FUN_004a8aa5();
      FUN_0044651b();
      FUN_004aaec9();
      if (*(char *)((int)extraout_ECX + (0x14b - DAT_006f0088)) == '\0') {
        piStack_118 = (int *)0x4a8d4e;
        FUN_004ca03f();
      }
      iVar5 = extraout_ECX[0x69];
      *(int **)(unaff_EBP + -0x24) = extraout_ECX + 10;
      if (iVar5 == 0) {
        if (*(char *)((int)extraout_ECX + 0x17a) != '\0') {
          FUN_004b0542();
        }
      }
      else {
        FUN_004c9cf3();
        piStack_118 = (int *)0x4a8d72;
        piStack_118 = (int *)FUN_004c9cba();
        iStack_11c = 0x4a8d7a;
        FUN_004a83dc();
      }
      if ((extraout_ECX[0x5c] != 0) || (extraout_ECX[0x5d] != 0)) {
        DAT_006f0080 = DAT_006f0080 + extraout_ECX[0x5c];
        DAT_006f0084 = DAT_006f0084 + extraout_ECX[0x5d];
        FUN_004a7d36();
      }
      *(undefined1 *)((int)extraout_ECX + 0x179) = 1;
      iVar5 = *(int *)(*DAT_006e486c + 0x14);
      iVar6 = *(int *)(iVar5 + 0x84);
      *(int *)(unaff_EBP + -0x18) = iVar6;
      while (iVar6 != *(int *)(iVar5 + 0x88)) {
        piVar7 = (int *)**(undefined4 **)(unaff_EBP + -0x18);
        *(int **)(unaff_EBP + -0x1c) = piVar7;
        piVar7 = (int *)(**(code **)(*piVar7 + 0x8c))();
        cVar3 = (**(code **)(*piVar7 + 0x6c))();
        if (cVar3 == '\0') {
          FUN_0043908c();
        }
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
        iVar6 = *(int *)(unaff_EBP + -0x18);
      }
      if ((char)extraout_ECX[0x5e] == '\0') {
        *(undefined1 *)(extraout_ECX + 0x5e) = 1;
      }
      piStack_118 = (int *)0x4a8e2c;
      FUN_005d51f5();
      FUN_004b406a();
      piStack_118 = (int *)0x0;
      *(undefined4 *)(unaff_EBP + -0x30) = 1;
      iStack_11c = 0x4a8e4e;
      FUN_004b463f();
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      while (*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x30)) {
        if (*(int *)(unaff_EBP + -0x28) == 1) {
          piStack_118 = (int *)0x0;
          *(undefined4 *)(unaff_EBP + -0x28) = 2;
          iStack_11c = 0x4a8e7a;
          FUN_004b463f();
          piStack_118 = (int *)0x0;
          iStack_11c = 0x4a8e86;
          FUN_004b463f();
        }
        if ((extraout_ECX[0x5c] == 0) && (extraout_ECX[0x5d] == 0)) {
          if (DAT_006e4870 != '\0') {
            piStack_118 = (int *)0x4a8eb7;
            FUN_005d51f5();
            FUN_004b406a();
          }
          if ((extraout_ECX[0x133] < extraout_ECX[0x135]) &&
             (extraout_ECX[0x134] < extraout_ECX[0x136])) {
            FUN_004b469d();
            *(undefined4 *)(unaff_EBP + -0x38) = DAT_006fe838;
            DAT_006fe838 = DAT_006d6180;
            FUN_005cddcf();
            DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x38);
            extraout_ECX[0x133] = 0;
            extraout_ECX[0x134] = 0;
            extraout_ECX[0x135] = 0;
            extraout_ECX[0x136] = 0;
          }
          cVar3 = FUN_004b465e();
          puVar11 = *(undefined2 **)(unaff_EBP + -0x24);
          if (cVar3 != '\0') {
            FUN_004ab376();
          }
        }
        else {
          FUN_005db0b7();
          FUN_0057ac7f();
          FUN_004a7d36();
          iVar5 = FUN_00636bef();
          piVar7 = *(int **)(unaff_EBP + -0x24);
          if ((iVar5 < piVar7[2] - *piVar7) &&
             (iVar5 = FUN_00636bef(), iVar5 < piVar7[3] - piVar7[1])) {
            *(uint *)(unaff_EBP + -0x1c) = (uint)(DAT_006e4870 == '\0');
            cVar3 = FUN_004b465e();
            if (cVar3 != '\0') {
              FUN_004aadfa();
            }
            piStack_118 = (int *)0x0;
            iStack_11c = 0x4a8faf;
            FUN_004b463f();
            piStack_118 = (int *)0x0;
            iStack_11c = 0x4a8fbe;
            FUN_004b463f();
            *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
            *(undefined4 *)(unaff_EBP + -0x28) = 1;
            piStack_118 = *(int **)(unaff_EBP + -0x24);
            iStack_11c = 0x4a8fd4;
            FUN_004ab1fb();
          }
          else {
            (**(code **)(*extraout_ECX + 0x48))();
          }
          puVar11 = *(undefined2 **)(unaff_EBP + -0x24);
          extraout_ECX[0x5c] = 0;
          extraout_ECX[0x5d] = 0;
        }
        iStack_11c = 0x4a8ffb;
        piStack_118 = (int *)puVar11;
        FUN_004a9472();
        piStack_118 = (int *)0x4a9009;
        FUN_005d51f5();
        FUN_004b406a();
        *(undefined2 *)(unaff_EBP + -0x50) = puVar11[2];
        *(undefined2 *)(unaff_EBP + -0x4c) = puVar11[6];
        *(undefined2 *)(unaff_EBP + -0x4e) = *puVar11;
        *(undefined2 *)(unaff_EBP + -0x4a) = puVar11[4];
        _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x4c);
        _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x50);
        *(undefined4 *)(unaff_EBP + -0x3c) = _DAT_006f0bc4;
        *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x50);
        piStack_118 = (int *)0x4a9057;
        FUN_004b038a();
        if ((char)extraout_ECX[0x1e] != '\0') {
          extraout_ECX[0x1f] = 0;
        }
        *(undefined4 *)(unaff_EBP + -4) = 1;
        piStack_118 = (int *)0x4a9076;
        FUN_004acdcb();
        piStack_118 = (int *)0x4a9081;
        FUN_004ac916();
        if (extraout_ECX[0x11f] != 0) {
          FUN_004b0ba6();
          FUN_004a90a0();
          return;
        }
        cVar3 = *(char *)((int)extraout_ECX + 0x17f);
        *(undefined4 *)(unaff_EBP + -4) = 6;
        if (cVar3 != '\0') {
          piVar7 = (int *)FUN_005cf113();
          iVar5 = *piVar7;
          *(int **)(unaff_EBP + -0x1c) = piVar7;
          for (; iVar5 != piVar7[1]; iVar5 = iVar5 + 0x10) {
            piStack_118 = (int *)0xff;
            iStack_120 = 0x4a90d4;
            iStack_11c = iVar5;
            FUN_004b06db();
            piVar7 = *(int **)(unaff_EBP + -0x1c);
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004b048c();
        cVar3 = FUN_004b465e();
        if (cVar3 != '\0') {
          if (DAT_006e4870 != '\0') {
            FUN_005cf10c();
            FUN_004a891e();
            piVar7 = (int *)FUN_005cf113();
            *(int **)(unaff_EBP + -0x1c) = piVar7;
            if (piVar7 != extraout_ECX + 0x22) {
              FUN_004b4251();
              iVar5 = *(int *)(unaff_EBP + -0x1c);
              *(char *)(iVar5 + 0xc) = (char)extraout_ECX[0x25];
              *(int *)(iVar5 + 0x10) = extraout_ECX[0x26];
            }
            FUN_005caf36();
            FUN_005cf113();
            FUN_005cdecb();
          }
          FUN_004a891e();
        }
        *(undefined1 *)((int)extraout_ECX + 0x179) = 0;
        piStack_118 = (int *)0x4a917b;
        FUN_005d51f5();
        FUN_004b406a();
        if (((char)extraout_ECX[0x137] != '\0') && (cVar3 = FUN_004b465e(), cVar3 != '\0')) {
          iVar5 = 100;
          *(undefined1 *)(extraout_ECX + 0x137) = 0;
          pvVar8 = operator_new(100);
          *(void **)(unaff_EBP + -0x1c) = pvVar8;
          *(undefined4 *)(unaff_EBP + -4) = 8;
          if (pvVar8 == (void *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            puVar9 = (undefined4 *)FUN_005dfb13();
            iVar5 = extraout_ECX_00;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(undefined4 **)(unaff_EBP + -0x18) = puVar9;
          *(undefined4 **)(unaff_EBP + -0x1c) = puVar9;
          if (puVar9 != (undefined4 *)0x0) {
            uVar10 = *puVar9;
            piStack_118 = (int *)0x0;
            *(int **)(unaff_EBP + -0x20) = &iStack_120;
            piVar7 = extraout_ECX + 0x138;
            *(undefined4 *)(unaff_EBP + -0x20) = uVar10;
            iStack_120 = iVar5;
            iStack_11c = iVar5;
            FUN_00436a50(4);
            uVar10 = FUN_004a946b();
            uVar10 = FUN_004a9465(uVar10);
            cVar3 = (**(code **)(*(int *)(unaff_EBP + -0x20) + 0xc))(uVar10);
            if (cVar3 != '\0') {
              if ((char)extraout_ECX[0x130] != '\0') {
                piStack_118 = (int *)0x4a9231;
                FUN_004b038a();
                if ((char)extraout_ECX[0x1e] != '\0') {
                  extraout_ECX[0x1f] = 0;
                }
                FUN_004b1779();
                FUN_004b048c();
              }
              cVar3 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x20))();
              iVar6 = DAT_006f0084;
              iVar5 = DAT_006f0080;
              if (cVar3 != '\0') {
                *piVar7 = *piVar7 + DAT_006f0080;
                extraout_ECX[0x13a] = extraout_ECX[0x13a] + iVar5;
                extraout_ECX[0x139] = extraout_ECX[0x139] + iVar6;
                extraout_ECX[0x13b] = extraout_ECX[0x13b] + iVar6;
                if (*piVar7 < 0) {
                  iVar5 = -*piVar7;
                  *piVar7 = *piVar7 + iVar5;
                  extraout_ECX[0x13a] = extraout_ECX[0x13a] + iVar5;
                }
                if (extraout_ECX[0x139] < 0) {
                  iVar5 = -extraout_ECX[0x139];
                  extraout_ECX[0x139] = extraout_ECX[0x139] + iVar5;
                  extraout_ECX[0x13b] = extraout_ECX[0x13b] + iVar5;
                }
                if (*(int *)(DAT_006e486c[0xf] + 0x1c) < extraout_ECX[0x13a]) {
                  iVar5 = *(int *)(DAT_006e486c[0xf] + 0x1c) - extraout_ECX[0x13a];
                  *piVar7 = *piVar7 + iVar5;
                  extraout_ECX[0x13a] = extraout_ECX[0x13a] + iVar5;
                }
                if (*(int *)(DAT_006e486c[0xf] + 0x20) < extraout_ECX[0x13b]) {
                  iVar5 = *(int *)(DAT_006e486c[0xf] + 0x20) - extraout_ECX[0x13b];
                  extraout_ECX[0x139] = extraout_ECX[0x139] + iVar5;
                  extraout_ECX[0x13b] = extraout_ECX[0x13b] + iVar5;
                }
                iStack_11c = DAT_006e486c[0xf];
                iStack_120 = 0x4a92e7;
                piStack_118 = piVar7;
                (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x9c))();
                iStack_120 = 0x10;
                (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x24))();
                cVar3 = FUN_004074bc();
                if (cVar3 == '\x01') {
LAB_004a933d:
                  iVar5 = FUN_00410977();
                  *(int *)(unaff_EBP + -0x20) = iVar5;
                  if (iVar5 != 0) {
                    FUN_004cfdf2();
                    piStack_118 = (int *)0x4a9365;
                    FUN_004ed86c();
                    iVar5 = extraout_ECX[0x13e];
                    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                    if (iVar5 != extraout_ECX[0x13d]) {
                      FUN_004ed980();
                      piStack_118 = (int *)0x4a9390;
                      FUN_00406466();
                    }
                  }
                }
                else {
                  FUN_004e99a9();
                  iVar5 = FUN_004e9744();
                  if ((iVar5 != 0) && (iVar5 = FUN_00425db3(), iVar5 != 0)) goto LAB_004a933d;
                }
                if (((char)extraout_ECX[0x13c] != '\0') && (*(int *)(DAT_006f2a08 + 0x84) != 0)) {
                  piStack_118 = (int *)0x1f;
                  iStack_11c = 3;
                  iStack_120 = *(int *)(DAT_006f2a08 + 0x84);
                  FUN_005da644();
                }
              }
              if ((char)extraout_ECX[0x130] != '\0') {
                piStack_118 = (int *)0x4a93ce;
                FUN_004b038a();
                if ((char)extraout_ECX[0x1e] != '\0') {
                  extraout_ECX[0x1f] = 0;
                }
                FUN_004b1779();
                FUN_004b048c();
              }
            }
            if (*(undefined4 **)(unaff_EBP + -0x1c) != (undefined4 *)0x0) {
              (**(code **)**(undefined4 **)(unaff_EBP + -0x1c))();
            }
          }
        }
        *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
      }
      piStack_118 = (int *)0x4a9416;
      FUN_005d51f5();
      FUN_004b406a();
      thunk_FUN_005847fc();
      FUN_005a042b();
    }
  }
  piStack_118 = (int *)0x4a944c;
  FUN_005d51f5();
  FUN_004b406a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

