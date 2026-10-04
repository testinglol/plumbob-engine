
undefined4 FUN_00516284(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  uVar3 = FUN_004e609e();
  iVar4 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  if (iVar4 != 1) {
    if (iVar4 == 0xc) {
      piVar7 = *(int **)(unaff_EBP + 0xc);
      if (piVar7 == *(int **)(extraout_ECX + 0x138)) {
        uVar3 = (**(code **)(*piVar7 + 0x19c))();
        FUN_004e62c3(uVar3);
      }
      else if (piVar7 == *(int **)(extraout_ECX + 0x13c)) {
        uVar3 = (**(code **)(*piVar7 + 0x19c))();
        FUN_004e62fc(uVar3);
      }
      else if (piVar7 == *(int **)(extraout_ECX + 0x140)) {
        uVar3 = (**(code **)(*piVar7 + 0x19c))();
        FUN_004e6335(uVar3);
      }
      else {
        piVar7 = (int *)0x0;
      }
      if (piVar7 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar7 + 0x19c))();
        if (iVar4 == 0) {
          uVar3 = *(undefined4 *)(extraout_ECX + 0x1a8);
        }
        else {
          uVar3 = *(undefined4 *)(extraout_ECX + 0x1a4);
        }
        (**(code **)(*piVar7 + 0x1b8))(uVar3,0);
      }
    }
    else if (iVar4 == 0x13) {
      for (piVar7 = (int *)(extraout_ECX + 0xe0);
          (piVar7 != (int *)(extraout_ECX + 0x188) && (*piVar7 != *(int *)(unaff_EBP + 0xc)));
          piVar7 = piVar7 + 1) {
      }
      if (piVar7 != (int *)(extraout_ECX + 0x188)) {
        iVar4 = (int)piVar7 + (-0xe0 - extraout_ECX) >> 2;
        if (iVar4 < 0x1d) {
          if ((iVar4 < 0x19) &&
             ((iVar4 < 6 || ((0xb < iVar4 && ((iVar4 < 0x13 || (0x15 < iVar4))))))))
          goto LAB_005172d1;
        }
        else if ((iVar4 < 0x21) || (0x25 < iVar4)) goto LAB_005172d1;
        if ((*(char *)(*(int *)(extraout_ECX + 0x194) + 0xe0) == '\0') ||
           (*(int *)(unaff_EBP + 0xc) != *(int *)(*(int *)(extraout_ECX + 0x198) + 0x14))) {
          if (*(int *)(*(int *)(extraout_ECX + 0x198) + 0x14) != 0) {
            FUN_005e46f0(0);
          }
          puVar1 = *(undefined4 **)(*(int *)(unaff_EBP + 0xc) + 0xac);
          FUN_00510747(*puVar1);
          FUN_00510775(puVar1[1]);
          FUN_00510489(0,puVar1[2]);
          *(undefined4 *)(*(int *)(extraout_ECX + 0x198) + 0x14) = *(undefined4 *)(unaff_EBP + 0xc);
          FUN_0050fb20(*(undefined4 *)(extraout_ECX + 0x198),extraout_ECX);
        }
        else {
          FUN_0050fc0a(1);
        }
      }
    }
    else if (iVar4 == 0x1c) {
      for (piVar7 = (int *)(extraout_ECX + 0xe0); piVar7 != (int *)(extraout_ECX + 0x188);
          piVar7 = piVar7 + 1) {
        if (*piVar7 == *(int *)(unaff_EBP + 0xc)) {
          if (piVar7 != (int *)(extraout_ECX + 0x188)) {
            iVar4 = (int)piVar7 + (-0xe0 - extraout_ECX) >> 2;
            if (iVar4 < 0x20) {
              if (iVar4 == 0x1f) {
                cVar2 = FUN_004e6383();
                FUN_004e6387('\x01' - (cVar2 != '\0'));
              }
              else if (iVar4 == 0xc) {
                cVar2 = FUN_004e60c2();
                FUN_004e60c8('\x01' - (cVar2 != '\0'));
              }
              else if (iVar4 == 0xd) {
                cVar2 = FUN_004e60ed();
                FUN_004e60f3('\x01' - (cVar2 != '\0'));
              }
              else if (iVar4 == 0xe) {
                cVar2 = FUN_004e6110();
                FUN_004e6116('\x01' - (cVar2 != '\0'));
              }
              else if (iVar4 == 0xf) {
                cVar2 = FUN_004e6133();
                FUN_004e6137('\x01' - (cVar2 != '\0'));
              }
              else if (iVar4 == 0x1d) {
                cVar2 = FUN_004e6352();
                FUN_004e6358('\x01' - (cVar2 != '\0'));
              }
              else if (iVar4 == 0x1e) {
                cVar2 = FUN_004074bc();
                if ((((cVar2 == '\0') && (cVar2 = FUN_00407525(), cVar2 == '\0')) &&
                    (cVar2 = FUN_004074d9(), cVar2 == '\0')) &&
                   ((cVar2 = FUN_0040750e(), cVar2 == '\0' &&
                    (cVar2 = FUN_0042886f(), cVar2 == '\0')))) {
                  FUN_0057a7f7(s_UI_error_006c5e80,0xfffffffc);
                  uVar3 = 0;
                  goto LAB_005172d3;
                }
                cVar2 = FUN_004e6364();
                FUN_004e6376('\x01' - (cVar2 != '\0'));
              }
            }
            else if (iVar4 == 0x20) {
              cVar2 = FUN_004e636a();
              FUN_004e63ce('\x01' - (cVar2 != '\0'));
            }
            else if (iVar4 == 0x26) {
              cVar2 = FUN_004e63de();
              FUN_004e63f8('\x01' - (cVar2 != '\0'));
              uVar3 = FUN_004e63de();
              FUN_00517ae4(uVar3);
            }
            else if (iVar4 == 0x27) {
              cVar2 = FUN_004e642d();
              FUN_004e6431('\x01' - (cVar2 != '\0'));
            }
            else if (iVar4 == 0x28) {
              cVar2 = FUN_004cffb7();
              FUN_004e643b('\x01' - (cVar2 != '\0'));
            }
            else if (iVar4 == 0x29) {
              cVar2 = FUN_004e6445();
              FUN_004e6449('\x01' - (cVar2 != '\0'));
            }
          }
          break;
        }
      }
    }
    else if (iVar4 == 0x1e) {
      if (*(int *)(unaff_EBP + 0xc) == *(int *)(extraout_ECX + 0x120)) {
        iVar4 = FUN_005379dc();
        if (iVar4 == 0) {
          uVar3 = 0;
        }
        else {
          iVar4 = FUN_005379dc();
          if (iVar4 == 1) {
            uVar3 = 1;
          }
          else {
            iVar4 = FUN_005379dc();
            if (iVar4 != 2) goto LAB_005172d1;
            uVar3 = 2;
          }
        }
        FUN_004e6166(uVar3);
      }
      else if (*(int *)(unaff_EBP + 0xc) == *(int *)(extraout_ECX + 0x124)) {
        iVar4 = FUN_005379dc();
        if (iVar4 == 0) {
          uVar3 = 0;
        }
        else {
          iVar4 = FUN_005379dc();
          if (iVar4 == 1) {
            uVar3 = 1;
          }
          else {
            iVar4 = FUN_005379dc();
            if (iVar4 != 2) goto LAB_005172d1;
            uVar3 = 2;
          }
        }
        FUN_004e61c6(uVar3);
      }
    }
    goto LAB_005172d1;
  }
  iVar4 = *(int *)(*(int *)(extraout_ECX + 0xd4) + 0x5c);
  *(int *)(unaff_EBP + 8) = iVar4;
  for (piVar7 = (int *)(extraout_ECX + 0xe0);
      (piVar7 != (int *)(extraout_ECX + 0x188) && (*piVar7 != *(int *)(unaff_EBP + 0xc)));
      piVar7 = piVar7 + 1) {
  }
  if (piVar7 == (int *)(extraout_ECX + 0x188)) goto LAB_005172d1;
  iVar5 = (int)piVar7 + (-0xe0 - extraout_ECX) >> 2;
  *(int *)(unaff_EBP + -0x10) = iVar5;
  if ((((-1 < iVar5) && (iVar5 < 0x2a)) &&
      (iVar5 = *(int *)(extraout_ECX + 0xe0 + iVar5 * 4), iVar5 != 0)) &&
     (*(int *)(iVar5 + 0xac) != 0)) {
    if ((*(char *)(*(int *)(extraout_ECX + 0x194) + 0xe0) == '\0') ||
       (*(int *)(unaff_EBP + 0xc) != *(int *)(*(int *)(extraout_ECX + 0x198) + 0x14))) {
      if (*(int *)(*(int *)(extraout_ECX + 0x198) + 0x14) != 0) {
        FUN_005e46f0(0);
      }
      puVar1 = *(undefined4 **)(*(int *)(unaff_EBP + 0xc) + 0xac);
      FUN_00510747(*puVar1);
      FUN_00510775(puVar1[1]);
      FUN_00510489(0,puVar1[2]);
      *(undefined4 *)(*(int *)(extraout_ECX + 0x198) + 0x14) = *(undefined4 *)(unaff_EBP + 0xc);
      FUN_0050fb20(*(undefined4 *)(extraout_ECX + 0x198),extraout_ECX);
      iVar4 = *(int *)(unaff_EBP + 8);
    }
    else {
      FUN_0050fc0a(1);
    }
  }
  iVar5 = *(int *)(unaff_EBP + -0x10);
  if (iVar5 != 0) {
    if (iVar5 == 1) {
      FUN_00517c78(0);
      FUN_004f277c();
      goto LAB_005172d1;
    }
    if (iVar5 == 2) {
      if (*(char *)(iVar4 + 0xf7) != '\0') {
        iVar5 = FUN_00517c78(1);
        if (iVar5 == 1) {
          FUN_004f277c();
        }
        else {
          if (iVar5 == 0) {
            *(undefined1 *)(unaff_EBP + 0xf) = *(undefined1 *)(iVar4 + 0xf7);
            *(undefined1 *)(iVar4 + 0xf7) = 0;
            cVar2 = (**(code **)(*(int *)(iVar4 + 0x48) + 0x28))();
            if (cVar2 == '\0') {
              *(bool *)(iVar4 + 0xf7) = *(char *)(unaff_EBP + 0xf) == '\x01';
            }
            goto LAB_005172d1;
          }
          if (iVar5 == -1) goto LAB_005172d1;
        }
      }
      (**(code **)(*(int *)(iVar4 + 0x48) + 0x28))();
      goto LAB_005172d1;
    }
    if (iVar5 == 3) {
      if (*(int *)(extraout_ECX + 0xdc) == 1) {
LAB_0051686d:
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
    else if (iVar5 == 4) {
      if (*(int *)(extraout_ECX + 0xdc) == 2) goto LAB_0051686d;
      uVar3 = 2;
    }
    else {
      if (iVar5 != 5) {
        if (iVar5 == 0x21) {
          FUN_004f2661();
        }
        goto LAB_005172d1;
      }
      if (*(int *)(extraout_ECX + 0xdc) == 3) goto LAB_0051686d;
      uVar3 = 3;
    }
    FUN_00517545(uVar3);
    goto LAB_005172d1;
  }
  if ((*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0) &&
     (cVar2 = FUN_004074f7(), cVar2 != '\0')) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004fff98(0x8f,&DAT_006c265c,unaff_EBP + -0xac,0);
    uVar3 = FUN_004705f2(1,0xffffffff);
    FUN_005d4bbf(uVar3);
    uVar3 = FUN_004705f2(2,0xffffffff);
    FUN_005d4bbf(uVar3);
    pvVar6 = operator_new(0x148);
    *(void **)(unaff_EBP + 0xc) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar6 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00523434();
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar4 != 0) {
      FUN_00523771(unaff_EBP + -0x1c);
      FUN_00523be3(unaff_EBP + -0x28);
      uVar8 = 3;
      uVar3 = FUN_005e50fa(3,3);
      FUN_0052386b(uVar3,uVar8);
      uVar8 = 1;
      uVar3 = FUN_005e50fa(1,1);
      FUN_0052386b(uVar3,uVar8);
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
      FUN_005a5631(0x1532,unaff_EBP + 0xc,4);
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        FUN_00523b25(*(undefined4 *)(unaff_EBP + 0xc),1);
      }
      uVar3 = FUN_004f6c41(iVar4,1,0);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
      FUN_005da4c7(iVar4);
      if (*(int *)(unaff_EBP + -0x10) != 3) {
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00517131:
        FUN_00470467();
        goto LAB_005172d1;
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_0051715d:
    FUN_00470467();
    iVar4 = *(int *)(unaff_EBP + 8);
  }
  else {
    if ((*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0) &&
       (cVar2 = FUN_0040750e(), cVar2 != '\0')) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_004fff98(0x92,&DAT_006c265c,unaff_EBP + -0xac,0);
      uVar3 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar3);
      uVar3 = FUN_004705f2(2,0xffffffff);
      FUN_005d4bbf(uVar3);
      pvVar6 = operator_new(0x148);
      *(void **)(unaff_EBP + 0xc) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      if (pvVar6 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00523434();
      }
      *(undefined1 *)(unaff_EBP + -4) = 6;
      if (iVar4 != 0) {
        FUN_00523771(unaff_EBP + -0x28);
        FUN_00523be3(unaff_EBP + -0x1c);
        uVar8 = 3;
        uVar3 = FUN_005e50fa(3,3);
        FUN_0052386b(uVar3,uVar8);
        uVar8 = 1;
        uVar3 = FUN_005e50fa(1,1);
        FUN_0052386b(uVar3,uVar8);
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        FUN_005a5631(0x153a,unaff_EBP + 0xc,4);
        if (*(int *)(unaff_EBP + 0xc) != 0) {
          FUN_00523b25(*(undefined4 *)(unaff_EBP + 0xc),1);
        }
        uVar3 = FUN_004f6c41(iVar4,1,0);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
        FUN_005da4c7(iVar4);
        if (*(int *)(unaff_EBP + -0x10) != 3) {
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          goto LAB_00517131;
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_0051715d;
    }
    if ((*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0) &&
       (cVar2 = FUN_0042886f(), cVar2 != '\0')) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 8;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_004fff98(0x93,&DAT_006c265c,unaff_EBP + -0xac,0);
      if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x54) == 1) {
        uVar3 = 1;
      }
      else {
        uVar3 = 3;
      }
      uVar3 = FUN_004705f2(uVar3,0xffffffff);
      FUN_005d4bbf(uVar3);
      uVar3 = FUN_004705f2(2,0xffffffff);
      FUN_005d4bbf(uVar3);
      pvVar6 = operator_new(0x148);
      *(void **)(unaff_EBP + 0xc) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      if (pvVar6 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00523434();
      }
      *(undefined1 *)(unaff_EBP + -4) = 10;
      if (iVar4 != 0) {
        FUN_00523771(unaff_EBP + -0x28);
        FUN_00523be3(unaff_EBP + -0x1c);
        uVar8 = 3;
        uVar3 = FUN_005e50fa(3,3);
        FUN_0052386b(uVar3,uVar8);
        uVar8 = 1;
        uVar3 = FUN_005e50fa(1,1);
        FUN_0052386b(uVar3,uVar8);
        iVar5 = DAT_006e486c;
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        if (*(short *)(*(int *)(iVar5 + 0x1c) + 0x54) == 1) {
          uVar3 = 0x153b;
        }
        else {
          uVar3 = 0x153c;
        }
        FUN_005a5631(uVar3,unaff_EBP + 0xc,4);
        if (*(int *)(unaff_EBP + 0xc) != 0) {
          FUN_00523b25(*(undefined4 *)(unaff_EBP + 0xc),1);
        }
        uVar3 = FUN_004f6c41(iVar4,1,0);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
        FUN_005da4c7(iVar4);
        if (*(int *)(unaff_EBP + -0x10) != 3) {
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          goto LAB_00517131;
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_0051715d;
    }
    if (((*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0) &&
        (cVar2 = FUN_00407525(), cVar2 != '\0')) &&
       (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x22) == 0)) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 0xc;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_004fff98(0x90,&DAT_006c265c,unaff_EBP + -0xac,0);
      uVar3 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar3);
      uVar3 = FUN_004705f2(2,0xffffffff);
      FUN_005d4bbf(uVar3);
      pvVar6 = operator_new(0x148);
      *(void **)(unaff_EBP + 0xc) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      if (pvVar6 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00523434();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      if (iVar4 != 0) {
        FUN_00523771(unaff_EBP + -0x28);
        FUN_00523be3(unaff_EBP + -0x1c);
        uVar8 = 3;
        uVar3 = FUN_005e50fa(3,3);
        FUN_0052386b(uVar3,uVar8);
        uVar8 = 1;
        uVar3 = FUN_005e50fa(1,1);
        FUN_0052386b(uVar3,uVar8);
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        FUN_005a5631(0x1537,unaff_EBP + 0xc,4);
        if (*(int *)(unaff_EBP + 0xc) != 0) {
          FUN_00523b25(*(undefined4 *)(unaff_EBP + 0xc),1);
        }
        uVar3 = FUN_004f6c41(iVar4,1,0);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
        FUN_005da4c7(iVar4);
        if (*(int *)(unaff_EBP + -0x10) != 3) {
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          goto LAB_00517131;
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_0051715d;
    }
    if ((*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0) &&
       (cVar2 = FUN_004ce974(), cVar2 != '\0')) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x118) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 0x10;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      FUN_004fff98(0x91,&DAT_006c265c,unaff_EBP + -0x118,0);
      uVar3 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar3);
      uVar3 = FUN_004705f2(2,0xffffffff);
      FUN_005d4bbf(uVar3);
      pvVar6 = operator_new(0x148);
      *(void **)(unaff_EBP + 0xc) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      if (pvVar6 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00523434();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      if (iVar4 != 0) {
        FUN_00523771(unaff_EBP + -0x34);
        FUN_00523be3(unaff_EBP + -0x40);
        uVar8 = 3;
        uVar3 = FUN_005e50fa(3,3);
        FUN_0052386b(uVar3,uVar8);
        uVar8 = 1;
        uVar3 = FUN_005e50fa(1,1);
        FUN_0052386b(uVar3,uVar8);
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        FUN_005a5631(0x1539,unaff_EBP + -0x10,4);
        if (*(int *)(unaff_EBP + -0x10) != 0) {
          FUN_00523b25(*(undefined4 *)(unaff_EBP + -0x10),1);
        }
        uVar3 = FUN_004f6c41(iVar4,1,0);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
        FUN_005da4c7(iVar4);
        if (*(int *)(unaff_EBP + 0xc) != 3) {
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          goto LAB_00517131;
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_0051715d;
    }
  }
  cVar2 = FUN_004cebf4();
  if ((cVar2 == '\0') && (*(char *)(iVar4 + 0xf7) == '\x01')) {
    iVar4 = FUN_00517c78(1);
    if (iVar4 == -1) goto LAB_005172d1;
    if (iVar4 == 1) {
      FUN_004f277c();
    }
    if ((iVar4 == -2) && (cVar2 = FUN_004f1abe(), cVar2 == '\0')) goto LAB_005172d1;
  }
  cVar2 = FUN_004074f7();
  if ((cVar2 != '\0') && (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 1)) {
    FUN_004f5b09(0);
    goto LAB_005172d1;
  }
  cVar2 = FUN_00407525();
  if ((cVar2 != '\0') && (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 1)) {
    FUN_004f5b34(0);
    goto LAB_005172d1;
  }
  cVar2 = FUN_0040750e();
  if ((cVar2 != '\0') && (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 1)) {
    FUN_004f5b5f(0);
    goto LAB_005172d1;
  }
  cVar2 = FUN_0042886f();
  if ((cVar2 == '\0') || (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) != 1)) {
    cVar2 = FUN_0042886f();
    if ((cVar2 == '\0') || (iVar4 = *(int *)(DAT_006e486c + 0x1c), *(short *)(iVar4 + 0x50) != 0)) {
      cVar2 = FUN_004ce994();
      if ((cVar2 != '\0') && (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0))
      goto LAB_0051728b;
      cVar2 = FUN_004074d9();
      if ((cVar2 != '\0') && (iVar4 = *(int *)(DAT_006e486c + 0x1c), *(short *)(iVar4 + 0x50) == 0))
      goto LAB_00517263;
    }
    else {
LAB_00517263:
      if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
        iVar4 = FUN_00425db3((int)*(short *)(iVar4 + 0x22));
        if ((0x59 < *(int *)(iVar4 + 0x110)) && (*(int *)(iVar4 + 0x110) < 0x5d)) goto LAB_0051728b;
      }
    }
    FUN_004f5aa0(0);
  }
  else {
LAB_0051728b:
    FUN_004f5b8a(0);
  }
LAB_005172d1:
  uVar3 = 1;
LAB_005172d3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

