
void FUN_005320ad(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar7;
  
  FUN_00634c24();
  cVar3 = (**(code **)(*extraout_ECX + 200))();
  if (cVar3 == '\0') {
    cVar3 = FUN_004cff80();
    if (cVar3 == '\0') {
      FUN_005a5631(0x1325,extraout_ECX + 0x35,4);
      uVar7 = 0x1338;
    }
    else {
      FUN_005a5631(0x1324,extraout_ECX + 0x35,4);
      uVar7 = 0x1337;
    }
    FUN_005a5631(uVar7,extraout_ECX + 0x36,4);
    (**(code **)(*extraout_ECX + 0x60))(0,0,0x1ab,100);
    cVar3 = FUN_004cff80();
    if (cVar3 != '\0') {
      uVar4 = 0;
      do {
        cVar3 = *(char *)(DAT_006e486c + 100);
        if (cVar3 == '\x14') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar4) = *(undefined4 *)((int)&DAT_006f4480 + uVar4);
          uVar7 = *(undefined4 *)((int)&DAT_006f4484 + uVar4);
        }
        else if (cVar3 == '\x13') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar4) = *(undefined4 *)(&DAT_006f4498 + uVar4);
          uVar7 = *(undefined4 *)(&DAT_006f449c + uVar4);
        }
        else if (cVar3 == '\x12') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar4) = *(undefined4 *)(&DAT_006f4468 + uVar4);
          uVar7 = *(undefined4 *)(&DAT_006f446c + uVar4);
        }
        else if (cVar3 == '\x0f') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar4) = *(undefined4 *)(&DAT_006f4450 + uVar4);
          uVar7 = *(undefined4 *)(&DAT_006f4454 + uVar4);
        }
        else {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar4) = *(undefined4 *)(&DAT_006f44b0 + uVar4);
          uVar7 = *(undefined4 *)(&DAT_006f44b4 + uVar4);
        }
        *(undefined4 *)((int)&DAT_006f44cc + uVar4) = uVar7;
        *(undefined4 *)((int)&DAT_006f4438 + uVar4) = *(undefined4 *)((int)&DAT_006f4420 + uVar4);
        *(undefined4 *)((int)&DAT_006f443c + uVar4) = *(undefined4 *)((int)&DAT_006f4424 + uVar4);
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x18);
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xb4) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar3 = FUN_004fff98(0xab,&DAT_006c265c,unaff_EBP + -0xb4,0);
    if (cVar3 != '\0') {
      FUN_00471655(unaff_EBP + -0x3c);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046fc87(unaff_EBP + -0x20,0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar7 = FUN_0046fc7a();
      FUN_005d4bbf(uVar7);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      *(undefined4 **)(unaff_EBP + -0x10) = &DAT_006f44c8;
      do {
        pvVar5 = operator_new(0x1ac);
        *(void **)(unaff_EBP + -0x1c) = pvVar5;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar5 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_0052c6db();
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(int *)(unaff_EBP + -0x14) = iVar6;
        if (iVar6 != 0) {
          uVar7 = FUN_0046fc7a();
          FUN_005d4956(uVar7);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x9c))(unaff_EBP + -0x34);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x60))(0,0,0x66,0x10);
          FUN_004cb21d(**(undefined4 **)(unaff_EBP + -0x10),(*(undefined4 **)(unaff_EBP + -0x10))[1]
                      );
          *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf8) = 1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf4) = 1;
          iVar6 = *(int *)(unaff_EBP + -0x14);
          *(undefined4 *)(iVar6 + 0x160) = 1;
          *(undefined4 *)(iVar6 + 0x11c) = 0;
          *(undefined4 *)(iVar6 + 0x120) = 0;
          *(undefined4 *)(iVar6 + 0x124) = 0x66;
          *(undefined4 *)(iVar6 + 0x128) = 0x10;
          *(undefined4 *)(iVar6 + 0x164) = 2;
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x19c))(0,4,0);
          FUN_005e4a3a(1);
          FUN_005e4071(DAT_006f2a90);
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
          FUN_0052d5d9(unaff_EBP + -0x14);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
        FUN_005c11ce();
      } while (*(int *)(unaff_EBP + -0x10) < 0x6f44e0);
      uVar7 = FUN_0046fc7a();
      FUN_005d4956(uVar7);
      puVar2 = (undefined4 *)extraout_ECX[0x37];
      *(undefined1 *)(unaff_EBP + -4) = 5;
      (**(code **)(*(int *)*puVar2 + 0x9c))(unaff_EBP + -0x34);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      FUN_0046fc56();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      cVar3 = FUN_004fff98(0xac,&DAT_006c265c,unaff_EBP + -0xb4,0);
      if (cVar3 != '\0') {
        uVar7 = FUN_00471655(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_0046fc63(uVar7);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_0042004f();
        *(undefined4 *)(unaff_EBP + -0x10) = 3;
        do {
          FUN_0046fc87(unaff_EBP + -0x20,0);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          uVar7 = FUN_0046fc7a();
          FUN_005d4956(uVar7);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_004054fa(unaff_EBP + -0x34);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_0042004f();
          FUN_0046fc87(unaff_EBP + -0x18,0);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          uVar7 = FUN_0046fc7a();
          FUN_005d4956(uVar7);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_004054fa(unaff_EBP + -0x48);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_0042004f();
          piVar1 = (int *)(unaff_EBP + -0x10);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      FUN_0046fc87(unaff_EBP + -0x20,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      uVar7 = FUN_0046fc7a();
      FUN_005d4bbf(uVar7);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_0042004f();
      uVar7 = FUN_0046fc7a();
      FUN_005d4bbf(uVar7);
      pvVar5 = operator_new(0x84);
      *(void **)(unaff_EBP + -0x10) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      if (pvVar5 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_00510166(*(undefined4 *)extraout_ECX[0x3e],*(undefined4 *)extraout_ECX[0x41],0,0
                             ,0,0,0,0,0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 6;
      extraout_ECX[0x44] = iVar6;
      if (iVar6 != 0) {
        FUN_00503993(s_petskil_006ccd64);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
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

