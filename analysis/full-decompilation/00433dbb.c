
void FUN_00433dbb(int *param_1,int *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_18 [4];
  int local_8;
  
  iVar4 = FUN_00435244();
  iVar8 = local_8;
  iVar5 = *param_1;
  iVar3 = param_1[1];
  iVar4 = iVar4 / 2;
  param_2[1] = iVar3 + iVar4;
  param_2[3] = iVar3 - iVar4;
  param_2[2] = iVar5 - iVar4;
  *param_2 = iVar5 + iVar4;
  sVar1 = *(short *)(*(int *)(local_8 + 0x118) + 0x9a);
  sVar2 = 0;
  if (*(short *)(*(int *)(local_8 + 0x118) + 0x12) == 2) {
    iVar5 = FUN_006359f2(local_8,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0
                        );
    if ((*(byte *)(iVar8 + 0x4c) & 1) == 0) {
      sVar2 = *(short *)(iVar5 + 0x61e);
    }
  }
  if ((sVar1 != 0) || (sVar2 != 0)) {
    uVar6 = (uint)sVar1;
    local_18[1] = (int)uVar6 >> 4 & 0xf;
    local_18[2] = (int)uVar6 >> 8 & 0xf;
    local_18[3] = (int)uVar6 >> 0xc & 0xf;
    local_18[0] = uVar6 & 0xf;
    if (sVar2 != 0) {
      uVar7 = (uint)sVar2;
      local_18[0] = (uVar6 & 0xf) - (uVar7 & 0xf);
      local_18[1] = local_18[1] - ((int)uVar7 >> 4 & 0xfU);
      local_18[3] = local_18[3] - ((int)uVar7 >> 0xc & 0xfU);
      local_18[2] = local_18[2] - ((int)uVar7 >> 8 & 0xfU);
      iVar8 = local_8;
    }
    iVar5 = (8 - *(short *)(iVar8 + 0x4c)) / 2;
    param_2[2] = param_2[2] + local_18[iVar5 % 4];
    param_2[1] = param_2[1] - local_18[(iVar5 + 1) % 4];
    *param_2 = *param_2 - local_18[(iVar5 + 2) % 4];
    param_2[3] = param_2[3] + local_18[(iVar5 + 3) % 4];
  }
  return;
}

