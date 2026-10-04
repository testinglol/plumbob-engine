
void __fastcall FUN_00487374(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  iVar1 = FUN_004a694e();
  FUN_004a69c4();
  if (*(int *)(param_1 + 0x3c) == 0) {
    return;
  }
  if ((*(int *)(param_1 + 0x34) != 4) && (*(int *)(param_1 + 0x34) != 3)) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    return;
  }
  local_8 = 0;
  local_c = 0;
  if (iVar1 == 1) {
    local_8 = DAT_006e5778 >> 2;
    iVar5 = DAT_006e5770 >> 2;
    iVar6 = DAT_006e5774 >> 2;
    local_c = DAT_006e577c >> 2;
  }
  else if (iVar1 == 2) {
    local_8 = DAT_006e5778 >> 1;
    iVar5 = DAT_006e5770 >> 1;
    iVar6 = DAT_006e5774 >> 1;
    local_c = DAT_006e577c >> 1;
  }
  else {
    iVar5 = 0;
    iVar6 = 0;
    if (iVar1 == 3) {
      local_8 = DAT_006e5778;
      iVar5 = DAT_006e5770;
      iVar6 = DAT_006e5774;
      local_c = DAT_006e577c;
    }
  }
  iVar1 = FUN_006359f2(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x1ac),0,
                       &cXObject::RTTI_Type_Descriptor,&cXPortal::RTTI_Type_Descriptor,0);
  iVar2 = FUN_004a69b7();
  iVar3 = (int)*(short *)(iVar1 + 0x4c);
  if ((*(byte *)(iVar1 + 100) & 1) != 0) {
    iVar3 = iVar3 + 4;
  }
  uVar4 = (-iVar3 >> 1) - iVar2 & 3;
  if (uVar4 == 0) {
LAB_00487487:
    *(int *)(param_1 + 0x50) = iVar5;
  }
  else {
    if (uVar4 == 1) {
      iVar5 = -iVar5;
      goto LAB_00487487;
    }
    if (uVar4 == 2) {
      iVar5 = -iVar5;
    }
    else if (uVar4 != 3) goto LAB_0048748d;
    *(int *)(param_1 + 0x50) = iVar5;
    iVar6 = -iVar6;
  }
  *(int *)(param_1 + 0x54) = iVar6;
LAB_0048748d:
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + local_8;
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + local_c;
  return;
}

