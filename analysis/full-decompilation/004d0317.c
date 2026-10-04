
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004d0317(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  void *pvVar7;
  int *piVar8;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_005e8d11();
    *(char *)(unaff_EBP + -0xd) = cVar1;
    if (cVar1 != '\0') {
      iVar4 = FUN_005dd5e1(0x1f,0x50,0x1f);
      extraout_ECX[0x19] = iVar4;
      cVar1 = FUN_005e8d11();
      uVar2 = 0;
      if (cVar1 == '\0') goto LAB_004d0c3f;
      piVar5 = (int *)FUN_005e7743();
      uVar6 = (**(code **)(*piVar5 + 8))(1);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
      piVar5 = (int *)FUN_005e7743();
      uVar6 = (**(code **)(*piVar5 + 0x44))(0);
      *(undefined4 *)(unaff_EBP + -0x28) = uVar6;
      FUN_005a5631(4000,extraout_ECX + 0x55,4);
      (**(code **)(*(int *)extraout_ECX[0x55] + 0x68))(*(undefined4 *)(unaff_EBP + -0x28));
      FUN_005a5631(0x334,extraout_ECX + 0x49,4);
      (**(code **)(*(int *)extraout_ECX[0x49] + 0x68))(*(undefined4 *)(unaff_EBP + -0x28));
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar7 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x4d] = (int)piVar5;
      (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x49],9,1);
      FUN_005a5631(0x335,extraout_ECX + 0x4a,4);
      (**(code **)(*(int *)extraout_ECX[0x4a] + 0x68))(*(undefined4 *)(unaff_EBP + -0x28));
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar7 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x4e] = (int)piVar5;
      (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x4a],9,1);
      FUN_005a5631(0x336,extraout_ECX + 0x4b,4);
      (**(code **)(*(int *)extraout_ECX[0x4b] + 0x68))(*(undefined4 *)(unaff_EBP + -0x28));
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar7 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x4f] = (int)piVar5;
      (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x4b],5,1);
      FUN_005a5631(0x337,extraout_ECX + 0x4c,4);
      (**(code **)(*(int *)extraout_ECX[0x4c] + 0x68))(*(undefined4 *)(unaff_EBP + -0x28));
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar7 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x50] = (int)piVar5;
      (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x4c],5,1);
      pvVar7 = operator_new(0x19c);
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005ea0f3();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x51] = iVar4;
      FUN_005a5631(0x339,extraout_ECX + 0x48,4);
      FUN_005e357a();
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x228))(extraout_ECX[0x48],0);
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x230))(*(undefined4 *)(unaff_EBP + -0x14));
      uVar6 = FUN_005dd5e1(0xbb,0xbb,0xbb);
      *(undefined4 *)(extraout_ECX[0x51] + 100) = uVar6;
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x1d4))(6);
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x1e0))(0x5a);
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x24c))(0);
      iVar4 = extraout_ECX[0x51];
      *(undefined4 *)(iVar4 + 0x184) = 6;
      *(undefined4 *)(iVar4 + 0x188) = 0x28;
      *(int **)(extraout_ECX[0x51] + 0x48) = extraout_ECX;
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x1f0))(0);
      uVar6 = FUN_005d4956(s_Zoom_Out_006c7c10);
      piVar5 = (int *)extraout_ECX[0x51];
      iVar4 = extraout_ECX[0x4e];
      *(undefined4 *)(unaff_EBP + -4) = 5;
      (**(code **)(*piVar5 + 0x1a8))(uVar6,iVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar6 = FUN_005d4956(s_Rotate_Right_006c7c00);
      piVar5 = (int *)extraout_ECX[0x51];
      iVar4 = extraout_ECX[0x50];
      *(undefined4 *)(unaff_EBP + -4) = 6;
      (**(code **)(*piVar5 + 0x1a8))(uVar6,iVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar6 = FUN_005d4956(s_Zoom_In_006c7bf8);
      *(undefined4 *)(unaff_EBP + -4) = 7;
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x1a8))(uVar6,extraout_ECX[0x4d]);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar6 = FUN_005d4956(s_Rotate_Left_006c7bec);
      piVar5 = (int *)extraout_ECX[0x51];
      iVar4 = extraout_ECX[0x4f];
      *(undefined4 *)(unaff_EBP + -4) = 8;
      (**(code **)(*piVar5 + 0x1a8))(uVar6,iVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar3 = (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x38))(0xff,0,0);
      if (*(char *)(DAT_006e486c + 100) == '\v') {
        uVar6 = 0xc;
      }
      else {
        uVar6 = 0x30;
      }
      piVar5 = (int *)(**(code **)(**(int **)(DAT_006e486c + 0x54) + 0x10))(1,uVar6,0,0);
      extraout_ECX[0x60] = (int)piVar5;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x20))(uVar3);
      }
      pvVar7 = operator_new(0xd4);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 9;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005dbd68();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x61] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar4);
        (**(code **)(*(int *)extraout_ECX[0x61] + 0x98))();
        FUN_005ddfdc(1);
      }
      pvVar7 = operator_new(0xd4);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 10;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005dbd68();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x54] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar4);
        FUN_005ddfdc(1);
        (**(code **)(*(int *)extraout_ECX[0x54] + 0x98))();
      }
      FUN_004733da(1000);
      pvVar7 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xb;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005e9913();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x67] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*(int *)(iVar4 + 0xd4) + 0x18))(DAT_006f2a94);
        (**(code **)(*(int *)(extraout_ECX[0x67] + 0xd4) + 0x14))(0);
        (**(code **)(*(int *)(extraout_ECX[0x67] + 0xd4) + 0x10))(DAT_006f2a5c);
        (**(code **)(*(int *)(extraout_ECX[0x67] + 0xd4) + 0xc))(2,0);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x67]);
        (**(code **)(*(int *)extraout_ECX[0x67] + 0x98))();
      }
      pvVar7 = operator_new(0x124);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xc;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004d59d4();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x459] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar4);
        (**(code **)(*(int *)extraout_ECX[0x459] + 0x98))();
      }
      uVar2 = FUN_004d1fcd();
      iVar4 = extraout_ECX[0x5d];
      *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
      if (iVar4 == 0) {
        iVar4 = FUN_004d44d4();
        extraout_ECX[0x5d] = iVar4;
      }
      pvVar7 = operator_new(0x15c);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xd;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ff71c();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x46b] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar4);
        FUN_005ddfdc(1);
      }
      FUN_005e692b(DAT_006f2a98);
      piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      piVar5 = (int *)(**(code **)(*piVar5 + 8))();
      (**(code **)(*piVar5 + 0x1c8))(extraout_ECX);
      FUN_004b7bc1();
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x100) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 0xe;
      uVar6 = FUN_0041532c(9,unaff_EBP + -0x100,0);
      cVar1 = FUN_004fff98(0x94,uVar6);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x10;
        uVar6 = FUN_0046fc7a();
        FUN_005d4bbf(uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x11;
        uVar6 = FUN_0046fc7a(&DAT_006c08e4,extraout_ECX + 0x66);
        FUN_00634d24(uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        FUN_0042004f();
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_0042004f();
      }
      pvVar7 = operator_new(0xec);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      if (pvVar7 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e95ac();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      if (piVar5 != (int *)0x0) {
        piVar8 = (int *)(**(code **)(*extraout_ECX + 0x18))();
        (**(code **)(*piVar8 + 0x20))(piVar5);
        FUN_005ddfdc(1);
        (**(code **)(*piVar5 + 0x98))();
        FUN_005a5631(0x1374,unaff_EBP + -0x20,4);
        if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(DAT_006f2a64);
        }
        FUN_005e976e(*(undefined4 *)(unaff_EBP + -0x20),3,_DAT_00666cbc);
        (**(code **)(*piVar5 + 0x90))(0x10000,1);
        FUN_005db297(piVar5);
      }
      if (0x2f < *(int *)(DAT_006e486c + 0x44)) {
        iVar4 = FUN_004e609e();
        if (iVar4 != 0) {
          FUN_004e6453(0);
        }
      }
      pvVar7 = operator_new(0xfc);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00524f8d();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      extraout_ECX[0x46f] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar4);
        FUN_004cb1a2(200,200);
        (**(code **)(*(int *)extraout_ECX[0x46f] + 0x98))();
      }
      pvVar7 = operator_new(0x108);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      if (pvVar7 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0053565d();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      extraout_ECX[0x470] = (int)piVar5;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x98))();
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x470]);
      }
      *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      uVar6 = FUN_0041532c(9,unaff_EBP + -0x94,0);
      cVar1 = FUN_004fff98(0x9a,uVar6);
      if (cVar1 != '\0') {
        uVar6 = FUN_004705f2(3,0xffffffff);
        FUN_005d4bbf(uVar6);
      }
      pvVar7 = operator_new(0xc);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      if (pvVar7 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004d0c4d();
      }
      extraout_ECX[0x474] = iVar4;
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_00470467();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
    }
    uVar2 = *(undefined1 *)(unaff_EBP + -0xd);
  }
  else {
    uVar2 = FUN_005e8d11();
  }
LAB_004d0c3f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

