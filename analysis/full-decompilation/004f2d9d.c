
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined1 FUN_004f2d9d(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined1 *puVar6;
  LPCSTR pCVar7;
  LPCSTR pCVar8;
  BOOL BVar9;
  undefined4 extraout_ECX;
  int unaff_EBP;
  char *pcVar10;
  UINT UVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x2f4) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x34) = DAT_006fe8bc;
  uVar4 = (**(code **)(**(int **)(unaff_EBP + -0x34) + 0x34))();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  pvVar5 = operator_new(0x6c);
  *(void **)(unaff_EBP + -0x10c) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x10c) == 0) {
    *(undefined4 *)(unaff_EBP + -0x2f8) = 0;
  }
  else {
    uVar4 = FUN_00413b0e();
    *(undefined4 *)(unaff_EBP + -0x2f8) = uVar4;
  }
  *(undefined4 *)(unaff_EBP + -0x108) = *(undefined4 *)(unaff_EBP + -0x2f8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  DAT_006e486c = *(int *)(unaff_EBP + -0x108);
  if (DAT_006e486c == 0) {
    uVar2 = 0;
  }
  else {
    cVar1 = FUN_005d6516(s_nostacktrace_006cafd8,0,1);
    if (cVar1 == '\0') {
      FUN_004d6339();
    }
    FUN_005b8e25();
    uVar2 = FUN_004d5360();
    *(undefined1 *)(unaff_EBP + -0x4c) = uVar2;
    if (*(char *)(unaff_EBP + -0x4c) != '\0') {
      uVar12 = 1;
      uVar4 = 1;
      pcVar10 = s___UIGraphics__006cafc8;
      FUN_005b8e25(s___UIGraphics__006cafc8,1,1);
      FUN_005b92ee(pcVar10,uVar4,uVar12);
    }
    *(undefined1 *)(unaff_EBP + -0x28) = 0;
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    cVar1 = FUN_004fc152(s_SIMS_OTHERLANGUAGE_006cafb4,unaff_EBP + -0x40);
    if ((cVar1 != '\0') ||
       (cVar1 = FUN_004fc152(s_SIMS_LANGUAGE_006cafa4,unaff_EBP + -0x40), cVar1 != '\0')) {
      cVar1 = FUN_00460748(unaff_EBP + -0x40,s_USEnglish_006caf98);
      if (cVar1 == '\0') {
        cVar1 = FUN_00460748(unaff_EBP + -0x40,s_UKEnglish_006caf8c);
        if (cVar1 == '\0') {
          cVar1 = FUN_00460748(unaff_EBP + -0x40,s_French_006caf84);
          if (cVar1 == '\0') {
            cVar1 = FUN_00460748(unaff_EBP + -0x40,s_German_006caf7c);
            if (cVar1 == '\0') {
              cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Italian_006caf74);
              if (cVar1 == '\0') {
                cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Spanish_006caf6c);
                if (cVar1 == '\0') {
                  cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Dutch_006caf64);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Danish_006caf5c);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Swedish_006caf54);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Norwegian_006caf48);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Finnish_006caf40);
                          if (cVar1 == '\0') {
                            cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Portuguese_006caf34);
                            if (cVar1 == '\0') {
                              cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Japanese_006caf28);
                              if (cVar1 == '\0') {
                                cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Polish_006caf20);
                                if (cVar1 == '\0') {
                                  cVar1 = FUN_00460748(unaff_EBP + -0x40,
                                                       s_TraditionalChinese_006caf0c);
                                  if (cVar1 == '\0') {
                                    cVar1 = FUN_00460748(unaff_EBP + -0x40,
                                                         s_SimplifiedChinese_006caef8);
                                    if (cVar1 == '\0') {
                                      cVar1 = FUN_00460748(unaff_EBP + -0x40,&DAT_006caef0);
                                      if (cVar1 == '\0') {
                                        cVar1 = FUN_00460748(unaff_EBP + -0x40,s_Korean_006caee8);
                                        if (cVar1 != '\0') {
                                          *(undefined1 *)(DAT_006e486c + 100) = 0x14;
                                          *(undefined1 *)(unaff_EBP + -0x28) = 1;
                                        }
                                      }
                                      else {
                                        *(undefined1 *)(DAT_006e486c + 100) = 0x13;
                                        *(undefined1 *)(unaff_EBP + -0x28) = 1;
                                      }
                                    }
                                    else {
                                      *(undefined1 *)(DAT_006e486c + 100) = 0x11;
                                      *(undefined1 *)(unaff_EBP + -0x28) = 1;
                                    }
                                  }
                                  else {
                                    *(undefined1 *)(DAT_006e486c + 100) = 0x12;
                                    *(undefined1 *)(unaff_EBP + -0x28) = 1;
                                  }
                                }
                                else {
                                  *(undefined1 *)(DAT_006e486c + 100) = 0x10;
                                  *(undefined1 *)(unaff_EBP + -0x28) = 1;
                                }
                              }
                              else {
                                *(undefined1 *)(DAT_006e486c + 100) = 0xf;
                                *(undefined1 *)(unaff_EBP + -0x28) = 1;
                              }
                            }
                            else {
                              *(undefined1 *)(DAT_006e486c + 100) = 0xe;
                              *(undefined1 *)(unaff_EBP + -0x28) = 1;
                            }
                          }
                          else {
                            *(undefined1 *)(DAT_006e486c + 100) = 0xb;
                            *(undefined1 *)(unaff_EBP + -0x28) = 1;
                          }
                        }
                        else {
                          *(undefined1 *)(DAT_006e486c + 100) = 10;
                          *(undefined1 *)(unaff_EBP + -0x28) = 1;
                        }
                      }
                      else {
                        *(undefined1 *)(DAT_006e486c + 100) = 9;
                        *(undefined1 *)(unaff_EBP + -0x28) = 1;
                      }
                    }
                    else {
                      *(undefined1 *)(DAT_006e486c + 100) = 8;
                      *(undefined1 *)(unaff_EBP + -0x28) = 1;
                    }
                  }
                  else {
                    *(undefined1 *)(DAT_006e486c + 100) = 7;
                    *(undefined1 *)(unaff_EBP + -0x28) = 1;
                  }
                }
                else {
                  *(undefined1 *)(DAT_006e486c + 100) = 6;
                  *(undefined1 *)(unaff_EBP + -0x28) = 1;
                }
              }
              else {
                *(undefined1 *)(DAT_006e486c + 100) = 5;
                *(undefined1 *)(unaff_EBP + -0x28) = 1;
              }
            }
            else {
              *(undefined1 *)(DAT_006e486c + 100) = 4;
              *(undefined1 *)(unaff_EBP + -0x28) = 1;
            }
          }
          else {
            *(undefined1 *)(DAT_006e486c + 100) = 3;
            *(undefined1 *)(unaff_EBP + -0x28) = 1;
          }
        }
        else {
          *(undefined1 *)(DAT_006e486c + 100) = 2;
          *(undefined1 *)(unaff_EBP + -0x28) = 1;
        }
      }
      else {
        *(undefined1 *)(DAT_006e486c + 100) = 1;
        *(undefined1 *)(unaff_EBP + -0x28) = 1;
      }
    }
    cVar1 = FUN_005d6516(s_lUKEnglish_006caedc,0,1);
    if (cVar1 == '\0') {
      cVar1 = FUN_005d6516(s_lFrench_006caed4,0,1);
      if (cVar1 == '\0') {
        cVar1 = FUN_005d6516(s_lGerman_006caecc,0,1);
        if (cVar1 == '\0') {
          cVar1 = FUN_005d6516(s_lItalian_006caec0,0,1);
          if (cVar1 == '\0') {
            cVar1 = FUN_005d6516(s_lSpanish_006caeb4,0,1);
            if (cVar1 == '\0') {
              cVar1 = FUN_005d6516(s_lDutch_006caeac,0,1);
              if (cVar1 == '\0') {
                cVar1 = FUN_005d6516(s_lDanish_006caea4,0,1);
                if (cVar1 == '\0') {
                  cVar1 = FUN_005d6516(s_lSwedish_006cae98,0,1);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_005d6516(s_lNorwegian_006cae8c,0,1);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_005d6516(s_lFinnish_006cae80,0,1);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_005d6516(s_lHebrew_006cae78,0,1);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_005d6516(s_lRussian_006cae6c,0,1);
                          if (cVar1 == '\0') {
                            cVar1 = FUN_005d6516(s_lPortuguese_006cae60,0,1);
                            if (cVar1 == '\0') {
                              cVar1 = FUN_005d6516(s_lJapanese_006cae54,0,1);
                              if (cVar1 == '\0') {
                                cVar1 = FUN_005d6516(s_lPolish_006cae4c,0,1);
                                if (cVar1 == '\0') {
                                  cVar1 = FUN_005d6516(s_lSimplifiedChinese_006cae38,0,1);
                                  if (cVar1 == '\0') {
                                    cVar1 = FUN_005d6516(s_lTraditionalChinese_006cae24,0,1);
                                    if (cVar1 == '\0') {
                                      cVar1 = FUN_005d6516(s_lThai_006cae1c,0,1);
                                      if (cVar1 == '\0') {
                                        cVar1 = FUN_005d6516(s_lKorean_006cae14,0,1);
                                        if (cVar1 == '\0') {
                                          cVar1 = FUN_005d6516(s_lUSEnglish_006cae08,0,1);
                                          if (cVar1 == '\0') {
                                            if (*(char *)(unaff_EBP + -0x28) == '\0') {
                                              *(undefined1 *)(DAT_006e486c + 100) = 1;
                                            }
                                          }
                                          else {
                                            *(undefined1 *)(DAT_006e486c + 100) = 1;
                                          }
                                        }
                                        else {
                                          *(undefined1 *)(DAT_006e486c + 100) = 0x14;
                                        }
                                      }
                                      else {
                                        *(undefined1 *)(DAT_006e486c + 100) = 0x13;
                                      }
                                    }
                                    else {
                                      *(undefined1 *)(DAT_006e486c + 100) = 0x12;
                                    }
                                  }
                                  else {
                                    *(undefined1 *)(DAT_006e486c + 100) = 0x11;
                                  }
                                }
                                else {
                                  *(undefined1 *)(DAT_006e486c + 100) = 0x10;
                                }
                              }
                              else {
                                *(undefined1 *)(DAT_006e486c + 100) = 0xf;
                              }
                            }
                            else {
                              *(undefined1 *)(DAT_006e486c + 100) = 0xe;
                            }
                          }
                          else {
                            *(undefined1 *)(DAT_006e486c + 100) = 0xd;
                          }
                        }
                        else {
                          *(undefined1 *)(DAT_006e486c + 100) = 0xc;
                        }
                      }
                      else {
                        *(undefined1 *)(DAT_006e486c + 100) = 0xb;
                      }
                    }
                    else {
                      *(undefined1 *)(DAT_006e486c + 100) = 10;
                    }
                  }
                  else {
                    *(undefined1 *)(DAT_006e486c + 100) = 9;
                  }
                }
                else {
                  *(undefined1 *)(DAT_006e486c + 100) = 8;
                }
              }
              else {
                *(undefined1 *)(DAT_006e486c + 100) = 7;
              }
            }
            else {
              *(undefined1 *)(DAT_006e486c + 100) = 6;
            }
          }
          else {
            *(undefined1 *)(DAT_006e486c + 100) = 5;
          }
        }
        else {
          *(undefined1 *)(DAT_006e486c + 100) = 4;
        }
      }
      else {
        *(undefined1 *)(DAT_006e486c + 100) = 3;
      }
    }
    else {
      *(undefined1 *)(DAT_006e486c + 100) = 2;
    }
    cVar1 = FUN_004fc152(s_SIMS_SKU_006cadfc,unaff_EBP + -0x40);
    if (cVar1 == '\0') {
      *(undefined1 *)(unaff_EBP + -700) = *(undefined1 *)(DAT_006e486c + 100);
      if ((*(char *)(unaff_EBP + -700) != '\x01') &&
         (*(undefined1 *)(unaff_EBP + -0x2c0) = *(undefined1 *)(DAT_006e486c + 100),
         *(char *)(unaff_EBP + -0x2c0) != '\x11')) {
        *(undefined1 *)(DAT_006e486c + 100) = 0x11;
      }
    }
    else {
      cVar1 = FUN_00460748(unaff_EBP + -0x40,&DAT_006c1038);
      if (((cVar1 != '\0') &&
          (*(undefined1 *)(unaff_EBP + -0x2b4) = *(undefined1 *)(DAT_006e486c + 100),
          *(char *)(unaff_EBP + -0x2b4) != '\x01')) &&
         (*(undefined1 *)(unaff_EBP + -0x2b8) = *(undefined1 *)(DAT_006e486c + 100),
         *(char *)(unaff_EBP + -0x2b8) != '\x11')) {
        *(undefined1 *)(DAT_006e486c + 100) = 0x11;
      }
    }
    *(undefined1 *)(unaff_EBP + -0x2c4) = *(undefined1 *)(DAT_006e486c + 100);
    *(undefined4 *)(unaff_EBP + -0x2fc) = DAT_006fe8bc;
    uVar4 = (**(code **)(**(int **)(unaff_EBP + -0x2fc) + 4))((int)*(char *)(unaff_EBP + -0x2c4));
    *(undefined4 *)(unaff_EBP + -0x300) = uVar4;
    (**(code **)(**(int **)(unaff_EBP + -0x300) + 0x10))();
    *(undefined1 *)(unaff_EBP + -0x2c8) = *(undefined1 *)(DAT_006e486c + 100);
    *(undefined4 *)(unaff_EBP + -0x304) = DAT_006fe8bc;
    uVar4 = (**(code **)(**(int **)(unaff_EBP + -0x304) + 4))((int)*(char *)(unaff_EBP + -0x2c8));
    *(undefined4 *)(unaff_EBP + -0x308) = uVar4;
    (**(code **)(**(int **)(unaff_EBP + -0x308) + 0x20))();
    pvVar5 = operator_new(0x6c);
    *(void **)(unaff_EBP + -0x114) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (*(int *)(unaff_EBP + -0x114) == 0) {
      *(undefined4 *)(unaff_EBP + -0x30c) = 0;
    }
    else {
      FUN_0046fca5();
      **(undefined4 **)(unaff_EBP + -0x114) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -0x30c) = *(undefined4 *)(unaff_EBP + -0x114);
    }
    *(undefined4 *)(unaff_EBP + -0x110) = *(undefined4 *)(unaff_EBP + -0x30c);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x110);
    uVar4 = FUN_0041532c(9,*(undefined4 *)(unaff_EBP + -0x54),0);
    cVar1 = FUN_004fff98(0x98,uVar4);
    if (cVar1 != '\0') {
      uVar4 = FUN_004705f2(1,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005e50d8(3,unaff_EBP + -0x120);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      uVar4 = FUN_004705f2(1,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_00526ed5(2,unaff_EBP + -300);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      uVar4 = FUN_004705f2(2,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005e50d8(1,unaff_EBP + -0x138);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      uVar4 = FUN_004705f2(2,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_00526ed5(1,unaff_EBP + -0x144);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      uVar4 = FUN_004705f2(3,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005e50d8(4,unaff_EBP + -0x150);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      uVar4 = FUN_004705f2(4,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005e50d8(2,unaff_EBP + -0x15c);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
    }
    uVar4 = FUN_0041532c(9,*(undefined4 *)(unaff_EBP + -0x54),0);
    cVar1 = FUN_004fff98(0xa1,uVar4);
    if (cVar1 != '\0') {
      puVar6 = (undefined1 *)FUN_004705f2(7,0xffffffff);
      FUN_005e5135(4,*puVar6);
      puVar6 = (undefined1 *)FUN_004705f2(8,0xffffffff);
      FUN_005e5135(2,*puVar6);
      *(undefined1 *)(unaff_EBP + -0x2cc) = *(undefined1 *)(DAT_006e486c + 100);
      *(undefined1 *)(unaff_EBP + -0x310) = *(undefined1 *)(unaff_EBP + -0x2cc);
      if ((*(char *)(unaff_EBP + -0x310) == '\x0f') ||
         (('\x10' < *(char *)(unaff_EBP + -0x310) && (*(char *)(unaff_EBP + -0x310) < '\x15')))) {
        pcVar10 = (char *)FUN_004705f2(0x15,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[0] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x16,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[1] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x17,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[2] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x18,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[3] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x19,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[4] = *pcVar10;
      }
      else {
        pcVar10 = (char *)FUN_004705f2(0x15,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[0] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x16,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[1] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x17,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[2] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x18,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[3] = *pcVar10;
        pcVar10 = (char *)FUN_004705f2(0x19,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[4] = *pcVar10;
      }
      pcVar10 = (char *)FUN_004705f2(0x1d,0xffffffff);
      if (*pcVar10 != '\0') {
        pcVar10 = (char *)FUN_004705f2(0x1d,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[5] = *pcVar10;
      }
      pcVar10 = (char *)FUN_004705f2(0x1e,0xffffffff);
      if (*pcVar10 != '\0') {
        pcVar10 = (char *)FUN_004705f2(0x1e,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[6] = *pcVar10;
      }
      pcVar10 = (char *)FUN_004705f2(0x1f,0xffffffff);
      if (*pcVar10 != '\0') {
        pcVar10 = (char *)FUN_004705f2(0x1f,0xffffffff);
        s_XCVZYAQScaught_exception_in_chil_006d7448[7] = *pcVar10;
      }
    }
    pvVar5 = operator_new(0x6c);
    *(void **)(unaff_EBP + -0x164) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    if (*(int *)(unaff_EBP + -0x164) == 0) {
      *(undefined4 *)(unaff_EBP + -0x314) = 0;
    }
    else {
      FUN_0046fca5();
      **(undefined4 **)(unaff_EBP + -0x164) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -0x314) = *(undefined4 *)(unaff_EBP + -0x164);
    }
    *(undefined4 *)(unaff_EBP + -0x160) = *(undefined4 *)(unaff_EBP + -0x314);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x160);
    uVar4 = FUN_0041532c(9,*(undefined4 *)(unaff_EBP + -0x50),0);
    cVar1 = FUN_004fff98(0x99,uVar4);
    if (cVar1 != '\0') {
      uVar4 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(2,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(3,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(4,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(5,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(6,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(7,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(8,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(9,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(10,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xb,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xc,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xd,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xe,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xf,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x10,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x11,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x12,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x13,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x14,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x15,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x16,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x17,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0x18,0xffffffff);
      FUN_005d4bbf(uVar4);
    }
    uVar4 = FUN_0041532c(9,*(undefined4 *)(unaff_EBP + -0x50),0);
    cVar1 = FUN_004fff98(0x9d,uVar4);
    if (cVar1 != '\0') {
      uVar4 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(2,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(3,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(4,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(5,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(6,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(7,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(8,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(9,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(10,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xb,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xc,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xd,0xffffffff);
      FUN_005d4bbf(uVar4);
      uVar4 = FUN_004705f2(0xe,0xffffffff);
      FUN_005d4bbf(uVar4);
    }
    *(undefined4 *)(unaff_EBP + -0x16c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0x168) = *(undefined4 *)(unaff_EBP + -0x16c);
    if (*(int *)(unaff_EBP + -0x168) == 0) {
      *(undefined4 *)(unaff_EBP + -0x318) = 0;
    }
    else {
      uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x168))(1);
      *(undefined4 *)(unaff_EBP + -0x318) = uVar4;
    }
    *(undefined4 *)(unaff_EBP + -0x174) = *(undefined4 *)(unaff_EBP + -0x50);
    *(undefined4 *)(unaff_EBP + -0x170) = *(undefined4 *)(unaff_EBP + -0x174);
    if (*(int *)(unaff_EBP + -0x170) == 0) {
      *(undefined4 *)(unaff_EBP + -0x31c) = 0;
    }
    else {
      uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x170))(1);
      *(undefined4 *)(unaff_EBP + -0x31c) = uVar4;
    }
    pvVar5 = operator_new(0x6c);
    *(void **)(unaff_EBP + -0x17c) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (*(int *)(unaff_EBP + -0x17c) == 0) {
      *(undefined4 *)(unaff_EBP + -800) = 0;
    }
    else {
      FUN_0046fca5();
      **(undefined4 **)(unaff_EBP + -0x17c) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -800) = *(undefined4 *)(unaff_EBP + -0x17c);
    }
    *(undefined4 *)(unaff_EBP + -0x178) = *(undefined4 *)(unaff_EBP + -800);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x178);
    cVar1 = FUN_004fff98(1,s_Ranger7_iff_006cadf0,*(undefined4 *)(unaff_EBP + -0x48),0);
    if (cVar1 == '\0') {
      *(undefined4 *)(unaff_EBP + -0x184) = *(undefined4 *)(unaff_EBP + -0x48);
      *(undefined4 *)(unaff_EBP + -0x180) = *(undefined4 *)(unaff_EBP + -0x184);
      if (*(int *)(unaff_EBP + -0x180) == 0) {
        *(undefined4 *)(unaff_EBP + -0x324) = 0;
      }
      else {
        uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x180))(1);
        *(undefined4 *)(unaff_EBP + -0x324) = uVar4;
      }
      *(undefined1 *)(unaff_EBP + -0x188) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar2 = *(undefined1 *)(unaff_EBP + -0x188);
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x24) = 1;
      if (*(char *)(unaff_EBP + -0x24) != '\0') {
        *(undefined2 *)(unaff_EBP + -0x60) = 0;
        pvVar5 = operator_new(0x6c);
        *(void **)(unaff_EBP + -400) = pvVar5;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        if (*(int *)(unaff_EBP + -400) == 0) {
          *(undefined4 *)(unaff_EBP + -0x328) = 0;
        }
        else {
          FUN_0046fca5();
          **(undefined4 **)(unaff_EBP + -400) = &PTR_FUN_0066643c;
          *(undefined4 *)(unaff_EBP + -0x328) = *(undefined4 *)(unaff_EBP + -400);
        }
        *(undefined4 *)(unaff_EBP + -0x18c) = *(undefined4 *)(unaff_EBP + -0x328);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x18c);
        *(undefined1 *)(unaff_EBP + -0x5c) = 0;
        cVar1 = FUN_0050019c(1,s_Ranger_iff_006c16b0,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 1;
        }
        cVar1 = FUN_0050019c(1,s_Ranger2_iff_006c167c,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 2;
        }
        cVar1 = FUN_0050019c(1,s_Ranger3_iff_006c164c,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 4;
        }
        cVar1 = FUN_0050019c(1,s_Ranger4_iff_006c161c,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 8;
        }
        cVar1 = FUN_0050019c(1,s_RangerD_iff_006c1610,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 0x10;
        }
        cVar1 = FUN_0050019c(1,s_Ranger5_iff_006c15e0,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 0x20;
        }
        cVar1 = FUN_0050019c(1,s_Ranger6_iff_006c15d4,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 0x40;
        }
        cVar1 = FUN_0050019c(1,s_Ranger7_iff_006cadf0,*(undefined4 *)(unaff_EBP + -0x58),0);
        if (cVar1 != '\0') {
          *(ushort *)(unaff_EBP + -0x60) = *(ushort *)(unaff_EBP + -0x60) | 0x80;
        }
        if (0xff < *(short *)(unaff_EBP + -0x60)) {
          MessageBoxA((HWND)0x0,s_A_newer_version_of_the_Sims_has_b_006cad80,s_Error__006cade8,0);
          *(undefined4 *)(unaff_EBP + -0x198) = *(undefined4 *)(unaff_EBP + -0x48);
          *(undefined4 *)(unaff_EBP + -0x194) = *(undefined4 *)(unaff_EBP + -0x198);
          if (*(int *)(unaff_EBP + -0x194) == 0) {
            *(undefined4 *)(unaff_EBP + -0x32c) = 0;
          }
          else {
            uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x194))(1);
            *(undefined4 *)(unaff_EBP + -0x32c) = uVar4;
          }
          *(undefined4 *)(unaff_EBP + -0x1a0) = *(undefined4 *)(unaff_EBP + -0x58);
          *(undefined4 *)(unaff_EBP + -0x19c) = *(undefined4 *)(unaff_EBP + -0x1a0);
          if (*(int *)(unaff_EBP + -0x19c) == 0) {
            *(undefined4 *)(unaff_EBP + -0x330) = 0;
          }
          else {
            uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x19c))(1);
            *(undefined4 *)(unaff_EBP + -0x330) = uVar4;
          }
          *(undefined1 *)(unaff_EBP + -0x1a4) = 0;
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          uVar2 = *(undefined1 *)(unaff_EBP + -0x1a4);
          goto LAB_004f4a10;
        }
        cVar1 = FUN_004fc152(s_SIMS_GAME_EDITION_006c15b0,unaff_EBP + -0x40);
        if (cVar1 == '\0') {
          if (*(short *)(unaff_EBP + -0x60) != 8) {
            *(undefined1 *)(unaff_EBP + -0x5c) = 1;
          }
        }
        else {
          uVar4 = FUN_004096c2();
          uVar3 = FUN_00635f62(uVar4);
          *(undefined2 *)(unaff_EBP + -100) = uVar3;
          if (*(short *)(unaff_EBP + -100) != *(short *)(unaff_EBP + -0x60)) {
            *(undefined1 *)(unaff_EBP + -0x5c) = 1;
          }
        }
        if (*(char *)(unaff_EBP + -0x5c) != '\0') {
          pvVar5 = operator_new(0x6c);
          *(void **)(unaff_EBP + -0x1ac) = pvVar5;
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          if (*(int *)(unaff_EBP + -0x1ac) == 0) {
            *(undefined4 *)(unaff_EBP + -0x334) = 0;
          }
          else {
            FUN_0046fca5();
            **(undefined4 **)(unaff_EBP + -0x1ac) = &PTR_FUN_0066643c;
            *(undefined4 *)(unaff_EBP + -0x334) = *(undefined4 *)(unaff_EBP + -0x1ac);
          }
          *(undefined4 *)(unaff_EBP + -0x1a8) = *(undefined4 *)(unaff_EBP + -0x334);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x1a8);
          cVar1 = FUN_004fff98(1,s_Ranger7_iff_006cadf0,*(undefined4 *)(unaff_EBP + -0x68),0);
          if (cVar1 != '\0') {
            UVar11 = 0;
            pCVar7 = (LPCSTR)FUN_004705f2(3,0xffffffff);
            pCVar8 = (LPCSTR)FUN_004705f2(2,0xffffffff);
            MessageBoxA((HWND)0x0,pCVar8,pCVar7,UVar11);
            *(undefined1 *)(unaff_EBP + -0xd8) = 0;
            FUN_005d48d9();
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_005d4956(s_setup_exe_006cad74);
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            while (*(char *)(unaff_EBP + -0xd8) == '\0') {
              *(undefined1 *)(unaff_EBP + -0xdc) = 0x44;
              while (*(char *)(unaff_EBP + -0xdc) < '[') {
                FUN_005d5156(unaff_EBP + -200,s__c__setup__006cad68,
                             (int)*(char *)(unaff_EBP + -0xdc));
                uVar4 = FUN_00412a04(unaff_EBP + -0x1b8,unaff_EBP + -200,s_SETUP_INI_006cad5c);
                *(undefined4 *)(unaff_EBP + -0x338) = uVar4;
                *(undefined4 *)(unaff_EBP + -0x33c) = *(undefined4 *)(unaff_EBP + -0x338);
                *(undefined1 *)(unaff_EBP + -4) = 0xf;
                FUN_005b86bd(*(undefined4 *)(unaff_EBP + -0x33c));
                *(undefined1 *)(unaff_EBP + -4) = 0x11;
                FUN_00401729();
                uVar4 = FUN_004096c2();
                FUN_005b8e25(uVar4);
                cVar1 = FUN_005b9a53(uVar4);
                if (cVar1 != '\0') {
                  FUN_005b86bd(unaff_EBP + -0xe8);
                  *(undefined ***)(unaff_EBP + -0xf8) = &PTR_FUN_006698c8;
                  *(undefined1 *)(unaff_EBP + -4) = 0x12;
                  FUN_005d48d9();
                  *(undefined1 *)(unaff_EBP + -4) = 0x13;
                  FUN_005d4956(s_AppName_006cad54);
                  *(undefined1 *)(unaff_EBP + -4) = 0x14;
                  FUN_005d4956(s_Startup_006cad4c);
                  *(undefined1 *)(unaff_EBP + -4) = 0x15;
                  cVar1 = FUN_005f0b6c(unaff_EBP + -0x1d4,unaff_EBP + -0x1c8,unaff_EBP + -0x104);
                  *(char *)(unaff_EBP + -0x1bc) = '\x01' - (cVar1 != '\x01');
                  *(undefined1 *)(unaff_EBP + -4) = 0x14;
                  FUN_005b8770();
                  *(undefined1 *)(unaff_EBP + -4) = 0x13;
                  FUN_005b8770();
                  if ((*(char *)(unaff_EBP + -0x1bc) != '\0') &&
                     (cVar1 = FUN_00460748(unaff_EBP + -0x104,s_The_Sims_Makin__Magic_006cad34),
                     cVar1 != '\0')) {
                    *(undefined1 *)(unaff_EBP + -0xd8) = 1;
                    *(undefined1 *)(unaff_EBP + -0xb0) = *(undefined1 *)(unaff_EBP + -0xdc);
                    *(undefined1 *)(unaff_EBP + -4) = 0x12;
                    FUN_005b8770();
                    *(undefined1 *)(unaff_EBP + -4) = 0x11;
                    *(undefined ***)(unaff_EBP + -0xf8) = &PTR_FUN_006698c8;
                    FUN_005b8770();
                    *(undefined1 *)(unaff_EBP + -4) = 0xe;
                    FUN_005b8770();
                    break;
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0x12;
                  FUN_005b8770();
                  *(undefined1 *)(unaff_EBP + -4) = 0x11;
                  *(undefined ***)(unaff_EBP + -0xf8) = &PTR_FUN_006698c8;
                  FUN_005b8770();
                }
                *(undefined1 *)(unaff_EBP + -4) = 0xe;
                FUN_005b8770();
                *(char *)(unaff_EBP + -0xdc) = *(char *)(unaff_EBP + -0xdc) + '\x01';
              }
              if (*(char *)(unaff_EBP + -0xd8) != '\0') break;
              UVar11 = 0;
              pCVar7 = (LPCSTR)FUN_004705f2(3,0xffffffff);
              pCVar8 = (LPCSTR)FUN_004705f2(4,0xffffffff);
              MessageBoxA((HWND)0x0,pCVar8,pCVar7,UVar11);
            }
            *(undefined1 *)(unaff_EBP + -0x2f0) = *(undefined1 *)(DAT_006e486c + 100);
            *(int *)(unaff_EBP + -0x340) = (int)*(char *)(unaff_EBP + -0x2f0);
            *(int *)(unaff_EBP + -0x340) = *(int *)(unaff_EBP + -0x340) + -1;
            switch(*(undefined4 *)(unaff_EBP + -0x340)) {
            case 0:
              *(undefined4 *)(unaff_EBP + -0xac) = 9;
              break;
            case 1:
              *(undefined4 *)(unaff_EBP + -0xac) = 9;
              break;
            case 2:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x40c;
              break;
            case 3:
              *(undefined4 *)(unaff_EBP + -0xac) = 7;
              break;
            case 4:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x10;
              break;
            case 5:
              *(undefined4 *)(unaff_EBP + -0xac) = 10;
              break;
            case 6:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x13;
              break;
            case 7:
              *(undefined4 *)(unaff_EBP + -0xac) = 6;
              break;
            case 8:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x1d;
              break;
            case 9:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x14;
              break;
            case 10:
              *(undefined4 *)(unaff_EBP + -0xac) = 0xb;
              break;
            default:
              *(undefined4 *)(unaff_EBP + -0xac) = 9;
              break;
            case 0xd:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x416;
              break;
            case 0xe:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x11;
              break;
            case 0xf:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x15;
              break;
            case 0x10:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x804;
              break;
            case 0x11:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x404;
              break;
            case 0x12:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x1e;
              break;
            case 0x13:
              *(undefined4 *)(unaff_EBP + -0xac) = 0x12;
            }
            FUN_005d48d9();
            *(undefined1 *)(unaff_EBP + -4) = 0x16;
            FUN_005d5156(unaff_EBP + -0xd4,s__l_04x_006cad2c,*(undefined4 *)(unaff_EBP + -0xac));
            _memset((void *)(unaff_EBP + -0xa8),0,0x3c);
            *(undefined4 *)(unaff_EBP + -0xa8) = 0x3c;
            *(undefined4 *)(unaff_EBP + -0xa4) = 0;
            *(uint *)(unaff_EBP + -0xa4) = *(uint *)(unaff_EBP + -0xa4) | 0x40;
            *(undefined4 *)(unaff_EBP + -0xa0) = 0;
            uVar4 = FUN_004096c2();
            *(undefined4 *)(unaff_EBP + -0x98) = uVar4;
            uVar4 = FUN_004096c2();
            *(undefined4 *)(unaff_EBP + -0x94) = uVar4;
            uVar4 = FUN_004096c2();
            *(undefined4 *)(unaff_EBP + -0x90) = uVar4;
            *(undefined4 *)(unaff_EBP + -0x8c) = 10;
            BVar9 = ShellExecuteExA((SHELLEXECUTEINFOA *)(unaff_EBP + -0xa8));
            *(BOOL *)(unaff_EBP + -0x6c) = BVar9;
            *(undefined4 *)(unaff_EBP + -0x1dc) = *(undefined4 *)(unaff_EBP + -0x68);
            *(undefined4 *)(unaff_EBP + -0x1d8) = *(undefined4 *)(unaff_EBP + -0x1dc);
            if (*(int *)(unaff_EBP + -0x1d8) == 0) {
              *(undefined4 *)(unaff_EBP + -0x344) = 0;
            }
            else {
              uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x1d8))(1);
              *(undefined4 *)(unaff_EBP + -0x344) = uVar4;
            }
            *(undefined4 *)(unaff_EBP + -0x1e4) = *(undefined4 *)(unaff_EBP + -0x48);
            *(undefined4 *)(unaff_EBP + -0x1e0) = *(undefined4 *)(unaff_EBP + -0x1e4);
            if (*(int *)(unaff_EBP + -0x1e0) == 0) {
              *(undefined4 *)(unaff_EBP + -0x348) = 0;
            }
            else {
              uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x1e0))(1);
              *(undefined4 *)(unaff_EBP + -0x348) = uVar4;
            }
            *(undefined4 *)(unaff_EBP + -0x1ec) = *(undefined4 *)(unaff_EBP + -0x58);
            *(undefined4 *)(unaff_EBP + -0x1e8) = *(undefined4 *)(unaff_EBP + -0x1ec);
            if (*(int *)(unaff_EBP + -0x1e8) == 0) {
              *(undefined4 *)(unaff_EBP + -0x34c) = 0;
            }
            else {
              uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x1e8))(1);
              *(undefined4 *)(unaff_EBP + -0x34c) = uVar4;
            }
            *(undefined1 *)(unaff_EBP + -0x1f0) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_005b8770();
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
            uVar2 = *(undefined1 *)(unaff_EBP + -0x1f0);
            goto LAB_004f4a10;
          }
          *(undefined4 *)(unaff_EBP + -0x1f8) = *(undefined4 *)(unaff_EBP + -0x68);
          *(undefined4 *)(unaff_EBP + -500) = *(undefined4 *)(unaff_EBP + -0x1f8);
          if (*(int *)(unaff_EBP + -500) == 0) {
            *(undefined4 *)(unaff_EBP + -0x350) = 0;
          }
          else {
            uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -500))(1);
            *(undefined4 *)(unaff_EBP + -0x350) = uVar4;
          }
          *(undefined4 *)(unaff_EBP + -0x200) = *(undefined4 *)(unaff_EBP + -0x58);
          *(undefined4 *)(unaff_EBP + -0x1fc) = *(undefined4 *)(unaff_EBP + -0x200);
          if (*(int *)(unaff_EBP + -0x1fc) == 0) {
            *(undefined4 *)(unaff_EBP + -0x354) = 0;
          }
          else {
            uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x1fc))(1);
            *(undefined4 *)(unaff_EBP + -0x354) = uVar4;
          }
        }
        *(undefined4 *)(unaff_EBP + -0x208) = *(undefined4 *)(unaff_EBP + -0x48);
        *(undefined4 *)(unaff_EBP + -0x204) = *(undefined4 *)(unaff_EBP + -0x208);
        if (*(int *)(unaff_EBP + -0x204) == 0) {
          *(undefined4 *)(unaff_EBP + -0x358) = 0;
        }
        else {
          uVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x204))(1);
          *(undefined4 *)(unaff_EBP + -0x358) = uVar4;
        }
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 800;
      *(undefined4 *)(unaff_EBP + -0x20) = 600;
      cVar1 = FUN_005d6516(s_r1024x768_006cad20,0,1);
      if (cVar1 != '\0') {
        *(undefined4 *)(unaff_EBP + -0x10) = 0x400;
        *(undefined4 *)(unaff_EBP + -0x20) = 0x300;
      }
      cVar1 = FUN_005d6516(s_3dhardware_006cad14,0,1);
      DAT_006c9f90 = '\x01' - (cVar1 != '\0');
      cVar1 = FUN_005d6516(&DAT_006c0a78,0,1);
      *(char *)(unaff_EBP + -0x30) = '\x01' - (cVar1 != '\0');
      *(undefined1 *)(unaff_EBP + -0x1c) = 0;
      DAT_006f29f6 = *(byte *)(unaff_EBP + -0x30);
      uVar2 = FUN_005d6516(s_skip_verify_006cad08,0,1);
      *(undefined1 *)(unaff_EBP + -0x18) = uVar2;
      if (*(char *)(unaff_EBP + -0x18) == '\0') {
        FUN_004f4f41(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x20),
                     DAT_006f29f6);
      }
      *(undefined4 *)(unaff_EBP + -0x35c) = DAT_006fe8bc;
      uVar4 = (**(code **)(**(int **)(unaff_EBP + -0x35c) + 0x1c))();
      *(undefined4 *)(unaff_EBP + -0x360) = uVar4;
      *(uint *)(unaff_EBP + -0x44) =
           -(uint)(*(int *)(unaff_EBP + -0x360) != 0) & *(int *)(unaff_EBP + -0x360) - 0x48U;
      (**(code **)(**(int **)(unaff_EBP + -0x44) + 0x1c))
                (CONCAT31((int3)(-(uint)DAT_006f29f6 >> 8),'\x01' - (DAT_006f29f6 != 0)));
      *(undefined4 *)(unaff_EBP + -0x214) = *(undefined4 *)(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -0x210) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x20c) = 0x10;
      (**(code **)(**(int **)(unaff_EBP + -0x44) + 0x14))(unaff_EBP + -0x214);
      (**(code **)(**(int **)(unaff_EBP + -0x44) + 0x18))(*(undefined4 *)(unaff_EBP + -0x1c));
      DAT_006fe914 = 1;
      FUN_005a55de();
      cVar1 = FUN_005d6516(s_testmusic_006cacfc,0,1);
      if (cVar1 != '\0') {
        MessageBoxA((HWND)0x0,s_Please_insert_the_music_CD__and_p_006cacbc,s_Music_006cacf4,0);
      }
      uVar4 = FUN_004e609e();
      *(undefined4 *)(unaff_EBP + -0x2c) = uVar4;
      if (*(int *)(unaff_EBP + -0x2c) != 0) {
        FUN_004e6453(1);
      }
      FUN_004fbb84();
      *(undefined1 *)(unaff_EBP + -0x218) = 1;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar2 = *(undefined1 *)(unaff_EBP + -0x218);
    }
  }
LAB_004f4a10:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

