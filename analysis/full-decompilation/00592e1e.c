
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00592e1e(void)

{
  float fVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  uint uVar10;
  int unaff_EBP;
  int *piVar11;
  undefined4 *puStack_1e0;
  undefined4 *puStack_1dc;
  undefined4 *puStack_1d8;
  undefined4 *puStack_1d4;
  undefined4 *puVar12;
  
  FUN_00634c24();
  puVar12 = (undefined4 *)0x64;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 200;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x1b8;
  pvVar3 = operator_new(100);
  *(void **)(unaff_EBP + -0x38) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005dfb13();
    puVar12 = extraout_ECX_00;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x2c) = piVar4;
  *(int **)(unaff_EBP + -0x30) = piVar4;
  piVar11 = (int *)0x0;
  if (piVar4 != (int *)0x0) {
    iVar6 = *piVar4;
    *(undefined4 ***)(unaff_EBP + -0x38) = &puStack_1d8;
    puStack_1dc = (undefined4 *)0x4;
    puStack_1e0 = (undefined4 *)0x592e89;
    puStack_1d8 = puVar12;
    puStack_1d4 = puVar12;
    FUN_00436a50();
    puVar12 = *(undefined4 **)(unaff_EBP + -0x2c);
    puStack_1dc = (undefined4 *)0x1b8;
    puStack_1e0 = (undefined4 *)0xc8;
    cVar2 = (**(code **)(iVar6 + 0xc))();
    if ((cVar2 == '\0') || (cVar2 = FUN_005df69e(), cVar2 == '\0')) {
      (**(code **)*puVar12)();
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
    }
    piVar11 = *(int **)(unaff_EBP + -0x30);
  }
  piVar4 = *(int **)(DAT_006e486c + 0x3c);
  *(int **)(unaff_EBP + -0x18) = piVar4;
  if (piVar4 == (int *)0x0) {
    uVar5 = 0;
  }
  else {
    *(int *)(unaff_EBP + -0x2c) = piVar4[0x17];
    if (piVar11 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar11 + 0x20))();
      if (cVar2 != '\0') {
        puStack_1d4 = *(undefined4 **)(unaff_EBP + -0x18);
        puStack_1d8 = (undefined4 *)0x592efa;
        (**(code **)(*piVar11 + 0x9c))();
        puStack_1d8 = (undefined4 *)0x10;
        puStack_1dc = (undefined4 *)0x592f03;
        (**(code **)(*piVar11 + 0x24))();
        puStack_1dc = (undefined4 *)0x10;
        puStack_1e0 = (undefined4 *)0x592f0d;
        cVar2 = (**(code **)(*(int *)piVar11[0x17] + 0x20))();
        if (cVar2 != '\0') {
          puStack_1d4 = *(undefined4 **)(unaff_EBP + -0x2c);
          puStack_1d8 = (undefined4 *)0x592f25;
          (**(code **)(*(int *)piVar11[0x17] + 0x9c))();
          puStack_1d8 = (undefined4 *)0x10;
          puStack_1dc = (undefined4 *)0x592f31;
          (**(code **)(*(int *)piVar11[0x17] + 0x24))();
        }
      }
      piVar4 = *(int **)(unaff_EBP + -0x18);
    }
    cVar2 = (**(code **)(*piVar4 + 0x20))();
    if (cVar2 != '\0') {
      piVar4 = *(int **)(unaff_EBP + -0x18);
      puStack_1d4 = (undefined4 *)0x592f50;
      (**(code **)(*piVar4 + 0x38))();
      puStack_1d4 = (undefined4 *)0x10;
      puStack_1d8 = (undefined4 *)0x592f59;
      (**(code **)(*piVar4 + 0x24))();
    }
    piVar4 = *(int **)(unaff_EBP + -0x2c);
    cVar2 = (**(code **)(*piVar4 + 0x20))();
    if (cVar2 != '\0') {
      puStack_1d4 = (undefined4 *)0xffff;
      puStack_1d8 = (undefined4 *)0x592f79;
      (**(code **)(*piVar4 + 0x38))();
      puStack_1d8 = (undefined4 *)0x10;
      puStack_1dc = (undefined4 *)0x592f82;
      (**(code **)(*piVar4 + 0x24))();
    }
    puStack_1d4 = (undefined4 *)0x592f95;
    FUN_004b4533();
    FUN_004b4714();
    uVar5 = (**(code **)(**(int **)(unaff_EBP + -0x1ac) + 0x18))();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
    *(undefined4 *)(unaff_EBP + -0x94) = 0x46fffe00;
    *(float *)(unaff_EBP + -0x14) = (float)*(int *)(unaff_EBP + -0x10);
    *(int *)(unaff_EBP + -0x10) = (*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24)) * 9;
    fVar1 = (float)*(int *)(unaff_EBP + -0x10) * _DAT_00669420;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28);
    puStack_1d4 = (undefined4 *)(unaff_EBP + -0x9c);
    puStack_1d8 = (undefined4 *)(unaff_EBP + -200);
    *(float *)(unaff_EBP + -0x9c) =
         (float)*(int *)(unaff_EBP + -0x10) * _DAT_00666578 + (float)*(int *)(unaff_EBP + -0x28);
    *(float *)(unaff_EBP + -0x98) = fVar1 + (float)*(int *)(unaff_EBP + -0x24);
    puStack_1dc = (undefined4 *)0x593013;
    FUN_005c3840();
    cVar2 = FUN_00492d2c();
    *(int *)(unaff_EBP + -0x10) = 1 << (cVar2 - 1U & 0x1f);
    puStack_1d4 = (undefined4 *)(unaff_EBP + -0x150);
    *(float *)(unaff_EBP + -0x88) = _DAT_00668314 / (float)*(int *)(unaff_EBP + -0x10);
    puStack_1d8 = (undefined4 *)0x593050;
    FUN_00462eea();
    fVar1 = *(float *)(unaff_EBP + -0x14) - _DAT_00666578;
    puStack_1d8 = (undefined4 *)(unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    puStack_1e0 = (undefined4 *)(unaff_EBP + -0x10c);
    puStack_1dc = (undefined4 *)0x1;
    *(float *)(unaff_EBP + -0x10) = fVar1 * DAT_00673438 * _DAT_00667440;
    FUN_005c38c0();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    puStack_1d4 = (undefined4 *)0x59308f;
    FUN_00462c01();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005c4890();
    puStack_1d4 = (undefined4 *)(unaff_EBP + -0x10c);
    puStack_1d8 = (undefined4 *)0x5930b1;
    FUN_00462f96();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    puStack_1d4 = (undefined4 *)0x5930c3;
    FUN_00462c01();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005c4890();
    *(undefined4 *)(unaff_EBP + -100) = 0;
    *(undefined4 *)(unaff_EBP + -0x60) = 0;
    *(undefined4 *)(unaff_EBP + -0x5c) = 0;
    iVar6 = extraout_ECX[0x9e];
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (iVar6 - extraout_ECX[0x9d] >> 2 != 0) {
      do {
        puStack_1d4 = (undefined4 *)0x5930fc;
        pvVar3 = operator_new(0x1c);
        *(void **)(unaff_EBP + -0x38) = pvVar3;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        if (pvVar3 == (void *)0x0) {
          uVar5 = 0;
        }
        else {
          puStack_1d4 = (undefined4 *)0x593117;
          uVar5 = FUN_0058368c();
        }
        *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        puStack_1d4 = (undefined4 *)0x59312e;
        FUN_005873ba();
        iVar6 = extraout_ECX[0x9e];
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar6 - extraout_ECX[0x9d] >> 2));
    }
    (**(code **)(*extraout_ECX + 0x18))();
    iVar6 = extraout_ECX[0x4e];
    *(int *)(unaff_EBP + -0x90) = (int)*(short *)(iVar6 + 0x59c);
    *(int *)(unaff_EBP + -0x8c) = (int)*(short *)(iVar6 + 0x5b8);
    *(int *)(unaff_EBP + -0x74) = (int)*(short *)(iVar6 + 0x5ba);
    *(undefined2 *)(iVar6 + 0x59c) = *(undefined2 *)(unaff_EBP + 0xc);
    *(undefined2 *)(extraout_ECX[0x4e] + 0x5b8) = 0;
    *(undefined2 *)(extraout_ECX[0x4e] + 0x5ba) = 0;
    puStack_1d4 = (undefined4 *)0x59319c;
    FUN_0058a17c();
    puStack_1d4 = (undefined4 *)0x5931aa;
    puVar12 = (undefined4 *)FUN_005a026f();
    uVar5 = (**(code **)(*extraout_ECX + 0x34))();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
    puStack_1d4 = (undefined4 *)(unaff_EBP + 0xc);
    puStack_1d8 = (undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP + 0xc) = 0x3f800000;
    puStack_1dc = (undefined4 *)0x64;
    *(undefined4 *)(unaff_EBP + 0x10) = 0x3f800000;
    puStack_1e0 = puVar12;
    iVar6 = FUN_005a08e3();
    *(int *)(unaff_EBP + -0x78) = iVar6;
    *(undefined4 *)(iVar6 + 0x28) = *(undefined4 *)(unaff_EBP + 0x14);
    puStack_1d4 = (undefined4 *)0x1;
    iVar6 = *(int *)(extraout_ECX[2] + 4);
    puStack_1d8 = (undefined4 *)extraout_ECX[0x2d];
    puStack_1dc = (undefined4 *)0x5931f4;
    FUN_005992ca();
    (**(code **)(*extraout_ECX + 0x60))();
    puStack_1d4 = (undefined4 *)0x593203;
    FUN_005994da();
    puStack_1d4 = (undefined4 *)0x59320c;
    FUN_005a1444();
    puStack_1d4 = (undefined4 *)0x593217;
    FUN_005a0f1a();
    uVar5 = FUN_004b46a0();
    *(undefined4 *)(unaff_EBP + -0xb0) = 0x3f800000;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
    *(undefined4 *)(unaff_EBP + -0xb4) = 0x3f800000;
    *(undefined4 *)(unaff_EBP + -0xb8) = 0x3f800000;
    *(undefined4 *)(unaff_EBP + -0xbc) = 0x3f800000;
    uVar5 = FUN_005cee4b();
    *(undefined4 *)(unaff_EBP + -0x38) = uVar5;
    puStack_1d4 = (undefined4 *)0x59325e;
    FUN_005cedcb();
    puStack_1d4 = (undefined4 *)(unaff_EBP + -0x34);
    puStack_1d8 = (undefined4 *)0x593270;
    FUN_005cfd9c();
    if (*(int *)(unaff_EBP + -0x34) != 0) {
      iVar7 = FUN_004b4714();
      fVar1 = DAT_00673438;
      *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar7 + 0x184);
      fVar1 = fVar1 * _DAT_00669424;
      *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar7 + 0x188);
      *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar7 + 0x18c);
      puStack_1d8 = (undefined4 *)(unaff_EBP + -0x10c);
      *(float *)(unaff_EBP + 0x10) = fVar1;
      puStack_1d4 = (undefined4 *)0x1;
      puStack_1dc = (undefined4 *)0x5932bf;
      puStack_1dc = (undefined4 *)FUN_005c38c0();
      puStack_1e0 = (undefined4 *)(unaff_EBP + -0x54);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      puVar12 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x44);
      *(undefined4 *)(unaff_EBP + -0x54) = *puVar12;
      *(undefined4 *)(unaff_EBP + -0x50) = puVar12[1];
      *(undefined4 *)(unaff_EBP + -0x4c) = puVar12[2];
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005c4890();
      puStack_1d4 = (undefined4 *)0x593300;
      FUN_005d0a7c();
      puStack_1d4 = (undefined4 *)0x59330b;
      FUN_005ceca4();
    }
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
    *(undefined4 *)(unaff_EBP + -0x6c) = 0;
    *(undefined4 *)(unaff_EBP + -0x68) = 0;
    iVar7 = *(int *)(iVar6 + 0x8c);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    iVar8 = *(int *)(iVar6 + 0x88);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar7 = iVar7 - iVar8 >> 2;
    *(int *)(unaff_EBP + -0x7c) = iVar7;
    if (0 < iVar7) {
      do {
        iVar7 = *(int *)(*(int *)(iVar6 + 0x88) + *(int *)(unaff_EBP + -0x14) * 4);
        *(int *)(unaff_EBP + -0x80) = iVar7;
        iVar7 = (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 8)) / 0xc;
        if (0 < iVar7) {
          *(undefined4 *)(unaff_EBP + 0x10) = 0;
          *(int *)(unaff_EBP + 0x14) = iVar7;
          do {
            *(undefined4 *)(unaff_EBP + -0x84) =
                 *(undefined4 *)
                  (*(int *)(*(int *)(unaff_EBP + -0x80) + 8) + 8 + *(int *)(unaff_EBP + 0x10));
            puStack_1d4 = (undefined4 *)0x59337a;
            FUN_004e8708();
            *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 0xc;
            piVar4 = (int *)(unaff_EBP + 0x14);
            *piVar4 = *piVar4 + -1;
          } while (*piVar4 != 0);
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x7c));
    }
    puStack_1d4 = (undefined4 *)0x593398;
    iVar6 = FUN_005ce621();
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
      if (*(int *)(unaff_EBP + -0x6c) - *(int *)(unaff_EBP + -0x70) >> 2 != 0) {
        do {
          *(undefined4 *)(unaff_EBP + 0x14) =
               *(undefined4 *)(*(int *)(unaff_EBP + -0x70) + *(int *)(unaff_EBP + 0x10) * 4);
          puStack_1d4 = (undefined4 *)0x5933cc;
          FUN_005c36c0();
          *(undefined1 *)(unaff_EBP + -4) = 8;
          puStack_1d4 = (undefined4 *)0x5933e2;
          FUN_00463023();
          puStack_1d4 = *(undefined4 **)(unaff_EBP + 0xc);
          puStack_1d8 = (undefined4 *)0x5933f2;
          FUN_005cf6fc();
          puStack_1d4 = (undefined4 *)0x593404;
          FUN_00463023();
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005c4890();
          *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
        } while (*(uint *)(unaff_EBP + 0x10) <
                 (uint)(*(int *)(unaff_EBP + -0x6c) - *(int *)(unaff_EBP + -0x70) >> 2));
      }
      FUN_005ce67e();
    }
    puStack_1d4 = (undefined4 *)0x593437;
    FUN_005a0903();
    *(undefined2 *)(extraout_ECX[0x4e] + 0x59c) = *(undefined2 *)(unaff_EBP + -0x90);
    *(undefined2 *)(extraout_ECX[0x4e] + 0x5b8) = *(undefined2 *)(unaff_EBP + -0x8c);
    *(undefined2 *)(extraout_ECX[0x4e] + 0x5ba) = *(undefined2 *)(unaff_EBP + -0x74);
    puStack_1d4 = (undefined4 *)0x593478;
    FUN_0058a17c();
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (*(int *)(unaff_EBP + -0x60) - *(int *)(unaff_EBP + -100) >> 2 != 0) {
      do {
        puStack_1d4 = (undefined4 *)0x59349b;
        FUN_005873ba();
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(uint *)(unaff_EBP + -0x14) <
               (uint)(*(int *)(unaff_EBP + -0x60) - *(int *)(unaff_EBP + -100) >> 2));
    }
    (**(code **)(*extraout_ECX + 0x1c))();
    puStack_1d4 = (undefined4 *)0x1;
    puStack_1d8 = (undefined4 *)extraout_ECX[0x2d];
    puStack_1dc = (undefined4 *)0x5934c4;
    FUN_005992ca();
    (**(code **)(*extraout_ECX + 0x60))();
    puStack_1d4 = (undefined4 *)0x5934d3;
    FUN_005994da();
    puStack_1d4 = (undefined4 *)0x5934dc;
    FUN_005a1444();
    puStack_1d4 = (undefined4 *)0x5934e7;
    FUN_005a0f1a();
    if (*(int *)(unaff_EBP + -0x34) != 0) {
      puStack_1d4 = (undefined4 *)0x5934f7;
      FUN_005ced0e();
      (**(code **)(**(int **)(unaff_EBP + -0x34) + 4))();
    }
    puStack_1d4 = (undefined4 *)0x59350a;
    FUN_005cee2f();
    puStack_1d8 = (undefined4 *)(unaff_EBP + -0x28);
    puStack_1d4 = *(undefined4 **)(unaff_EBP + 8);
    puStack_1dc = *(undefined4 **)(unaff_EBP + -0x18);
    puStack_1e0 = (undefined4 *)0x593520;
    cVar2 = FUN_004c3766();
    if (cVar2 != '\0') {
      *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0xac) + *(int *)(unaff_EBP + -0x28);
      puVar12 = (undefined4 *)0x64;
      *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0xa4);
      *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0xa8) + *(int *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0xa0);
      puStack_1d4 = (undefined4 *)0x593566;
      pvVar3 = operator_new(100);
      *(void **)(unaff_EBP + 0xc) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 9;
      if (pvVar3 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_005dfb13();
        puVar12 = extraout_ECX_01;
      }
      *(undefined1 *)(unaff_EBP + -4) = 7;
      if (piVar4 != (int *)0x0) {
        iVar6 = *piVar4;
        puStack_1d4 = (undefined4 *)0x0;
        puStack_1d8 = (undefined4 *)0x0;
        *(undefined4 ***)(unaff_EBP + 0xc) = &puStack_1e0;
        puStack_1e0 = puVar12;
        puStack_1dc = puVar12;
        FUN_00436a50(4);
        uVar5 = FUN_004a946b();
        uVar5 = FUN_004a9465(uVar5);
        cVar2 = (**(code **)(iVar6 + 0xc))(uVar5);
        if (cVar2 != '\0') {
          cVar2 = (**(code **)(*piVar4 + 0x20))(0x10);
          if (cVar2 == '\0') {
            piVar11 = *(int **)(unaff_EBP + -0x18);
          }
          else {
            piVar11 = *(int **)(unaff_EBP + -0x18);
            (**(code **)(*piVar4 + 0x9c))(piVar11,unaff_EBP + -0x58,piVar4 + 5,0);
            (**(code **)(*piVar4 + 0x24))(0x10);
          }
          cVar2 = (**(code **)(*piVar11 + 0x20))(1);
          if (cVar2 != '\0') {
            (**(code **)(*piVar11 + 0x38))(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x28);
            (**(code **)(*piVar11 + 0x24))(1);
          }
          *(int *)(unaff_EBP + -0x48) = piVar4[5];
          iVar6 = piVar4[7];
          *(int *)(unaff_EBP + -0x44) = piVar4[6];
          *(int *)(unaff_EBP + -0x40) = piVar4[7];
          *(int *)(unaff_EBP + -0x3c) = piVar4[8];
          iVar7 = (*(int *)(unaff_EBP + -0x1c) - piVar4[8]) - *(int *)(unaff_EBP + -0x24);
          *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + iVar7;
          *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + iVar7;
          *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + -0x28;
          *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + -0x28;
          iVar6 = ((*(int *)(unaff_EBP + -0x20) - iVar6) - *(int *)(unaff_EBP + -0x28)) / 2;
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + iVar6;
          *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + iVar6;
          cVar2 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x20))(0x10);
          if (cVar2 != '\0') {
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x9c))
                      (piVar4,piVar4 + 5,unaff_EBP + -0x48,0);
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x24))(0x10);
          }
        }
        (**(code **)*piVar4)(1);
      }
    }
    iVar6 = *(int *)(unaff_EBP + -0x20);
    iVar7 = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + 8) = iVar6 - *(int *)(unaff_EBP + -0x28);
    *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + 0xc) = iVar7 - *(int *)(unaff_EBP + -0x24);
    fVar1 = *(float *)(unaff_EBP + 8) / (float)*(int *)(unaff_EBP + 0xc);
    if (fVar1 <= _DAT_0067205c) {
      if (fVar1 < _DAT_0067205c) {
        iVar8 = __ftol();
        if (200 < iVar8) {
          iVar8 = 200;
        }
        uVar9 = (iVar8 - iVar6) + *(int *)(unaff_EBP + -0x28);
        if (1 < (int)uVar9) {
          uVar10 = uVar9 >> 1;
          *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) - uVar10;
          uVar9 = uVar9 + uVar10 * -2;
          do {
            iVar6 = iVar6 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
          *(int *)(unaff_EBP + -0x20) = iVar6;
        }
        if (uVar9 == 1) {
          iVar6 = iVar6 + 1;
          *(int *)(unaff_EBP + -0x20) = iVar6;
        }
      }
    }
    else {
      iVar8 = __ftol();
      if (0x1b8 < iVar8) {
        iVar8 = 0x1b8;
      }
      uVar9 = (iVar8 - iVar7) + *(int *)(unaff_EBP + -0x24);
      if (1 < (int)uVar9) {
        uVar10 = uVar9 >> 1;
        uVar9 = uVar9 + uVar10 * -2;
        do {
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -1;
          iVar7 = iVar7 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
        *(int *)(unaff_EBP + -0x1c) = iVar7;
      }
      if (uVar9 == 1) {
        iVar7 = iVar7 + 1;
        *(int *)(unaff_EBP + -0x1c) = iVar7;
      }
    }
    puStack_1d4 = (undefined4 *)(unaff_EBP + -0x28);
    *(int *)(unaff_EBP + 8) = iVar7 - *(int *)(unaff_EBP + -0x24);
    iVar7 = *(int *)(unaff_EBP + 8);
    puStack_1d8 = *(undefined4 **)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + 8) = iVar6 - *(int *)(unaff_EBP + -0x28);
    puStack_1dc = (undefined4 *)(_DAT_00672054 / (float)iVar7);
    puStack_1e0 = (undefined4 *)(_DAT_0066674c / (float)*(int *)(unaff_EBP + 8));
    uVar5 = FUN_004ba98d();
    puVar12 = *(undefined4 **)(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + 8) = uVar5;
    if (puVar12 != (undefined4 *)0x0) {
      piVar4 = *(int **)(unaff_EBP + -0x18);
      puStack_1d4 = (undefined4 *)0x5937aa;
      cVar2 = (**(code **)(*piVar4 + 0x20))();
      if (cVar2 != '\0') {
        puStack_1dc = puVar12 + 5;
        puStack_1d4 = (undefined4 *)0x0;
        puStack_1e0 = puVar12;
        puStack_1d8 = puStack_1dc;
        (**(code **)(*piVar4 + 0x9c))();
        (**(code **)(*piVar4 + 0x24))(0x10);
        piVar4 = *(int **)(unaff_EBP + -0x2c);
        if (piVar4 != (int *)0x0) {
          puStack_1d4 = (undefined4 *)0x10;
          puStack_1d8 = (undefined4 *)0x5937d8;
          cVar2 = (**(code **)(*piVar4 + 0x20))();
          if (cVar2 != '\0') {
            puStack_1e0 = (undefined4 *)puVar12[0x17];
            puStack_1dc = puVar12 + 5;
            puStack_1d4 = (undefined4 *)0x0;
            puStack_1d8 = puStack_1dc;
            (**(code **)(*piVar4 + 0x9c))();
            (**(code **)(*piVar4 + 0x24))(0x10);
          }
        }
      }
      puStack_1d4 = (undefined4 *)0x1;
      puStack_1d8 = (undefined4 *)0x593801;
      (**(code **)*puVar12)();
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0048c4c9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0048c4c9();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c4890();
    uVar5 = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

