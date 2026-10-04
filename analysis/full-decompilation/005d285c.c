
undefined4 __fastcall FUN_005d285c(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [8];
  undefined4 local_28 [7];
  int local_c;
  int local_8;
  
  piVar1 = (int *)(param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x1c) = 1;
  local_8 = param_1;
  if ((*(int *)(param_1 + 0x14) - *piVar1 & 0xffffffe0U) != 0) {
    FUN_0040812f(*piVar1,*(undefined4 *)(param_1 + 0x14));
  }
  piVar2 = *(int **)(*(int *)(param_1 + 0xc) + 0x38);
  (**(code **)(*piVar2 + 0x20))(piVar2,&LAB_005d29cf,param_1);
  _memset(local_48,0,0x20);
  local_48[0] = 0x20;
  piVar2 = (int *)FUN_005cacf9();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x54))(piVar2,local_48);
  }
  _memset(local_28,0,0x20);
  local_28[0] = 0x20;
  puVar3 = (undefined4 *)FUN_005d312f(*piVar1,*(undefined4 *)(param_1 + 0x14),&LAB_005d29c1,local_8)
  ;
  iVar4 = 8;
  if (puVar3 == *(undefined4 **)(param_1 + 0x14)) {
    puVar3 = local_48;
  }
  puVar5 = local_28;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_005caff2(local_28);
  _memset(local_28,0,0x20);
  local_28[0] = 0x20;
  if (local_c == 0) {
    FUN_005d3081(piVar1,&LAB_005d29a5,local_28);
    if (local_c == 0) {
      FUN_005d3081(piVar1,&LAB_005d2997,local_28);
      if (local_c == 0) {
        FUN_005d3081(piVar1,&LAB_005d29b3,local_28);
        if (local_c == 0) {
          puVar3 = local_48;
          puVar5 = local_28;
          for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
          }
        }
      }
    }
  }
  FUN_005cb00a(local_28);
  return 0;
}

