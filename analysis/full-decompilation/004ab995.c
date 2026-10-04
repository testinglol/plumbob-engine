
undefined1 FUN_004ab995(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar9;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  uStack_34 = *(undefined4 *)(unaff_EBP + 0xc);
  iStack_3c = 0x4ab9b3;
  iStack_38 = iVar5;
  uVar2 = FUN_00476c67();
  iVar9 = (int)*(short *)(iVar5 + 0xe);
  iVar6 = extraout_ECX[10];
  *(undefined1 *)(unaff_EBP + 0xb) = uVar2;
  iVar4 = (int)*(short *)(iVar5 + 0xc);
  *(int *)(unaff_EBP + -0x2c) = iVar4;
  if ((((iVar9 < iVar6) || (extraout_ECX[0xc] < iVar9)) || (iVar4 < extraout_ECX[0xb])) ||
     (extraout_ECX[0xd] < iVar4)) {
    uStack_34 = 0x4ab9e5;
    iVar5 = FUN_00401f6f();
    if (iVar5 == 4) {
      *(undefined1 *)(extraout_ECX + 0x130) = 0;
    }
  }
  else {
    uStack_34 = 0x4aba0a;
    iVar6 = FUN_00401f6f();
    if (iVar6 == 4) {
      iVar6 = *(int *)(unaff_EBP + -0x2c);
      *(undefined1 *)(extraout_ECX + 0x130) = 1;
      extraout_ECX[0x131] = iVar9;
      extraout_ECX[0x132] = iVar6;
    }
    if ((*(short *)(unaff_EBP + 0xc) == 0) && (*(char *)((int)extraout_ECX + 0x49) != '\0')) {
      uVar1 = *(undefined4 *)(iVar5 + 0xc);
      uStack_34 = 1;
      iStack_3c = unaff_EBP + -0x28;
      uStack_40 = 0x4aba4b;
      iStack_38 = uVar1;
      (**(code **)(*extraout_ECX + 4))();
      uStack_40 = unaff_EBP + -0x28;
      cVar3 = FUN_00484ba0();
      if (cVar3 == '\0') {
        iVar5 = extraout_ECX[6];
        uVar2 = (undefined1)(*(int *)(unaff_EBP + -0x24) >> 4);
        *(undefined1 *)(unaff_EBP + -0x14) = uVar2;
        uVar8 = (undefined1)(*(int *)(unaff_EBP + -0x28) >> 4);
        *(undefined1 *)(unaff_EBP + -0x13) = uVar8;
        *(char *)(unaff_EBP + -0x12) = (char)iVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 **)(unaff_EBP + 0xc) = &uStack_40;
        uStack_40._0_2_ = CONCAT11(uVar8,uVar2);
        uStack_40._3_1_ = (char)(*(int *)(unaff_EBP + -0x28) >> 0x1c);
        uStack_40._0_3_ = CONCAT12((char)iVar5,(undefined2)uStack_40);
        uVar7 = FUN_00489b59();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar7;
        *(undefined4 *)(unaff_EBP + 0xc) = uVar7;
        iVar5 = extraout_ECX[0x18];
        *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
        for (iVar5 = iVar5 / 2; iVar5 < extraout_ECX[0x4c - DAT_006f0088] / 2;
            iVar5 = iVar5 + extraout_ECX[0x18] / 2) {
          uStack_40 = 1;
          *(short *)(unaff_EBP + -0x18) = (short)iVar5 + (short)uVar1;
          (**(code **)(*extraout_ECX + 4))(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x18));
          uStack_40 = unaff_EBP + -0x30;
          cVar3 = FUN_00484ba0();
          if (cVar3 == '\0') {
            iVar6 = extraout_ECX[6];
            *(int *)(unaff_EBP + 0xc) = iVar6;
            uVar2 = (undefined1)(*(int *)(unaff_EBP + -0x2c) >> 4);
            *(undefined1 *)(unaff_EBP + -0x1c) = uVar2;
            uVar8 = (undefined1)(*(int *)(unaff_EBP + -0x30) >> 4);
            *(undefined1 *)(unaff_EBP + -0x1b) = uVar8;
            *(char *)(unaff_EBP + -0x1a) = (char)iVar6;
            *(undefined1 *)(unaff_EBP + -4) = 1;
            *(undefined4 **)(unaff_EBP + -0x20) = &uStack_40;
            uStack_40._0_2_ = CONCAT11(uVar8,uVar2);
            uStack_40._3_1_ = (char)(*(int *)(unaff_EBP + -0x30) >> 0x1c);
            uStack_40._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 0xc),(undefined2)uStack_40);
            uVar7 = FUN_00489b59();
            *(undefined1 *)(unaff_EBP + -4) = 0;
            *(undefined4 *)(unaff_EBP + 0xc) = uVar7;
          }
          if (*(short *)(unaff_EBP + 0xc) != *(short *)(unaff_EBP + -0x10)) break;
        }
        if (*(ushort *)(unaff_EBP + -0x10) < 0xfffb) {
          uStack_40 = (uint)*(ushort *)(unaff_EBP + -0x10);
          FUN_0049ea9a();
        }
        if (*(ushort *)(unaff_EBP + 0xc) < 0xfffb) {
          uStack_40 = (uint)*(ushort *)(unaff_EBP + 0xc);
          FUN_0049ea9a();
        }
        uStack_40 = 1;
        FUN_004abb9e();
      }
      else {
        uStack_40 = 0x4abb8a;
        FUN_004ac287();
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + 0xb);
}

