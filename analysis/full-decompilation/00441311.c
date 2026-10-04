
undefined1 FUN_00441311(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffbf0;
  *(undefined4 *)(unaff_EBP + -0x3dc) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x1c) = 0;
LAB_00441332:
  do {
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 100);
    while( true ) {
      *(undefined4 *)(unaff_EBP + -0x130) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x68);
      if (*(int *)(unaff_EBP + -0x18) == *(int *)(unaff_EBP + -0x130)) {
        if ((*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xe8) < 0) &&
           (*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xe8) != -9999)) {
          pvVar4 = operator_new(0x1b0);
          *(void **)(unaff_EBP + -0xe4) = pvVar4;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (*(int *)(unaff_EBP + -0xe4) == 0) {
            *(undefined4 *)(unaff_EBP + -0x3e4) = 0;
          }
          else {
            uVar5 = FUN_005222e9(DAT_006f2aa4,-(int)*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xe8))
            ;
            *(undefined4 *)(unaff_EBP + -0x3e4) = uVar5;
          }
          *(undefined4 *)(unaff_EBP + -0xe0) = *(undefined4 *)(unaff_EBP + -0x3e4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0xe0);
          uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0x24),1,0);
          *(undefined4 *)(unaff_EBP + -0x28) = uVar5;
          iVar6 = FUN_00522eb9();
          if (iVar6 < 1) {
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xe8) = 0xd8f1;
          }
          else {
            uVar3 = FUN_00522eb9();
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xe8) = uVar3;
          }
          FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x24));
        }
        if (*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xea) < 0) {
          pvVar4 = operator_new(0x1f8);
          *(void **)(unaff_EBP + -0xec) = pvVar4;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (*(int *)(unaff_EBP + -0xec) == 0) {
            *(undefined4 *)(unaff_EBP + -1000) = 0;
          }
          else {
            uVar5 = FUN_00549f7f(0);
            *(undefined4 *)(unaff_EBP + -1000) = uVar5;
          }
          *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(unaff_EBP + -1000);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0xe8);
          uVar5 = FUN_004b46a0();
          *(undefined4 *)(unaff_EBP + -0x14c) = uVar5;
          *(int *)(unaff_EBP + -0x150) = *(int *)(unaff_EBP + -0x14c) + 0x7c;
          (**(code **)(**(int **)(unaff_EBP + -0x30) + 0x60))
                    (**(undefined4 **)(unaff_EBP + -0x150),
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x150) + 4),
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x150) + 8),
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x150) + 0xc));
          FUN_0057a14d(s_bkground_fade_006c3bcc);
          FUN_0057a14d(s_kill_all_objectsounds_006c3bb4);
          uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0x30),1,0);
          *(undefined4 *)(unaff_EBP + -0x2c) = uVar5;
          FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x30));
          if ((*(uint *)(unaff_EBP + -0x2c) < 0x15) || (0x1e < *(uint *)(unaff_EBP + -0x2c))) {
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xea) = 0;
          }
          else {
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xea) =
                 *(undefined2 *)(unaff_EBP + -0x2c);
            FUN_004fc4ab(0);
          }
        }
        if (*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xf2) < 0) {
          *(undefined4 *)(unaff_EBP + -0x34) = 0;
          if ((*(ushort *)(DAT_006e486c + 0x66) & 0x20) == 0) {
            pvVar4 = operator_new(0x1b0);
            *(void **)(unaff_EBP + -0xfc) = pvVar4;
            *(undefined4 *)(unaff_EBP + -4) = 3;
            if (*(int *)(unaff_EBP + -0xfc) == 0) {
              *(undefined4 *)(unaff_EBP + -0x3f0) = 0;
            }
            else {
              uVar5 = FUN_004425e8(1);
              *(undefined4 *)(unaff_EBP + -0x3f0) = uVar5;
            }
            *(undefined4 *)(unaff_EBP + -0xf8) = *(undefined4 *)(unaff_EBP + -0x3f0);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0xf8);
          }
          else {
            pvVar4 = operator_new(0x20c);
            *(void **)(unaff_EBP + -0xf4) = pvVar4;
            *(undefined4 *)(unaff_EBP + -4) = 2;
            if (*(int *)(unaff_EBP + -0xf4) == 0) {
              *(undefined4 *)(unaff_EBP + -0x3ec) = 0;
            }
            else {
              uVar5 = FUN_005569af(0);
              *(undefined4 *)(unaff_EBP + -0x3ec) = uVar5;
            }
            *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x3ec);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0xf0);
          }
          uVar5 = FUN_004b46a0();
          *(undefined4 *)(unaff_EBP + -0x30c) = uVar5;
          *(int *)(unaff_EBP + -0x310) = *(int *)(unaff_EBP + -0x30c) + 0x7c;
          (**(code **)(**(int **)(unaff_EBP + -0x34) + 0x60))
                    (**(undefined4 **)(unaff_EBP + -0x310),
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x310) + 4),
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x310) + 8),
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x310) + 0xc));
          FUN_0057a14d(s_bkground_fade_006c3bcc);
          FUN_0057a14d(s_kill_all_objectsounds_006c3bb4);
          uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0x34),1,0);
          *(undefined4 *)(unaff_EBP + -0x38) = uVar5;
          FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x34));
          *(undefined4 *)(unaff_EBP + -0x314) = *(undefined4 *)(DAT_006e486c + 0x24);
          iVar6 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + -0x38));
          if (iVar6 == 2) {
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf2) =
                 *(undefined2 *)(unaff_EBP + -0x38);
            FUN_004fc4ab(3);
          }
          else {
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf2) = 0;
          }
        }
        else {
          if (*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0xf8) != 0) {
            pvVar4 = operator_new(0x138);
            *(void **)(unaff_EBP + -0x104) = pvVar4;
            *(undefined4 *)(unaff_EBP + -4) = 4;
            if (*(int *)(unaff_EBP + -0x104) == 0) {
              *(undefined4 *)(unaff_EBP + -0x3f4) = 0;
            }
            else {
              uVar5 = FUN_00508f8f((int)*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xf4),
                                   *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf8));
              *(undefined4 *)(unaff_EBP + -0x3f4) = uVar5;
            }
            *(undefined4 *)(unaff_EBP + -0x100) = *(undefined4 *)(unaff_EBP + -0x3f4);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x100);
            uVar5 = FUN_004b46a0();
            *(undefined4 *)(unaff_EBP + -0x3c) = uVar5;
            *(int *)(unaff_EBP + -0x318) = *(int *)(unaff_EBP + -0x3c) + 0x7c;
            *(undefined4 *)(unaff_EBP + -0x54) = **(undefined4 **)(unaff_EBP + -0x318);
            *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(*(int *)(unaff_EBP + -0x318) + 4);
            *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x318) + 8);
            *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x318) + 0xc)
            ;
            *(int *)(unaff_EBP + -0x31c) = *(int *)(unaff_EBP + -0x3c) + 0x7c;
            *(int *)(unaff_EBP + -0x54) =
                 *(int *)(unaff_EBP + -0x54) +
                 ((*(int *)(*(int *)(unaff_EBP + -0x31c) + 8) - **(int **)(unaff_EBP + -0x31c)) +
                 -300) / 2;
            *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x54) + 300;
            *(int *)(unaff_EBP + -800) = *(int *)(unaff_EBP + -0x3c) + 0x7c;
            *(int *)(unaff_EBP + -0x50) =
                 *(int *)(unaff_EBP + -0x50) +
                 ((*(int *)(*(int *)(unaff_EBP + -800) + 0xc) -
                  *(int *)(*(int *)(unaff_EBP + -800) + 4)) + -400) / 2;
            *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x50) + 400;
            uVar5 = *(undefined4 *)(unaff_EBP + -0x50);
            (**(code **)(**(int **)(unaff_EBP + -0x58) + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x54),uVar5,*(undefined4 *)(unaff_EBP + -0x4c),
                       *(undefined4 *)(unaff_EBP + -0x48));
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf6) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 5;
            uVar7 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0x58),1,0);
            *(undefined4 *)(unaff_EBP + -0x3f8) = uVar7;
            *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x3f8);
            uVar2 = FUN_0044198d(uVar5);
            return uVar2;
          }
          if (*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0xfc) != 0) {
            pvVar4 = operator_new(0x13c);
            *(void **)(unaff_EBP + -0x10c) = pvVar4;
            *(undefined4 *)(unaff_EBP + -4) = 7;
            if (*(int *)(unaff_EBP + -0x10c) == 0) {
              *(undefined4 *)(unaff_EBP + -0x3fc) = 0;
            }
            else {
              uVar5 = FUN_00536c99(*(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0xfc));
              *(undefined4 *)(unaff_EBP + -0x3fc) = uVar5;
            }
            *(undefined4 *)(unaff_EBP + -0x108) = *(undefined4 *)(unaff_EBP + -0x3fc);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x108);
            uVar5 = FUN_004b46a0();
            *(undefined4 *)(unaff_EBP + -0x5c) = uVar5;
            *(int *)(unaff_EBP + -0x324) = *(int *)(unaff_EBP + -0x5c) + 0x7c;
            *(undefined4 *)(unaff_EBP + -0x78) = **(undefined4 **)(unaff_EBP + -0x324);
            *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(*(int *)(unaff_EBP + -0x324) + 4);
            *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(*(int *)(unaff_EBP + -0x324) + 8);
            *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x324) + 0xc)
            ;
            *(int *)(unaff_EBP + -0x328) = *(int *)(unaff_EBP + -0x5c) + 0x7c;
            *(int *)(unaff_EBP + -0x78) =
                 *(int *)(unaff_EBP + -0x78) +
                 ((*(int *)(*(int *)(unaff_EBP + -0x328) + 8) - **(int **)(unaff_EBP + -0x328)) +
                 -300) / 2;
            *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x78) + 300;
            *(int *)(unaff_EBP + -0x32c) = *(int *)(unaff_EBP + -0x5c) + 0x7c;
            *(int *)(unaff_EBP + -0x74) =
                 *(int *)(unaff_EBP + -0x74) +
                 ((*(int *)(*(int *)(unaff_EBP + -0x32c) + 0xc) -
                  *(int *)(*(int *)(unaff_EBP + -0x32c) + 4)) + -400) / 2;
            *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x74) + 400;
            uVar5 = *(undefined4 *)(unaff_EBP + -0x74);
            (**(code **)(**(int **)(unaff_EBP + -0x68) + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x78),uVar5,*(undefined4 *)(unaff_EBP + -0x70),
                       *(undefined4 *)(unaff_EBP + -0x6c));
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf6) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 8;
            uVar7 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0x68),1,0);
            *(undefined4 *)(unaff_EBP + -0x400) = uVar7;
            *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x400);
            uVar2 = FUN_00441b72(uVar5);
            return uVar2;
          }
          if (*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x104) == 0) {
            if (*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xec) < 0) {
              pvVar4 = operator_new(0x200);
              *(void **)(unaff_EBP + -0x11c) = pvVar4;
              *(undefined4 *)(unaff_EBP + -4) = 0xb;
              if (*(int *)(unaff_EBP + -0x11c) == 0) {
                *(undefined4 *)(unaff_EBP + -0x408) = 0;
              }
              else {
                uVar5 = FUN_00568898(0);
                *(undefined4 *)(unaff_EBP + -0x408) = uVar5;
              }
              *(undefined4 *)(unaff_EBP + -0x118) = *(undefined4 *)(unaff_EBP + -0x408);
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              *(undefined4 *)(unaff_EBP + -0xa4) = *(undefined4 *)(unaff_EBP + -0x118);
              uVar5 = FUN_004b46a0();
              *(undefined4 *)(unaff_EBP + -0x34c) = uVar5;
              *(int *)(unaff_EBP + -0x350) = *(int *)(unaff_EBP + -0x34c) + 0x7c;
              (**(code **)(**(int **)(unaff_EBP + -0xa4) + 0x60))
                        (**(undefined4 **)(unaff_EBP + -0x350),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x350) + 4),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x350) + 8),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x350) + 0xc));
              FUN_0057a14d(s_bkground_fade_006c3bcc);
              FUN_0057a14d(s_kill_all_objectsounds_006c3bb4);
              uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0xa4),1,0);
              *(undefined4 *)(unaff_EBP + -0xa0) = uVar5;
              FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0xa4));
              if ((*(uint *)(unaff_EBP + -0xa0) < 0x28) || (0x30 < *(uint *)(unaff_EBP + -0xa0))) {
                *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xec) = 0;
              }
              else {
                *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xec) =
                     *(undefined2 *)(unaff_EBP + -0xa0);
                *(undefined4 *)(unaff_EBP + -0x354) = *(undefined4 *)(DAT_006e486c + 0x1c);
                cVar1 = FUN_004074bc();
                if (cVar1 == '\x01') {
                  FUN_004fc4ab(2);
                }
                else {
                  FUN_004fc4ab(1);
                }
              }
            }
            else if (*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xee) < 0) {
              *(undefined1 *)(unaff_EBP + -0xac) = 0;
              if (((*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x10c) != 0) &&
                  (*(undefined2 *)(unaff_EBP + -0x360) =
                        *(undefined2 *)(*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x10c) + 0x62c),
                  0 < *(short *)(unaff_EBP + -0x360))) &&
                 (*(undefined2 *)(unaff_EBP + -0x364) =
                       *(undefined2 *)(*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x10c) + 0x5fc),
                 *(short *)(unaff_EBP + -0x364) == 0)) {
                *(undefined1 *)(unaff_EBP + -0xac) = 1;
              }
              pvVar4 = operator_new(0x478);
              *(void **)(unaff_EBP + -0x124) = pvVar4;
              *(undefined4 *)(unaff_EBP + -4) = 0xc;
              if (*(int *)(unaff_EBP + -0x124) == 0) {
                *(undefined4 *)(unaff_EBP + -0x40c) = 0;
              }
              else {
                uVar5 = FUN_00564664(0);
                *(undefined4 *)(unaff_EBP + -0x40c) = uVar5;
              }
              *(undefined4 *)(unaff_EBP + -0x120) = *(undefined4 *)(unaff_EBP + -0x40c);
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              *(undefined4 *)(unaff_EBP + -0xb0) = *(undefined4 *)(unaff_EBP + -0x120);
              *(undefined1 *)(*(int *)(unaff_EBP + -0xb0) + 0xe0) =
                   *(undefined1 *)(unaff_EBP + -0xac);
              uVar5 = FUN_004b46a0();
              *(undefined4 *)(unaff_EBP + -0x368) = uVar5;
              *(int *)(unaff_EBP + -0x36c) = *(int *)(unaff_EBP + -0x368) + 0x7c;
              (**(code **)(**(int **)(unaff_EBP + -0xb0) + 0x60))
                        (**(undefined4 **)(unaff_EBP + -0x36c),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x36c) + 4),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x36c) + 8),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x36c) + 0xc));
              FUN_0057a14d(s_bkground_fade_006c3bcc);
              FUN_0057a14d(s_kill_all_objectsounds_006c3bb4);
              uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0xb0),1,0);
              *(undefined4 *)(unaff_EBP + -0xa8) = uVar5;
              FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0xb0));
              if ((*(uint *)(unaff_EBP + -0xa8) < 0x51) || (0x59 < *(uint *)(unaff_EBP + -0xa8))) {
                *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xee) = 0;
              }
              else {
                *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xee) =
                     *(undefined2 *)(unaff_EBP + -0xa8);
                *(uint *)(unaff_EBP + -0xb4) = (*(char *)(unaff_EBP + -0xac) != '\0') + 4;
                FUN_004fc4ab(*(undefined4 *)(unaff_EBP + -0xb4));
                *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x10c) = 0;
              }
            }
            else if (*(short *)(*(int *)(unaff_EBP + -0x3dc) + 0xf0) < 0) {
              *(undefined1 *)(unaff_EBP + -0xbc) = 1;
              pvVar4 = operator_new(0x1f0);
              *(void **)(unaff_EBP + -300) = pvVar4;
              *(undefined4 *)(unaff_EBP + -4) = 0xd;
              if (*(int *)(unaff_EBP + -300) == 0) {
                *(undefined4 *)(unaff_EBP + -0x410) = 0;
              }
              else {
                uVar5 = FUN_00551513(0);
                *(undefined4 *)(unaff_EBP + -0x410) = uVar5;
              }
              *(undefined4 *)(unaff_EBP + -0x128) = *(undefined4 *)(unaff_EBP + -0x410);
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              *(undefined4 *)(unaff_EBP + -0xb8) = *(undefined4 *)(unaff_EBP + -0x128);
              *(undefined2 *)(unaff_EBP + -0x370) =
                   *(undefined2 *)(*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x7c) + 0x54);
              if (*(short *)(unaff_EBP + -0x370) == 0) {
                *(undefined1 *)(unaff_EBP + -0xbc) = 0;
              }
              *(undefined1 *)(*(int *)(unaff_EBP + -0xb8) + 0xec) =
                   *(undefined1 *)(unaff_EBP + -0xbc);
              uVar5 = FUN_004b46a0();
              *(undefined4 *)(unaff_EBP + -0x374) = uVar5;
              *(int *)(unaff_EBP + -0x378) = *(int *)(unaff_EBP + -0x374) + 0x7c;
              (**(code **)(**(int **)(unaff_EBP + -0xb8) + 0x60))
                        (**(undefined4 **)(unaff_EBP + -0x378),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x378) + 4),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x378) + 8),
                         *(undefined4 *)(*(int *)(unaff_EBP + -0x378) + 0xc));
              FUN_0057a14d(s_bkground_fade_006c3bcc);
              FUN_0057a14d(s_kill_all_objectsounds_006c3bb4);
              uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0xb8),1,0);
              *(undefined4 *)(unaff_EBP + -0xc0) = uVar5;
              FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0xb8));
              if ((*(uint *)(unaff_EBP + -0xc0) < 0x5a) || (0x62 < *(uint *)(unaff_EBP + -0xc0))) {
                *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf0) = 0;
              }
              else {
                *(uint *)(unaff_EBP + -0xc4) = 7 - (uint)(*(char *)(unaff_EBP + -0xbc) != '\0');
                *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf0) =
                     *(undefined2 *)(unaff_EBP + -0xc0);
                *(undefined4 *)(unaff_EBP + -200) = *(undefined4 *)(unaff_EBP + -0xc4);
                FUN_004fc4ab(*(undefined4 *)(unaff_EBP + -200));
              }
            }
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x330) = *(undefined4 *)(DAT_006e486c + 0x1c);
            uVar5 = FUN_0046d8a7();
            *(undefined4 *)(unaff_EBP + -0x9c) = uVar5;
            *(undefined4 *)(unaff_EBP + -0x338) = *(undefined4 *)(DAT_006e486c + 0x1c);
            uVar5 = FUN_004425e2();
            FUN_0046d7b3(uVar5);
            pvVar4 = operator_new(0x134);
            *(void **)(unaff_EBP + -0x114) = pvVar4;
            *(undefined4 *)(unaff_EBP + -4) = 10;
            if (*(int *)(unaff_EBP + -0x114) == 0) {
              *(undefined4 *)(unaff_EBP + -0x404) = 0;
            }
            else {
              uVar5 = FUN_00521882(*(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x104));
              *(undefined4 *)(unaff_EBP + -0x404) = uVar5;
            }
            *(undefined4 *)(unaff_EBP + -0x110) = *(undefined4 *)(unaff_EBP + -0x404);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(undefined4 *)(unaff_EBP + -0x84) = *(undefined4 *)(unaff_EBP + -0x110);
            uVar5 = FUN_004b46a0();
            *(undefined4 *)(unaff_EBP + -0x7c) = uVar5;
            *(int *)(unaff_EBP + -0x33c) = *(int *)(unaff_EBP + -0x7c) + 0x7c;
            *(undefined4 *)(unaff_EBP + -0x98) = **(undefined4 **)(unaff_EBP + -0x33c);
            *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(*(int *)(unaff_EBP + -0x33c) + 4);
            *(undefined4 *)(unaff_EBP + -0x90) = *(undefined4 *)(*(int *)(unaff_EBP + -0x33c) + 8);
            *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x33c) + 0xc)
            ;
            *(int *)(unaff_EBP + -0x340) = *(int *)(unaff_EBP + -0x7c) + 0x7c;
            *(int *)(unaff_EBP + -0x98) =
                 *(int *)(unaff_EBP + -0x98) +
                 ((*(int *)(*(int *)(unaff_EBP + -0x340) + 8) - **(int **)(unaff_EBP + -0x340)) +
                 -300) / 2;
            *(int *)(unaff_EBP + -0x90) = *(int *)(unaff_EBP + -0x98) + 300;
            *(int *)(unaff_EBP + -0x344) = *(int *)(unaff_EBP + -0x7c) + 0x7c;
            *(int *)(unaff_EBP + -0x94) =
                 *(int *)(unaff_EBP + -0x94) +
                 ((*(int *)(*(int *)(unaff_EBP + -0x344) + 0xc) -
                  *(int *)(*(int *)(unaff_EBP + -0x344) + 4)) + -300) / 2;
            *(int *)(unaff_EBP + -0x8c) = *(int *)(unaff_EBP + -0x94) + 300;
            (**(code **)(**(int **)(unaff_EBP + -0x84) + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x98),*(undefined4 *)(unaff_EBP + -0x94),
                       *(undefined4 *)(unaff_EBP + -0x90),*(undefined4 *)(unaff_EBP + -0x8c));
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf6) = 0;
            uVar5 = FUN_004f6c41(*(undefined4 *)(unaff_EBP + -0x84),1,0);
            *(undefined4 *)(unaff_EBP + -0x88) = uVar5;
            *(uint *)(unaff_EBP + -0x80) = *(uint *)(unaff_EBP + -0x88) & 0xffff0000;
            *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) >> 0x10;
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0x100) =
                 *(undefined2 *)(unaff_EBP + -0x80);
            *(uint *)(unaff_EBP + -0x80) = *(uint *)(unaff_EBP + -0x88) & 0xffff;
            *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0x108) =
                 *(undefined2 *)(unaff_EBP + -0x80);
            FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x84));
            *(undefined4 *)(unaff_EBP + -0x348) = *(undefined4 *)(DAT_006e486c + 0x1c);
            FUN_0046d7b3(*(undefined4 *)(unaff_EBP + -0x9c));
          }
        }
        if (*(char *)(unaff_EBP + 8) == '\0') {
          while( true ) {
            *(int *)(unaff_EBP + -900) = *(int *)(unaff_EBP + -0x3dc) + 0x58;
            *(undefined4 *)(unaff_EBP + -0x37c) = *(undefined4 *)(*(int *)(unaff_EBP + -900) + 4);
            *(undefined4 *)(unaff_EBP + -0x380) = **(undefined4 **)(unaff_EBP + -900);
            if (*(int *)(unaff_EBP + -0x37c) - *(int *)(unaff_EBP + -0x380) >> 1 == 0) break;
            *(undefined4 *)(unaff_EBP + -0x388) =
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x58);
            *(undefined2 *)(unaff_EBP + -0xcc) = **(undefined2 **)(unaff_EBP + -0x388);
            *(undefined4 *)(unaff_EBP + -0x38c) =
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x58);
            FUN_004484c8(*(undefined4 *)(unaff_EBP + -0x38c));
            *(int *)(unaff_EBP + -0x3c4) = (int)*(short *)(unaff_EBP + -0xcc);
            *(undefined4 *)(unaff_EBP + -0x3b0) = 0;
            if (0 < *(int *)(unaff_EBP + -0x3c4)) {
              *(int *)(unaff_EBP + -0x3bc) = *(int *)(unaff_EBP + -0x3dc) + 0x18;
              *(undefined4 *)(unaff_EBP + -0x3b4) =
                   *(undefined4 *)(*(int *)(unaff_EBP + -0x3bc) + 4);
              *(undefined4 *)(unaff_EBP + -0x3b8) = **(undefined4 **)(unaff_EBP + -0x3bc);
              if (*(uint *)(unaff_EBP + -0x3c4) <
                  (*(int *)(unaff_EBP + -0x3b4) - *(int *)(unaff_EBP + -0x3b8) >> 2) + 1U) {
                *(undefined4 *)(unaff_EBP + -0x3c0) =
                     *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x18);
                *(undefined4 *)(unaff_EBP + -0x3b0) =
                     *(undefined4 *)
                      (*(int *)(unaff_EBP + -0x3c0) + -4 + *(int *)(unaff_EBP + -0x3c4) * 4);
              }
            }
            *(undefined4 *)(unaff_EBP + -0xd0) = *(undefined4 *)(unaff_EBP + -0x3b0);
            if (*(int *)(unaff_EBP + -0xd0) != 0) {
              if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0xd0) + 0x118) + 0x14) != 0) {
                uVar5 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0xd0),0,
                                     &cXObject::RTTI_Type_Descriptor,
                                     &cXMTObject::RTTI_Type_Descriptor,0);
                *(undefined4 *)(unaff_EBP + -0xd4) = uVar5;
                if ((*(int *)(unaff_EBP + -0xd4) != 0) && (cVar1 = FUN_00423481(), cVar1 != '\0')) {
                  FUN_0042349d();
                }
              }
              FUN_0044127f(*(undefined4 *)(unaff_EBP + -0xcc));
            }
          }
          if ((*(char *)(*(int *)(unaff_EBP + -0x3dc) + 0x12) != '\0') &&
             (*(undefined4 *)(unaff_EBP + -0x3c8) =
                   *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x7c) + 0x98),
             *(int *)(unaff_EBP + -0x3c8) % 0x28 == 0)) {
            *(undefined4 *)(unaff_EBP + -0x3cc) = *(undefined4 *)(DAT_006e486c + 0x24);
            FUN_0042004f();
            *(undefined1 *)(*(int *)(unaff_EBP + -0x3dc) + 0x12) = 0;
          }
        }
        uVar5 = FUN_00445724();
        *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
        if (*(int *)(unaff_EBP + -0x14) == 0) {
          FUN_00445541();
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x3d0) = *(undefined4 *)(DAT_006e486c + 0x1c);
          cVar1 = FUN_004074bc();
          if (((cVar1 == '\x01') && (DAT_006e4f14 == 0)) &&
             (*(short *)(*(int *)(unaff_EBP + -0x14) + 0x5cc) != 0)) {
            FUN_00445541();
          }
        }
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return *(undefined1 *)(unaff_EBP + -0x1c);
      }
      *(undefined4 *)(unaff_EBP + -0x20) = **(undefined4 **)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x134) = *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0x74);
      if (*(int *)(unaff_EBP + -0x134) == 0) {
        cVar1 = FUN_00436e45();
        if (cVar1 != '\0') {
          *(undefined1 *)(unaff_EBP + -0x1c) = 1;
        }
        goto LAB_00441332;
      }
      *(undefined4 *)(unaff_EBP + -0x138) = *(undefined4 *)(**(int **)(unaff_EBP + -0x18) + 0x74);
      if (*(int *)(unaff_EBP + -0x138) == 5) break;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
    }
    *(undefined4 *)(unaff_EBP + -0xdc) = **(undefined4 **)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0xd8) = *(undefined4 *)(unaff_EBP + -0xdc);
    if (*(int *)(unaff_EBP + -0xd8) == 0) {
      *(undefined4 *)(unaff_EBP + -0x3e0) = 0;
    }
    else {
      FUN_00435f6d();
      FUN_006321f0(*(undefined4 *)(unaff_EBP + -0xd8));
      *(undefined4 *)(unaff_EBP + -0x3e0) = *(undefined4 *)(unaff_EBP + -0xd8);
    }
    FUN_004486a3(*(undefined4 *)(unaff_EBP + -0x18));
  } while( true );
}

