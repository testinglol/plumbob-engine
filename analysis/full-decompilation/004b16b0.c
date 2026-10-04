
void __thiscall FUN_004b16b0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  tagRECT local_14;
  
  iVar1 = FUN_004cfddd();
  iVar2 = FUN_004cfde4();
  local_14.right = *(int *)(param_1 + 0x4c4) + -1 + iVar1 / 2;
  local_14.bottom = *(int *)(param_1 + 0x4c8);
  local_14.left = (*(int *)(param_1 + 0x4c4) - iVar1 / 2) + -1;
  local_14.top = (local_14.bottom - iVar2) + -2;
  if (local_14.left < *(int *)(param_1 + 0x28)) {
    iVar1 = *(int *)(param_1 + 0x28) - local_14.left;
LAB_004b1732:
    OffsetRect(&local_14,iVar1,0);
  }
  else if (*(int *)(param_1 + 0x30) <= local_14.right) {
    iVar1 = (*(int *)(param_1 + 0x30) - local_14.right) + -1;
    goto LAB_004b1732;
  }
  if (local_14.top < *(int *)(param_1 + 0x2c)) {
    iVar1 = *(int *)(param_1 + 0x2c) - local_14.top;
  }
  else {
    if (local_14.bottom < *(int *)(param_1 + 0x34)) goto LAB_004b175c;
    iVar1 = (*(int *)(param_1 + 0x34) - local_14.bottom) + -1;
  }
  OffsetRect(&local_14,0,iVar1);
LAB_004b175c:
  FUN_004a7901();
  *param_2 = local_14.left;
  param_2[1] = local_14.top;
  param_2[2] = local_14.right;
  param_2[3] = local_14.bottom;
  return;
}

