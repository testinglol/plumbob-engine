
void FUN_0052dde1(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    FUN_005a5631(0x1324,extraout_ECX + 0x35,4);
    FUN_005a5631(0x1337,extraout_ECX + 0x36,4);
    extraout_ECX[0x3a] = DAT_006f2a98;
    (**(code **)(*extraout_ECX + 0x60))(0,0,0x1ab,100);
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xc0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004cff80();
    if (cVar1 != '\0') {
      iVar3 = 0;
      do {
        cVar1 = *(char *)(DAT_006e486c + 100);
        if (cVar1 == '\x12') {
          *(undefined4 *)((int)&DAT_006f4120 + iVar3) = *(undefined4 *)((int)&DAT_006f4090 + iVar3);
          uVar4 = *(undefined4 *)((int)&DAT_006f4094 + iVar3);
LAB_0052defb:
          *(undefined4 *)((int)&DAT_006f4124 + iVar3) = uVar4;
          *(undefined4 *)((int)&DAT_006f3fb8 + iVar3) = *(undefined4 *)((int)&DAT_006f3f70 + iVar3);
          uVar4 = *(undefined4 *)((int)&DAT_006f3f74 + iVar3);
        }
        else {
          if (cVar1 == '\x0f') {
            *(undefined4 *)((int)&DAT_006f4120 + iVar3) = *(undefined4 *)(&DAT_006f4048 + iVar3);
            uVar4 = *(undefined4 *)(&DAT_006f404c + iVar3);
            goto LAB_0052defb;
          }
          if (cVar1 != '\x13') {
            *(undefined4 *)((int)&DAT_006f4120 + iVar3) = *(undefined4 *)(&DAT_006f40d8 + iVar3);
            uVar4 = *(undefined4 *)(&DAT_006f40dc + iVar3);
            goto LAB_0052defb;
          }
          *(undefined4 *)((int)&DAT_006f4120 + iVar3) = *(undefined4 *)(&DAT_006f4000 + iVar3);
          *(undefined4 *)((int)&DAT_006f4124 + iVar3) = *(undefined4 *)(&DAT_006f4004 + iVar3);
          *(undefined4 *)((int)&DAT_006f3fb8 + iVar3) = *(undefined4 *)(&DAT_006f3f28 + iVar3);
          uVar4 = *(undefined4 *)(&DAT_006f3f2c + iVar3);
        }
        *(undefined4 *)((int)&DAT_006f3fbc + iVar3) = uVar4;
        *(undefined4 *)((int)&DAT_006f3ee0 + iVar3) = *(undefined4 *)((int)&DAT_006f3e98 + iVar3);
        *(undefined4 *)((int)&DAT_006f3ee4 + iVar3) = *(undefined4 *)((int)&DAT_006f3e9c + iVar3);
        iVar3 = iVar3 + 8;
      } while (iVar3 < 0x48);
    }
    cVar1 = FUN_004fff98(0x85,&DAT_006c265c,unaff_EBP + -0xc0,0);
    if (cVar1 != '\0') {
      FUN_00471655(unaff_EBP + -0x2c);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046fc87(unaff_EBP + -0x1c,0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar4 = FUN_0046fc7a();
      FUN_005d4bbf(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      iVar3 = 0;
      uVar4 = FUN_0047166d(unaff_EBP + -0x24);
      while( true ) {
        *(undefined1 *)(unaff_EBP + -4) = 3;
        uVar2 = FUN_0046fc3a(uVar4);
        *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
        if (*(char *)(unaff_EBP + -0xd) == '\0') break;
        pvVar5 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x18) = pvVar5;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        if (pvVar5 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005e372a();
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(int *)(unaff_EBP + -0x14) = iVar6;
        if (iVar6 != 0) {
          if (iVar3 < 5) {
            FUN_0046fc87(unaff_EBP + -0x54,0);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            uVar4 = FUN_0046fc7a();
            FUN_005d4956(uVar4);
            *(undefined1 *)(unaff_EBP + -4) = 6;
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x9c))(unaff_EBP + -0x40);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_0042004f();
          }
          else {
            FUN_0046fc87(unaff_EBP + -0x34,0);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            uVar4 = FUN_0046fc7a();
            FUN_005d4bbf(uVar4);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_0042004f();
            *(undefined1 *)(*(int *)(unaff_EBP + -0x14) + 0x173) = 0;
          }
          if (*(char *)(DAT_006e486c + 100) == '\x03') {
            FUN_004cb1a2((&DAT_006f3fb8)[iVar3 * 2] + 0xc,(&DAT_006f3fbc)[iVar3 * 2]);
            uVar4 = (&DAT_006f4124)[iVar3 * 2];
            iVar6 = (&DAT_006f4120)[iVar3 * 2] + -6;
          }
          else {
            FUN_004cb1a2((&DAT_006f3fb8)[iVar3 * 2],(&DAT_006f3fbc)[iVar3 * 2]);
            uVar4 = (&DAT_006f4124)[iVar3 * 2];
            iVar6 = (&DAT_006f4120)[iVar3 * 2];
          }
          FUN_004cb21d(iVar6,uVar4);
          *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf8) = 1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf4) = 1;
          FUN_005e4ada(2);
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x19c))(0,4,0);
          FUN_005e4a3a(1);
          uVar4 = DAT_006f2a94;
          if ((iVar3 == 8) && (*(char *)(DAT_006e486c + 100) == '\x03')) {
            uVar4 = DAT_006f2a90;
          }
          FUN_005e4071(uVar4);
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
          FUN_00524c70(unaff_EBP + -0x14);
          iVar3 = iVar3 + 1;
        }
        uVar4 = FUN_0047166d(unaff_EBP + -0x24);
      }
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 **)(unaff_EBP + -0x14) = &DAT_006f3ee0;
      do {
        iVar3 = *(int *)(extraout_ECX[0x37] + *(int *)(unaff_EBP + -0x20));
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar3 + 0x4c);
        piVar7 = (int *)FUN_005e40a5();
        uVar4 = (**(code **)(*piVar7 + 0x68))
                          (*(undefined4 *)(unaff_EBP + -0x18),
                           *(int *)(iVar3 + 0x50) - *(int *)(iVar3 + 0x4c));
        *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
        piVar7 = (int *)FUN_005e40a5();
        uVar4 = (**(code **)(*piVar7 + 0x58))();
        FUN_004cb1a2(*(undefined4 *)(unaff_EBP + -0x18),uVar4);
        FUN_00512c83(((**(int **)(unaff_EBP + -0x14) - *(int *)(iVar3 + 0x7c)) -
                     *(int *)(unaff_EBP + -0x18)) + -3,0);
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 8;
      } while (*(int *)(unaff_EBP + -0x14) < 0x6f3f01);
      cVar1 = FUN_004fff98(0x87,&DAT_006c265c,unaff_EBP + -0xc0,0);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        uVar4 = FUN_0047166d(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        uVar2 = FUN_0046fc3a(uVar4);
        *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_0042004f();
        cVar1 = *(char *)(unaff_EBP + -0xd);
        while (cVar1 != '\0') {
          FUN_0046fc87(unaff_EBP + -0x34,0);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          uVar4 = FUN_0046fc7a();
          FUN_005d4956(uVar4);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_004054fa(unaff_EBP + -0x40);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_0042004f();
          FUN_0046fc87(unaff_EBP + -0x54,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar4 = FUN_0046fc7a();
          FUN_005d4956(uVar4);
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_004054fa(unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_0042004f();
          uVar4 = FUN_0047166d(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          uVar2 = FUN_0046fc3a(uVar4);
          *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_0042004f();
          cVar1 = *(char *)(unaff_EBP + -0xd);
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
      }
      cVar1 = FUN_004fff98(0x8a,&DAT_006c265c,unaff_EBP + -0xc0,0);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        uVar4 = FUN_0047166d(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        uVar2 = FUN_0046fc3a(uVar4);
        *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_0042004f();
        cVar1 = *(char *)(unaff_EBP + -0xd);
        while (cVar1 != '\0') {
          FUN_0046fc87(unaff_EBP + -0x34,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          uVar4 = FUN_0046fc7a();
          FUN_005d4956(uVar4);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_004054fa(unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          FUN_0042004f();
          uVar4 = FUN_0047166d(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          uVar2 = FUN_0046fc3a(uVar4);
          *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          FUN_0042004f();
          cVar1 = *(char *)(unaff_EBP + -0xd);
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
      }
      pvVar5 = operator_new(0x84);
      *(void **)(unaff_EBP + -0x18) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      if (pvVar5 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00510166(*(undefined4 *)extraout_ECX[0x3c],*(undefined4 *)extraout_ECX[0x3f],0,0
                             ,0,0,0,0,0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      extraout_ECX[0x45] = iVar3;
      if (iVar3 != 0) {
        FUN_00503993(s_house_006cb814);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  FUN_005dbf32();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

