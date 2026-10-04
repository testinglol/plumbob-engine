
undefined4 FUN_005c85e2(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  HDC hdc;
  UINT UVar9;
  byte *pbVar10;
  int extraout_ECX;
  int iVar11;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005caacc();
  piVar4 = *(int **)(unaff_EBP + 8);
  piVar1 = (int *)(extraout_ECX + 0x48);
  *piVar1 = *piVar4;
  *(int *)(extraout_ECX + 0x4c) = piVar4[1];
  if (*piVar1 < 0x32) {
    *piVar1 = 0x32;
  }
  if (*(int *)(extraout_ECX + 0x4c) < 0x32) {
    *(undefined4 *)(extraout_ECX + 0x4c) = 0x32;
  }
  SetRect((LPRECT)(extraout_ECX + 0x28),0,0,*piVar1,*(int *)(extraout_ECX + 0x4c));
  _memset((void *)(unaff_EBP + -0xa8),0,0x7c);
  cVar3 = *(char *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -0xa8) = 0x7c;
  if (cVar3 == '\0') {
    *(undefined4 *)(unaff_EBP + -0xa4) = 1;
    *(undefined4 *)(unaff_EBP + -0x40) = 0x2200;
    *(undefined1 *)(extraout_ECX + 0x44d) = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa4) = 0x21;
    *(undefined4 *)(unaff_EBP + -0x40) = 0x2218;
    *(undefined4 *)(unaff_EBP + -0x94) = 1;
    *(undefined1 *)(extraout_ECX + 0x44d) = 1;
  }
  iVar6 = (**(code **)(**(int **)(extraout_ECX + 0x74) + 0x18))
                    (*(int **)(extraout_ECX + 0x74),unaff_EBP + -0xa8,unaff_EBP + 8,0);
  *(int *)(extraout_ECX + 4) = iVar6;
  if (iVar6 == 0) {
    (**(code **)(*(int *)(extraout_ECX + 0xe8) + 4))(*(undefined4 *)(unaff_EBP + 8));
    uVar7 = FUN_005c841c(unaff_EBP + -0x14,extraout_ECX + 0xe8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005cb642(uVar7);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005cb62e();
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x58))(*(int **)(unaff_EBP + 8),unaff_EBP + -0xa8);
    iVar6 = *(int *)(unaff_EBP + -0xa0);
    *(undefined4 *)(extraout_ECX + 0xc) = *(undefined4 *)(unaff_EBP + -0x54);
    SetRect((LPRECT)(extraout_ECX + 0x38),0,0,*(int *)(unaff_EBP + -0x9c),iVar6);
    (**(code **)(**(int **)(unaff_EBP + 8) + 8))(*(int **)(unaff_EBP + 8));
    _memset((void *)(unaff_EBP + -0x124),0,0x7c);
    *(undefined4 *)(unaff_EBP + -0x118) = *(undefined4 *)(extraout_ECX + 0x48);
    *(undefined4 *)(unaff_EBP + -0x11c) = *(undefined4 *)(extraout_ECX + 0x4c);
    *(uint *)(unaff_EBP + -0xbc) =
         (-(uint)(*(char *)(extraout_ECX + 0x11) != '\0') & 0x1ffff800) + 0x800 | 0x2040;
    piVar1 = *(int **)(extraout_ECX + 0x74);
    *(undefined4 *)(unaff_EBP + -0x124) = 0x7c;
    *(undefined4 *)(unaff_EBP + -0x120) = 7;
    iVar6 = (**(code **)(*piVar1 + 0x18))(piVar1,unaff_EBP + -0x124,unaff_EBP + 8,0);
    *(int *)(extraout_ECX + 4) = iVar6;
    if (iVar6 == 0) {
      (**(code **)(*(int *)(extraout_ECX + 0x100) + 4))(*(undefined4 *)(unaff_EBP + 8));
      uVar7 = FUN_005c841c(unaff_EBP + -0x14,extraout_ECX + 0x100);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005cb642(uVar7);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005cb62e();
      (**(code **)(**(int **)(unaff_EBP + 8) + 8))(*(int **)(unaff_EBP + 8));
      if (*(char *)(extraout_ECX + 8) == '\0') {
LAB_005c885d:
        puVar2 = (undefined4 *)(extraout_ECX + 0x9c);
        iVar6 = (**(code **)(**(int **)(extraout_ECX + 0x74) + 0x10))
                          (*(int **)(extraout_ECX + 0x74),0,puVar2,0);
        *(int *)(extraout_ECX + 4) = iVar6;
        if (iVar6 == 0) {
          iVar6 = (**(code **)(*(int *)*puVar2 + 0x20))
                            ((int *)*puVar2,0,*(undefined4 *)(extraout_ECX + 300));
          *(int *)(extraout_ECX + 4) = iVar6;
          if (iVar6 == 0) {
            iVar6 = (**(code **)(**(int **)(extraout_ECX + 0xec) + 0x70))
                              (*(int **)(extraout_ECX + 0xec),*puVar2);
            *(int *)(extraout_ECX + 4) = iVar6;
            if (iVar6 == 0) goto LAB_005c88ad;
          }
        }
      }
      else {
        _memset((void *)(unaff_EBP + -0x2c),0,0x10);
        piVar1 = *(int **)(extraout_ECX + 0xec);
        *(undefined4 *)(unaff_EBP + -0x2c) = 4;
        iVar6 = (**(code **)(*piVar1 + 0x30))(piVar1,unaff_EBP + -0x2c,unaff_EBP + 8);
        *(int *)(extraout_ECX + 4) = iVar6;
        if (iVar6 == 0) {
          (**(code **)(*(int *)(extraout_ECX + 0xf4) + 4))(*(undefined4 *)(unaff_EBP + 8));
          uVar7 = FUN_005c841c(unaff_EBP + -0x14,extraout_ECX + 0xf4);
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_005cb642(uVar7);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005cb62e();
          (**(code **)(**(int **)(unaff_EBP + 8) + 8))(*(int **)(unaff_EBP + 8));
          if (*(char *)(extraout_ECX + 8) == '\0') goto LAB_005c885d;
LAB_005c88ad:
          _memset((void *)(unaff_EBP + -0x124),0,0x7c);
          piVar1 = *(int **)(extraout_ECX + 0xec);
          *(undefined4 *)(unaff_EBP + -0x124) = 0x7c;
          iVar6 = (**(code **)(*piVar1 + 0x58))(piVar1,unaff_EBP + -0x124);
          *(int *)(extraout_ECX + 4) = iVar6;
          if (iVar6 == 0) {
            uVar8 = *(uint *)(unaff_EBP + -0xd8) >> 5;
            *(byte *)(unaff_EBP + 0xb) = (byte)uVar8 & 1;
            if ((uVar8 & 1) == 0) goto LAB_005c8a24;
            iVar6 = *(int *)(unaff_EBP + 0x10);
            if (iVar6 == 0) {
              hdc = GetDC((HWND)0x0);
              if (hdc == (HDC)0x0) {
                *(undefined4 *)(extraout_ECX + 4) = 0x9b0b0014;
              }
              else {
                UVar9 = GetSystemPaletteEntries(hdc,0,0x100,(LPPALETTEENTRY)(unaff_EBP + -0x524));
                if (UVar9 != 0) {
                  ReleaseDC((HWND)0x0,hdc);
                  iVar6 = unaff_EBP + -0x524;
                  goto LAB_005c894b;
                }
                *(undefined4 *)(extraout_ECX + 4) = 1;
              }
            }
            else {
LAB_005c894b:
              if (*(char *)(extraout_ECX + 8) == '\0') {
                pbVar10 = (byte *)(iVar6 + 3);
                iVar11 = 10;
                do {
                  *pbVar10 = *pbVar10 | 0x40;
                  pbVar10 = pbVar10 + 4;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
                pbVar10 = (byte *)(iVar6 + 0x2b);
                iVar11 = 0xec;
                do {
                  bVar5 = *pbVar10;
                  if ((bVar5 & 1) == 0) {
                    if ((bVar5 & 4) != 0) {
                      bVar5 = bVar5 | 0x40;
                      goto LAB_005c896f;
                    }
                    *pbVar10 = 0;
                  }
                  else {
                    bVar5 = bVar5 | 0x80;
LAB_005c896f:
                    *pbVar10 = bVar5;
                  }
                  pbVar10 = pbVar10 + 4;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
                pbVar10 = (byte *)(iVar6 + 0x3db);
                iVar11 = 10;
                do {
                  *pbVar10 = *pbVar10 | 0x40;
                  pbVar10 = pbVar10 + 4;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
              }
              else {
                *(byte *)(iVar6 + 3) = *(byte *)(iVar6 + 3) | 0x40;
                pbVar10 = (byte *)(iVar6 + 7);
                iVar11 = 0xfe;
                do {
                  bVar5 = *pbVar10;
                  if ((bVar5 & 1) == 0) {
                    if ((bVar5 & 4) != 0) {
                      bVar5 = bVar5 | 0x40;
                      goto LAB_005c89ab;
                    }
                    *pbVar10 = 0;
                  }
                  else {
                    bVar5 = bVar5 | 0x80;
LAB_005c89ab:
                    *pbVar10 = bVar5;
                  }
                  pbVar10 = pbVar10 + 4;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
                *(undefined1 *)(iVar6 + 0x3ff) = 0x40;
              }
              puVar2 = (undefined4 *)(extraout_ECX + 0x98);
              iVar6 = (**(code **)(**(int **)(extraout_ECX + 0x74) + 0x14))
                                (*(int **)(extraout_ECX + 0x74),4,iVar6,puVar2,0);
              *(int *)(extraout_ECX + 4) = iVar6;
              if (iVar6 == 0) {
                iVar6 = (**(code **)(**(int **)(extraout_ECX + 0xec) + 0x7c))
                                  (*(int **)(extraout_ECX + 0xec),*puVar2);
                *(int *)(extraout_ECX + 4) = iVar6;
                if (iVar6 == 0) {
                  iVar6 = (**(code **)(**(int **)(extraout_ECX + 0x104) + 0x7c))
                                    (*(int **)(extraout_ECX + 0x104),*puVar2);
                  *(int *)(extraout_ECX + 4) = iVar6;
                  if (iVar6 == 0) {
                    piVar1 = *(int **)(extraout_ECX + 0xf8);
                    if (piVar1 != (int *)0x0) {
                      iVar6 = (**(code **)(*piVar1 + 0x7c))(piVar1,*puVar2);
                      *(int *)(extraout_ECX + 4) = iVar6;
                      if (iVar6 != 0) goto LAB_005c8a59;
                    }
LAB_005c8a24:
                    if (*(char *)(unaff_EBP + 0xc) == '\0') goto LAB_005c8a8d;
                    iVar6 = FUN_005c8aa1(extraout_ECX + 0x10c,extraout_ECX + 0x48);
                    if (iVar6 == 0) {
                      iVar6 = (**(code **)(**(int **)(extraout_ECX + 0x104) + 0xc))
                                        (*(int **)(extraout_ECX + 0x104),
                                         *(undefined4 *)(extraout_ECX + 0x110));
                      *(int *)(extraout_ECX + 4) = iVar6;
                      if (iVar6 == 0) {
                        uVar7 = FUN_005c841c(unaff_EBP + -0x1c,extraout_ECX + 0x10c);
                        *(undefined4 *)(unaff_EBP + -4) = 3;
                        FUN_005cb642(uVar7);
                        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                        FUN_005cb62e();
                        goto LAB_005c8a8d;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005c8a59:
  FUN_005caacc();
LAB_005c8a8d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(extraout_ECX + 4);
}

