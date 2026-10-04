
undefined4 FUN_0051b86b(void)

{
  char cVar1;
  SHORT SVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  size_t sVar8;
  char *_Str;
  void *pvVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *extraout_ECX;
  int iVar13;
  int unaff_EBP;
  uint uVar14;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  if (iVar5 == 1) {
    iVar5 = extraout_ECX[0x3d];
    iVar13 = *(int *)(unaff_EBP + 0xc);
    iVar7 = extraout_ECX[0x3c];
    uVar14 = 0;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (iVar5 - iVar7 >> 2 != 0) {
      iVar5 = extraout_ECX[0x3c];
      do {
        if (iVar13 == *(int *)(iVar5 + uVar14 * 4)) {
          SVar2 = GetAsyncKeyState(0x11);
          if (-1 < SVar2) {
            extraout_ECX[0x3a] = uVar14;
            uVar4 = FUN_004e9918(uVar14);
            FUN_004cfb63(uVar4);
            FUN_004cee86(8);
            FUN_0051c61b(uVar4);
            goto LAB_0051c525;
          }
          pvVar9 = operator_new(0xf4);
          *(void **)(unaff_EBP + 0xc) = pvVar9;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar9 == (void *)0x0) {
            piVar10 = (int *)0x0;
          }
          else {
            uVar4 = FUN_004e9918(uVar14);
            piVar10 = (int *)FUN_0050d159(uVar4);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          if ((piVar10 == (int *)0x0) || (cVar1 = (**(code **)(*piVar10 + 0xc))(), cVar1 == '\0'))
          goto LAB_0051c525;
          piVar11 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          iVar12 = (**(code **)(*piVar11 + 8))();
          iVar5 = *(int *)(iVar12 + 0x7c);
          iVar7 = *(int *)(iVar12 + 0x80);
          iVar13 = *(int *)(iVar12 + 0x84);
          *(int *)(unaff_EBP + -0x2c) = iVar7;
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar12 + 0x88);
          iVar7 = -iVar7;
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar7;
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar7;
          iVar7 = piVar10[0x20];
          iVar12 = piVar10[0x22];
          *(int *)(unaff_EBP + -0x28) = iVar13 - iVar5;
          FUN_004cb21d(((*(int *)(unaff_EBP + -0x28) - piVar10[0x21]) + piVar10[0x1f]) / 2,
                       (((iVar7 - iVar12) - *(int *)(unaff_EBP + -0x2c)) +
                       *(int *)(unaff_EBP + -0x24)) / 2);
          piVar10[0x12] = (int)extraout_ECX;
          FUN_004d3f37(1);
          FUN_004f778b();
          uVar4 = 0;
          piVar11 = piVar10;
          (**(code **)(*DAT_006fe8bc + 0x18))(0,piVar10);
          FUN_005daa44(uVar4,piVar11);
          FUN_004d3f37(0);
          FUN_005da4c7(piVar10);
          FUN_005db1e2();
          iVar5 = FUN_004cfb43();
          iVar7 = FUN_004e9918(*(undefined4 *)(unaff_EBP + -0x10));
          if (iVar7 == iVar5) goto LAB_0051c525;
          goto LAB_0051bee5;
        }
        iVar7 = extraout_ECX[0x3d];
        uVar14 = uVar14 + 1;
        iVar12 = extraout_ECX[0x3c];
        *(uint *)(unaff_EBP + -0x10) = uVar14;
      } while (uVar14 < (uint)(iVar7 - iVar12 >> 2));
    }
    if (iVar13 == extraout_ECX[0x57]) {
      if (extraout_ECX[0x3a] == -1) {
LAB_0051bee5:
        FUN_005e46f0(0);
        goto LAB_0051c525;
      }
      uVar4 = 1;
    }
    else if (iVar13 == extraout_ECX[0x5b]) {
      if (extraout_ECX[0x3a] == -1) goto LAB_0051bee5;
      uVar4 = 2;
    }
    else if (iVar13 == extraout_ECX[0x58]) {
      if (extraout_ECX[0x3a] == -1) goto LAB_0051bee5;
      uVar4 = 5;
    }
    else if (iVar13 == extraout_ECX[0x59]) {
      if (extraout_ECX[0x3a] == -1) goto LAB_0051bee5;
      uVar4 = 3;
    }
    else if (iVar13 == extraout_ECX[0x5a]) {
      if ((extraout_ECX[0x3a] == -1) || (cVar1 = FUN_004074bc(), cVar1 != '\x01')) {
        FUN_005e46f0(0);
        FUN_0057a7f7(s_UI_error_006c5e80,0xfffffffc);
        goto LAB_0051c525;
      }
      uVar4 = 4;
    }
    else if (iVar13 == extraout_ECX[0x5c]) {
      if (extraout_ECX[0x3a] == -1) goto LAB_0051bee5;
      uVar4 = 6;
    }
    else {
      if (iVar13 != extraout_ECX[0x5d]) {
        if (extraout_ECX[0x3f] == 1) {
          for (piVar10 = (int *)extraout_ECX[0x4a]; piVar10 != (int *)extraout_ECX[0x4b];
              piVar10 = piVar10 + 1) {
            if (*piVar10 == iVar13) {
              if (piVar10 != (int *)extraout_ECX[0x4b]) {
                iVar5 = extraout_ECX[0x56];
                iVar7 = *piVar10;
                *(undefined4 *)(unaff_EBP + 8) = 1;
                iVar7 = *(int *)(iVar7 + 0x1a0);
                if (*(char *)(iVar5 + 0xe0) == '\0') {
                  FUN_0050fb20(iVar7,extraout_ECX);
                }
                else if (*(int *)(iVar5 + 0x10c) == iVar7) {
                  FUN_0050fc0a(1);
                }
                else {
                  FUN_0050fc6a(iVar7);
                }
              }
              break;
            }
          }
          for (piVar10 = (int *)extraout_ECX[0x4d]; piVar10 != (int *)extraout_ECX[0x4e];
              piVar10 = piVar10 + 1) {
            if (*piVar10 == iVar13) {
              if (piVar10 != (int *)extraout_ECX[0x4e]) {
                iVar5 = extraout_ECX[0x56];
                cVar1 = *(char *)(iVar5 + 0xe0);
                iVar7 = *(int *)(*piVar10 + 0x1a0);
                *(undefined4 *)(unaff_EBP + 8) = 1;
                if (cVar1 != '\0') {
                  if (*(int *)(iVar5 + 0x10c) != iVar7) goto LAB_0051bfa5;
                  goto LAB_0051bf9a;
                }
                FUN_0050fb20(iVar7,extraout_ECX);
              }
              break;
            }
          }
          if (*(int *)(unaff_EBP + 8) != 0) goto LAB_0051c525;
        }
        if (extraout_ECX[0x3f] == 2) {
          for (piVar10 = (int *)extraout_ECX[0x50]; piVar10 != (int *)extraout_ECX[0x51];
              piVar10 = piVar10 + 1) {
            if (*piVar10 == iVar13) {
              if (piVar10 != (int *)extraout_ECX[0x51]) {
                iVar5 = extraout_ECX[0x56];
                iVar7 = *piVar10;
                *(undefined4 *)(unaff_EBP + 8) = 1;
                iVar7 = *(int *)(iVar7 + 0x19c);
                if (*(char *)(iVar5 + 0xe0) == '\0') {
                  FUN_0050fb20(iVar7,extraout_ECX);
                }
                else if (*(int *)(iVar5 + 0x10c) == iVar7) {
                  FUN_0050fc0a(1);
                }
                else {
                  FUN_0050fc6a(iVar7);
                }
              }
              break;
            }
          }
          if (extraout_ECX[0x71] == iVar13) {
            uVar4 = *(undefined4 *)(extraout_ECX[0x71] + 0x4c);
            *(undefined4 *)(unaff_EBP + 8) = 1;
            sVar3 = FUN_00484444(uVar4);
            if ((0 < sVar3) && (sVar3 < 0xd)) {
              FUN_00510747(extraout_ECX[(short)(sVar3 + -1) * 3 + 0x73]);
              FUN_00510775(extraout_ECX[(short)(sVar3 + -1) * 3 + 0x97]);
              if (*(char *)(extraout_ECX[0x56] + 0xe0) == '\0') {
                FUN_0050fb20(extraout_ECX[0x72],extraout_ECX);
                goto LAB_0051c0bb;
              }
              iVar7 = extraout_ECX[0x72];
              if (*(int *)(extraout_ECX[0x56] + 0x10c) == iVar7) {
LAB_0051bf9a:
                FUN_0050fc0a(1);
              }
              else {
LAB_0051bfa5:
                FUN_0050fc6a(iVar7);
              }
            }
          }
          else {
LAB_0051c0bb:
            if (*(int *)(unaff_EBP + 8) == 0) goto LAB_0051c0c5;
          }
          goto LAB_0051c525;
        }
LAB_0051c0c5:
        if (extraout_ECX[0x3f] == 5) {
          for (piVar10 = (int *)extraout_ECX[0x53]; piVar10 != (int *)extraout_ECX[0x54];
              piVar10 = piVar10 + 1) {
            if (*piVar10 == iVar13) {
              if (piVar10 != (int *)extraout_ECX[0x54]) {
                iVar5 = extraout_ECX[0x56];
                iVar7 = *piVar10;
                *(undefined4 *)(unaff_EBP + 8) = 1;
                iVar13 = *(int *)(iVar7 + 0x1ac);
                if (*(char *)(iVar5 + 0xe0) == '\0') {
                  *(int *)(iVar13 + 0x14) = iVar7;
                  FUN_00528ce1();
                  FUN_0050fb20(iVar13,extraout_ECX);
                }
                else if (*(int *)(*(int *)(iVar5 + 0x10c) + 0x14) == iVar7) {
                  FUN_0050fc0a(1);
                }
                else {
                  if (*(int *)(iVar13 + 0x14) != 0) {
                    FUN_005e46f0(0);
                  }
                  *(int *)(iVar13 + 0x14) = *piVar10;
                  FUN_00528ce1();
                  FUN_0050fc6a(iVar13);
                }
                iVar13 = *(int *)(unaff_EBP + 0xc);
              }
              break;
            }
          }
          if (iVar13 == extraout_ECX[0x65]) {
            FUN_0050fc0a(1);
            extraout_ECX[100] = extraout_ECX[100] + -1;
          }
          else if (iVar13 == extraout_ECX[0x66]) {
            FUN_0050fc0a(1);
            extraout_ECX[100] = extraout_ECX[100] + 1;
          }
          else {
            if ((iVar13 == extraout_ECX[0x67]) || (iVar13 == extraout_ECX[0x68])) {
              FUN_005e46f0(0);
              FUN_005e46f0(0);
            }
            else {
              if (iVar13 != extraout_ECX[0x69]) {
                if (iVar13 == extraout_ECX[0x6a]) {
                  FUN_005e46f0(0);
                  FUN_005e46f0(0);
                  FUN_005e46f0(0);
                  FUN_0050fc0a(1);
                  extraout_ECX[100] = 0;
                  FUN_0051d7c8();
                  (**(code **)(*extraout_ECX + 0x168))();
                  *(undefined4 *)(unaff_EBP + 8) = 1;
                }
                if (*(int *)(unaff_EBP + 8) != 0) goto LAB_0051c525;
                goto LAB_0051c282;
              }
              FUN_005e46f0(0);
              FUN_005e46f0(0);
            }
            FUN_005e46f0(0);
            FUN_0050fc0a(1);
            extraout_ECX[100] = 0;
          }
          FUN_0051d7c8();
        }
        else {
LAB_0051c282:
          if (extraout_ECX[0x3f] == 6) {
            *(undefined4 *)(unaff_EBP + -0x14) = 0x13;
            *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0xd7;
            do {
              iVar5 = **(int **)(unaff_EBP + -0x10);
              if (iVar5 == iVar13) {
                iVar7 = extraout_ECX[0x56];
                iVar13 = *(int *)(iVar5 + 0x19c);
                *(undefined4 *)(unaff_EBP + 8) = 1;
                if (*(char *)(iVar7 + 0xe0) == '\0') {
                  *(int *)(iVar13 + 0x14) = iVar5;
                  FUN_0050f513();
                  FUN_0050fb20(iVar13,extraout_ECX);
                }
                else if (*(int *)(*(int *)(iVar7 + 0x10c) + 0x14) == iVar5) {
                  FUN_0050fc0a(1);
                }
                else {
                  if (*(int *)(iVar13 + 0x14) != 0) {
                    FUN_005e46f0(0);
                  }
                  *(int *)(iVar13 + 0x14) = iVar5;
                  FUN_0050f513();
                  FUN_0050fc6a(iVar13);
                }
                iVar13 = *(int *)(unaff_EBP + 0xc);
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
              piVar10 = (int *)(unaff_EBP + -0x14);
              *piVar10 = *piVar10 + -1;
            } while (*piVar10 != 0);
            if (iVar13 == extraout_ECX[0xd0]) {
              if (extraout_ECX[0x102] + -1 < 0) {
                extraout_ECX[0x102] = 0;
              }
              else {
                extraout_ECX[0x102] = extraout_ECX[0x102] + -1;
              }
              FUN_0051e1a1();
              goto LAB_0051c51b;
            }
            if (iVar13 == extraout_ECX[0xd1]) {
              if (extraout_ECX[0x103] < extraout_ECX[0x102] + 1) {
                extraout_ECX[0x102] = extraout_ECX[0x103];
              }
              else {
                extraout_ECX[0x102] = extraout_ECX[0x102] + 1;
              }
              FUN_0051e1a1();
              (**(code **)(*extraout_ECX + 0x168))();
              *(undefined4 *)(unaff_EBP + 8) = 1;
            }
            if (*(int *)(unaff_EBP + 8) != 0) goto LAB_0051c525;
          }
          if (extraout_ECX[0x3f] != 7) goto LAB_0051c525;
          iVar5 = extraout_ECX[0x10e];
          *(undefined4 *)(unaff_EBP + 8) = 0;
          if (iVar5 - extraout_ECX[0x10d] >> 2 != 0) {
            do {
              iVar5 = *(int *)(extraout_ECX[0x10d] + *(int *)(unaff_EBP + 8) * 4);
              if (iVar5 == iVar13) {
                iVar7 = *(int *)(iVar5 + 0x1b4);
                if (*(char *)(extraout_ECX[0x56] + 0xe0) == '\0') {
                  *(int *)(iVar7 + 0x14) = iVar5;
                  FUN_0050e75d();
                  FUN_0050fb20(iVar7,extraout_ECX);
                }
                else if (*(int *)(*(int *)(extraout_ECX[0x56] + 0x10c) + 0x14) == iVar5) {
                  FUN_0050fc0a(1);
                }
                else {
                  if (*(int *)(iVar7 + 0x14) != 0) {
                    FUN_005e46f0(0);
                  }
                  *(int *)(iVar7 + 0x14) = iVar5;
                  FUN_0050e75d();
                  FUN_0050fc6a(iVar7);
                }
                iVar13 = *(int *)(unaff_EBP + 0xc);
              }
              iVar5 = extraout_ECX[0x10e];
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
            } while (*(uint *)(unaff_EBP + 8) < (uint)(iVar5 - extraout_ECX[0x10d] >> 2));
          }
          if (iVar13 == extraout_ECX[0x106]) {
            iVar5 = extraout_ECX[0x115] + -1;
            if (iVar5 < 0) {
              extraout_ECX[0x115] = 0;
            }
            else {
LAB_0051c493:
              extraout_ECX[0x115] = iVar5;
            }
          }
          else {
            if (iVar13 != extraout_ECX[0x107]) {
              if (iVar13 == extraout_ECX[0x6b]) {
                FUN_0051e3b5();
                FUN_005e46f0(0);
              }
              else {
                if (iVar13 == extraout_ECX[0x6c]) {
                  FUN_0051e3b5();
                }
                else {
                  if (iVar13 != extraout_ECX[0x6d]) goto LAB_0051c525;
                  FUN_0051e3b5();
                }
                FUN_005e46f0(0);
              }
              FUN_005e46f0(0);
              FUN_004cee86(0x4000000);
              goto LAB_0051c51b;
            }
            iVar5 = extraout_ECX[0x115] + 1;
            if (iVar5 <= extraout_ECX[0x116]) goto LAB_0051c493;
            extraout_ECX[0x115] = extraout_ECX[0x116];
          }
          FUN_0051e3b5();
        }
LAB_0051c51b:
        (**(code **)(*extraout_ECX + 0x168))();
        goto LAB_0051c525;
      }
      if (extraout_ECX[0x3a] == -1) goto LAB_0051bee5;
      uVar4 = 7;
    }
    FUN_0051d3e7(uVar4);
  }
  else if (iVar5 == 0xe) {
    iVar5 = *(int *)(unaff_EBP + 0xc);
    if ((iVar5 == extraout_ECX[0x37]) || (iVar5 == extraout_ECX[0x38])) {
      FUN_00484901(6);
      FUN_0048e072(iVar5);
    }
  }
  else if (iVar5 == 0xf) {
    iVar5 = *(int *)(unaff_EBP + 0xc);
    if ((iVar5 == extraout_ECX[0x37]) || (iVar5 == extraout_ECX[0x38])) {
      uVar4 = FUN_00484901(6);
      FUN_006359f2(uVar4,0,&cTool::RTTI_Type_Descriptor,&cObjPickerTool::RTTI_Type_Descriptor,0);
      FUN_0048deb1(iVar5);
    }
  }
  else {
    if (iVar5 == 0x10) {
LAB_0051bb60:
      cVar1 = (**(code **)(*(int *)extraout_ECX[0x38] + 500))();
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*(int *)extraout_ECX[0x37] + 500))();
        if (cVar1 == '\0') goto LAB_0051c525;
        piVar10 = (int *)extraout_ECX[0x37];
      }
      else {
        piVar10 = (int *)extraout_ECX[0x38];
      }
      iVar5 = *piVar10;
      uVar4 = 0xffffffff;
    }
    else {
      if (iVar5 != 0x12) {
        if (iVar5 == 0x13) {
          iVar5 = extraout_ECX[0x3d];
          iVar7 = extraout_ECX[0x3c];
          uVar14 = 0;
          *(undefined4 *)(unaff_EBP + 8) = 0;
          if (iVar5 - iVar7 >> 2 != 0) {
            iVar5 = extraout_ECX[0x3c];
            do {
              if (*(int *)(unaff_EBP + 0xc) == *(int *)(iVar5 + uVar14 * 4)) {
                iVar5 = FUN_004e9918(uVar14);
                if ((iVar5 != -1) && (extraout_ECX[0xbe] != 0)) {
                  uVar4 = FUN_005d49d6();
                  uVar6 = FUN_004096c2(uVar4);
                  uVar4 = FUN_005b86cf(uVar6,uVar4);
                  *(undefined4 *)(unaff_EBP + -4) = 1;
                  FUN_004e9c34(iVar5,uVar4);
                  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                  FUN_005b8770();
                  FUN_004e9bbd(iVar5);
                  uVar4 = FUN_004096c2();
                  FUN_005d4bbf(uVar4);
                  iVar7 = FUN_004ea79e(iVar5);
                  sVar3 = *(short *)(iVar7 + 0x8c);
                  *(uint *)(unaff_EBP + 0xc) = CONCAT22((short)((uint)iVar5 >> 0x10),sVar3);
                  FUN_005d4bbf(&DAT_006de560);
                  if (0 < sVar3) {
                    sVar8 = _strlen(&DAT_006ccae4);
                    FUN_00412d8a(&DAT_006ccae4,&DAT_006ccae4 + sVar8);
                    _Str = (char *)FUN_00484411(*(undefined4 *)(unaff_EBP + 0xc));
                    sVar8 = _strlen(_Str);
                    FUN_00412d8a(_Str,_Str + sVar8);
                    sVar8 = _strlen(&DAT_006c3cd4);
                    FUN_00412d8a(&DAT_006c3cd4,&DAT_006c3cd4 + sVar8);
                  }
                  FUN_00510747(extraout_ECX[0xbf]);
                  FUN_00510775(extraout_ECX[0xc2]);
                  if (*(char *)(extraout_ECX[0x56] + 0xe0) == '\0') {
                    FUN_0050fb20(extraout_ECX[0xbe],extraout_ECX);
                  }
                  else {
                    FUN_0050fc6a(extraout_ECX[0xbe]);
                  }
                  extraout_ECX[0xc5] = *(int *)(extraout_ECX[0x3c] + *(int *)(unaff_EBP + 8) * 4);
                }
                goto LAB_0051c525;
              }
              iVar7 = extraout_ECX[0x3d];
              uVar14 = uVar14 + 1;
              iVar13 = extraout_ECX[0x3c];
              *(uint *)(unaff_EBP + 8) = uVar14;
            } while (uVar14 < (uint)(iVar7 - iVar13 >> 2));
          }
          uVar4 = (**(code **)(*extraout_ECX + 300))(1,*(int *)(unaff_EBP + 0xc));
          goto LAB_0051c527;
        }
        if ((iVar5 == 0x1b) && (uVar14 = 0, extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2 != 0)) {
          do {
            if (*(int *)(unaff_EBP + 0xc) == *(int *)(extraout_ECX[0x3c] + uVar14 * 4)) {
              uVar4 = FUN_004e9918(uVar14);
              uVar4 = FUN_004e9744(uVar4);
              FUN_0051c538(uVar4);
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < (uint)(extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2));
        }
        goto LAB_0051c525;
      }
      iVar5 = *(int *)(unaff_EBP + 0xc);
      if (iVar5 == 9) {
        cVar1 = (**(code **)(*(int *)extraout_ECX[0x38] + 500))();
        if (cVar1 == '\0') {
          cVar1 = (**(code **)(*(int *)extraout_ECX[0x37] + 500))();
          if (cVar1 == '\0') goto LAB_0051c525;
          piVar10 = (int *)extraout_ECX[0x37];
        }
        else {
          piVar10 = (int *)extraout_ECX[0x38];
        }
        iVar5 = *piVar10;
        uVar4 = 0xfffffffd;
      }
      else {
        if (iVar5 == 0x1b) goto LAB_0051bb60;
        if (iVar5 != 0x20) {
          if ((iVar5 == 0x5a) || (iVar5 == 0x7a)) {
            FUN_0040766a(0xd8,0);
          }
          goto LAB_0051c525;
        }
        FUN_00445541();
        cVar1 = (**(code **)(*(int *)extraout_ECX[0x38] + 500))();
        if (cVar1 == '\0') {
          cVar1 = (**(code **)(*(int *)extraout_ECX[0x37] + 500))();
          if (cVar1 == '\0') goto LAB_0051c525;
          piVar10 = (int *)extraout_ECX[0x37];
        }
        else {
          piVar10 = (int *)extraout_ECX[0x38];
        }
        iVar5 = *piVar10;
        uVar4 = 0xfffffffe;
      }
    }
    (**(code **)(iVar5 + 0x268))(uVar4);
  }
LAB_0051c525:
  uVar4 = 1;
LAB_0051c527:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

