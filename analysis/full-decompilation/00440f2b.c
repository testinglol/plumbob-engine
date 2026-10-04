
void __thiscall FUN_00440f2b(int param_1,short param_2,char param_3)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_68;
  int local_20;
  int local_18;
  int local_14;
  int local_c;
  
  piVar4 = (int *)FUN_00407498((int)param_2);
  if (piVar4 != (int *)0x0) {
    iVar1 = piVar4[0x46];
    local_c = FUN_006359f2(piVar4,0,&cXObject::RTTI_Type_Descriptor,
                           &cXMTObject::RTTI_Type_Descriptor,0);
    if ((param_3 == '\0') && (local_c != 0)) {
      local_18 = local_c;
      if (*(int *)(local_c + 400) == 0) {
        for (; local_18 != 0; local_18 = *(int *)(local_18 + 0x18c)) {
          *(uint *)(local_18 + 0x114) = *(uint *)(local_18 + 0x114) & 0xffffffbf;
          *(uint *)(local_18 + 0x114) = *(uint *)(local_18 + 0x114) | 0x40;
        }
        while (local_c != 0) {
          iVar1 = *(int *)(local_c + 0x18c);
          FUN_00440f2b(*(undefined2 *)(local_c + 0xf0),1);
          local_c = iVar1;
        }
      }
      else {
        FUN_00440f2b(CONCAT22((short)((uint)*(int *)(local_c + 400) >> 0x10),
                              *(undefined2 *)(*(int *)(local_c + 400) + 0xf0)),0);
      }
    }
    else {
      FUN_0040766a(0x87,(int)param_2);
      piVar4[0x45] = piVar4[0x45] & 0xffffffbf;
      piVar4[0x45] = piVar4[0x45] | 0x40;
      if (piVar4 == *(int **)(param_1 + 0xa8)) {
        FUN_00444c08(0);
      }
      piVar5 = (int *)FUN_00445724();
      if (piVar4 == piVar5) {
        FUN_00445489(0);
      }
      FUN_0044822b(piVar4);
      FUN_004341a6(0);
      FUN_00444346(piVar4);
      uVar7 = 0;
      (**(code **)(*piVar4 + 0x38))(0);
      if (*(short *)(iVar1 + 0x12) == 9) {
        FUN_006359f2(piVar4,0,&cXObject::RTTI_Type_Descriptor,&cXCursorObject::RTTI_Type_Descriptor,
                     0);
        sVar3 = FUN_00421a41();
        if (sVar3 == 0) {
          FUN_0042189e();
        }
      }
      iVar1 = piVar4[0x4d];
      iVar2 = piVar4[0x4c];
      for (local_20 = 0; local_20 < (iVar1 - iVar2) / 0x24 + -1; local_20 = local_20 + 1) {
        if ((local_20 < 0) || ((piVar4[0x4d] - piVar4[0x4c]) / 0x24 + -1 <= local_20)) {
          local_68 = 0;
        }
        else {
          local_68 = piVar4[0x4c] + (local_20 + 1) * 0x24;
        }
        if (*(short *)(local_68 + 0x10) != 0) {
          FUN_0044127f(*(short *)(local_68 + 0x10));
        }
      }
      FUN_00432984();
      FUN_0044387c(piVar4);
      if (piVar4 == (int *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (**(code **)(*piVar4 + 0x10))(1);
      }
      if (param_2 == *(short *)(param_1 + 0x80)) {
        *(undefined2 *)(param_1 + 0x80) = 0;
      }
      for (local_14 = *(int *)(param_1 + 0x30); local_14 != 0; local_14 = *(int *)(local_14 + 0xe0))
      {
        FUN_00465090((int)param_2);
      }
      FUN_0040766a(0x88,(int)param_2,uVar7,uVar6);
    }
  }
  return;
}

