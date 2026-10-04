
undefined4 FUN_0057ccc8(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int extraout_ECX;
  undefined4 *extraout_ECX_00;
  int unaff_EBP;
  undefined4 *puStack_34;
  undefined4 *puStack_30;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  puStack_30 = (undefined4 *)0x57cce5;
  FUN_0057ceb6();
  DAT_006f6a18 = 0;
  puStack_30 = (undefined4 *)0x57ccf6;
  FUN_0058059c();
  if (DAT_006f68f8 != '\0') {
    DAT_006f68f8 = '\0';
  }
  DAT_006f6848 = 0;
  DAT_006f6998 = 0;
  puStack_30 = (undefined4 *)(unaff_EBP + -0x2c);
  puStack_34 = (undefined4 *)0x57cd23;
  FUN_00580a92();
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  while( true ) {
    if (*(int *)(unaff_EBP + -0x2c) == *(int *)(unaff_EBP + -0x24)) {
      puStack_30 = (undefined4 *)0x57cd74;
      FUN_005824b6();
      puStack_30 = (undefined4 *)(unaff_EBP + -0x2c);
      puStack_34 = (undefined4 *)0x57cd85;
      FUN_00580a92();
      iVar2 = *(int *)(unaff_EBP + -0x2c);
      *(int *)(unaff_EBP + -0x1c) = iVar2;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x28);
      while (iVar2 != 0) {
        puVar3 = *(undefined4 **)(*(int *)(unaff_EBP + -0x1c) + 8);
        if (puVar3 != (undefined4 *)0x0) {
          puStack_30 = (undefined4 *)0x57cda6;
          FUN_0057ce80();
          puStack_34 = (undefined4 *)0x57cdac;
          puStack_30 = puVar3;
          FUN_006321f0();
        }
        puStack_30 = (undefined4 *)0x57cdb5;
        FUN_00576e56();
        iVar2 = *(int *)(unaff_EBP + -0x1c);
      }
      puStack_34 = (undefined4 *)0x0;
      puStack_30 = (undefined4 *)(extraout_ECX + 0xd8);
      FUN_00581ddc(*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28));
      puStack_30 = (undefined4 *)(unaff_EBP + -0x1c);
      puStack_34 = (undefined4 *)0x57cddd;
      FUN_00580a92();
      iVar2 = *(int *)(unaff_EBP + -0x1c);
      *(int *)(unaff_EBP + -0x2c) = iVar2;
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      while (iVar2 != 0) {
        puVar3 = *(undefined4 **)(*(int *)(unaff_EBP + -0x2c) + 8);
        if (puVar3 != (undefined4 *)0x0) {
          puStack_30 = (undefined4 *)0x1;
          puStack_34 = (undefined4 *)0x57cdff;
          (**(code **)*puVar3)();
        }
        puStack_30 = (undefined4 *)0x57ce07;
        FUN_00576e56();
        iVar2 = *(int *)(unaff_EBP + -0x2c);
      }
      puStack_34 = (undefined4 *)0x0;
      puStack_30 = (undefined4 *)(extraout_ECX + 0xec);
      FUN_00581ddc(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
      puVar3 = *(undefined4 **)(extraout_ECX + 0xac);
      puVar5 = (undefined4 *)*puVar3;
      puStack_30 = extraout_ECX_00;
      while (*(undefined4 **)(unaff_EBP + -0x14) = puVar5, puVar5 != puVar3) {
        puStack_30 = (undefined4 *)puVar5[2];
        puStack_34 = (undefined4 *)0x57ce39;
        FUN_006321f0();
        puVar5 = (undefined4 *)**(undefined4 **)(unaff_EBP + -0x14);
      }
      *(undefined4 ***)(unaff_EBP + -0x18) = &puStack_30;
      *(undefined4 ***)(unaff_EBP + -0x18) = &puStack_34;
      puStack_34 = puStack_30;
      puStack_30 = puVar3;
      FUN_00602c56(unaff_EBP + -0x14);
      FUN_00578f92(unaff_EBP + -0x20);
      puStack_30 = (undefined4 *)0x57ce6b;
      FUN_004d5360();
      *(undefined1 *)(extraout_ECX + 0x54) = 0;
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    piVar1 = *(int **)(*(int *)(unaff_EBP + -0x2c) + 8);
    if (piVar1 != (int *)0x0) break;
    puStack_30 = (undefined4 *)0x57cd67;
    FUN_00576e56();
  }
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puStack_30 = (undefined4 *)0x57cd41;
  (**(code **)(iVar2 + 0xc))();
  puStack_30 = (undefined4 *)0x1;
  puStack_34 = (undefined4 *)0x57cd49;
  (**(code **)*piVar1)();
  uVar4 = FUN_0057cd54();
  return uVar4;
}

