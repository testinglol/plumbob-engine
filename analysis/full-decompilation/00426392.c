
undefined4 FUN_00426392(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  char *pcVar10;
  size_t sVar11;
  int extraout_ECX;
  uint uVar12;
  int unaff_EBP;
  int iVar13;
  undefined *puVar14;
  undefined4 uStack_6e4;
  undefined *puStack_6e0;
  char *pcStack_6dc;
  
  FUN_00634c24();
  timeGetTime();
  pcStack_6dc = (char *)0x4263b8;
  FUN_005bc6cb();
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(DAT_006e486c + 0x28);
  pcStack_6dc = (char *)0x4263cb;
  puVar2 = (undefined4 *)FUN_0043acf5();
  *(undefined4 **)(unaff_EBP + -0x18) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x28) = *puVar2;
    puStack_6e0 = (undefined *)(unaff_EBP + -0x244);
    pcStack_6dc = (char *)0x0;
    *(undefined4 *)(unaff_EBP + 8) = 0xffffffd5;
    uStack_6e4 = 0x4263fd;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x250) = &PTR_FUN_006664e8;
    if (*(int *)(extraout_ECX + 0x160) < 32000) {
      do {
        if (*(int *)(unaff_EBP + 8) != -0x2b) break;
        pcStack_6dc = (char *)(unaff_EBP + -0x350);
        puStack_6e0 = (undefined *)0x42643a;
        FUN_0046fb9b();
        *(undefined ***)(unaff_EBP + -0x35c) = &PTR_LAB_0066655c;
        pcStack_6dc = s_User_05d_006c2650;
        puStack_6e0 = *(undefined **)(unaff_EBP + -0x358);
        uStack_6e4 = 0x42645a;
        FUN_00635858();
        puStack_6e0 = (undefined *)(unaff_EBP + -0x45c);
        pcStack_6dc = (char *)0x0;
        uStack_6e4 = 0x426472;
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x468) = &PTR_FUN_00666524;
        pcStack_6dc = (char *)0x42648e;
        FUN_0046f8e4();
        pcStack_6dc = &DAT_006c2648;
        puStack_6e0 = (undefined *)0x4264a0;
        FUN_0046f847();
        puStack_6e0 = (undefined *)0x4264ad;
        FUN_00412122();
        pcStack_6dc = s_Characters__006c1d48;
        puStack_6e0 = (undefined *)0x4264c1;
        FUN_0046f847();
        pcStack_6dc = (char *)(unaff_EBP + -0x468);
        puStack_6e0 = (undefined *)0x4264d5;
        FUN_0046f917();
        puStack_6e0 = (undefined *)(unaff_EBP + -0x568);
        pcStack_6dc = (char *)0x0;
        uStack_6e4 = 0x4264ea;
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x574) = &PTR_FUN_00666524;
        pcStack_6dc = (char *)0x426506;
        FUN_0046f8e4();
        pcStack_6dc = (char *)0x426513;
        FUN_0046fa24();
        FUN_0047234b();
        pcStack_6dc = (char *)0x426530;
        FUN_0047239b();
        pcStack_6dc = *(char **)(unaff_EBP + -0x28);
        puStack_6e0 = (undefined *)0x426545;
        uVar3 = FUN_004723b0();
        *(int *)(extraout_ECX + 0x160) = *(int *)(extraout_ECX + 0x160) + 1;
        iVar4 = *(int *)(extraout_ECX + 0x160);
        *(undefined4 *)(unaff_EBP + 8) = uVar3;
      } while (iVar4 < 32000);
      puVar2 = *(undefined4 **)(unaff_EBP + -0x18);
      if (31999 < *(int *)(extraout_ECX + 0x160)) goto LAB_00426565;
    }
    else {
LAB_00426565:
      *(undefined4 *)(extraout_ECX + 0x160) = 0;
    }
    if (*(int *)(unaff_EBP + 8) == 0) {
      pcStack_6dc = (char *)0x426585;
      FUN_0043c422();
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      pcStack_6dc = (char *)0x426596;
      iVar4 = FUN_0043ad1f();
      if (iVar4 != 0) {
        do {
          if ((*(short *)(*(int *)(iVar4 + 0x60) + 0x12) == 0x200) ||
             (*(short *)(*(int *)(iVar4 + 0x60) + 0x12) == 0x400)) {
            piVar8 = *(int **)(extraout_ECX + 0x148);
            piVar9 = *(int **)(extraout_ECX + 0x14c);
            *(undefined4 *)(unaff_EBP + 8) = 0;
            if (piVar8 != piVar9) {
              do {
                iVar13 = *piVar8;
                if (((iVar13 != 0) && (*(int *)(iVar13 + 8) == iVar4)) &&
                   (*(int *)(unaff_EBP + 8) == 0)) {
                  *(int *)(unaff_EBP + 8) = iVar13;
                }
                piVar8 = piVar8 + 1;
              } while (piVar8 != piVar9);
              if (*(int *)(unaff_EBP + 8) != 0) goto LAB_004265f5;
            }
            if (*(int *)(unaff_EBP + -0x1c) == 0) {
              puStack_6e0 = (undefined *)0x4265f2;
              pcStack_6dc = (char *)iVar4;
              uVar3 = FUN_004257ef();
              *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
            }
          }
LAB_004265f5:
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          pcStack_6dc = (char *)0x426603;
          iVar4 = FUN_0043ad1f();
        } while (iVar4 != 0);
        if (*(int *)(unaff_EBP + -0x1c) != 0) {
          puVar1 = *(undefined4 **)(*(int *)(unaff_EBP + -0x1c) + 8);
          *(undefined4 **)(unaff_EBP + -0x44) = puVar1;
          if (puVar1 != (undefined4 *)0x0) {
            (**(code **)(*(int *)*puVar1 + 0x10))();
            (**(code **)(*(int *)*puVar1 + 0x14))();
            *(undefined2 *)(puVar1[0x18] + 0x12) = 2;
            FUN_004574bb();
            FUN_004e8b76();
            if (*(short *)(puVar2[0x18] + 0x12) != 0x200) {
              FUN_0045741b();
              pcStack_6dc = (char *)0x426a09;
              puStack_6e0 = (undefined *)FUN_004e988f();
              pcStack_6dc = (char *)0x1;
              *(undefined **)(unaff_EBP + -0x10) = puStack_6e0;
              uStack_6e4 = 0x426a14;
              FUN_004ea53c();
              uStack_6e4 = *(undefined4 *)(unaff_EBP + -0x10);
              uVar3 = FUN_004eabb1();
              *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -0xd4) = &PTR_FUN_0066643c;
              pcStack_6dc = (char *)(unaff_EBP + -0xd4);
              *(undefined4 *)(unaff_EBP + -4) = 4;
              puStack_6e0 = &DAT_006c265c;
              if (*(int *)(unaff_EBP + -0x24) == 0) {
                uStack_6e4 = 0x96;
              }
              else {
                uStack_6e4 = 0x97;
              }
              FUN_004fff98();
              iVar4 = *(int *)(unaff_EBP + 0xc);
              *(undefined1 *)(unaff_EBP + 0xb) = 0;
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
LAB_00426a6e:
              if ((*(int *)(unaff_EBP + -0x18) < 10) && (iVar13 = FUN_0047168f(), 1 < iVar13)) {
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
                FUN_0047168f();
                pcStack_6dc = (char *)0x426aa6;
                iVar13 = FUN_005bc722();
                iVar13 = iVar13 + 1;
                if ((*(int *)(unaff_EBP + -0x24) == 0) ||
                   (*(int *)(iVar4 + 0x28) - *(int *)(iVar4 + 0x24) >> 2 == 0)) {
                  if (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2 != 0) {
                    piVar8 = *(int **)(iVar4 + 0x1c);
                    for (piVar9 = *(int **)(iVar4 + 0x18); piVar9 != piVar8; piVar9 = piVar9 + 1) {
                      if (*piVar9 == iVar13) goto LAB_00426aeb;
                    }
                  }
                }
                else {
                  piVar8 = *(int **)(iVar4 + 0x28);
                  for (piVar9 = *(int **)(iVar4 + 0x24); piVar9 != piVar8; piVar9 = piVar9 + 1) {
                    if (*piVar9 == iVar13) goto LAB_00426aeb;
                  }
                }
                goto LAB_00426aef;
              }
              goto LAB_00426b64;
            }
            FUN_0045741b();
            pcStack_6dc = (char *)0x426668;
            uVar3 = FUN_004e988f();
            *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
            pcStack_6dc = (char *)0x42667e;
            uVar5 = FUN_005bc722();
            pcStack_6dc = (char *)0x42668b;
            uVar6 = FUN_005bc722();
            puStack_6e0 = (undefined *)0x426695;
            pcStack_6dc = (char *)uVar3;
            FUN_004ea53c();
            puStack_6e0 = (undefined *)(~uVar5 & 1);
            uStack_6e4 = uVar3;
            FUN_004eabf6();
            uVar7 = FUN_004eabb1(uVar3);
            *(undefined4 *)(unaff_EBP + -0x18) = uVar7;
            uVar12 = uVar6 % 3;
            if (uVar12 == 0) {
              *(undefined4 **)(unaff_EBP + 8) = &uStack_6e4;
              *(undefined4 **)(unaff_EBP + 8) = &uStack_6e4;
              FUN_0040f49d();
              puVar14 = &DAT_006c1010;
              **(undefined4 **)(unaff_EBP + 8) = &PTR_FUN_00666634;
            }
            else if (uVar12 == 1) {
              *(undefined4 **)(unaff_EBP + 8) = &uStack_6e4;
              *(undefined4 **)(unaff_EBP + 8) = &uStack_6e4;
              FUN_0040f49d();
              puVar14 = &DAT_006c100c;
              **(undefined4 **)(unaff_EBP + 8) = &PTR_FUN_00666634;
            }
            else {
              if (uVar12 != 2) goto LAB_0042672f;
              *(undefined4 **)(unaff_EBP + 8) = &uStack_6e4;
              *(undefined4 **)(unaff_EBP + 8) = &uStack_6e4;
              FUN_0040f49d();
              puVar14 = &DAT_006c1008;
              **(undefined4 **)(unaff_EBP + 8) = &PTR_FUN_00666634;
            }
            FUN_0046f8cb(puVar14);
            FUN_004eac8c(uVar3);
LAB_0042672f:
            *(uint *)(unaff_EBP + -0x40) = uVar5;
            *(uint *)(unaff_EBP + -0x3c) = uVar6;
            pcStack_6dc = (char *)0x42673d;
            iVar4 = FUN_004eacb7();
            pcStack_6dc = *(char **)(unaff_EBP + -0x10);
            puStack_6e0 = (undefined *)0x426747;
            uVar3 = FUN_004ead68();
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
            *(undefined1 *)(unaff_EBP + -0x11) = 0;
            puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
            iVar13 = 0;
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
            *(undefined4 *)(unaff_EBP + -0x24) = 0;
            if (0 < iVar4) {
              pcStack_6dc = (char *)0x426771;
              iVar4 = FUN_005bc722();
              *(int *)(unaff_EBP + -0x24) = iVar4;
              do {
                if (9 < *(int *)(unaff_EBP + -0x1c)) break;
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                for (piVar8 = (int *)*puVar2; piVar8 != (int *)puVar2[1]; piVar8 = piVar8 + 1) {
                  if (*piVar8 == iVar4) {
                    if (piVar8 != (int *)puVar2[1]) goto LAB_004267a7;
                    break;
                  }
                }
                *(int *)(unaff_EBP + 0xc) = iVar4;
                pcStack_6dc = (char *)0x4267a3;
                FUN_0042eab4();
                *(undefined1 *)(unaff_EBP + 0xb) = 1;
LAB_004267a7:
              } while (*(char *)(unaff_EBP + 0xb) == '\0');
            }
            if (0 < *(int *)(unaff_EBP + -0x28)) {
              pcStack_6dc = (char *)0x4267c4;
              iVar13 = FUN_005bc722();
              pcStack_6dc = (char *)(unaff_EBP + 0xc);
              puStack_6e0 = (undefined *)0x4267d8;
              FUN_0042f380();
              if (*(int *)(unaff_EBP + 0xc) == puVar2[3]) {
                *(undefined4 *)(unaff_EBP + -0x38) = 0;
                *(undefined4 *)(unaff_EBP + -0x34) = 0;
                *(undefined4 *)(unaff_EBP + -0x30) = 0;
                *(undefined4 *)(unaff_EBP + -4) = 0;
                *(int *)(unaff_EBP + 8) = iVar13;
                pcStack_6dc = (char *)0x42683e;
                FUN_0042eab4();
                *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x40);
                *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x3c);
                pcStack_6dc = (char *)0x426856;
                FUN_0042ed23();
                pcStack_6dc = (char *)(unaff_EBP + -0x2c);
                *(undefined1 *)(unaff_EBP + -4) = 1;
                puStack_6e0 = (undefined *)0x426869;
                FUN_0042f2dd();
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_0048c4c9();
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_0048c4c9();
              }
              else {
                do {
                  if (9 < *(int *)(unaff_EBP + -0x20)) break;
                  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
                  piVar8 = *(int **)(*(int *)(unaff_EBP + 0xc) + 0x1c);
                  for (piVar9 = *(int **)(*(int *)(unaff_EBP + 0xc) + 0x18); piVar9 != piVar8;
                      piVar9 = piVar9 + 1) {
                    if (*piVar9 == iVar13) {
                      if (piVar9 != piVar8) goto LAB_00426819;
                      break;
                    }
                  }
                  *(int *)(unaff_EBP + 8) = iVar13;
                  pcStack_6dc = (char *)0x426815;
                  FUN_0042eab4();
                  *(undefined1 *)(unaff_EBP + -0x11) = 1;
LAB_00426819:
                } while (*(char *)(unaff_EBP + -0x11) == '\0');
              }
            }
            pcStack_6dc = *(char **)(unaff_EBP + -0x10);
            puStack_6e0 = (undefined *)0x42688c;
            FUN_004eacf0();
            uStack_6e4 = *(undefined4 *)(unaff_EBP + -0x10);
            puStack_6e0 = (undefined *)iVar13;
            FUN_004eada1();
            FUN_004eadc1(*(undefined4 *)(unaff_EBP + -0x10));
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0x140) = &PTR_FUN_0066643c;
            pcStack_6dc = (char *)(unaff_EBP + -0x140);
            *(undefined4 *)(unaff_EBP + -4) = 2;
            puStack_6e0 = &DAT_006c265c;
            if (*(int *)(unaff_EBP + -0x18) == 0) {
              uStack_6e4 = 0x96;
            }
            else {
              uStack_6e4 = 0x97;
            }
            FUN_004fff98();
            *(undefined1 *)(unaff_EBP + 0xf) = 0;
            *(undefined4 *)(unaff_EBP + 8) = 0;
LAB_004268eb:
            if ((*(int *)(unaff_EBP + 8) < 10) && (iVar4 = FUN_0047168f(), 1 < iVar4)) {
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
              FUN_0047168f();
              pcStack_6dc = (char *)0x426923;
              iVar4 = FUN_005bc722();
              iVar4 = iVar4 + 1;
              if ((*(int *)(unaff_EBP + -0x18) == 0) || ((int)(puVar2[10] - puVar2[9]) >> 2 == 0)) {
                if ((int)(puVar2[7] - puVar2[6]) >> 2 != 0) {
                  piVar8 = (int *)puVar2[7];
                  for (piVar9 = (int *)puVar2[6]; piVar9 != piVar8; piVar9 = piVar9 + 1) {
                    if (*piVar9 == iVar4) goto LAB_00426968;
                  }
                }
              }
              else {
                piVar8 = (int *)puVar2[10];
                for (piVar9 = (int *)puVar2[9]; piVar9 != piVar8; piVar9 = piVar9 + 1) {
                  if (*piVar9 == iVar4) goto LAB_00426968;
                }
              }
              goto LAB_0042696c;
            }
            goto LAB_004269e1;
          }
          goto LAB_00426622;
        }
      }
      uVar3 = 0xffffffff;
      goto LAB_00426b8c;
    }
  }
LAB_00426622:
  uVar3 = 0;
  goto LAB_00426b8c;
LAB_00426aeb:
  if (piVar9 == piVar8) {
LAB_00426aef:
    puStack_6e0 = (undefined *)0x426afd;
    pcStack_6dc = (char *)iVar13;
    pcVar10 = (char *)FUN_004705f2();
    if (pcVar10 != (char *)0x0) {
      pcStack_6dc = (char *)0x426b09;
      sVar11 = _strlen(pcVar10);
      if (sVar11 != 0) {
        pcStack_6dc = (char *)0x426b17;
        FUN_005b870f();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        pcStack_6dc = *(char **)(unaff_EBP + -0x10);
        puStack_6e0 = (undefined *)0x426b27;
        FUN_004e9a99();
        if (*(int *)(unaff_EBP + -0x24) == 0) {
          *(int *)(unaff_EBP + -0x48) = iVar13;
        }
        else {
          *(int *)(unaff_EBP + 0xc) = iVar13;
        }
        pcStack_6dc = (char *)0x426b4a;
        FUN_0042eab4();
        *(undefined1 *)(unaff_EBP + 0xb) = 1;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
      }
    }
  }
  if (*(char *)(unaff_EBP + 0xb) != '\0') goto LAB_00426b64;
  goto LAB_00426a6e;
LAB_00426b64:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  uStack_6e4 = *(undefined4 *)(unaff_EBP + -0x10);
  goto LAB_00426b7c;
LAB_00426968:
  if (piVar9 == piVar8) {
LAB_0042696c:
    puStack_6e0 = (undefined *)0x42697a;
    pcStack_6dc = (char *)iVar4;
    pcVar10 = (char *)FUN_004705f2();
    if (pcVar10 != (char *)0x0) {
      pcStack_6dc = (char *)0x426986;
      sVar11 = _strlen(pcVar10);
      if (sVar11 != 0) {
        pcStack_6dc = (char *)0x426994;
        FUN_005b870f();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        pcStack_6dc = *(char **)(unaff_EBP + -0x10);
        puStack_6e0 = (undefined *)0x4269a4;
        FUN_004e9a99();
        if (*(int *)(unaff_EBP + -0x18) == 0) {
          *(int *)(unaff_EBP + 0xc) = iVar4;
        }
        else {
          *(int *)(unaff_EBP + 0xc) = iVar4;
        }
        pcStack_6dc = (char *)0x4269c7;
        FUN_0042eab4();
        *(undefined1 *)(unaff_EBP + 0xf) = 1;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8770();
      }
    }
  }
  if (*(char *)(unaff_EBP + 0xf) != '\0') goto LAB_004269e1;
  goto LAB_004268eb;
LAB_004269e1:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  uStack_6e4 = *(undefined4 *)(unaff_EBP + -0x10);
LAB_00426b7c:
  pcStack_6dc = (char *)0x1;
  puStack_6e0 = (undefined *)0x1;
  FUN_004ea674();
  uVar3 = FUN_0045741b();
LAB_00426b8c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

