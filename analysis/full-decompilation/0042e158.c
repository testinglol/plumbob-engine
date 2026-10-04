
short * FUN_0042e158(void)

{
  short sVar1;
  short *psVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  void *pvVar9;
  int *piVar10;
  int iVar11;
  TypeDescriptor *pTVar12;
  int *piVar13;
  int extraout_ECX;
  uint uVar14;
  byte bVar15;
  TypeDescriptor *pTVar16;
  int unaff_EBP;
  short *psVar17;
  TypeDescriptor *pTStack_774;
  TypeDescriptor *pTStack_770;
  TypeDescriptor *pTStack_76c;
  TypeDescriptor *pTStack_768;
  undefined2 uVar18;
  
  FUN_00634c24();
  psVar2 = *(short **)(unaff_EBP + 8);
  uVar8 = *(undefined4 *)(*DAT_006e486c + 0x14);
  uVar3 = *(undefined4 *)(psVar2 + 4);
  pTStack_768 = &cXPerson::RTTI_Type_Descriptor;
  pTStack_76c = &cXObject::RTTI_Type_Descriptor;
  pTStack_770 = (TypeDescriptor *)0x0;
  *(int *)(unaff_EBP + -0x40) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar8;
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar3;
  pTStack_774 = (TypeDescriptor *)0x42e19b;
  pTStack_774 = (TypeDescriptor *)FUN_00401f73();
  pTStack_774 = (TypeDescriptor *)FUN_00440914();
  iVar7 = FUN_006359f2();
  *(int *)(unaff_EBP + -0x3c) = iVar7;
  if (iVar7 != 0) {
    pTStack_768 = (TypeDescriptor *)0x42e1bb;
    FUN_00425ab3();
  }
  FUN_0045741b();
  pTStack_768 = (TypeDescriptor *)0x42e1c9;
  FUN_0042dea1();
  *(int *)(unaff_EBP + -0x14) = DAT_006e486c[10];
  pTStack_768 = (TypeDescriptor *)0x42e1fe;
  iVar7 = FUN_00425769();
  if ((iVar7 != 0) && (*(undefined4 **)(iVar7 + 8) != (undefined4 *)0x0)) {
    *(undefined4 *)(unaff_EBP + -0x34) = **(undefined4 **)(iVar7 + 8);
    pTStack_76c = (TypeDescriptor *)(unaff_EBP + -0x2d4);
    pTStack_768 = (TypeDescriptor *)0x0;
    *(undefined4 *)(unaff_EBP + 8) = 0xffffffd5;
    pTStack_770 = (TypeDescriptor *)0x42e236;
    FUN_0046f824();
    iVar7 = *(int *)(extraout_ECX + 0x160);
    *(undefined ***)(unaff_EBP + -0x2e0) = &PTR_FUN_006664e8;
    if (iVar7 < 32000) {
      do {
        if (*(int *)(unaff_EBP + 8) != -0x2b) break;
        pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0x3e0);
        pTStack_76c = (TypeDescriptor *)0x42e272;
        FUN_0046fb9b();
        *(undefined ***)(unaff_EBP + -0x3ec) = &PTR_LAB_0066655c;
        pTStack_768 = (TypeDescriptor *)s_User_05d_006c2650;
        pTStack_76c = *(TypeDescriptor **)(unaff_EBP + -1000);
        pTStack_770 = (TypeDescriptor *)0x42e292;
        FUN_00635858();
        pTStack_76c = (TypeDescriptor *)(unaff_EBP + -0x4ec);
        pTStack_768 = (TypeDescriptor *)0x0;
        pTStack_770 = (TypeDescriptor *)0x42e2aa;
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x4f8) = &PTR_FUN_00666524;
        pTStack_768 = (TypeDescriptor *)0x42e2c6;
        FUN_0046f8e4();
        pTStack_768 = (TypeDescriptor *)&DAT_006c2648;
        pTStack_76c = (TypeDescriptor *)0x42e2d8;
        FUN_0046f847();
        pTStack_76c = (TypeDescriptor *)0x42e2e5;
        FUN_00412122();
        pTStack_768 = (TypeDescriptor *)s_Characters__006c1d48;
        pTStack_76c = (TypeDescriptor *)0x42e2f9;
        FUN_0046f847();
        pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0x4f8);
        pTStack_76c = (TypeDescriptor *)0x42e30d;
        FUN_0046f917();
        pTStack_76c = (TypeDescriptor *)(unaff_EBP + -0x1c0);
        pTStack_768 = (TypeDescriptor *)0x0;
        pTStack_770 = (TypeDescriptor *)0x42e322;
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x1cc) = &PTR_FUN_00666524;
        pTStack_768 = (TypeDescriptor *)0x42e33e;
        FUN_0046f8e4();
        pTStack_768 = (TypeDescriptor *)0x42e34b;
        FUN_0046fa24();
        FUN_0047234b();
        pTStack_768 = (TypeDescriptor *)0x42e368;
        FUN_0047239b();
        pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x34);
        pTStack_76c = (TypeDescriptor *)0x42e37d;
        uVar8 = FUN_004723b0();
        *(int *)(extraout_ECX + 0x160) = *(int *)(extraout_ECX + 0x160) + 1;
        iVar7 = *(int *)(extraout_ECX + 0x160);
        *(undefined4 *)(unaff_EBP + 8) = uVar8;
      } while (iVar7 < 32000);
      if (31999 < *(int *)(extraout_ECX + 0x160)) goto LAB_0042e3a2;
    }
    else {
LAB_0042e3a2:
      *(undefined4 *)(extraout_ECX + 0x160) = 0;
    }
    if (*(int *)(unaff_EBP + 8) == 0) {
      pTStack_768 = (TypeDescriptor *)0x42e3c2;
      FUN_0043c422();
      psVar17 = (short *)0x0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      pTStack_768 = (TypeDescriptor *)0x42e3d0;
      iVar7 = FUN_0043ad1f();
      *(int *)(unaff_EBP + -0x28) = iVar7;
      if (iVar7 != 0) {
        do {
          if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0x28) + 0x60) + 0x12) == 2) {
            piVar10 = *(int **)(extraout_ECX + 0x148);
            *(undefined4 *)(unaff_EBP + 8) = 0;
            if (piVar10 != *(int **)(extraout_ECX + 0x14c)) {
              do {
                iVar7 = *piVar10;
                if (((iVar7 != 0) && (*(int *)(iVar7 + 8) == *(int *)(unaff_EBP + -0x28))) &&
                   (*(int *)(unaff_EBP + 8) == 0)) {
                  *(int *)(unaff_EBP + 8) = iVar7;
                }
                piVar10 = piVar10 + 1;
              } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
              if (*(int *)(unaff_EBP + 8) != 0) goto LAB_0042e450;
            }
            if (psVar17 == (short *)0x0) {
              uVar18 = 0;
              pTStack_768 = (TypeDescriptor *)0x42e42d;
              pvVar9 = operator_new(0x274);
              *(void **)(unaff_EBP + 8) = pvVar9;
              *(undefined4 *)(unaff_EBP + -4) = 0;
              if (pvVar9 == (void *)0x0) {
                psVar17 = (short *)0x0;
              }
              else {
                pTStack_768 = (TypeDescriptor *)CONCAT22(uVar18,*psVar2);
                pTStack_76c = (TypeDescriptor *)0x42e446;
                psVar17 = (short *)FUN_004237d4();
              }
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
          }
LAB_0042e450:
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
          pTStack_768 = (TypeDescriptor *)0x42e45e;
          iVar7 = FUN_0043ad1f();
          *(int *)(unaff_EBP + -0x28) = iVar7;
        } while (iVar7 != 0);
        if (psVar17 != (short *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(psVar17 + 4);
          pTStack_768 = (TypeDescriptor *)0x42e47f;
          piVar10 = (int *)FUN_0042385a();
          *(int **)(unaff_EBP + -0x68) = piVar10;
          *(undefined4 *)(unaff_EBP + -100) = 0;
          *(undefined4 *)(unaff_EBP + -0x60) = 0;
          *(undefined4 *)(unaff_EBP + -0x5c) = 0;
          iVar7 = *piVar10;
          iVar11 = piVar10[1];
          *(undefined4 *)(unaff_EBP + -4) = 1;
          *(int *)(unaff_EBP + 8) = iVar7;
          if (iVar7 != iVar11) {
            do {
              pTStack_768 = (TypeDescriptor *)0x42e4b7;
              FUN_004029df();
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 8;
            } while (*(int *)(unaff_EBP + 8) != piVar10[1]);
          }
          thunk_FUN_00457ea7();
          pTStack_768 = (TypeDescriptor *)0x42e4d4;
          FUN_005b86bd();
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_0045754a();
          pTStack_768 = (TypeDescriptor *)0x42e4e9;
          FUN_005b86bd();
          sVar6 = psVar2[0x7b];
          sVar1 = psVar2[0x76];
          *(int *)(unaff_EBP + -0x20) = (int)sVar6;
          *(int *)(unaff_EBP + -0x1c) = (int)sVar1;
          bVar15 = ~(byte)sVar6 & 1;
          *(undefined4 *)(unaff_EBP + -0x4c) = 0;
          *(undefined4 *)(unaff_EBP + -0x48) = 0;
          *(undefined4 *)(unaff_EBP + -0x44) = 0;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          iVar7 = FUN_004652f7();
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          *(int *)(unaff_EBP + -0x38) = iVar7;
          if (0 < iVar7) {
            do {
              pTStack_768 = (TypeDescriptor *)0x42e52f;
              uVar8 = FUN_00465300();
              *(undefined4 *)(unaff_EBP + -0x18) = uVar8;
              pTStack_768 = (TypeDescriptor *)0x42e53b;
              uVar8 = FUN_00465062();
              pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x18);
              *(undefined4 *)(unaff_EBP + -0x24) = uVar8;
              pTStack_76c = (TypeDescriptor *)0x42e54a;
              FUN_004650d0();
              *(undefined4 *)(unaff_EBP + 8) = 0;
              if (0 < *(int *)(unaff_EBP + -0x24)) {
                do {
                  pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x18);
                  pTStack_76c = (TypeDescriptor *)0x42e562;
                  FUN_0046518a();
                  pTStack_768 = *(TypeDescriptor **)(unaff_EBP + 8);
                  pTStack_76c = *(TypeDescriptor **)(unaff_EBP + -0x18);
                  pTStack_770 = (TypeDescriptor *)0x42e571;
                  FUN_004651b1();
                  *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x24));
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x38));
          }
          uVar8 = FUN_00401f73();
          *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
          *(undefined1 *)(unaff_EBP + 0xb) = 0;
          *(undefined4 *)(unaff_EBP + -0x58) = 0;
          *(undefined4 *)(unaff_EBP + -0x54) = 0;
          *(undefined4 *)(unaff_EBP + -0x34) = 0;
          *(undefined4 *)(unaff_EBP + -0x50) = 0;
          if (*(int *)(unaff_EBP + -0x3c) != 0) {
            iVar7 = *(int *)(unaff_EBP + -0x3c);
            *(undefined1 *)(unaff_EBP + 0xb) = 1;
            *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(iVar7 + 0xf4);
            *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar7 + 0xf8);
            uVar18 = *(undefined2 *)(iVar7 + 0x4c);
            *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar7 + 0x110);
            *(undefined2 *)(unaff_EBP + -0x50) = uVar18;
          }
          while( true ) {
            pTStack_768 = (TypeDescriptor *)0x42e5dc;
            iVar7 = FUN_00440914();
            *(int *)(unaff_EBP + -0x18) = iVar7;
            if (iVar7 == 0) break;
            pTStack_76c = (TypeDescriptor *)(int)*(short *)(iVar7 + 0xf0);
            pTStack_768 = (TypeDescriptor *)0x1;
            pTStack_770 = (TypeDescriptor *)0x42e5f7;
            FUN_0044582f();
            pTStack_768 = (TypeDescriptor *)0x42e60d;
            FUN_0044127f();
          }
          pTStack_76c = (TypeDescriptor *)(unaff_EBP + -0x1c4);
          pTStack_768 = (TypeDescriptor *)0x0;
          pTStack_770 = (TypeDescriptor *)0x42e628;
          FUN_0046f824();
          *(undefined ***)(unaff_EBP + -0x1d0) = &PTR_FUN_006664e8;
          pTStack_768 = (TypeDescriptor *)0x42e643;
          (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x2c) + 0x24))();
          pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x2c);
          pTStack_76c = (TypeDescriptor *)0x42e653;
          cVar5 = FUN_0043caba();
          if (cVar5 != '\0') {
            iVar7 = *(int *)(*(int *)(unaff_EBP + -0x40) + 0x148);
            if (*(short **)(iVar7 + -4 + *psVar2 * 4) == psVar2) {
              *(undefined4 *)(iVar7 + -4 + *psVar2 * 4) = 0;
            }
            if (psVar2 != (short *)0x0) {
              pTStack_768 = (TypeDescriptor *)0x42e6b6;
              FUN_00423852();
              pTStack_76c = (TypeDescriptor *)0x42e6bc;
              pTStack_768 = (TypeDescriptor *)psVar2;
              FUN_006321f0();
            }
            pTStack_768 = (TypeDescriptor *)0x42e6c8;
            FUN_004567a6();
            pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0x1d0);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            pTStack_76c = (TypeDescriptor *)0x42e6de;
            FUN_0046b546();
            *(undefined1 *)(unaff_EBP + -4) = 4;
            pTStack_768 = (TypeDescriptor *)0x42e6ed;
            FUN_0045685f();
            pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x10);
            puVar4 = *(undefined4 **)(unaff_EBP + -0x28);
            pTStack_76c = *(TypeDescriptor **)(psVar17 + 2);
            *(TypeDescriptor **)(psVar17 + 2) = pTStack_768;
            *(TypeDescriptor **)(puVar4[0x18] + 0x1c) = pTStack_768;
            pTStack_774 = (TypeDescriptor *)0x42e70a;
            pTStack_770 = (TypeDescriptor *)puVar4;
            FUN_0043cb5d();
            pTStack_768 = (TypeDescriptor *)0x42e711;
            FUN_004574bb();
            pTStack_768 = (TypeDescriptor *)0x42e718;
            (**(code **)(*(int *)*puVar4 + 0x10))();
            pTStack_768 = (TypeDescriptor *)0x42e71f;
            (**(code **)(*(int *)*puVar4 + 0x14))();
            iVar7 = *(int *)(*(int *)(unaff_EBP + -0x40) + 0x148);
            if (*(short **)(iVar7 + -4 + *psVar17 * 4) != psVar17) {
              *(short **)(iVar7 + -4 + *psVar17 * 4) = psVar17;
            }
            pTStack_768 = (TypeDescriptor *)&DAT_006c100c;
            pTStack_76c = (TypeDescriptor *)0x42e74b;
            FUN_0040bfed();
            iVar7 = *(int *)(unaff_EBP + 0xc);
            if (iVar7 == 0) {
              iVar7 = *(int *)(unaff_EBP + -0x1c);
              *(uint *)(unaff_EBP + -0x20) = *(uint *)(unaff_EBP + -0x20) & 1;
              *(uint *)(unaff_EBP + -0x18) = (uint)(bVar15 == 0);
              if ((iVar7 < 1) || (3 < iVar7)) {
                pTStack_768 = (TypeDescriptor *)0x3;
                pTStack_76c = (TypeDescriptor *)0x42e7c0;
                iVar7 = FUN_005bc722();
                iVar7 = iVar7 + 1;
                *(int *)(unaff_EBP + -0x1c) = iVar7;
              }
              *(uint *)(unaff_EBP + -0x14) = (uint)(*(int *)(unaff_EBP + 0x10) < 0x1b);
            }
            else {
              if (iVar7 == 1) {
                *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                *(uint *)(unaff_EBP + -0x18) = 3 - (uint)(bVar15 != 0);
                iVar11 = (*(uint *)(unaff_EBP + -0x20) & 1) + 2;
              }
              else {
                if (iVar7 != 2) {
                  iVar7 = *(int *)(unaff_EBP + -0x1c);
                  goto LAB_0042e7d7;
                }
                *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                *(uint *)(unaff_EBP + -0x18) = 5 - (uint)(bVar15 != 0);
                iVar11 = (*(uint *)(unaff_EBP + -0x20) & 1) + 4;
              }
              iVar7 = 0;
              *(int *)(unaff_EBP + -0x20) = iVar11;
              *(undefined4 *)(unaff_EBP + 0x10) = 0x1b;
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
            }
LAB_0042e7d7:
            if (iVar7 == 1) {
              pTStack_768 = (TypeDescriptor *)&DAT_006c1010;
              pTStack_76c = (TypeDescriptor *)0x42e822;
              FUN_0040bfed();
              pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0xa0);
LAB_0042e828:
              pTStack_76c = (TypeDescriptor *)0x42e834;
              FUN_0046f8e4();
            }
            else {
              if (iVar7 == 2) {
                pTStack_768 = (TypeDescriptor *)&DAT_006c1008;
                pTStack_76c = (TypeDescriptor *)0x42e80a;
                FUN_0040bfed();
                pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0xc0);
                goto LAB_0042e828;
              }
              if (iVar7 == 3) {
                pTStack_768 = (TypeDescriptor *)&DAT_006c100c;
                pTStack_76c = (TypeDescriptor *)0x42e7f2;
                FUN_0040bfed();
                pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0xb0);
                goto LAB_0042e828;
              }
            }
            pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x10);
            psVar17[0x7b] = *(short *)(unaff_EBP + -0x20);
            sVar6 = *(short *)(unaff_EBP + 0x10);
            psVar17[0x76] = (short)iVar7;
            psVar17[0x74] = sVar6;
            pTStack_76c = (TypeDescriptor *)0x42e859;
            pTVar12 = (TypeDescriptor *)FUN_004e988f();
            pTStack_76c = (TypeDescriptor *)0x1;
            pTStack_774 = (TypeDescriptor *)0x42e863;
            pTStack_770 = pTVar12;
            FUN_004ea53c();
            pTStack_774 = *(TypeDescriptor **)(unaff_EBP + -0x18);
            FUN_004eabf6(pTVar12);
            if (0 < iVar7) {
              *(TypeDescriptor ***)(unaff_EBP + -0x24) = &pTStack_774;
              *(TypeDescriptor ***)(unaff_EBP + -0x24) = &pTStack_774;
              FUN_0040f4b7(unaff_EBP + -0x90);
              **(undefined4 **)(unaff_EBP + -0x24) = &PTR_FUN_00666634;
              FUN_004eac8c(pTVar12);
            }
            if (*(int *)(unaff_EBP + -0x20) < 2) {
              pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x14);
              pTStack_770 = (TypeDescriptor *)0x42e8ab;
              pTStack_76c = pTVar12;
              FUN_004eaa9b();
            }
            pTStack_76c = (TypeDescriptor *)0x42e8b3;
            pTStack_768 = pTVar12;
            uVar8 = FUN_004eacb7();
            *(undefined4 *)(unaff_EBP + -0x24) = uVar8;
            iVar11 = *(int *)(unaff_EBP + 0xc);
            if (iVar11 == 0) {
              pTStack_76c = (TypeDescriptor *)0x42e8d1;
              pTStack_768 = pTVar12;
              uVar8 = FUN_004ead68();
              *(undefined4 *)(unaff_EBP + -0x14) = uVar8;
            }
            else if ((iVar11 == 1) || (iVar11 == 2)) {
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
            }
            if (0 < *(int *)(unaff_EBP + -0x24)) {
              pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x24);
              pTStack_76c = (TypeDescriptor *)0x42e8e8;
              pTStack_768 = (TypeDescriptor *)FUN_005bc722();
              pTStack_770 = (TypeDescriptor *)0x42e8ef;
              pTStack_76c = pTVar12;
              FUN_004eacf0();
            }
            if (0 < *(int *)(unaff_EBP + -0x14)) {
              pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x14);
              pTStack_76c = (TypeDescriptor *)0x42e904;
              pTStack_768 = (TypeDescriptor *)FUN_005bc722();
              pTStack_770 = (TypeDescriptor *)0x42e90b;
              pTStack_76c = pTVar12;
              FUN_004eada1();
            }
            if (*(int *)(unaff_EBP + 0xc) == 0) {
              pTStack_76c = (TypeDescriptor *)0x42e919;
              pTStack_768 = pTVar12;
              FUN_004eadc1();
            }
            pTStack_768 = (TypeDescriptor *)(unaff_EBP + -0x74);
            pTStack_770 = (TypeDescriptor *)0x42e924;
            pTStack_76c = pTVar12;
            FUN_004e9a99();
            pTStack_770 = (TypeDescriptor *)(unaff_EBP + -0x80);
            pTStack_774 = pTVar12;
            FUN_004e9b56();
            FUN_004ea674(pTVar12,1,1,0);
            puVar4 = *(undefined4 **)(unaff_EBP + -0x28);
            pTStack_768 = (TypeDescriptor *)0x42e947;
            (**(code **)(*(int *)*puVar4 + 0x10))();
            pTStack_768 = (TypeDescriptor *)0x42e94e;
            (**(code **)(*(int *)*puVar4 + 0x14))();
            piVar10 = *(int **)(unaff_EBP + -0x68);
            piVar13 = (int *)*piVar10;
            if (piVar13 != (int *)piVar10[1]) {
              iVar7 = 0;
              do {
                iVar11 = *piVar13;
                piVar13 = piVar13 + 2;
                psVar17[iVar11 + 0x3a] = *(short *)(iVar7 + *(int *)(unaff_EBP + -100));
                iVar7 = iVar7 + 2;
              } while (piVar13 != (int *)piVar10[1]);
              iVar7 = *(int *)(unaff_EBP + -0x1c);
            }
            iVar11 = *(int *)(unaff_EBP + -0x38);
            psVar17[0x7b] = *(short *)(unaff_EBP + -0x20);
            sVar6 = *(short *)(unaff_EBP + 0x10);
            psVar17[0x76] = (short)iVar7;
            psVar17[0x74] = sVar6;
            psVar17[0x72] = 0;
            psVar17[0x73] = 0;
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            if (0 < iVar11) {
              do {
                pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x10);
                pTStack_76c = (TypeDescriptor *)0x42e9b5;
                pTVar12 = (TypeDescriptor *)FUN_00465300();
                pTStack_76c = (TypeDescriptor *)0x42e9c0;
                pTStack_768 = pTVar12;
                pTStack_768 = (TypeDescriptor *)FUN_00465062();
                *(TypeDescriptor **)(unaff_EBP + 0x10) = pTStack_768;
                pTStack_770 = (TypeDescriptor *)0x42e9cd;
                pTStack_76c = pTVar12;
                FUN_004650d0();
                pTVar16 = (TypeDescriptor *)0x0;
                if (0 < *(int *)(unaff_EBP + 0x10)) {
                  do {
                    pTStack_770 = (TypeDescriptor *)0x42e9de;
                    pTStack_76c = pTVar12;
                    pTStack_768 = pTVar16;
                    pTStack_768 = (TypeDescriptor *)FUN_0046518a();
                    pTStack_774 = (TypeDescriptor *)0x42e9e9;
                    pTStack_770 = pTVar12;
                    pTStack_76c = pTVar16;
                    FUN_004651b1();
                    pTVar16 = (TypeDescriptor *)((int)&pTVar16->pVFTable + 1);
                  } while ((int)pTVar16 < *(int *)(unaff_EBP + 0x10));
                }
                *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x38));
            }
            if (*(int *)(unaff_EBP + -0x3c) != 0) {
              iVar7 = *(int *)(unaff_EBP + -0x30);
              pTStack_768 = *(TypeDescriptor **)(unaff_EBP + -0x28);
              pTStack_76c = (TypeDescriptor *)0x42ea0e;
              sVar6 = FUN_00440b6d();
              uVar14 = (uint)sVar6;
              uVar8 = 0;
              if ((0 < (int)uVar14) &&
                 (uVar14 < (*(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2) + 1U)) {
                uVar8 = *(undefined4 *)(*(int *)(iVar7 + 0x18) + -4 + uVar14 * 4);
              }
              pTStack_768 = (TypeDescriptor *)0x0;
              pTStack_76c = &cXPerson::RTTI_Type_Descriptor;
              pTStack_770 = &cXObject::RTTI_Type_Descriptor;
              pTStack_774 = (TypeDescriptor *)0x0;
              pTStack_768 = (TypeDescriptor *)FUN_006359f2(uVar8);
              pTStack_76c = (TypeDescriptor *)0x42ea4c;
              FUN_0042597a();
              if (*(char *)(unaff_EBP + 0xb) != '\0') {
                pTStack_76c = (TypeDescriptor *)(int)*(short *)(unaff_EBP + -0x50);
                pTStack_768 = (TypeDescriptor *)0x0;
                pTStack_770 = (TypeDescriptor *)0x1;
                pTStack_774 = (TypeDescriptor *)0x0;
                FUN_004550e0(*(undefined4 *)(unaff_EBP + -0x58),*(undefined4 *)(unaff_EBP + -0x54),
                             *(undefined4 *)(unaff_EBP + -0x34),0);
              }
            }
            *(undefined1 *)(unaff_EBP + -4) = 3;
            pTStack_768 = (TypeDescriptor *)0x42ea78;
            FUN_004652c0();
            *(undefined1 *)(unaff_EBP + -4) = 2;
            pTStack_768 = (TypeDescriptor *)0x42ea84;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 1;
            pTStack_768 = (TypeDescriptor *)0x42ea90;
            FUN_005b8770();
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            pTStack_768 = (TypeDescriptor *)0x42ea9c;
            FUN_004d4185();
            goto LAB_0042ea9e;
          }
          *(undefined1 *)(unaff_EBP + -4) = 3;
          pTStack_768 = (TypeDescriptor *)0x42e663;
          FUN_004652c0();
          *(undefined1 *)(unaff_EBP + -4) = 2;
          pTStack_768 = (TypeDescriptor *)0x42e66f;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          pTStack_768 = (TypeDescriptor *)0x42e67b;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          pTStack_768 = (TypeDescriptor *)0x42e687;
          FUN_004d4185();
        }
      }
    }
  }
  psVar17 = (short *)0x0;
LAB_0042ea9e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return psVar17;
}

