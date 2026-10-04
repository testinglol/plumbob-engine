
undefined4 FUN_00546fd4(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *_Str;
  int *extraout_ECX;
  uint uVar8;
  int unaff_EBP;
  int *piVar9;
  undefined *puVar10;
  int iStack_96c;
  
  FUN_00634c24();
  iVar6 = *(int *)(unaff_EBP + 8);
  if (iVar6 == 1) {
    iVar6 = *(int *)(unaff_EBP + 0xc);
    if (iVar6 == extraout_ECX[0x56]) {
      if ((char)extraout_ECX[0x4a] == '\0') {
        if (0 < extraout_ECX[0x49]) {
          iStack_96c = 0x5470bc;
          wsprintfA((LPSTR)(unaff_EBP + -0x158),(LPCSTR)extraout_ECX[0x66]);
          iStack_96c = unaff_EBP + -0x158;
          iVar6 = FUN_004f6994();
          if (iVar6 != 4) {
            FUN_005e4b90();
            goto LAB_005476b0;
          }
        }
        iVar6 = extraout_ECX[0x45];
        if (iVar6 != 0) {
          iVar6 = (*(int *)(iVar6 + 0xe8) - *(int *)(iVar6 + 0xe4)) + -1;
          if (iVar6 < 1) {
            *(undefined1 *)(unaff_EBP + -0x95c) = 0;
          }
          else {
            if (0x801 < iVar6) {
              iVar6 = 0x801;
            }
            iStack_96c = 0x54711e;
            FUN_00636510();
            *(undefined1 *)(unaff_EBP + -0x95c + iVar6) = 0;
          }
          FUN_005b870f();
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_004e9a99();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        iVar6 = (*(int *)(extraout_ECX[0x46] + 0xe8) - *(int *)(extraout_ECX[0x46] + 0xe4)) + -1;
        if (iVar6 < 1) {
          *(undefined1 *)(unaff_EBP + -0x95c) = 0;
        }
        else {
          iStack_96c = 0x547184;
          FUN_00636510();
          *(undefined1 *)(unaff_EBP + -0x95c + iVar6) = 0;
        }
        FUN_005b870f();
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_004e9b56();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        iVar6 = extraout_ECX[0x59];
        *(undefined4 *)(unaff_EBP + 8) = 0;
        if (iVar6 - extraout_ECX[0x58] >> 2 != 0) {
          do {
            sVar4 = FUN_00563107();
            iVar7 = FUN_004ea79e();
            iVar6 = *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
            *(short *)(iVar7 + (&DAT_0066c600)[iVar6] * 2) = sVar4 * 100;
          } while (*(uint *)(unaff_EBP + 8) < (uint)(extraout_ECX[0x59] - extraout_ECX[0x58] >> 2));
        }
        iVar6 = FUN_004eaa44();
        if (iVar6 == 0) {
          FUN_004eadc1();
        }
        iStack_96c = extraout_ECX[0x47];
        FUN_004ea674();
        *(undefined1 *)(extraout_ECX + 0x4a) = 1;
        if (((char)extraout_ECX[0x48] != '\0') &&
           (puVar2 = (undefined4 *)extraout_ECX[0x5b], puVar2 != (undefined4 *)0x0)) {
          iVar6 = extraout_ECX[0x47];
          *(undefined4 *)(unaff_EBP + -0x4c) = 3;
          *(undefined4 *)(unaff_EBP + -0x48) = 0x1f;
          *(int *)(unaff_EBP + -0x44) = iVar6;
          cVar3 = FUN_005da398();
          if (cVar3 != '\0') {
            (**(code **)*puVar2)();
          }
        }
      }
    }
    else {
      if (iVar6 != extraout_ECX[0x57]) {
        if (iVar6 == extraout_ECX[0x52]) {
          piVar1 = extraout_ECX + 0x5d;
          *piVar1 = *piVar1 + -1;
          piVar9 = extraout_ECX + 0x5d;
          if (*piVar1 < 0) {
            iVar6 = FUN_004eacb7();
LAB_00547326:
            *piVar9 = iVar6 + -1;
          }
        }
        else if (iVar6 == extraout_ECX[0x53]) {
          extraout_ECX[0x5d] = extraout_ECX[0x5d] + 1;
          piVar9 = extraout_ECX + 0x5d;
          iVar6 = FUN_004eacb7();
LAB_00547363:
          if (iVar6 <= *piVar9) {
            *piVar9 = 0;
          }
        }
        else {
          if (iVar6 != extraout_ECX[0x54]) {
            if (iVar6 == extraout_ECX[0x55]) {
              extraout_ECX[0x5c] = extraout_ECX[0x5c] + 1;
              piVar9 = extraout_ECX + 0x5c;
              iVar6 = FUN_004ead68();
              goto LAB_00547363;
            }
            if (iVar6 == extraout_ECX[0x4b]) {
              FUN_005476c3();
              extraout_ECX[0x60] = 1;
              FUN_005476fc();
LAB_005473d3:
              FUN_004eaa9b();
            }
            else {
              if (iVar6 == extraout_ECX[0x4c]) {
                FUN_005476c3();
                extraout_ECX[0x60] = 0;
                FUN_005476fc();
                goto LAB_005473d3;
              }
              if (iVar6 == extraout_ECX[0x4d]) {
                FUN_005476c3();
                extraout_ECX[0x5e] = 1;
                FUN_005476fc();
LAB_00547447:
                FUN_004eabf6();
              }
              else {
                if (iVar6 == extraout_ECX[0x4e]) {
                  FUN_005476c3();
                  extraout_ECX[0x5e] = 0;
                  FUN_005476fc();
                  goto LAB_00547447;
                }
                if (iVar6 == extraout_ECX[0x4f]) {
                  FUN_005476c3();
                  extraout_ECX[0x5f] = 2;
                  FUN_005476fc();
                  *(int **)(unaff_EBP + 0xc) = &iStack_96c;
                  puVar10 = &DAT_006c1008;
                }
                else if (iVar6 == extraout_ECX[0x50]) {
                  FUN_005476c3();
                  extraout_ECX[0x5f] = 1;
                  FUN_005476fc();
                  *(int **)(unaff_EBP + 0xc) = &iStack_96c;
                  puVar10 = &DAT_006c100c;
                }
                else {
                  if (iVar6 != extraout_ECX[0x51]) {
                    if ((iVar6 != extraout_ECX[0x61]) && (iVar6 == extraout_ECX[0x77])) {
                      FUN_005b86bd();
                      *(undefined4 *)(unaff_EBP + -4) = 2;
                      if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + -0x18)) {
                        uVar8 = 0;
                        FUN_00406466();
                        FUN_00406466();
                        iVar6 = FUN_00484444();
                        if (((short)iVar6 == 0) ||
                           (*(int *)(unaff_EBP + 0xc) = iVar6 + 1, 0xc < (short)(iVar6 + 1))) {
                          *(undefined4 *)(unaff_EBP + 0xc) = 1;
                        }
                        FUN_005d48d9();
                        *(undefined1 *)(unaff_EBP + -4) = 3;
                        FUN_005d48d9();
                        *(undefined1 *)(unaff_EBP + -4) = 4;
                        FUN_005481eb();
                        **(undefined1 **)(unaff_EBP + -0x30) = 0x28;
                        FUN_005481eb();
                        **(undefined1 **)(unaff_EBP + -0x24) = 0x29;
                        FUN_005d499c();
                        _Str = (char *)FUN_00484411();
                        _strlen(_Str);
                        FUN_00412d8a();
                        FUN_00412d8a();
                        (**(code **)(*(int *)extraout_ECX[0x77] + 0x9c))();
                        iStack_96c = 0x547606;
                        (**(code **)(*(int *)extraout_ECX[0x77] + 0x90))();
                        iStack_96c = *(int *)(unaff_EBP + 0xc);
                        uVar5 = FUN_004ea79e(extraout_ECX[0x47]);
                        FUN_004843bd(uVar5);
                        extraout_ECX[0x49] = 0x19;
                        if (extraout_ECX[0x59] - extraout_ECX[0x58] >> 2 != 0) {
                          do {
                            iStack_96c = extraout_ECX[0x47];
                            iVar6 = FUN_004ea79e();
                            iStack_96c = (int)*(short *)(iVar6 + (&DAT_0066c600)[uVar8] * 2) / 100;
                            FUN_005630c6();
                            iStack_96c = 0x547672;
                            iVar6 = FUN_00563107();
                            extraout_ECX[0x49] = extraout_ECX[0x49] - iVar6;
                            uVar8 = uVar8 + 1;
                          } while (uVar8 < (uint)(extraout_ECX[0x59] - extraout_ECX[0x58] >> 2));
                        }
                        *(undefined1 *)(unaff_EBP + -4) = 3;
                        iStack_96c = 0x547698;
                        FUN_005b8770();
                        *(undefined1 *)(unaff_EBP + -4) = 2;
                        iStack_96c = 0x5476a4;
                        FUN_005b8770();
                      }
                      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                      FUN_005b8770();
                    }
                    goto LAB_005476b0;
                  }
                  FUN_005476c3();
                  extraout_ECX[0x5f] = 0;
                  FUN_005476fc();
                  *(int **)(unaff_EBP + 0xc) = &iStack_96c;
                  puVar10 = &DAT_006c1010;
                }
                FUN_0040bfed(puVar10);
                FUN_004eac8c(extraout_ECX[0x47]);
              }
            }
            *(undefined1 *)(extraout_ECX + 0x79) = 1;
            goto LAB_0054706a;
          }
          piVar1 = extraout_ECX + 0x5c;
          *piVar1 = *piVar1 + -1;
          piVar9 = extraout_ECX + 0x5c;
          if (*piVar1 < 0) {
            iVar6 = FUN_004ead68();
            goto LAB_00547326;
          }
        }
        *(undefined1 *)(extraout_ECX + 0x79) = 1;
        FUN_00547754();
        FUN_0054800e();
        goto LAB_005476b0;
      }
      if ((char)extraout_ECX[0x4a] == '\0') {
        iStack_96c = extraout_ECX[0x47];
        FUN_004ea674();
        *(undefined1 *)(extraout_ECX + 0x4a) = 1;
        if ((char)extraout_ECX[0x48] != '\0') {
          FUN_004e1e40();
        }
      }
    }
LAB_00547005:
    uVar5 = FUN_005e9006();
  }
  else {
    if (iVar6 == 0x16) {
      if (*(int *)(unaff_EBP + 0xc) == extraout_ECX[0x45]) {
LAB_0054706a:
        FUN_00547754();
      }
    }
    else if (iVar6 == 0x18) {
      (**(code **)(*extraout_ECX + 300))();
    }
    else {
      if (iVar6 != 0x19) goto LAB_00547005;
      iVar6 = extraout_ECX[0x45];
      if (*(int *)(unaff_EBP + 0xc) == iVar6) {
        iVar6 = extraout_ECX[0x46];
      }
      else if (*(int *)(unaff_EBP + 0xc) != extraout_ECX[0x46]) goto LAB_005476b0;
      if (iVar6 != 0) {
        FUN_00436e16();
      }
    }
LAB_005476b0:
    uVar5 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

