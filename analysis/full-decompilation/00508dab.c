
undefined4 __fastcall FUN_00508dab(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined3 uVar5;
  int iVar6;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*(int *)(param_1 + 0x84) == *(int *)(param_1 + 0x7c)) ||
     (*(int *)(param_1 + 0x88) == *(int *)(param_1 + 0x80))) {
    uVar5 = 0;
    goto LAB_00508f6b;
  }
  if (DAT_006e5490 < *(uint *)(param_1 + 0x100)) {
    FUN_00473496(DAT_006e5490);
    iVar2 = __ftol();
    local_8 = (*(int *)(param_1 + 0x88) - iVar2) - *(int *)(param_1 + 0x80);
  }
  else {
    local_8 = 0;
  }
  FUN_004e609e();
  cVar1 = FUN_004e6133();
  if (cVar1 == '\0') {
    uVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if ((char)uVar3 != '\0') {
      iVar2 = *(int *)(param_1 + 0x118);
      local_18 = *(int *)(iVar2 + 0x14);
      local_14 = *(int *)(iVar2 + 0x18);
      local_10 = *(int *)(iVar2 + 0x1c);
      local_28 = local_18 + *(int *)(param_1 + 0x1c);
      local_20 = local_10 + *(int *)(param_1 + 0x1c);
      local_1c = *(int *)(param_1 + 0x20) + *(int *)(iVar2 + 0x20);
      local_c = *(int *)(iVar2 + 0x20) - local_8;
      local_24 = local_14 + *(int *)(param_1 + 0x20) + local_8;
      iVar6 = **(int **)(param_1 + 0x5c);
LAB_00508f4f:
      (**(code **)(iVar6 + 0x9c))(iVar2,&local_18,&local_28,0);
      uVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  else if (DAT_006e5490 < *(uint *)(param_1 + 0x100)) {
    local_10 = 0;
    local_8 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
    local_c = 0;
    uVar3 = *(undefined4 *)(param_1 + 0x5c);
    FUN_00473496(DAT_006e5490);
    uVar4 = __ftol();
    uVar3 = (*DAT_006f0674)(uVar3,param_1 + 0x1c,uVar3,param_1 + 0x1c,
                            *(undefined4 *)(param_1 + 0x118),&local_10,uVar4);
  }
  else {
    uVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if ((char)uVar3 != '\0') {
      iVar2 = *(int *)(param_1 + 0x118);
      local_18 = *(int *)(iVar2 + 0x14);
      local_14 = *(int *)(iVar2 + 0x18);
      local_10 = *(int *)(iVar2 + 0x1c);
      local_c = *(int *)(iVar2 + 0x20);
      local_28 = local_18 + *(int *)(param_1 + 0x1c);
      local_24 = local_14 + *(int *)(param_1 + 0x20);
      local_20 = local_10 + *(int *)(param_1 + 0x1c);
      local_1c = local_c + *(int *)(param_1 + 0x20);
      iVar6 = **(int **)(param_1 + 0x5c);
      goto LAB_00508f4f;
    }
  }
  uVar5 = (undefined3)((uint)uVar3 >> 8);
LAB_00508f6b:
  return CONCAT31(uVar5,1);
}

