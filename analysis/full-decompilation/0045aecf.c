
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_0045aecf(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  int *extraout_ECX;
  int *piVar13;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar11 = *(int *)(unaff_EBP + 8);
  sVar6 = *(short *)(iVar11 + 4);
  iVar8 = *(int *)(iVar11 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar8;
  iVar7 = FUN_00407498((int)sVar6);
  *(int *)(unaff_EBP + -0x1c) = iVar7;
  if ((iVar7 == 0) || (cVar5 = FUN_00432644(), cVar5 == '\0')) {
    *(undefined1 *)(unaff_EBP + -0x11) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x11) = 0;
  }
  if (iVar8 == 0) {
    if (*(char *)(unaff_EBP + -0x11) == '\0') {
      FUN_00481798(extraout_ECX,*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + 0xc))
      ;
      bVar2 = *(byte *)(extraout_ECX + 0x185);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((bVar2 & 1) == 1) {
        iVar8 = FUN_004818cc();
        *(byte *)(iVar8 + 0x1d) = *(byte *)(iVar8 + 0x1d) | 8;
      }
      if ((extraout_ECX[0x2bd] - extraout_ECX[700]) / 0x9c != 0) {
        iVar8 = FUN_004818cc();
        uVar9 = *(uint *)(iVar8 + 0x1c) >> 0xe;
        *(byte *)(unaff_EBP + 0xf) = (byte)uVar9 & 1;
        if ((uVar9 & 1) == 0) {
          iVar8 = FUN_004818cc();
          *(byte *)(iVar8 + 0x1d) = *(byte *)(iVar8 + 0x1d) & 0xbf;
        }
      }
      FUN_0045fa08(unaff_EBP + -0x220);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      FUN_005db425();
      goto LAB_0045afc2;
    }
  }
  else {
LAB_0045afc2:
    iVar8 = FUN_0045c4b5();
    if (iVar8 != 0) {
      if (*(int *)(iVar8 + 0x48) != 0) {
        if (*(char *)(unaff_EBP + -0x11) != '\0') {
          *(uint *)(unaff_EBP + -0x10) = (*(int *)(unaff_EBP + -0x10) == 3) + 0x13;
        }
        if (*(char *)(iVar8 + 0x78) == '\0') {
          if (*(int *)(unaff_EBP + -0x10) == 2) {
            *(undefined4 *)(iVar8 + 0x68) = 0;
          }
          else if (*(int *)(unaff_EBP + -0x10) == 3) {
            *(undefined4 *)(unaff_EBP + -0x10) = 0xf;
          }
          *(undefined1 *)(iVar8 + 0x78) = 1;
        }
        uVar10 = FUN_004818cc();
        *(undefined4 *)(unaff_EBP + 0xc) = uVar10;
        uVar10 = *(undefined4 *)(iVar8 + 0x58);
        *(undefined1 *)(unaff_EBP + -0x11) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = uVar10;
        uVar10 = *(undefined4 *)(iVar8 + 0x60);
        *(undefined4 *)(unaff_EBP + -0x18) = 2;
        *(undefined4 *)(unaff_EBP + -0x30) = uVar10;
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar8 + 100);
LAB_0045b050:
        iVar11 = *(int *)(unaff_EBP + -0x10);
        switch(iVar11) {
        case 0:
          goto LAB_0045b050;
        case 1:
          if ((*(byte *)((int)extraout_ECX + 0x5a) & 8) == 0) goto LAB_0045b130;
          if (((*(byte *)(extraout_ECX + 0x185) & 1) == 1) ||
             (iVar11 = *(int *)(unaff_EBP + -0x1c),
             *(short *)(iVar11 + 0x84) == (short)extraout_ECX[0x21])) {
            cVar5 = FUN_0045d92c();
            if ((cVar5 != '\0') &&
               (iVar11 = (**(code **)(*(int *)extraout_ECX[0x2b7] + 0x30))(), iVar11 != 0)) {
              *(undefined4 *)(unaff_EBP + -0x10) = 7;
              goto LAB_0045b318;
            }
            FUN_004824b8();
            iVar11 = extraout_ECX[0x163];
            *(undefined4 *)(unaff_EBP + -0x10) = 0x12;
            if ((short)iVar11 == 1) {
              cVar5 = FUN_004818d9(extraout_ECX);
              if (cVar5 != '\0') goto LAB_0045b34f;
              *(undefined4 *)(unaff_EBP + -0x10) = 7;
              FUN_0043270d(extraout_ECX);
              if (*(int *)(unaff_EBP + -0x48) != 0) {
                FUN_00457da4();
                sVar6 = FUN_004561a0(0x1a);
                if (sVar6 != 0) {
                  FUN_00457da4();
                  uVar10 = FUN_004561a0(0x1b);
                  if ((short)uVar10 != 0) {
                    iVar11 = *extraout_ECX;
                    *(undefined2 *)(unaff_EBP + -0x38) = *(undefined2 *)(iVar8 + 0x74);
                    *(undefined2 *)(unaff_EBP + -0x36) = 0;
                    *(undefined2 *)(unaff_EBP + -0x34) = 0;
                    *(undefined2 *)(unaff_EBP + -0x32) = 0;
                    cVar5 = (**(code **)(iVar11 + 0x34))
                                      (*(undefined4 *)(unaff_EBP + -0x48),unaff_EBP + -0x38,uVar10,0
                                      );
                    if (cVar5 != '\0') {
                      uVar10 = *(undefined4 *)(iVar8 + 0x74);
                      *(undefined4 *)(unaff_EBP + -0x10) = 5;
                      *(short *)((int)extraout_ECX + 0x5d6) = (short)uVar10;
LAB_0045bac7:
                      *(undefined4 *)(unaff_EBP + -0x18) = 3;
                      goto LAB_0045bace;
                    }
                  }
                }
              }
            }
          }
          else {
            iVar7 = *(int *)(iVar11 + 0x118);
            *(undefined4 *)(unaff_EBP + -0x10) = 2;
            if (*(short *)(iVar7 + 0x12) == 8) {
              iVar7 = extraout_ECX[700];
              iVar4 = extraout_ECX[0x2bd];
              if (iVar7 != iVar4) {
                while( true ) {
                  if (*(int *)(iVar7 + 0x68) == iVar11) {
                    *(undefined4 *)(unaff_EBP + -0x10) = 7;
                  }
                  iVar7 = iVar7 + 0x9c;
                  if (iVar7 == iVar4) break;
                  iVar11 = *(int *)(unaff_EBP + -0x1c);
                }
              }
            }
          }
          goto LAB_0045b050;
        case 2:
          cVar5 = FUN_0045d92c();
          if ((cVar5 != '\0') &&
             (iVar11 = (**(code **)(*(int *)extraout_ECX[0x2b7] + 0x30))(), iVar11 != 0))
          goto LAB_0045b156;
          if (*(short *)(*(int *)(unaff_EBP + -0x1c) + 0x84) != (short)extraout_ECX[0x21]) {
            if ((*(int *)(iVar8 + 0x68) != 0) && ((char)extraout_ECX[8] == '\0')) {
              FUN_00463f5f(extraout_ECX[0x37],extraout_ECX,*(int *)(iVar8 + 0x68));
            }
            cVar5 = FUN_0045c92e(iVar8);
            if (cVar5 != '\0') {
              *(undefined4 *)(unaff_EBP + -0x10) = 2;
              goto LAB_0045bac7;
            }
            *(undefined4 *)(iVar8 + 0x88) = 2;
            goto LAB_0045b1ac;
          }
          *(undefined2 *)(extraout_ECX + 0x187) = *(undefined2 *)(iVar8 + 0x94);
          break;
        case 3:
          cVar5 = FUN_0045d92c();
          if ((cVar5 == '\0') ||
             (iVar11 = (**(code **)(*(int *)extraout_ECX[0x2b7] + 0x30))(), iVar11 == 0)) {
            if (((extraout_ECX[0x2bd] - extraout_ECX[700]) / 0x9c == 0) ||
               ((extraout_ECX[0x2b9] - extraout_ECX[0x2b8] & 0xfffffff8U) == 0)) {
              *(undefined4 *)(unaff_EBP + -0x10) = 0xb;
            }
            else {
              iVar11 = FUN_00589d4b();
              *(int *)(unaff_EBP + -0x18) = iVar11;
              if (iVar11 == 0) {
                *(undefined4 *)(unaff_EBP + -0x10) = 10;
              }
              else if (iVar11 == 1) {
                *(undefined4 *)(unaff_EBP + -0x10) = 9;
              }
              else if (iVar11 == 2) goto LAB_0045bb0c;
            }
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x10) = 0xb;
LAB_0045b318:
            *(undefined4 *)(iVar8 + 0x88) = 4;
          }
          goto LAB_0045b050;
        case 4:
          cVar5 = FUN_00474fe6();
          if (cVar5 != '\0') goto LAB_0045b34f;
          iVar11 = extraout_ECX[0x182];
          *(undefined4 *)(unaff_EBP + -0x10) = 0x10;
          if ((short)iVar11 == 0) {
            *(undefined4 *)(iVar8 + 0x88) = 5;
          }
          else {
            *(int *)(iVar8 + 0x88) = (int)(short)iVar11;
          }
          goto LAB_0045b050;
        case 5:
          *(undefined2 *)(extraout_ECX + 0x187) = *(undefined2 *)(iVar8 + 0x94);
          cVar5 = FUN_00474fe6();
          if ((cVar5 == '\0') || ((short)extraout_ECX[0x163] != 0)) {
            *(undefined4 *)(unaff_EBP + -0x10) = 0x10;
            *(undefined4 *)(iVar8 + 0x88) = 6;
            goto LAB_0045b050;
          }
          break;
        case 6:
          sVar6 = (short)*(undefined4 *)(unaff_EBP + -0x20);
          if (sVar6 != 0) {
            iVar11 = 1;
            if (sVar6 == 1) {
              iVar11 = *(int *)(iVar8 + 0x80);
              *(undefined4 *)(unaff_EBP + -0x20) = 2;
              if ((iVar11 == 0) && (cVar5 = FUN_0045bb94(iVar8), cVar5 != '\0')) {
                *(undefined4 *)(unaff_EBP + -0x10) = 0xe;
              }
              else {
LAB_0045b1ac:
                *(undefined4 *)(unaff_EBP + -0x10) = 0x10;
              }
            }
            else {
              if (sVar6 == 2) {
                *(undefined4 *)(unaff_EBP + -0x20) = 3;
              }
              else {
                iVar11 = ((sVar6 != 3) - 1 & 9) + 7;
              }
              *(int *)(unaff_EBP + -0x10) = iVar11;
            }
            goto LAB_0045b050;
          }
          iVar7 = extraout_ECX[0x3d] - *(int *)(unaff_EBP + -0x30);
          iVar11 = extraout_ECX[0x3e] - *(int *)(unaff_EBP + -0x2c);
          *(int *)(unaff_EBP + -0x30) = extraout_ECX[0x3d];
          *(int *)(unaff_EBP + -0x2c) = extraout_ECX[0x3e];
          if (iVar7 * iVar7 + iVar11 * iVar11 < 0x41) {
            *(undefined4 *)(unaff_EBP + -0x20) = 1;
            goto LAB_0045b050;
          }
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          break;
        case 7:
        case 8:
          goto LAB_0045b856;
        case 9:
          cVar5 = FUN_00589e31();
          if (cVar5 != '\0') {
            *(undefined4 *)(unaff_EBP + -0x10) = 8;
            goto LAB_0045b4f7;
          }
          goto LAB_0045bb0c;
        case 10:
          cVar5 = FUN_00589e31();
          if (cVar5 != '\0') {
            *(undefined4 *)(unaff_EBP + -0x10) = 6;
            goto LAB_0045b4f7;
          }
          goto LAB_0045bb0c;
        case 0xb:
          cVar5 = FUN_00589e31();
          if (cVar5 == '\0') goto LAB_0045bb0c;
          *(undefined4 *)(unaff_EBP + -0x10) = 7;
LAB_0045b4f7:
          FUN_0057a7f7(s_end_route_006c4560,(short)extraout_ECX[0x3c]);
          goto LAB_0045b050;
        case 0xc:
          FUN_0057a7f7(s_begin_route_006c4520,
                       CONCAT22((short)((uint)iVar11 >> 0x10),(short)extraout_ECX[0x3c]));
          FUN_00589c89();
          *(undefined4 *)(unaff_EBP + -0x10) = 3;
          goto LAB_0045bb0c;
        case 0xd:
          cVar5 = FUN_0045d92c();
          if ((cVar5 == '\0') ||
             (iVar11 = (**(code **)(*(int *)extraout_ECX[0x2b7] + 0x30))(), iVar11 == 0)) {
            iVar11 = *(int *)(iVar8 + 0x5c);
            if (iVar11 == 0) {
              iVar11 = *(int *)(*(int *)(extraout_ECX[0x37] + 0x7c) + 0x98);
            }
            if (*(int *)(*(int *)(extraout_ECX[0x37] + 0x7c) + 0x98) - iVar11 < 0xf) {
              FUN_0046f824(unaff_EBP + -300,0,0x40);
              *(undefined ***)(unaff_EBP + -0x138) = &PTR_FUN_0066651c;
              FUN_0046f847(s_route_waiting_animation_006c452c,0xffffffff);
              uVar10 = FUN_00402246(unaff_EBP + -0x138);
              if (((short)uVar10 != 0) &&
                 (cVar5 = (**(code **)(*extraout_ECX + 0x34))(extraout_ECX,0,uVar10,0),
                 cVar5 != '\0')) {
LAB_0045b7f5:
                *(undefined4 *)(unaff_EBP + -0x18) = 3;
                *(undefined1 *)(unaff_EBP + -0x11) = 1;
                goto LAB_0045b80b;
              }
            }
            iVar11 = 0;
            *(undefined4 *)(unaff_EBP + -0x10) = 1;
            goto LAB_0045b80b;
          }
          goto LAB_0045b156;
        case 0xe:
          cVar5 = FUN_0045d92c();
          if ((cVar5 == '\0') ||
             (iVar11 = (**(code **)(*(int *)extraout_ECX[0x2b7] + 0x30))(), iVar11 == 0)) {
            iVar11 = *(int *)(iVar8 + 0x5c);
            if (*(int *)(iVar8 + 0x80) == 0) {
              iVar11 = 0;
              *(undefined4 *)(unaff_EBP + -0x10) = 1;
              if (*(char *)(iVar8 + 0x84) != '\0') {
                *(undefined4 *)(unaff_EBP + -0x20) = 0;
              }
            }
            else {
              if (iVar11 == 0) {
                FUN_0046f824(unaff_EBP + -0x178,0,0x40);
                *(undefined ***)(unaff_EBP + -0x184) = &PTR_FUN_0066651c;
                FUN_0046f847(s_route_ask_to_move_animation_006c4544,0xffffffff);
                uVar10 = FUN_00402246(unaff_EBP + -0x184);
                if (((short)uVar10 != 0) &&
                   (cVar5 = (**(code **)(*extraout_ECX + 0x34))(extraout_ECX,0,uVar10,0),
                   cVar5 != '\0')) {
                  uVar3 = *(undefined2 *)(*(int *)(iVar8 + 0x80) + 0xf0);
                  iVar11 = FUN_004750a6();
                  *(undefined2 *)(iVar11 + 4) = uVar3;
                  iVar11 = extraout_ECX[0x37];
                  *(undefined4 *)(unaff_EBP + -0x18) = 3;
                  *(undefined1 *)(unaff_EBP + -0x11) = 1;
                  iVar11 = *(int *)(*(int *)(iVar11 + 0x7c) + 0x98);
                  goto LAB_0045b80b;
                }
              }
              else {
                if (*(int *)(*(int *)(extraout_ECX[0x37] + 0x7c) + 0x98) - iVar11 < 100) {
                  FUN_0046f824(unaff_EBP + -0xe0,0,0x40);
                  *(undefined ***)(unaff_EBP + -0xec) = &PTR_FUN_0066651c;
                  FUN_0046f847(s_route_waiting_animation_006c452c,0xffffffff);
                  uVar10 = FUN_00402246(unaff_EBP + -0xec);
                  if (((short)uVar10 != 0) &&
                     (cVar5 = (**(code **)(*extraout_ECX + 0x34))(extraout_ECX,0,uVar10,0),
                     cVar5 != '\0')) goto LAB_0045b7f5;
                }
                iVar11 = 0;
              }
              *(undefined4 *)(unaff_EBP + -0x10) = 6;
            }
LAB_0045b80b:
            *(int *)(iVar8 + 0x5c) = iVar11;
            goto LAB_0045b817;
          }
LAB_0045b156:
          *(undefined4 *)(iVar8 + 0x88) = 4;
        case 0x13:
LAB_0045b130:
          *(undefined4 *)(unaff_EBP + -0x10) = 7;
          goto LAB_0045b050;
        case 0xf:
          cVar5 = FUN_00589e31();
          if (cVar5 == '\0') goto LAB_0045bb0c;
          break;
        case 0x10:
          if (*(int *)(iVar8 + 0x88) == 0) {
            *(undefined4 *)(iVar8 + 0x88) = 1;
          }
          uVar10 = *(undefined4 *)(iVar8 + 0x88);
          *(undefined4 *)(unaff_EBP + -0x10) = 7;
          *(short *)(extraout_ECX + 0x182) = (short)uVar10;
          if ((*(uint *)(*(int *)(unaff_EBP + 0xc) + 0x1c) >> 0xe & 1) != 0) {
            FUN_0046f824(unaff_EBP + -0x94,0,0x40);
            *(undefined ***)(unaff_EBP + -0xa0) = &PTR_FUN_0066651c;
            FUN_0046f847(s_Route_failure_feedback_006c456c,0xffffffff);
            uVar10 = FUN_00402246(unaff_EBP + -0xa0);
            *(undefined2 *)(unaff_EBP + -0x28) = *(undefined2 *)(iVar8 + 0x88);
            *(undefined2 *)(unaff_EBP + -0x26) = *(undefined2 *)(iVar8 + 0x8c);
            *(undefined2 *)(unaff_EBP + -0x24) = 0;
            *(undefined2 *)(unaff_EBP + -0x22) = 0;
            if (((short)uVar10 != 0) &&
               (cVar5 = (**(code **)(*extraout_ECX + 0x34))
                                  (*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBP + -0x28,uVar10,0),
               cVar5 != '\0')) {
              *(undefined4 *)(unaff_EBP + -0x18) = 3;
              *(undefined2 *)(extraout_ECX + 0x187) = 0;
              *(undefined4 *)(unaff_EBP + -0x10) = 0x11;
              goto LAB_0045bb0c;
            }
          }
          goto LAB_0045b050;
        case 0x11:
          *(short *)(extraout_ECX + 0x182) = (short)*(undefined4 *)(iVar8 + 0x88);
          goto LAB_0045b130;
        case 0x12:
          iVar11 = FUN_0045c4fa(iVar8);
          *(int *)(unaff_EBP + -0x18) = iVar11;
          if (iVar11 == 0) {
            *(undefined4 *)(unaff_EBP + -0x10) = 6;
          }
          else if (iVar11 == 1) {
LAB_0045b34f:
            *(undefined4 *)(unaff_EBP + -0x10) = 8;
          }
          else if (iVar11 == 2) {
            *(undefined4 *)(unaff_EBP + -0x10) = 0xc;
          }
          else if (iVar11 == 3) {
            *(undefined4 *)(unaff_EBP + -0x10) = 4;
LAB_0045bace:
            *(undefined2 *)(extraout_ECX + 0x187) = 0;
            goto LAB_0045bb0c;
          }
          goto LAB_0045b050;
        case 0x14:
          cVar5 = FUN_00589e31();
          if (cVar5 != '\0') goto code_r0x0045b4d1;
          goto LAB_0045bb0c;
        default:
          *(undefined4 *)(unaff_EBP + -0x10) = 7;
LAB_0045b817:
          if (*(char *)(unaff_EBP + -0x11) != '\0') goto LAB_0045bb0c;
          goto LAB_0045b050;
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 1;
        goto LAB_0045b050;
      }
      *(undefined4 *)(iVar11 + 8) = 0;
      FUN_0045fa37();
      uVar10 = 2;
      goto LAB_0045bb2f;
    }
  }
  uVar10 = 0;
LAB_0045bb2f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar10;
code_r0x0045b4d1:
  *(undefined4 *)(unaff_EBP + -0x10) = 0x13;
  goto LAB_0045b050;
LAB_0045b856:
  if (iVar11 == 8) {
    if ((short)extraout_ECX[0x187] == 0) {
      cVar5 = (**(code **)(*extraout_ECX + 0x54))(extraout_ECX + 0x3d,extraout_ECX[0x44],0,0);
      if (cVar5 != '\0') goto LAB_0045b924;
    }
    else {
      *(short *)((int)extraout_ECX + 0x61e) = (short)extraout_ECX[0x187];
      cVar5 = (**(code **)(*extraout_ECX + 0x54))(extraout_ECX + 0x3d,extraout_ECX[0x44],0,0);
      if (cVar5 != '\0') {
LAB_0045b924:
        (**(code **)(*extraout_ECX + 0x88))(extraout_ECX + 0x3d,extraout_ECX[0x44],0,0);
        if ((1 < (uint)(extraout_ECX[0x2b9] - extraout_ECX[0x2b8] >> 3)) &&
           ((short)extraout_ECX[0x17] == 0)) {
          iVar11 = extraout_ECX[0x2b8];
          iVar7 = extraout_ECX[0x2b9] - iVar11 >> 3;
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar11 + -0x10 + iVar7 * 8);
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar11 + -0xc + iVar7 * 8);
          sVar6 = FUN_00452129(iVar11 + -8 + (extraout_ECX[0x2b9] - iVar11 >> 3) * 8);
          *(short *)(extraout_ECX + 0x13) = sVar6;
          while (sVar6 < 0) {
            *(short *)(extraout_ECX + 0x13) = (short)extraout_ECX[0x13] + 8;
            sVar6 = (short)extraout_ECX[0x13];
          }
          *(ushort *)(extraout_ECX + 0x13) = *(ushort *)(extraout_ECX + 0x13) & 7;
          (**(code **)(*extraout_ECX + 0x74))();
        }
        goto LAB_0045b8b5;
      }
      *(undefined2 *)((int)extraout_ECX + 0x61e) = 0;
    }
    if ((short)extraout_ECX[0x163] == 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 7;
      *(undefined4 *)(iVar8 + 0x88) = 1;
    }
  }
LAB_0045b8b5:
  iVar11 = FUN_00589ea5();
  if (iVar11 != 0) {
    FUN_0045451c();
    FUN_00589e31();
  }
  if (*(int *)(unaff_EBP + -0x10) == 7) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    if (*(int *)(iVar8 + 0x88) == 0) {
      *(undefined4 *)(iVar8 + 0x88) = 1;
    }
  }
  else {
    *(undefined4 *)(iVar8 + 0x88) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
  }
  piVar13 = extraout_ECX + 700;
  *(short *)(extraout_ECX + 0x182) = (short)*(undefined4 *)(iVar8 + 0x88);
  iVar11 = extraout_ECX[0x2bd];
  *(int **)(unaff_EBP + 0xc) = piVar13;
  if (((iVar11 - *piVar13) / 0x9c == 1) && ((short)extraout_ECX[0x176] == 0)) {
    *(undefined2 *)((int)extraout_ECX + 0x5da) = 1;
  }
  *(undefined2 *)(extraout_ECX + 0x17) = 0;
  iVar11 = extraout_ECX[0x2a1];
  *(int *)(unaff_EBP + -0x3c) = iVar11;
  if (iVar11 != 0) {
    iVar11 = extraout_ECX[0x37];
    puVar12 = *(undefined4 **)(iVar11 + 0x84);
    puVar1 = *(undefined4 **)(iVar11 + 0x88);
    *(undefined4 **)(unaff_EBP + -0x1c) = puVar12;
    if (puVar12 != puVar1) {
      do {
        if (((((int *)*puVar12 != extraout_ECX) && (iVar7 = FUN_0045c4b5(), iVar7 != 0)) &&
            (piVar13 = *(int **)(iVar7 + 0x80), *(int *)(unaff_EBP + -0x24) = iVar7 + 0x80,
            piVar13 == extraout_ECX)) && (*(int *)(iVar7 + 0x90) == *(int *)(unaff_EBP + -0x3c))) {
          *(bool *)(iVar7 + 0x84) = *(int *)(unaff_EBP + -0x10) == 8;
          **(undefined4 **)(unaff_EBP + -0x24) = 0;
          *(int *)(iVar7 + 0x90) = 0;
        }
        puVar12 = (undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4);
        puVar1 = *(undefined4 **)(iVar11 + 0x88);
        *(undefined4 **)(unaff_EBP + -0x1c) = puVar12;
      } while (puVar12 != puVar1);
      piVar13 = *(int **)(unaff_EBP + 0xc);
    }
  }
  if (*(int *)(iVar8 + 0x80) != 0) {
    FUN_0045d764(*(undefined4 *)(iVar8 + 0x90));
    piVar13 = *(int **)(unaff_EBP + 0xc);
  }
  if ((piVar13[1] - *piVar13) / 0x9c != 0) {
    FUN_0045fa46(extraout_ECX[0x2bd] + -0x9c);
  }
  iVar8 = 0;
LAB_0045bb0c:
  *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8) = *(undefined4 *)(unaff_EBP + -0x10);
  if (iVar8 != 0) {
    *(int *)(iVar8 + 0x58) = (int)*(short *)(unaff_EBP + -0x20);
    *(undefined4 *)(iVar8 + 0x60) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(unaff_EBP + -0x2c);
  }
  uVar10 = *(undefined4 *)(unaff_EBP + -0x18);
  goto LAB_0045bb2f;
}

