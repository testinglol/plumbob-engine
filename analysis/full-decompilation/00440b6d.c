
undefined4 FUN_00440b6d(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined2 extraout_var;
  undefined2 uVar9;
  undefined4 uVar10;
  TypeDescriptor *pTVar11;
  TypeDescriptor *pTVar12;
  undefined4 uVar13;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  short local_c;
  
  local_c = 0;
  cVar3 = (**(code **)(*(int *)*param_1 + 0x28))();
  if (cVar3 == '\0') {
    return 0;
  }
  iVar1 = param_1[0x18];
  if (*(short *)(iVar1 + 0x14) == 0) {
    iVar6 = FUN_004580cc(0);
    if (((((iVar6 != 0) && (iVar6 = FUN_004705f2(1,0xffffffff), iVar6 != 0)) &&
         ((*(ushort *)(DAT_006e486c + 0x66) & 0x20) == 0)) &&
        ((*(ushort *)(DAT_006e486c + 0x66) & 0x80) == 0)) &&
       ((iVar7 = FUN_00646330(iVar6,PTR_PTR_006c3b8c), iVar7 == 0 ||
        (iVar6 = FUN_00646330(iVar6,PTR_DAT_006c3b90), iVar6 == 0)))) {
      return 0;
    }
    piVar8 = (int *)FUN_004409db(param_1,0);
    if (piVar8 == (int *)0x0) {
      return 0;
    }
    local_c = FUN_0044350d(piVar8,0,0);
    if (local_c == 0) {
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 0x10))(1);
      }
    }
    else {
      (**(code **)(*piVar8 + 0x3c))();
      FUN_00431ea2();
      (**(code **)(*piVar8 + 0x40))(1);
      *(undefined2 *)(piVar8 + 0x27) = *(undefined2 *)(iVar1 + 0x24);
      piVar8[0x45] = piVar8[0x45] & 0xffffff7f;
      piVar8[0x45] = piVar8[0x45] | 0x80;
      FUN_0044582f((int)(short)piVar8[0x3c],1,1);
    }
  }
  else {
    cVar3 = FUN_0043aedc();
    if (cVar3 != '\0') {
      bVar2 = false;
      local_18 = (int *)0x0;
      local_1c = FUN_0043adda(param_1);
      local_20 = 0;
      while (local_1c != 0) {
        if ((local_18 == (int *)0x0) || (local_18[0x47] != local_1c)) {
          uVar13 = 0;
          pTVar12 = &cXMTObject::RTTI_Type_Descriptor;
          pTVar11 = &cXObject::RTTI_Type_Descriptor;
          uVar10 = 0;
          uVar5 = FUN_004409db(local_1c,local_18);
          local_14 = (int *)FUN_006359f2(uVar5,uVar10,pTVar11,pTVar12,uVar13);
          if ((local_14 == (int *)0x0) || (sVar4 = FUN_0044350d(local_14,0,0), sVar4 == 0)) {
            if (local_14 != (int *)0x0) {
              (**(code **)(*local_14 + 0x10))(1);
            }
            bVar2 = true;
          }
          else {
            (**(code **)(*local_14 + 0x3c))();
            FUN_00431ea2();
            if (local_18 == (int *)0x0) {
              local_18 = local_14;
            }
          }
        }
        local_1c = FUN_0043ae5e(param_1,local_20);
        local_20 = local_20 + 1;
      }
      if ((bVar2) || (local_18 == (int *)0x0)) {
        if (local_18 != (int *)0x0) {
          FUN_00440f2b((short)local_18[0x3c],0);
        }
      }
      else {
        local_c = (short)local_18[0x3c];
        *(undefined2 *)(local_18 + 0x27) = *(undefined2 *)(iVar1 + 0x24);
        (**(code **)(*local_14 + 0x40))(1);
        for (local_14 = local_18; local_14 != (int *)0x0; local_14 = (int *)local_14[99]) {
          local_14[0x45] = local_14[0x45] & 0xffffff7f;
          local_14[0x45] = local_14[0x45] | 0x80;
          FUN_0044582f((int)(short)local_14[0x3c],1,1);
        }
      }
    }
  }
  uVar9 = 0;
  if (local_c != 0) {
    FUN_0040766a(0xe2,(int)local_c);
    uVar9 = extraout_var;
  }
  return CONCAT22(uVar9,local_c);
}

