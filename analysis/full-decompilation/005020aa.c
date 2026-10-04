
undefined1 FUN_005020aa(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int *extraout_ECX;
  int iVar10;
  int iVar11;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    cVar2 = FUN_005dbf32();
    uVar3 = 0;
    if (cVar2 != '\0') {
      FUN_0041654e();
      iVar11 = 0;
      (**(code **)(*extraout_ECX + 0x174))(1,0);
      FUN_005a5631(0xbc0,extraout_ECX + 0x35,4);
      FUN_004cb1a2(100,100);
      piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      iVar5 = (**(code **)(*piVar4 + 0x10))(1,0x14,0,0);
      extraout_ECX[0x4f] = iVar5;
      pvVar6 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x18) = pvVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar6 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x36] = iVar5;
      if (iVar5 != 0) {
        FUN_005a5631(0x1366,unaff_EBP + -0x14,4);
        (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x36] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
        *(undefined1 *)(extraout_ECX[0x36] + 0x16b) = 1;
        iVar5 = extraout_ECX[0x36];
        FUN_004cb21d((((extraout_ECX[0x21] - *(int *)(iVar5 + 0x84)) - extraout_ECX[0x1f]) +
                     *(int *)(iVar5 + 0x7c)) / 2,
                     ((extraout_ECX[0x22] - extraout_ECX[0x20]) - *(int *)(iVar5 + 0x88)) +
                     *(int *)(iVar5 + 0x80));
        FUN_005e4071(extraout_ECX[0x4f]);
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = 2;
        *(undefined4 *)(unaff_EBP + -0x3c) = 2;
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        FUN_005e4104(unaff_EBP + -0x48);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x36]);
      }
      iVar5 = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0x37;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      do {
        pvVar6 = operator_new(0x128);
        *(void **)(unaff_EBP + -0x18) = pvVar6;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar6 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_00502d73();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        **(int **)(unaff_EBP + -0x10) = iVar7;
        if (iVar7 != 0) {
          (**(code **)(*extraout_ECX + 0x20))(iVar7);
          FUN_005031d5(*(undefined4 *)(&DAT_006cc300 + *(int *)(unaff_EBP + -0x14)));
          FUN_004cb1a2(0x1cc,0);
          FUN_005031b0(**(undefined4 **)((int)&PTR_DAT_006cc2b0 + *(int *)(unaff_EBP + -0x14)));
          iVar7 = *(int *)(**(int **)(unaff_EBP + -0x10) + 0x88) -
                  *(int *)(**(int **)(unaff_EBP + -0x10) + 0x80);
          piVar4 = (int *)(unaff_EBP + -0x18);
          *(int *)(unaff_EBP + -0x18) = iVar7;
          if (iVar7 <= iVar5) {
            piVar4 = (int *)(unaff_EBP + -0x28);
          }
          iVar5 = *piVar4;
          *(int *)(unaff_EBP + -0x28) = iVar5;
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
      } while (*(int *)(unaff_EBP + -0x14) < 0x50);
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x140) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      uVar8 = FUN_0041532c(9,unaff_EBP + -0x140,0);
      cVar2 = FUN_004fff98(0x92,uVar8);
      if (cVar2 != '\0') {
        FUN_00471655(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        uVar8 = FUN_0046fc7a();
        piVar4 = (int *)FUN_00500249(unaff_EBP + -0x50,uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        extraout_ECX[0x4b] = *piVar4;
        extraout_ECX[0x4c] = piVar4[1];
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        uVar8 = FUN_0046fc7a();
        piVar4 = (int *)FUN_00500249(unaff_EBP + -0x50,uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        extraout_ECX[0x4d] = *piVar4;
        extraout_ECX[0x4e] = piVar4[1];
        FUN_0042004f();
        *(undefined4 *)(unaff_EBP + -0xa8) = 1;
        iVar7 = extraout_ECX[0x4c];
        iVar10 = extraout_ECX[0x4b];
        *(int *)(unaff_EBP + -0x2c) = iVar5 * 0x14 + iVar7;
        *(int *)(unaff_EBP + -200) = extraout_ECX[0x4b];
        *(undefined4 *)(unaff_EBP + -0xb4) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(int *)(unaff_EBP + -0xc4) = iVar7;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        *(int *)(unaff_EBP + -0xb8) = iVar10 + 400;
        *(undefined4 *)(unaff_EBP + -0xc0) = 0;
        *(int *)(unaff_EBP + -0xbc) = iVar5;
        *(undefined4 *)(unaff_EBP + -0xb0) = 400;
        *(int *)(unaff_EBP + -0xac) = iVar5;
        FUN_004ebf01(extraout_ECX + 0x37,0x14);
        piVar4 = extraout_ECX + 0x38;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        *(undefined4 *)(unaff_EBP + -0x28) = 0x13;
        *(int **)(unaff_EBP + -0x14) = piVar4;
        while( true ) {
          FUN_004cb21d(*(undefined4 *)(piVar4[-1] + 0x7c),*(undefined4 *)(piVar4[-1] + 0x88));
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
          piVar4 = (int *)(unaff_EBP + -0x28);
          *piVar4 = *piVar4 + -1;
          if (*piVar4 == 0) break;
          piVar4 = *(int **)(unaff_EBP + -0x14);
        }
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        piVar4 = (int *)extraout_ECX[0x36];
        *(undefined1 *)(unaff_EBP + -4) = 8;
        (**(code **)(*piVar4 + 0x9c))(unaff_EBP + -0x54);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        piVar4 = (int *)extraout_ECX[0x37];
        *(undefined1 *)(unaff_EBP + -4) = 10;
        (**(code **)(*piVar4 + 0x9c))(unaff_EBP + -0x54);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined1 *)(extraout_ECX[0x37] + 0x10c) = 1;
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        uVar8 = FUN_0046fc7a();
        FUN_0050326d(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        uVar8 = FUN_0046fc7a();
        FUN_00503291(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined4 *)(unaff_EBP + -0x10) = 2;
        piVar4 = extraout_ECX + 0x39;
        do {
          if (((*(int *)(unaff_EBP + -0x10) != 5) && (*(int *)(unaff_EBP + -0x10) != 0xe)) &&
             (*(int *)(unaff_EBP + -0x10) != 0x10)) {
            FUN_0046fc87(unaff_EBP + -0x24,0);
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            uVar8 = FUN_0046fc7a();
            FUN_005d4956(uVar8);
            piVar1 = (int *)*piVar4;
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            (**(code **)(*piVar1 + 0x9c))(unaff_EBP + -0xd4);
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0042004f();
            FUN_0046fc87(unaff_EBP + -0x50,0);
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            uVar8 = FUN_0046fc7a();
            FUN_005d4956(uVar8);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005dd9c8(unaff_EBP + -0x34);
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0042004f();
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          piVar4 = piVar4 + 1;
        } while (*(int *)(unaff_EBP + -0x10) < 0x10);
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x11;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x12;
        FUN_005d499c(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 0x11;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined1 *)(extraout_ECX[0x48] + 0x10c) = 1;
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x13;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        FUN_005dd9c8(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 0x13;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x16;
        FUN_005d499c(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined1 *)(extraout_ECX[0x4a] + 0x10c) = 1;
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x17;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x18;
        FUN_005dd9c8(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 0x17;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x1a;
        FUN_005d499c(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined1 *)(extraout_ECX[0x49] + 0x10c) = 1;
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x1b;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x1c;
        FUN_005dd9c8(unaff_EBP + -0x34);
        *(undefined1 *)(unaff_EBP + -4) = 0x1b;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_0042004f();
      }
      puVar9 = (undefined4 *)(unaff_EBP + -0x84);
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      puVar9 = (undefined4 *)(unaff_EBP + -0xa4);
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      FUN_0046dbf4(unaff_EBP + -0x84);
      FUN_0046dc0a(unaff_EBP + -0xa4);
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0xa0));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x80));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0x9c));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x7c));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0x94));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x74));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0x98));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x78));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0x90));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x70));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0x8c));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x6c));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0x88));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x68));
      FUN_005031e9(*(undefined4 *)(unaff_EBP + -0xa4));
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x84));
      iVar7 = 0;
      iVar10 = 0;
      iVar5 = 0;
      do {
        iVar7 = iVar7 + *(int *)(unaff_EBP + -0xa4 + iVar5);
        iVar10 = iVar10 + *(int *)(unaff_EBP + -0x84 + iVar5);
        iVar5 = iVar5 + 4;
      } while (iVar5 < 0x20);
      *(int *)(unaff_EBP + -0x18) = iVar10;
      FUN_005031e9(iVar7);
      FUN_0050322b(*(undefined4 *)(unaff_EBP + -0x18));
      FUN_0050326d(&DAT_006de560);
      FUN_00503291(&DAT_006de560);
      FUN_0050326d(&DAT_006de560);
      FUN_00503291(&DAT_006de560);
      FUN_0050326d(&DAT_006de560);
      FUN_00503291(&DAT_006de560);
      uVar8 = FUN_0046d9e5();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar8;
      FUN_005d48d9();
      piVar4 = DAT_006fe8bc;
      *(undefined1 *)(unaff_EBP + -4) = 0x1d;
      piVar4 = (int *)(**(code **)(*piVar4 + 4))();
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x7c))
                  (*(int *)(unaff_EBP + -0x18),*(int *)(unaff_EBP + -0x18) >> 0x1f,unaff_EBP + -100)
        ;
      }
      FUN_005d499c(unaff_EBP + -100);
      uVar8 = FUN_0046dadb();
      wsprintfA((LPSTR)(unaff_EBP + -0x240),(LPCSTR)&DAT_006c08e4,uVar8);
      FUN_005d4956(unaff_EBP + -0x240);
      *(undefined1 *)(unaff_EBP + -4) = 0x1e;
      FUN_005d499c(unaff_EBP + -0x34);
      *(undefined1 *)(unaff_EBP + -4) = 0x1d;
      FUN_005b8770();
      iVar5 = FUN_00410304();
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x7c))(iVar5,iVar5 >> 0x1f,unaff_EBP + -100);
      }
      FUN_005d499c(unaff_EBP + -100);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x14;
      do {
        FUN_005032cb(unaff_EBP + -0x28,unaff_EBP + -0x58,unaff_EBP + -0x4c);
        puVar9 = (undefined4 *)(unaff_EBP + -0x28);
        if (*(int *)(unaff_EBP + -0x28) <= *(int *)(unaff_EBP + -0x10)) {
          puVar9 = (undefined4 *)(unaff_EBP + -0x10);
        }
        *(undefined4 *)(unaff_EBP + -0x10) = *puVar9;
        puVar9 = (undefined4 *)(unaff_EBP + -0x58);
        if (*(int *)(unaff_EBP + -0x58) <= *(int *)(unaff_EBP + -0x14)) {
          puVar9 = (undefined4 *)(unaff_EBP + -0x14);
        }
        *(undefined4 *)(unaff_EBP + -0x14) = *puVar9;
        piVar4 = (int *)(unaff_EBP + -0x4c);
        if (*(int *)(unaff_EBP + -0x4c) <= iVar11) {
          piVar4 = (int *)(unaff_EBP + -0x20);
        }
        iVar11 = *piVar4;
        piVar4 = (int *)(unaff_EBP + -0x18);
        *piVar4 = *piVar4 + -1;
        *(int *)(unaff_EBP + -0x20) = iVar11;
      } while (*piVar4 != 0);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x14;
      do {
        FUN_0050337c(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14),iVar11);
        piVar4 = (int *)(unaff_EBP + -0x18);
        *piVar4 = *piVar4 + -1;
      } while (*piVar4 != 0);
      FUN_004cb1a2(*(int *)(extraout_ECX[0x3a] + 0x84) + extraout_ECX[0x4d],
                   *(int *)(extraout_ECX[0x4a] + 0x88) + extraout_ECX[0x4e]);
      iVar11 = extraout_ECX[0x36];
      FUN_004cb21d((((extraout_ECX[0x21] - *(int *)(iVar11 + 0x84)) - extraout_ECX[0x1f]) +
                   *(int *)(iVar11 + 0x7c)) / 2,
                   ((((*(int *)(iVar11 + 0x80) - *(int *)(iVar11 + 0x88)) + extraout_ECX[0x4e]) / 2
                    - extraout_ECX[0x20]) + extraout_ECX[0x22]) - extraout_ECX[0x4e]);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
      uVar3 = 1;
    }
  }
  else {
    uVar3 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

