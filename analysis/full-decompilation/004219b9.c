
undefined4 FUN_004219b9(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined2 uVar4;
  int iVar3;
  undefined4 uVar5;
  TypeDescriptor *pTVar6;
  TypeDescriptor *pTVar7;
  undefined4 uVar8;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00440b6d(param_2);
  }
  sVar1 = FUN_00421619(param_1,uVar2,param_3,param_4);
  if (sVar1 == 0) {
    FUN_0044127f(uVar2);
    uVar4 = extraout_var;
  }
  else {
    uVar8 = 0;
    pTVar7 = &cXCursorObject::RTTI_Type_Descriptor;
    pTVar6 = &cXObject::RTTI_Type_Descriptor;
    uVar5 = 0;
    uVar2 = FUN_00407498((int)sVar1);
    while( true ) {
      iVar3 = FUN_006359f2(uVar2,uVar5,pTVar6,pTVar7,uVar8);
      uVar4 = 0;
      if (iVar3 == 0) break;
      uVar8 = 0;
      pTVar7 = &cXCursorObject::RTTI_Type_Descriptor;
      pTVar6 = &cXMTObject::RTTI_Type_Descriptor;
      uVar5 = 0;
      uVar2 = *(undefined4 *)(iVar3 + 0x18c);
      *(undefined2 *)(iVar3 + 0x1b2) = 1;
    }
  }
  return CONCAT22(uVar4,sVar1);
}

