
undefined4 __thiscall FUN_005c8aa1(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_3c [8];
  undefined4 local_1c;
  int *local_8;
  
  (**(code **)(*param_2 + 4))(0);
  _memset(&local_84,0,0x7c);
  local_84 = 0x7c;
  local_78 = *param_3;
  local_7c = param_3[1];
  piVar1 = *(int **)(param_1 + 0x74);
  local_80 = 0x1007;
  local_1c = 0x20800;
  puVar3 = (undefined4 *)(param_1 + 0xc74);
  puVar4 = local_3c;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,&local_84,&local_8,0);
  *(int *)(param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    (**(code **)(*param_2 + 4))(local_8);
  }
  else if (local_8 == (int *)0x0) goto LAB_005c8b2f;
  (**(code **)(*local_8 + 8))(local_8);
LAB_005c8b2f:
  return *(undefined4 *)(param_1 + 4);
}

