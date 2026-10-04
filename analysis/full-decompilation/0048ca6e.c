
void FUN_0048ca6e(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  uint uVar5;
  int unaff_EBP;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  sVar1 = *(short *)(*(int *)(unaff_EBP + 0x14) + 0xc);
  iVar3 = *(int *)(extraout_ECX + 0x3c);
  *(int *)(unaff_EBP + -0x14) = (int)*(short *)(*(int *)(unaff_EBP + 0x14) + 0xe);
  *(int *)(unaff_EBP + -0x10) = (int)sVar1;
  if (iVar3 == 1) {
LAB_0048cb08:
    uVar7 = FUN_00584802(0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
    iVar3 = FUN_006359f2(uVar7);
    if (iVar3 == 0) {
LAB_0048cb44:
      uVar5 = *(uint *)(unaff_EBP + 0x10);
    }
    else {
      *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(iVar3 + 0x110);
      iVar4 = FUN_00492b26();
      if (iVar4 != *(int *)(unaff_EBP + 0x14)) goto LAB_0048cb44;
      uVar5 = (uint)*(ushort *)(iVar3 + 0xf0);
    }
    if (*(int *)(extraout_ECX + 0x3c) == 0) {
      iVar3 = FUN_00492b10(uVar5);
      if ((iVar3 == 0) || (*(short *)(iVar3 + 0x8e) != 0)) {
        uVar7 = 0xffffffff;
        uVar6 = 0xffffffff;
        uVar5 = 0;
      }
      else {
        uVar7 = *(undefined4 *)(unaff_EBP + -0x10);
        uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
      }
    }
    else {
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
    }
    FUN_0048c97e(uVar5,uVar6,uVar7);
    cVar2 = FUN_00584812();
    if (cVar2 == '\0') {
      uVar7 = 1;
      goto LAB_0048cabc;
    }
  }
  else {
    FUN_00492b05();
    iVar3 = FUN_00445724();
    *(int *)(extraout_ECX + 0x100) = iVar3;
    if (iVar3 != 0) goto LAB_0048cb08;
    FUN_0048c97e(0,0xffffffff,0xffffffff);
    uVar7 = 0;
LAB_0048cabc:
    FUN_00584818(uVar7);
  }
  if (*(short *)(extraout_ECX + 0x2e) == 0) {
    FUN_00492d46(0);
    cVar2 = FUN_00484ba0(unaff_EBP + 8);
    if (cVar2 == '\0') {
      *(undefined4 *)(extraout_ECX + 0x68) = 0x1c;
      FUN_00492b05();
      iVar3 = FUN_00445724();
      if (iVar3 != 0) {
        FUN_00492b05();
        iVar3 = FUN_00445724();
        *(uint *)(extraout_ECX + 0x68) = ((1 < *(short *)(iVar3 + 0x60e)) - 1 & 0xfffffff1) + 0x2b;
      }
      goto LAB_0048ccaf;
    }
    *(undefined4 *)(extraout_ECX + 0x68) = 0x1f;
    uVar7 = 0x1f;
  }
  else {
    uVar5 = (uint)*(short *)(extraout_ECX + 0x2e);
    iVar3 = *(int *)(*DAT_006e486c + 0x14);
    if ((((int)uVar5 < 1) || ((*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2) + 1U <= uVar5))
       || (iVar3 = *(int *)(*(int *)(iVar3 + 0x18) + -4 + uVar5 * 4), iVar3 == 0))
    goto LAB_0048cce2;
    if (*(short *)(*(int *)(iVar3 + 0x118) + 0x12) != 2) {
      if ((*(uint *)(iVar3 + 0x114) & 1) == 0) {
        uVar7 = 0x1f;
      }
      else {
        uVar7 = 0x1e;
      }
      *(undefined4 *)(extraout_ECX + 0x68) = uVar7;
      FUN_004d25a5(uVar7);
      FUN_00492d46(0);
      goto LAB_0048cce2;
    }
    if ((*(byte *)(*(int *)(iVar3 + 0x118) + 0xb6) & 4) == 0) {
      iVar3 = FUN_006359f2(iVar3,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0
                          );
      FUN_005d48d9();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar7 = FUN_004e98c0(iVar3,unaff_EBP + -0x20);
      FUN_004eb157(uVar7);
      uVar7 = FUN_004096c2();
      FUN_00492d46(uVar7);
      if ((*(short *)(iVar3 + 0x60e) < 2) || (iVar3 = FUN_0045741b(), iVar3 == -0x39689ed)) {
        *(undefined4 *)(extraout_ECX + 0x68) = 0x1d;
      }
      else {
        *(undefined4 *)(extraout_ECX + 0x68) = 0x2a;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else {
      *(undefined4 *)(extraout_ECX + 0x68) = 0x1f;
      FUN_00492d46(0);
    }
LAB_0048ccaf:
    uVar7 = *(undefined4 *)(extraout_ECX + 0x68);
  }
  FUN_004d25a5(uVar7);
LAB_0048cce2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

