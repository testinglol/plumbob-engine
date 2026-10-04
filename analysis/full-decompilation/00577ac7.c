
undefined4 FUN_00577ac7(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x14) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((char)iVar1 != '\0') {
    if (*(char *)((int)extraout_ECX + 0x40a9) != '\0') {
      (**(code **)(*extraout_ECX + 0x6c))();
    }
    if ((char)extraout_ECX[0xf] == '\0') {
      *(undefined1 *)((int)extraout_ECX + 0x3d) = 0;
      extraout_ECX[0x10] = *(int *)(extraout_ECX[0xd] + 0x2c);
      FUN_005bc6cb(0xffffffff);
      extraout_ECX[0x18] = *(int *)(extraout_ECX[0xd] + 0x30);
      iVar1 = *(int *)(extraout_ECX[0xd] + 0x30);
      if (2 < iVar1) {
        extraout_ECX[0x18] = iVar1 + -1;
      }
      extraout_ECX[0x16] = extraout_ECX[0x18];
      extraout_ECX[0x17] = extraout_ECX[0x18];
      FUN_00578cda();
      puVar2 = operator_new(0x20);
      *(undefined4 **)(unaff_EBP + -0x10) = puVar2;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2[2] = 0;
        puVar2[4] = 0;
        *puVar2 = 1;
        puVar2[3] = 0;
        puVar2[5] = 0;
        uVar3 = FUN_005fd96f();
        puVar2[6] = uVar3;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      extraout_ECX[0xc] = (int)puVar2;
      FUN_005772e2();
      FUN_005fd8ea();
      (**(code **)(*extraout_ECX + 0x34))(*(undefined4 *)(extraout_ECX[0xd] + 0x3c));
      (**(code **)(*extraout_ECX + 0x30))(*(undefined4 *)(extraout_ECX[0xd] + 0x40));
      FUN_005771d6(extraout_ECX);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined1 *)(extraout_ECX + 0xf) = 1;
      goto LAB_00577bd0;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00577bd0:
  (**(code **)(DAT_006f63e8 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

