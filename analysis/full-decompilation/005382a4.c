
undefined1 FUN_005382a4(void)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  int *piVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uVar8;
  size_t sVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int *extraout_ECX;
  uint uVar13;
  int unaff_EBP;
  char *pcVar14;
  
  FUN_00634c24();
  cVar3 = (**(code **)(*extraout_ECX + 200))();
  if (cVar3 == '\0') {
    piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
    iVar6 = (**(code **)(*piVar5 + 0x1c))();
    if ((((iVar6 == 0xf) || (iVar6 == 0x11)) || (iVar6 == 0x12)) ||
       ((iVar6 == 0x14 || (iVar6 == 0x13)))) {
      piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      iVar6 = (**(code **)(*piVar5 + 0x10))(1,10,0,1);
      extraout_ECX[0x82] = iVar6;
      piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      iVar6 = (**(code **)(*piVar5 + 0x10))(1,8,0,1);
      extraout_ECX[0x83] = iVar6;
    }
    FUN_005a5631(0x7f5,extraout_ECX + 0x4b,4);
    if ((int *)extraout_ECX[0x4b] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x4b] + 0x70))();
    }
    (**(code **)(*extraout_ECX + 0x90))(0x200,1);
    (**(code **)(*extraout_ECX + 0x90))(0x10,0);
    FUN_005ddfdc(1);
    FUN_004cb1a2(*(undefined4 *)(extraout_ECX[0x4b] + 0x1c),
                 *(undefined4 *)(extraout_ECX[0x4b] + 0x20));
    cVar3 = FUN_005dbf32();
    uVar4 = 0;
    if (cVar3 != '\0') {
      (**(code **)(*extraout_ECX + 0x174))(1,0);
      if ((int *)extraout_ECX[0x16] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x16] + 0x68))(DAT_006f2a64);
      }
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x36] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x37] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x38] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x39] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x3a] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 5;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x3b] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 6;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x3c] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 7;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x3d] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 8;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x3e] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 9;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x3f] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 10;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x40] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xb;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x41] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xc;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x42] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xd;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x43] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xe;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x44] = iVar6;
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0xf;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x45] = iVar6;
      FUN_005a5631(0x7e7,extraout_ECX + 0x4c,4);
      FUN_005a5631(0x7e8,extraout_ECX + 0x4d,4);
      FUN_005a5631(0x7e9,extraout_ECX + 0x4e,4);
      FUN_005a5631(0x7dc,extraout_ECX + 0x50,4);
      FUN_005a5631(0x7db,extraout_ECX + 0x4f,4);
      FUN_005a5631(0x7dd,extraout_ECX + 0x51,4);
      FUN_005a5631(0x7de,extraout_ECX + 0x52,4);
      FUN_005a5631(0x7d6,extraout_ECX + 0x53,4);
      FUN_005a5631(0x7d4,extraout_ECX + 0x54,4);
      FUN_005a5631(0x7d7,extraout_ECX + 0x55,4);
      FUN_005a5631(0x7da,extraout_ECX + 0x56,4);
      FUN_005a5631(0x7d8,extraout_ECX + 0x57,4);
      FUN_005a5631(0x7d3,extraout_ECX + 0x58,4);
      FUN_005a5631(0x7d9,extraout_ECX + 0x59,4);
      FUN_005a5631(0x7f2,extraout_ECX + 0x5a,4);
      (**(code **)(*(int *)extraout_ECX[0x4c] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x4d] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x4e] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x50] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x4f] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x51] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x52] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x53] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x54] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x55] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x56] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x57] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x58] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x59] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x5a] + 0x68))(DAT_006f2a64);
      (**(code **)(*(int *)extraout_ECX[0x43] + 0x19c))(extraout_ECX[0x4c],4,1);
      FUN_004cb21d(DAT_006f45b0,DAT_006f45b4);
      *(undefined4 *)(extraout_ECX[0x43] + 0xf8) = 1;
      *(undefined4 *)(extraout_ECX[0x43] + 0xf4) = 1;
      *(undefined1 *)(extraout_ECX[0x43] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x43]);
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x19c))(extraout_ECX[0x4d],4,1);
      FUN_004cb21d(DAT_006f45b8,DAT_006f45bc);
      *(undefined4 *)(extraout_ECX[0x44] + 0xf8) = 1;
      *(undefined4 *)(extraout_ECX[0x44] + 0xf4) = 1;
      *(undefined1 *)(extraout_ECX[0x44] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x19c))(extraout_ECX[0x4e],4,1);
      FUN_004cb21d(DAT_006f45c0,DAT_006f45c4);
      *(undefined4 *)(extraout_ECX[0x45] + 0xf8) = 1;
      *(undefined4 *)(extraout_ECX[0x45] + 0xf4) = 1;
      *(undefined1 *)(extraout_ECX[0x45] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
      (**(code **)(*(int *)extraout_ECX[0x37] + 0x19c))(extraout_ECX[0x50],4,1);
      FUN_004cb21d(DAT_006f45a0,DAT_006f45a4);
      *(undefined4 *)(extraout_ECX[0x37] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x37] + 0xf8) = 0;
      *(undefined1 *)(extraout_ECX[0x37] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x37]);
      (**(code **)(*(int *)extraout_ECX[0x36] + 0x19c))(extraout_ECX[0x4f],4,1);
      FUN_004cb21d(DAT_006f45a8,DAT_006f45ac);
      *(undefined4 *)(extraout_ECX[0x36] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x36] + 0xf8) = 0;
      *(undefined1 *)(extraout_ECX[0x36] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x36]);
      (**(code **)(*(int *)extraout_ECX[0x38] + 0x19c))(extraout_ECX[0x51],4,1);
      FUN_004cb21d(DAT_006f4598,DAT_006f459c);
      *(undefined4 *)(extraout_ECX[0x38] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x38] + 0xf8) = 0;
      *(undefined1 *)(extraout_ECX[0x38] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x38]);
      (**(code **)(*(int *)extraout_ECX[0x39] + 0x19c))(extraout_ECX[0x52],4,1);
      FUN_004cb21d(DAT_006f4590,DAT_006f4594);
      *(undefined4 *)(extraout_ECX[0x39] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x39] + 0xf8) = 0;
      *(undefined1 *)(extraout_ECX[0x39] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
      (**(code **)(*(int *)extraout_ECX[0x3a] + 0x19c))(extraout_ECX[0x53],4,1);
      FUN_004cb21d(DAT_006f4588,DAT_006f458c);
      *(undefined4 *)(extraout_ECX[0x3a] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x3a] + 0xf8) = 1;
      *(undefined1 *)(extraout_ECX[0x3a] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3a]);
      (**(code **)(*(int *)extraout_ECX[0x3b] + 0x19c))(extraout_ECX[0x54],4,1);
      FUN_004cb21d(DAT_006f4580,DAT_006f4584);
      *(undefined4 *)(extraout_ECX[0x3b] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x3b] + 0xf8) = 1;
      *(undefined1 *)(extraout_ECX[0x3b] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3b]);
      (**(code **)(*(int *)extraout_ECX[0x3c] + 0x19c))(extraout_ECX[0x55],4,1);
      FUN_004cb21d(DAT_006f4578,DAT_006f457c);
      *(undefined4 *)(extraout_ECX[0x3c] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x3c] + 0xf8) = 1;
      *(undefined1 *)(extraout_ECX[0x3c] + 0x16b) = 1;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3c]);
      (**(code **)(*(int *)extraout_ECX[0x3d] + 0x19c))(extraout_ECX[0x56],4,1);
      FUN_004cb21d(DAT_006f4570,DAT_006f4574);
      *(undefined4 *)(extraout_ECX[0x3d] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x3d] + 0xf8) = 1;
      FUN_005e4a73(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3d]);
      (**(code **)(*(int *)extraout_ECX[0x3e] + 0x19c))(extraout_ECX[0x57],4,1);
      FUN_004cb21d(DAT_006f4558,DAT_006f455c);
      *(undefined4 *)(extraout_ECX[0x3e] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x3e] + 0xf8) = 1;
      FUN_005e4a73(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3e]);
      (**(code **)(*(int *)extraout_ECX[0x3f] + 0x19c))(extraout_ECX[0x58],4,1);
      FUN_004cb21d(DAT_006f4560,DAT_006f4564);
      *(undefined4 *)(extraout_ECX[0x3f] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x3f] + 0xf8) = 1;
      FUN_005e4a73(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3f]);
      (**(code **)(*(int *)extraout_ECX[0x40] + 0x19c))(extraout_ECX[0x59],4,1);
      FUN_004cb21d(DAT_006f4568,DAT_006f456c);
      *(undefined4 *)(extraout_ECX[0x40] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x40] + 0xf8) = 1;
      FUN_005e4a73(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x40]);
      (**(code **)(*(int *)extraout_ECX[0x41] + 0x19c))(extraout_ECX[0x5a],4,1);
      FUN_004cb21d(DAT_006f4550,DAT_006f4554);
      *(undefined4 *)(extraout_ECX[0x41] + 0xf4) = 1;
      *(undefined4 *)(extraout_ECX[0x41] + 0xf8) = 1;
      FUN_005e4a73(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x41]);
      FUN_005a5631(0x7ea,unaff_EBP + -0x28,4);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x10;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x46] = iVar6;
      if (iVar6 != 0) {
        (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x46] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,2);
        FUN_004cb21d(DAT_006f4500,DAT_006f4504);
        *(undefined4 *)(extraout_ECX[0x46] + 0xf8) = 1;
        *(undefined1 *)(extraout_ECX[0x46] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x46] + 0x150) = 0;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x46]);
      }
      FUN_005a5631(0x1261,unaff_EBP + -0x28,4);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x11;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x47] = iVar6;
      if (iVar6 != 0) {
        (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x47] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,1);
        FUN_004cb21d(DAT_006f44f8,DAT_006f44fc);
        *(undefined4 *)(extraout_ECX[0x47] + 0xf8) = 1;
        *(undefined1 *)(extraout_ECX[0x47] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x47] + 0x150) = 0;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x47]);
      }
      FUN_005a5631(0x1262,unaff_EBP + -0x28,4);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x12;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x48] = iVar6;
      if (iVar6 != 0) {
        (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x48] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,1);
        FUN_004cb21d(DAT_006f44f0,DAT_006f44f4);
        *(undefined4 *)(extraout_ECX[0x48] + 0xf8) = 1;
        *(undefined1 *)(extraout_ECX[0x48] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x48] + 0x150) = 0;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x48]);
      }
      FUN_005a5631(0x1263,unaff_EBP + -0x28,4);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x13;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x49] = iVar6;
      if (iVar6 != 0) {
        (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x49] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,1);
        FUN_004cb21d(DAT_006f44e8,DAT_006f44ec);
        *(undefined4 *)(extraout_ECX[0x49] + 0xf8) = 1;
        *(undefined1 *)(extraout_ECX[0x49] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x49] + 0x150) = 0;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x49]);
      }
      FUN_005a5631(0x1381,unaff_EBP + -0x28,4);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x14;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x4a] = iVar6;
      if (iVar6 != 0) {
        (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x4a] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,1);
        FUN_004cb21d(DAT_006f44e0,DAT_006f44e4);
        *(undefined4 *)(extraout_ECX[0x4a] + 0xf8) = 1;
        *(undefined1 *)(extraout_ECX[0x4a] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x4a] + 0x150) = 0;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4a]);
      }
      (**(code **)(*(int *)extraout_ECX[0x42] + 0x19c))(0,4,0);
      FUN_005e4a3a(1);
      iVar6 = DAT_006f2a9c;
      if (extraout_ECX[0x82] != 0) {
        iVar6 = extraout_ECX[0x82];
      }
      FUN_005e4071(iVar6);
      piVar5 = (int *)FUN_005e40a5();
      uVar8 = FUN_005e40a5();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
      uVar8 = (**(code **)(*piVar5 + 0x58))();
      iVar6 = **(int **)(unaff_EBP + -0x10);
      sVar9 = _strlen(s__9_999_999_006cd374);
      pcVar14 = s__9_999_999_006cd374;
      uVar8 = (**(code **)(iVar6 + 0x68))(s__9_999_999_006cd374,sVar9,uVar8);
      FUN_004cb1a2(uVar8,pcVar14);
      FUN_004cb21d((DAT_006f4540 - *(int *)(extraout_ECX[0x42] + 0x84)) +
                   *(int *)(extraout_ECX[0x42] + 0x7c),DAT_006f454c);
      uVar8 = FUN_005d4956(&DAT_006de560);
      piVar5 = (int *)extraout_ECX[0x42];
      *(undefined4 *)(unaff_EBP + -4) = 0x15;
      (**(code **)(*piVar5 + 0x9c))(uVar8);
      (**(code **)(*piVar5 + 0x168))();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_005e46f0(0);
      piVar5 = (int *)extraout_ECX[0x42];
      if ((char)piVar5[0x5a] != '\x01') {
        *(undefined1 *)(piVar5 + 0x5a) = 1;
        (**(code **)(*piVar5 + 0x168))();
      }
      iVar6 = extraout_ECX[0x42];
      *(undefined4 *)(unaff_EBP + -0x10) = 4;
      *(undefined4 *)(iVar6 + 0xf8) = 1;
      iVar6 = extraout_ECX[0x42];
      *(undefined4 *)(iVar6 + 0x160) = 1;
      *(undefined4 *)(iVar6 + 0x11c) = 0;
      *(undefined4 *)(iVar6 + 0x120) = 0;
      *(int *)(iVar6 + 0x124) = *(int *)(iVar6 + 0x84) - *(int *)(iVar6 + 0x7c);
      *(int *)(iVar6 + 0x128) = *(int *)(iVar6 + 0x88) - *(int *)(iVar6 + 0x80);
      *(undefined4 *)(iVar6 + 0x164) = 2;
      puVar10 = (uint *)(extraout_ECX + 0x69);
      extraout_ECX[0x6a] = 0xfeff;
      extraout_ECX[0x6b] = 0xd5fef4;
      *puVar10 = 0x29e65e;
      extraout_ECX[0x6c] = 0x1a8b4a;
      do {
        uVar1 = *puVar10;
        if (*(int *)(DAT_006e486c + 0x34) == 1) {
          uVar13 = ((uVar1 >> 0x10 & 0xf8) << 5 | uVar1 >> 8 & 0xf8) << 2;
        }
        else {
          uVar13 = ((uVar1 >> 0x10 & 0xfff8) << 5 | uVar1 >> 8 & 0xfc) << 3;
        }
        *puVar10 = uVar13 & 0xffff | uVar1 >> 3 & 0x1f;
        puVar10 = puVar10 + 1;
        piVar5 = (int *)(unaff_EBP + -0x10);
        *piVar5 = *piVar5 + -1;
      } while (*piVar5 != 0);
      FUN_005e40ac(extraout_ECX + 0x69);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x42]);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x16;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x74] = iVar6;
      if (iVar6 != 0) {
        iVar6 = DAT_006f2a9c;
        if (extraout_ECX[0x82] != 0) {
          iVar6 = extraout_ECX[0x82];
        }
        FUN_005e4071(iVar6);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x74]);
        iVar6 = *(int *)(extraout_ECX[0x42] + 0x80);
        uVar8 = *(undefined4 *)(extraout_ECX[0x42] + 0x7c);
        *(int *)(unaff_EBP + -0x3c) = iVar6;
        *(undefined4 *)(unaff_EBP + -0x38) = uVar8;
        piVar5 = (int *)FUN_005e40a5();
        iVar11 = (**(code **)(*piVar5 + 0x58))();
        *(int *)(unaff_EBP + -0x34) = iVar11 + iVar6;
        piVar5 = (int *)FUN_005e40a5();
        iVar6 = *piVar5;
        *(int **)(unaff_EBP + -0x10) = piVar5;
        sVar9 = _strlen(&DAT_006cd370);
        iVar12 = (**(code **)(iVar6 + 0x68))(&DAT_006cd370,sVar9);
        iVar6 = *(int *)(unaff_EBP + -0x38);
        iVar11 = extraout_ECX[7];
        *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + iVar11;
        iVar2 = extraout_ECX[8];
        *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + iVar2;
        *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + iVar2;
        (**(code **)(*(int *)extraout_ECX[0x74] + 0x60))
                  ((iVar6 - iVar12) + iVar11,*(undefined4 *)(unaff_EBP + -0x3c),
                   *(undefined4 *)(unaff_EBP + -0x38),*(undefined4 *)(unaff_EBP + -0x34));
        (**(code **)(*(int *)extraout_ECX[0x74] + 0x19c))(0,4,1);
        FUN_005e40ac(extraout_ECX + 0x69);
        iVar6 = extraout_ECX[0x74];
        *(undefined4 *)(iVar6 + 0x160) = 1;
        *(undefined4 *)(iVar6 + 0x11c) = 0;
        *(undefined4 *)(iVar6 + 0x120) = 0;
        *(int *)(iVar6 + 0x124) = *(int *)(iVar6 + 0x84) - *(int *)(iVar6 + 0x7c);
        *(int *)(iVar6 + 0x128) = *(int *)(iVar6 + 0x88) - *(int *)(iVar6 + 0x80);
        *(undefined4 *)(iVar6 + 0x164) = 2;
      }
      pvVar7 = operator_new(0xd4);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0x17;
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005dbd68();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x73] = iVar6;
      if (iVar6 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar6);
        (**(code **)(*(int *)extraout_ECX[0x73] + 0x98))();
      }
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xb8) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 0x18;
      uVar8 = FUN_0041532c(9,unaff_EBP + -0xb8,0);
      cVar3 = FUN_004fff98(0x8a,uVar8);
      if (cVar3 != '\0') {
        FUN_00471655(unaff_EBP + -0x30);
        iVar6 = extraout_ECX[0x43];
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        if (iVar6 != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x1b;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x44] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x1c;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x1d;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x1c;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x45] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x1e;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x1f;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x1e;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x37] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x20;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x21;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x20;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x36] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x22;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x23;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x22;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x38] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x24;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x25;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x24;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x39] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x26;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x27;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x26;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x3a] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x28;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x29;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x28;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x3b] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x2a;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x2b;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x2a;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x3c] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x2c;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x2d;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x2c;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x3d] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x2e;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x2f;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x2e;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x3e] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x30;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x31;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x30;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x3f] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x32;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x33;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x32;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x40] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x34;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x35;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x34;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x42] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x36;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x37;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x36;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x46] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x38;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x39;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x38;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x47] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x3a;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x3b;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x3a;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x48] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x3c;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x3d;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x3c;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x49] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x3e;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x3f;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x3e;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x41] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x40;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x41;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x40;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        if (extraout_ECX[0x74] != 0) {
          FUN_0046fc87(unaff_EBP + -0x14,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x42;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x43;
          FUN_005dd9c8(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0x42;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        FUN_0046fc87(unaff_EBP + -0x14,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x44;
        uVar8 = FUN_0046fc7a();
        FUN_005d4bbf(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x14,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x45;
        uVar8 = FUN_0046fc7a();
        FUN_005d4bbf(uVar8);
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        FUN_0042004f();
        if (extraout_ECX[0x4a] != 0) {
          FUN_0046fc87(unaff_EBP + -0x20,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x46;
          uVar8 = FUN_0046fc7a();
          FUN_005d4956(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0x47;
          FUN_005dd9c8(unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0x46;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0042004f();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0x18;
        FUN_0042004f();
      }
      uVar8 = FUN_005e74ca(0);
      FUN_005dde6d(uVar8);
      FUN_005a5631(0x12c3,extraout_ECX + 0x7d,4);
      if ((int *)extraout_ECX[0x7d] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x7d] + 0x68))(DAT_006f2a64);
      }
      FUN_005a5631(0x12c4,extraout_ECX + 0x7e,4);
      if ((int *)extraout_ECX[0x7e] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x7e] + 0x68))(DAT_006f2a64);
      }
      FUN_005a5631(0x12c5,extraout_ECX + 0x7f,4);
      if ((int *)extraout_ECX[0x7f] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x7f] + 0x68))(DAT_006f2a64);
      }
      FUN_005a5631(0x12c6,extraout_ECX + 0x80,4);
      if ((int *)extraout_ECX[0x80] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x80] + 0x68))(DAT_006f2a64);
      }
      FUN_005a5631(0x7f3,extraout_ECX + 0x81,4);
      piVar5 = (int *)extraout_ECX[0x81];
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x68))(DAT_006f2a64);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
      uVar4 = 1;
    }
  }
  else {
    uVar4 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

