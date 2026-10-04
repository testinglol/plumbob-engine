
int __thiscall FUN_00416fc3(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 local_54 [64];
  undefined4 local_14;
  int local_10;
  undefined2 local_c;
  ushort local_a;
  undefined4 local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 != '\0') {
    return -0x2f;
  }
  iVar3 = FUN_004130d2(param_2,param_3);
  if (iVar3 != 0) {
    return iVar3;
  }
  param_3 = 0x40;
  iVar3 = FUN_004131a0(0);
  if ((iVar3 == 0) && (iVar3 = FUN_00413178(local_54,&param_3), iVar3 == 0)) {
    sVar2 = FUN_0042007c(s_IFF_FILE_1_0_TYPE_FOLLOWED_BY_SI_006c1ff0,local_54,0x40);
    if (sVar2 != 0) goto LAB_00417050;
    iVar3 = -0x5d;
  }
  FUN_00413154();
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_00417050:
  param_1[8] = 0;
  iVar3 = 0x40;
  while (iVar4 = FUN_004181b3(&local_14,iVar3), iVar4 == 0) {
    if ((local_a & 4) == 0) {
      piVar5 = param_1 + 7;
      if ((local_a & 8) == 0) {
        piVar5 = param_1 + 6;
      }
      iVar4 = FUN_004182c3(piVar5,local_14);
      if (iVar4 != 0) {
        *(undefined2 *)(iVar4 + 4) = local_c;
        *(ushort *)(iVar4 + 6) = local_a;
        *(int *)(iVar4 + 8) = iVar3;
        *(undefined4 *)(iVar4 + 0x10) = 0;
        *(undefined4 *)(iVar4 + 0xc) = local_8;
      }
    }
    else {
      param_1[8] = param_1[8] + local_10;
    }
    iVar3 = iVar3 + local_10;
  }
  iVar3 = param_1[9];
  if (iVar3 != 0) {
    FUN_00418416();
    FUN_006321f0(iVar3);
  }
  puVar6 = operator_new(0x10);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    *(undefined1 *)(puVar6 + 3) = 1;
  }
  param_1[9] = (int)puVar6;
  if ((char)param_1[10] == '\0') {
    iVar3 = param_1[6];
    param_1[6] = param_1[7];
    param_1[7] = iVar3;
    *(undefined1 *)(param_1 + 10) = 1;
  }
  FUN_00416d13(param_1);
  if ((char)param_1[10] != '\0') {
    iVar3 = param_1[6];
    *(undefined1 *)(param_1 + 10) = 0;
    param_1[6] = param_1[7];
    param_1[7] = iVar3;
  }
  return 0;
}

