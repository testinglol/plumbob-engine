
void FUN_0053166b(void)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar6;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    cVar2 = FUN_004cff80();
    if (cVar2 == '\0') {
      FUN_005a5631(0x1325,extraout_ECX + 0x35,4);
      uVar6 = 0x1338;
    }
    else {
      FUN_005a5631(0x1324,extraout_ECX + 0x35,4);
      uVar6 = 0x1337;
    }
    FUN_005a5631(uVar6,extraout_ECX + 0x36,4);
    (**(code **)(*extraout_ECX + 0x60))(0,0,0x1ab,100);
    cVar2 = FUN_004cff80();
    if (cVar2 != '\0') {
      uVar3 = 0;
      do {
        cVar2 = *(char *)(DAT_006e486c + 100);
        if (cVar2 == '\x14') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar3) = *(undefined4 *)((int)&DAT_006f4480 + uVar3);
          uVar6 = *(undefined4 *)((int)&DAT_006f4484 + uVar3);
        }
        else if (cVar2 == '\x13') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar3) = *(undefined4 *)(&DAT_006f4498 + uVar3);
          uVar6 = *(undefined4 *)(&DAT_006f449c + uVar3);
        }
        else if (cVar2 == '\x12') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar3) = *(undefined4 *)(&DAT_006f4468 + uVar3);
          uVar6 = *(undefined4 *)(&DAT_006f446c + uVar3);
        }
        else if (cVar2 == '\x0f') {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar3) = *(undefined4 *)(&DAT_006f4450 + uVar3);
          uVar6 = *(undefined4 *)(&DAT_006f4454 + uVar3);
        }
        else {
          *(undefined4 *)((int)&DAT_006f44c8 + uVar3) = *(undefined4 *)(&DAT_006f44b0 + uVar3);
          uVar6 = *(undefined4 *)(&DAT_006f44b4 + uVar3);
        }
        *(undefined4 *)((int)&DAT_006f44cc + uVar3) = uVar6;
        *(undefined4 *)((int)&DAT_006f4438 + uVar3) = *(undefined4 *)((int)&DAT_006f4420 + uVar3);
        *(undefined4 *)((int)&DAT_006f443c + uVar3) = *(undefined4 *)((int)&DAT_006f4424 + uVar3);
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x18);
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xb8) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar2 = FUN_004fff98(0xab,&DAT_006c265c,unaff_EBP + -0xb8,0);
    if (cVar2 != '\0') {
      FUN_00471655(unaff_EBP + -0x28);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046fc87(unaff_EBP + -0x20,0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar6 = FUN_0046fc7a();
      FUN_005d4bbf(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      *(undefined4 **)(unaff_EBP + -0x10) = &DAT_006f44c8;
      do {
        pvVar4 = operator_new(0x1ac);
        *(void **)(unaff_EBP + -0x1c) = pvVar4;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar4 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_0052c6db();
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(int *)(unaff_EBP + -0x14) = iVar5;
        if (iVar5 != 0) {
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x9c))(unaff_EBP + -0x34);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x60))(0,0,0x66,0x10);
          FUN_004cb21d(**(undefined4 **)(unaff_EBP + -0x10),(*(undefined4 **)(unaff_EBP + -0x10))[1]
                      );
          *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf8) = 1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf4) = 1;
          iVar5 = *(int *)(unaff_EBP + -0x14);
          *(undefined4 *)(iVar5 + 0x160) = 1;
          *(undefined4 *)(iVar5 + 0x11c) = 0;
          *(undefined4 *)(iVar5 + 0x120) = 0;
          *(undefined4 *)(iVar5 + 0x124) = 0x66;
          *(undefined4 *)(iVar5 + 0x128) = 0x10;
          *(undefined4 *)(iVar5 + 0x164) = 2;
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x19c))(0,4,0);
          FUN_005e4a3a(1);
          FUN_005e4071(DAT_006f2a90);
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
          FUN_0052d5d9(unaff_EBP + -0x14);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
        FUN_005c11ce();
      } while (*(int *)(unaff_EBP + -0x10) < 0x6f44e0);
      cVar2 = FUN_004fff98(0xac,&DAT_006c265c,unaff_EBP + -0xb8,0);
      if (cVar2 != '\0') {
        FUN_00471655(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        *(undefined4 *)(unaff_EBP + -0x10) = 3;
        do {
          FUN_0046fc87(unaff_EBP + -0x18,0);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_004054fa(unaff_EBP + -0x40);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_0042004f();
          FUN_0046fc87(unaff_EBP + -0x30,0);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_004054fa(unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_0042004f();
          piVar1 = (int *)(unaff_EBP + -0x10);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
      }
      pvVar4 = operator_new(0x84);
      *(void **)(unaff_EBP + -0x10) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 10;
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00510166(*(undefined4 *)extraout_ECX[0x3e],*(undefined4 *)extraout_ECX[0x41],0,0
                             ,0,0,0,0,0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      extraout_ECX[0x44] = iVar5;
      if (iVar5 != 0) {
        FUN_00503993(s_petskil_006ccd64);
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

