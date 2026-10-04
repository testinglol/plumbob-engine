
void FUN_0040afbd(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  undefined4 *puVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00636080();
  uVar3 = *(undefined4 *)(extraout_ECX + 8);
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
  FUN_00472fca(uVar3,2);
  FUN_0040d069(unaff_EBP + -0x140);
  FUN_0046f824(unaff_EBP + -0x124,0,4);
  *(undefined ***)(unaff_EBP + -0x130) = &PTR_FUN_0066663c;
  FUN_0046f847(*(int *)(unaff_EBP + -0x478) + 1,3);
  FUN_0046f824(unaff_EBP + -0xb4,0,4);
  *(undefined ***)(unaff_EBP + -0xc0) = &PTR_FUN_0066663c;
  FUN_0046f847(*(int *)(unaff_EBP + -0x478) + 6,3);
  FUN_0046f824(unaff_EBP + -0x180,0,0x40);
  *(undefined ***)(unaff_EBP + -0x18c) = &PTR_FUN_0066651c;
  FUN_0040b7bc(unaff_EBP + -0x430,unaff_EBP + -0x18c);
  *(undefined1 **)(unaff_EBP + -0x10) = &DAT_006de560;
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    *(undefined **)(unaff_EBP + -0x10) = &DAT_006c0f98;
  }
  else if (iVar2 == 1) {
    *(undefined **)(unaff_EBP + -0x10) = &DAT_006c0f9c;
  }
  FUN_0040b75a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047274f(&DAT_006c0ffc);
  FUN_004727bd(&DAT_006c0ff8,*(undefined4 *)(unaff_EBP + -0x10));
  FUN_0047274f(*(undefined4 *)(unaff_EBP + -0xbc));
  FUN_0040b7f3(unaff_EBP + -0x2b8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0047274f(*(undefined4 *)(unaff_EBP + -0x13c));
  FUN_004727bd(*(undefined4 *)(unaff_EBP + -0x188),&DAT_006de560);
  FUN_0040b7f3(unaff_EBP + -0x3e4);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004728b5(&DAT_006c0ff8);
  FUN_0040b7f3(unaff_EBP + -0x2b8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004728b5(&DAT_006c0fb0);
  FUN_0040b7f3(unaff_EBP + -0x3e4);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004728b5(&DAT_006c0fb0);
  FUN_00635e55(unaff_EBP + -0x1160,300,8,FUN_0040b75a,thunk_FUN_00409919);
  *(undefined **)(unaff_EBP + -0x120) = &DAT_006c0ff4;
  *(undefined **)(unaff_EBP + -0x114) = &DAT_006c0ff4;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined **)(unaff_EBP + -0x11c) = &DAT_006c0fb8;
  *(undefined **)(unaff_EBP + -0x118) = &DAT_006c0ff0;
  *(undefined **)(unaff_EBP + -0x110) = &DAT_006c0fec;
  *(undefined **)(unaff_EBP + -0x10c) = &DAT_006c0ff0;
  *(undefined **)(unaff_EBP + -0x108) = &DAT_006c0fc0;
  *(undefined **)(unaff_EBP + -0x104) = &DAT_006c0fb8;
  *(undefined **)(unaff_EBP + -0x100) = &DAT_006c0ff0;
  *(undefined **)(unaff_EBP + -0xfc) = &DAT_006c0fc0;
  *(undefined **)(unaff_EBP + -0xf8) = &DAT_006c0fec;
  *(undefined **)(unaff_EBP + -0xf4) = &DAT_006c0ff0;
  *(undefined **)(unaff_EBP + -0xe0) = &DAT_006c0fec;
  *(undefined **)(unaff_EBP + -200) = &DAT_006c0fec;
  *(undefined **)(unaff_EBP + -0xe8) = &DAT_006c0fe8;
  *(undefined **)(unaff_EBP + -0xdc) = &DAT_006c0fe8;
  *(int *)(unaff_EBP + -0x14) = unaff_EBP + -0x1160;
  *(undefined **)(unaff_EBP + -0xf0) = &DAT_006c0fc0;
  *(undefined **)(unaff_EBP + -0xec) = &DAT_006c0fb8;
  *(undefined **)(unaff_EBP + -0xe4) = &DAT_006c0fc0;
  *(undefined **)(unaff_EBP + -0xd8) = &DAT_006c0fc0;
  *(undefined **)(unaff_EBP + -0xd4) = &DAT_006c0fb8;
  *(undefined2 **)(unaff_EBP + -0xd0) = &DAT_006c0fe4;
  *(undefined **)(unaff_EBP + -0xcc) = &DAT_006c0fc0;
  *(undefined2 **)(unaff_EBP + -0xc4) = &DAT_006c0fe4;
  *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x11c;
  *(undefined4 *)(unaff_EBP + -0x18) = 8;
  do {
    FUN_0047274f(*(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + -4));
    FUN_004727bd(&DAT_006c0ff8,*(undefined4 *)(unaff_EBP + -0x10));
    FUN_004727bd(&DAT_006c0fe0,**(undefined4 **)(unaff_EBP + -0x1c));
    FUN_0047274f(*(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4));
    FUN_004727bd(*(undefined4 *)(unaff_EBP + -0x13c),&DAT_006de560);
    FUN_004727bd(*(undefined4 *)(unaff_EBP + -0x188),&DAT_006de560);
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0xc;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 300;
    piVar1 = (int *)(unaff_EBP + -0x18);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  *(undefined4 *)(unaff_EBP + -0xa8) = 0;
  *(int *)(unaff_EBP + -0xb0) = unaff_EBP + -0x2b8;
  *(int *)(unaff_EBP + -0xac) = unaff_EBP + -0x800;
  iVar2 = FUN_00409291();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x18) = iVar2;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
      if (unaff_EBP != 0x2b8) {
        iVar2 = unaff_EBP + -0x2b8;
        iVar5 = unaff_EBP + -0xb0;
        do {
          FUN_00472b1d(*(undefined4 *)(unaff_EBP + -0x20));
          iVar2 = (*(code *)**(undefined4 **)(iVar2 + 0x20))();
          if (iVar2 != 0) break;
          iVar2 = *(int *)(iVar5 + 4);
          iVar5 = iVar5 + 4;
        } while (iVar2 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
  }
  *(undefined4 *)(unaff_EBP + -0x78) = 0;
  *(int *)(unaff_EBP + -0xa4) = unaff_EBP + -0x1160;
  *(int *)(unaff_EBP + -0xa0) = unaff_EBP + -0x1034;
  *(int *)(unaff_EBP + -0x9c) = unaff_EBP + -0xf08;
  *(int *)(unaff_EBP + -0x98) = unaff_EBP + -0xddc;
  *(int *)(unaff_EBP + -0x94) = unaff_EBP + -0xcb0;
  *(int *)(unaff_EBP + -0x90) = unaff_EBP + -0xb84;
  *(int *)(unaff_EBP + -0x8c) = unaff_EBP + -0xa58;
  *(int *)(unaff_EBP + -0x88) = unaff_EBP + -0x92c;
  *(int *)(unaff_EBP + -0x84) = unaff_EBP + -0x6d4;
  *(int *)(unaff_EBP + -0x80) = unaff_EBP + -0x3e4;
  *(int *)(unaff_EBP + -0x7c) = unaff_EBP + -0x5a8;
  FUN_004089ca();
  iVar2 = (DAT_006e4864 - DAT_006e4860) / 0x4c;
  if (0 < iVar2) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    do {
      FUN_004089ca();
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x10) + DAT_006e4860;
      if (unaff_EBP != 0x1160) {
        iVar2 = unaff_EBP + -0xa4;
        do {
          FUN_00472b1d(*(undefined4 *)(unaff_EBP + -0x20));
          piVar1 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 4;
        } while (*piVar1 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x4c;
      piVar1 = (int *)(unaff_EBP + -0x18);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  FUN_0046f824(unaff_EBP + -0x68,0,0x40);
  *(undefined2 *)(unaff_EBP + -0x6c) = 0;
  *(undefined ***)(unaff_EBP + -0x74) = &PTR_FUN_0066651c;
  **(undefined1 **)(unaff_EBP + -0x70) = 0;
  FUN_0046f917(unaff_EBP + -0x298,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x3c4,0xffffffff);
  FUN_005876ac(0x10,*(undefined4 *)(unaff_EBP + -0x70));
  *(undefined2 *)(unaff_EBP + -0x6c) = 0;
  **(undefined1 **)(unaff_EBP + -0x70) = 0;
  FUN_0046f917(unaff_EBP + -0x298,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  iVar2 = (*(code *)**(undefined4 **)(unaff_EBP + -0x588))();
  if (iVar2 == 0) {
    iVar2 = FUN_0040cc3f();
    if (iVar2 == 1) {
      iVar2 = unaff_EBP + -0x3c4;
      goto LAB_0040b53d;
    }
  }
  iVar2 = unaff_EBP + -0x588;
LAB_0040b53d:
  FUN_0046f917(iVar2,0xffffffff);
  FUN_005876ac(0x11,*(undefined4 *)(unaff_EBP + -0x70));
  *(undefined2 *)(unaff_EBP + -0x6c) = 0;
  **(undefined1 **)(unaff_EBP + -0x70) = 0;
  FUN_0046f917(unaff_EBP + -0x7e0,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x6b4,0xffffffff);
  FUN_005876ac(0x1c,*(undefined4 *)(unaff_EBP + -0x70));
  *(undefined1 *)(unaff_EBP + -0x10) = 0x75;
  iVar2 = FUN_0040cc3f();
  if (iVar2 == 0) {
    iVar2 = FUN_0040cd0e();
    if (iVar2 == 0) {
      *(undefined1 *)(unaff_EBP + -0x10) = 0x6d;
    }
    else if (iVar2 == 1) {
      *(undefined1 *)(unaff_EBP + -0x10) = 0x66;
    }
  }
  else if (iVar2 == 1) {
    *(undefined1 *)(unaff_EBP + -0x10) = 0x75;
  }
  puVar4 = (undefined4 *)(unaff_EBP + -0x1140);
  *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x94;
  *(undefined4 *)(unaff_EBP + -0x94) = 0x1d;
  *(undefined4 *)(unaff_EBP + -0x90) = 0x1e;
  *(undefined4 *)(unaff_EBP + -0x8c) = 0x12;
  *(undefined4 *)(unaff_EBP + -0x88) = 0x13;
  *(undefined4 *)(unaff_EBP + -0x84) = 0x16;
  *(undefined4 *)(unaff_EBP + -0x80) = 0x17;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0x14;
  *(undefined4 *)(unaff_EBP + -0x78) = 0x15;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar4;
  *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x118;
  *(undefined4 *)(unaff_EBP + -0x20) = 8;
  while( true ) {
    *(undefined2 *)(unaff_EBP + -0x6c) = 0;
    **(undefined1 **)(unaff_EBP + -0x70) = 0;
    iVar2 = (**(code **)*puVar4)();
    if (iVar2 != 0) {
      FUN_0046f847(&DAT_006c0fc0,0xffffffff);
      FUN_0046fa24(*(undefined4 *)(unaff_EBP + -0x10));
      FUN_0046f847(*(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + -4),0xffffffff);
      FUN_0046f847(**(undefined4 **)(unaff_EBP + -0x1c),0xffffffff);
      FUN_0046f847(&DAT_006c0fdc,0xffffffff);
      FUN_0046f917(&DAT_006f6c20,0xffffffff);
      FUN_0046f917(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
    }
    FUN_005876ac(**(undefined4 **)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x70));
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0xc;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 300;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
    piVar1 = (int *)(unaff_EBP + -0x20);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) break;
    puVar4 = *(undefined4 **)(unaff_EBP + -0x14);
  }
  FUN_004eae06(**(undefined4 **)(unaff_EBP + -0x24),(*(undefined4 **)(unaff_EBP + -0x24))[1]);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00635f6d(unaff_EBP + -0x1160,300,8,thunk_FUN_00409919);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00409919();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00409919();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00409919();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00409919();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

