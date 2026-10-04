
uint FUN_004c24d2(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int unaff_EBP;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  uVar6 = *(uint *)(extraout_ECX + 0x1c);
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if ((uVar6 == 0) || (*(uint *)(extraout_ECX + 0x148) != uVar6)) {
    piVar1 = *(int **)(DAT_006e486c + 4);
    *(undefined1 *)(unaff_EBP + -0x11) = 1;
    uStack_34 = 0x4c2515;
    uVar5 = (**(code **)(*piVar1 + 0x18))();
    *(undefined4 *)(extraout_ECX + 0x10) = uVar5;
    uStack_34 = 0x4c2525;
    uVar5 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x14))();
    uStack_34 = *(undefined4 *)(extraout_ECX + 0x2c);
    *(undefined4 *)(extraout_ECX + 0x14) = uVar5;
    uStack_38 = 0x4c2536;
    uVar5 = FUN_004c2743();
    *(undefined4 *)(extraout_ECX + 0x30) = uVar5;
    *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(extraout_ECX + 8);
    *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(extraout_ECX + 9);
    *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(extraout_ECX + 10);
    iVar2 = *(int *)(extraout_ECX + 4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      uStack_34 = *(undefined4 *)(extraout_ECX + 0x10);
      *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(iVar2 + 0xfc);
      *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(iVar2 + 0xfd);
      *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(iVar2 + 0xfe);
      uStack_38 = 0x4c257a;
      FUN_00434ffd();
    }
    if (*(int **)(extraout_ECX + 0x14c) != (int *)0x0) {
      uStack_34 = 1;
      uStack_38 = 0x4c258e;
      cVar3 = (**(code **)(**(int **)(extraout_ECX + 0x14c) + 0x20))();
      if (cVar3 != '\0') {
        uStack_38 = 0;
        uStack_3c = 0;
        uStack_40 = 0x4c259f;
        (**(code **)(**(int **)(extraout_ECX + 0x14c) + 0x38))();
        uStack_40 = 1;
        uStack_44 = 0x4c25ab;
        (**(code **)(**(int **)(extraout_ECX + 0x14c) + 0x24))();
      }
      piVar1 = *(int **)(*(int *)(extraout_ECX + 0x14c) + 0x5c);
      uStack_50 = 0;
      if (piVar1 != (int *)0x0) {
        uStack_38 = 1;
        uStack_3c = 0x4c25be;
        cVar3 = (**(code **)(*piVar1 + 0x20))();
        uStack_50 = extraout_ECX_00;
        if (cVar3 != '\0') {
          uStack_38 = 0;
          uStack_3c = 0xffff;
          uStack_40 = 0x4c25d6;
          (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x14c) + 0x5c) + 0x38))();
          uStack_40 = 1;
          uStack_44 = 0x4c25e5;
          (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x14c) + 0x5c) + 0x24))();
          uStack_50 = extraout_ECX_01;
        }
      }
      uStack_38 = *(undefined4 *)(extraout_ECX + 0x30);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uStack_3c = *(undefined4 *)(extraout_ECX + 0x28);
      uStack_40 = *(undefined4 *)(extraout_ECX + 0x24);
      uStack_44 = *(undefined4 *)(extraout_ECX + 0x10);
      uStack_48 = *(undefined4 *)(extraout_ECX + 0x14);
      uStack_4c = *(undefined4 *)(extraout_ECX + 0x14c);
      *(undefined4 **)(unaff_EBP + -0x20) = &uStack_50;
      FUN_00461b74(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004c273a();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_004b39b1();
      *(undefined1 *)(unaff_EBP + -0x11) = uVar4;
      uVar6 = FUN_004c2633();
      return uVar6;
    }
    *(int *)(extraout_ECX + 0x148) = *(int *)(extraout_ECX + 0x148) + 1;
    uVar5 = DAT_006e5490;
    *(undefined4 *)(extraout_ECX + 0x144) = DAT_006e5490;
    uVar6 = CONCAT31((int3)((uint)uVar5 >> 8),*(undefined1 *)(unaff_EBP + -0x11));
  }
  else {
    uVar6 = uVar6 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

